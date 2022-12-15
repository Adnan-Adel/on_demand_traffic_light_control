/*
 * dio.c
 *
 * Created: 12/7/2022 9:28:03 PM
 *  Author: Adnan
 */ 
#include "dio.h"

void DIO_init(DIO_PORT_ID portNumber, DIO_PIN_ID pinNumber, DIO_Direction direction)
{
	switch(portNumber)
	{
		case PORT_A:
			if(INPUT == direction)
			{
				CLEAR_BIT(DDRA, pinNumber);
			}
			else if(OUTPUT == direction)
			{
				SET_BIT(DDRA, pinNumber);
			}
		break;
		
		case PORT_B:
			if(INPUT == direction)
			{
				CLEAR_BIT(DDRB, pinNumber);
			}
			else if(OUTPUT == direction)
			{
				SET_BIT(DDRB, pinNumber);
			}
		break;
		
		case PORT_C:
			if(INPUT == direction)
			{
				CLEAR_BIT(DDRC, pinNumber);
			}
			else if(OUTPUT == direction)
			{
				SET_BIT(DDRC, pinNumber);
			}
		break;
		
		case PORT_D:
			if(INPUT == direction)
			{
				CLEAR_BIT(DDRD, pinNumber);
			}
			else if(OUTPUT == direction)
			{
				SET_BIT(DDRD, pinNumber);
			}
		break;
	}
}                     

void DIO_write(DIO_PORT_ID portNumber, DIO_PIN_ID pinNumber, DIO_Value value)
{
	switch(portNumber)
	{
		case PORT_A:
		if(LOW == value)
		{
			CLEAR_BIT(PORTA, pinNumber);
		}
		else if(HIGH == value)
		{
			SET_BIT(PORTA, pinNumber);
		}
		break;
		
		case PORT_B:
			if(LOW == value)
			{
				CLEAR_BIT(PORTB, pinNumber);
			}
			else if(HIGH == value)
			{
				SET_BIT(PORTB, pinNumber);
			}
		break;
		
		case PORT_C:
			if(LOW == value)
			{
				CLEAR_BIT(PORTC, pinNumber);
			}
			else if(HIGH == value)
			{
				SET_BIT(PORTC, pinNumber);
			}
		break;
		
		case PORT_D:
			if(LOW == value)
			{
				CLEAR_BIT(PORTD, pinNumber);
			}
			else if(HIGH == value)
			{
				SET_BIT(PORTD, pinNumber);
			}
		break;
	}
}                           

void DIO_toggle(DIO_PORT_ID portNumber, DIO_PIN_ID pinNumber)
{
	switch(portNumber)
	{
		case PORT_A:
			TOGGLE_BIT(PORTA, pinNumber);
		break;
		
		case PORT_B:
			TOGGLE_BIT(PORTB, pinNumber);
		break;
		
		case PORT_C:
			TOGGLE_BIT(PORTC, pinNumber);
		break;
		
		case PORT_D:
			TOGGLE_BIT(PORTD, pinNumber);
		break;
	}	
}                                            

void DIO_read(DIO_PORT_ID portNumber, DIO_PIN_ID pinNumber, DIO_Value *value)
{
	switch(portNumber)
	{
		case PORT_A:
			*value= READ_BIT(PINA, pinNumber);
		break;
		
		case PORT_B:
			*value= READ_BIT(PINB, pinNumber);
		break;
		
		case PORT_C:
			*value= READ_BIT(PINC, pinNumber);
		break;
		
		case PORT_D:
			*value= READ_BIT(PIND, pinNumber);
		break;
	}
}