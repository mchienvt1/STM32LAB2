/*
 * software_timer.c
 *
 *  Created on: Oct 12, 2023
 *      Author: lmchi
 */
#include "software_timer.h"
#include "main.h"

int timer_7SEG = 0;
int flag_7SEG = 0;
int timer_led = 0;
int flag_led = 0;
int TIMER_CYCLE = 10;

void setTimer_7SEG(int duration){
	timer_7SEG = duration / TIMER_CYCLE;
	flag_7SEG = 0;
}

void setTimer_Led(int duration){
	timer_led = duration / TIMER_CYCLE;
	flag_led = 0;
}

void timer_run(){
	if(timer_7SEG > 0){
		timer_7SEG--;
		if(timer_7SEG == 0) flag_7SEG = 1;
	}
	if(timer_led > 0){
		timer_led--;
		if(timer_led == 0) flag_led = 1;
	}
}
