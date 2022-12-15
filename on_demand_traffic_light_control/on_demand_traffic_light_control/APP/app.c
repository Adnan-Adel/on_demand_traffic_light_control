/*
 * app.c
 *
 * Created: 12/7/2022 9:30:09 PM
 *  Author: Adnan
 */ 
#include "app.h"
#include <avr/interrupt.h>
 
// Global Variables
DIO_Value Val;
uint8_t index_i=0;
volatile uint8_t button_state= BUTTON_NOT_PRESSED;
volatile uint8_t current_state=0;


void APP_init(void)
{
	// Initializing Leds
	LED_init(PEDSTRAIN_LED_RED_PORT, PEDSTRAIN_LED_RED_PIN);
	LED_init(PEDSTRAIN_LED_YELLOW_PORT, PEDSTRAIN_LED_YELLOW_PIN);
	LED_init(PEDSTRAIN_LED_GREEN_PORT, PEDSTRAIN_LED_GREEN_PIN);
	
	LED_init(CAR_LED_RED_PORT, CAR_LED_RED_PIN);
	LED_init(CAR_LED_YELLOW_PORT, CAR_LED_YELLOW_PIN);
	LED_init(CAR_LED_GREEN_PORT, CAR_LED_GREEN_PIN);
	
	// Initializing Button
	BUTTON_init(BUTTON_PORT, BUTTON_PIN);
	
	// Initializing Timer
	TIMER_init();
	
	/* Initializing interrupts */
	INTERRRUPT_init();
}

void APP_start(void)
{
/* ---------------------------------------------- STATE 1 ---------------------------------------------- */	
		current_state= 1; // CAR_LED_GREEN IS ON 
		LED_on(PEDSTRAIN_LED_RED_PORT, PEDSTRAIN_LED_RED_PIN);
		LED_on(CAR_LED_GREEN_PORT, CAR_LED_GREEN_PIN);
	
		for(index_i = 0; index_i < 20; index_i++)
		{
			// If button is not pressed
			TIMER_start();
			TIMER_stop();
		}
		LED_off(CAR_LED_GREEN_PORT, CAR_LED_GREEN_PIN);
	
/* ---------------------------------------------- STATE 2 ---------------------------------------------- */		
		current_state= 2; // CAR_LED_YELLOW IS ON
		for(index_i = 0; index_i < 10; index_i++)
		{

			// If button is not pressed
			LED_on(CAR_LED_YELLOW_PORT, CAR_LED_YELLOW_PIN);
			TIMER_start();
			TIMER_stop();
			LED_off(CAR_LED_YELLOW_PORT, CAR_LED_YELLOW_PIN);
			TIMER_start();
			TIMER_stop();
		}
		LED_off(CAR_LED_YELLOW_PORT, CAR_LED_YELLOW_PIN);
		LED_off(PEDSTRAIN_LED_RED_PORT, PEDSTRAIN_LED_RED_PIN);
		
/* ---------------------------------------------- STATE 3 ---------------------------------------------- */	
			current_state= 3; // CAR_LED_RED IS ON
			LED_on(PEDSTRAIN_LED_GREEN_PORT, PEDSTRAIN_LED_GREEN_PIN);
			LED_on(CAR_LED_RED_PORT, CAR_LED_RED_PIN);
			for(index_i = 0; index_i < 20; index_i++)
			{	
				// If button is not pressed
				TIMER_start();
				TIMER_stop();
			}
			LED_off(CAR_LED_RED_PORT, CAR_LED_RED_PIN);
			

/* ---------------------------------------------- STATE 2 ---------------------------------------------- */		
			current_state= 2; // CAR_LED_YELLOW IS ON
			for(index_i = 0; index_i < 10; index_i++)
			{

				// If button is not pressed
				LED_on(CAR_LED_YELLOW_PORT, CAR_LED_YELLOW_PIN);
				TIMER_start();
				TIMER_stop();
				LED_off(CAR_LED_YELLOW_PORT, CAR_LED_YELLOW_PIN);
				TIMER_start();
				TIMER_stop();
			}
			LED_off(CAR_LED_YELLOW_PORT, CAR_LED_YELLOW_PIN);
			LED_off(PEDSTRAIN_LED_GREEN_PORT, PEDSTRAIN_LED_GREEN_PIN);
			
			
		APP_start();      // Returns to application start
}

