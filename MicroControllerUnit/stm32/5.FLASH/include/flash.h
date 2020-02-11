#ifndef FLASH_H__
#define FLASH_H__

#include "stm32f10x_flash.h"

#define STM32_FLASH_WREN 1		// ʹ��д
#define STM32_FLASH_PAGE 1024  // �Զ��������ҳ��
#define FLASH_SAVE_ADDR  0x08070000 //����FLASH �����ַ

// �����STM32_FLASH_PAGEΪ�����ҳ��
#if STM32_FLASH_PAGE < 256		// С������Ʒ
#define STM_SECTOR_SIZE 1024 	// ���ֽ�Ϊ��λ
#else		// ��������Ʒ
#define STM_SECTOR_SIZE 2048
#endif

typedef unsigned short u16;
typedef unsigned int u32;

u16 STMFLASH_ReadHalfWord(u32);
void STMFLASH_Write_NoCheck(u32,  u16, u16*);
void STMFLASH_Write(u32, u16, u16*);
void STMFLASH_Read(u32, u16, u16*);

#endif // FLASH_H__

