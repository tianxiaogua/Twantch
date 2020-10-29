
#include "stdio.h"

#include "app.h"

#include "display.h"

#include "main.h"
#include "adc.h"
#include "dma.h"
#include "i2c.h"

#include "spi.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

#include "contro.h"

#include "display.h"

#include "lcd.h"
#include "lcd_init.h"
#include "apppicture.h"

#include "mpu6050Driver.h"


uint8_t clock_time_hour[7] = {60,60,60,60,60,60};

uint8_t clock_time_min[7] = {60,60,60,60,60,60};

uint8_t clock_Data[7];


/*******************************************
* @function: 	游戏
* @input:			无
* @return:		无
* @author:		田小花
* @time:			2020.10.25
*******************************************/
int X_cricle ,Y_cricle;

int X_cricle_his ,Y_cricle_his;

void APP_GAME(void)
{
	unsigned char switch_value;
	
	float pitch,roll,yaw; 		//欧拉角
	
	float Jpitch,Jroll,Jyaw; 		//欧拉角//校准值

	begin:
	
	X_cricle = LCD_W/2;
	
	Y_cricle = LCD_H/2;
	
	LCD_Fill(0,0,LCD_W,LCD_H,BLACK); //
	
	Draw_Circle(	X_cricle,	Y_cricle,	5,	RED	);
	
	Draw_Circle(	2,	18,	5,	RED	);
	
	Draw_Circle(	67,	1,	5,	RED	);
	
	Draw_Circle(	23,	96,	5,	RED	);
	
	Draw_Circle(	76,	24,	5,	RED	);
	
	Draw_Circle(	19,	200,	5,	RED	);
	
	Draw_Circle(	90,	210,	5,	RED	);
	
	Draw_Circle(	100,	18,	5,	RED	);

	//HAL_Delay(200); //等待
	
	printf("游戏初始化\r\n");
	
	/*重新对陀螺仪进行校准*/
	while(1)
	{
		if(	mpu_dmp_get_data(	&pitch,	&roll,	&yaw	)	==	0	)
		{
			printf("%.2f %.2f %.2f \r\n",pitch,roll,yaw);
			
			Jpitch = pitch; //对获取到的角度进行校准
			
			Jroll = roll;
			
			Jyaw = yaw;
			
			printf("游戏初始化完成\r\n");
			
			break;
		}
	}
	
	printf("进入了游戏\r\n");
	
	/*LCD_W 135	 LCD_H 240*/
	while(1)
	{
		switch_value = Get_Key_value(0);
		
		if(	switch_value	 == Button_1_pressed	||	switch_value	 == Button_3_pressed	)	goto begin;
		
		if(	switch_value	 == Button_2_pressed	)	break;
		
		if(	mpu_dmp_get_data(	&pitch,	&roll,	&yaw	)	==	0	)
		{
			printf("%.2f %.2f %.2f \r\n",pitch,roll,yaw);
			
			pitch = pitch	-	Jpitch	;
			
			roll = roll	-	Jroll	;
			
			yaw = yaw	-	Jyaw	;
		}
		
		
		Draw_Circle(	X_cricle_his,	Y_cricle_his,	10,	BLACK	);

		if(	pitch	>	8	)
		{
			Y_cricle ++ ;
		}
		if(pitch	<	-8	)
		{
			Y_cricle-- ;
		}
		
		if(	roll	>	8	)
		{
			X_cricle-- ;
		}
		if(	roll	<	-8	)	
		{
			X_cricle ++ ;
		}
		
		if(	X_cricle	>	LCD_W	)
		{
			X_cricle	=	LCD_W;
		}
		if(	X_cricle	<	0	)
		{
			X_cricle	=	0;
		}
		if(	Y_cricle	>	LCD_H	)
		{
			Y_cricle	=	LCD_H;
		}
		if(	Y_cricle	<	0	)
		{
			Y_cricle	=	0;
		}
		
		Draw_Circle(X_cricle,Y_cricle,10,GREEN);

		HAL_Delay(5);
		
		X_cricle_his = X_cricle;
		
		Y_cricle_his = Y_cricle;
		
	}//游戏主循环结束
	
	printf("退出了游戏\r\n");
	
}


/*******************************************
* @function: 	闹钟的功能
* @input:			无
* @return:		无
* @author:		田小花
* @time:			2020.10.3
*******************************************/

void clock_begin_display(void)
{
	LCD_Fill(0,	0,	LCD_W,	LCD_H,	WHITE); //显示界面成白色刷新
	
	LCD_Fill(0,	0,	LCD_W,	30,	WHITE); //显示界面成灰色刷新
		
	LCD_Fill(0,	30,	LCD_W,	31,	BLACK); //画线		
	
	LCD_Fill(0,	60,	LCD_W,	61,	BLACK); //画线			
	
	LCD_Fill(0,	90,	LCD_W,	91,	BLACK); //画线			
	
	LCD_Fill(0,	120,	LCD_W,	121,	BLACK); //画线			
	
	LCD_Fill(0,	150,	LCD_W,	151,	BLACK); //画线			
	
	LCD_Fill(0,	180,	LCD_W,	181,	BLACK); //画线			
	
	LCD_Fill(0,	210,	LCD_W,	211,	BLACK); //画线

	LCD_Fill(0,		61,	LCD_W,	90,	WHITE); //显示界面成灰色刷新
	
	
	//LCD_Fill(0,		0,	LCD_W,	30,	LGRAY); //显示界面成灰色刷新
		
	LCD_ShowChinese(0,	3,	"返回",	BLACK,	WHITE,24,0);
	
//	LCD_Fill(0,		31,	LCD_W,	60,	WHITE); //显示界面成灰色刷新	
	
	LCD_ShowChinese(0,		33,	"新建",	BLACK,	WHITE,24,0);
		
	//显示第一个闹钟
	if(clock_time_hour[0] != 60)
	{
		LCD_ShowFloatNum1(5,	68,	clock_time_hour[0]+clock_time_min[0]*0.01,	4,	BLACK,	WHITE,	16);
		
		switch(clock_Data[0])
		{
			case 0:	LCD_ShowChinese(80,		63,	"每天",	BLACK,	WHITE,	24,0);	break;//显示那一天
			case 1:	LCD_ShowChinese(80,		63,	"周一",	BLACK,	WHITE,	24,0);  break;//显示那一天
			case 2:	LCD_ShowChinese(80,		63,	"周二",	BLACK,	WHITE,	24,0);  break;//显示那一天
			case 3:	LCD_ShowChinese(80,		63,	"周三",	BLACK,	WHITE,	24,0);  break;//显示那一天
			case 4:	LCD_ShowChinese(80,		63,	"周四",	BLACK,	WHITE,	24,0);  break;//显示那一天
			case 5:	LCD_ShowChinese(80,		63,	"周五",	BLACK,	WHITE,	24,0);  break;//显示那一天
			case 6:	LCD_ShowChinese(80,		63,	"周六",	BLACK,	WHITE,	24,0);  break;//显示那一天
			case 7:	LCD_ShowChinese(80,		63,	"周日",	BLACK,	WHITE,	24,0);  break;//显示那一天
		}
	}	
	
	//显示第2个闹钟
	if(clock_time_hour[1] != 60)
	{
		LCD_ShowFloatNum1(5,	98,	clock_time_hour[1]+clock_time_min[1]*0.01,	4,	BLACK,	WHITE,	16);
		switch(clock_Data[1])
		{
			case 0:	LCD_ShowChinese(80,		93,	"每天",	BLACK,	WHITE,	24,0);	break;//显示那一天
			case 1:	LCD_ShowChinese(80,		93,	"周一",	BLACK,	WHITE,	24,0);  break;//显示那一天
			case 2:	LCD_ShowChinese(80,		93,	"周二",	BLACK,	WHITE,	24,0);  break;//显示那一天
			case 3:	LCD_ShowChinese(80,		93,	"周三",	BLACK,	WHITE,	24,0);  break;//显示那一天
			case 4:	LCD_ShowChinese(80,		93,	"周四",	BLACK,	WHITE,	24,0);  break;//显示那一天
			case 5:	LCD_ShowChinese(80,		93,	"周五",	BLACK,	WHITE,	24,0);  break;//显示那一天
			case 6:	LCD_ShowChinese(80,		93,	"周六",	BLACK,	WHITE,	24,0);  break;//显示那一天
			case 7:	LCD_ShowChinese(80,		93,	"周日",	BLACK,	WHITE,	24,0);  break;//显示那一天
		}
	}
	
	
	//显示第3个闹钟
	if(clock_time_hour[2] != 60)
	{
		LCD_ShowFloatNum1(5,	128,	clock_time_hour[2]+clock_time_min[2]*0.01,	4,	BLACK,	WHITE,	16);
		switch(clock_Data[2])
		{
			case 0:	LCD_ShowChinese(80,		123,	"每天",	BLACK,	WHITE,	24,0);	break;//显示那一天
			case 1:	LCD_ShowChinese(80,		123,	"周一",	BLACK,	WHITE,	24,0);  break;//显示那一天
			case 2:	LCD_ShowChinese(80,		123,	"周二",	BLACK,	WHITE,	24,0);  break;//显示那一天
			case 3:	LCD_ShowChinese(80,		123,	"周三",	BLACK,	WHITE,	24,0);  break;//显示那一天
			case 4:	LCD_ShowChinese(80,		123,	"周四",	BLACK,	WHITE,	24,0);  break;//显示那一天
			case 5:	LCD_ShowChinese(80,		123,	"周五",	BLACK,	WHITE,	24,0);  break;//显示那一天
			case 6:	LCD_ShowChinese(80,		123,	"周六",	BLACK,	WHITE,	24,0);  break;//显示那一天
			case 7:	LCD_ShowChinese(80,		123,	"周日",	BLACK,	WHITE,	24,0);  break;//显示那一天
		}
	}
	
	
	//显示第4个闹钟
	if(clock_time_hour[3] != 60)
	{
		LCD_ShowFloatNum1(5,	158,	clock_time_hour[2]+clock_time_min[2]*0.01,	4,	BLACK,	WHITE,	16);
		switch(clock_Data[2])
		{
			case 0:	LCD_ShowChinese(80,		153,	"每天",	BLACK,	WHITE,	24,0);	break;//显示那一天
			case 1:	LCD_ShowChinese(80,		153,	"周一",	BLACK,	WHITE,	24,0);  break;//显示那一天
			case 2:	LCD_ShowChinese(80,		153,	"周二",	BLACK,	WHITE,	24,0);  break;//显示那一天
			case 3:	LCD_ShowChinese(80,		153,	"周三",	BLACK,	WHITE,	24,0);  break;//显示那一天
			case 4:	LCD_ShowChinese(80,		153,	"周四",	BLACK,	WHITE,	24,0);  break;//显示那一天
			case 5:	LCD_ShowChinese(80,		153,	"周五",	BLACK,	WHITE,	24,0);  break;//显示那一天
			case 6:	LCD_ShowChinese(80,		153,	"周六",	BLACK,	WHITE,	24,0);  break;//显示那一天
			case 7:	LCD_ShowChinese(80,		153,	"周日",	BLACK,	WHITE,	24,0);  break;//显示那一天
		}
	}
	
	
	//显示第5个闹钟
	if(clock_time_hour[4] != 60)
	{
		LCD_ShowFloatNum1(5,	188,	clock_time_hour[4]+clock_time_min[4]*0.01,	4,	BLACK,	WHITE,	16);
		switch(clock_Data[4])
		{
			case 0:	LCD_ShowChinese(80,		183,	"每天",	BLACK,	WHITE,	24,0);	break;//显示那一天
			case 1:	LCD_ShowChinese(80,		183,	"周一",	BLACK,	WHITE,	24,0);  break;//显示那一天
			case 2:	LCD_ShowChinese(80,		183,	"周二",	BLACK,	WHITE,	24,0);  break;//显示那一天
			case 3:	LCD_ShowChinese(80,		183,	"周三",	BLACK,	WHITE,	24,0);  break;//显示那一天
			case 4:	LCD_ShowChinese(80,		183,	"周四",	BLACK,	WHITE,	24,0);  break;//显示那一天
			case 5:	LCD_ShowChinese(80,		183,	"周五",	BLACK,	WHITE,	24,0);  break;//显示那一天
			case 6:	LCD_ShowChinese(80,		183,	"周六",	BLACK,	WHITE,	24,0);  break;//显示那一天
			case 7:	LCD_ShowChinese(80,		183,	"周日",	BLACK,	WHITE,	24,0);  break;//显示那一天
		}
	}
	//显示第6个闹钟
	if(clock_time_hour[5] != 60)
	{
		LCD_ShowFloatNum1(5,	218,	clock_time_hour[5]+clock_time_min[5]*0.01,	4,	BLACK,	WHITE,	16);
		switch(clock_Data[5])
		{
			case 0:	LCD_ShowChinese(80,		213,	"每天",	BLACK,	WHITE,	24,0);	break;//显示那一天
			case 1:	LCD_ShowChinese(80,		213,	"周一",	BLACK,	WHITE,	24,0);  break;//显示那一天
			case 2:	LCD_ShowChinese(80,		213,	"周二",	BLACK,	WHITE,	24,0);  break;//显示那一天
			case 3:	LCD_ShowChinese(80,		213,	"周三",	BLACK,	WHITE,	24,0);  break;//显示那一天
			case 4:	LCD_ShowChinese(80,		213,	"周四",	BLACK,	WHITE,	24,0);  break;//显示那一天
			case 5:	LCD_ShowChinese(80,		213,	"周五",	BLACK,	WHITE,	24,0);  break;//显示那一天
			case 6:	LCD_ShowChinese(80,		213,	"周六",	BLACK,	WHITE,	24,0);  break;//显示那一天
			case 7:	LCD_ShowChinese(80,		213,	"周日",	BLACK,	WHITE,	24,0);  break;//显示那一天
		}
	}
}


