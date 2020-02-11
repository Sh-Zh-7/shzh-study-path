#include "delay.h"
#include "adc.h"

// �������ǽ��Թ���ͨ��Ϊ��
// ����Ĭ�Ͻ�����ͨ��0~3
void Adc_Init(void) {
// ��ʼ��ADC	
	// ʹ��ADC1��ͨ��ʱ�ӣ����ǵİ�����һ����3��ADC��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_ADC1, ENABLE);
	//����ADC��Ƶ����6, 72M / 6 = 12, ADC���ʱ�䲻�ܳ���14M
	RCC_ADCCLKConfig(RCC_PCLK2_Div6); 
	GPIO_Config();
	ADC1_Config();
}

static void GPIO_Config(void) {
// ��������
	GPIO_InitTypeDef GPIO_InitStructure;
	// PA.1
	GPIO_InitStructure.GPIO_Pin =GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;		// ģ������
	GPIO_Init(GPIOA, &GPIO_InitStructure); 
}


static void ADC1_Config(void) {
// ����ADC1
	ADC_InitTypeDef ADC_InitStructure;
	
	// ��ʼ��ADC1
	ADC_DeInit(ADC1); //��λADC1,������ADC1 ��ȫ���Ĵ�������Ϊȱʡֵ
	ADC_InitStructure.ADC_Mode = ADC_Mode_Independent; 		//ADC ����ģʽ
	ADC_InitStructure.ADC_ScanConvMode = DISABLE; 				//��ͨ��ģʽ
	ADC_InitStructure.ADC_ContinuousConvMode = DISABLE; 	//����ת��ģʽ
	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;		//ת��������������ⲿ��������
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right; 								//ADC �����Ҷ���
	ADC_InitStructure.ADC_NbrOfChannel = 1; 							//˳����й���ת����ADC ͨ������
	ADC_Init(ADC1, &ADC_InitStructure); 									//����ָ���Ĳ�����ʼ������ADCx
	ADC_Cmd(ADC1, ENABLE); 											//ʹ��ָ����ADC1
	
	// У׼
	ADC_ResetCalibration(ADC1); 								//������λУ׼
	while(ADC_GetResetCalibrationStatus(ADC1)); //�ȴ���λУ׼����
	ADC_StartCalibration(ADC1); 								//����ADУ׼
	while(ADC_GetCalibrationStatus(ADC1)); 			//�ȴ�У׼����
}

static u16 GetADC(u8 ch) {
// ���ADCֵ
// ch������ָ����ͨ��
	//����ָ��ADC�Ĺ�����ͨ�����������ǵ�ת��˳��Ͳ���ʱ��
	ADC_RegularChannelConfig(ADC1, ch, 1, ADC_SampleTime_239Cycles5 );
	//ͨ��1,�������˳��ֵΪ1,����ʱ��Ϊ239.5 ����
	ADC_SoftwareStartConvCmd(ADC1, ENABLE); 					//ʹ�����ת������
	while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));		//�ȴ�ת������
	return ADC_GetConversionValue(ADC1); 							//�������һ��ADC1 �������ת�����
}

u16 GetADCAverage(u8 ch,u8 times) {
// ���ƽ��ADCֵ
	u32 temp_val=0;
	for(u8 t = 0; t < times; ++t) {
		temp_val += GetADC(ch);
		delay_ms(5);
	}
	return temp_val / times;
}

