/*
 * CPPFile1.cpp
 *
 * Created: 21.01.2017 14:00:56
 *  Author: AnoBit
 */ 

#include "pwm.h"

//Init OC0B with FastPWM, 8 bit.
void PWM_init(void)
{
	
	//IO Pin
	DDRB|= 1<<1;
	PORTB &= ~(1<<1);
	
	// Timer 0
	TCCR0B |= (1<<WGM02); 	// FastPWM, 8-Bit, OCRA as top
	TCCR0B |= (1<<CS01);	// Prescaler 64 -> 61Hz
	
	TCCR0A |= (1<<COM0B1) | (1<<WGM01) | (1<<WGM00); 
	
	PWM_set(0);
}

//Value from 0..255, 255 = 100% Duty Cycle
void PWM_set(uint8_t value)
{
	
	if(value == 0 || value >= 255)
	{
		//PWM aus
		TCCR0A &= ~(1<<COM0B1);
		//Pin entsprechend beschalten.
		if(value == 255)
			PORTB |= (1<<1); //Dauer-an
		else
			PORTB &= ~(1<<1);//Dauer-aus

	}
	else
	{
		//PWM an
		TCCR0A |= (1<<COM0B1);
	}

	OCR0B = value;
}