#include "led.h" 
#include "nvic.h"
#include "delay.h"
#include "usart1.h"
// led和delay的定义见LED的repo 

//利用串口实现对LED灯的开关操作
int main(void) {
	LEDInit();	// 小灯初始化
	// 先设置串口，在配置NVIC 
	USART1_Init(115200);	
	NVIC_Config();
	while (1) {}
}
