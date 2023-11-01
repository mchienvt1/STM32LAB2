/*
 * software_timer.h
 *
 *  Created on: Oct 12, 2023
 *      Author: lmchi
 */

#ifndef SRC_SOFTWARE_TIMER_H_
#define SRC_SOFTWARE_TIMER_H_

#include "main.h"


//int timer_7SEG;
int flag_7SEG;
//int timer_led;
int flag_led;
int TIMER_CYCLE;


void setTimer_7SEG(int duration);
void setTimer_Led(int duration);
void timer_run();

#endif /* SRC_SOFTWARE_TIMER_H_ */
