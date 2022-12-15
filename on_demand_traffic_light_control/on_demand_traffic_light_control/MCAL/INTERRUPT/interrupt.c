/*
 * interrupt.c
 *
 * Created: 12/7/2022 9:28:14 PM
 *  Author: Adnan
 */ 
#include "interrupt.h"
#include "../TIMER/timer.h"


void INTERRRUPT_init(void)
{	
	/* Enable global interrupts -> setting bit 7 in the status register to 1 */
	sei();
	
	/* Choose the external interrupt sense - sense on rising edge */
	MCUCR |= (1 << ISC00) | (1 << ISC01);
	
	/* Enable external interrupt0 - INT0 */
	GICR |= (1 << INT0);
}
