/*
 * led.c
 *
 *  Created on: Oct 10, 2023
 *      Author: lmchi
 */

#include "led.h"

int EN_state = 0;

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
	HAL_GPIO_TogglePin(GPIOA, LED_RED_Pin);
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
			HAL_GPIO_TogglePin(GPIOA,EN0_Pin | EN1_Pin);
			clear7SEG();
			display7SEG(1);
			EN_state = 1;
			break;
	}
}
