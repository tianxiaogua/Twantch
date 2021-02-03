#include "contro.h"
#include "display.h"
#include "adc.h"
#include "dma.h"
#include "i2c.h"

#include "inv_mpu_dmp_motion_driver.h" 

#include "mpu6050Driver.h"

#include "spi.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

#include "stdio.h"

#include "sht30_i2c_drv.h"

#include "app.h"

unsigned char usart_print_flag = 1; //是不是需要串口显示

unsigned long	STEPS = 0; //步数

/*******************************************
* @function: 	根据SHT30获取温湿度值，使用IIC2总线驱动，需要注意此传感器不能频繁读取其数值，会造数据无法读取，这里延时大约一秒钟
* @input:			无
* @return:		全局变量
* @author:		田小花
* @time:			2020.10.22
*******************************************/
float temperature = 0.0;

float humidity = 0.0;

unsigned char flag_sht30 = 0;

void SHT30_Get_date(void)
{
	uint8_t recv_dat[6] = {0};
	if(	Total_cycle == 99	)
	{
		flag_sht30  = ! flag_sht30;
	}
	if(	flag_sht30	&& Total_cycle == 99	)
	{
		if(SHT30_Read_Dat(recv_dat) == HAL_OK)
		{
			if(SHT30_Dat_To_Float(recv_dat, &temperature, &humidity)==0)
			{
//				printf("T%f H%f", temperature, humidity);
				temperature = temperature -17; //读取到的温度和实际的温度有偏差，需要校准
			}
			else
			{
				printf("crc check fail.");
			}
		}
		else
		{
			printf("read data from sht30 fail.");
		}
	}
}



/*******************************************
* @function: 	检测是否有sub连接，检测高电平引脚 PB12
* @input:			无
* @return:		返回一个标志
* @author:		田小花
* @time:			2020.10.3
*******************************************/

unsigned char USB_in_sign;

void Test_usb_input(void)
{
	if(HAL_GPIO_ReadPin(USB_in_sign_GPIO_Port, USB_in_sign_Pin))//检测高电平作为判断有USB设备连接的依据
	{
		USB_in_sign = Connected;
		//printf("！！！！！！！");
	}
	else
	{
		USB_in_sign = Not_connected;
	//	printf("没人连接");
	}
		
}

/*******************************************
* @function: 	按键消抖函数
* @input:			无
* @return:		返回三个按键代表的三个值
* @author:		田小花
* @time:			2020.10.2
*******************************************/
unsigned char Screen_off_time = 0;

unsigned char set_Screen_off_flag = 1;

unsigned char	Total_cycle_sleep = 0;

unsigned char	Total_cycle_sleep_flag = 0;

