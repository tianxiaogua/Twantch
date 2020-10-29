#ifndef __CONTRO_H
#define __CONTRO_H 	   

#include "rtc.h"

#define Connected 0
#define Not_connected 1

#define function_clock 	1
#define function_light 	2
#define function_game  	3
#define function_set 		4
#define function_quit 	5

#define Button_1_pressed 	1
#define Button_2_pressed 	2
#define Button_3_pressed 	3


extern	unsigned char set_Screen_off_flag ; //屏幕是不是已经熄灭了

extern unsigned char usart_print_flag; //是不是需要串口显示
                                                                                          
extern	unsigned long	STEPS; //步数

extern float temperature ; //温度值

extern float humidity ; //湿度值

	
extern unsigned char USB_in_sign;

/*******************************************
* @function: 	按键消抖函数
* @input:			无
* @return:		返回三个按键代表的三个值
* @author:		田小花
* @time:			2020.10.2
*******************************************/

extern	unsigned char Screen_off_time;

uint8_t Get_Key_value(unsigned char flag);



extern	float ADC_Value_BATTERY;
extern	int Battery_voltage; //电池电压的百分比 
extern	float Battery_voltage_[10]; //电池历史电压，用来进行滑动平均滤波 
extern	float Battery_voltage_history; //电池历史电压，用来进行滑动平均滤波 
	
/*******************************************
* @function: 	使用STM32板载ADC获取电池电压值，将获取到的电压值储存在全局变量中，打开ADC1通道10，对应引脚PA4
* @input:			无
* @return:		输出成为全局变量直接使用
* @author:		田小花
* @time:			2020.9.1
*******************************************
*/
void Obtain_battery_voltage(void);



/*******************************************
* @function: 	使用STM32板载ADC获取电池电压值，将获取到的电压值储存在全局变量中，打开ADC1通道1 ，对应引脚PA1
* @input:			无
* @return:		输出成为全局变量直接使用
* @author:		田小花
* @time:			2020.10.2
*******************************************/
extern RTC_DateTypeDef sDate; //全局变量，外部可以直接调用使用 ，存放日期数据

extern RTC_TimeTypeDef sTime; //全局变量，外部可以直接调用使用 ，存放时间数据

void get_time(void);


/*******************************************
* @function: 	对各个传感器部分的数据处理函数进行调用和整合
* @input:			无
* @return:		输出成为全局变量直接使用
* @author:		田小花
* @time:			2020.10.2
*******************************************/
void Get_Sensor_data(void);
	

#endif



