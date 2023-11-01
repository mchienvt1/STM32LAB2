/*
 * led.h
 *
 *  Created on: Oct 10, 2023
 *      Author: lmchi
 */

#ifndef INC_LED_H_
#define INC_LED_H_

#include "main.h"

int EN_state;

void clear7SEG();
void display7SEG(int num);
void changeLed();
void changeNum();


#endif /* INC_LED_H_ */
