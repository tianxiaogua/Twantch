
#include "stdio.h"

#include "display.h"

#include "main.h"
#include "adc.h"
#include "dma.h"
#include "i2c.h"

#include "spi.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

#include "lcd.h"
#include "lcd_init.h"
#include "pic.h"

#include "contro.h"

#include "app.h"

	
/*******************************************
* @function: 	在显示屏幕上显示主界面
* @input:			无
* @return:		返回三个按键代表的三个值
* @author:		田小花
* @time:			2020.10.2
*******************************************/
void MENU_init_(void)
{
	//LCD_ShowPicture(0,		0,		13,		15,	gImage_clock);
	
	//LCD_ShowPicture(20,		0,		13,		15,	gImage_play);
	
	LCD_ShowPicture(0,		0,		13,		15,	gImage_play);
	
	LCD_ShowPicture(106,	0,		27,		15,	gImage_power);
	
	LCD_ShowChinese(17+32,		190+24,	"℃",	WHITE,	BLACK,	16,	0);
	
	LCD_ShowString (19+32+24+32,		190+24,	"%",	WHITE,	BLACK,	16,	0); //显示百分号
	
	//把计步器的步数显示在主屏幕上面
	if(	STEPS	>	9999	)
	{
		LCD_ShowIntNum (20,		0,	STEPS,	5,	WHITE,	BLACK,	16); //显示步数
	}
	else if(	STEPS	>	999	)
	{
		LCD_ShowIntNum (20,		0,	STEPS,	4,	WHITE,	BLACK,	16); //显示步数
	}
	else if(	STEPS	>	99	)
	{
		LCD_ShowIntNum (20,		0,	STEPS,	3,	WHITE,	BLACK,	16); //显示步数
	}
	else if(	STEPS	>	9	)	
	{
		LCD_ShowIntNum (20,		0,	STEPS,	2,	WHITE,	BLACK,	16); //显示步数
	}
	else
	{
		LCD_ShowIntNum (20,		0,	STEPS,	1,	WHITE,	BLACK,	16); //显示步数
	}
}



/*******************************************
* @function: 	在显示屏幕上显示主界面
* @input:			无
* @return:		返回三个按键代表的三个值
* @author:		田小花
* @time:			2020.10.2
*******************************************/
void MENU_init(void)
{
	LCD_Init();//LCD初始化
	
	LCD_Fill(0,0,LCD_W,LCD_H,BLACK);
	
	MENU_init_();
}
	


/*******************************************
* @function: 	在显示屏幕上显示主界面
* @input:			无
* @return:		返回三个按键代表的三个值
* @author:		田小花
* @time:			2020.10.2
*******************************************/
static unsigned char history_time[6] = {100,100,100,100,100,100}; //保存时间的历史数据

static unsigned char history_temperature ;

static unsigned char history_humidity;

unsigned long	history_STEPS = 0; //步数

static	unsigned char Battery_display_flag ;

char Total_cycle = 0;

