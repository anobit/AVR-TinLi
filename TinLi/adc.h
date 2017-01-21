/*
 * adc.h
 *
 * Created: 21.01.2017 16:20:32
 *  Author: AnoBit
 */ 


#ifndef ADC_H_
#define ADC_H_

#include <avr/io.h>

void initADC(void);

uint8_t getADC();


#endif /* ADC_H_ */