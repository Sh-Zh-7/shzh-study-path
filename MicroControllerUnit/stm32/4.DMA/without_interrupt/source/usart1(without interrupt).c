#include <string.h>
#include "led.h"
#include "delay.h"
#include "nvic(without interrupt).h"
#include "usart1(without interrupt).h"

void USART1_Init(unsigned int BaudRate) {
// ��ʼ������1 																	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1 | RCC_APB2Periph_GPIOA, ENABLE);		// ʹ��USART1��GPIOAʱ��
	GPIOA_Config();							// GPIO�˿�����
	USART1_Config(BaudRate);		// USART��ʼ������
	NVIC_Config();
	// ʹ�ܴ���
	USART_Cmd(USART1, ENABLE);
}

void GPIOA_Config(void) {
	GPIO_InitTypeDef GPIO_InitStructure;
	
	// TX - PA.9
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;						//PA.9
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;			//�����������
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	// RX - PA.10
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;							//PA.10
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;		//��������
	GPIO_Init(GPIOA, &GPIO_InitStructure);	
}	

void USART1_Config(unsigned int BaudRate) {
// ����1�Ĳ���������
	USART_InitTypeDef USART_InitStructure;
	
	USART_InitStructure.USART_BaudRate = BaudRate;		//������
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;		//�ֳ�8λ
	USART_InitStructure.USART_StopBits = USART_StopBits_1;		//ֹͣλ1λ
	USART_InitStructure.USART_Parity = USART_Parity_No;			//����żУ��
	USART_InitStructure.USART_HardwareFlowControl	= USART_HardwareFlowControl_None;		//��Ӳ������������
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;			//˫��
	
	USART_Init(USART1, &USART_InitStructure);
}



