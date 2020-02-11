#ifndef MY_UART1_H__
#define MY_UART1_H__

#include "stm32f10x_usart.h"

void USART1_Init(unsigned int);
void GPIOA_Config(void);
void USART1_Config(unsigned int);
void NVIC_Config(void);
void USART1_IRQHandler(void);

#endif // MY_UART1_H__
 
