#include "stm32f10x.h"
#include "Delay.h"
#include "OLED.h"
#include "Serial.h"
uint8_t KeyNum;
int main(void)
{
	OLED_Init();
	Serial_Inir();
	
//	Serial_SendByte(1234);
//	uint8_t arraya[2] = {0x30,0x31};
//	Serial_SendArray(arraya, 2);
//	Serial_SendString( "HelloWord!\r\n");
//	Serial_SendNumber(1234,4);
	printf("哈哈哈");
	while(1)
    {
		
	}
}
