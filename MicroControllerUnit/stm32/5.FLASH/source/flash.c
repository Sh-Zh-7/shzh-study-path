#include "flash.h"

const int total_num_in_sector = STM32_FLASH_PAGE / 2;		// ȷ������д�������,ע��һ��ֻ��д2���ֽ�
u16 STMFLASH_BUF[total_num_in_sector];

// --------------------------------------------------------------------------------------------------- //
// д������
#if STM32_FLASH_WREN		// ���ʹ����д
void STMFLASH_Write_NoCheck(u32 write_addr, u16 num_to_write, u16* pBuffer) {
// ��FLASHû�м���д����
	for (int i = 0; i < num_to_write; ++i) {
		FLASH_ProgramHalfWord(write_addr, pBuffer[i]);
		write_addr += 2;		// ָ���������ֽ�
	}
}

void STMFLASH_Write(u32 address_to_write, u16 num_to_write, u16* pBuffer) {
// ע�������num_to_writeҲ����2���ֽ�Ϊ��λ��
	u32 off_address;							// ȥ��0X08000000��ĵ�ַ
	u32 position_of_sector;				// �����ĵ�ַ
	u16 offset_num_in_sector; 		// ���������ĸ�Ԫ��λ��
	u16 remain_num_in_sector;			// ������ʣ����Ԫ�ؿ�д
	
	// �������û���Ƿ����ڴ���д����
	if (address_to_write < FLASH_BASE
		|| address_to_write >= (FLASH_BASE + STM_SECTOR_SIZE * STM32_FLASH_PAGE)) {
			return; 
	}
	
	FLASH_Unlock();	
	
	// ��ֵ
	off_address = address_to_write - FLASH_BASE;	
	position_of_sector = off_address / STM_SECTOR_SIZE;				
	offset_num_in_sector = off_address % STM_SECTOR_SIZE / 2;	
	remain_num_in_sector = total_num_in_sector - offset_num_in_sector;
	
	// ��remain_num_in_sector��ȷ��Ҫд����Ԫ�� 		
	if (num_to_write <= remain_num_in_sector) {
		remain_num_in_sector = num_to_write;	
	}
	
	while (1) {
		int i;
		STMFLASH_Read(address_to_write, total_num_in_sector, STMFLASH_BUF);		// ��ȡ<b>����</b>���������ݣ�����BUF��
		for(i = 0; i < remain_num_in_sector; ++i) { 		// ��ȡ�Ļ��������ֽ�
			if(STMFLASH_BUF[offset_num_in_sector + i] != 0xFFFF) break;		// ��Ҫ����
		}
		if(i < remain_num_in_sector) { 	// ��Ҫ����
			FLASH_ErasePage(address_to_write);					// �����������
			for(i = 0; i < remain_num_in_sector; ++i) {	
				STMFLASH_BUF[i + offset_num_in_sector]=pBuffer[i];			// ��ʼ��ֵ
			}
			STMFLASH_Write_NoCheck(address_to_write, total_num_in_sector, STMFLASH_BUF);// д����������
		} else {
			STMFLASH_Write_NoCheck(address_to_write, remain_num_in_sector, pBuffer); 	//д�Ѿ������˵�,ֱ��д������ʣ������.
		}
		
		if(num_to_write <= remain_num_in_sector) break;// д�������
		else {	
			// д����һ������
			++position_of_sector; 
			offset_num_in_sector = 0;
			// ���ϴ�δд���buffer�������д
			pBuffer += remain_num_in_sector;
			address_to_write += remain_num_in_sector; 	// д��ַƫ��
			num_to_write -= remain_num_in_sector; 	// �ֽ����ݼ�
			
			//��һ����������д����
			if(num_to_write > total_num_in_sector) {
				remain_num_in_sector = total_num_in_sector;
			}
			else remain_num_in_sector = num_to_write;		//��һ����������д����
		}
	}
	
	// ���� 
	FLASH_Lock();
}
#endif

// ---------------------------------------------------------------------------------------------------//
// ������
u16 STMFLASH_ReadHalfWord(u32 flash_addr) {
// ��ȡָ����ַ�İ��֣�16λ���ݣ�
	return * (vu16*)flash_addr;
}

void STMFLASH_Read(u32 address_of_read, u16 num_to_read, u16 *pBuffer) {
// ÿ�����ֽڶ�ȡ,ֱ������ָ��λ�õ�Ԫ��Ϊֹ
	for(int i = 0;i < num_to_read; ++i) {
		pBuffer[i]=STMFLASH_ReadHalfWord(address_of_read);		// ��ȡ2���ֽ�.
		address_of_read += 2; 	// ƫ��2���ֽ�.
	}
}

	


