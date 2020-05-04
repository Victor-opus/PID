#include "exti.h"
#include "led.h"
#include "key.h"
#include "delay.h"
#include "usart.h"
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEK Mini STM32������
//�ⲿ�ж� ��������			   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//�޸�����:2014/3/06  
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2009-2019
//All rights reserved									 
////////////////////////////////////////////////////////////////////////////////// 	  

//�ⲿ�ж�0�������
void EXTI0_IRQHandler(void)
{
	delay_ms(10);	//����
	if(WK_UP==1)	//WK_UP���� 
	{
		LED0=!LED0;
		LED1=!LED1;	
	}		 
	EXTI->PR=1<<0;  //���LINE0�ϵ��жϱ�־λ  
}
//�ⲿ�ж�9~5�������
void EXTI9_5_IRQHandler(void)
{			
	delay_ms(10);   //����			 
    if(KEY0==0)		//����0
	{
		LED0=!LED0;
	}
 	EXTI->PR=1<<5;     //���LINE5�ϵ��жϱ�־λ  
}
//�ⲿ�ж�15~10�������
void EXTI15_10_IRQHandler(void)
{			
	delay_ms(10);   //����			 
    if(KEY1==0)		//����1
	{
		LED1=!LED1;
	}
 	EXTI->PR=1<<15; //���LINE15�ϵ��жϱ�־λ  
}
//�ⲿ�жϳ�ʼ������
//��ʼ��PA0,PC5,PA15Ϊ�ж�����.
void EXTI_Init(void)
{
	KEY_Init();
	Ex_NVIC_Config(GPIO_A,0,RTIR); 		//�����ش���
	Ex_NVIC_Config(GPIO_C,5,FTIR);		//�½��ش���
	Ex_NVIC_Config(GPIO_A,15,FTIR);		//�½��ش���

	MY_NVIC_Init(2,2,EXTI0_IRQn,2);    	//��ռ2�������ȼ�2����2
	MY_NVIC_Init(2,1,EXTI9_5_IRQn,2);  	//��ռ2�������ȼ�1����2
	MY_NVIC_Init(2,0,EXTI15_10_IRQn,2);	//��ռ2�������ȼ�0����2	   
}