/*******************************************
* @function: 	闹钟的功能
* @input:			无
* @return:		无
* @author:		田小花
* @time:			2020.10.3
*******************************************/

void set_clock_fun(unsigned char i)
{
	unsigned char switch_value = 0;
	
	unsigned char Number_of_cycles_ = 1;
	
	unsigned char flag_ = 0;
	
	int value_1 = 6; //时钟数字
	
	int value_2 = 40; //分钟数字
	
	int value_3 = 0; //天数 0代表每天 。7代表周日
	
	if(clock_time_hour[i] != 60)
	{
		value_1 = clock_time_hour[i];
		
		value_2 = clock_time_min[i];

		value_3 = clock_Data[i];
	}
	
	LCD_Fill(0,		0,		LCD_W,	LCD_H,	WHITE); //显示界面成白色刷新
			
	LCD_ShowIntNum1(5,	65,	6,	2,	BLACK,	LGRAY,	32); //显示时钟数
				
	LCD_ShowChinese(37,		65,	"时",	BLACK,	WHITE,	32,0); //显示时
	
	LCD_ShowIntNum1(69,	65,	40,	2,	BLACK,	WHITE,	32); //显示分钟
	
	LCD_ShowChinese(101,		65,	"分",	BLACK,	WHITE,	32,0); //显示分
	
	LCD_ShowChinese(37,		110,	"每天",	BLACK,	WHITE,	32,0); //显示那一天
	
	LCD_ShowChinese(5,		210,	"确定",	BLACK,	WHITE,	24,0); //显示确定
	
	LCD_ShowChinese(85,		210,	"删除",	BLACK,	WHITE,	24,0); //显示删除
	
	while(1)
	{
		switch_value = Get_Key_value(1); //检测按键
		
		if(switch_value == Button_1_pressed)// 上下调节选择时间或者日期
		{
			Number_of_cycles_--;
			
			flag_ = 1;
			
			if(Number_of_cycles_<1)
			{
				Number_of_cycles_ = 5;
			}
		}
		
		if(switch_value == Button_3_pressed)// // 上下调节选择时间或者日期
		{
			Number_of_cycles_++;
			
			flag_ = 1;
			
			if(Number_of_cycles_>5)
			{
				Number_of_cycles_ = 1;
			}
		}

		
		/*************************************
		
		显示部分，把时间日期和确认删除分开进行显示，每次按键按下才进行刷新
		
		*****************************************/
		if(Number_of_cycles_ == 1 && flag_ == 1)
		{
			flag_ = 0;
			
			LCD_ShowChinese(85,		210,	"删除",	BLACK,	WHITE,	24,0); //显示删除
			
			LCD_ShowIntNum1(5,	65,	value_1,	2,	BLACK,	LGRAY,	32); //显示时钟数
			
			LCD_ShowIntNum1(69,	65,	value_2,	2,	BLACK,	WHITE,	32); //显示分钟
		}
		if(Number_of_cycles_ == 2 && flag_ == 1)
		{
			flag_ = 0;
			
			LCD_ShowIntNum1(5,	65,	value_1,	2,	BLACK,	WHITE,	32); //显示时钟数
			
			LCD_ShowIntNum1(69,	65,	value_2,	2,	BLACK,	LGRAY,	32); //显示分钟
			
			switch(value_3)
			{
				case 0:	LCD_ShowChinese(37,		110,	"每天",	BLACK,	WHITE,	32,0);  break;//显示那一天
				case 1:	LCD_ShowChinese(37,		110,	"周一",	BLACK,	WHITE,	32,0);  break;//显示那一天
				case 2:	LCD_ShowChinese(37,		110,	"周二",	BLACK,	WHITE,	32,0);  break;//显示那一天
				case 3:	LCD_ShowChinese(37,		110,	"周三",	BLACK,	WHITE,	32,0);  break;//显示那一天
				case 4:	LCD_ShowChinese(37,		110,	"周四",	BLACK,	WHITE,	32,0);  break;//显示那一天
				case 5:	LCD_ShowChinese(37,		110,	"周五",	BLACK,	WHITE,	32,0);  break;//显示那一天
				case 6:	LCD_ShowChinese(37,		110,	"周六",	BLACK,	WHITE,	32,0);  break;//显示那一天
				case 7:	LCD_ShowChinese(37,		110,	"周日",	BLACK,	WHITE,	32,0);  break;//显示那一天
			}
		}
		if(Number_of_cycles_ == 3 && flag_ == 1)
		{
			flag_ = 0;
			
			LCD_ShowIntNum1(69,	65,	value_2,	2,	BLACK,	WHITE,	32); //显示分钟
			
			switch(value_3)
			{
				case 0:	LCD_ShowChinese(37,		110,	"每天",	BLACK,	LGRAY,	32,0);  break;//显示那一天
				case 1:	LCD_ShowChinese(37,		110,	"周一",	BLACK,	LGRAY,	32,0);  break;//显示那一天
				case 2:	LCD_ShowChinese(37,		110,	"周二",	BLACK,	LGRAY,	32,0);  break;//显示那一天
				case 3:	LCD_ShowChinese(37,		110,	"周三",	BLACK,	LGRAY,	32,0);  break;//显示那一天
				case 4:	LCD_ShowChinese(37,		110,	"周四",	BLACK,	LGRAY,	32,0);  break;//显示那一天
				case 5:	LCD_ShowChinese(37,		110,	"周五",	BLACK,	LGRAY,	32,0);  break;//显示那一天
				case 6:	LCD_ShowChinese(37,		110,	"周六",	BLACK,	LGRAY,	32,0);  break;//显示那一天
				case 7:	LCD_ShowChinese(37,		110,	"周日",	BLACK,	LGRAY,	32,0);  break;//显示那一天
			}
			LCD_ShowChinese(5,		210,	"确定",	BLACK,	WHITE,	24,0); //显示确定
		}
		if(Number_of_cycles_ == 4 && flag_ == 1)
		{
			flag_ = 0;
			
			switch(value_3)
			{
				case 0:	LCD_ShowChinese(37,		110,	"每天",	BLACK,	WHITE,	32,0);  break;//显示那一天
				case 1:	LCD_ShowChinese(37,		110,	"周一",	BLACK,	WHITE,	32,0);  break;//显示那一天
				case 2:	LCD_ShowChinese(37,		110,	"周二",	BLACK,	WHITE,	32,0);  break;//显示那一天
				case 3:	LCD_ShowChinese(37,		110,	"周三",	BLACK,	WHITE,	32,0);  break;//显示那一天
				case 4:	LCD_ShowChinese(37,		110,	"周四",	BLACK,	WHITE,	32,0);  break;//显示那一天
				case 5:	LCD_ShowChinese(37,		110,	"周五",	BLACK,	WHITE,	32,0);  break;//显示那一天
				case 6:	LCD_ShowChinese(37,		110,	"周六",	BLACK,	WHITE,	32,0);  break;//显示那一天
				case 7:	LCD_ShowChinese(37,		110,	"周日",	BLACK,	WHITE,	32,0);  break;//显示那一天
			}
			
			LCD_ShowChinese(5,		210,	"确定",	BLACK,	LGRAY,	24,0); //显示确定
			
			LCD_ShowChinese(85,		210,	"删除",	BLACK,	WHITE,	24,0); //显示删除
		}
		if(Number_of_cycles_ == 5 && flag_ == 1)
		{
			flag_ = 0;
			
			LCD_ShowChinese(5,		210,	"确定",	BLACK,	WHITE,	24,0); //显示确定
			
			LCD_ShowChinese(85,		210,	"删除",	BLACK,	LGRAY,	24,0); //显示删除
			
			LCD_ShowIntNum1(5,	65,	value_1,	2,	BLACK,	WHITE,	32); //显示时钟数
		}
		
		
		//对功能进行操作：
		if(Number_of_cycles_ == 1 && switch_value == Button_2_pressed) //对小时调节的功能进行操作
		{
			while(1)
			{
				switch_value = Get_Key_value(1);
				
				LCD_ShowIntNum1(5,	65,	value_1,	2,	BLACK,	LGRAYBLUE,	32); //显示时钟数 //选中以后变成灰蓝色
				
				if(switch_value == Button_1_pressed)
				{								
					value_1 --;									
				}
				if(switch_value == Button_3_pressed)
				{						
					value_1 ++;
				}
				if(value_1 < 0)
				{
					value_1 = 23;
				}
				if(value_1 > 23)
				{
					value_1 = 0;
				}
				if(switch_value == Button_2_pressed)
				{
					LCD_ShowIntNum1(5,	65,	value_1,	2,	BLACK,	LGRAY,	32); //显示时钟数 //选中以后变成灰蓝色 //把选中之后的颜色改变回来
					
					break;
				}
			}
		}	
		if(Number_of_cycles_ == 2 && switch_value == Button_2_pressed) //对分钟调节的功能进行操作
		{
			while(1)
			{
				switch_value = Get_Key_value(1);
				
				LCD_ShowIntNum1(69,	65,	value_2,	2,	BLACK,	LGRAYBLUE,	32); //显示分钟 //选中以后变成灰蓝色
				
				if(switch_value == Button_1_pressed)
				{								
					value_2 --;									
				}
				if(switch_value == Button_3_pressed)
				{						
					value_2 ++;
				}
				if(value_2 < 0)
				{
					value_2 = 59;
				}
				if(value_2 > 59)
				{
					value_2 = 0;
				}
				if(switch_value == Button_2_pressed)
				{
					LCD_ShowIntNum1(69,	65,	value_2,	2,	BLACK,	LGRAY,	32);  //显示时钟数 //选中以后变成灰蓝色 //把选中之后的颜色改变回来
					
					break;
				}
			}
		}	
		if(Number_of_cycles_ == 3 && switch_value == Button_2_pressed) //对天数调节的功能进行操作
		{
			while(1)
			{
				switch_value = Get_Key_value(1);
				
				switch(value_3)
				{
					case 0:	LCD_ShowChinese(37,		110,	"每天",	BLACK,	LGRAYBLUE,	32,0);  break;//显示那一天
					case 1:	LCD_ShowChinese(37,		110,	"周一",	BLACK,	LGRAYBLUE,	32,0);  break;//显示那一天
					case 2:	LCD_ShowChinese(37,		110,	"周二",	BLACK,	LGRAYBLUE,	32,0);  break;//显示那一天
					case 3:	LCD_ShowChinese(37,		110,	"周三",	BLACK,	LGRAYBLUE,	32,0);  break;//显示那一天
					case 4:	LCD_ShowChinese(37,		110,	"周四",	BLACK,	LGRAYBLUE,	32,0);  break;//显示那一天
					case 5:	LCD_ShowChinese(37,		110,	"周五",	BLACK,	LGRAYBLUE,	32,0);  break;//显示那一天
					case 6:	LCD_ShowChinese(37,		110,	"周六",	BLACK,	LGRAYBLUE,	32,0);  break;//显示那一天
					case 7:	LCD_ShowChinese(37,		110,	"周日",	BLACK,	LGRAYBLUE,	32,0);  break;//显示那一天
				}
				
				if(switch_value == Button_1_pressed)
				{								
					value_3 --;									
				}
				if(switch_value == Button_3_pressed)
				{						
					value_3 ++;
				}
				if(value_3 < 0)
				{
					value_3 = 7;
				}
				if(value_3 > 7)
				{
					value_3 = 0;
				}
				if(switch_value == Button_2_pressed)
				{
					switch(value_3)
					{
						case 0:	LCD_ShowChinese(37,		110,	"每天",	BLACK,	LGRAY,	32,0);  break;//显示那一天
						case 1:	LCD_ShowChinese(37,		110,	"周一",	BLACK,	LGRAY,	32,0);  break;//显示那一天
						case 2:	LCD_ShowChinese(37,		110,	"周二",	BLACK,	LGRAY,	32,0);  break;//显示那一天
						case 3:	LCD_ShowChinese(37,		110,	"周三",	BLACK,	LGRAY,	32,0);  break;//显示那一天
						case 4:	LCD_ShowChinese(37,		110,	"周四",	BLACK,	LGRAY,	32,0);  break;//显示那一天
						case 5:	LCD_ShowChinese(37,		110,	"周五",	BLACK,	LGRAY,	32,0);  break;//显示那一天
						case 6:	LCD_ShowChinese(37,		110,	"周六",	BLACK,	LGRAY,	32,0);  break;//显示那一天
						case 7:	LCD_ShowChinese(37,		110,	"周日",	BLACK,	LGRAY,	32,0);  break;//显示那一天
					}
				
					break;
				}
			}
		}	
		if(Number_of_cycles_ == 4 && switch_value == Button_2_pressed) //结束此功能的设置，跳出循环，回到闹钟的界面
		{
			clock_time_hour[i] = value_1;
			
			clock_time_min[i] = value_2; //把设置好的闹钟的日期更新到数组里保存起来
			
			clock_Data[i] = value_3; //把设置好的时间更新到数组里保存起来
			
			value_1 = 6; //把数值恢复到之前的状态 ，为下一个新建闹钟做准备
			
			value_2 = 40;
			
			value_3 = 0;

			break; //退出
		}	
		if(Number_of_cycles_ == 5 && switch_value == Button_2_pressed)  //结束此功能的设置，跳出循环，回到闹钟的界面
		{
			clock_time_hour[0] = 60; //正常情况下是不会出现六十这样的事件，是无效的事件。判定为无效闹钟就会被删除
			
			value_1 = 6; //把数值恢复到之前的状态 ，为下一个新建闹钟做准备
			
			value_2 = 40;
			
			value_3 = 0;
			
			clock_time_hour[i] = 60;
			
		 //退出训话之后会回到开始的地方
			
			break;
		}		
	}
}


