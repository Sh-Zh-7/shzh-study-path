#include "pwm.h"
#include "delay.h"

int main(void) {
	// ���ü�����
	u16 TIM3_PWM_val = 0, TIM3_dir = 1;

	// ��ʼ�� 
	TIM3_PWM_Init(899, 0);		//����PWMƵ��
	
	// ����ռ�ձ�
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
		
		// ����ռ�ձ�
		TIM_SetCompare1(TIM3, TIM3_PWM_val);	// TIM3_PWM_val��ARR����ռ�ı�������ռ�ձ�
		// �õ�ѹ������ʵ����ƽ����ѹ
}
