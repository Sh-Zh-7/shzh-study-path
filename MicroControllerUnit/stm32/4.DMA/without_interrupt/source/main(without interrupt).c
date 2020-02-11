#include <string.h>
#include "led.h"
#include "delay.h"
#include "dma(without interrupt).h"
#include "usart1(without interrupt).h"

#define SIZE 8
char receive_buf[SIZE];
int remain;
int main(void) {

	memset(receive_buf, 0, sizeof(char) * 8);		// ���ﲻ�ܴ�ָ�룬��Ӧ�ô�char��ռ�ڴ��8��
	
	LEDInit();
	USART1_Init(115200);
	// P.S. ->�����ȼ�����&
	// ���仰����ʼ��
	MYDMA_Config(DMA1_Channel5, (u32)&USART1->DR, (u32)receive_buf, 2);
	USART_DMACmd(USART1, USART_DMAReq_Rx, ENABLE);		// ʹ�ܴ��ڵ�DMA����
	MYDMA_Enable(DMA1_Channel5);
	
	while (1) {
		// ���DMAҲ���жϲ�࣬���Զ�����
		// ����ǵ������յ����ݵ�ʱ����ִ������������

		while (1) {
			if (DMA_GetFlagStatus(DMA1_FLAG_TC5) != RESET) {
				DMA_ClearFlag(DMA1_FLAG_TC5);			// ���ͨ��5�Ĵ�����ɱ�־
				break;
			}
		}

		// �����receive_buf����󻹻�һֱ����
		// ��������ֻ�ܲ���һ�����ݣ����ް취
		if (receive_buf[0] == '#' && receive_buf[1] == 'k') {
			// ������һ��
			LEFT_LED_ON; RIGHT_LED_ON;
			delay_ms(2000);
			LEFT_LED_OFF; RIGHT_LED_OFF;
			delay_ms(2000);	// ��������һ��delay_ms��ִ���ٶȺܿ죬���Լ���������
		}
		memset(receive_buf, 0, sizeof(char) * 8);
	}
}


