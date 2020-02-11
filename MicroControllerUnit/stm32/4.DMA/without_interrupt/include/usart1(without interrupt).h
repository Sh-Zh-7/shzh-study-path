#ifndef USART1_H__
#define USART1_H__

#include "stm32f10x_usart.h"

void USART1_Init(unsigned int);
void GPIOA_Config(void);
void USART1_Config(unsigned int);
// P.S.中断函数不用声明

#endif // MY_USART1_H__


