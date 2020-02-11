#include "my_pwm.h"

void TIM3_PWM_Init(u16 arr, u16 psc) {
// TIM3的部分初始化
	// 使能三种时钟
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);		// 使能定时器时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_AFIO, ENABLE);		// 使能GPIO和AFIO复用功能时钟
	
	// 各种配置
	GPIO_Config();
	TIM3_Initialize(arr, psc);
	TIM3_Channel2_PWM_Initialize();	
	
	// 使能
	TIM_OC1PreloadConfig(TIM3, TIM_OCPreload_Enable);		// 使能预装载寄存器
	TIM_Cmd(TIM3, ENABLE);		// 使能TIM3
}

static void GPIO_Config(void) {
// GPIO初始化
	// 端口重映射（TIM3_CH2->PA6）
	// 这里不需要重映射
	// GPIO_PinRemapConfig(GPIO_PartialRemap_TIM3, ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure;
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6; 			// PA6
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	// 复用推挽
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
}

static void TIM3_Initialize(u16 arr, u16 psc) {
// 初始化TIM3
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	
	TIM_TimeBaseStructure.TIM_Period = arr; 	// 设定自动重装载周期
	TIM_TimeBaseStructure.TIM_Prescaler = psc;		// 设置预分频值
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; 	// 设置时钟分割
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; 	// 向上计数模式
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);		// 利用InitStructure初始化TIM3
}

static void TIM3_Channel2_PWM_Initialize(void) {
// 初始化TIM3 Channel2 PWM模式
	TIM_OCInitTypeDef TIM_OCInitStructure;		// 设置PWM专用
	
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; 	// 选择PWM模式2
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; 	// 输出比较使能
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;		// 输出极性高
	TIM_OC1Init(TIM3, &TIM_OCInitStructure);		// 初始化外设TIM3 OC2
}


