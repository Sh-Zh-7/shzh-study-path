#include "delay.h"

void delay_ms(unsigned int t) {
#if defined USE_UCOSII
	OSTimeDly (t);
#else
	// 这里利用CPU的频率搞出单位时间内所需要的操作的次数
	// 在传入t，对这个单位事件的操作进行循环
	for(int i = 0; i < t; ++i) {
		#if defined(STM32F10X_LD)||defined (STM32F10X_LD_VL)||defined (STM32F10X_MD)||defined (STM32F10X_MD_VL)||defined (STM32F10X_HD)||defined (STM32F10X_HD_VL)||defined (STM32F10X_XL)||defined (STM32F10X_CL) 
		int a = 10300; //F1 at 72MHz 10300 is ok
		#elif defined(STM32F4XX)
		//int a=42000; //F4 at 168MHz 42000 is ok
		#endif 
 		while(a--);
	}
#endif
}

void delay_us(unsigned int t) {
	for(int i = 0; i < t; ++i) {
		#if defined(STM32F10X_LD)||defined (STM32F10X_LD_VL)||defined (STM32F10X_MD)||defined (STM32F10X_MD_VL)||defined (STM32F10X_HD)||defined (STM32F10X_HD_VL)||defined (STM32F10X_XL)||defined (STM32F10X_CL) 
		int a = 9;  //F1 at 72MHz 9 is ok
		#elif defined(STM32F4XX)
	// int a=40; //F4 at 168MHz 40 is ok
		#endif
		while(a--);
	}
}

