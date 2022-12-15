/*
 * interrupt.h
 *
 * Created: 12/7/2022 9:28:24 PM
 *  Author: Adnan
 */ 


#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#include "../../Utilities/Registers.h"


// MCUCR PINS
// INT0
#define ISC00 0
#define ISC01 1
// INT1
#define ISC10 2
#define ISC11 3

// GICR PINS
#define INT2 5
#define INT0 6
#define INT1 7

// GIFR PINS
#define INTF2 5
#define INTF0 6
#define INTF1 7


/*******************************************************************/
/*      INTERRUPT Vectors
/******************************************************************/
/* External interrupt vectors */
/* External Interrupt Request 0 */
#define EXT_INT_0 __vector_1

/* External Interrupt Request 1 */
#define EXT_INT_1 __vector_2

/* External Interrupt Request 2 */
#define EXT_INT_2 __vector_3

/* Set global interrupts, set the I bit in status register to 1 */
#define sei() __asm__ __volatile__ ("sei" ::: "memory")

/* Clear global interrupts, set the I bit in status register to 0 */
#define cli() __asm__ __volatile__ ("cli" ::: "memory")

/* Macro defines ISR */
#define ISR(INT_VECT)void INT_VECT(void) __attribute__ ((signal,used));\
void INT_VECT(void)

// Functions prototypes
void INTERRRUPT_init(void);



#endif /* INTERRUPT_H_ */