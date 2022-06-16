#include <stdio.h>
#include "stm32f7xx.h"                

//A MANERA GENERAL, LA TARJETA ESTÁ TRABAJANDO COMO MAESTRO EN LA COMUNICACIÓN 
 //PF1->SCL
 //PF0->SDA

int time=8000;

#define LCD_I2C_Address 0x40 //Dirección de la LCD

//Peso de cada comando de la LCD
#define LCD_I2C_CLEARDISPLAY 0x01
#define LCD_I2C_RETURNHOME 0x02
#define LCD_I2C_ENTRYMODESET 0x04
#define LCD_I2C_DISPLAYCONTROL 0x08
#define LCD_I2C_CURSORSHIFT 0x10
#define LCD_I2C_FUNCTIONSET 0x20
#define LCD_I2C_SETCGRAMADDR 0x40
#define LCD_I2C_SETDDRAMADDR 0x80

//Peso de bits para función display entry mode
#define LCD_I2C_ENTRYRIGHT 0x00
#define LCD_I2C_ENTRYLEFT 0x02
#define LCD_I2C_ENTRYSHIFTDECREMENT 0x00
#define LCD_I2C_ENTRYSHIFTINCREMENT 0x01

//Peso de bits para función display on/off control
#define LCD_I2C_DISPLAYOFF 0x00
#define LCD_I2C_DISPLAYON 0x04
#define LCD_I2C_CURSOROFF 0x00
#define LCD_I2C_CURSORON 0x02
#define LCD_I2C_BLINKOFF 0x00
#define LCD_I2C_BLINKON 0x01

//Peso de bits para función display/cursor shift
#define LCD_I2C_CURSORMOVE 0x00
#define LCD_I2C_DISPLAYMOVE 0x08
#define LCD_I2C_MOVERIGHT 0x04
#define LCD_I2C_MOVELEFT 0x00

//Peso de bits para función function set
#define LCD_I2C_4BITMODE 0x00
#define LCD_I2C_2LINE 0x08
#define LCD_I2C_5x7DOTS 0x00

//Peso de bits para el control de backlight
#define LCD_I2C_NOBACKLIGHT 0x00
#define LCD_I2C_BACKLIGHT 0x08

#define En 0x04  // Enable bit
#define Rs 0x01  // Register select bit

void SystemIn(void);
char data;
 
 
 
void I2C2_Init (void)   {
		RCC->AHB1ENR  |=  0x00000020; // Encender reloj puertoF
		GPIOF->AFR[0] |=  0x00000044; // seleccion de la funcion alterna 4 del puerto F(I2C) para  PF1-SCL,PF0-SDA -> I2C2
		GPIOF->MODER  |=  0x0000000A; // PF0,PF1 => en modo alterno
		GPIOF->OTYPER |=  0x0003;     // Open drain  
    GPIOF->PUPDR  |=  0x5;
    GPIOF->OSPEEDR |=  0xC;
     
    RCC->APB1ENR  |= 0x00400000;       // Enable clock for I2C2 bit 22 
    RCC->DCKCFGR2  |= 0x80000;                //Reloj de frecuencia del I2C2
     
    // Disable the I2Cx peripheral
    I2C2->CR1 &= ~I2C_CR1_PE; //deshabilita SCL y SDA para el periferico 
    while (I2C2->CR1 & I2C_CR1_PE);
    
	  //I2C2->TIMINGR
    I2C2->TIMINGR |= 0x30420F13;         //I2C2 Timing config at t2clk=1/FHSI		
    
	  I2C2->CR2 |= 0x0202204E;
	
    // Use 7-bit addresses
    I2C2->CR2 &=~ I2C_CR2_ADD10; //Modo maestro receptor, solo recibe 7 de 10 bits de comunicación
    // Enable auto-end mode
    I2C2->CR2 |= I2C_CR2_AUTOEND; //autofinalización activada
    // Disable the analog filter
    I2C2->CR1 |= I2C_CR1_ANFOFF; //filtro de ruido desactivado
    // Disable NOSTRETCH
    I2C2->CR1 |= I2C_CR1_NOSTRETCH; //nostretch desactivado
    
		// Enable the I2Cx peripheral
    I2C2->CR1 |= I2C_CR1_PE; //habilita SCL y SDA para el periferico 
}

//FUNCION PARA ENVIAR 

void I2C2_Write (char Dat){
//I2C2 Initialization
    I2C2->CR2 |= 0x0202204E;	
    while (!(I2C2->ISR & I2C_ISR_TXIS));
    I2C2->TXDR = LCD_I2C_Address;
    while (!(I2C2->ISR & I2C_ISR_TXIS));
    I2C2->TXDR = (Dat | LCD_I2C_BACKLIGHT);
    while (!(I2C2->ISR & I2C_ISR_TXE));
    while (!(I2C2->ISR & I2C_ISR_STOPF));
    I2C2->ISR &= ~I2C_ISR_STOPF;    
}