/*******************************************
* @function: 	闹钟的功能
* @input:			无
* @return:		无
* @author:		田小花
* @time:			2020.10.3
*******************************************/


unsigned char display_clock_function(unsigned char Number_of_cycles,unsigned char flag__)
{
	//显示新建和返回
	if(Number_of_cycles == 1 && flag__ == 1)
	{
//		flag__ = 0; //限制屏幕刷新
		
		LCD_Fill(0,		211,LCD_W,240,WHITE); //显示界面成灰色刷新
		
		//显示第6个闹钟
		if(clock_time_hour[5] != 60)
		{
			LCD_ShowFloatNum1(5,	218,	clock_time_hour[5]+clock_time_min[5]*0.01,	4,	BLACK,	WHITE,	16);
			switch(clock_Data[5])
			{
				case 0:	LCD_ShowChinese(80,		213,	"每天",	BLACK,	WHITE,	24,0);	break;//显示那一天
				case 1:	LCD_ShowChinese(80,		213,	"周一",	BLACK,	WHITE,	24,0);  break;//显示那一天
				case 2:	LCD_ShowChinese(80,		213,	"周二",	BLACK,	WHITE,	24,0);  break;//显示那一天
				case 3:	LCD_ShowChinese(80,		213,	"周三",	BLACK,	WHITE,	24,0);  break;//显示那一天
				case 4:	LCD_ShowChinese(80,		213,	"周四",	BLACK,	WHITE,	24,0);  break;//显示那一天
				case 5:	LCD_ShowChinese(80,		213,	"周五",	BLACK,	WHITE,	24,0);  break;//显示那一天
				case 6:	LCD_ShowChinese(80,		213,	"周六",	BLACK,	WHITE,	24,0);  break;//显示那一天
				case 7:	LCD_ShowChinese(80,		213,	"周日",	BLACK,	WHITE,	24,0);  break;//显示那一天
			}
		}
		
		LCD_Fill(0,		0,LCD_W,30,LGRAY); //显示界面成灰色刷新
		
		LCD_ShowChinese(0,		3,	"返回",	BLACK,	LGRAY,24,0);
		
		LCD_Fill(0,		31,LCD_W,60,WHITE); //显示界面成灰色刷新
		
		LCD_ShowChinese(0,		33,	"新建",	BLACK,	WHITE,24,0);
	}
	
	
	if(Number_of_cycles == 2 && flag__ == 1)
	{
//		flag__ = 0; //限制屏幕刷新
													
		LCD_Fill(0,		0,LCD_W,30,WHITE); //显示界面成灰色刷新
		
		LCD_ShowChinese(0,		3,	"返回",	BLACK,	WHITE,24,0);
		
		LCD_Fill(0,		31,LCD_W,60,LGRAY); //显示界面成灰色刷新	
		
		LCD_ShowChinese(0,		33,	"新建",	BLACK,	LGRAY,24,0);
		
		LCD_Fill(0,		61,LCD_W,90,WHITE); //显示界面成灰色刷新
		//显示第一个闹钟
		if(clock_time_hour[0] != 60)
		{
			LCD_ShowFloatNum1(5,	68,	clock_time_hour[0]+clock_time_min[0]*0.01,	4,	BLACK,	WHITE,	16);
			
			switch(clock_Data[0])
			{
				case 0:	LCD_ShowChinese(80,		63,	"每天",	BLACK,	WHITE,	24,0);	break;//显示那一天
				case 1:	LCD_ShowChinese(80,		63,	"周一",	BLACK,	WHITE,	24,0);  break;//显示那一天
				case 2:	LCD_ShowChinese(80,		63,	"周二",	BLACK,	WHITE,	24,0);  break;//显示那一天
				case 3:	LCD_ShowChinese(80,		63,	"周三",	BLACK,	WHITE,	24,0);  break;//显示那一天
				case 4:	LCD_ShowChinese(80,		63,	"周四",	BLACK,	WHITE,	24,0);  break;//显示那一天
				case 5:	LCD_ShowChinese(80,		63,	"周五",	BLACK,	WHITE,	24,0);  break;//显示那一天
				case 6:	LCD_ShowChinese(80,		63,	"周六",	BLACK,	WHITE,	24,0);  break;//显示那一天
				case 7:	LCD_ShowChinese(80,		63,	"周日",	BLACK,	WHITE,	24,0);  break;//显示那一天
			}
			//LCD_ShowChinese(80,		63,	clock_time_hour[0],	BLACK,	WHITE,24,0);
		}
	}
	
	//显示闹钟的列表
	if(Number_of_cycles == 3 && flag__ == 1)
	{
//		flag__ = 0; //限制屏幕刷新

		LCD_Fill(0,		31,LCD_W,60,WHITE); //显示界面成灰色刷新
		
		LCD_ShowChinese(0,		33,	"新建",	BLACK,	WHITE,24,0);
		
		LCD_Fill(0,		61,LCD_W,90,LGRAY); //显示界面成灰色刷新
		
		//显示第一个闹钟
		if(clock_time_hour[0] != 60)
		{
			LCD_ShowFloatNum1(5,	68,	clock_time_hour[0]+clock_time_min[0]*0.01,	4,	BLACK,	LGRAY,	16);
			
			switch(clock_Data[0])
			{
				case 0:	LCD_ShowChinese(80,		63,	"每天",	BLACK,	LGRAY,	24,0);	break;//显示那一天
				case 1:	LCD_ShowChinese(80,		63,	"周一",	BLACK,	LGRAY,	24,0);  break;//显示那一天
				case 2:	LCD_ShowChinese(80,		63,	"周二",	BLACK,	LGRAY,	24,0);  break;//显示那一天
				case 3:	LCD_ShowChinese(80,		63,	"周三",	BLACK,	LGRAY,	24,0);  break;//显示那一天
				case 4:	LCD_ShowChinese(80,		63,	"周四",	BLACK,	LGRAY,	24,0);  break;//显示那一天
				case 5:	LCD_ShowChinese(80,		63,	"周五",	BLACK,	LGRAY,	24,0);  break;//显示那一天
				case 6:	LCD_ShowChinese(80,		63,	"周六",	BLACK,	LGRAY,	24,0);  break;//显示那一天
				case 7:	LCD_ShowChinese(80,		63,	"周日",	BLACK,	LGRAY,	24,0);  break;//显示那一天
			}
		}
		
		LCD_Fill(0,		91,LCD_W,120,WHITE); //显示界面成灰色刷新
		//显示第2个闹钟
		if(clock_time_hour[1] != 60)
		{
			LCD_ShowFloatNum1(5,	98,	clock_time_hour[1]+clock_time_min[1]*0.01,	4,	BLACK,	WHITE,	16);
			switch(clock_Data[1])
			{
				case 0:	LCD_ShowChinese(80,		93,	"每天",	BLACK,	WHITE,	24,0);	break;//显示那一天
				case 1:	LCD_ShowChinese(80,		93,	"周一",	BLACK,	WHITE,	24,0);  break;//显示那一天
				case 2:	LCD_ShowChinese(80,		93,	"周二",	BLACK,	WHITE,	24,0);  break;//显示那一天
				case 3:	LCD_ShowChinese(80,		93,	"周三",	BLACK,	WHITE,	24,0);  break;//显示那一天
				case 4:	LCD_ShowChinese(80,		93,	"周四",	BLACK,	WHITE,	24,0);  break;//显示那一天
				case 5:	LCD_ShowChinese(80,		93,	"周五",	BLACK,	WHITE,	24,0);  break;//显示那一天
				case 6:	LCD_ShowChinese(80,		93,	"周六",	BLACK,	WHITE,	24,0);  break;//显示那一天
				case 7:	LCD_ShowChinese(80,		93,	"周日",	BLACK,	WHITE,	24,0);  break;//显示那一天
			}
		}
	}
	
	
	
	if(Number_of_cycles == 4 && flag__ == 1)
	{
//		flag__ = 0; //限制屏幕刷新
		
		LCD_Fill(0,		61,LCD_W,90,WHITE); //显示界面成灰色刷新

		//显示第一个闹钟
		if(clock_time_hour[0] != 60)
		{
			LCD_ShowFloatNum1(5,	68,	clock_time_hour[0]+clock_time_min[0]*0.01,	4,	BLACK,	WHITE,	16);
			
			switch(clock_Data[0])
			{
				case 0:	LCD_ShowChinese(80,		63,	"每天",	BLACK,	WHITE,	24,0);	break;//显示那一天
				case 1:	LCD_ShowChinese(80,		63,	"周一",	BLACK,	WHITE,	24,0);  break;//显示那一天
				case 2:	LCD_ShowChinese(80,		63,	"周二",	BLACK,	WHITE,	24,0);  break;//显示那一天
				case 3:	LCD_ShowChinese(80,		63,	"周三",	BLACK,	WHITE,	24,0);  break;//显示那一天
				case 4:	LCD_ShowChinese(80,		63,	"周四",	BLACK,	WHITE,	24,0);  break;//显示那一天
				case 5:	LCD_ShowChinese(80,		63,	"周五",	BLACK,	WHITE,	24,0);  break;//显示那一天
				case 6:	LCD_ShowChinese(80,		63,	"周六",	BLACK,	WHITE,	24,0);  break;//显示那一天
				case 7:	LCD_ShowChinese(80,		63,	"周日",	BLACK,	WHITE,	24,0);  break;//显示那一天
			}
		}	
		
		LCD_Fill(0,		91,LCD_W,120,LGRAY); //显示界面成灰色刷新
		//显示第2个闹钟
		if(clock_time_hour[1] != 60)
		{
			LCD_ShowFloatNum1(5,	98,	clock_time_hour[1]+clock_time_min[1]*0.01,	4,	BLACK,	LGRAY,	16);
			switch(clock_Data[1])
			{
				case 0:	LCD_ShowChinese(80,		93,	"每天",	BLACK,	LGRAY,	24,0);	break;//显示那一天
				case 1:	LCD_ShowChinese(80,		93,	"周一",	BLACK,	LGRAY,	24,0);  break;//显示那一天
				case 2:	LCD_ShowChinese(80,		93,	"周二",	BLACK,	LGRAY,	24,0);  break;//显示那一天
				case 3:	LCD_ShowChinese(80,		93,	"周三",	BLACK,	LGRAY,	24,0);  break;//显示那一天
				case 4:	LCD_ShowChinese(80,		93,	"周四",	BLACK,	LGRAY,	24,0);  break;//显示那一天
				case 5:	LCD_ShowChinese(80,		93,	"周五",	BLACK,	LGRAY,	24,0);  break;//显示那一天
				case 6:	LCD_ShowChinese(80,		93,	"周六",	BLACK,	LGRAY,	24,0);  break;//显示那一天
				case 7:	LCD_ShowChinese(80,		93,	"周日",	BLACK,	LGRAY,	24,0);  break;//显示那一天
			}
		}
		
		
		LCD_Fill(0,		121,LCD_W,150,WHITE); //显示界面成灰色刷新
		//显示第3个闹钟
		if(clock_time_hour[2] != 60)
		{
			LCD_ShowFloatNum1(5,	128,	clock_time_hour[2]+clock_time_min[2]*0.01,	4,	BLACK,	WHITE,	16);
			switch(clock_Data[2])
			{
				case 0:	LCD_ShowChinese(80,		123,	"每天",	BLACK,	WHITE,	24,0);	break;//显示那一天
				case 1:	LCD_ShowChinese(80,		123,	"周一",	BLACK,	WHITE,	24,0);  break;//显示那一天
				case 2:	LCD_ShowChinese(80,		123,	"周二",	BLACK,	WHITE,	24,0);  break;//显示那一天
				case 3:	LCD_ShowChinese(80,		123,	"周三",	BLACK,	WHITE,	24,0);  break;//显示那一天
				case 4:	LCD_ShowChinese(80,		123,	"周四",	BLACK,	WHITE,	24,0);  break;//显示那一天
				case 5:	LCD_ShowChinese(80,		123,	"周五",	BLACK,	WHITE,	24,0);  break;//显示那一天
				case 6:	LCD_ShowChinese(80,		123,	"周六",	BLACK,	WHITE,	24,0);  break;//显示那一天
				case 7:	LCD_ShowChinese(80,		123,	"周日",	BLACK,	WHITE,	24,0);  break;//显示那一天
			}
		}
	}
	
	if(Number_of_cycles == 5 && flag__ == 1)
	{
//		flag__ = 0; //限制屏幕刷新
		
		LCD_Fill(0,		91,LCD_W,120,WHITE); //显示界面成灰色刷新
		//显示第2个闹钟
		if(clock_time_hour[1] != 60)
		{
			LCD_ShowFloatNum1(5,	98,	clock_time_hour[1]+clock_time_min[1]*0.01,	4,	BLACK,	WHITE,	16);
			switch(clock_Data[1])
			{
				case 0:	LCD_ShowChinese(80,		93,	"每天",	BLACK,	WHITE,	24,0);	break;//显示那一天
				case 1:	LCD_ShowChinese(80,		93,	"周一",	BLACK,	WHITE,	24,0);  break;//显示那一天
				case 2:	LCD_ShowChinese(80,		93,	"周二",	BLACK,	WHITE,	24,0);  break;//显示那一天
				case 3:	LCD_ShowChinese(80,		93,	"周三",	BLACK,	WHITE,	24,0);  break;//显示那一天
				case 4:	LCD_ShowChinese(80,		93,	"周四",	BLACK,	WHITE,	24,0);  break;//显示那一天
				case 5:	LCD_ShowChinese(80,		93,	"周五",	BLACK,	WHITE,	24,0);  break;//显示那一天
				case 6:	LCD_ShowChinese(80,		93,	"周六",	BLACK,	WHITE,	24,0);  break;//显示那一天
				case 7:	LCD_ShowChinese(80,		93,	"周日",	BLACK,	WHITE,	24,0);  break;//显示那一天
			}
//			LCD_ShowFloatNum1(5,	98,	6.39,	4,	BLACK,	WHITE,	16);
//					
//			LCD_ShowChinese(80,		93,	"每天",	BLACK,	WHITE,24,0);
		}
		
		LCD_Fill(0,		121,LCD_W,150,LGRAY); //显示界面成灰色刷新
		//显示第3个闹钟
		if(clock_time_hour[2] != 60)
		{
			LCD_ShowFloatNum1(5,	128,	clock_time_hour[2]+clock_time_min[2]*0.01,	4,	BLACK,	LGRAY,	16);
			switch(clock_Data[2])
			{
				case 0:	LCD_ShowChinese(80,		123,	"每天",	BLACK,	LGRAY,	24,0);	break;//显示那一天
				case 1:	LCD_ShowChinese(80,		123,	"周一",	BLACK,	LGRAY,	24,0);  break;//显示那一天
				case 2:	LCD_ShowChinese(80,		123,	"周二",	BLACK,	LGRAY,	24,0);  break;//显示那一天
				case 3:	LCD_ShowChinese(80,		123,	"周三",	BLACK,	LGRAY,	24,0);  break;//显示那一天
				case 4:	LCD_ShowChinese(80,		123,	"周四",	BLACK,	LGRAY,	24,0);  break;//显示那一天
				case 5:	LCD_ShowChinese(80,		123,	"周五",	BLACK,	LGRAY,	24,0);  break;//显示那一天
				case 6:	LCD_ShowChinese(80,		123,	"周六",	BLACK,	LGRAY,	24,0);  break;//显示那一天
				case 7:	LCD_ShowChinese(80,		123,	"周日",	BLACK,	LGRAY,	24,0);  break;//显示那一天
			}
//			LCD_ShowFloatNum1(5,	128,	6.39,	4,	BLACK,	LGRAY,	16);
//					
//			LCD_ShowChinese(80,		123,	"每天",	BLACK,	LGRAY,24,0);
		}
		
		LCD_Fill(0,		151,LCD_W,180,WHITE); //显示界面成灰色刷新
		//显示第4个闹钟
		if(clock_time_hour[3] != 60)
		{
			LCD_ShowFloatNum1(5,	158,	clock_time_hour[3]+clock_time_min[3]*0.01,	4,	BLACK,	WHITE,	16);
			switch(clock_Data[3])
			{
				case 0:	LCD_ShowChinese(80,		153,	"每天",	BLACK,	WHITE,	24,0);	break;//显示那一天
				case 1:	LCD_ShowChinese(80,		153,	"周一",	BLACK,	WHITE,	24,0);  break;//显示那一天
				case 2:	LCD_ShowChinese(80,		153,	"周二",	BLACK,	WHITE,	24,0);  break;//显示那一天
				case 3:	LCD_ShowChinese(80,		153,	"周三",	BLACK,	WHITE,	24,0);  break;//显示那一天
				case 4:	LCD_ShowChinese(80,		153,	"周四",	BLACK,	WHITE,	24,0);  break;//显示那一天
				case 5:	LCD_ShowChinese(80,		153,	"周五",	BLACK,	WHITE,	24,0);  break;//显示那一天
				case 6:	LCD_ShowChinese(80,		153,	"周六",	BLACK,	WHITE,	24,0);  break;//显示那一天
				case 7:	LCD_ShowChinese(80,		153,	"周日",	BLACK,	WHITE,	24,0);  break;//显示那一天
			}
//			LCD_ShowFloatNum1(5,	158,	6.39,	4,	BLACK,	WHITE,	16);
//					
//			LCD_ShowChinese(80,		153,	"每天",	BLACK,	WHITE,24,0);
		}
	}
	
	if(Number_of_cycles == 6 && flag__ == 1)
	{
//		flag__ = 0; //限制屏幕刷新
		
		LCD_Fill(0,		121,LCD_W,150,WHITE); //显示界面成灰色刷新
		//显示第3个闹钟
		if(clock_time_hour[2] != 60)
		{
			LCD_ShowFloatNum1(5,	128,	clock_time_hour[2]+clock_time_min[2]*0.01,	4,	BLACK,	WHITE,	16);
			switch(clock_Data[2])
			{
				case 0:	LCD_ShowChinese(80,		123,	"每天",	BLACK,	WHITE,	24,0);	break;//显示那一天
				case 1:	LCD_ShowChinese(80,		123,	"周一",	BLACK,	WHITE,	24,0);  break;//显示那一天
				case 2:	LCD_ShowChinese(80,		123,	"周二",	BLACK,	WHITE,	24,0);  break;//显示那一天
				case 3:	LCD_ShowChinese(80,		123,	"周三",	BLACK,	WHITE,	24,0);  break;//显示那一天
				case 4:	LCD_ShowChinese(80,		123,	"周四",	BLACK,	WHITE,	24,0);  break;//显示那一天
				case 5:	LCD_ShowChinese(80,		123,	"周五",	BLACK,	WHITE,	24,0);  break;//显示那一天
				case 6:	LCD_ShowChinese(80,		123,	"周六",	BLACK,	WHITE,	24,0);  break;//显示那一天
				case 7:	LCD_ShowChinese(80,		123,	"周日",	BLACK,	WHITE,	24,0);  break;//显示那一天
			}
//			LCD_ShowFloatNum1(5,	128,	6.39,	4,	BLACK,	WHITE,	16);
//					
//			LCD_ShowChinese(80,		123,	"每天",	BLACK,	WHITE,24,0);
		}
		
		LCD_Fill(0,		151,LCD_W,180,LGRAY); //显示界面成灰色刷新
		//显示第4个闹钟
		if(clock_time_hour[3] != 60)
		{
			LCD_ShowFloatNum1(5,	158,	clock_time_hour[3]+clock_time_min[3]*0.01,	4,	BLACK,	LGRAY,	16);
			switch(clock_Data[3])
			{
				case 0:	LCD_ShowChinese(80,		153,	"每天",	BLACK,	LGRAY,	24,0);	break;//显示那一天
				case 1:	LCD_ShowChinese(80,		153,	"周一",	BLACK,	LGRAY,	24,0);  break;//显示那一天
				case 2:	LCD_ShowChinese(80,		153,	"周二",	BLACK,	LGRAY,	24,0);  break;//显示那一天
				case 3:	LCD_ShowChinese(80,		153,	"周三",	BLACK,	LGRAY,	24,0);  break;//显示那一天
				case 4:	LCD_ShowChinese(80,		153,	"周四",	BLACK,	LGRAY,	24,0);  break;//显示那一天
				case 5:	LCD_ShowChinese(80,		153,	"周五",	BLACK,	LGRAY,	24,0);  break;//显示那一天
				case 6:	LCD_ShowChinese(80,		153,	"周六",	BLACK,	LGRAY,	24,0);  break;//显示那一天
				case 7:	LCD_ShowChinese(80,		153,	"周日",	BLACK,	LGRAY,	24,0);  break;//显示那一天
			}
//			LCD_ShowFloatNum1(5,	158,	6.39,	4,	BLACK,	LGRAY,	16);
//					
//			LCD_ShowChinese(80,		153,	"每天",	BLACK,	LGRAY,24,0);
		}
		
		LCD_Fill(0,		181,LCD_W,210,WHITE); //显示界面成灰色刷新
		//显示第5个闹钟
		if(clock_time_hour[4] != 60)
		{
			LCD_ShowFloatNum1(5,	188,	clock_time_hour[4]+clock_time_min[4]*0.01,	4,	BLACK,	WHITE,	16);
			switch(clock_Data[4])
			{
				case 0:	LCD_ShowChinese(80,		183,	"每天",	BLACK,	WHITE,	24,0);	break;//显示那一天
				case 1:	LCD_ShowChinese(80,		183,	"周一",	BLACK,	WHITE,	24,0);  break;//显示那一天
				case 2:	LCD_ShowChinese(80,		183,	"周二",	BLACK,	WHITE,	24,0);  break;//显示那一天
				case 3:	LCD_ShowChinese(80,		183,	"周三",	BLACK,	WHITE,	24,0);  break;//显示那一天
				case 4:	LCD_ShowChinese(80,		183,	"周四",	BLACK,	WHITE,	24,0);  break;//显示那一天
				case 5:	LCD_ShowChinese(80,		183,	"周五",	BLACK,	WHITE,	24,0);  break;//显示那一天
				case 6:	LCD_ShowChinese(80,		183,	"周六",	BLACK,	WHITE,	24,0);  break;//显示那一天
				case 7:	LCD_ShowChinese(80,		183,	"周日",	BLACK,	WHITE,	24,0);  break;//显示那一天
			}
//			LCD_ShowFloatNum1(5,	188,	6.39,	4,	BLACK,	WHITE,	16);
//					
//			LCD_ShowChinese(80,		183,	"每天",	BLACK,	WHITE,24,0);
		}
	}
	
	if(Number_of_cycles == 7 && flag__ == 1)
	{
//		flag__ = 0; //限制屏幕刷新
		
		LCD_Fill(0,		151,LCD_W,180,WHITE); //显示界面成灰色刷新
		//显示第4个闹钟
		if(clock_time_hour[3] != 60)
		{
			LCD_ShowFloatNum1(5,	158,	clock_time_hour[3]+clock_time_min[3]*0.01,	4,	BLACK,	WHITE,	16);
			switch(clock_Data[3])
			{
				case 0:	LCD_ShowChinese(80,		153,	"每天",	BLACK,	WHITE,	24,0);	break;//显示那一天
				case 1:	LCD_ShowChinese(80,		153,	"周一",	BLACK,	WHITE,	24,0);  break;//显示那一天
				case 2:	LCD_ShowChinese(80,		153,	"周二",	BLACK,	WHITE,	24,0);  break;//显示那一天
				case 3:	LCD_ShowChinese(80,		153,	"周三",	BLACK,	WHITE,	24,0);  break;//显示那一天
				case 4:	LCD_ShowChinese(80,		153,	"周四",	BLACK,	WHITE,	24,0);  break;//显示那一天
				case 5:	LCD_ShowChinese(80,		153,	"周五",	BLACK,	WHITE,	24,0);  break;//显示那一天
				case 6:	LCD_ShowChinese(80,		153,	"周六",	BLACK,	WHITE,	24,0);  break;//显示那一天
				case 7:	LCD_ShowChinese(80,		153,	"周日",	BLACK,	WHITE,	24,0);  break;//显示那一天
			}
//			LCD_ShowFloatNum1(5,	158,	6.39,	4,	BLACK,	WHITE,	16);
//					
//			LCD_ShowChinese(80,		153,	"每天",	BLACK,	WHITE,24,0);
		}
		
		LCD_Fill(0,		181,LCD_W,210,LGRAY); //显示界面成灰色刷新
		//显示第5个闹钟
		if(clock_time_hour[4] != 60)
		{
			LCD_ShowFloatNum1(5,	188,	clock_time_hour[4]+clock_time_min[4]*0.01,	4,	BLACK,	LGRAY,	16);
			switch(clock_Data[4])
			{
				case 0:	LCD_ShowChinese(80,		183,	"每天",	BLACK,	LGRAY,	24,0);	break;//显示那一天
				case 1:	LCD_ShowChinese(80,		183,	"周一",	BLACK,	LGRAY,	24,0);  break;//显示那一天
				case 2:	LCD_ShowChinese(80,		183,	"周二",	BLACK,	LGRAY,	24,0);  break;//显示那一天
				case 3:	LCD_ShowChinese(80,		183,	"周三",	BLACK,	LGRAY,	24,0);  break;//显示那一天
				case 4:	LCD_ShowChinese(80,		183,	"周四",	BLACK,	LGRAY,	24,0);  break;//显示那一天
				case 5:	LCD_ShowChinese(80,		183,	"周五",	BLACK,	LGRAY,	24,0);  break;//显示那一天
				case 6:	LCD_ShowChinese(80,		183,	"周六",	BLACK,	LGRAY,	24,0);  break;//显示那一天
				case 7:	LCD_ShowChinese(80,		183,	"周日",	BLACK,	LGRAY,	24,0);  break;//显示那一天
			}
//			LCD_ShowFloatNum1(5,	188,	6.39,	4,	BLACK,	LGRAY,	16);
//					
//			LCD_ShowChinese(80,		183,	"每天",	BLACK,	LGRAY,24,0);
		}
		
		LCD_Fill(0,		211,LCD_W,240,WHITE); //显示界面成灰色刷新
		//显示第6个闹钟
		if(clock_time_hour[5] != 60)
		{
			LCD_ShowFloatNum1(5,	218,	clock_time_hour[5]+clock_time_min[5]*0.01,	4,	BLACK,	WHITE,	16);
			
			switch(clock_Data[5])
			{
				case 0:	LCD_ShowChinese(80,		213,	"每天",	BLACK,	WHITE,	24,0);	break;//显示那一天
				case 1:	LCD_ShowChinese(80,		213,	"周一",	BLACK,	WHITE,	24,0);  break;//显示那一天
				case 2:	LCD_ShowChinese(80,		213,	"周二",	BLACK,	WHITE,	24,0);  break;//显示那一天
				case 3:	LCD_ShowChinese(80,		213,	"周三",	BLACK,	WHITE,	24,0);  break;//显示那一天
				case 4:	LCD_ShowChinese(80,		213,	"周四",	BLACK,	WHITE,	24,0);  break;//显示那一天
				case 5:	LCD_ShowChinese(80,		213,	"周五",	BLACK,	WHITE,	24,0);  break;//显示那一天
				case 6:	LCD_ShowChinese(80,		213,	"周六",	BLACK,	WHITE,	24,0);  break;//显示那一天
				case 7:	LCD_ShowChinese(80,		213,	"周日",	BLACK,	WHITE,	24,0);  break;//显示那一天
			}
//			LCD_ShowFloatNum1(5,	218,	6.39,	4,	BLACK,	WHITE,	16);
//					
//			LCD_ShowChinese(80,		213,	"每天",	BLACK,	WHITE,24,0);
		}
	}
	
	if(Number_of_cycles == 8 && flag__ == 1)
	{
//		flag__ = 0; //限制屏幕刷新
		
		LCD_Fill(0,		181,LCD_W,210,WHITE); //显示界面成灰色刷新
		//显示第5个闹钟
		if(clock_time_hour[4] != 60)
		{
			LCD_ShowFloatNum1(5,	188,	clock_time_hour[4]+clock_time_min[4]*0.01,	4,	BLACK,	WHITE,	16);
			
			switch(clock_Data[4])
			{
				case 0:	LCD_ShowChinese(80,		183,	"每天",	BLACK,	WHITE,	24,0);	break;//显示那一天
				case 1:	LCD_ShowChinese(80,		183,	"周一",	BLACK,	WHITE,	24,0);  break;//显示那一天
				case 2:	LCD_ShowChinese(80,		183,	"周二",	BLACK,	WHITE,	24,0);  break;//显示那一天
				case 3:	LCD_ShowChinese(80,		183,	"周三",	BLACK,	WHITE,	24,0);  break;//显示那一天
				case 4:	LCD_ShowChinese(80,		183,	"周四",	BLACK,	WHITE,	24,0);  break;//显示那一天
				case 5:	LCD_ShowChinese(80,		183,	"周五",	BLACK,	WHITE,	24,0);  break;//显示那一天
				case 6:	LCD_ShowChinese(80,		183,	"周六",	BLACK,	WHITE,	24,0);  break;//显示那一天
				case 7:	LCD_ShowChinese(80,		183,	"周日",	BLACK,	WHITE,	24,0);  break;//显示那一天
			}
//			LCD_ShowFloatNum1(5,	188,	6.39,	4,	BLACK,	WHITE,	16);
//					
//			LCD_ShowChinese(80,		183,	"每天",	BLACK,	WHITE,24,0);
		}
		
		LCD_Fill(0,		211,LCD_W,240,LGRAY); //显示界面成灰色刷新
		//显示第6个闹钟
		if(clock_time_hour[5] != 60)
		{
			LCD_ShowFloatNum1(5,	218,	clock_time_hour[5]+clock_time_min[5]*0.01,	4,	BLACK,	LGRAY,	16);
			
			switch(clock_Data[5])
			{
				case 0:	LCD_ShowChinese(80,		213,	"每天",	BLACK,	LGRAY,	24,0);	break;//显示那一天
				case 1:	LCD_ShowChinese(80,		213,	"周一",	BLACK,	LGRAY,	24,0);  break;//显示那一天
				case 2:	LCD_ShowChinese(80,		213,	"周二",	BLACK,	LGRAY,	24,0);  break;//显示那一天
				case 3:	LCD_ShowChinese(80,		213,	"周三",	BLACK,	LGRAY,	24,0);  break;//显示那一天
				case 4:	LCD_ShowChinese(80,		213,	"周四",	BLACK,	LGRAY,	24,0);  break;//显示那一天
				case 5:	LCD_ShowChinese(80,		213,	"周五",	BLACK,	LGRAY,	24,0);  break;//显示那一天
				case 6:	LCD_ShowChinese(80,		213,	"周六",	BLACK,	LGRAY,	24,0);  break;//显示那一天
				case 7:	LCD_ShowChinese(80,		213,	"周日",	BLACK,	LGRAY,	24,0);  break;//显示那一天
			}
		}
		
		LCD_Fill(0,		0,LCD_W,30,WHITE); //显示界面成灰色刷新
		
		LCD_ShowChinese(0,		3,	"返回",	BLACK,	WHITE,24,0);
		
	}
	return 0;
}
/*******************************************
* @function: 	闹钟的功能
* @input:			无
* @return:		无
* @author:		田小花
* @time:			2020.10.3
*******************************************/

