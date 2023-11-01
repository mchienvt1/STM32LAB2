/*
 * software_timer.h
 *
 *  Created on: Oct 12, 2023
 *      Author: lmchi
 */

#ifndef SRC_SOFTWARE_TIMER_H_
#define SRC_SOFTWARE_TIMER_H_

#include "main.h"


int timer0_counter;
int timer0_flag;
int TIMER_CYCLE;

void setTimer0(int duration);
void timer_run();

#endif /* SRC_SOFTWARE_TIMER_H_ */
