#ifndef __KEY_H
#define __KEY_H	 
#include "sys.h"
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEK Mini STM32������
//�������� ��������		   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//�޸�����:2014/3/06
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2009-2019
//All rights reserved									   
//////////////////////////////////////////////////////////////////////////////////	 

#define KEY0_PRES	1		//KEY0����
#define KEY1_PRES	2		//KEY1����
#define WKUP_PRES	3		//WK_UP����

#define KEY0  PCin(5)   	//PC5
#define KEY1  PAin(15)	 	//PA15 
#define WK_UP PAin(0)	 	//PA0  WK_UP
	 
void KEY_Init(void);		//IO��ʼ��
u8 KEY_Scan(u8 mode);		//����ɨ�躯��
#endif
