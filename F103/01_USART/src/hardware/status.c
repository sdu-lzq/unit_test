#include "stm32f10x.h"


void GP13_init(void){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);//设置RCC
	GPIO_InitTypeDef GPIO_Initstruct;
	GPIO_Initstruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Initstruct.GPIO_Pin = GPIO_Pin_13;
	GPIO_Initstruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOC,&GPIO_Initstruct);
}


void GP13_on(uint8_t num){
	if(num == 1) GPIO_ResetBits(GPIOC,GPIO_Pin_13);
	else GPIO_SetBits(GPIOC,GPIO_Pin_13);
}
