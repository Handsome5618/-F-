#include "stm32f10x.h"                  // Device header
#include "usart1.h"
#include <stdarg.h>
#include "openmv.h"
#include "Motor.h"

void USART1_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure; //���ڶ˿����ýṹ�����
	USART_InitTypeDef USART_InitStructure;//���ڲ������ýṹ�����
	NVIC_InitTypeDef NVIC_InitStructure;//�����ж����ýṹ�����

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);	//�򿪴��ڸ���ʱ��
   	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);   //��PC�˿�ʱ��

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9; //PC.10
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//�趨IO�ڵ�����ٶ�Ϊ50MHz
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	//�����������
 	GPIO_Init(GPIOA, &GPIO_InitStructure);//��ʼ��GPIOC.10

  	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;//PC.11
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;//��������
  	GPIO_Init(GPIOA, &GPIO_InitStructure);//��ʼ��GPIOC.10  

  	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=2 ;//��ռ���ȼ�2
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;		//�����ȼ�3
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQͨ��ʹ��
	NVIC_Init(&NVIC_InitStructure);	//����ָ���Ĳ�����ʼ��VIC�Ĵ���
  
  	//USART ��ʼ������
	USART_InitStructure.USART_BaudRate = 115200;//���ڲ�����Ϊ115200
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;//�ֳ�Ϊ8λ���ݸ�ʽ
	USART_InitStructure.USART_StopBits = USART_StopBits_1;//һ��ֹͣλ
	USART_InitStructure.USART_Parity = USART_Parity_No;//����żУ��λ
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//��Ӳ������������
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	//�շ�ģʽʹ��
	USART_Init(USART1, &USART_InitStructure); //��ʼ������4
	
	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);//�������ڽ����ж�
	USART_Cmd(USART1, ENABLE);                    //ʹ�ܴ���4
   	USART_ClearFlag(USART1, USART_FLAG_TC);       //�崮��4���ͱ�־
}


void USART1_IRQHandler(void)			   //�����ж�
{
	u8 temp;
	if( USART_GetITStatus(USART1,USART_IT_RXNE)!=RESET )
	{
		USART_ClearITPendingBit(USART1,USART_IT_RXNE);//����жϱ�־
		temp = USART_ReceiveData(USART1);
		Openmv_Receive_Data(temp);//openmv���ݴ�����
	}
}
