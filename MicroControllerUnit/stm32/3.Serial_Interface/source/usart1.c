#include <string.h>
#include "led.h"
#include "nvic.h"
#include "delay.h"
#include "usart1.h"

void USART1_Init(unsigned int BaudRate) {
// 初始化串口1 																	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1 | RCC_APB2Periph_GPIOA, ENABLE);		// 使能USART1，GPIOA时钟
	GPIOA_Config();		// GPIO端口设置
	USART1_Config(BaudRate);		// USART初始化配置
	USART_Cmd(USART1, ENABLE);
}

void GPIOA_Config(void) {
	GPIO_InitTypeDef GPIO_InitStructure;
	
	// TX - PA.9
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;						//PA.9
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;			//复用推挽输出
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	// RX - PA.10
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;							//PA.10
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;		//浮空输入
	GPIO_Init(GPIOA, &GPIO_InitStructure);	
}	

void USART1_Config(unsigned int BaudRate) {
// 串口1的波特率设置
	USART_InitTypeDef USART_InitStructure;
	
	USART_InitStructure.USART_BaudRate = BaudRate;		//波特率
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;		//字长8位
	USART_InitStructure.USART_StopBits = USART_StopBits_1;		//停止位1位
	USART_InitStructure.USART_Parity = USART_Parity_No;			//无奇偶校验
	USART_InitStructure.USART_HardwareFlowControl	= USART_HardwareFlowControl_None;		//无硬件数据流控制
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;			//收/发模式
	
	USART_Init(USART1, &USART_InitStructure);
}

// 我在这里原本放了中断处理函数
// 现在我把它扔到nvic.c中了 
// TODO：如果有问题的话，我不得不把它又剪贴到这里
