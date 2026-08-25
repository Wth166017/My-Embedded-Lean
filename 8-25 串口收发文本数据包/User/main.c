#include "stm32f10x.h"
#include "Delay.h"
#include "OLED.h"
#include "Serial.h"
#include "key.h"
#include "LED.h"
#include <string.h>

int main(void)
{
	OLED_Init();
	LED_Init();
	Serial_Inir();
	
	
	OLED_ShowString(1,1,"TxPacket");
	OLED_ShowString(3,1,"RxPacket");	

	while(1)
    {
		if(Serial_GetRxFlag() ==1)
		{
			OLED_ShowString(4,1,"				");
			OLED_ShowString(4,1,Serial_RXPacket);
			
			if(strcmp(Serial_RXPacket,"LED_ON") == 0)
			{
				LED1_ON();
				Serial_SendString("LED_ON\r\n");
				OLED_ShowString(2,1,"				");
				OLED_ShowString(2,1,"LED1_ON_OK");
			}
			else if(strcmp(Serial_RXPacket,"LED_OFF") == 0)
			{
				LED1_OFF();
				Serial_SendString("LED_OFF\r\n");
				OLED_ShowString(2,1,"				");
				OLED_ShowString(2,1,"LED1_OFF_OK");
			}
			else
			{
				Serial_SendString("ERROR_COMMAND\r\n");
				OLED_ShowString(2,1,"				");
				OLED_ShowString(2,1,"ERROR_COMMAND");
			}
		}
	}
}