void clock_function(void)
{
//	static unsigned char Number_of_cycles = function_clock;
	
	unsigned char switch_value;
		
	static unsigned char flag__ = 0;
	
//	static unsigned char flag_ = 0;
	
	static unsigned char Number_of_cycles = 1;
	
//	static unsigned char Number_of_cycles_ = 1;
	
	unsigned char i = 0;
	
	LCD_Fill(0,0,LCD_W,LCD_H,BLACK); //电池里面的填充
	
	printf("进入了闹钟app\r\n");

	clock_begin_display(); //对闹钟的开始的表格化界面进行刷新
	
	flag__ = 1; //限制屏幕刷新
	
	while(1)
	{
		switch_value = Get_Key_value(1);
		
		if(switch_value == Button_3_pressed)
		{
			Number_of_cycles++;
			
			flag__ = 1; //限制屏幕刷新
			
			if(Number_of_cycles > 8)
			{
				Number_of_cycles = 1;
			}
		}
		
		if(switch_value == Button_1_pressed)
		{
			Number_of_cycles--;
			
			flag__ = 1; //限制屏幕刷新
			
			if(Number_of_cycles<1)
			{
				Number_of_cycles = 8;
			}
		}
		
		//显示和刷新界面。包括返回和新建以及闹钟列表
		flag__ = display_clock_function(Number_of_cycles,flag__); //限制刷新
		
		//判断需要返回
		if(switch_value == Button_2_pressed && Number_of_cycles == 1)
		{
//				flag = 1;
			Number_of_cycles = 1;
			
			break;
		}		
		//判断选择了新建按钮
		if(switch_value == Button_2_pressed && Number_of_cycles == 2)
		{
			for(i=0;i<6;i++)
			{
				if(clock_time_hour[i] == 60)
				{
					
					//进入设置闹钟的界面
					set_clock_fun(i);
					
					i=0;
					
					//推出后需要重新刷新界面
					clock_begin_display();
								
					flag__ = 1; //限制屏幕刷新
					
					break;
				}
			}
			for(i=0;i<6;i++)
			{
				printf("%d  ",clock_time_hour[i]);
			}
			printf("\r\n");
		}
			
		//判断选择了第一个闹钟
		if(switch_value == Button_2_pressed && Number_of_cycles == 3)
		{
			if(clock_time_hour[0] != 60)
			{
				set_clock_fun(0);
				
				clock_begin_display();
				
				Number_of_cycles = 1;	
			}
			
		}
		//判断选择了第2个闹钟
		if(switch_value == Button_2_pressed && Number_of_cycles == 4)
		{
			if(clock_time_hour[1] != 60)
			{
				set_clock_fun(1);
				
				clock_begin_display();
				
				Number_of_cycles = 1;	
			}
			
		}
		//判断选择了第3个闹钟
		if(switch_value == Button_2_pressed && Number_of_cycles == 5)
		{
			if(clock_time_hour[2] != 60)
			{
				set_clock_fun(2);
				
				clock_begin_display();
				
				Number_of_cycles = 1;	
			}
			
		}
		//判断选择了第4个闹钟
		if(switch_value == Button_2_pressed && Number_of_cycles == 6)
		{
			if(clock_time_hour[3] != 60)
			{
				set_clock_fun(3);
				
				clock_begin_display();
				
				Number_of_cycles = 1;	
			}
			
		}
		//判断选择了第5个闹钟
		if(switch_value == Button_2_pressed && Number_of_cycles == 7)
		{
			if(clock_time_hour[4] != 60)
			{
				set_clock_fun(4);
				
				clock_begin_display();
				
				Number_of_cycles = 1;
			}
			
		}
		//判断选择了第6个闹钟
		if(switch_value == Button_2_pressed && Number_of_cycles == 8)
		{
			if(clock_time_hour[5] != 60)
			{
				set_clock_fun(5);
				
				clock_begin_display();
				
				Number_of_cycles = 1;
			}
			
		}
	}
}
	
