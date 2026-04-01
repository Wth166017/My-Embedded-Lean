#include "stm32f10x.h"   // Device header
#include "Delay.h"
void Key_Init(void)
{
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
		GPIO_InitTypeDef GPIO_Initsture;
		GPIO_Initsture.GPIO_Mode=GPIO_Mode_IPU;
		GPIO_Initsture.GPIO_Pin=GPIO_Pin_1|GPIO_Pin_11;
		GPIO_Initsture.GPIO_Speed=GPIO_Speed_50MHz;
		GPIO_Init(GPIOB,&GPIO_Initsture);
}	 
uint8_t Key_GetNum(void)
{
	uint8_t Key=0;
	if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_1) ==0)
	{
		Delay_ms(20);
		while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_1) ==0)
		Delay_ms(20);
		Key=1;
	}
	if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_11) ==0)
	{
		Delay_ms(20);
		while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_11) ==0)
		Delay_ms(20);
		Key=2;
	}
	return Key;
}
