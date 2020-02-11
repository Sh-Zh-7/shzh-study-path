#ifndef MY_USART_H__
#define MY_USART_H__

#include "stm32f10x_usart.h"

void USART1_Init(unsigned int);
void GPIOA_Config(void);
void USART1_Config(unsigned int);
// 中断处理函数不用声明

#endif // MY_USART_H__

 
