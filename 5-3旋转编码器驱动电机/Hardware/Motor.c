#include "stm32f10x.h"                  // Device header
#include "pwm.h"

void Motor_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	// 2. 定义一个GPIO初始化结构体，用来存放配置参数
	GPIO_InitTypeDef GPIO_InitStruct;  
	// 3. 配置GPIO模式：推挽输出（可以输出强高低电平，驱动LED）
	GPIO_InitStruct.GPIO_Mode= GPIO_Mode_Out_PP;
	// 4. 配置要操作的引脚：同时选择 PA1 和 PA2
	GPIO_InitStruct.GPIO_Pin= GPIO_Pin_4| GPIO_Pin_5;
	// 5. 配置IO口翻转速度：50MHz（驱动LED足够用）
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz ;
	// 6. 根据结构体参数，初始化GPIOA相关引脚
	GPIO_Init(GPIOA,&GPIO_InitStruct);
	
	PWM_Init();
}

void Motor_SetSpeed(int16_t speed)
{
	if(speed>=0)
	{
		GPIO_SetBits(GPIOA,GPIO_Pin_4);
		GPIO_ResetBits(GPIOA,GPIO_Pin_5);
		PWM_SetCompare3(speed);
	
	}
	else
	{
		GPIO_SetBits(GPIOA,GPIO_Pin_5);
		GPIO_ResetBits(GPIOA,GPIO_Pin_4);
		PWM_SetCompare3(-speed);
	}
}
