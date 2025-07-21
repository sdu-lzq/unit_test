#include "stm32f10x.h"

void LED_init(void){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);//设置RCC
	GPIO_InitTypeDef GPIO_Initstruct;
	GPIO_Initstruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Initstruct.GPIO_Pin = GPIO_Pin_0;
	GPIO_Initstruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOA,&GPIO_Initstruct);
	GPIO_SetBits(GPIOA,GPIO_Pin_0);
}

void LED_on_off(uint8_t key_num){
	if(key_num == 0){
		GPIO_SetBits(GPIOA,GPIO_Pin_0);
	}
	else{
		GPIO_ResetBits(GPIOA,GPIO_Pin_0);
	}
}
