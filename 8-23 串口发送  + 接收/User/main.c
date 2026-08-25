#include "stm32f10x.h"
#include "Delay.h"
#include "OLED.h"
#include "Serial.h"
uint8_t RxDate;
int main(void)
{
	OLED_Init();
	Serial_Inir();
	
	while(1)
    {
		if(Serial_GetRxFlag() == 1)
		{
			RxDate = Serial_GetRxData();
			Serial_SendByte(RxDate);
			OLED_ShowHexNum(1,1,RxDate,2);
		}
	}
}
