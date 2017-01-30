/*
 * adc.h
 *
 * Created: 21.01.2017 16:20:32
 *  Author: AnoBit
 */ 


#ifndef ADC_H_
#define ADC_H_

#include <avr/io.h>

void ADC_init(unsigned int channel);

uint8_t ADC_getValue();


#endif /* ADC_H_ */