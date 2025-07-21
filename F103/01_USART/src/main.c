#include "stm32f10x.h"
#include "OLED.h"
#include "delay.h"
#include "Serial.h"

int main(void)
{
	OLED_Init();
	
	Serial_Init();
	//Serial_SendByte(0x41);
	
	//uint8_t MyArray[]={0x42,0x43,0x44,0x45};
	//Serial_SendArray(MyArray,4); 
	Serial_SendNumber(12345,5);
	
	while(1){
		Serial_ReceiveByte();
	}
}

