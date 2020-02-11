#include "no_semi_hosting.h"

FILE __stdout;
 
void _sys_exit(int x) {}
	
// 重定义fgetc()
int fputc(int ch, FILE *f) {
	while(USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET);		//等待上次发送结束
	USART_SendData(USART1, (unsigned char)ch);				//发送数据到串口
	return ch;
}	
