#include "stm32f10x.h"
#include "Delay.h"
#include "OLED.h"
#include "Serial.h"
#include "key.h"

uint8_t KeyNum;

int main(void)
{
	OLED_Init();
	Serial_Inir();
	Key_Init();
	
	OLED_ShowString(1,1,"TxPacket");
	OLED_ShowString(3,1,"RxPacket");	
	
	Serial_TXPacket[0] = 0x01;
	Serial_TXPacket[1] = 0x02;
	Serial_TXPacket[2] = 0x03;
	Serial_TXPacket[3] = 0x04;
	
	Serial_SendPacket();
	while(1)
    {
		KeyNum = Key_GetNum();
		if(KeyNum == 1)
		{
			Serial_TXPacket[0] ++;
			Serial_TXPacket[1] ++;
			Serial_TXPacket[2] ++;
			Serial_TXPacket[3] ++;
			
			Serial_SendPacket();
			
			for(uint8_t i = 0;i <= 3;i++)
			{
				OLED_ShowHexNum(2,i*3+1,Serial_TXPacket[i],2);
			}
			
		}   
		
		if(Serial_GetRxFlag() == 1)
		{
			for(uint8_t i = 0;i <= 3;i++)
			{
				OLED_ShowHexNum(4,i*3+1,Serial_RXPacket[i],2);
			}
		}
	}
}
