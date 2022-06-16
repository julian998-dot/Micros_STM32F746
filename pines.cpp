#include "Pines.h"
//Pines f1(4,0,1,2,0,0);	
//Pines f2(4,0,1,2,0,0);	
//Pines f3(4,0,1,2,0,0);	
//Pines f4(4,0,1,2,0,0);	
//Pines c1(4,0,1,2,0,0);	
//Pines c2(4,0,1,2,0,0);	
//Pines c3(4,0,1,2,0,0);	
//Pines c4(4,0,1,2,0,0);	
Pines::Pines()
{
	Port=0;
	NumPin=0;
	MODER=0;
	PUPDR=0;
	OTYPER=0;
	OSPEEDR=0;
}

Pines::Pines(int port, int numpin, uint32_t moder, uint32_t pupdr,uint32_t otyper, uint32_t ospeedr)
{
	Port=port;
	NumPin=numpin;
	MODER=moder;
	PUPDR=pupdr;
	OTYPER=otyper;
	OSPEEDR=ospeedr;
}

Pines::~Pines()
{
}
void Pines::setPin(){
	//SET PORT
	RCC->AHB1ENR &=~(3UL<<Port);
	RCC->AHB1ENR |=(1UL<<Port);
	//set MODER
	switch(Port){
		case 0:
			if(MODER==0){GPIOA->MODER&=~(3UL<<2*NumPin);}
				else{
					if(MODER==1){GPIOA->MODER&=~(3UL<<2*NumPin);GPIOA->MODER|=(1UL<<2*NumPin);}
						else{
							if(MODER==2){GPIOA->MODER&=~(3UL<<2*NumPin);GPIOA->MODER|=(2UL<<2*NumPin);}
								else{
									if(MODER==3){GPIOA->MODER&=~(3UL<<2*NumPin);GPIOA->MODER|=(3UL<<2*NumPin);}	
								}
						}
				}
		break;
		case 1:
			if(MODER==0){GPIOB->MODER&=~(3UL<<2*NumPin);}
				else{
					if(MODER==1){GPIOB->MODER&=~(3UL<<2*NumPin);GPIOB->MODER|=(1UL<<2*NumPin);}
						else{
							if(MODER==2){GPIOB->MODER&=~(3UL<<2*NumPin);GPIOB->MODER|=(2UL<<2*NumPin);}
								else{
									if(MODER==3){GPIOB->MODER&=~(3UL<<2*NumPin);GPIOB->MODER|=(3UL<<2*NumPin);}	
								}
						}
				}
		break;
		case 2:
			if(MODER==0){GPIOC->MODER&=~(3UL<<2*NumPin);}
				else{
					if(MODER==1){GPIOC->MODER&=~(3UL<<2*NumPin);GPIOC->MODER|=(1UL<<2*NumPin);}
						else{
							if(MODER==2){GPIOC->MODER&=~(3UL<<2*NumPin);GPIOC->MODER|=(2UL<<2*NumPin);}
								else{
									if(MODER==3){GPIOC->MODER&=~(3UL<<2*NumPin);GPIOC->MODER|=(3UL<<2*NumPin);}	
								}
						}
				}
		break;
		case 3:
			if(MODER==0){GPIOD->MODER&=~(3UL<<2*NumPin);}
				else{
					if(MODER==1){GPIOD->MODER&=~(3UL<<2*NumPin);GPIOD->MODER|=(1UL<<2*NumPin);}
						else{
							if(MODER==2){GPIOD->MODER&=~(3UL<<2*NumPin);GPIOD->MODER|=(2UL<<2*NumPin);}
								else{
									if(MODER==3){GPIOD->MODER&=~(3UL<<2*NumPin);GPIOD->MODER|=(3UL<<2*NumPin);}	
								}
						}
				}
		break;
		case 4:
			if(MODER==0){GPIOE->MODER&=~(3UL<<2*NumPin);}
				else{
					if(MODER==1){GPIOE->MODER&=~(3UL<<2*NumPin);GPIOE->MODER|=(1UL<<2*NumPin);}
						else{
							if(MODER==2){GPIOE->MODER&=~(3UL<<2*NumPin);GPIOE->MODER|=(2UL<<2*NumPin);}
								else{
									if(MODER==3){GPIOE->MODER&=~(3UL<<2*NumPin);GPIOE->MODER|=(3UL<<2*NumPin);}	
								}
						}
				}
		break;
		case 5:
			if(MODER==0){GPIOF->MODER&=~(3UL<<2*NumPin);}
				else{
					if(MODER==1){GPIOF->MODER&=~(3UL<<2*NumPin);GPIOF->MODER|=(1UL<<2*NumPin);}
						else{
							if(MODER==2){GPIOF->MODER&=~(3UL<<2*NumPin);GPIOF->MODER|=(2UL<<2*NumPin);}
								else{
									if(MODER==3){GPIOF->MODER&=~(3UL<<2*NumPin);GPIOF->MODER|=(3UL<<2*NumPin);}	
								}
						}
				}
		break;
		case 6:
			if(MODER==0){GPIOG->MODER&=~(3UL<<2*NumPin);}
				else{
					if(MODER==1){GPIOG->MODER&=~(3UL<<2*NumPin);GPIOG->MODER|=(1UL<<2*NumPin);}
						else{
							if(MODER==2){GPIOG->MODER&=~(3UL<<2*NumPin);GPIOG->MODER|=(2UL<<2*NumPin);}
								else{
									if(MODER==3){GPIOG->MODER&=~(3UL<<2*NumPin);GPIOG->MODER|=(3UL<<2*NumPin);}	
								}
						}
				}
		break;
		case 7:
			if(MODER==0){GPIOH->MODER&=~(3UL<<2*NumPin);}
				else{
					if(MODER==1){GPIOH->MODER&=~(3UL<<2*NumPin);GPIOH->MODER|=(1UL<<2*NumPin);}
						else{
							if(MODER==2){GPIOH->MODER&=~(3UL<<2*NumPin);GPIOH->MODER|=(2UL<<2*NumPin);}
								else{
									if(MODER==3){GPIOH->MODER&=~(3UL<<2*NumPin);GPIOH->MODER|=(3UL<<2*NumPin);}	
								}
						}
				}
		break;
		case 8:
			if(MODER==0){GPIOI->MODER&=~(3UL<<2*NumPin);}
				else{
					if(MODER==1){GPIOI->MODER&=~(3UL<<2*NumPin);GPIOI->MODER|=(1UL<<2*NumPin);}
						else{
							if(MODER==2){GPIOI->MODER&=~(3UL<<2*NumPin);GPIOI->MODER|=(2UL<<2*NumPin);}
								else{
									if(MODER==3){GPIOI->MODER&=~(3UL<<2*NumPin);GPIOI->MODER|=(3UL<<2*NumPin);}	
								}
						}
				}
		break;
		case 9:
			if(MODER==0){GPIOJ->MODER&=~(3UL<<2*NumPin);}
				else{
					if(MODER==1){GPIOJ->MODER&=~(3UL<<2*NumPin);GPIOJ->MODER|=(1UL<<2*NumPin);}
						else{
							if(MODER==2){GPIOJ->MODER&=~(3UL<<2*NumPin);GPIOJ->MODER|=(2UL<<2*NumPin);}
								else{
									if(MODER==3){GPIOJ->MODER&=~(3UL<<2*NumPin);GPIOJ->MODER|=(3UL<<2*NumPin);}	
								}
						}
				}
		break;
		case 10:
			if(MODER==0){GPIOK->MODER&=~(3UL<<2*NumPin);}
				else{
					if(MODER==1){GPIOK->MODER&=~(3UL<<2*NumPin);GPIOK->MODER|=(1UL<<2*NumPin);}
						else{
							if(MODER==2){GPIOK->MODER&=~(3UL<<2*NumPin);GPIOK->MODER|=(2UL<<2*NumPin);}
								else{
									if(MODER==3){GPIOK->MODER&=~(3UL<<2*NumPin);GPIOK->MODER|=(3UL<<2*NumPin);}	
								}
						}
				}
		break;
		default:
		break;				
	}
	//set PUPDR
	switch(Port){
		case 0:
			if(PUPDR==0){GPIOA->PUPDR&=~(3UL<<2*NumPin);}
				else{
					if(PUPDR==1){GPIOA->PUPDR&=~(3UL<<2*NumPin);GPIOA->PUPDR|=(1UL<<2*NumPin);}
						else{
							if(PUPDR==2){GPIOA->PUPDR&=~(3UL<<2*NumPin);GPIOA->PUPDR|=(2UL<<2*NumPin);}
								else{
									if(PUPDR==3){GPIOA->PUPDR&=~(3UL<<2*NumPin);GPIOA->PUPDR|=(3UL<<2*NumPin);}	
								}
						}
				}
		break;
		case 1:
			if(PUPDR==0){GPIOB->PUPDR&=~(3UL<<2*NumPin);}
				else{
					if(PUPDR==1){GPIOB->PUPDR&=~(3UL<<2*NumPin);GPIOB->PUPDR|=(1UL<<2*NumPin);}
						else{
							if(PUPDR==2){GPIOB->PUPDR&=~(3UL<<2*NumPin);GPIOB->PUPDR|=(2UL<<2*NumPin);}
								else{
									if(PUPDR==3){GPIOB->PUPDR&=~(3UL<<2*NumPin);GPIOB->PUPDR|=(3UL<<2*NumPin);}	
								}
						}
				}
		break;
		case 2:
			if(PUPDR==0){GPIOC->PUPDR&=~(3UL<<2*NumPin);}
				else{
					if(PUPDR==1){GPIOC->PUPDR&=~(3UL<<2*NumPin);GPIOC->PUPDR|=(1UL<<2*NumPin);}
						else{
							if(PUPDR==2){GPIOC->PUPDR&=~(3UL<<2*NumPin);GPIOC->PUPDR|=(2UL<<2*NumPin);}
								else{
									if(PUPDR==3){GPIOC->PUPDR&=~(3UL<<2*NumPin);GPIOC->PUPDR|=(3UL<<2*NumPin);}	
								}
						}
				}
		break;
		case 3:
			if(PUPDR==0){GPIOD->PUPDR&=~(3UL<<2*NumPin);}
				else{
					if(PUPDR==1){GPIOD->PUPDR&=~(3UL<<2*NumPin);GPIOD->PUPDR|=(1UL<<2*NumPin);}
						else{
							if(PUPDR==2){GPIOD->PUPDR&=~(3UL<<2*NumPin);GPIOD->PUPDR|=(2UL<<2*NumPin);}
								else{
									if(PUPDR==3){GPIOD->PUPDR&=~(3UL<<2*NumPin);GPIOD->PUPDR|=(3UL<<2*NumPin);}	
								}
						}
				}
		break;
		case 4:
			if(PUPDR==0){GPIOE->PUPDR&=~(3UL<<2*NumPin);}
				else{
					if(PUPDR==1){GPIOE->PUPDR&=~(3UL<<2*NumPin);GPIOE->PUPDR|=(1UL<<2*NumPin);}
						else{
							if(PUPDR==2){GPIOE->PUPDR&=~(3UL<<2*NumPin);GPIOE->PUPDR|=(2UL<<2*NumPin);}
								else{
									if(PUPDR==3){GPIOE->PUPDR&=~(3UL<<2*NumPin);GPIOE->PUPDR|=(3UL<<2*NumPin);}	
								}
						}
				}
		break;
		case 5:
			if(PUPDR==0){GPIOF->PUPDR&=~(3UL<<2*NumPin);}
				else{
					if(PUPDR==1){GPIOF->PUPDR&=~(3UL<<2*NumPin);GPIOF->PUPDR|=(1UL<<2*NumPin);}
						else{
							if(PUPDR==2){GPIOF->PUPDR&=~(3UL<<2*NumPin);GPIOF->PUPDR|=(2UL<<2*NumPin);}
								else{
									if(PUPDR==3){GPIOF->PUPDR&=~(3UL<<2*NumPin);GPIOF->PUPDR|=(3UL<<2*NumPin);}	
								}
						}
				}
		break;
		case 6:
			if(PUPDR==0){GPIOG->PUPDR&=~(3UL<<2*NumPin);}
				else{
					if(PUPDR==1){GPIOG->PUPDR&=~(3UL<<2*NumPin);GPIOG->PUPDR|=(1UL<<2*NumPin);}
						else{
							if(PUPDR==2){GPIOG->PUPDR&=~(3UL<<2*NumPin);GPIOG->PUPDR|=(2UL<<2*NumPin);}
								else{
									if(PUPDR==3){GPIOG->PUPDR&=~(3UL<<2*NumPin);GPIOG->PUPDR|=(3UL<<2*NumPin);}	
								}
						}
				}
		break;
		case 7:
			if(PUPDR==0){GPIOH->PUPDR&=~(3UL<<2*NumPin);}
				else{
					if(PUPDR==1){GPIOH->PUPDR&=~(3UL<<2*NumPin);GPIOH->PUPDR|=(1UL<<2*NumPin);}
						else{
							if(PUPDR==2){GPIOH->PUPDR&=~(3UL<<2*NumPin);GPIOH->PUPDR|=(2UL<<2*NumPin);}
								else{
									if(PUPDR==3){GPIOH->PUPDR&=~(3UL<<2*NumPin);GPIOH->PUPDR|=(3UL<<2*NumPin);}	
								}
						}
				}
		break;
		case 8:
			if(PUPDR==0){GPIOI->PUPDR&=~(3UL<<2*NumPin);}
				else{
					if(PUPDR==1){GPIOI->PUPDR&=~(3UL<<2*NumPin);GPIOI->PUPDR|=(1UL<<2*NumPin);}
						else{
							if(PUPDR==2){GPIOI->PUPDR&=~(3UL<<2*NumPin);GPIOI->PUPDR|=(2UL<<2*NumPin);}
								else{
									if(PUPDR==3){GPIOI->PUPDR&=~(3UL<<2*NumPin);GPIOI->PUPDR|=(3UL<<2*NumPin);}	
								}
						}
				}
		break;
		case 9:
			if(PUPDR==0){GPIOJ->PUPDR&=~(3UL<<2*NumPin);}
				else{
					if(PUPDR==1){GPIOJ->PUPDR&=~(3UL<<2*NumPin);GPIOJ->PUPDR|=(1UL<<2*NumPin);}
						else{
							if(PUPDR==2){GPIOJ->PUPDR&=~(3UL<<2*NumPin);GPIOJ->PUPDR|=(2UL<<2*NumPin);}
								else{
									if(PUPDR==3){GPIOJ->PUPDR&=~(3UL<<2*NumPin);GPIOJ->PUPDR|=(3UL<<2*NumPin);}	
								}
						}
				}
		break;
		case 10:
			if(PUPDR==0){GPIOK->PUPDR&=~(3UL<<2*NumPin);}
				else{
					if(PUPDR==1){GPIOK->PUPDR&=~(3UL<<2*NumPin);GPIOK->PUPDR|=(1UL<<2*NumPin);}
						else{
							if(PUPDR==2){GPIOK->PUPDR&=~(3UL<<2*NumPin);GPIOK->PUPDR|=(2UL<<2*NumPin);}
								else{
									if(PUPDR==3){GPIOK->PUPDR&=~(3UL<<2*NumPin);GPIOK->PUPDR|=(3UL<<2*NumPin);}	
								}
						}
				}
		break;
		default:
		break;				
	}
  //set OTYPER
	switch(Port){
		case 0:
			if(OTYPER==0){GPIOA->OTYPER&=~(3UL<<2*NumPin);}
				else{if(OTYPER==1){GPIOA->OTYPER&=~(3UL<<2*NumPin);GPIOA->OTYPER|=(1UL<<2*NumPin);}				}
		break;
		case 1:
			if(OTYPER==0){GPIOB->OTYPER&=~(1UL<<NumPin);}
				else{if(OTYPER==1){GPIOB->OTYPER&=~(1UL<<NumPin);GPIOB->OTYPER|=(1UL<<NumPin);}}
		break;
		case 2:
			if(OTYPER==0){GPIOC->OTYPER&=~(1UL<<NumPin);}
				else{if(OTYPER==1){GPIOC->OTYPER&=~(1UL<<NumPin);GPIOC->OTYPER|=(1UL<<NumPin);}}
		break;
		case 3:
			if(OTYPER==0){GPIOD->OTYPER&=~(1UL<<NumPin);}
				else{if(OTYPER==1){GPIOD->OTYPER&=~(1UL<<NumPin);GPIOD->OTYPER|=(1UL<<NumPin);}}
		break;
		case 4:
			if(OTYPER==0){GPIOE->OTYPER&=~(1UL<<NumPin);}
				else{if(OTYPER==1){GPIOE->OTYPER&=~(1UL<<NumPin);GPIOE->OTYPER|=(1UL<<NumPin);}}
		break;
		case 5:
			if(OTYPER==0){GPIOF->OTYPER&=~(1UL<<NumPin);}
				else{if(OTYPER==1){GPIOF->OTYPER&=~(1UL<<NumPin);GPIOF->OTYPER|=(1UL<<NumPin);}}
		break;
		case 6:
			if(OTYPER==0){GPIOG->OTYPER&=~(1UL<<NumPin);}
				else{if(OTYPER==1){GPIOG->OTYPER&=~(1UL<<NumPin);GPIOG->OTYPER|=(1UL<<NumPin);}}
		break;
		case 7:
			if(OTYPER==0){GPIOH->OTYPER&=~(1UL<<NumPin);}
				else{if(OTYPER==1){GPIOH->OTYPER&=~(1UL<<NumPin);GPIOH->OTYPER|=(1UL<<NumPin);}}
		break;
		case 8:
			if(OTYPER==0){GPIOI->OTYPER&=~(1UL<<NumPin);}
				else{if(OTYPER==1){GPIOI->OTYPER&=~(1UL<<NumPin);GPIOI->OTYPER|=(1UL<<NumPin);}}
		break;
		case 9:
			if(OTYPER==0){GPIOJ->OTYPER&=~(1UL<<NumPin);}
				else{if(OTYPER==1){GPIOJ->OTYPER&=~(1UL<<NumPin);GPIOJ->OTYPER|=(1UL<<NumPin);}}
		break;
		case 10:
			if(OTYPER==0){GPIOK->OTYPER&=~(1UL<<NumPin);}
				else{if(OTYPER==1){GPIOK->OTYPER&=~(1UL<<NumPin);GPIOK->OTYPER|=(1UL<<NumPin);}}
		break;
		default:
		break;				
	}

	//set OSPEEDR
	switch(Port){
		case 0:
			if(OSPEEDR==0){GPIOA->OSPEEDR&=~(3UL<<2*NumPin);}
				else{
					if(OSPEEDR==1){GPIOA->OSPEEDR&=~(3UL<<2*NumPin);GPIOA->OSPEEDR|=(1UL<<2*NumPin);}
						else{
							if(OSPEEDR==2){GPIOA->OSPEEDR&=~(3UL<<2*NumPin);GPIOA->OSPEEDR|=(2UL<<2*NumPin);}
								else{
									if(OSPEEDR==3){GPIOA->OSPEEDR&=~(3UL<<2*NumPin);GPIOA->OSPEEDR|=(3UL<<2*NumPin);}	
								}
						}
				}
		break;
		case 1:
			if(OSPEEDR==0){GPIOB->OSPEEDR&=~(3UL<<2*NumPin);}
				else{
					if(OSPEEDR==1){GPIOB->OSPEEDR&=~(3UL<<2*NumPin);GPIOB->OSPEEDR|=(1UL<<2*NumPin);}
						else{
							if(OSPEEDR==2){GPIOB->OSPEEDR&=~(3UL<<2*NumPin);GPIOB->OSPEEDR|=(2UL<<2*NumPin);}
								else{
									if(OSPEEDR==3){GPIOB->OSPEEDR&=~(3UL<<2*NumPin);GPIOB->OSPEEDR|=(3UL<<2*NumPin);}	
								}
						}
				}
		break;
		case 2:
			if(OSPEEDR==0){GPIOC->OSPEEDR&=~(3UL<<2*NumPin);}
				else{
					if(OSPEEDR==1){GPIOC->OSPEEDR&=~(3UL<<2*NumPin);GPIOC->OSPEEDR|=(1UL<<2*NumPin);}
						else{
							if(OSPEEDR==2){GPIOC->OSPEEDR&=~(3UL<<2*NumPin);GPIOC->OSPEEDR|=(2UL<<2*NumPin);}
								else{
									if(OSPEEDR==3){GPIOC->OSPEEDR&=~(3UL<<2*NumPin);GPIOC->OSPEEDR|=(3UL<<2*NumPin);}	
								}
						}
				}
		break;
		case 3:
			if(OSPEEDR==0){GPIOD->OSPEEDR&=~(3UL<<2*NumPin);}
				else{
					if(OSPEEDR==1){GPIOD->OSPEEDR&=~(3UL<<2*NumPin);GPIOD->OSPEEDR|=(1UL<<2*NumPin);}
						else{
							if(OSPEEDR==2){GPIOD->OSPEEDR&=~(3UL<<2*NumPin);GPIOD->OSPEEDR|=(2UL<<2*NumPin);}
								else{
									if(OSPEEDR==3){GPIOD->OSPEEDR&=~(3UL<<2*NumPin);GPIOD->OSPEEDR|=(3UL<<2*NumPin);}	
								}
						}
				}
		break;
		case 4:
			if(OSPEEDR==0){GPIOE->OSPEEDR&=~(3UL<<2*NumPin);}
				else{
					if(OSPEEDR==1){GPIOE->OSPEEDR&=~(3UL<<2*NumPin);GPIOE->OSPEEDR|=(1UL<<2*NumPin);}
						else{
							if(OSPEEDR==2){GPIOE->OSPEEDR&=~(3UL<<2*NumPin);GPIOE->OSPEEDR|=(2UL<<2*NumPin);}
								else{
									if(OSPEEDR==3){GPIOE->OSPEEDR&=~(3UL<<2*NumPin);GPIOE->OSPEEDR|=(3UL<<2*NumPin);}	
								}
						}
				}
		break;
		case 5:
			if(OSPEEDR==0){GPIOF->OSPEEDR&=~(3UL<<2*NumPin);}
				else{
					if(OSPEEDR==1){GPIOF->OSPEEDR&=~(3UL<<2*NumPin);GPIOF->OSPEEDR|=(1UL<<2*NumPin);}
						else{
							if(OSPEEDR==2){GPIOF->OSPEEDR&=~(3UL<<2*NumPin);GPIOF->OSPEEDR|=(2UL<<2*NumPin);}
								else{
									if(OSPEEDR==3){GPIOF->OSPEEDR&=~(3UL<<2*NumPin);GPIOF->OSPEEDR|=(3UL<<2*NumPin);}	
								}
						}
				}
		break;
		case 6:
			if(OSPEEDR==0){GPIOG->OSPEEDR&=~(3UL<<2*NumPin);}
				else{
					if(OSPEEDR==1){GPIOG->OSPEEDR&=~(3UL<<2*NumPin);GPIOG->OSPEEDR|=(1UL<<2*NumPin);}
						else{
							if(OSPEEDR==2){GPIOG->OSPEEDR&=~(3UL<<2*NumPin);GPIOG->OSPEEDR|=(2UL<<2*NumPin);}
								else{
									if(OSPEEDR==3){GPIOG->OSPEEDR&=~(3UL<<2*NumPin);GPIOG->OSPEEDR|=(3UL<<2*NumPin);}	
								}
						}
				}
		break;
		case 7:
			if(OSPEEDR==0){GPIOH->OSPEEDR&=~(3UL<<2*NumPin);}
				else{
					if(OSPEEDR==1){GPIOH->OSPEEDR&=~(3UL<<2*NumPin);GPIOH->OSPEEDR|=(1UL<<2*NumPin);}
						else{
							if(OSPEEDR==2){GPIOH->OSPEEDR&=~(3UL<<2*NumPin);GPIOH->OSPEEDR|=(2UL<<2*NumPin);}
								else{
									if(OSPEEDR==3){GPIOH->OSPEEDR&=~(3UL<<2*NumPin);GPIOH->OSPEEDR|=(3UL<<2*NumPin);}	
								}
						}
				}
		break;
		case 8:
			if(OSPEEDR==0){GPIOI->OSPEEDR&=~(3UL<<2*NumPin);}
				else{
					if(OSPEEDR==1){GPIOI->OSPEEDR&=~(3UL<<2*NumPin);GPIOI->OSPEEDR|=(1UL<<2*NumPin);}
						else{
							if(OSPEEDR==2){GPIOI->OSPEEDR&=~(3UL<<2*NumPin);GPIOI->OSPEEDR|=(2UL<<2*NumPin);}
								else{
									if(OSPEEDR==3){GPIOI->OSPEEDR&=~(3UL<<2*NumPin);GPIOI->OSPEEDR|=(3UL<<2*NumPin);}	
								}
						}
				}
		break;
		case 9:
			if(OSPEEDR==0){GPIOJ->OSPEEDR&=~(3UL<<2*NumPin);}
				else{
					if(OSPEEDR==1){GPIOJ->OSPEEDR&=~(3UL<<2*NumPin);GPIOJ->OSPEEDR|=(1UL<<2*NumPin);}
						else{
							if(OSPEEDR==2){GPIOJ->OSPEEDR&=~(3UL<<2*NumPin);GPIOJ->OSPEEDR|=(2UL<<2*NumPin);}
								else{
									if(OSPEEDR==3){GPIOJ->OSPEEDR&=~(3UL<<2*NumPin);GPIOJ->OSPEEDR|=(3UL<<2*NumPin);}	
								}
						}
				}
		break;
		case 10:
			if(OSPEEDR==0){GPIOK->OSPEEDR&=~(3UL<<2*NumPin);}
				else{
					if(OSPEEDR==1){GPIOK->OSPEEDR&=~(3UL<<2*NumPin);GPIOK->OSPEEDR|=(1UL<<2*NumPin);}
						else{
							if(OSPEEDR==2){GPIOK->OSPEEDR&=~(3UL<<2*NumPin);GPIOK->OSPEEDR|=(2UL<<2*NumPin);}
								else{
									if(OSPEEDR==3){GPIOK->OSPEEDR&=~(3UL<<2*NumPin);GPIOK->OSPEEDR|=(3UL<<2*NumPin);}	
								}
						}
				}
		break;
		default:
		break;				
	}

}


