#ifndef  __Serial_H
#define  __Serial_H
extern uint8_t Serial_TXPacket[];
extern uint8_t Serial_RXPacket[];

#include <stdio.h>

void Serial_Inir(void);
void Serial_SendByte(uint8_t Byte);
void Serial_SendArray(uint8_t *Array,uint16_t length);
void Serial_SendString(char *String);
void Serial_SendNumber(uint32_t Number,uint8_t Length);
void Serial_SendPacket(void);
uint8_t Serial_GetRxFlag(void);




#endif
