#include "stm32f10x.h"
#include "OLED.h"

void Serial_Init(void){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	GPIO_InitTypeDef GPIO_Initstruct;
	GPIO_Initstruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Initstruct.GPIO_Pin = GPIO_Pin_9;
	GPIO_Initstruct.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Init(GPIOA,&GPIO_Initstruct);


	GPIO_Initstruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Initstruct.GPIO_Pin = GPIO_Pin_10;
	GPIO_Initstruct.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_Init(GPIOA,&GPIO_Initstruct);
	
	USART_InitTypeDef USART_InitStructure;
	USART_InitStructure.USART_BaudRate  = 9600;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Tx |  USART_Mode_Rx;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_Init(USART1,&USART_InitStructure);
	
	USART_Cmd(USART1,ENABLE);
}


void Serial_SendByte(uint8_t Byte)
{
	USART_SendData(USART1,Byte);
	while(USART_GetFlagStatus(USART1,USART_FLAG_TXE) == RESET);
	
}

uint8_t Serial_ReceiveByte(void)
{
	uint8_t RxData;
	
	if(USART_GetFlagStatus(USART1,USART_FLAG_RXNE) ==  SET)
	{
		RxData = USART_ReceiveData(USART1);
		OLED_ShowHexNum(1,1,RxData,2);
	}
	return RxData;
}



void Serial_SendArray(uint8_t *Array,uint16_t Length){
	uint16_t i;
	for( i = 0;i < Length;i ++){
		Serial_SendByte(Array[i]);
	}
}

void Serial_SendString(char *String){
	uint8_t i;
	for( i = 0;String[i] != '\0';i++){
		Serial_SendByte(String[i]);
	}
}

uint32_t Serial_Pow(uint32_t X,uint32_t Y){
	uint32_t result = 1;
	while(Y--){
		result = result*X;
	}
	return result;
}

void Serial_SendNumber(uint32_t Number,uint8_t  Length){
	for(uint8_t i = 0;i < Length;i ++)
	{
		 Serial_SendByte(Number / Serial_Pow(10,Length-i-1) % 10+'0');
	}
	
}

