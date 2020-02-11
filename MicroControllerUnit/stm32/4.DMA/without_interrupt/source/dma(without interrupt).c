#include "dma(without interrupt).h"

u16 DMA1_MEM_LEN;//保存DMA每次数据传送的长度

void MYDMA_Config(DMA_Channel_TypeDef* DMA_CHx, u32 cpar, u32 cmar,u16 cndtr) {
//DMA1 的各通道配置
	DMA_InitTypeDef DMA_InitStructure;
	
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE); //使能DMA 时钟
	DMA_DeInit(DMA_CHx); 															 //将DMA的通道1寄存器重设为缺省值——CH其实就是Channle的简写
  DMA1_MEM_LEN = cndtr;
	
	// 其实这个cpar就是我们传进来的字符串
	DMA_InitStructure.DMA_PeripheralBaseAddr = cpar; 		// 外设基地址（这里的cpar我们是作为参数传进来的）
	DMA_InitStructure.DMA_MemoryBaseAddr = cmar; 				// 存储期基地址（这里我们选择用我们数组的地址）
	DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC; 	// 数据传输方向从外设到内存
	DMA_InitStructure.DMA_BufferSize = cndtr; 					// DMA通道的DMA缓存的大小
	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable; 					// 外设地址不变
	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;										// 内存地址寄存器递增
	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;		//每次传输一个字节
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte; 
	DMA_InitStructure.DMA_Mode = DMA_Mode_Normal; 						// 工作在正常缓存模式
	DMA_InitStructure.DMA_Priority = DMA_Priority_Medium;		 	// DM通道拥有中优先级
	DMA_InitStructure.DMA_M2M = DMA_M2M_Disable; 							// 非内存到内存传输
	DMA_Init(DMA_CHx, &DMA_InitStructure); 										// 初始化DMA的通道
}

void MYDMA_Enable(DMA_Channel_TypeDef* DMA_CHx) {
// 开启一次DMA传输
	DMA_Cmd(DMA_CHx, DISABLE); 														// 关闭USART1 TX DMA1 所指示的通道
	DMA_SetCurrDataCounter(DMA1_Channel5, DMA1_MEM_LEN);	// 设置DMA缓存的大小
	DMA_Cmd(DMA_CHx, ENABLE); 	
}

