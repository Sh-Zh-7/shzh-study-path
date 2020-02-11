#include "no_semi_hosting.h"
#include "usart1.h"
#include "delay.h"
#include "adc.h"

int main() {
	u16 tmp;
	float voltage;
	
	USART1_Init(115200);
	Adc_Init();
	NVIC_Config();
	
	while (1) {
		tmp = GetADCAverage(ADC_Channel_17, 10);		// ��ʾADC��ֵ
		printf("ADC = %d\r\n", tmp);
		
		// ADCֵ���޷�������
		// ��ѹֵ��ADC�ǳ����ȹ�ϵ
		// ����ѹֵ��Ȼ������һ��ʵ��
		voltage = (float)tmp * (3.3 / 4096);
		printf("Voltage = %f\r\n", voltage);
		
		// ÿ1s����һ��
		delay_ms(1000);
	}
}