uint8_t Get_Key_value(unsigned char flag)
{	 
	get_time(); //根据时间来熄灭屏幕
	
	read_acc(); //根据加速度的大小来唤醒屏幕
		
	/*摇动手腕来唤醒屏幕*/
	if(	ACX	>	1.6	&& Total_cycle_sleep_flag == 0 )
	{
		Total_cycle_sleep_flag = 1;
	}	
	if(	Total_cycle_sleep_flag == 1	)
	{
		Total_cycle_sleep++;
		
		if(	Total_cycle_sleep	<	150	&&	Total_cycle_sleep	>	100	&&	ACX	>	1.5)
		{
			Total_cycle_sleep_flag = 0;
			
			Total_cycle_sleep = 0 ;
			
			__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_4, 70); //设置PWM的占空比，调节背光

			Screen_off_time = sTime.Seconds + 10; //设置自动熄灭屏幕的时间是20秒
			
			if(	Screen_off_time >	59	) //如果设计的屏幕熄灭实践超过了一分钟就倒退回去
			{
				Screen_off_time = Screen_off_time -60; //得到正确的熄屏时间
			}
			return 0;
		}
		if(	Total_cycle_sleep	>	150)
		{
			Total_cycle_sleep_flag = 0;
			
			Total_cycle_sleep	= 0;
		}
	}
	
	/*判断是否到达设定时间来熄灭屏幕*/
	if(	Screen_off_time == sTime.Seconds && flag)
	{
		/*熄灭屏幕*/
		__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_4, 0); //设置PWM的占空比，调节背光
		
		set_Screen_off_flag = 0; //代表已经熄灭了屏幕 熄灭屏幕的状态下不对按键等操作进行反应
	}
	
	if(!HAL_GPIO_ReadPin(KEY_1_GPIO_Port, KEY_1_Pin))
	{
		/*按下按键来唤醒屏幕*/
		__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_4, 70); //设置PWM的占空比，调节背光

		Screen_off_time = sTime.Seconds + 10; //设置自动熄灭屏幕的时间是20秒
		
		if(	Screen_off_time >	59	) //如果设计的屏幕熄灭实践超过了一分钟就倒退回去
		{
			Screen_off_time = Screen_off_time -60; //得到正确的熄屏时间
		}
		
		
		while(!HAL_GPIO_ReadPin(KEY_1_GPIO_Port, KEY_1_Pin))
		{
			/*根据设置判断是不是需要在按下按键的时候鸣响蜂鸣器提示*/
			if(	Sound_switch	)	__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_4, 50); 
			
			HAL_Delay(10);//去抖动 
			
			if(HAL_GPIO_ReadPin(KEY_1_GPIO_Port, KEY_1_Pin))
			{
				__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_4, 0);
				
				if( !set_Screen_off_flag ) //检测到屏幕是是熄灭的状态就不能返回按键值
				{
					set_Screen_off_flag = 1; //有按键按下了，应该唤醒屏幕
					
					return 0;
				}
				else
				{
					return Button_1_pressed;					
				}	
			}
		}
	}
	
	if(!HAL_GPIO_ReadPin(KEY_2_GPIO_Port, KEY_2_Pin))
	{
		/*按下按键来唤醒屏幕*/
		__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_4, 70); //设置PWM的占空比，调节背光

		Screen_off_time = sTime.Seconds + 10; //设置自动熄灭屏幕的时间是20秒
		
		if(	Screen_off_time >	59	) //如果设计的屏幕熄灭实践超过了一分钟就倒退回去
		{
			Screen_off_time = Screen_off_time -60; //得到正确的熄屏时间
		}
		
		while(!HAL_GPIO_ReadPin(KEY_2_GPIO_Port, KEY_2_Pin))
		{
			if(	Sound_switch	)	__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_4, 50);
			
			HAL_Delay(10);//去抖动 
			
			if(HAL_GPIO_ReadPin(KEY_2_GPIO_Port, KEY_2_Pin))
			{
				__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_4, 0);
				
				if( !set_Screen_off_flag ) //检测到屏幕是是熄灭的状态就不能返回按键值
				{
					set_Screen_off_flag = 1; //有按键按下了，应该唤醒屏幕
					
					return 0;
				}
				else
				{
					return Button_2_pressed;					
				}	
			}
		}
	}
	
	if(!HAL_GPIO_ReadPin(KEY_3_GPIO_Port, KEY_3_Pin))
	{
		
		__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_4, 70); //设置PWM的占空比，调节背光

		Screen_off_time = sTime.Seconds + 10; //设置自动熄灭屏幕的时间是20秒
		
		if(	Screen_off_time >	59	) //如果设计的屏幕熄灭实践超过了一分钟就倒退回去
		{
			Screen_off_time = Screen_off_time -60; //得到正确的熄屏时间
		}
		
		
		while(!HAL_GPIO_ReadPin(KEY_3_GPIO_Port, KEY_3_Pin))
		{
			if(	Sound_switch	)	__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_4, 50);
			
			HAL_Delay(10);//去抖动 
			
			if(HAL_GPIO_ReadPin(KEY_3_GPIO_Port, KEY_3_Pin))
			{
				__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_4, 0);
				
				if( !set_Screen_off_flag ) //检测到屏幕是是熄灭的状态就不能返回按键值
				{
					set_Screen_off_flag = 1; //有按键按下了，应该唤醒屏幕
					
					return 0;
				}
				else
				{
					return Button_3_pressed;					
				}	
			}
		}
	}
	return 0;// 无按键按下
}


