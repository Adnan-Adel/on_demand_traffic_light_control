/*
 * led.h
 *
 * Created: 12/7/2022 9:29:21 PM
 *  Author: Adnan
 */ 


#ifndef LED_H_
#define LED_H_
#include "../../MCAL/DIO/dio.h"
#include "../../MCAL/TIMER/timer.h"

// Pedstrains leds
#define PEDSTRAIN_LED_RED_PORT PORT_B
#define PEDSTRAIN_LED_RED_PIN  pin0

#define PEDSTRAIN_LED_YELLOW_PORT PORT_B
#define PEDSTRAIN_LED_YELLOW_PIN  pin1

#define PEDSTRAIN_LED_GREEN_PORT PORT_B
#define PEDSTRAIN_LED_GREEN_PIN  pin2

// Car leds
#define CAR_LED_RED_PORT PORT_A
#define CAR_LED_RED_PIN  pin0

#define CAR_LED_YELLOW_PORT PORT_A
#define CAR_LED_YELLOW_PIN  pin1

#define CAR_LED_GREEN_PORT PORT_A
#define CAR_LED_GREEN_PIN  pin2

void LED_init(DIO_PORT_ID portNumber, DIO_PIN_ID pinNumber);

void LED_on(DIO_PORT_ID portNumber, DIO_PIN_ID pinNumber);  

void LED_off(DIO_PORT_ID portNumber, DIO_PIN_ID pinNumber);

void LED_toggle(DIO_PORT_ID portNumber, DIO_PIN_ID pinNumber);




#endif /* LED_H_ */