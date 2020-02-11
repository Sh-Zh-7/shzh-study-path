#ifndef NO_SEMI_HOSTING_H__
#define NO_SEMI_HOSTING_H__

// 禁用semihost模式
#pragma import(__use_no_semihosting)
#include <stdio.h>		// 引入FILE结构体
#include "stm32f10x_usart.h"		// 引入串口的头文件

// 禁用semihost模式下所需的结构体和函数原型
struct __FILE {
	int a;
};
 
void _sys_exit(int);
int fputc(int, FILE*);

#endif // NO_SEMI_HOSING_H__

