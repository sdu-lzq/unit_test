#include "stm32f10x.h"
#include "Delay.h"

void key_init(void){
	GPIO_InitTypeDef GPIO_Initstruct;
	GPIO_Initstruct.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_Initstruct.GPIO_Pin = GPIO_Pin_6;
	GPIO_Initstruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_Initstruct);
}

uint8_t key_input(uint8_t key_num){
	if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_6)==0){
		Delay_ms(20);
		while(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_6)==0);
		key_num = ~key_num ;
	}
	return key_num ;
}

