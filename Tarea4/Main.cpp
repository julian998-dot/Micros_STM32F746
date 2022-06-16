/* CONEXIONES
	Puerto B: Teclado			
				Pin 3: Fila 1							
 				Pin 2: Fila 2					
				Pin 1: Fila 3					
				Pin 0: Fila 4	 				
				Pin 5: Columna 1
				Pin 6: Columna 2
				Pin 7: Columna 3			
				Pin 8: Columna 4		

*/

// **************** LIBRERIAS **********************
		#include <stdio.h>
		#include "STM32F7xx.h"
// *************************************************

// **************** VARIABLES GLOBALES *************
		short contador_teclado=0;
		short contador_display=0;
		short boton_pulsado=0;
		bool bandera_pulsacion=0;
		bool mostrar=0;
		short tipCont=0;
		short contMax=0;
		short contMin=9;
		short visu=0;
		short tecla=0;
		short pausa=0;
		short parp=0;
		short convinaciones[11]={0x40, 0x79, 0x24, 0x30, 0x19, 0x12, 0x02, 0x78, 0x00, 0x18, 0x3F};
														// 0      1     2     3     4     5     6     7     8     9  
// *************************************************

// **************** FUNCIONES **********************
		void accion_teclado(){
			switch(contador_teclado){
				case 0:
					GPIOB->ODR =0x8;
					break;
				case 1:
					GPIOB->ODR =0x4;
					break;
				case 2:
					GPIOB->ODR =0x2;
					break;
				case 3:
					GPIOB->ODR =0x1;
					break;
			}
		}
		void decodificacion_teclado(){
			switch(contador_teclado){
				case 0: // Si esta en la fila 1
						switch(boton_pulsado){
							case 0x20: // Columna 1 = 1
								tecla=1;
								boton_pulsado=0;
								break;
							case 0x40: // Columna 2 = 2
								tecla=2;
								boton_pulsado=0;
								break; 
							case 0x80: // Columna 3 = 3
								tecla=3;
								boton_pulsado=0;
								break;
							case 0x100: // Columna 4 = A
								tecla=10;
								boton_pulsado=0;
								break;
						}
					break;
				case 1: // Si esta en la fila 2
						switch(boton_pulsado){
							case 0x20: // Columna 1 = 4
								tecla=4;
								boton_pulsado=0;
								break;
							case 0x40: // Columna 2 = 5
								tecla=5;
								boton_pulsado=0;
								break; 
							case 0x80: // Columna 3 = 6
								tecla=6;
								boton_pulsado=0;
								break;
							case 0x100: // Columna 4 = B
								tecla=11;
								boton_pulsado=0;
								break;
						}
					break;
				case 2: // Si esta en la fila 3
					switch(boton_pulsado){
							case 0x20: // Columna 1 = 7
								tecla=7;
								boton_pulsado=0;
								break;
							case 0x40: // Columna 2 = 8
								tecla=8;
								boton_pulsado=0;
								break; 
							case 0x80: // Columna 3 = 9
								tecla=9;
								boton_pulsado=0;
								break;
							case 0x100: // Columna 4 = C
								tecla=12;
								pausa=1;
								boton_pulsado=0;
								break;
						}
					break;
				case 3: // Si esta en la fila 4
					switch(boton_pulsado){ 
							case 0x20: // Columna 1 = *
								tecla=14;
								boton_pulsado=0;
								break;
							case 0x40: // Columna 2 = 0
								tecla=0;
								GPIOA->ODR =convinaciones[0];
								boton_pulsado=0;
								break; 
							case 0x80: // Columna 3 = #
								tecla=15;
								boton_pulsado=0;
								break;
							case 0x100: // Columna 4 = D
								tecla=13;
								pausa=0;
								boton_pulsado=0;
								break;
						}
					break;
			}
		}
// *************************************************

