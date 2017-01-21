/*
 * timer.c
 *
 * Created: 07.11.2016 10:35:11
 *  Author: AnoBit
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include "scheduler.h"
#include "uart.h"

volatile uint8_t ISR_10MS = 0;
volatile uint8_t ISR_100MS = 0;

void Scheduler_init(void){
	
	// Timer 1 konfigurieren
	TCCR1 |= (1<<CTC1); 				// CTC-Modus
	TCCR1 |= (1<<CS12) | (1<<CS11) | (1<<CS10);	// Prescaler 64 CHECK!

	//CTC's einstellen
//	OCR1B = 25000-1;		//100ms
	OCR1A = 156;			//10ms
	
	//Interrupts aktivieren
	TIMSK = (1<<OCIE1A);	//OCR1A CTC-Interrupt aktivieren.
	
}

//10ms Interrupt. Just set the flags!
//We don't want to get interrupts stacked.
ISR (TIMER1_COMPA_vect){
	volatile static uint8_t cnt=0;
	cnt++;
	
	//I know this is set a bit shorter than 10ms.. But we don't need high precision..
	ISR_10MS = 1;
		
	if(cnt>=10){
		ISR_100MS = 1;
		cnt = 0;
	}
}