void MENU_main(void)
{
	/*用来产生一个延时，主循环循环一百次的时间大约为一秒，小于一秒*/
	Total_cycle--;
		
	if(Total_cycle == 0)
	{
		Total_cycle = 100;
	}
		
	if(history_time[0] != sTime.Hours)
	{
		switch(sTime.Hours/10)
		{
			case  0: LCD_ShowPicture(28,		50,		40,		49,	gImage_a0);	break; //40*49
			case  1: LCD_ShowPicture(28,		50,		39,		50,	gImage_a1);	break; //39*50
			case  2: LCD_ShowPicture(28,		50,		39,		50,	gImage_a2);	break; //39*50
			default:  LCD_ShowPicture(28,		50,		40,		49,	gImage_a0);
		}
		
		switch(sTime.Hours%10)
		{
			case  0: LCD_ShowPicture(68,		50,		40,		49,	gImage_a0);	break; //40*49
			case  1: LCD_ShowPicture(68,		50,		39,		50,	gImage_a1);	break; //39*50
			case  2: LCD_ShowPicture(68,		50,		39,		50,	gImage_a2);	break; //39*50
			case  3: LCD_ShowPicture(68,		50,		40,		49,	gImage_a3);	break; //40*49
			case  4: LCD_ShowPicture(68,		50,		40,		49,	gImage_a4);	break; //40*49
			case  5: LCD_ShowPicture(68,		50,		40,		50,	gImage_a5);	break; //40*50
			case  6: LCD_ShowPicture(68,		50,		39,		50,	gImage_a6);	break; //39*50
			case  7: LCD_ShowPicture(68,		50,		40,		49,	gImage_a7);	break; //40*49
			case  8: LCD_ShowPicture(68,		50,		40,		50,	gImage_a8);	break; //40*50
			case  9: LCD_ShowPicture(68,		50,		39,		50,	gImage_a9);	break; //39*50
			default:  LCD_ShowPicture(68,		50,		40,		49,	gImage_a0);
		}
	}

	if(history_time[1] != sTime.Minutes)
	{
		switch(sTime.Minutes/10)
		{
			case  0: LCD_ShowPicture(0,		120,	40,		50,	gImage_c0);	break; //40*50
			case  1: LCD_ShowPicture(0,		120,	40,		49,	gImage_c1);	break; //40*49
			case  2: LCD_ShowPicture(0,		120,	40,		49,	gImage_c2);	break;  //40*49
			case  3: LCD_ShowPicture(0,		120,	39,		50,	gImage_c3);	break;  //39*50
			case  4: LCD_ShowPicture(0,		120,	39,		50,	gImage_c4);	break;  //39*50
			case  5: LCD_ShowPicture(0,		120,	39,		50,	gImage_c5);	break;  //39*50
			case  6: LCD_ShowPicture(0,		120,	40,		49,	gImage_c6);	break;  //40*49
			case  7: LCD_ShowPicture(0,		120,	40,		50,	gImage_c7);	break;  //40*50
			case  8: LCD_ShowPicture(0,		120,	40,		49,	gImage_c8);	break;  //40*49
			case  9: LCD_ShowPicture(0,		120,	39,		49,	gImage_c9);	break;  //39*49
			default:  LCD_ShowPicture(0,		120,	40,		50,	gImage_c1); //40*50
		}
		
		switch(sTime.Minutes%10)
		{
			case  0: LCD_ShowPicture(40,		120,	40,		50,	gImage_c0);	break; //40*50
			case  1: LCD_ShowPicture(40,		120,	40,		49,	gImage_c1);	break; //40*49
			case  2: LCD_ShowPicture(40,		120,	40,		49,	gImage_c2);	break; //40*49
			case  3: LCD_ShowPicture(40,		120,	39,		50,	gImage_c3);	break; //39*50
			case  4: LCD_ShowPicture(40,		120,	39,		50,	gImage_c4);	break; //39*50
			case  5: LCD_ShowPicture(40,		120,	39,		50,	gImage_c5);	break; //39*50
			case  6: LCD_ShowPicture(40,		120,	40,		49,	gImage_c6);	break; //40*49
			case  7: LCD_ShowPicture(40,		120,	40,		50,	gImage_c7);	break; //40*50
			case  8: LCD_ShowPicture(40,		120,	40,		49,	gImage_c8);	break; //40*49
			case  9: LCD_ShowPicture(40,		120,	39,		50,	gImage_c9);	break; //39*50 
			default:  LCD_ShowPicture(40,		120,	40,		50,	gImage_c0); //40*50
		}
	}

	if(history_time[2] != sDate.Month)
	{
		LCD_ShowIntNum1(65,		190,	sDate.Month,	2,	WHITE,	BLACK,	16); //显示月份
	}
		
	if(history_time[3] != sDate.Date)
	{
		LCD_ShowString (81,		190,	"/",							WHITE,	BLACK,	16,	0); //显示斜杆
		
		LCD_ShowIntNum1(89,		190,	sDate.Date,		2,	WHITE,	BLACK,	16); //显示日期
	}

	if(history_time[4] != sTime.Seconds)
	{
		LCD_ShowIntNum1 (85,		120,	sTime.Seconds,	2,	WHITE,	BLACK,	32); //显示秒钟数字
	}

	if(history_time[5] != sDate.WeekDay)
	{
		if(sDate.WeekDay == RTC_WEEKDAY_MONDAY) 		LCD_ShowChinese(26,		190,	"周一",WHITE,BLACK,16,0);
		if(sDate.WeekDay == RTC_WEEKDAY_TUESDAY) 		LCD_ShowChinese(26,		190,	"周二",WHITE,BLACK,16,0);
		if(sDate.WeekDay == RTC_WEEKDAY_WEDNESDAY) 	LCD_ShowChinese(26,		190,	"周三",WHITE,BLACK,16,0);
		if(sDate.WeekDay == RTC_WEEKDAY_THURSDAY) 	LCD_ShowChinese(26,		190,	"周四",WHITE,BLACK,16,0);
		if(sDate.WeekDay == RTC_WEEKDAY_FRIDAY) 		LCD_ShowChinese(26,		190,	"周五",WHITE,BLACK,16,0);
		if(sDate.WeekDay == RTC_WEEKDAY_SATURDAY) 	LCD_ShowChinese(26,		190,	"周六",WHITE,BLACK,16,0);
		if(sDate.WeekDay == RTC_WEEKDAY_SUNDAY) 		LCD_ShowChinese(26,		190,	"周日",WHITE,BLACK,16,0);
	}
	
	if(	history_temperature != temperature || history_humidity != humidity	)
	{
			LCD_ShowFloatNum(15,		190+24,	temperature,	3,	WHITE,	BLACK,	16); //显示温度
	
			//LCD_ShowChinese(17+32,		190+24,	"℃",	WHITE,	BLACK,	16,	0);
	
			LCD_ShowFloatNum(19+32+24,		190+24,	humidity,		3,	WHITE,	BLACK,	16); //显示湿度
	
			//LCD_ShowString (19+32+24+32,		190+24,	"%",	WHITE,	BLACK,	16,	0); //显示百分号	
	}
	
	//把计步器的步数显示在主屏幕上面
	if(	history_STEPS != STEPS)
	{
		if(	STEPS	>	9999	)
		{
			LCD_ShowIntNum (20,		0,	STEPS,	5,	WHITE,	BLACK,	16); //显示步数
		}
		else if(	STEPS	>	999	)
		{
			LCD_ShowIntNum (20,		0,	STEPS,	4,	WHITE,	BLACK,	16); //显示步数
		}
		else if(	STEPS	>	99	)
		{
			LCD_ShowIntNum (20,		0,	STEPS,	3,	WHITE,	BLACK,	16); //显示步数
		}
		else if(	STEPS	>	9	)	
		{
			LCD_ShowIntNum (20,		0,	STEPS,	2,	WHITE,	BLACK,	16); //显示步数
		}
		else
		{
			LCD_ShowIntNum (20,		0,	STEPS,	1,	WHITE,	BLACK,	16); //显示步数
		}
	}
	
	
	history_time[0] = sTime.Hours;

	history_time[1] = sTime.Minutes;

	history_time[2] = sDate.Month;

	history_time[3] = sDate.Date;

	history_time[4] = sTime.Seconds;	

	history_time[5] = sDate.WeekDay;

	history_temperature = temperature;
	
	history_humidity = humidity;
	
	history_STEPS = STEPS;
	
	if(	USB_in_sign == Not_connected	)
	{
//		printf("没有设备连接 \t");
		if(Battery_voltage>90)
		{
			if(	Battery_display_flag != 9	)
			{
				LCD_Fill(	110,4,110+17,11,WHITE); //电池里面的填充	
			}
			Battery_display_flag = 9;
		}
		if(Battery_voltage<90 && Battery_voltage>80)
		{
			if(Battery_display_flag != 8)
			{
				LCD_Fill(110,4,110+17-2,11,WHITE); //电池里面的填充	
				
				LCD_Fill(110+17-2,4,110+17,11,BLACK); //电池里面的填充	
			}
			Battery_display_flag = 8;
		}
		if(Battery_voltage<80 && Battery_voltage>70)
		{
			if(Battery_display_flag != 7)
			{
				LCD_Fill(110,4,110+17-4,11,WHITE); //电池里面的填充	
				
				LCD_Fill(110+17-4,4,110+17,11,BLACK); //电池里面的填充	
			}
			Battery_display_flag = 7;
		}
		if(Battery_voltage<70 && Battery_voltage>60)
		{
			if(Battery_display_flag != 6)
			{
				LCD_Fill(110,4,110+17-6,11,WHITE); //电池里面的填充	
				
				LCD_Fill(110+17-6,4,110+17,11,BLACK); //电池里面的填充	
			}
			Battery_display_flag = 6;
		}
		if(Battery_voltage<60 && Battery_voltage>50)
		{
			if(Battery_display_flag != 5)
			{
				LCD_Fill(110,4,110+17-8,11,WHITE); //电池里面的填充	
				
				LCD_Fill(110+17-8,4,110+17,11,BLACK); //电池里面的填充	
			}
			Battery_display_flag = 5;
		}
		if(Battery_voltage<50 && Battery_voltage>40)
		{
			if(Battery_display_flag != 4)
			{
				LCD_Fill(110,4,110+17-10,11,WHITE); //电池里面的填充	
				
				LCD_Fill(110+17-10,4,110+17,11,BLACK); //电池里面的填充	
			}
			Battery_display_flag = 4;
		}
		if(Battery_voltage<40 && Battery_voltage>30)
		{
			if(Battery_display_flag != 3)
			{
				LCD_Fill(110,4,110+17-12,11,WHITE); //电池里面的填充	
				
				LCD_Fill(110+17-12,4,110+17,11,BLACK); //电池里面的填充	
			}
			Battery_display_flag = 3;
		}
		if(Battery_voltage<30 && Battery_voltage>20)
		{
			if(Battery_display_flag != 2)
			{
				LCD_Fill(110,4,110+17-14,11,WHITE); //电池里面的填充	
				
				LCD_Fill(110+17-14,4,110+17,11,BLACK); //电池里面的填充	
			}
			Battery_display_flag = 2;
		}
		if(Battery_voltage<20 && Battery_voltage>10)
		{
			if(Battery_display_flag != 1)
			{
				LCD_Fill(110,4,110+17-16,11,WHITE); //电池里面的填充	
				
				LCD_Fill(110+17-16,4,110+17,11,BLACK); //电池里面的填充	
			}
			Battery_display_flag = 1;
		}
		if(Battery_voltage<10)
		{
			if(Battery_display_flag != 0)
			{
				LCD_Fill(110,4,110+17-17,11,WHITE); //电池里面的填充	
				
				LCD_Fill(110+17-17,4,110+17,11,BLACK); //电池里面的填充	
			}
			Battery_display_flag = 0;
		}
	}
	if(USB_in_sign == Connected)
	{
//		printf("有usb输出并且 完成了一次循环 %d \t",Total_cycle);
		
		Battery_display_flag = 100;
		// /
		if(Total_cycle<8)
		{
			LCD_Fill(110,4,110+17,11,WHITE); //电池里面的填充	
		}
		if(Total_cycle<16 && Total_cycle>8)
		{
			LCD_Fill(110,4,110+17-2,11,WHITE); //电池里面的填充	
				
			LCD_Fill(110+17-2,4,110+17,11,BLACK); //电池里面的填充	
		}
		if(Total_cycle<24 && Total_cycle>16)
		{
			LCD_Fill(110,4,110+17-4,11,WHITE); //电池里面的填充	
				
			LCD_Fill(110+17-4,4,110+17,11,BLACK); //电池里面的填充	
		}
		if(Total_cycle<32 && Total_cycle>24)
		{
			LCD_Fill(110,4,110+17-6,11,WHITE); //电池里面的填充	
				
			LCD_Fill(110+17-6,4,110+17,11,BLACK); //电池里面的填充	
		}
		if(Total_cycle<40 && Total_cycle>32)
		{
			LCD_Fill(110,4,110+17-8,11,WHITE); //电池里面的填充	
				
			LCD_Fill(110+17-8,4,110+17,11,BLACK); //电池里面的填充	
		}
		if(Total_cycle<48 && Total_cycle>40)
		{
			LCD_Fill(110,4,110+17-10,11,WHITE); //电池里面的填充	
				
			LCD_Fill(110+17-10,4,110+17,11,BLACK); //电池里面的填充	
		}
		if(Total_cycle<56 && Total_cycle>48)
		{
			LCD_Fill(110,4,110+17-12,11,WHITE); //电池里面的填充	
				
			LCD_Fill(110+17-12,4,110+17,11,BLACK); //电池里面的填充
		}
		if(Total_cycle<64 && Total_cycle>56)
		{
			LCD_Fill(110,4,110+17-14,11,WHITE); //电池里面的填充	
				
			LCD_Fill(110+17-14,4,110+17,11,BLACK); //电池里面的填充	
		}
		if(Total_cycle<72 && Total_cycle>64)
		{
			LCD_Fill(110,4,110+17-16,11,WHITE); //电池里面的填充	
				
			LCD_Fill(110+17-16,4,110+17,11,BLACK); //电池里面的填充	
		}
		if(Total_cycle<80 && Total_cycle>72)
		{
			LCD_Fill(110,4,110+17-17,11,WHITE); //电池里面的填充	
				
			LCD_Fill(110+17-17,4,110+17,11,BLACK); //电池里面的填充	
		}
	}
}

