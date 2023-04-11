#include "stm32f10x.h"                  // Device header
#include "usart3.h"
#include "delay.h"

u8 num;
u8 Date[4];
u8 flat;
u8 PassFlag;

void USART3_Config(void)
{
    //GPIO�˿�����
    GPIO_InitTypeDef GPIO_InitStructure;
    USART_InitTypeDef USART_InitStructure;
    NVIC_InitTypeDef NVIC_InitStructure;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	//ʹ��USART3��GPIOBʱ��
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3,ENABLE);

    //USART3_TX   GPIOB.10
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10; //PB10
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	//�����������
    GPIO_Init(GPIOB, &GPIO_InitStructure);//��ʼ��GPIOB.10

    //USART3_RX	  GPIOB.11��ʼ��
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;//PB11
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;//��������
    GPIO_Init(GPIOB, &GPIO_InitStructure);//��ʼ��GPIOB.11

    //Usart1 NVIC ����
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
    NVIC_InitStructure.NVIC_IRQChannel = USART3_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=2;//��ռ���ȼ�0
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;		//�����ȼ�0
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQͨ��ʹ��
    NVIC_Init(&NVIC_InitStructure);	//����ָ���Ĳ�����ʼ��VIC�Ĵ���

    //USART ��ʼ������

    USART_InitStructure.USART_BaudRate = 9600;//���ڲ�����
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;//�ֳ�Ϊ8λ���ݸ�ʽ
    USART_InitStructure.USART_StopBits = USART_StopBits_1;//һ��ֹͣλ
    USART_InitStructure.USART_Parity = USART_Parity_No;//����żУ��λ
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//��Ӳ������������
    USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	//�շ�ģʽ

    USART_Init(USART3, &USART_InitStructure); //��ʼ������3
    USART_ITConfig(USART3, USART_IT_RXNE, ENABLE);//�������ڽ����ж�
    USART_Cmd(USART3, ENABLE);                    //ʹ�ܴ���3
}
void PC_SendChar(uint8_t DataToSend)

{

    USART_SendData (USART3 ,DataToSend);

    while((USART3->SR&0x40)==0 );

}
void PC_SendString(uint8_t *str)
{

    while(*str)

    {

        PC_SendChar (*str);

        str++;

    }

}

/*����һ���ֽ�����*/
void UART3SendByte(unsigned char SendData)
{
    USART_SendData(USART3,SendData);
    while(USART_GetFlagStatus(USART3, USART_FLAG_TXE) == RESET);
}

/*����һ���ֽ�����*/
unsigned char UART3GetByte(unsigned char* GetData)
{
    if(USART_GetFlagStatus(USART3, USART_FLAG_RXNE) == RESET)
    {   return 0;//û���յ�����
    }
    *GetData = USART_ReceiveData(USART3);
    return 1;//�յ�����
}
/*����һ�����ݣ����Ϸ��ؽ��յ����������*/
void UART3Test(void)
{
    unsigned char i = 0;

    while(1)
    {
        while(UART3GetByte(&i))
        {
            USART_SendData(USART3,i);
        }
    }
}

void Receive_Data(int16_t data)
{
	static u8 state = 0;
	num = data;
	if(state == 0 && data != 0)
	{
		num = data;
		state = 1;
	}
	
	else if(state == 1 && data != 0 && PassFlag == 1)
	{
		Date[0] = data;
		state = 2;
	}
	
	else if(state == 2 && data != 0 && PassFlag == 1)
	{
		Date[1] = data;
		state = 3;
	}
	
	else if(state == 3 && data != 0 && PassFlag == 1)
	{
		Date[2] = data;
		state = 1;
	}
}

void USART3_IRQHandler(void)                	//����3�жϷ������
{
	u8 temp;
    if(USART_GetITStatus(USART3, USART_IT_RXNE) != RESET)
    {
        USART_ClearFlag(USART3,USART_FLAG_RXNE);
		flat = 1;
		temp = USART_ReceiveData(USART3);
		Receive_Data(temp);
    }
}
