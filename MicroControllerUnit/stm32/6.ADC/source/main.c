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
		tmp = GetADCAverage(ADC_Channel_17, 10);		// 显示ADC的值
		printf("ADC = %d\r\n", tmp);
		
		// ADC值是无符号整数
		// 电压值和ADC是成正比关系
		// 而电压值显然可以是一般实数
		voltage = (float)tmp * (3.3 / 4096);
		printf("Voltage = %f\r\n", voltage);
		
		// 每1s采样一次
		delay_ms(1000);
	}
}
