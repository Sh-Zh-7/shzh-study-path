#ifndef PWM_H__
#define PWM_H__

#include "stm32f10x_tim.h"

// 初始化计时器的PWM模式
void TIM3_PWM_Init(u16 arr, u16 psc);

// 静态函数初始化
static void GPIO_Config(void);
static void TIM3_Initialize(u16, u16);
static void TIM3_Channel2_PWM_Initialize(void);

#endif // PWM_H__ ends