/*******************************************
* @function: 	闹钟的功能
* @input:			无
* @return:		无
* @author:		田小花
* @time:			2020.10.3
*******************************************/
void light_function(void)
{
	unsigned char switch_value;
	
	LCD_Fill(0,0,LCD_W,LCD_H,WHITE); //让屏幕变成大白色
	
	__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_4, 600); //设置PWM的占空比，调节背光 //把屏幕调节成高亮
	
	HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_RESET);	
	
	while(1)
	{
		switch_value = Get_Key_value(1);
		
		if(switch_value == Button_3_pressed || switch_value == Button_2_pressed || switch_value == Button_1_pressed)
		{
			__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_4, 70); //设置PWM的占空比，调节背光
			
			HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_SET);
			
			break;
		}
	}
	MENU_light();

}	



/*******************************************
* @function: 	设置时间的功能界面功能
* @input:			无
* @return:		无
* @author:		田小花
* @time:			2020.10.24
*******************************************/
void set_time_function(void)
{
	unsigned char switch_value = 0;
	
	unsigned char Number_of_cycles_ = 1;
	
	unsigned char flag_ = 0;
	
	int value_1 = 0; //时钟数字
	
	int value_2 = 0; //分钟数字
	
	value_1 = sTime.Hours;
	
	value_2 = sTime.Minutes;
	
	LCD_Fill(0,		0,		LCD_W,	LCD_H,	WHITE); //显示界面成白色刷新
			
	LCD_ShowIntNum1(5,	65,	value_1,	2,	BLACK,	LGRAY,	32); //显示时钟数
				
	LCD_ShowChinese(37,		65,	"时",	BLACK,	WHITE,	32,0); //显示时
	
	LCD_ShowIntNum1(69,	65,	value_2,	2,	BLACK,	WHITE,	32); //显示分钟
	
	LCD_ShowChinese(101,		65,	"分",	BLACK,	WHITE,	32,0); //显示分
		
	LCD_ShowChinese(5,		210,	"确定",	BLACK,	WHITE,	24,0); //显示确定
	
	LCD_ShowChinese(85,		210,	"取消",	BLACK,	WHITE,	24,0); //显示删除
	
	/*************************************
		
	进入主要的功能实现主循环
		
	*****************************************/
	while(1)
	{
		switch_value = Get_Key_value(1); //检测按键
		
		if(switch_value == Button_1_pressed)// 上下调节选择时间或者日期
		{
			Number_of_cycles_--;
			
			flag_ = 1;
			
			if(Number_of_cycles_<1)
			{
				Number_of_cycles_ = 5;
			}
		}
		
		if(switch_value == Button_3_pressed)// // 上下调节选择时间或者日期
		{
			Number_of_cycles_++;
			
			flag_ = 1;
			
			if(Number_of_cycles_>5)
			{
				Number_of_cycles_ = 1;
			}
		}

		
		/*************************************
		
		显示部分，把时间日期和确认删除分开进行显示，每次按键按下才进行刷新
		
		*****************************************/
		if(Number_of_cycles_ == 1 && flag_ == 1)
		{
			flag_ = 0;
			
			LCD_ShowChinese(85,		210,	"取消",	BLACK,	WHITE,	24,0); //显示删除
			
			LCD_ShowIntNum1(5,	65,	value_1,	2,	BLACK,	LGRAY,	32); //显示时钟数
			
			LCD_ShowIntNum1(69,	65,	value_2,	2,	BLACK,	WHITE,	32); //显示分钟
		}
		if(Number_of_cycles_ == 2 && flag_ == 1)
		{
			flag_ = 0;
			
			LCD_ShowIntNum1(5,	65,	value_1,	2,	BLACK,	WHITE,	32); //显示时钟数
			
			LCD_ShowIntNum1(69,	65,	value_2,	2,	BLACK,	LGRAY,	32); //显示分钟
			
			LCD_ShowChinese(5,		210,	"确定",	BLACK,	WHITE,	24,0); //显示确定
		}
		if(Number_of_cycles_ == 3 && flag_ == 1)
		{
			flag_ = 0;
			
			LCD_ShowIntNum1(69,	65,	value_2,	2,	BLACK,	WHITE,	32); //显示分钟
			
			LCD_ShowChinese(5,		210,	"确定",	BLACK,	LGRAY,	24,0); //显示确定
			
			LCD_ShowChinese(85,		210,	"取消",	BLACK,	WHITE,	24,0); //显示删除
		}
		if(Number_of_cycles_ == 4 && flag_ == 1)
		{
			flag_ = 0;
			
			LCD_ShowChinese(5,		210,	"确定",	BLACK,	WHITE,	24,0); //显示确定
			
			LCD_ShowChinese(85,		210,	"取消",	BLACK,	LGRAY,	24,0); //显示删除
			
			LCD_ShowIntNum1(5,	65,	value_1,	2,	BLACK,	WHITE,	32); //显示时钟数
		}
		
		
		/*************************************
		
		对功能实现的具体操作
		
		*****************************************/
		if(Number_of_cycles_ == 1 && switch_value == Button_2_pressed) //对小时调节的功能进行操作
		{
			while(1)
			{
				switch_value = Get_Key_value(1);
				
				LCD_ShowIntNum1(5,	65,	value_1,	2,	BLACK,	LGRAYBLUE,	32); //显示时钟数 //选中以后变成灰蓝色
				
				if(switch_value == Button_1_pressed)
				{								
					value_1 --;									
				}
				if(switch_value == Button_3_pressed)
				{						
					value_1 ++;
				}
				if(value_1 < 0)
				{
					value_1 = 23;
				}
				if(value_1 > 23)
				{
					value_1 = 0;
				}
				if(switch_value == Button_2_pressed)
				{
					LCD_ShowIntNum1(5,	65,	value_1,	2,	BLACK,	LGRAY,	32); //显示时钟数 //选中以后变成灰蓝色 //把选中之后的颜色改变回来
					
					break;
				}
			}
		}	
		if(Number_of_cycles_ == 2 && switch_value == Button_2_pressed) //对分钟调节的功能进行操作
		{
			while(1)
			{
				switch_value = Get_Key_value(1);
				
				LCD_ShowIntNum1(69,	65,	value_2,	2,	BLACK,	LGRAYBLUE,	32); //显示分钟 //选中以后变成灰蓝色
				
				if(switch_value == Button_1_pressed)
				{								
					value_2 --;									
				}
				if(switch_value == Button_3_pressed)
				{						
					value_2 ++;
				}
				if(value_2 < 0)
				{
					value_2 = 59;
				}
				if(value_2 > 59)
				{
					value_2 = 0;
				}
				if(switch_value == Button_2_pressed)
				{
					LCD_ShowIntNum1(69,	65,	value_2,	2,	BLACK,	LGRAY,	32);  //显示时钟数 //选中以后变成灰蓝色 //把选中之后的颜色改变回来
					
					break;
				}
			}
		}	
		if(Number_of_cycles_ == 3 && switch_value == Button_2_pressed) //结束此功能的设置，跳出循环，回到闹钟的界面
		{
			sTime.Hours = value_1+1;
			
			sTime.Minutes = value_2+1;
			
			sTime.Seconds = 0;
			
			sTime.DayLightSaving = RTC_DAYLIGHTSAVING_SUB1H;
			
			sTime.StoreOperation = RTC_STOREOPERATION_SET;
			
			if (HAL_RTC_SetTime(&hrtc, &sTime, RTC_FORMAT_BIN) != HAL_OK)
			{
				Error_Handler();
			}
			break; //退出
		}	
		if(Number_of_cycles_ == 4 && switch_value == Button_2_pressed)  //结束此功能的设置，跳出循环，回到闹钟的界面
		{
		 //退出循环之后会回到开始的地方
			
			break;
		}		
	}
}


