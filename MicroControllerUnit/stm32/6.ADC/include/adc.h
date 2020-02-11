#ifndef ADC_H__
#define ADC_H__

#include "stm32f10x_adc.h"

// 这里不能用ADC，不然与标准库中的同名函数冲突
void Adc_Init(void);
static void GPIO_Config(void);
static void ADC1_Config(void);
static u16 GetADC(u8 ch);
u16 GetADCAverage(u8, u8);

#endif // ADC_H__

