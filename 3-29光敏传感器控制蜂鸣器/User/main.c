#include "stm32f10x.h"
#include "Delay.h"
#include "LED.h"
#include "key.h"
#include "Buzzer.h"
#include "LightSensor.h"
uint8_t KeyNum;
int main(void)
{
    Buzzer_Init();
	LightSensor_Init();
	LED_Init();
	Key_Init();
	while(1)
    {
		 KeyNum = Key_GetNum();  // 读按键
    if (KeyNum == 1)        // 如果按下了按键1
    {
        LED1_Turn();;        // 就调用翻转函数，灯状态变一次
    }
	if(KeyNum == 2)
		{
			 LED2_Turn();
		}
	  if(LihhtSensor_Get() == 1)
	  {
	  Buzzer_ON();
	  }
	  else
	 {
	  Buzzer_OFF();
	 }
	}
	
}
