#include "stm32f10x.h" // Device header
#include "Motor.h"
#include "Drug.h"
#include "Delay.h"
#include "usart3.h"

extern u8 RubbishFlat;
u8 banana = 0;

void Tracking(void)
{
		if(Left_Get()==1)
		{
			Motor_2_Prun();
			Motor_1_Nrun();
			delay_ms(10);
		}
		if(Right_Get()==1)
		{
			Motor_1_Prun();
			Motor_2_Nrun();
			delay_ms(10);
		}
}

void Left1_Tracking(void)
{
	Motor_Prun();
	if(Left_Get()==1&&Right_Get()==1&&banana==3)//���
		{
			Motor_1_Prun();
			Motor_2_Nrun();
			delay_ms(970);
			Motor_Stop();
			banana = 4;
			RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,DISABLE);
			PC_SendString((u8*)"\n\n�ѻص����\n\n");
		}
	if(Left_Get()==1&&Right_Get()==1&&banana==2)//�س̵�һ��ʮ��·��
		{
			banana = 3;
			Motor_Prun();
			delay_ms(270);
			Motor_2_Prun();
			Motor_1_Nrun();
			delay_ms(500);
		}
	if(Left_Get()==1&&Right_Get()==1&&banana==1)//�յ�
	{
		Motor_Stop();
		PC_SendString((u8*)"\n\n�ѵ���ָ���ص�\n");
		PC_SendString((u8*)"�ȴ�����ȡ��\n\n");
		while(RubbishFlat == 1)
		{
			delay_ms(1);
		}
		PC_SendString((u8*)"\n\n��⵽������ȡ��\n");
		PC_SendString((u8*)"���ڻس�\n");
		Motor_1_Prun();
		Motor_2_Nrun();
		delay_ms(1050);
		banana = 2;
	}
		if(Left_Get()==1&&Right_Get()==1)//ȥ�̵�һ��ʮ��·��
		{
			banana = 1;
			Motor_Prun();
			delay_ms(200);
			Motor_1_Prun();
			Motor_2_Nrun();
			delay_ms(500);
		}
		if(Left_Get()==1)
		{
			Motor_2_Prun();
			Motor_1_Nrun();
			delay_ms(10);
		}
		if(Right_Get()==1)
		{
			Motor_1_Prun();
			Motor_2_Nrun();
			delay_ms(10);
		}
}

void Left2_Tracking(void)
{
		if(Left_Get()==1&&Right_Get()==1&&banana==5)//�ص����
		{
			Motor_Stop();
			RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,DISABLE);
		}
		if(Left_Get()==1&&Right_Get()==1&&banana==4)//�س̶��ڸ�ʮ��·��
		{
			banana = 5;
			Motor_Prun();
			delay_ms(130);
		}
		if(Left_Get()==1&&Right_Get()==1&&banana==3)//�س̵�һ��ʮ��·��
		{
			banana = 4;
			Motor_Prun();
			delay_ms(270);
			Motor_2_Prun();
			Motor_1_Nrun();
			delay_ms(480);
		}
		if(Left_Get()==1&&Right_Get()==1&&banana==2)//�����յ�
		{
			Motor_Stop();
			delay_ms(500);delay_ms(500);
			banana = 3;
			Motor_1_Prun();
			Motor_2_Nrun();
			delay_ms(870);
		}
		if(Left_Get()==1&&Right_Get()==1&&banana==1)//ȥ�̵ڶ���ʮ��·��
		{
			banana = 2;
			Motor_Prun();
			delay_ms(200);
			Motor_1_Prun();
			Motor_2_Nrun();
			delay_ms(400);
		}
		if(Left_Get()==1&&Right_Get()==1)//ȥ�̵�һ��ʮ��·��
		{
			banana = 1;
			Motor_Prun();
			delay_ms(200);
		}
		if(Left_Get()==1)
		{
			Motor_2_Prun();
			Motor_1_Nrun();
			delay_ms(10);
		}
		if(Right_Get()==1)
		{
			Motor_1_Prun();
			Motor_2_Nrun();
			delay_ms(10);
		}
}

void Right1_Tracking(void)
{
	if(Left_Get()==1&&Right_Get()==1&&banana==3)//���
		{
			Motor_Stop();
			RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,DISABLE);
		}
	if(Left_Get()==1&&Right_Get()==1&&banana==2)//�س̵�һ��ʮ��·��
		{
			banana = 3;
			Motor_Prun();
			delay_ms(270);
			Motor_1_Prun();
			Motor_2_Nrun();
			delay_ms(480);
		}
	if(Left_Get()==1&&Right_Get()==1&&banana==1)//�յ�
	{
		Motor_Stop();
		delay_ms(500);delay_ms(500);
		Motor_1_Prun();
		Motor_2_Nrun();
		delay_ms(870);
		banana = 2;
	}
		if(Left_Get()==1&&Right_Get()==1)//ȥ�̵�һ��ʮ��·��
		{
			banana = 1;
			Motor_Prun();
			delay_ms(200);
			Motor_2_Prun();
			Motor_1_Nrun();
			delay_ms(400);
		}
		if(Left_Get()==1)
		{
			Motor_2_Prun();
			Motor_1_Nrun();
			delay_ms(10);
		}
		if(Right_Get()==1)
		{
			Motor_1_Prun();
			Motor_2_Nrun();
			delay_ms(10);
		}
}

void Right2_Tracking(void)
{
		Motor_Prun();
		if(Left_Get()==1&&Right_Get()==1&&banana==5)//�ص����
		{
			Motor_1_Prun();
			Motor_2_Nrun();
			delay_ms(970);
			Motor_Stop();
			banana = 6;
			RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,DISABLE);
			PC_SendString((u8*)"\n\n�ѻص����\n\n");
		}
		if(Left_Get()==1&&Right_Get()==1&&banana==4)//�س̶��ڸ�ʮ��·��
		{
			banana = 5;
			Motor_Prun();
			delay_ms(130);
		}
		if(Left_Get()==1&&Right_Get()==1&&banana==3)//�س̵�һ��ʮ��·��
		{
			banana = 4;
			Motor_Prun();
			delay_ms(270);
			Motor_1_Prun();
			Motor_2_Nrun();
			delay_ms(500);
		}
		if(Left_Get()==1&&Right_Get()==1&&banana==2)//�����յ�
		{
			Motor_Stop();
			PC_SendString((u8*)"\n\n�ѵ���ָ���ص�\n");
			PC_SendString((u8*)"�ȴ�����ȡ��\n\n");
			while(RubbishFlat)
		{
			delay_ms(1);
		}
			PC_SendString((u8*)"\n\n��⵽������ȡ��\n");
			PC_SendString((u8*)"���ڻس�\n");
			banana = 3;
			Motor_1_Prun();
			Motor_2_Nrun();
			delay_ms(1050);
		}
		if(Left_Get()==1&&Right_Get()==1&&banana==1)//ȥ�̵ڶ���ʮ��·��
		{
			banana = 2;
			Motor_Prun();
			delay_ms(200);
			Motor_2_Prun();
			Motor_1_Nrun();
			delay_ms(500);
		}
		if(Left_Get()==1&&Right_Get()==1)//ȥ�̵�һ��ʮ��·��
		{
			banana = 1;
			Motor_Prun();
			delay_ms(200);
		}
		if(Left_Get()==1)
		{
			Motor_2_Prun();
			Motor_1_Nrun();
			delay_ms(10);
		}
		if(Right_Get()==1)
		{
			Motor_1_Prun();
			Motor_2_Nrun();
			delay_ms(10);
		}
}
