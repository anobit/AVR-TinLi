/*
 * timer.h
 *
 * Created: 07.11.2016 10:33:35
 *  Author: AnoBit
 */ 

#include <stdint.h>

#ifndef SCHEDULER_H_
#define SCHEDULER_H_


extern volatile uint8_t ISR_10MS;
extern volatile uint8_t ISR_100MS;

void Scheduler_init(void);



#endif /* TIMER_H_ */