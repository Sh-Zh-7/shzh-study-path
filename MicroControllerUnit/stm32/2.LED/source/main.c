#include "delay.h"
#include "led.h"

int main(void) {
// ����� 
	LEDInit();
	while (1) {
		// ÿ1��ֻ��һյ����
		LEFT_LED_ON;
		RIGHT_LED_OFF;
		delay_ms(1000);
		
		LEFT_LED_OFF;
		RIGHT_LED_ON;
		delay_ms(1000);
	}
}
