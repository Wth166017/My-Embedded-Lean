#include "stm32f10x.h"                  // Device header

void LightSensor_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
		GPIO_InitTypeDef GPIO_Initsture;
		GPIO_Initsture.GPIO_Mode=GPIO_Mode_IPU;
		GPIO_Initsture.GPIO_Pin=GPIO_Pin_13;
		GPIO_Initsture.GPIO_Speed=GPIO_Speed_50MHz;
		GPIO_Init(GPIOB,&GPIO_Initsture);
}

uint8_t LihhtSensor_Get(void)
{
	return GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_13);
}
