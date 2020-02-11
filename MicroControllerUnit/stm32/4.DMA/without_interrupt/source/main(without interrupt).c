#include <string.h>
#include "led.h"
#include "delay.h"
#include "dma(without interrupt).h"
#include "usart1(without interrupt).h"

#define SIZE 8
char receive_buf[SIZE];
int remain;
int main(void) {

	memset(receive_buf, 0, sizeof(char) * 8);		// 这里不能传指针，而应该传char所占内存的8倍
	
	LEDInit();
	USART1_Init(115200);
	// P.S. ->的优先级高于&
	// 三句话来初始化
	MYDMA_Config(DMA1_Channel5, (u32)&USART1->DR, (u32)receive_buf, 2);
	USART_DMACmd(USART1, USART_DMAReq_Rx, ENABLE);		// 使能串口的DMA接收
	MYDMA_Enable(DMA1_Channel5);
	
	while (1) {
		// 这个DMA也跟中断差不多，是自动调用
		// 最好是等他接收到数据的时候再执行其它的流程

		while (1) {
			if (DMA_GetFlagStatus(DMA1_FLAG_TC5) != RESET) {
				DMA_ClearFlag(DMA1_FLAG_TC5);			// 清除通道5的传输完成标志
				break;
			}
		}

		// 这里的receive_buf到最后还会一直递增
		// 这样我们只能测试一组数据，毫无办法
		if (receive_buf[0] == '#' && receive_buf[1] == 'k') {
			// 让他闪一下
			LEFT_LED_ON; RIGHT_LED_ON;
			delay_ms(2000);
			LEFT_LED_OFF; RIGHT_LED_OFF;
			delay_ms(2000);	// 这个必须加一个delay_ms，执行速度很快，所以几乎看不见
		}
		memset(receive_buf, 0, sizeof(char) * 8);
	}
}


