#include "led.h"

void LEDInit(void)
{
		GPIO_InitTypeDef GPIO_Config;
	
		// ʹ��IOʱ��
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE);

		// ��ʼ��IO����
		// PE.2 �� PE.3
		GPIO_Config.GPIO_Pin = GPIO_Pin_2|GPIO_Pin_3;		
		GPIO_Config.GPIO_Mode = GPIO_Mode_Out_PP;
		GPIO_Config.GPIO_Speed = GPIO_Speed_2MHz;
		GPIO_Init(GPIOE, &GPIO_Config);		
	
		// �ر���յ��
		LEFT_LED_OFF;
		RIGHT_LED_OFF;
}

