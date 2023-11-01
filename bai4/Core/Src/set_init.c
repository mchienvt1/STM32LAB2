/*
 * set_init.c
 *
 *  Created on: Oct 10, 2023
 *      Author: lmchi
 */


#include "set_init.h"

void set_init(){
	HAL_GPIO_WritePin(GPIOA, LED_RED_Pin | EN0_Pin | EN1_Pin | EN2_Pin | EN3_Pin | DOT_Pin , 1);
	HAL_GPIO_WritePin(GPIOB, a_Pin | b_Pin | c_Pin | d_Pin | e_Pin | f_Pin | g_Pin, 1);
}
