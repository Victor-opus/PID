实验器材:
	MiniSTM32F103开发板V3版本
	
实验目的:
	学习彩色TFTLCD显示屏的使用
	
硬件资源:
	1,DS0(连接在PA8) 
	2,串口1(波特率:9600,PA9/PA10连接在板载USB转串口芯片CH340上面)
	3,ALIENTEK 2.8/3.5/4.3/7寸TFTLCD模块(通过GPIO驱动,连接关系见lcd.h) 
	
实验现象:
	本实验利用MiniSTM32开发板连接ALIENTEK TFTLCD模块(除CPLD版本7寸屏模块外,其余所有ALIENTEK的
	LCD模块都可以支持)，实现TFTLCD模块的显示，下载成功后，通过把LCD模块插入TFTLCD模块接口（靠右
	插），按下复位之后，就可以看到LCD模块不停的显示一些信息并不断切换底色。同时该实验会显示LCD驱
	动器的ID，并且会在串口打印（按复位一次，打印一次）。
	
注意事项:  
	1,4.3寸和7寸屏需要比较大电流,USB供电可能不足,请用外部电源供电(5V电源，接VOUT2即可).
	2,本例程在LCD_Init函数里面(在ILI93xx.c),用到了printf,如果不初始化串口1,将导致液晶无法显示!! 
	3,LCD模块在开发板的LCD接口上面，必须靠右插。 
	
	
					正点原子@ALIENTEK
					2014-3-07
					广州市星翼电子科技有限公司
					电话：020-38271790
					传真：020-36773971
					购买：http://shop62103354.taobao.com
					http://shop62057469.taobao.com
					公司网站：www.alientek.com
					技术论坛：www.openedv.com