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
const int MAX_LED_MATRIX = 8
int index_matrix = 0;
unit8_t matrix[8] = {0x00, 0xfc, 0xfe, 0x33, 0x33, 0xfe, 0xfc, 0x00};

void writeRowMatrix(uint8_t config){
    HAL_GPIO_WritePin(GPIOB, ROW0_Pin, !(config&1));
    config = config >> 1;
    HAL_GPIO_WritePin(GPIOB, ROW1_Pin, !(config&1));
    config = config >> 1;
    HAL_GPIO_WritePin(GPIOB, ROW2_Pin, !(config&1));
    config = config >> 1;
    HAL_GPIO_WritePin(GPIOB, ROW3_Pin, !(config&1));
    config = config >> 1;
    HAL_GPIO_WritePin(GPIOB, ROW4_Pin, !(config&1));
    config = config >> 1;
    HAL_GPIO_WritePin(GPIOB, ROW5_Pin, !(config&1));
    config = config >> 1;
    HAL_GPIO_WritePin(GPIOB, ROW6_Pin, !(config&1));
    config = config >> 1;
    HAL_GPIO_WritePin(GPIOB, ROW7_Pin, !(config&1));
}

void updateMatrixLED(int index){
	switch(index){
	    case 0:
	    	writeRowMatrix(matrix_buffer[0]);
	    	break;
	    case 1:
	    	writeRowMatrix(matrix_buffer[1]);
	    	break;
	    case 2:
	    	writeRowMatrix(matrix_buffer[2]);
	    	break;
	    case 3:
	    	writeRowMatrix(matrix_buffer[3]);
	    	break;
	    case 4:
	    	writeRowMatrix(matrix_buffer[4]);
	    	break;
	    case 5:
	    	writeRowMatrix(matrix_buffer[5]);
	    	break;
	    case 6:
	    	writeRowMatrix(matrix_buffer[6]);
	    	break;
	    case 7:
	    	writeRowMatrix(matrix_buffer[7]);
	    	break;
	    default:
	      break;
	}
}



void clearENM(){
	  HAL_GPIO_WritePin(GPIOA, ENM0_Pin | ENM1_Pin | ENM2_Pin | ENM3_Pin | ENM4_Pin | ENM5_Pin | ENM6_Pin | ENM7_Pin, 1);
}

void openENM(int index){
	switch(index)
	{
	case 0:
	  HAL_GPIO_WritePin(GPIOA, ENM0_Pin, 0);
	  break;
	case 1:
	  HAL_GPIO_WritePin(GPIOA, ENM1_Pin, 0);
	  break;
	case 2:
	  HAL_GPIO_WritePin(GPIOA, ENM2_Pin, 0);
	  break;
	case 3:
	  HAL_GPIO_WritePin(GPIOA, ENM3_Pin, 0);
	  break;
	case 4:
	  HAL_GPIO_WritePin(GPIOA, ENM4_Pin, 0);
	  break;
	case 5:
	  HAL_GPIO_WritePin(GPIOA, ENM5_Pin, 0);
	  break;
	case 6:
	  HAL_GPIO_WritePin(GPIOA, ENM6_Pin, 0);
	  break;
	case 7:
	  HAL_GPIO_WritePin(GPIOA, ENM7_Pin, 0);
	  break;
	default:
	  break;
	}
}









void update7SEG(int index){
	switch(index){
		case 0:
			clearEN_7SEG();
			clear7SEG();
			HAL_GPIO_TogglePin(GPIOA,EN0_Pin);
			display7SEG(led_buffer[0]);
			break;
		case 1:
			clearEN_7SEG();
			clear7SEG();
			HAL_GPIO_TogglePin(GPIOA,EN1_Pin);
			display7SEG(led_buffer[1]);
			break;
		case 2:
			clearEN_7SEG();
			clear7SEG();
			HAL_GPIO_TogglePin(GPIOA,EN2_Pin);
			display7SEG(led_buffer[2]);
			break;
		case 3:
			clearEN_7SEG();
			clear7SEG();
			HAL_GPIO_TogglePin(GPIOA,EN3_Pin);
			display7SEG(led_buffer[3]);
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