/*******************************************
* @function: 	在显示屏幕上显示设置界面
* @input:			无
* @return:		无
* @author:		田小花
* @time:			2020.10.2
*******************************************/
void MENU_SETTING(void )
{

		LCD_Fill(0,0,LCD_W,LCD_H,WHITE); //电池里面的填充	
		
		LCD_ShowPicture(18,		50,		100,		100,	gImage_setting); //40*49
		
		LCD_ShowChinese(42,		170,	"设置",	LBBLUE,	WHITE,24,0);
}

/*******************************************
* @function: 	在显示屏幕上显示手电筒界面
* @input:			无
* @return:		无
* @author:		田小花
* @time:			2020.10.2
*******************************************/
void MENU_light(void )
{

		LCD_Fill(0,0,LCD_W,LCD_H,WHITE); //电池里面的填充	
		
		LCD_ShowPicture(18,		50,		100,		100,	gImage_light); //40*49
		
		LCD_ShowChinese(42,		170,	"照明",	LGRAY,	WHITE,24,0);
}

/*******************************************
* @function: 	在显示屏幕上显示闹钟
* @input:			无
* @return:		无
* @author:		田小花
* @time:			2020.10.2
*******************************************/
void MENU_clock(void )
{

		LCD_Fill(0,0,LCD_W,LCD_H,WHITE); //电池里面的填充	
		
		LCD_ShowPicture(18,		50,		100,		100,	gImage_P_clock); //40*49
		
		LCD_ShowChinese(42,		170,	"闹钟",	BRRED,	WHITE,24,0);
}