/*******************************************
* @function: 	使用STM32板载ADC获取电池电压值，将获取到的电压值储存在全局变量中，打开ADC1通道10，对应引脚PA4
* @input:			无
* @return:		输出成为全局变量直接使用
* @author:		田小花
* @time:			2020.9.1
*******************************************
*/
float ADC_Value_BATTERY;

int Battery_voltage = 0; //电池电压的百分比 

float Battery_voltage_[10]; //电池历史电压，用来进行滑动平均滤波 

float Battery_voltage_history; //电池历史电压，用来进行滑动平均滤波 


void Obtain_battery_voltage(void)
{
	unsigned char i	=	0;
	
	HAL_ADC_Start(&hadc1);  //打开ADC1
		
	HAL_ADC_PollForConversion(&hadc1, 10); //

	if(HAL_IS_BIT_SET(HAL_ADC_GetState(&hadc1), HAL_ADC_STATE_REG_EOC))
	{
		ADC_Value_BATTERY = HAL_ADC_GetValue(&hadc1); //读取ADC值存放在ADC_Value_BATTERY中
	}	
	Battery_voltage_history = 0 ; //由于获取的电压值会有波动，使用滑动平均滤波，至少需要测量十次才是有效测量
	
	
	for(i=0;i<9;i++)
	{
		Battery_voltage_[i] = Battery_voltage_[i+1];
	}
//	Battery_voltage_[9] = 2*ADC_Value_BATTERY*3.3f/4096+0.15;	//电池的电压值
	
	Battery_voltage_[9] = 2*ADC_Value_BATTERY*3.3f/4096;	//电池的电压值
	
//	printf("电池电压：%.1f",Battery_voltage_[9]);
	
	for(i=0;i<10;i++) //把储存起来的电池电压的历史值进行求平均值运算
	{
		Battery_voltage_history = Battery_voltage_[i] +	Battery_voltage_history;
	}
	Battery_voltage_history = Battery_voltage_history/10; //最终得到的电池电压的平均值
	
	Battery_voltage = Battery_voltage_history*200 - 731; //最终得到的电池电量的百分比
}

/*******************************************
* @function: 	使用STM32板载ADC获取电池电压值，将获取到的电压值储存在全局变量中，打开ADC1通道1 ，对应引脚PA1
* @input:			无
* @return:		输出成为全局变量直接使用
* @author:		田小花
* @time:			2020.10.2
*******************************************/
RTC_DateTypeDef sDate; //全局变量，外部可以直接调用使用 ，存放日期数据

RTC_TimeTypeDef sTime; //全局变量，外部可以直接调用使用 ，存放时间数据

void get_time(void)
{
	/*时间获取部分*/
	
	HAL_RTC_GetDate(&hrtc, &sDate, RTC_FORMAT_BIN); //获取日期
		
	HAL_RTC_GetTime(&hrtc, &sTime, RTC_FORMAT_BIN); //获取时间
}



/*******************************************
* @function: 	对各个传感器部分的数据处理函数进行调用和整合
* @input:			无
* @return:		输出成为全局变量直接使用
* @author:		田小花
* @time:			2020.10.2
*******************************************/
void Get_Sensor_data(void)
{
	get_time();//读取RTC时钟的时间
	
	Obtain_battery_voltage(); //读取电池的电压值
	
	Test_usb_input(); //检测是不是有USB设备的接入
	
	SHT30_Get_date(); //检测温湿度
	
	dmp_get_pedometer_step_count(&STEPS); //计步器获取到步数
//				printf("%d\r\n",STEPS);
}




