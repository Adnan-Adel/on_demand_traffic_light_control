/*
 * led.c
 *
 * Created: 12/7/2022 9:29:31 PM
 *  Author: LAP TECH
 */ 

#include "led.h"


void LED_init(DIO_PORT_ID portNumber, DIO_PIN_ID pinNumber)
{
	DIO_init(portNumber, pinNumber, OUTPUT);
}

void LED_on(DIO_PORT_ID portNumber, DIO_PIN_ID pinNumber)
{
	DIO_write(portNumber, pinNumber, HIGH);
}

void LED_off(DIO_PORT_ID portNumber, DIO_PIN_ID pinNumber)
{
	DIO_write(portNumber, pinNumber, LOW);
}

void LED_toggle(DIO_PORT_ID portNumber, DIO_PIN_ID pinNumber)
{
	DIO_toggle(portNumber, pinNumber);
}