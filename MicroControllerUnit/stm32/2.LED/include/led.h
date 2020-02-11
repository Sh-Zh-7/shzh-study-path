#ifndef LED_H__		// 条件编译
#define LED_H__

// stm32f10x.h中包含了各种外围寄存器的定义
#include "stm32f10x.h"

// 利用高低电平设置LED灯的状态
#define ON 0
#define OFF 1

// 点亮(或关闭)PE2(3)
#define LEFT_LED_ON GPIO_ResetBits(GPIOE, GPIO_Pin_2)
#define RIGHT_LED_ON GPIO_ResetBits(GPIOE, GPIO_Pin_3)
#define LEFT_LED_OFF GPIO_SetBits(GPIOE, GPIO_Pin_2)
#define RIGHT_LED_OFF GPIO_SetBits(GPIOE, GPIO_Pin_3)

void LEDInit(void);

#endif // LED_H__

