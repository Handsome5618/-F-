#include "stm32f10x.h"                  // Device header

//���� 13
//�̵� 14
//��� 15

void LED_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); 
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
}

void openMVreaday(void)//��
{
	GPIO_SetBits(GPIOB,GPIO_Pin_13);
}

void Drug_Send(void)//��
{
	GPIO_SetBits(GPIOB,GPIO_Pin_15);
}

void Drug_Discharge(void)
{
	GPIO_ResetBits(GPIOB,GPIO_Pin_15);
}	

void Pharmacy_Arrive(void)//��
{
	GPIO_SetBits(GPIOB,GPIO_Pin_14);
}
