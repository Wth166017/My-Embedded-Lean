#include "stm32f10x.h"
#include "Delay.h"
#include "OLED.h"
#include "PWM.h"
#include "IC.h"
int main(void)
{
	OLED_Init();
	PWM_Init();
	IC_Init();
	
	OLED_ShowString(1,1,"Freq:00000HZ");
	
	PWM_SetPrescaler(720-1);
	PWM_SetComparel(50);
	
	while(1)
    {
		OLED_ShowNum(1,6,IC_GetFreg(),5);
	}	
}
