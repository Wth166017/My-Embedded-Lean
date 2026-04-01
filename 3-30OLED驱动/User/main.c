#include "stm32f10x.h"
#include "Delay.h"
#include "OLED.h"
uint8_t KeyNum;
int main(void)
{
	OLED_Init();
	
	OLED_ShowChar(1,1,'*');
	OLED_ShowChar(1,16,'*');
	OLED_ShowString(1,3,"HELLO  WORLD");
	
	while(1)
    {
		
	}
}