/* ------------------------------- ISR ------------------------------- */
ISR(INT0_vect)
{
	button_state = BUTTON_PRESSED;
	
	switch(current_state)
	{
		case 1: // Button was pressed when car_led_green was on
				LED_off(CAR_LED_GREEN_PORT, CAR_LED_GREEN_PIN);
				for(index_i = 0; index_i < 20; index_i++)
				{
					LED_toggle(CAR_LED_YELLOW_PORT, CAR_LED_YELLOW_PIN);
					LED_toggle(PEDSTRAIN_LED_YELLOW_PORT, PEDSTRAIN_LED_YELLOW_PIN);
					TIMER_start();
					TIMER_stop();
				}
				LED_off(CAR_LED_YELLOW_PORT, CAR_LED_YELLOW_PIN);
				LED_off(PEDSTRAIN_LED_YELLOW_PORT, PEDSTRAIN_LED_YELLOW_PIN);

				LED_off(PEDSTRAIN_LED_RED_PORT, PEDSTRAIN_LED_RED_PIN);
				LED_on(CAR_LED_RED_PORT, CAR_LED_RED_PIN);
				LED_on(PEDSTRAIN_LED_GREEN_PORT, PEDSTRAIN_LED_GREEN_PIN);
				for(index_i = 0; index_i < 20; index_i++)
				{
					TIMER_start();
					TIMER_stop();
				}
				LED_off(CAR_LED_RED_PORT, CAR_LED_RED_PIN);

				for(index_i = 0; index_i < 20; index_i++)
				{
					LED_toggle(CAR_LED_YELLOW_PORT, CAR_LED_YELLOW_PIN);
					LED_toggle(PEDSTRAIN_LED_YELLOW_PORT, PEDSTRAIN_LED_YELLOW_PIN);
					TIMER_start();
					TIMER_stop();
				}
				LED_off(CAR_LED_YELLOW_PORT, CAR_LED_YELLOW_PIN);
				LED_off(PEDSTRAIN_LED_YELLOW_PORT, PEDSTRAIN_LED_YELLOW_PIN);
				LED_off(PEDSTRAIN_LED_GREEN_PORT, PEDSTRAIN_LED_GREEN_PIN);

				button_state = BUTTON_NOT_PRESSED;  // Returns button state to initial (not pressed)

				APP_start();      // Returns to application start
		break;
		
		case 2: // Button was pressed when car_led_yellow was on
			for(index_i = 0; index_i < 20; index_i++)
			{
				LED_toggle(CAR_LED_YELLOW_PORT, CAR_LED_YELLOW_PIN);
				LED_toggle(PEDSTRAIN_LED_YELLOW_PORT, PEDSTRAIN_LED_YELLOW_PIN);
				TIMER_start();
				TIMER_stop();
			}
			LED_off(CAR_LED_YELLOW_PORT, CAR_LED_YELLOW_PIN);
			LED_off(PEDSTRAIN_LED_YELLOW_PORT, PEDSTRAIN_LED_YELLOW_PIN);

			LED_off(PEDSTRAIN_LED_RED_PORT, PEDSTRAIN_LED_RED_PIN);
			LED_on(CAR_LED_RED_PORT, CAR_LED_RED_PIN);
			LED_on(PEDSTRAIN_LED_GREEN_PORT, PEDSTRAIN_LED_GREEN_PIN);
			
			for(index_i = 0; index_i < 20; index_i++)
			{
				TIMER_start();
				TIMER_stop();
			}
			LED_on(CAR_LED_RED_PORT, CAR_LED_RED_PIN);

			for(index_i = 0; index_i < 20; index_i++)
			{
				LED_toggle(CAR_LED_YELLOW_PORT, CAR_LED_YELLOW_PIN);
				LED_toggle(PEDSTRAIN_LED_YELLOW_PORT, PEDSTRAIN_LED_YELLOW_PIN);
				TIMER_start();
				TIMER_stop();
			}
			LED_off(CAR_LED_YELLOW_PORT, CAR_LED_YELLOW_PIN);
			LED_off(PEDSTRAIN_LED_YELLOW_PORT, PEDSTRAIN_LED_YELLOW_PIN);
			LED_off(PEDSTRAIN_LED_GREEN_PORT, PEDSTRAIN_LED_GREEN_PIN);

			button_state = BUTTON_NOT_PRESSED;   // Returns button state to initial (not pressed)

			APP_start();      // Returns to application start
		break;
		
		case 3: // Button was pressed when car_led_red was on
			LED_on(PEDSTRAIN_LED_GREEN_PORT, PEDSTRAIN_LED_GREEN_PIN);
			for(index_i = 0; index_i < 20; index_i++)
			{
				TIMER_start();
				TIMER_stop();
			}
			LED_off(CAR_LED_RED_PORT, CAR_LED_RED_PIN);
			LED_off(PEDSTRAIN_LED_RED_PORT, PEDSTRAIN_LED_RED_PIN);

			for(index_i = 0; index_i < 20; index_i++)
			{
				LED_toggle(CAR_LED_YELLOW_PORT, CAR_LED_YELLOW_PIN);
				LED_toggle(PEDSTRAIN_LED_YELLOW_PORT, PEDSTRAIN_LED_YELLOW_PIN);
				TIMER_start();
				TIMER_stop();
			}
			LED_off(CAR_LED_YELLOW_PORT, CAR_LED_YELLOW_PIN);
			LED_off(PEDSTRAIN_LED_YELLOW_PORT, PEDSTRAIN_LED_YELLOW_PIN);
			LED_off(PEDSTRAIN_LED_GREEN_PORT, PEDSTRAIN_LED_GREEN_PIN);

			button_state = BUTTON_NOT_PRESSED;  // Returns button state to initial (not pressed)

			APP_start();      // Returns to application start
		break;

	}		
}



void timer_test(void)
{
	LED_on(CAR_LED_GREEN_PORT, CAR_LED_GREEN_PIN);
	
	for(index_i = 0; index_i < 20; index_i++)
	{
		// If button is not pressed
		TIMER_start();
		TIMER_stop();
	}
	LED_off(CAR_LED_GREEN_PORT, CAR_LED_GREEN_PIN);
}

