#include "my_pwm.h"

void TIM3_PWM_Init(u16 arr, u16 psc) {
// TIM3�Ĳ��ֳ�ʼ��
	// ʹ������ʱ��
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);		// ʹ�ܶ�ʱ��ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_AFIO, ENABLE);		// ʹ��GPIO��AFIO���ù���ʱ��
	
	// ��������
	GPIO_Config();
	TIM3_Initialize(arr, psc);
	TIM3_Channel2_PWM_Initialize();	
	
	// ʹ��
	TIM_OC1PreloadConfig(TIM3, TIM_OCPreload_Enable);		// ʹ��Ԥװ�ؼĴ���
	TIM_Cmd(TIM3, ENABLE);		// ʹ��TIM3
}

static void GPIO_Config(void) {
// GPIO��ʼ��
	// �˿���ӳ�䣨TIM3_CH2->PA6��
	// ���ﲻ��Ҫ��ӳ��
	// GPIO_PinRemapConfig(GPIO_PartialRemap_TIM3, ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure;
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6; 			// PA6
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	// ��������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
}

static void TIM3_Initialize(u16 arr, u16 psc) {
// ��ʼ��TIM3
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	
	TIM_TimeBaseStructure.TIM_Period = arr; 	// �趨�Զ���װ������
	TIM_TimeBaseStructure.TIM_Prescaler = psc;		// ����Ԥ��Ƶֵ
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; 	// ����ʱ�ӷָ�
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; 	// ���ϼ���ģʽ
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);		// ����InitStructure��ʼ��TIM3
}

static void TIM3_Channel2_PWM_Initialize(void) {
// ��ʼ��TIM3 Channel2 PWMģʽ
	TIM_OCInitTypeDef TIM_OCInitStructure;		// ����PWMר��
	
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; 	// ѡ��PWMģʽ2
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; 	// ����Ƚ�ʹ��
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;		// ������Ը�
	TIM_OC1Init(TIM3, &TIM_OCInitStructure);		// ��ʼ������TIM3 OC2
}


