/*
 * button.c
 *
 * Created: 12/7/2022 9:29:47 PM
 *  Author: Adnan
 */ 

#include "button.h"

void BUTTON_init(DIO_PORT_ID portNumber, DIO_PIN_ID pinNumber)
{
	DIO_init(portNumber, pinNumber, INPUT);
}

void BUTTON_read(DIO_PORT_ID portNumber, DIO_PIN_ID pinNumber, DIO_Value *value)
{
	DIO_read(portNumber, pinNumber, value);
}