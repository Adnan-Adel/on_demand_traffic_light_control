/*
 * timer.c
 *
 * Created: 12/7/2022 9:28:32 PM
 *  Author: Adnan
 */ 

#include "timer.h"

uint32_t_m overflow_counter= 0;

void TIMER_init(void)
{
	TCCR0= 0x00;   // Normal mode
	
	// Set timer initial value
	TCNT0= 6; 
}

void TIMER_start(void)
{
		SET_BIT(TCCR0, CS00);    // No prescale
		
		while(NUMBER_0F_OVERFLOWS > overflow_counter)
		{
			// Will be repeated 1000 times
			while((TIFR & (1 << 0)) == 0);
			
			// Clear overflow flag
			SET_BIT(TIFR, TOV0);
			
			overflow_counter++;
		}
		overflow_counter= 0;
}

void TIMER_stop(void)
{	
	TCCR0= 0x00;
}

