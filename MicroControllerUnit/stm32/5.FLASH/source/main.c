#include <stdio.h>
#include "no_semi_hosting.h"
#include "flash.h"
#include "usart1.h"
#include "delay.h"

int main(void) {
	u16 fuck[] = {666, 789};
	u16 temp[2];
	USART1_Init(115200);
	// NVIC���������ӵ��жϿ���ģ��
	// ���Է�����������������
	// ���������֮ǰд�Ĳ�ͬ�����ԶԱȵؿ���
	// ����Ҳ������usart1.hҪ�޸ĵĵط��� 
	NVIC_Config();
  STMFLASH_Write(FLASH_SAVE_ADDR, 2, fuck);
	STMFLASH_Read(FLASH_SAVE_ADDR, 2, temp);
	for (u8 i = 0; i < 2; ++i) {
		printf("%d\r\n", temp[i]);
	}
	while (1);
}
