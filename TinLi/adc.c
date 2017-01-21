/*
 * ADC.cpp
 *
 * Created: 21.01.2017 14:36:10
 *  Author: AnoBit
 */ 

#include "adc.h"

void initADC(void){ //doesn't work. need to have a look at 2 or more channels
	ADMUX = (1<<ADLAR) | //Left adjust, so we only need the high byte. Vcc as reference
			0x03;		 //Channel: ADC3
	ADCSRA = 0xE7;		 //Prescaler: 128, Free Running. No interrupts. Starting conversion.
}

uint8_t getADC(){
	return (uint8_t) (ADC>>8); //Get the high byte.
}