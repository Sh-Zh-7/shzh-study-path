#include "pwm.h"
#include "delay.h"

int main(void) {
	// 设置计数器
	u16 TIM3_PWM_val = 0, TIM3_dir = 1;

	// 初始化 
	TIM3_PWM_Init(899, 0);		//设置PWM频率
	
	// 利用占空比
	while (1) {
		delay_ms(10);
		
		if (TIM3_dir) {
			++TIM3_PWM_val;
		} else {
			--TIM3_PWM_val;
		}
		if (TIM3_PWM_val > 300) {
			TIM3_dir = 0;
		}
		if (TIM3_PWM_val == 0) {
			TIM3_dir = 1;
		}
		
		// 设置占空比
		TIM_SetCompare1(TIM3, TIM3_PWM_val);	// TIM3_PWM_val在ARR中所占的比例就是占空比
		// 用电压表测的其实就是平均电压
}
