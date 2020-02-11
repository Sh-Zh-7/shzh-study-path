#include "dma(without interrupt).h"

u16 DMA1_MEM_LEN;//����DMAÿ�����ݴ��͵ĳ���

void MYDMA_Config(DMA_Channel_TypeDef* DMA_CHx, u32 cpar, u32 cmar,u16 cndtr) {
//DMA1 �ĸ�ͨ������
	DMA_InitTypeDef DMA_InitStructure;
	
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE); //ʹ��DMA ʱ��
	DMA_DeInit(DMA_CHx); 															 //��DMA��ͨ��1�Ĵ�������Ϊȱʡֵ����CH��ʵ����Channle�ļ�д
  DMA1_MEM_LEN = cndtr;
	
	// ��ʵ���cpar�������Ǵ��������ַ���
	DMA_InitStructure.DMA_PeripheralBaseAddr = cpar; 		// �������ַ�������cpar��������Ϊ�����������ģ�
	DMA_InitStructure.DMA_MemoryBaseAddr = cmar; 				// �洢�ڻ���ַ����������ѡ������������ĵ�ַ��
	DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC; 	// ���ݴ��䷽������赽�ڴ�
	DMA_InitStructure.DMA_BufferSize = cndtr; 					// DMAͨ����DMA����Ĵ�С
	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable; 					// �����ַ����
	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;										// �ڴ��ַ�Ĵ�������
	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;		//ÿ�δ���һ���ֽ�
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte; 
	DMA_InitStructure.DMA_Mode = DMA_Mode_Normal; 						// ��������������ģʽ
	DMA_InitStructure.DMA_Priority = DMA_Priority_Medium;		 	// DMͨ��ӵ�������ȼ�
	DMA_InitStructure.DMA_M2M = DMA_M2M_Disable; 							// ���ڴ浽�ڴ洫��
	DMA_Init(DMA_CHx, &DMA_InitStructure); 										// ��ʼ��DMA��ͨ��
}

void MYDMA_Enable(DMA_Channel_TypeDef* DMA_CHx) {
// ����һ��DMA����
	DMA_Cmd(DMA_CHx, DISABLE); 														// �ر�USART1 TX DMA1 ��ָʾ��ͨ��
	DMA_SetCurrDataCounter(DMA1_Channel5, DMA1_MEM_LEN);	// ����DMA����Ĵ�С
	DMA_Cmd(DMA_CHx, ENABLE); 	
}