// **************** INTERRUPCIONES *****************
		extern "C"{
			void SysTick_Handler(void){
//				mostrar=1;
				contador_display++;
				contador_teclado++;
				
				if(contador_display>3){
					contador_display=0;
				}
				
				if(contador_teclado==4){
					contador_teclado=0; 
				}
				accion_teclado();
			}
			void EXTI9_5_IRQHandler(void){
				EXTI->PR |=0x1E0; // Limpio la bandera de la interrupcion 
				boton_pulsado=(GPIOB->IDR & 0x1E0); // El resultado de esta operacion me da el boton pulsado 
//				bandera_pulsacion=1;
				decodificacion_teclado();
			}
		}
// *************************************************

// **************** MAIN ***************************
int main(void){
		// ************ PUERTOS ************************
				RCC->AHB1ENR |=0x0E; // Puertos A, B y F
				RCC->APB2ENR |=0x4000; // Activo reloj de la exti 
		// *********************************************
	
		// ************ PINES **************************
	
				GPIOB->MODER =	0x55; // OUTPUT pines 0 a 3 - INPUT pines 5 a 8 
				GPIOB->OTYPER |=0x00; // PUSH-PULL todos los pines 
				GPIOB->OSPEEDR |=0x55; // HIGH-SPEED pines 0 a 8 
				GPIOB->PUPDR |=0xAAAAA; // PULL-UP pines 0 a 3 - PULL-DOWN pines 5 a 8  
	
				GPIOC->MODER =	0x05; // OUTPUT 
				GPIOC->OTYPER |=0x00; // PUSH-PULL 
				GPIOC->OSPEEDR |=0x05; // HIGH-SPEED 
				GPIOC->PUPDR |=0x05; // PULL-UP   
	
				GPIOD->MODER =	0x5555; // OUTPUT pines 0 a 3 - INPUT pines 5 a 8 
				GPIOD->OTYPER |=0x00; // PUSH-PULL todos los pines 
				GPIOD->OSPEEDR |=0x5555; // HIGH-SPEED pines 0 a 8 
				GPIOD->PUPDR |=0x5555; // PULL-UP pines 0 a 3 - PULL-DOWN pines 5 a 8  

		// *********************************************
	
		// ************ SYSTICK ************************
				 // La interrupcion se generara cada 1ms 
		// *********************************************
		
		// ************ EXTI ***************************
				EXTI->IMR =0x1E0; //desenmascaro la interrupcion
				EXTI->RTSR =0x1E0; // Quiero que funcione con flanco de subida
				SYSCFG->EXTICR[1]=0x1110; 
				SYSCFG->EXTICR[2]=0x01;
				NVIC_EnableIRQ(EXTI9_5_IRQn);
		// *********************************************
	
				GPIOC->ODR =0X01;
				GPIOD->ODR =convinaciones[0];
				
		// ************ BUCLE **************************
				while(true){
					
					
					if(tecla<10){
						contMax=tecla;
						parp=0;
					}else if(tecla==14){
						contMax=0;
					}else if(tecla==10){
						tipCont=0;
					}else if(tecla==11){
						tipCont=1;
					}else if(tecla==15){
							if(tipCont==0){
								contMin=contMax+1;
							}else if(tipCont==1){
								contMin=-1;
							}
						while(visu!=contMin){
								if(tipCont==0){
									for(visu=0;visu<(contMax+1);){
										if(pausa==0){
											GPIOD->ODR =convinaciones[visu];
											for(int i=0;i<1000000;i++);
											visu++;
										}
									}
								}else if(tipCont==1){
									for(visu=contMax;visu>-1;){	
										if(pausa==0){
											GPIOD->ODR =convinaciones[visu];
											for(int i=0;i<1000000;i++);
											visu--;
										}
									}
								}		
						}
						contMax=0;
						tecla=16;
						parp=1;
					}
					if(parp==1){
						GPIOC->ODR =0X00;
						for(int i=0;i<1000000;i++);
						GPIOC->ODR =0X01;
						for(int i=0;i<1000000;i++);
					}
				}
		// *********************************************	
}
// *************************************************