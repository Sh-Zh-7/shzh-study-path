#include "nvic(without interrupt).h"

void NVIC_Config(void) {
// ����1���ж����� 
// �˴���Ӧ�������жϷ����� 
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);			// �жϷ���1��1λ��ռ���ȼ���3λ��Ӧ���ȼ�	
}
