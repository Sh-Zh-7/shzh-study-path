#include "no_semi_hosting.h"

FILE __stdout;
 
void _sys_exit(int x) {}
	
// �ض���fgetc()
int fputc(int ch, FILE *f) {
	while(USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET);		//�ȴ��ϴη��ͽ���
	USART_SendData(USART1, (unsigned char)ch);				//�������ݵ�����
	return ch;
}	