/*******************************************
* @function: 	在显示屏幕上显示游戏
* @input:			无
* @return:		无
* @author:		田小花
* @time:			2020.10.2
*******************************************/
void MENU_Game(void )
{

		LCD_Fill(0,0,LCD_W,LCD_H,WHITE); //电池里面的填充	
		
		LCD_ShowPicture(18,		50,		100,		100,	gImage_game); //40*49
		
		LCD_ShowChinese(42,		170,	"游戏",	MAGENTA,	WHITE,24,0);
}

/*******************************************
* @function: 	在显示屏幕上显示退出
* @input:			无
* @return:		无
* @author:		田小花
* @time:			2020.10.2
*******************************************/
void MENU_quit(void )
{

		LCD_Fill(0,0,LCD_W,LCD_H,WHITE); //电池里面的填充	
		
		LCD_ShowPicture(18,		50,		100,		100,	gImage_quit); //40*49
		
		LCD_ShowChinese(42,		170,	"返回",	MAGENTA,	WHITE,24,0);
}

/*******************************************
* @function: 	在显示屏幕上显示主界面
* @input:			无
* @return:		返回三个按键代表的三个值
* @author:		田小花
* @time:			2020.10.2
*******************************************/
void Refresh(void)
{
	unsigned char i;
	
	for (i=0;i<6;i++)
	{
		history_time[i] = 100;
	}
	
	Battery_display_flag = 100;
	
	MENU_init_();
	
	MENU_main();
}

