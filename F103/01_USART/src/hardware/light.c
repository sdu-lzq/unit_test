#include "stm32f10x.h"

void light_init(void){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);//设置RCC
	GPIO_InitTypeDef GPIO_Initstruct;
	GPIO_Initstruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Initstruct.GPIO_Pin = GPIO_Pin_13;
	GPIO_Initstruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOB,&GPIO_Initstruct);
}

uint8_t light_input(void){
	return GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_13);
}

