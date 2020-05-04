#include "sys.h"
#include "usart.h"		
#include "delay.h"	
#include "led.h"   
#include "lcd.h" 
#include "timer.h"
#include "key.h"
//ALIENTEK Mini STM32开发板范例代码11
//TFTLCD显示实验   
//技术支持：www.openedv.com
//广州市星翼电子科技有限公司 

struct _pid{
	float SetSpeed;     //定义设定值
	float ActualSpeed;  //定义实际值
	float err;          //定义当前偏差值  k
	float err_next;     //定义上次偏差    k-1
	float err_last;     //定义上上次偏差  k-2
	float Kp, Ki, Kd;   //定义比例、积分、微分
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
	u8 lcd_id[12];			//存放LCD ID字符串
  Stm32_Clock_Init(9);	//系统时钟设置
	uart_init(72,9600);	 	//串口初始化为9600
	delay_init(72);	   	 	//延时初始化 
	LED_Init();		  		//初始化与LED连接的硬件接口
 	LCD_Init();
	KEY_Init();
	PID_init();
	TIM1_PWM_Init(899,0);//不分频。PWM频率=72000/(899+1)=80Khz 
	POINT_COLOR=RED; 
	sprintf((char*)lcd_id,"LCD ID:%04X",lcddev.id);//将LCD ID打印到lcd_id数组。				 	
  	LCD_DrawLine(0,160,240,160);		
		LCD_ShowString(30,40,200,24,24,"PID TEST");	
		LCD_ShowString(30,70,200,16,16,"by victor");
		LCD_ShowString(30,90,200,16,16,"ALIENTEK MINI");
 		LCD_ShowString(30,110,200,16,16,lcd_id);		//显示LCD ID	      					 
	  
  
	
	
		for(i=0;i<240;i++)
		{
		LCD_Fast_DrawPoint(i,320-(int)PID_realize(160.0),BLACK);
		delay_ms(200);
			
		}
		while(1);
}











