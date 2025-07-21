#ifndef __SERIAL_H
#define __SERIAL_H

void Serial_Init(void);
void Serial_SendByte(uint8_t Byte);
void Serial_SendArray(uint8_t *Array, uint16_t Length);
void Serial_SendNumber(uint32_t Number,uint8_t  Length);
uint8_t Serial_ReceiveByte(void);

#endif
