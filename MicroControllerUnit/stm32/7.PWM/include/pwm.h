#ifndef PWM_H__
#define PWM_H__

#include "stm32f10x_tim.h"

// ��ʼ����ʱ����PWMģʽ
void TIM3_PWM_Init(u16 arr, u16 psc);

// ��̬������ʼ��
static void GPIO_Config(void);
static void TIM3_Initialize(u16, u16);
static void TIM3_Channel2_PWM_Initialize(void);

#endif // PWM_H__ ends