/*******************************************
* @function: 	在显示屏幕上显示主界面
* @input:			无
* @return:		返回三个按键代表的三个值
* @author:		田小花
* @time:			2020.10.2
*******************************************/
void MENU_APP(unsigned char switch_value)
{
	static unsigned char Number_of_cycles = function_clock;
	
	static unsigned char flag = 0;
	
//	static unsigned char flag__ = 0;
	
//	unsigned char i = 1;
	
	if(switch_value == Button_3_pressed || switch_value == Button_1_pressed)
	{

		flag = 1; //为了防止无用的屏幕刷新进行显示界面的刷新次数控制 //只有在按键按下之后有具体操作了才会刷新
		
		Number_of_cycles = function_clock;
		
		while(1)
		{
			switch_value = Get_Key_value(1);

			if(switch_value == Button_3_pressed) //下面的按键
			{
				Number_of_cycles++;
				
				flag = 1; //为了防止无用的屏幕刷新进行显示界面的刷新次数控制 //只有在按键按下之后有具体操作了才会刷新
				
				if(Number_of_cycles > 5)
				{
					Number_of_cycles = 1;
				}
			}
			
			if(switch_value == 1)
			{
				Number_of_cycles--;
				
				flag = 1; //为了防止无用的屏幕刷新进行显示界面的刷新次数控制 //只有在按键按下之后有具体操作了才会刷新
				
				if(Number_of_cycles < 1)
				{
					Number_of_cycles = 5;
				}
			}
			///////////////////////////////////////////////////////////
			//显示闹钟界面
			
			
			
			
			
			
			if(Number_of_cycles == function_clock && flag == 1)
			{
				MENU_clock();
				
				flag = 0; //为了防止无用的屏幕刷新进行显示界面的刷新次数控制 //在没有按键按下时不会自己刷新显示
			}
			//显示照明界面
			if(Number_of_cycles == function_light  && flag == 1)
			{
				MENU_light();
				
				flag = 0; //为了防止无用的屏幕刷新进行显示界面的刷新次数控制 //在没有按键按下时不会自己刷新显示
			}
			//显示游戏界面
			if(Number_of_cycles == function_game && flag == 1)
			{
				MENU_Game();
				
				flag = 0; //为了防止无用的屏幕刷新进行显示界面的刷新次数控制 //在没有按键按下时不会自己刷新显示
			}
			//显示设置界面
			if(Number_of_cycles == function_set  && flag == 1)
			{
				MENU_SETTING();
				
				flag = 0; //为了防止无用的屏幕刷新进行显示界面的刷新次数控制 //在没有按键按下时不会自己刷新显示
			}
			//显示退出界面
			if(Number_of_cycles == function_quit && flag == 1)
			{
				MENU_quit();
				
				flag = 0; //为了防止无用的屏幕刷新进行显示界面的刷新次数控制 //在没有按键按下时不会自己刷新显示
			}
			
			
			//选择闹钟要显示的功能
			//flag = clock_function(Number_of_cycles,switch_value);
			if(Number_of_cycles == function_clock && switch_value == Button_2_pressed)
			{
				clock_function();
				
				flag = 1;
			}
			
			//选择照明要显示的功能
			if(Number_of_cycles == function_light  && switch_value == Button_2_pressed)
			{
				printf("进入了照明app\r\n");
				
				light_function();
			}
			
			//选择游戏要显示的功能
			if(Number_of_cycles == function_game  && switch_value == Button_2_pressed)
			{
				printf("进入了游戏app\r\n");
				
				APP_GAME();
				
				flag = 1;
			}
			
			//选择设置要显示的功能 //设置时间、设置日期、设置背光、设置声音、设置LED、设置计步器
			if(Number_of_cycles == function_set && switch_value == Button_2_pressed)
			{
				//LCD_Fill(0,0,LCD_W,LCD_H,BLACK); //电池里面的填充
				printf("进入了设置app\r\n");
				
				setting_function();
				
				flag = 1;
	
			}
						
			//返回到主界面
			if(Number_of_cycles == function_quit && switch_value == Button_2_pressed)
			{
				LCD_Fill(0,0,LCD_W,LCD_H,BLACK); //电池里面的填充

				Refresh(); //刷新主界面的显示
				
				break;
			}
		}
	}
}