void pulseEnable(char _data){       //Genera pulso de Enable    
	I2C2_Write(_data | En);           //Pin Enable en alto
	for (int i=0; i<time; i++) {};    //Pulso debe tener un ancho > 450ns
	I2C2_Write(_data & ~En);          //Pin Enable en bajo
	for (int i=0; i<time; i++) {};		//Comando necesita más de 37us para su ejecución
}


void Write4bits(char value){ //Función de envío de 4 bits a la LCD
	I2C2_Write(value);
	pulseEnable(value);
}


void send(char value,char mode){ //Escritura de cualquier comando o dato
	char highnib = value&0xf0;
	char lownib =(value<<4)&0xf0;
	Write4bits((highnib) | mode); //mode=0 comando, mode=1 dato
	Write4bits((lownib) | mode); 
}

void LCD_I2C_WriteControl(char value){
    send(value,0);
}

 void LCD_I2C_WriteData(char value){
	send(value,Rs);
}

void LCD_I2C_ClearLCD(void){    
	LCD_I2C_WriteControl(LCD_I2C_CLEARDISPLAY);//Borrar display
	for (int i=0; i<time; i++) {}; //Tiempo de ejecución del comando
    LCD_I2C_WriteControl(LCD_I2C_RETURNHOME); //Cursor al inicio
	for (int i=0; i<time; i++) {}; //Tiempo de ejecución del comando
}


void LCD_I2C_Ini(void){ //Inicialización de la LCD
	for (int i=0; i<time; i++) {};  //Tiempo de espera >15ms para estabilización de fuente DC
	I2C2_Write(LCD_I2C_BACKLIGHT); //Pone en '0' RS y R/W además enciende
	for (int i=0; i<time; i++) {};                   //el backlight de la LCD
	//Configuración de la LCD en formato de 4 bits
	Write4bits(0x30); //Envia comando 3 veces
	for (int i=0; i<time; i++) {}; //Espera por más de 4.1ms
	Write4bits(0x30);
	for (int i=0; i<time; i++) {}; //Espera por más de 4.1ms
	Write4bits(0x30);
	for (int i=0; i<time; i++) {}; //Espera por más de 100us
	Write4bits(0x20); //Finaliza enviando comando de interface de 4 bits
	
	//Configura: 2 línaes, letra de tamaño 5x7
	LCD_I2C_WriteControl(LCD_I2C_FUNCTIONSET | LCD_I2C_4BITMODE | LCD_I2C_2LINE | LCD_I2C_5x7DOTS);
	//Configura: Display On, cursor apagado y blinking deshabilitado
  LCD_I2C_WriteControl(LCD_I2C_DISPLAYCONTROL | LCD_I2C_DISPLAYON | LCD_I2C_CURSOROFF | LCD_I2C_BLINKOFF);
	//Borra LCD y ubica cursor al inicio
	LCD_I2C_ClearLCD();
	//Configura: escritura de izquierda a derecha
	LCD_I2C_WriteControl(LCD_I2C_ENTRYMODESET | LCD_I2C_ENTRYLEFT | LCD_I2C_ENTRYSHIFTDECREMENT);
}



int main ()  {
	
		//SystemIn();

    I2C2_Init();         // initializar  I2C2
	
    LCD_I2C_Ini();       // inicializar LCD


	  LCD_I2C_WriteData('M');  //Enviar letra de prueba
	  LCD_I2C_WriteData('E');  //Enviar letra de prueba
  	LCD_I2C_WriteData('N');  //Enviar letra de prueba
	  LCD_I2C_WriteData('S');  //Enviar letra de prueba
	  LCD_I2C_WriteData('A');  //Enviar letra de prueba
	  LCD_I2C_WriteData('J');  //Enviar letra de prueba
  	LCD_I2C_WriteData('E');  //Enviar letra de prueba
	  LCD_I2C_WriteData(' ');  //Enviar letra de prueba
    
	  LCD_I2C_WriteData('P');  //Enviar letra de prueba
	  LCD_I2C_WriteData('R');  //Enviar letra de prueba
  	LCD_I2C_WriteData('U');  //Enviar letra de prueba
	  LCD_I2C_WriteData('E');  //Enviar letra de prueba
	  LCD_I2C_WriteData('B');  //Enviar letra de prueba
	  LCD_I2C_WriteData('A');  //Enviar letra de prueba

					
  while(1) {

		
	}//cierra while
	
}//cierra maina
 
 
void SystemIn(void){
 int a=0;
 RCC->CR |= 0x10000;                         
 while((RCC->CR & 0x20000)==0);              
 RCC->APB1ENR = 0x10080000;                  
 RCC->CFGR = 0x00009400;                     
 RCC->PLLCFGR = 0x07405408;                  
 RCC->CR |= 0x01000000;                      
 while((RCC->CR & 0x02000000)==0);           
 FLASH->ACR = (0x00000605);                  
 RCC->CFGR |= 2;                             
 for (a=0;a<=500;a++);
}