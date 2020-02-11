#include "delay.h"
#include "led.h"

int main(void) {
// 跑马灯 
	LEDInit();
	while (1) {
		// 每1秒只有一盏灯亮
		LEFT_LED_ON;
		RIGHT_LED_OFF;
		delay_ms(1000);
		
		LEFT_LED_OFF;
		RIGHT_LED_ON;
		delay_ms(1000);
	}
}
