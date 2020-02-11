#ifndef LED_H__		// ��������
#define LED_H__

// stm32f10x.h�а����˸�����Χ�Ĵ����Ķ���
#include "stm32f10x.h"

// ���øߵ͵�ƽ����LED�Ƶ�״̬
#define ON 0
#define OFF 1

// ����(��ر�)PE2(3)
#define LEFT_LED_ON GPIO_ResetBits(GPIOE, GPIO_Pin_2)
#define RIGHT_LED_ON GPIO_ResetBits(GPIOE, GPIO_Pin_3)
#define LEFT_LED_OFF GPIO_SetBits(GPIOE, GPIO_Pin_2)
#define RIGHT_LED_OFF GPIO_SetBits(GPIOE, GPIO_Pin_3)

void LEDInit(void);

#endif // LED_H__

