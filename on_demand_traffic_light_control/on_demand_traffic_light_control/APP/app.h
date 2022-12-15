/*
 * app.h
 *
 * Created: 12/7/2022 9:30:03 PM
 *  Author: Adnan
 */ 


#ifndef APP_H_
#define APP_H_

#include "../HAL/LED/led.h"
#include "../HAL/BUTTON/button.h"


void APP_init(void);

void APP_start(void);

// Timer test function prototype
void timer_test(void);



#endif /* APP_H_ */