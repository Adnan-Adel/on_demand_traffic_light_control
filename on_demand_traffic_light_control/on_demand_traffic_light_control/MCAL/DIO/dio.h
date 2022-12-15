/*
 * dio.h
 *
 * Created: 12/7/2022 9:27:54 PM
 *  Author: Adnan
 */ 


#ifndef DIO_H_
#define DIO_H_
#include "../../Utilities/Registers.h"

/*---------------------- Enums ----------------------*/
typedef enum
{
	PORT_A,
	PORT_B,
	PORT_C,
	PORT_D
}DIO_PORT_ID;

typedef enum
{
	pin0,
	pin1,
	pin2,
	pin3,
	pin4,
	pin5,
	pin6,
	pin7	
}DIO_PIN_ID;

typedef enum
{
	INPUT,
	OUTPUT	
}DIO_Direction;

typedef enum
{
	LOW,
	HIGH	
}DIO_Value;

/*---------------------- DIO Functions Prototypes ----------------------*/
void DIO_init(DIO_PORT_ID portNumber, DIO_PIN_ID pinNumber, DIO_Direction direction);                       // Initialize DIO direction

void DIO_write(DIO_PORT_ID portNumber, DIO_PIN_ID pinNumber, DIO_Value value);                              // Write data to DIO

void DIO_toggle(DIO_PORT_ID portNumber, DIO_PIN_ID pinNumber);                                              // Toggle DIO

void DIO_read(DIO_PORT_ID portNumber, DIO_PIN_ID pinNumber, DIO_Value *value);                              // Read DIO value

#endif /* DIO_H_ */