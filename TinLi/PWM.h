/*
 * IncFile1.h
 *
 * Created: 21.01.2017 14:01:08
 *  Author: AnoBit
 */ 


#ifndef PWM_H_
#define PWM_H_

#include "stdint.h"
#include <avr/io.h>

void PWM_init();
void PWM_set(uint8_t dutyCycle);


#endif /* INCFILE1_H_ */