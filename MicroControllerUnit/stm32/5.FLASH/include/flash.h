#ifndef FLASH_H__
#define FLASH_H__

#include "stm32f10x_flash.h"

#define STM32_FLASH_WREN 1		// 使能写
#define STM32_FLASH_PAGE 1024  // 自定义闪存的页数
#define FLASH_SAVE_ADDR  0x08070000 //设置FLASH 保存地址

// 这里的STM32_FLASH_PAGE为闪存的页数
#if STM32_FLASH_PAGE < 256		// 小容量产品
#define STM_SECTOR_SIZE 1024 	// 以字节为单位
#else		// 大容量产品
#define STM_SECTOR_SIZE 2048
#endif

typedef unsigned short u16;
typedef unsigned int u32;

u16 STMFLASH_ReadHalfWord(u32);
void STMFLASH_Write_NoCheck(u32,  u16, u16*);
void STMFLASH_Write(u32, u16, u16*);
void STMFLASH_Read(u32, u16, u16*);

#endif // FLASH_H__

