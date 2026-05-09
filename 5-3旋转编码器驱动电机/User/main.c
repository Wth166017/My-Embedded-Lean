#include "stm32f10x.h"
#include "Delay.h"
#include "OLED.h"
#include "Motor.h"
#include "Encoder.h"

int16_t Speed=0;

int main(void)
{
	OLED_Init();
	Motor_Init();
	Encoder_Init();
	
	OLED_ShowString(1,1,"speed:");
	
	while(1)
	{
		int16_t delta = Encoder_Get();
        Speed += delta;
		
        if (Speed > 100) Speed = 100;
        if (Speed < -100)   Speed = -100;

       
		Motor_SetSpeed(Speed); 
		OLED_ShowNum(1,7,Speed,3);
	}	
}