//void LOW_SystemClock_Config(void)
//{
//  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
//  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
//  RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = {0};

//  /** Configure the main internal regulator output voltage 
//  */
//  __HAL_RCC_PWR_CLK_ENABLE();
//  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
//  /** Initializes the CPU, AHB and APB busses clocks 
//  */
//  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE|RCC_OSCILLATORTYPE_LSE;
//  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
//  RCC_OscInitStruct.LSEState = RCC_LSE_ON;
//  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
//  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
//  RCC_OscInitStruct.PLL.PLLM = 15;
//  RCC_OscInitStruct.PLL.PLLN = 144;
//  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV4;
//  RCC_OscInitStruct.PLL.PLLQ = 5;
//  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
//  {
//    Error_Handler();
//  }
//  /** Initializes the CPU, AHB and APB busses clocks 
//  */
//  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
//                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
//  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
//  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV4;
//  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
//  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

//  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
//  {
//    Error_Handler();
//  }
//  PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_RTC;
//  PeriphClkInitStruct.RTCClockSelection = RCC_RTCCLKSOURCE_LSE;
//  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
//  {
//    Error_Handler();
//  }
//}

//void fun0()
{
	/**************功能的具体实现****************/
	
	//__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_4, 0); //设置PWM的占空比，调节背光
	
	/*****************按键和显示处理***********************/
	
	/****************进入低功耗模式，关闭大部分外设来节约电流*************************/	
	
	LCD_RES_Clr();//显示屏幕复位
	
	 LOW_SystemClock_Config();
	/****************关闭GPIO*********************/
	__HAL_RCC_DMA2_CLK_DISABLE(); //关闭PWM控制输出
	__HAL_RCC_ADC1_CLK_DISABLE();	//关闭ADC
	__HAL_RCC_I2C1_CLK_DISABLE();  //关闭IIC通讯
	__HAL_RCC_SPI1_CLK_DISABLE(); 	//关闭屏幕的SPI通讯
	__HAL_RCC_TIM2_CLK_DISABLE();	//关闭PWM输出
	__HAL_RCC_TIM4_CLK_DISABLE();	//关闭PWM输出
	__HAL_RCC_USART1_CLK_DISABLE();//关闭串口通讯
	
//	SystemClock_Config();
	
	//进入到死循环中，并且降低系统时钟频率进一步降工作电流
	while(1)
	{
		if(!HAL_GPIO_ReadPin(KEY_2_GPIO_Port, KEY_2_Pin)) break;
	}	
	
	SystemClock_Config();
	
	__HAL_RCC_DMA2_CLK_ENABLE(); //关闭PWM控制输出
	__HAL_RCC_ADC1_CLK_ENABLE();	//关闭ADC
	__HAL_RCC_I2C1_CLK_ENABLE();  //关闭IIC通讯
	__HAL_RCC_SPI1_CLK_ENABLE(); 	//关闭屏幕的SPI通讯
	__HAL_RCC_TIM2_CLK_ENABLE();	//关闭PWM输出
	__HAL_RCC_TIM4_CLK_ENABLE();	//关闭PWM输出
	__HAL_RCC_USART1_CLK_ENABLE();//关闭串口通讯
	
	LCD_Init();//LCD初始化

//	LCD_ShowPicture(0,0,134,103,gImage_0);

//	key_choose = 0; //把按键选择归回原位
//	
//	function = -1; //把功能重新回到主界面
//	
//	key_confirm = 0; //把确认按键归零
	
	__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_4, 80); //设置PWM的占空比，调节背光
	
	HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_RESET);
			
}



