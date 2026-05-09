#include "stm32f10x.h"
#include "Delay.h"
#include "OLED.h"
#include "Timer.h"
uint16_t Num;
int main(void)
{
	OLED_Init();
    Timer_Init();
	OLED_ShowString(1,1,"NUM:");
	OLED_ShowString(2,1,"CNT:");

	while(1)
    {
		OLED_ShowNum(1,5,Num,5);
		OLED_ShowNum(2,5,Timer_GetCounter(),5);

	}
}
void TIM2_IRQHandler(void)
{
	if (TIM_GetITStatus(TIM2, TIM_IT_Update) == SET)		//判断是否是TIM2的更新事件触发的中断
	{
		Num ++;												//Num变量自增，用于测试定时中断
				//清除TIM2更新事件的中断标志位
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);															//中断标志位必须清除
															//否则中断将连续不断地触发，导致主程序卡死
	}
}

