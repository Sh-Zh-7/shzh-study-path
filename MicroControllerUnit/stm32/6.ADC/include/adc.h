#ifndef ADC_H__
#define ADC_H__

#include "stm32f10x_adc.h"

// ���ﲻ����ADC����Ȼ���׼���е�ͬ��������ͻ
void Adc_Init(void);
static void GPIO_Config(void);
static void ADC1_Config(void);
static u16 GetADC(u8 ch);
u16 GetADCAverage(u8, u8);

#endif // ADC_H__

