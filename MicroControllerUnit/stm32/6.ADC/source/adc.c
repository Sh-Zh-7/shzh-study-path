#include "delay.h"
#include "adc.h"

// 这里我们仅以规则通道为例
// 我们默认将开启通道0~3
void Adc_Init(void) {
// 初始化ADC	
	// 使能ADC1的通道时钟（我们的板子上一共有3个ADC）
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_ADC1, ENABLE);
	//设置ADC分频因子6, 72M / 6 = 12, ADC最大时间不能超过14M
	RCC_ADCCLKConfig(RCC_PCLK2_Div6); 
	GPIO_Config();
	ADC1_Config();
}

static void GPIO_Config(void) {
// 配置引脚
	GPIO_InitTypeDef GPIO_InitStructure;
	// PA.1
	GPIO_InitStructure.GPIO_Pin =GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;		// 模拟输入
	GPIO_Init(GPIOA, &GPIO_InitStructure); 
}


static void ADC1_Config(void) {
// 配置ADC1
	ADC_InitTypeDef ADC_InitStructure;
	
	// 初始化ADC1
	ADC_DeInit(ADC1); //复位ADC1,将外设ADC1 的全部寄存器重设为缺省值
	ADC_InitStructure.ADC_Mode = ADC_Mode_Independent; 		//ADC 独立模式
	ADC_InitStructure.ADC_ScanConvMode = DISABLE; 				//单通道模式
	ADC_InitStructure.ADC_ContinuousConvMode = DISABLE; 	//单次转换模式
	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;		//转换由软件而不是外部触发启动
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right; 								//ADC 数据右对齐
	ADC_InitStructure.ADC_NbrOfChannel = 1; 							//顺序进行规则转换的ADC 通道的数
	ADC_Init(ADC1, &ADC_InitStructure); 									//根据指定的参数初始化外设ADCx
	ADC_Cmd(ADC1, ENABLE); 											//使能指定的ADC1
	
	// 校准
	ADC_ResetCalibration(ADC1); 								//开启复位校准
	while(ADC_GetResetCalibrationStatus(ADC1)); //等待复位校准结束
	ADC_StartCalibration(ADC1); 								//开启AD校准
	while(ADC_GetCalibrationStatus(ADC1)); 			//等待校准结束
}

static u16 GetADC(u8 ch) {
// 获得ADC值
// ch是我们指定的通道
	//设置指定ADC的规则组通道，设置它们的转化顺序和采样时间
	ADC_RegularChannelConfig(ADC1, ch, 1, ADC_SampleTime_239Cycles5 );
	//通道1,规则采样顺序值为1,采样时间为239.5 周期
	ADC_SoftwareStartConvCmd(ADC1, ENABLE); 					//使能软件转换功能
	while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));		//等待转换结束
	return ADC_GetConversionValue(ADC1); 							//返回最近一次ADC1 规则组的转换结果
}

u16 GetADCAverage(u8 ch,u8 times) {
// 获得平均ADC值
	u32 temp_val=0;
	for(u8 t = 0; t < times; ++t) {
		temp_val += GetADC(ch);
		delay_ms(5);
	}
	return temp_val / times;
}

