/*
 * TinLi.cpp
 *
 * Created: 21.01.2017 13:35:13
 * Author : AnoBit
 */ 

#include <avr/io.h>

//Pinout
/*									_________
	  (PCINT5/(~RESET)/ADC0/dW)	PB5	|°		|	VCC
(PCINT3/XTAL1/CLKI/~(OC1B)/ADC3)PB3	|		|	PB2	(SCK/USCK/SCL/ADC1/T0/INT0/PCINT2)
(PCINT4/XTAL2/CLKO/OC1B/ADC2)	PB4 |		|	PB1	(MISO/DO/AIN1/OC0B/OC1A/PCINT1)
								GND |_______|	PB0	(MOSI/DI/SDA/AIN0/OC0A/~(OC1A)/AREF/PCINT0)
*/

//Böärd Cönnectiöns
/*

PIN		USAGE					DESCRIPTION

PB0		GPIO 1					Software UART / SPI / I2C?
PB1		PWM OUTPUT				PWM for Led Mosfet
PB2		GPIO 2					Software UART / SPI / I2C?
PB3		POTI INPUT				Set Maximum Current (Max Duty Cycle) / Set PWM Duty Cycle
PB4		GPIO 3 / ANALOG IN		GPIO / SPI / Set PWM Duty Cycle
PB5		GPIO 4 / (~RESET)		GPIO / SPI / Hardware Reset

*/

//NOTE: All inits are calculated for 1MHz operation.

#include "adc.h"
#include "pwm.h"
#include "scheduler.h"

void init(){
	
}

void cycle_10ms(){
	
}

void cycle_100ms(){
	
}

int main(void)
{
	init();
	
	while (1)
	{
		if(ISR_10MS){
			ISR_10MS = 0;
			cycle_10ms();
		}
		
		if(ISR_100MS){
			ISR_100MS = 0;
			cycle_100ms();
		}
	}
}