/*******************************************
* @function: 	对日期设置进行具体功能的实现
* @input:			无
* @return:		无
* @author:		田小花
* @time:			2020.10.24
*******************************************/

void set_data_function( void )
{
	unsigned char switch_value = 0;
	
	unsigned char Number_of_cycles_ = 1;
	
	unsigned char flag_ = 0;
	
	int value_WeekDay = 0; //value_WeekDay	value_Month		value_Date		value_Year
	
	int value_Month = 0; //
	
	int value_Date = 0; //
	
	int value_Year = 0; //

	value_WeekDay = sDate.WeekDay;
	
	value_Month = sDate.Month;

	value_Date= sDate.Date;

	value_Year= sDate.Year;

	LCD_Fill(0,		0,		LCD_W,	LCD_H,	WHITE); //显示界面成白色刷新
			
	LCD_ShowIntNum1(	5,		65,		value_Month,	2,	BLACK,	LGRAY,	32); //显示月
					
	LCD_ShowChinese(	37,		65,		"月",	BLACK,	WHITE,	32,0); //显示月份
	
	LCD_ShowIntNum1(	69,		65,		value_Date,	2,	BLACK,	WHITE,	32); //显示日
	
	LCD_ShowChinese(	101,	65,		"日",	BLACK,	WHITE,	32,0); //显示日
	
	LCD_ShowIntNum1(	5,		110,		value_Year,	2,	BLACK,	WHITE,	32); //显示年
	
	LCD_ShowChinese(	37,		110,	"年",	BLACK,	WHITE,	32,0); //显示年
	
	LCD_ShowIntNum1(	101,		110,	value_WeekDay,	2,	BLACK,	WHITE,	32); //显示周
	
	LCD_ShowChinese(	69,		110,	"周",	BLACK,	WHITE,	32,0); //显示周
	
	LCD_ShowChinese(	5,		210,	"确定",	BLACK,	WHITE,	24,0); //显示确定
	
	LCD_ShowChinese(	85,		210,	"取消",	BLACK,	WHITE,	24,0); //显示删除
	
	while(1)
	{
		switch_value = Get_Key_value(1); //检测按键
		
		if(switch_value == Button_1_pressed)// 上下调节选择时间或者日期
		{
			Number_of_cycles_--;
			
			flag_ = 1;
			
			if(Number_of_cycles_<1)
			{
				Number_of_cycles_ = 6;
			}
		}
		
		if(switch_value == Button_3_pressed)// // 上下调节选择时间或者日期
		{
			Number_of_cycles_++;
			
			flag_ = 1;
			
			if(Number_of_cycles_>6)
			{
				Number_of_cycles_ = 1;
			}
		}

		
		/*************************************
		
		显示部分，把时间日期和确认删除分开进行显示，每次按键按下才进行刷新
		
		*****************************************/
		
		if(Number_of_cycles_ == 1 && flag_ == 1)
		{
			flag_ = 0;
			
			LCD_ShowChinese(	85,		210,	"取消",	BLACK,	WHITE,	24,0); //显示删除
			
			LCD_ShowIntNum1(5,	65,	value_Month,	2,	BLACK,	LGRAY,	32); //显示月
			
			LCD_ShowIntNum1(69,	65,	value_Date,	2,	BLACK,	WHITE,	32); //显示日
		}
		
		
		if(Number_of_cycles_ == 2 && flag_ == 1)
		{
			flag_ = 0;
			
			LCD_ShowIntNum1(5,	65,	value_Month,	2,	BLACK,	WHITE,	32); //显示月
			
			LCD_ShowIntNum1(69,	65,	value_Date,	2,	BLACK,	LGRAY,	32); //显示日
			
			LCD_ShowIntNum1(5,	110,	value_Year,	2,	BLACK,	WHITE,	32); //显示年
		}
		
		
		
		if(Number_of_cycles_ == 3 && flag_ == 1)
		{
			flag_ = 0;
			
			LCD_ShowIntNum1(69,	65,	value_Date,	2,	BLACK,	WHITE,	32); //显示日
			
			LCD_ShowIntNum1(5,	110,	value_Year,	2,	BLACK,	LGRAY,	32); //显示年
			
			switch(value_WeekDay)
			{
				case 0:	LCD_ShowChinese(101,		110,	"日",	BLACK,	WHITE,	32,0);  break;//显示那一天
				case 1:	LCD_ShowChinese(101,		110,	"一",	BLACK,	WHITE,	32,0);  break;//显示那一天
				case 2:	LCD_ShowChinese(101,		110,	"二",	BLACK,	WHITE,	32,0);  break;//显示那一天
				case 3:	LCD_ShowChinese(101,		110,	"三",	BLACK,	WHITE,	32,0);  break;//显示那一天
				case 4:	LCD_ShowChinese(101,		110,	"四",	BLACK,	WHITE,	32,0);  break;//显示那一天
				case 5:	LCD_ShowChinese(101,		110,	"五",	BLACK,	WHITE,	32,0);  break;//显示那一天
				case 6:	LCD_ShowChinese(101,		110,	"六",	BLACK,	WHITE,	32,0);  break;//显示那一天
			}
		}
		
		
		
		if(Number_of_cycles_ == 4 && flag_ == 1)
		{
			flag_ = 0;
			
			LCD_ShowIntNum1(5,	110,	value_Year,	2,	BLACK,	WHITE,	32); //显示年
			
			switch(value_WeekDay)
			{
				case 0:	LCD_ShowChinese(101,		110,	"日",	BLACK,	LGRAY,	32,0);  break;//显示那一天
				case 1:	LCD_ShowChinese(101,		110,	"一",	BLACK,	LGRAY,	32,0);  break;//显示那一天
				case 2:	LCD_ShowChinese(101,		110,	"二",	BLACK,	LGRAY,	32,0);  break;//显示那一天
				case 3:	LCD_ShowChinese(101,		110,	"三",	BLACK,	LGRAY,	32,0);  break;//显示那一天
				case 4:	LCD_ShowChinese(101,		110,	"四",	BLACK,	LGRAY,	32,0);  break;//显示那一天
				case 5:	LCD_ShowChinese(101,		110,	"五",	BLACK,	LGRAY,	32,0);  break;//显示那一天
				case 6:	LCD_ShowChinese(101,		110,	"六",	BLACK,	LGRAY,	32,0);  break;//显示那一天
			}
			LCD_ShowChinese(5,		210,	"确定",	BLACK,	WHITE,	24,0); //显示确定
		}
		
		
		if(Number_of_cycles_ == 5 && flag_ == 1)
		{
			flag_ = 0;
			
			switch(value_WeekDay)
			{
				case 0:	LCD_ShowChinese(101,		110,	"日",	BLACK,	WHITE,	32,0);  break;//显示那一天
				case 1:	LCD_ShowChinese(101,		110,	"一",	BLACK,	WHITE,	32,0);  break;//显示那一天
				case 2:	LCD_ShowChinese(101,		110,	"二",	BLACK,	WHITE,	32,0);  break;//显示那一天
				case 3:	LCD_ShowChinese(101,		110,	"三",	BLACK,	WHITE,	32,0);  break;//显示那一天
				case 4:	LCD_ShowChinese(101,		110,	"四",	BLACK,	WHITE,	32,0);  break;//显示那一天
				case 5:	LCD_ShowChinese(101,		110,	"五",	BLACK,	WHITE,	32,0);  break;//显示那一天
				case 6:	LCD_ShowChinese(101,		110,	"六",	BLACK,	WHITE,	32,0);  break;//显示那一天
				case 7:	LCD_ShowChinese(101,		110,	"日",	BLACK,	WHITE,	32,0);  break;//显示那一天
			}
			
			LCD_ShowChinese(5,		210,	"确定",	BLACK,	LGRAY,	24,0); //显示确定
			
			LCD_ShowChinese(85,		210,	"取消",	BLACK,	WHITE,	24,0); //显示删除
		}
		
		
		if(Number_of_cycles_ == 6 && flag_ == 1)
		{
			flag_ = 0;
			
			LCD_ShowChinese(5,		210,	"确定",	BLACK,	WHITE,	24,0); //显示确定
			
			LCD_ShowChinese(85,		210,	"取消",	BLACK,	LGRAY,	24,0); //显示删除
			
			LCD_ShowIntNum1(5,		65,	value_Month,	2,	BLACK,	WHITE,	32); //显示时钟数
		}
		
		
		
		/*************************************
		
		具体功能实现部分
		
		*****************************************/
		
		if(Number_of_cycles_ == 1 && switch_value == Button_2_pressed) //对小时调节的功能进行操作
		{ //value_WeekDay	value_Month		value_Date		value_Year
			while(1)
			{
				switch_value = Get_Key_value(1);
				
				LCD_ShowIntNum1(5,	65,	value_Month,	2,	BLACK,	LGRAYBLUE,	32); //显示月份 //选中以后变成灰蓝色
				
				if(switch_value == Button_1_pressed)
				{								
					value_Month --;									
				}
				if(switch_value == Button_3_pressed)
				{						
					value_Month ++;
				}
				if(value_Month < 1)
				{
					value_Month = 12;
				}
				if(value_Month > 12)
				{
					value_Month = 1;
				}
				if(switch_value == Button_2_pressed)
				{
					LCD_ShowIntNum1(5,	65,	value_Month,	2,	BLACK,	LGRAY,	32); //显示时钟数 //选中以后变成灰蓝色 //把选中之后的颜色改变回来
					
					break;
				}
			}
		}	
		if(Number_of_cycles_ == 2 && switch_value == Button_2_pressed) //对分钟调节的功能进行操作
		{
			while(1)
			{
				switch_value = Get_Key_value(1);
				
				LCD_ShowIntNum1(69,	65,	value_Date,	2,	BLACK,	LGRAYBLUE,	32); //显示分钟 //选中以后变成灰蓝色
				
				if(switch_value == Button_1_pressed)
				{								
					value_Date --;									
				}
				if(switch_value == Button_3_pressed)
				{						
					value_Date ++;
				}
				if(value_Date < 1)
				{
					value_Date = 31;
				}
				if(value_Date > 31)
				{
					value_Date = 1;
				}
				if(switch_value == Button_2_pressed)
				{
					LCD_ShowIntNum1(69,	65,	value_Date,	2,	BLACK,	LGRAY,	32);  //显示时钟数 //选中以后变成灰蓝色 //把选中之后的颜色改变回来
					
					break;
				}
			}
		}	
		
		if(Number_of_cycles_ == 3 && switch_value == Button_2_pressed) //对分钟调节的功能进行操作
		{
			while(1)
			{
				switch_value = Get_Key_value(1);
				
				LCD_ShowIntNum1(69,	65,	value_Year,	2,	BLACK,	LGRAYBLUE,	32); //显示分钟 //选中以后变成灰蓝色
				
				if(switch_value == Button_1_pressed)
				{								
					value_Year --;									
				}
				if(switch_value == Button_3_pressed)
				{						
					value_Year ++;
				}
				if(value_Year < 0)
				{
					value_Year = 99;
				}
				if(value_Year > 99)
				{
					value_Year = 0;
				}
				if(switch_value == Button_2_pressed)
				{
					LCD_ShowIntNum1(69,	65,	value_Year,	2,	BLACK,	LGRAY,	32);  //显示时钟数 //选中以后变成灰蓝色 //把选中之后的颜色改变回来
					
					break;
				}
			}
		}	
		
		
		if(Number_of_cycles_ == 4 && switch_value == Button_2_pressed) //对天数调节的功能进行操作
		{
			while(1)
			{
				switch_value = Get_Key_value(1);
				
				switch(value_WeekDay)
				{
					case 0:	LCD_ShowChinese(101,		110,	"日",	BLACK,	LGRAYBLUE,	32,0);  break;//显示那一天
					case 1:	LCD_ShowChinese(101,		110,	"一",	BLACK,	LGRAYBLUE,	32,0);  break;//显示那一天
					case 2:	LCD_ShowChinese(101,		110,	"二",	BLACK,	LGRAYBLUE,	32,0);  break;//显示那一天
					case 3:	LCD_ShowChinese(101,		110,	"三",	BLACK,	LGRAYBLUE,	32,0);  break;//显示那一天
					case 4:	LCD_ShowChinese(101,		110,	"四",	BLACK,	LGRAYBLUE,	32,0);  break;//显示那一天
					case 5:	LCD_ShowChinese(101,		110,	"五",	BLACK,	LGRAYBLUE,	32,0);  break;//显示那一天
					case 6:	LCD_ShowChinese(101,		110,	"六",	BLACK,	LGRAYBLUE,	32,0);  break;//显示那一天
				}
				
				if(switch_value == Button_1_pressed)
				{								
					value_WeekDay --;									
				}
				if(switch_value == Button_3_pressed)
				{						
					value_WeekDay ++;
				}
				if(value_WeekDay < 1)
				{
					value_WeekDay = 7;
				}
				if(value_WeekDay > 7)
				{
					value_WeekDay = 1;
				}
				if(switch_value == Button_2_pressed)
				{
					switch(value_WeekDay)
					{
						case 1:	LCD_ShowChinese(101,		110,	"一",	BLACK,	LGRAY,	32,0);  break;//显示那一天
						case 2:	LCD_ShowChinese(101,		110,	"二",	BLACK,	LGRAY,	32,0);  break;//显示那一天
						case 3:	LCD_ShowChinese(101,		110,	"三",	BLACK,	LGRAY,	32,0);  break;//显示那一天
						case 4:	LCD_ShowChinese(101,		110,	"四",	BLACK,	LGRAY,	32,0);  break;//显示那一天
						case 5:	LCD_ShowChinese(101,		110,	"五",	BLACK,	LGRAY,	32,0);  break;//显示那一天
						case 6:	LCD_ShowChinese(101,		110,	"六",	BLACK,	LGRAY,	32,0);  break;//显示那一天
						case 7:	LCD_ShowChinese(101,		110,	"日",	BLACK,	LGRAY,	32,0);  break;//显示那一天
					}
					break;
				}
			}
		}	
		if(Number_of_cycles_ == 5 && switch_value == Button_2_pressed) //结束此功能的设置，跳出循环，回到闹钟的界面
		{
			sDate.WeekDay = value_WeekDay;
			
			sDate.Month = value_Month;
			
			sDate.Date = value_Date;
			
			sDate.Year = value_Year;

			if (HAL_RTC_SetDate(&hrtc, &sDate, RTC_FORMAT_BIN) != HAL_OK)
			{
				Error_Handler();
			}

			break; //退出
		}	
		if(Number_of_cycles_ == 6 && switch_value == Button_2_pressed)  //结束此功能的设置，跳出循环，回到闹钟的界面
		{	
		 //退出训话之后会回到开始的地方
		
			break;
		}		
	}
}


