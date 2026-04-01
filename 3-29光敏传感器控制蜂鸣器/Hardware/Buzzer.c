#include "stm32f10x.h"                  // Device header
void Buzzer_Init(void)
{	// 1. 开启GPIOB的时钟，所有GPIO必须先开时钟才能工作
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	// 2. 定义一个GPIO初始化结构体，用来存放配置参数
	GPIO_InitTypeDef GPIO_InitStruct;  
	// 3. 配置GPIO模式：推挽输出（可以输出强高低电平，驱动LED）
	GPIO_InitStruct.GPIO_Mode= GPIO_Mode_Out_PP;
	// 4. 配置要操作的引脚：同时选择 PA1 和 PA2
	GPIO_InitStruct.GPIO_Pin=  GPIO_Pin_12;
	// 5. 配置IO口翻转速度：50MHz（驱动LED足够用）
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz ;
	// 6. 根据结构体参数，初始化GPIOA相关引脚
	GPIO_Init(GPIOB,&GPIO_InitStruct);
	// 7. 将PA1、PA2设置为高电平，因为电路是低电平点亮，所以此时灯是熄灭的
	GPIO_SetBits(GPIOB, GPIO_Pin_12);
}

void Buzzer_ON(void)
{
	GPIO_ResetBits(GPIOB,GPIO_Pin_12);
}
void Buzzer_OFF(void)
{
	GPIO_SetBits(GPIOB,GPIO_Pin_12);
}
void Buzzer_Turn(void)
{
		if (GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_12)==0)
		{
			GPIO_SetBits(GPIOB,GPIO_Pin_12);
		}
		else
		{
			GPIO_ResetBits(GPIOB,GPIO_Pin_12);
		}
}
