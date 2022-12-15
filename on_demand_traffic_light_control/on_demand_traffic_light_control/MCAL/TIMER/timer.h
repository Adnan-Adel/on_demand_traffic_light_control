/*
 * timer.h
 *
 * Created: 12/7/2022 9:28:49 PM
 *  Author: Adnan
 */ 


#ifndef TIMER_H_
#define TIMER_H_
#include "../../Utilities/Registers.h"

#define NUMBER_0F_OVERFLOWS 1000

// TCCR0 pins
#define CS00  0
#define CS01  1
#define CS02  2
#define FOC0  7

// TIFR pins
#define TOV0  0
#define OCF0  0


// No prescaler,  8 bit timer,  CPU_frequecy= 1MHz
void TIMER_init(void);

void TIMER_start(void);

void TIMER_stop(void);






#endif /* TIMER_H_ */