int Pines::getValuePin(){
	int state;
	switch(Port){
		case 0:
		state = GPIOA->IDR & (1UL<<NumPin);
		break;
		case 1:
		state = GPIOB->IDR & (1UL<<NumPin);
		break;
		case 2:
		state = GPIOC->IDR & (1UL<<NumPin);
		break;
		case 3:
		state = GPIOD->IDR & (1UL<<NumPin);
		break;
		case 4:
		state = GPIOE->IDR & (1UL<<NumPin);
		break;
		case 5:
		state = GPIOF->IDR & (1UL<<NumPin);
		break;
		case 6:
		state = GPIOG->IDR & (1UL<<NumPin);
		break;
		case 7:
		state = GPIOH->IDR & (1UL<<NumPin);
		break;
		case 8:
		state = GPIOI->IDR & (1UL<<NumPin);
		break;
		case 9:
		state = GPIOJ->IDR & (1UL<<NumPin);
		break;
		case 10:
		state = GPIOK->IDR & (1UL<<NumPin);
		break;
		default:
		break;				
	}
	return state;
}
void Pines::setValuePin(bool Value){
	switch(Port){
		case 0:
		if(Value==0){GPIOA->ODR &= ~(1UL<<NumPin);}
			else{GPIOA->ODR |= (1UL<<NumPin);}
		break;
		case 1:
		if(Value==0){GPIOB->ODR &= ~(1UL<<NumPin);}
			else{GPIOB->ODR |= (1UL<<NumPin);}
		break;
		case 2:
		if(Value==0){GPIOC->ODR &= ~(1UL<<NumPin);}
			else{GPIOC->ODR |= (1UL<<NumPin);}
		break;
		case 3:
		if(Value==0){GPIOD->ODR &= ~(1UL<<NumPin);}
			else{GPIOD->ODR |= (1UL<<NumPin);}
		break;
		case 4:
		if(Value==0){GPIOE->ODR &= ~(1UL<<NumPin);}
			else{GPIOE->ODR |= (1UL<<NumPin);}
		break;
		case 5:
		if(Value==0){GPIOF->ODR &= ~(1UL<<NumPin);}
			else{GPIOF->ODR |= (1UL<<NumPin);}
		break;
		case 6:
		if(Value==0){GPIOG->ODR &= ~(1UL<<NumPin);}
			else{GPIOG->ODR |= (1UL<<NumPin);}
		break;
		case 7:
		if(Value==0){GPIOH->ODR &= ~(1UL<<NumPin);}
			else{GPIOH->ODR |= (1UL<<NumPin);}
		break;
		case 8:
		if(Value==0){GPIOI->ODR &= ~(1UL<<NumPin);}
			else{GPIOI->ODR |= (1UL<<NumPin);}
		break;
		case 9:
		if(Value==0){GPIOJ->ODR &= ~(1UL<<NumPin);}
			else{GPIOJ->ODR |= (1<<NumPin);}
		break;
		case 10:
		if(Value==0){GPIOK->ODR &= ~(1UL<<NumPin);}
			else{GPIOK->ODR |= (1UL<<NumPin);}
		break;
		default:
		break;				
	}
}