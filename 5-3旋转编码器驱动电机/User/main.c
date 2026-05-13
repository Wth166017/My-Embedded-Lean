#include "stm32f10x.h"
#include "Delay.h"
#include "OLED.h"
#include "Motor.h"
#include "Encoder.h"
int16_t speed;
int main(void)
{
	OLED_Init();
	Motor_Init();
	Encoder_Init();
	
	OLED_ShowString(1,1,"speed:");
	
	while(1)
	{
		
        speed += Encoder_Get();
		
		Motor_SetSpeed(speed); 
		OLED_ShowSignedNum(1,7,speed,3);
	}	
}
