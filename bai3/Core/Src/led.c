/*
 * led.c
 *
 *  Created on: Oct 10, 2023
 *      Author: lmchi
 */

#include "led.h"

int EN_state = 0;
const int MAX_LED = 4;
int index_led = 0;
int led_buffer[4] = {1,2,3,4};

void update7SEG(int index){
	switch(index){
		case 0:
			clearEN_7SEG();
			clear7SEG();
			HAL_GPIO_TogglePin(GPIOA,EN0_Pin);
			display7SEG(1);
			break;
		case 1:
			clearEN_7SEG();
			clear7SEG();
			HAL_GPIO_TogglePin(GPIOA,EN1_Pin);
			display7SEG(2);
			break;
		case 2:
			clearEN_7SEG();
			clear7SEG();
			HAL_GPIO_TogglePin(GPIOA,EN2_Pin);
			display7SEG(3);
			break;
		case 3:
			clearEN_7SEG();
			clear7SEG();
			HAL_GPIO_TogglePin(GPIOA,EN3_Pin);
			display7SEG(0);
			break;
		default:
			break;
	}
}

// reset led 7 doan
void clearEN_7SEG(){
	HAL_GPIO_WritePin(GPIOA, EN0_Pin | EN1_Pin | EN2_Pin | EN3_Pin, 1);
}

void clear7SEG(){
	HAL_GPIO_WritePin(GPIOB,a_Pin | b_Pin | c_Pin | d_Pin | e_Pin | f_Pin | g_Pin, 1);
}

void display7SEG(int num){
	switch(num){
		case 0:
			HAL_GPIO_WritePin(GPIOB, a_Pin | b_Pin | c_Pin | d_Pin | e_Pin | f_Pin , 0);
			break;
		case 1:
			HAL_GPIO_WritePin(GPIOB, b_Pin | c_Pin , 0);
			break;
		case 2:
			HAL_GPIO_WritePin(GPIOB, a_Pin | b_Pin | d_Pin | e_Pin | g_Pin , 0);
			break;
		case 3:
			HAL_GPIO_WritePin(GPIOB, a_Pin | b_Pin | c_Pin | d_Pin | g_Pin , 0);
			break;
		case 4:
			HAL_GPIO_WritePin(GPIOB, b_Pin | c_Pin | f_Pin | g_Pin , 0);
			break;
		case 5:
			HAL_GPIO_WritePin(GPIOB, a_Pin | c_Pin | d_Pin | f_Pin | g_Pin , 0);
			break;
		case 6:
			HAL_GPIO_WritePin(GPIOB, a_Pin | c_Pin | d_Pin | e_Pin | f_Pin | g_Pin , 0);
			break;
		case 7:
			HAL_GPIO_WritePin(GPIOB, a_Pin | b_Pin | c_Pin , 0);
			break;
		case 8:
			HAL_GPIO_WritePin(GPIOB, a_Pin | b_Pin | c_Pin | d_Pin | e_Pin | f_Pin | g_Pin, 0);
			break;
		case 9:
			HAL_GPIO_WritePin(GPIOB, a_Pin | b_Pin | c_Pin | d_Pin | f_Pin | g_Pin , 0);
			break;
		default:
			break;
	}
}

// bật tắt đèn Led
void changeLed(){
	HAL_GPIO_TogglePin(GPIOA, LED_RED_Pin | DOT_Pin);
}

// thay đổi led 7 đoạn nháy số 1 và 2
void changeNum(){
	switch(EN_state){
		case 0:
			HAL_GPIO_TogglePin(GPIOA,EN0_Pin);
			clear7SEG();
			display7SEG(1);
			EN_state = 1;
			break;
		case 1:
			HAL_GPIO_TogglePin(GPIOA,EN0_Pin | EN1_Pin);
			clear7SEG();
			display7SEG(2);
			EN_state = 2;
			break;
		case 2:
			HAL_GPIO_TogglePin(GPIOA,EN1_Pin | EN2_Pin);
			clear7SEG();
			display7SEG(3);
			EN_state = 3;
			break;
		case 3:
			HAL_GPIO_TogglePin(GPIOA,EN2_Pin | EN3_Pin);
			clear7SEG();
			display7SEG(0);
			EN_state = 4;
			break;
		case 4:
			HAL_GPIO_TogglePin(GPIOA,EN3_Pin | EN0_Pin);
			clear7SEG();
			display7SEG(1);
			EN_state = 1;
			break;
	}
}
