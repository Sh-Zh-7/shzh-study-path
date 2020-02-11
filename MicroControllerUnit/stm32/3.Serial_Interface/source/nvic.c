#include "nvic.h"

void NVIC_Config(void) {
// 串口1的中断配置 
	NVIC_InitTypeDef NVIC_InitStructure;
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);			// 中断分组1：1位抢占优先级，3位响应优先级
	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;		// 中断通道
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;	//抢占优先级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;		//子优先级
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//使能中断
	
	NVIC_Init(&NVIC_InitStructure);
	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE); //开启中断
}

//----------------------------------------------------各个外设的中断服务函数------------------------------------------------//
// 把他放在全局变量里
// RXNE就不会自动变为RESET了
u8 USART_RX_BUF[32];
u8 USART_RX_STA = 0;	
u8 temp;

// 串口接收格式："#"+"TEXT"+"\r"
// 本例中用到的USART_RX_BUF用到的位设置（包括+1和掩码都十分巧妙）
// 至于为什么使用一个8位无符号来存储，主要是因为节省内存
void USART1_IRQHandler(void) {	
// USART1的中断服务函数（可能包含各种事件的中断）
	// 我们每次只能收到一个字节（即单个字符）
	// STA用来监视全局的接收状态(第8位为1说明接收完成，第7位为1说明开始接收，后面几位是当前报文索引)
	// BUF用来存储整个过程中我们接收到的所有字符
	
	 if(USART_GetITStatus(USART1,USART_IT_RXNE) != RESET) {
	 	 USART_ClearFlag(USART1,USART_IT_RXNE);			
	   USART_ClearITPendingBit(USART1,USART_IT_RXNE);	
			
		temp = USART_ReceiveData(USART1);			// temp是每次循环从串口接收到的单个字节
		
		if((USART_RX_STA & 0x40) != 0) {			// 如果还在接收状态
      if((USART_RX_STA & 0x80) == 0) { 		// 并且接收未完成
        if(temp == 0x0d) {									// 先判断当前接收完成了没
          USART_RX_STA |= 0x80;						// 完成了，将STA第8位设置为1，表示全局接收都完成了
				} else {
          USART_RX_BUF[USART_RX_STA & 0x3f] = temp; // 存储当前报文  
          ++USART_RX_STA;														// 获得下一次报文的索引
					if((USART_RX_STA & 0x3f) > 31) {						// 超出接收范围
						USART_RX_STA = 0;	
					}
        }
      }
    } else if(temp == '#') {	// 开始接收！
			USART_RX_STA |= 0x40;	// 设置全局状态
			memset(USART_RX_BUF, 0, sizeof(USART_RX_BUF));
		}
		
		if((USART_RX_STA & 0x80) != 0) {	// 接收完成，对报文的内容进行判断并处理			
			// 这里我们选择的响应为LED跑马灯
			LEFT_LED_ON;
			RIGHT_LED_OFF;
			delay_ms(1000);
			
			RIGHT_LED_ON;
			LEFT_LED_OFF;
			delay_ms(1000);
		}
	}
}
