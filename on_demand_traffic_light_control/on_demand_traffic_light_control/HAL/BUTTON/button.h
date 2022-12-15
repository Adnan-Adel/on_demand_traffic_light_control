/*
 * button.h
 *
 * Created: 12/7/2022 9:29:55 PM
 *  Author: Adnan
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include "../../MCAL/DIO/dio.h"
#include "../../MCAL/INTERRUPT/interrupt.h"

#define BUTTON_PORT PORT_D
#define BUTTON_PIN  pin3

#define BUTTON_NOT_PRESSED 0
#define BUTTON_PRESSED     1

void BUTTON_init(DIO_PORT_ID portNumber, DIO_PIN_ID pinNumber);

void BUTTON_read(DIO_PORT_ID portNumber, DIO_PIN_ID pinNumber, DIO_Value *value);




#endif /* BUTTON_H_ */