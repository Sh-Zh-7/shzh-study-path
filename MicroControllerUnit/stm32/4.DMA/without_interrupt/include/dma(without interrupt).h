#ifndef DMA_H__
#define DMA_H__

#include "stm32f10x_dma.h"

void MYDMA_Config(DMA_Channel_TypeDef*, u32,u32, u16);
void MYDMA_Enable(DMA_Channel_TypeDef*);

#endif // DMA_H__

