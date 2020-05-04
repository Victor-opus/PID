#include "sys.h"
#include "usart.h"		
#include "delay.h"	
#include "led.h"   
#include "lcd.h" 
#include "timer.h"
#include "key.h"
//ALIENTEK Mini STM32�����巶������11
//TFTLCD��ʾʵ��   
//����֧�֣�www.openedv.com
//������������ӿƼ����޹�˾ 

struct _pid{
	float SetSpeed;     //�����趨ֵ
	float ActualSpeed;  //����ʵ��ֵ
	float err;          //���嵱ǰƫ��ֵ  k
	float err_next;     //�����ϴ�ƫ��    k-1
	float err_last;     //�������ϴ�ƫ��  k-2
	float Kp, Ki, Kd;   //������������֡�΢��
}pid;


void PID_init(){
	pid.SetSpeed = 0.0;
	pid.ActualSpeed = 0.0;
	pid.err = 0.0;
	pid.err_last = 0.0;
	pid.err_next = 0.0;
	pid.Kp = 0.2;
	pid.Ki = 0.04;  //
	pid.Kd = 0.2;
}

float PID_realize(float speed){
	float incrementSpeed;
	pid.SetSpeed = speed;
	pid.err = pid.SetSpeed - pid.ActualSpeed;
  incrementSpeed = pid.Kp*(pid.err - pid.err_next) + pid.Ki*pid.err + pid.Kd*(pid.err - 2 * pid.err_next + pid.err_last);
	pid.ActualSpeed += incrementSpeed;
	pid.err_last = pid.err_next;
	pid.err_next = pid.err;
	return pid.ActualSpeed;
}


int main(void)
{	 				  					 
  int i;
	u8 lcd_id[12];			//���LCD ID�ַ���
  Stm32_Clock_Init(9);	//ϵͳʱ������
	uart_init(72,9600);	 	//���ڳ�ʼ��Ϊ9600
	delay_init(72);	   	 	//��ʱ��ʼ�� 
	LED_Init();		  		//��ʼ����LED���ӵ�Ӳ���ӿ�
 	LCD_Init();
	KEY_Init();
	PID_init();
	TIM1_PWM_Init(899,0);//����Ƶ��PWMƵ��=72000/(899+1)=80Khz 
	POINT_COLOR=RED; 
	sprintf((char*)lcd_id,"LCD ID:%04X",lcddev.id);//��LCD ID��ӡ��lcd_id���顣				 	
  	LCD_DrawLine(0,160,240,160);		
		LCD_ShowString(30,40,200,24,24,"PID TEST");	
		LCD_ShowString(30,70,200,16,16,"by victor");
		LCD_ShowString(30,90,200,16,16,"ALIENTEK MINI");
 		LCD_ShowString(30,110,200,16,16,lcd_id);		//��ʾLCD ID	      					 
	  
  
	
	
		for(i=0;i<240;i++)
		{
		LCD_Fast_DrawPoint(i,320-(int)PID_realize(160.0),BLACK);
		delay_ms(200);
			
		}
		while(1);
}