/*******************************************
* @function: 	设置声音开关的功能
* @input:			无
* @return:		无
* @author:		田小花
* @time:			2020.10.24
*******************************************/

unsigned char Sound_switch = 1; //声音默认是打开的

void set_sound_function(void)
{
	unsigned char switch_value = 0;
	
	unsigned char Number_of_cycles_ = 1;
	
	unsigned char flag_ = 0;

	
	LCD_Fill(0,		0,		LCD_W,	LCD_H,	WHITE); //显示界面成白色刷新
			
	if( Sound_switch )
	{
		LCD_ShowPicture(32,		60,		70,		70,	gImage_sound);
	}
	else
	{
		LCD_ShowPicture(32,		60,		69,		70,	gImage_nosound);
	}
		
	LCD_ShowChinese(5,		210,	"确定",	BLACK,	WHITE,	24,0); //显示确定
	
	LCD_ShowChinese(85,		210,	"取消",	BLACK,	WHITE,	24,0); //显示删除
	
	/*************************************
		
	进入主要的功能实现主循环
		
	*****************************************/
	while(1)
	{
		switch_value = Get_Key_value(1); //检测按键
		
		if(switch_value == Button_1_pressed)// 上下调节选择时间或者日期
		{
			Number_of_cycles_--;
			
			flag_ = 1;
			
			if(Number_of_cycles_<1)
			{
				Number_of_cycles_ = 3;
			}
		}
		
		if(switch_value == Button_3_pressed)// // 上下调节选择时间或者日期
		{
			Number_of_cycles_++;
			
			flag_ = 1;
			
			if(Number_of_cycles_>3)
			{
				Number_of_cycles_ = 1;
			}
		}

		
		/*************************************
		
		显示部分
		
		*****************************************/
		if(Number_of_cycles_ == 1 && flag_ == 1)
		{
			flag_ = 0;
			
			LCD_ShowChinese(85,		210,	"取消",	BLACK,	WHITE,	24,0); //显示删除
			
			LCD_ShowChinese(5,		210,	"确定",	BLACK,	WHITE,	24,0); //显示确定
			
		}
		if(Number_of_cycles_ == 2 && flag_ == 1)
		{
			flag_ = 0;
			
			LCD_ShowChinese(5,		210,	"确定",	BLACK,	LGRAY,	24,0); //显示确定
			
			LCD_ShowChinese(85,		210,	"取消",	BLACK,	WHITE,	24,0); //显示删除			
		}
		if(Number_of_cycles_ == 3 && flag_ == 1)
		{
			flag_ = 0;
			
			LCD_ShowChinese(5,		210,	"确定",	BLACK,	WHITE ,	24,0); //显示确定
			
			LCD_ShowChinese(85,		210,	"取消",	BLACK,	LGRAY ,	24,0); //显示删除
		}
		
		
		/*************************************
		
		对功能实现的具体操作
		
		*****************************************/
		if(Number_of_cycles_ == 1 && switch_value == Button_2_pressed) //对小时调节的功能进行操作
		{
			Sound_switch =! Sound_switch;
			
			if( Sound_switch )
			{
				LCD_ShowPicture(32,		60,		70,		70,	gImage_sound);	
			}
			else
			{
				LCD_ShowPicture(32,		60,		69,		70,	gImage_nosound);
			}
		}	
		if(Number_of_cycles_ == 2 && switch_value == Button_2_pressed) //对分钟调节的功能进行操作
		{
			//退出循环之后会回到开始的地方
			break;
		}	
		if(Number_of_cycles_ == 3 && switch_value == Button_2_pressed) //结束此功能的设置，跳出循环，回到闹钟的界面
		{
			break; //退出
		}	
		
	}
}

