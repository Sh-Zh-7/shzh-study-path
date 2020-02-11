#include "flash.h"

const int total_num_in_sector = STM32_FLASH_PAGE / 2;		// 确定可以写入的总数,注意一次只能写2个字节
u16 STMFLASH_BUF[total_num_in_sector];

// --------------------------------------------------------------------------------------------------- //
// 写操作：
#if STM32_FLASH_WREN		// 如果使能了写
void STMFLASH_Write_NoCheck(u32 write_addr, u16 num_to_write, u16* pBuffer) {
// 往FLASH没有检测地写东西
	for (int i = 0; i < num_to_write; ++i) {
		FLASH_ProgramHalfWord(write_addr, pBuffer[i]);
		write_addr += 2;		// 指向下两个字节
	}
}

void STMFLASH_Write(u32 address_to_write, u16 num_to_write, u16* pBuffer) {
// 注意这里的num_to_write也是以2个字节为单位的
	u32 off_address;							// 去掉0X08000000后的地址
	u32 position_of_sector;				// 扇区的地址
	u16 offset_num_in_sector; 		// 在扇区的哪个元素位置
	u16 remain_num_in_sector;			// 扇区还剩多少元素可写
	
	// 不允许用户向非法的内存中写数据
	if (address_to_write < FLASH_BASE
		|| address_to_write >= (FLASH_BASE + STM_SECTOR_SIZE * STM32_FLASH_PAGE)) {
			return; 
	}
	
	FLASH_Unlock();	
	
	// 赋值
	off_address = address_to_write - FLASH_BASE;	
	position_of_sector = off_address / STM_SECTOR_SIZE;				
	offset_num_in_sector = off_address % STM_SECTOR_SIZE / 2;	
	remain_num_in_sector = total_num_in_sector - offset_num_in_sector;
	
	// 用remain_num_in_sector来确定要写多少元素 		
	if (num_to_write <= remain_num_in_sector) {
		remain_num_in_sector = num_to_write;	
	}
	
	while (1) {
		int i;
		STMFLASH_Read(address_to_write, total_num_in_sector, STMFLASH_BUF);		// 读取<b>整个</b>扇区的内容，放在BUF中
		for(i = 0; i < remain_num_in_sector; ++i) { 		// 读取的还是两个字节
			if(STMFLASH_BUF[offset_num_in_sector + i] != 0xFFFF) break;		// 需要擦除
		}
		if(i < remain_num_in_sector) { 	// 需要擦除
			FLASH_ErasePage(address_to_write);					// 擦除这个扇区
			for(i = 0; i < remain_num_in_sector; ++i) {	
				STMFLASH_BUF[i + offset_num_in_sector]=pBuffer[i];			// 开始赋值
			}
			STMFLASH_Write_NoCheck(address_to_write, total_num_in_sector, STMFLASH_BUF);// 写入整个扇区
		} else {
			STMFLASH_Write_NoCheck(address_to_write, remain_num_in_sector, pBuffer); 	//写已经擦除了的,直接写入扇区剩余区间.
		}
		
		if(num_to_write <= remain_num_in_sector) break;// 写入结束了
		else {	
			// 写入下一个扇区
			++position_of_sector; 
			offset_num_in_sector = 0;
			// 从上次未写完的buffer后面继续写
			pBuffer += remain_num_in_sector;
			address_to_write += remain_num_in_sector; 	// 写地址偏移
			num_to_write -= remain_num_in_sector; 	// 字节数递减
			
			//下一个扇区还是写不完
			if(num_to_write > total_num_in_sector) {
				remain_num_in_sector = total_num_in_sector;
			}
			else remain_num_in_sector = num_to_write;		//下一个扇区可以写完了
		}
	}
	
	// 上锁 
	FLASH_Lock();
}
#endif

// ---------------------------------------------------------------------------------------------------//
// 读操作
u16 STMFLASH_ReadHalfWord(u32 flash_addr) {
// 读取指定地址的半字（16位数据）
	return * (vu16*)flash_addr;
}

void STMFLASH_Read(u32 address_of_read, u16 num_to_read, u16 *pBuffer) {
// 每两个字节读取,直到读到指定位置的元素为止
	for(int i = 0;i < num_to_read; ++i) {
		pBuffer[i]=STMFLASH_ReadHalfWord(address_of_read);		// 读取2个字节.
		address_of_read += 2; 	// 偏移2个字节.
	}
}

	


