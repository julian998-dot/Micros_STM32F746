# ifndef PINES_H
# define PINES_H

# include <stdio.h>
# include "STM32F7xx.h"

class Pines
{
	private:
		
		int Port;
		int NumPin;
	  uint32_t MODER;
		uint32_t PUPDR;
		uint32_t OTYPER;
		uint32_t OSPEEDR;
	
	public:
		Pines();
		Pines(int Port, int NumPin, uint32_t MODER, uint32_t PUPDR,uint32_t OTYPER, uint32_t OSPEEDR);
		~Pines();
	//configurar pin
	void setPin();
	//obtener valor
	int getValuePin();
	//poner valor
	void setValuePin(bool value);
};
# endif
