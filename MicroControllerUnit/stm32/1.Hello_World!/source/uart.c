// Name: uart.c 
// Copyright: See README
// Author: BanScript7
// Date: 20/07/19 11:43
// Description: 
// 1.配置串口一, 包括串口的初始化，中断配置和中断服务函数 
// 2. 注意中断服务函数自己写
#include "my_uart1.h"

void USART1_Init(unsigned int BaudRate) {
// 初始化串口1 																	// 配置GPIO
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1 | RCC_APB2Periph_GPIOA, ENABLE);		// 使能USART1，GPIOA时钟
	GPIOA_Config();		
	USART1_Config(BaudRate);																// 设置波特率+开启中断
}

void GPIOA_Config(void) {
	GPIO_InitTypeDef GPIO_InitStructure;
	
	// TX - PA.9
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;		//PA.9
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;			//复用推挽输出
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	// RX - PA.10
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;		//PA.10
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;		//浮空输入
	GPIO_Init(GPIOA, &GPIO_InitStructure);	
}	

void USART1_Config(unsigned int BaudRate) {
// 串口1的波特率设置
	USART_InitTypeDef USART_InitStructure;
	
	USART_InitStructure.USART_BaudRate = BaudRate;		//波特率
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;		//字长8位
	USART_InitStructure.USART_StopBits = USART_StopBits_1;		//停止位1位
	USART_InitStructure.USART_Parity = USART_Parity_No;		//无奇偶校验
	USART_InitStructure.USART_HardwareFlowControl	= USART_HardwareFlowControl_None;		//无硬件数据流控制
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;			//收/发模式
	
	USART_Init(USART1, &USART_InitStructure);
	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);		//开启接收中断
	USART_ITConfig(USART1, USART_IT_IDLE, ENABLE);		//开启空闲中断
	USART_Cmd(USART1, ENABLE);
}

void NVIC_Config(void) {
// 串口1的中断配置 
	NVIC_InitTypeDef NVIC_InitStructure;
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);			//中断分组1：1位抢占优先级，3位响应优先级
	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;		//中断通道
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;	//抢占优先级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;		//子优先级
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//使能中断
	NVIC_Init(&NVIC_InitStructure);
}

void USART1_IRQHandler(void) {
// 串口1的中断服务函数，用来打印接收到的字节 
// TODO：修改为自己的中断处理函数
	static unsigned char buff[64];		// 说明我们接收到的字节不能超过64 
	static unsigned int n = 0;
	unsigned char i;
	
	//判断是否为接收中断	
	if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET) {
		buff[n++] = USART1->DR;		//读取接收到的字节数据
 
		// 超过长度就从头开始索引，覆盖原来的
		if(n == 64) {
			n = 0;
		}
	}
	//判断是否为空闲中断（读完一次完整的数据就进入空闲中断）
	if(USART_GetITStatus(USART1, USART_IT_IDLE) != RESET) {
		USART1->DR;		//读DR，清标志
		
		printf("%d characters:\r\n", n);
		for(i=0; i<n; i++) {
			printf("buff[%d] = 0x%02hhx\r\n", i, buff[i]);		//输出十六进制，保留最低两位，不够补0
		}
		n = 0;
	}
}

