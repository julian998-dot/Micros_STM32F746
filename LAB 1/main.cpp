
#include <stdio.h>
#include <STM32F7xx.h>
int cont=0;
int delay=600000;
int vaar=0;
int delay2=100000;
int delay3=550000;

int main(void){
	RCC->AHB1ENR|=0XFF;
	GPIOG->MODER|=0X55555555;
	GPIOG->OTYPER=0;
	GPIOG->OSPEEDR=0X1555;
	GPIOG->PUPDR=0X1555;
	GPIOC->MODER|=~(3UL<<2*13);
	GPIOC->OTYPER=0;
	GPIOC->PUPDR|=(2UL<<2*13);
	GPIOC->OSPEEDR|=(1UL<<2*13);
	GPIOE->MODER|=0x0;
	GPIOF->MODER=0;
	GPIOE->OTYPER=0;
	GPIOE->OSPEEDR=0X5555;
	//GPIOE->PUPDR=0X1;
	GPIOF->OTYPER=0;
	GPIOF->OSPEEDR=0X1555;
	GPIOF->PUPDR=0x2;
	GPIOB->MODER=0X10004001;
	GPIOB->OTYPER=0;
	GPIOB->OSPEEDR=0X10004001;
	GPIOB->PUPDR=0X20008002;
	int disp=9;
	GPIOD->MODER|=0X5555;
	GPIOD->OTYPER=0;
	GPIOD->OSPEEDR=0X5555;
	GPIOD->PUPDR=0X5555;
	int cont2=0;
	GPIOE->ODR|=0x1;
	while(true){
	if(GPIOC->IDR&=(1UL<<13)){ // 16 LEDS
			cont++;
		switch(cont){
			case 1:
				for(int i=0;i<6;i++){
				GPIOG->ODR|=0xAAAA;
					for(int i=0;i<delay;i++);
				GPIOG->ODR=0;
				GPIOG->ODR|=0x5555;
					for(int i=0;i<delay;i++);
					GPIOG->ODR=0;
				}
					break;
			case 2:
				for(int i=0;i<3;i++){
					GPIOG->ODR=0;
				GPIOG->ODR|=0xAA00;
					for(int i=0;i<delay;i++);
				GPIOG->ODR=0;
				GPIOG->ODR|=0x0055;
					for(int j=0;j<(delay/3);j++);
					GPIOG->ODR=0;
				}
					break;
				case 3:
					for(int i=0;i<3;i++){
						GPIOG->ODR=0;
						for(int i=0;i<delay;i++);
					GPIOG->ODR|=0xF;
					for(int i=0;i<delay;i++);
					GPIOG->ODR=0;
				GPIOG->ODR|=0xFF;
					for(int i=0;i<delay;i++);
					GPIOG->ODR=0;
				GPIOG->ODR|=0xFFF;
					for(int i=0;i<delay;i++);
					GPIOG->ODR=0;
				GPIOG->ODR|=0xFFFF;
					for(int i=0;i<delay;i++);
					GPIOG->ODR=0;
					}
				break;
				case 4:
					for(int i=0;i<3;i++){
					for(int i=0;i<delay;i++);		
				GPIOG->ODR|=0xFFFF;
					for(int i=0;i<delay;i++);
					GPIOG->ODR=0;
				GPIOG->ODR|=0xFFF;
					for(int i=0;i<delay;i++);
					GPIOG->ODR=0;
				GPIOG->ODR|=0xFF;
					for(int i=0;i<(delay/4);i++);
					GPIOG->ODR=0;
				GPIOG->ODR|=0xF;
					for(int i=0;i<delay;i++);
					GPIOG->ODR=0;
					}
					break;
				case 5:
					for(int i=0;i<4;i++){
					for(int i=0;i<delay;i++);		
				GPIOG->ODR|=0x8888;
					for(int i=0;i<delay;i++);
					GPIOG->ODR=0;
				GPIOG->ODR|=0x2222;
					for(int i=0;i<delay;i++);
					GPIOG->ODR=0;
				GPIOG->ODR|=0x8888;
					for(int i=0;i<delay;i++);
					GPIOG->ODR=0;
				GPIOG->ODR|=0x2222;
					for(int i=0;i<delay;i++);
					GPIOG->ODR=0;
					}
					break;
				default:
					cont=0;
				break;
			}//SWITCH			
		}//IF
	//| GPIOE->IDR==0x05 |GPIOE->IDR==0x06 | GPIOE->IDR==0x07 
	if(GPIOE->IDR==0xFFFC ){ // 16 LEDS
			
	//if(GPIOC->IDR==0x2000){
		//cont2++;
		
	switch(cont2){
			case 0:
				GPIOB->ODR=1;
			for(int i=0;i<delay2;i++);
			break;
			case 1:
				GPIOB->ODR=0X80;
			for(int i=0;i<delay2;i++);
			break;
			case 2:
				GPIOB->ODR|=1;
			for(int i=0;i<delay2;i++);
			break;
			case 3:
				GPIOB->ODR=0X4000;
			for(int i=0;i<delay2;i++);
			break;
			case 4:
				GPIOB->ODR|=1;
			for(int i=0;i<delay2;i++);
			break;
			case 5:
				GPIOB->ODR=0X80;
				GPIOB->ODR|=0X4000;
			for(int i=0;i<delay2;i++);
			break;
			case 6:
				GPIOB->ODR|=1;
			for(int i=0;i<delay2;i++);
			GPIOB->ODR=0;
			break;
			default:
				GPIOB->ODR=0;
			for(int i=0;i<delay2;i++);
			cont=0;
		}
		for(int i=0;i<delay2;i++);
		cont2++;
		if(cont2>6)cont2=0;
	}

	int vect[19]={0x6F,0xEF,0x23,0xEE,0x6E,0x2D,0x6B,0xCB,0x21,0xE7,0x31,0xDB,0x7B,0x3D,0x7E,0xFE,0x33,0xFF,0x7F};
	
	GPIOD->ODR=vect[disp];
	//| GPIOE->IDR==0X3
	if(GPIOE->IDR==0XFFF9 | GPIOE->IDR==0XFFFA ){

		if(GPIOE->IDR==0XFFF9){
			disp++;
			for(int i=0;i<delay3;i++);
			
	}
		if(GPIOE->IDR==0XFFFA){
			disp--;
			for(int i=0;i<delay3;i++);
	}
	
	
	}if(disp >= 19 |disp<0 )disp=9;
		
		
		
}//while
}//main
