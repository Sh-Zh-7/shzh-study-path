#include "nvic(without interrupt).h"

void NVIC_Config(void) {
// 串口1的中断配置 
// 此处不应该设有中断服务函数 
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);			// 中断分组1：1位抢占优先级，3位响应优先级	
}