/*******************************************
* @function: 	初始化设置界面的屏幕
* @input:			无
* @return:		无
* @author:		田小花
* @time:			2020.10.3
*******************************************/
void setting_function_init_display(void)
{
	LCD_Fill(0,0,LCD_W,LCD_H,BLACK); //电池里面的填充

	printf("进入了闹钟app\r\n");
	
	LCD_Fill(0,0,LCD_W,LCD_H,WHITE); //显示界面成白色刷新
	
//	LCD_Fill(0,		0,LCD_W,30,LGRAY); //显示界面成灰色刷新
		
	LCD_Fill(0,	30,	LCD_W,	31,	BLACK); //画线		
	
	LCD_Fill(0,	60,	LCD_W,	61,	BLACK); //画线			
	
	LCD_Fill(0,	90,	LCD_W,	91,	BLACK); //画线			
	
	LCD_Fill(0,	120,	LCD_W,	121,	BLACK); //画线			
	
	LCD_Fill(0,	150,	LCD_W,	151,	BLACK); //画线			
	
	LCD_Fill(0,	180,	LCD_W,	181,	BLACK); //画线			
	
	LCD_Fill(0,	210,	LCD_W,	211,	BLACK); //画线
				
	
	
	LCD_ShowChinese(0,		3,		"返回",			BLACK,	WHITE,24,0);
	LCD_ShowChinese(0,		33,		"设置时间",	BLACK,	WHITE,24,0);
	LCD_ShowChinese(0,		63,		"设置日期",	BLACK,	WHITE,24,0);
	LCD_ShowChinese(0,		93,		"声音",			BLACK,	WHITE,24,0);
	LCD_ShowChinese(0,		123,	"计步器",		BLACK,	WHITE,24,0);
	LCD_ShowChinese(0,		153,	"灯光",			BLACK,	WHITE,24,0);
	LCD_ShowChinese(0,		183,	"背光调节",	BLACK,	WHITE,24,0);

}


/*******************************************
* @function: 	设置的功能
* @input:			无
* @return:		无
* @author:		田小花
* @time:			2020.10.3
*******************************************/
void setting_function(void)
{
//	static unsigned char Number_of_cycles = function_clock;
	
	unsigned char switch_value;
		
	static unsigned char flag__ = 0;
	
	static unsigned char Number_of_cycles = 1;
	
	flag__ = 1; //限制屏幕刷新
	
	setting_function_init_display(); //初始化设置界面的屏幕
	
	while(1)
	{
		switch_value = Get_Key_value(1);
		
		if(switch_value == Button_3_pressed)
		{
			Number_of_cycles++;
			
			flag__ = 1; //限制屏幕刷新
			
			if(Number_of_cycles>8)
			{
				Number_of_cycles = 1;
			}
		}
		
		if(switch_value == Button_1_pressed)
		{
			Number_of_cycles--;
			
			flag__ = 1; //限制屏幕刷新
			
			if(Number_of_cycles<1)
			{
				Number_of_cycles = 8;
			}
		}
		
		/*************************************
		
		显示部分
		
		*****************************************/
		if(Number_of_cycles == 1 && flag__ == 1)
		{
			flag__ = 0; //限制屏幕刷新
			
			LCD_Fill(0,		211,LCD_W,240,WHITE); //显示界面成灰色刷新
			
			LCD_Fill(0,		0,LCD_W,30,LGRAY); //显示界面成灰色刷新
			
			LCD_ShowChinese(0,		3,	"返回",	BLACK,	LGRAY,24,0);
			
			LCD_Fill(0,		31,LCD_W,60,WHITE); //显示界面成灰色刷新
			
			LCD_ShowChinese(0,		33,	"设置时间",	BLACK,	WHITE,24,0);
		}
		if(Number_of_cycles == 2 && flag__ == 1)
		{
			flag__ = 0; //限制屏幕刷新
														
			LCD_Fill(0,		0,LCD_W,30,WHITE); //显示界面成灰色刷新
			
			LCD_ShowChinese(0,		3,	"返回",	BLACK,	WHITE,24,0);
			
			LCD_Fill(0,		31,LCD_W,60,LGRAY); //显示界面成灰色刷新	
			
			LCD_ShowChinese(0,		33,	"设置时间",	BLACK,	LGRAY,24,0);
			
			LCD_Fill(0,		61,LCD_W,90,WHITE); //显示界面成灰色刷新
			
			LCD_ShowChinese(0,		63,"设置日期",	BLACK,	WHITE,24,0);
		}

		if(Number_of_cycles == 3 && flag__ == 1)
		{
			flag__ = 0; //限制屏幕刷新

			LCD_Fill(0,		31,LCD_W,60,WHITE); //显示界面成灰色刷新
			
			LCD_ShowChinese(0,		33,"设置时间",	BLACK,	WHITE,24,0);
			
			LCD_Fill(0,		61,LCD_W,90,LGRAY); //显示界面成灰色刷新
			
			LCD_ShowChinese(0,		63,	"设置日期",	BLACK,	LGRAY,24,0);
			
			LCD_Fill(0,		91,LCD_W,120,WHITE); //显示界面成灰色刷新
			
			LCD_ShowChinese(0,		93,	"声音",	BLACK,	WHITE,24,0);
		}
		
		if(Number_of_cycles == 4 && flag__ == 1)
		{
			flag__ = 0; //限制屏幕刷新
			
			LCD_Fill(0,		61,LCD_W,90,WHITE); //显示界面成灰色刷新
			
			LCD_ShowChinese(0,		63,	"设置日期",	BLACK,	WHITE,24,0);
			
			LCD_Fill(0,		91,LCD_W,120,LGRAY); //显示界面成灰色刷新
			
			LCD_ShowChinese(0,		93,	"声音",	BLACK,	LGRAY,24,0);
			
			LCD_Fill(0,		121,LCD_W,150,WHITE); //显示界面成灰色刷新
			
			LCD_ShowChinese(0,		123,	"计步器",	BLACK,	WHITE,24,0);
		}
		
		if(Number_of_cycles == 5 && flag__ == 1)
		{
			flag__ = 0; //限制屏幕刷新
			
			LCD_Fill(0,		91,LCD_W,120,WHITE); //显示界面成灰色刷新
			
			LCD_ShowChinese(0,		93,	"声音",	BLACK,	WHITE,24,0);
			
			LCD_Fill(0,		121,LCD_W,150,LGRAY); //显示界面成灰色刷新
			
			LCD_ShowChinese(0,		123,	"计步器",	BLACK,	LGRAY,24,0);
			
			LCD_Fill(0,		151,LCD_W,180,WHITE); //显示界面成灰色刷新
			
			LCD_ShowChinese(0,		153,	"灯光",	BLACK,	WHITE,24,0);
		}
		
		if(Number_of_cycles == 6 && flag__ == 1)
		{
			flag__ = 0; //限制屏幕刷新
			
			LCD_Fill(0,		121,LCD_W,150,WHITE); //显示界面成灰色刷新
			
			LCD_ShowChinese(0,		123,	"计步器",	BLACK,	WHITE,24,0);
			
			LCD_Fill(0,		151,LCD_W,180,LGRAY); //显示界面成灰色刷新
			
			LCD_ShowChinese(0,		153,	"灯光",	BLACK,	LGRAY,24,0);
			
			LCD_Fill(0,		181,LCD_W,210,WHITE); //显示界面成灰色刷新
			
			LCD_ShowChinese(0,		183,	"背光调节",	BLACK,	WHITE,24,0);
		}
		
		if(Number_of_cycles == 7 && flag__ == 1)
		{
			flag__ = 0; //限制屏幕刷新
			
			LCD_Fill(0,		151,LCD_W,180,WHITE); //显示界面成灰色刷新
			
			LCD_ShowChinese(0,		153,	"灯光",	BLACK,	WHITE,24,0);
			
			LCD_Fill(0,		181,LCD_W,210,LGRAY); //显示界面成灰色刷新
			
			LCD_ShowChinese(0,		183,	"背光调节",	BLACK,	LGRAY,24,0);
			
			LCD_Fill(0,		211,LCD_W,240,WHITE); //显示界面成灰色刷新
			
		}
		
		if(Number_of_cycles == 8 && flag__ == 1)
		{
			flag__ = 0; //限制屏幕刷新
			
			LCD_Fill(0,		181,LCD_W,210,WHITE); //显示界面成灰色刷新
			
			LCD_ShowChinese(0,		183,	"背光调节",	BLACK,	WHITE,24,0);
			
			LCD_Fill(0,		211,LCD_W,240,LGRAY); //显示界面成灰色刷新
			
//			LCD_ShowChinese(0,		213,	"新建",	BLACK,	LGRAY,24,0);
		}
		
		/*************************************
		
		对功能实现的具体操作
		
		*****************************************/
		
		if(switch_value == Button_2_pressed && Number_of_cycles == 1)
		{
			Number_of_cycles = 1;
			
			break;	
		}
		
		if(switch_value == Button_2_pressed && Number_of_cycles == 2) //设置时间功能选择
		{
			
			set_time_function(); //设置时间的具体功能和界面
			
			setting_function_init_display(); //重新把显示界面显示到设置界面的一开始界面
			
			Number_of_cycles = 2; 
			
			flag__ = 1;
			
			
		}
		
		if(switch_value == Button_2_pressed && Number_of_cycles == 3)
		{
			set_data_function();
			
			setting_function_init_display(); //重新把显示界面显示到设置界面的一开始界面
			
			Number_of_cycles = 3;
			
			flag__ = 1;
			
			
			
		}
		
		if(switch_value == Button_2_pressed && Number_of_cycles == 4)
		{
			set_sound_function();
			
			setting_function_init_display(); //重新把显示界面显示到设置界面的一开始界面
			
			Number_of_cycles = 4;
			
			flag__ = 1;
			
			
		}
	}
}



/*******************************************
* @function: 	后台对闹钟和陀螺仪的计步器进行检测
* @input:			无
* @return:		无
* @author:		田小花
* @time:			2020.10.5
*******************************************/


void Background_detection(unsigned char switch_value)
{
	unsigned char i = 0;
	
	static unsigned char stata = 0;
		
	static unsigned char Detection_status = 1;
	
	//printf(" %d  %d  %d   \r\n",clock_time_hour[0],clock_time_min[0],clock_Data[i]);
	
	for(	i=0;	i<7;	i++	)
	{	
		//检测每天都有的闹钟
		if(clock_Data[i] == 0)
		{
			if(	sTime.Hours ==	clock_time_hour[i]  &&  sTime.Minutes ==	clock_time_min[i]	) //检测是否对应上了时间
			{
				if(	Detection_status == 1	)
				{
					stata = 1;
				}
			}
			else
			{
				Detection_status = 1;	//检测到没有到达闹钟的时间
			}
		}
		//检测周几有闹钟
		if(clock_Data[i] == sDate.WeekDay)
		{
			if(sTime.Hours ==	clock_time_hour[i]  &&  sTime.Minutes ==	clock_time_min[i]) //检测是否对应上了时间
			{
				if(	Detection_status == 1	)
				{
					stata = 1;
				}
			}
			else
			{
				Detection_status = 1;	//检测到没有到达闹钟的时间
			}
		}
		
	} //for循环结束
	

	//检测到按键输入就关闭闹钟的鸣叫
	if(	switch_value == Button_2_pressed || switch_value == Button_1_pressed	||	switch_value == Button_3_pressed	) //按下任意一个按键都会停止闹钟
	{
		stata = 0; //关闭闹钟
		
		Detection_status = 0;
	
		__HAL_TIM_SET_COMPARE(	&htim2, TIM_CHANNEL_4, 70	); //设置PWM的占空比，调节背光 //正常
		
		HAL_GPIO_WritePin(	LED_GPIO_Port, LED_Pin, GPIO_PIN_SET	);	//检测到闹钟之后会闪烁LED //关闭LED
		
		__HAL_TIM_SET_COMPARE(	&htim4, TIM_CHANNEL_4, 0	); ////让蜂鸣器停止鸣叫
	}
	
	//检测到了闹钟规定的时间
	if(	stata == 1	)
	{
		if(	Total_cycle == 25	) //Total_cycle在总循环中的计数值，从0到100循环递减，大约在800毫秒左右循环一次
		{
			HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_RESET);	//检测到闹钟之后会闪烁LED
			
			__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_4, 600); //设置PWM的占空比，调节背光 //高亮
			
			__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_4, 0); //让蜂鸣器停止鸣叫
			
		}
		if(	Total_cycle == 75	) //Total_cycle在总循环中的计数值，从0到100循环递减，大约在800毫秒左右循环一次
		{
			HAL_GPIO_WritePin(	LED_GPIO_Port, LED_Pin, GPIO_PIN_SET	);	//检测到闹钟之后会闪烁LED
			
			__HAL_TIM_SET_COMPARE(	&htim2, TIM_CHANNEL_4, 70	); //设置PWM的占空比，调节背光
			
			__HAL_TIM_SET_COMPARE(	&htim4, TIM_CHANNEL_4, 50	); //让蜂鸣器鸣叫
		}
	}
}


























