/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "adc.h"
#include "dma.h"
#include "i2c.h"
#include "rtc.h"
#include "spi.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
//#include "lcd.h"
//#include "lcd_init.h"
//#include "pic.h"
#include "stdio.h"

//#include "stm32f4xx_hal_flash_ex.h"

#include "inv_mpu.h"
#include "inv_mpu_dmp_motion_driver.h" 
#include "mpu6050Driver.h"

#include "sht30_i2c_drv.h"

#include "stdlib.h"
#include <stdlib.h>
#include <string.h>

#include <display.h>
#include <contro.h>

#include <app.h>
	
//#include "oflash.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
#ifdef __GNUC__
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif
PUTCHAR_PROTOTYPE
{
    //具体哪个串口可以更改huart1为其它串口
    HAL_UART_Transmit(&huart1 , (uint8_t *)&ch, 1 , 0xffff);
    return ch;
}

//uint8_t aRxBuffer;   //接收中断缓冲
//uint8_t Uart1_RxBuff[256];  //接收缓冲
//uint8_t Uart1_Rx_Cnt = 0;  //接收缓冲计数
//uint8_t cAlmStr[] = "数据溢出(大于256)\r\n";
//uint8_t Reve_Data[256];    //串口接收的数据缓存



uint8_t sign;
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */


/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
//	float pitch,roll,yaw; 		//欧拉角
	
	unsigned char switch_value; //获取到的按键值
//	unsigned long	STEPS = 0;

  /* USER CODE END 1 */
  

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */
	
  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_ADC1_Init();
  MX_I2C1_Init();
  MX_SPI1_Init();
  MX_TIM2_Init();
  MX_TIM4_Init();
  MX_USART1_UART_Init();
  MX_RTC_Init();
  MX_I2C2_Init();
  /* USER CODE BEGIN 2 */
	
//	HAL_UART_Receive_IT(&huart1, (uint8_t *)&aRxBuffer, 1);	//打开串口接收中断
	/*主显示界面*/
	MENU_init();
	
	/*调节蜂鸣器*/
	HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_4); //开启定时器PWM通道 定时器2 通道3
	__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_4, 0); //设置PWM的占空比，这里初始化占空比为0
	
	/*调节屏幕背光*/
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_4); //开启定时器PWM通道 定时器2 通道3
	__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_4, 70); //设置PWM的占空比，调节背光
	 
	
	MPU_6050_Init();// 可以尝试 直接打开FIFO
	//初始化DMP
	while(mpu_dmp_init())
	{
		printf("MPU6050 is error !!!!!!\r\n");
	}
	printf("go!!!!!!\r\n");
	
	SHT30_Reset();
	if(SHT30_Init() == HAL_OK)
			printf("sht30 init ok.\r\n");
	else
			printf("sht30 init fail.\r\n");

	HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_SET);	
	
	Screen_off_time = sTime.Seconds + 10; //设置自动熄灭屏幕的时间是20秒
		
	if(	Screen_off_time >	59	) //如果设计的屏幕熄灭实践超过了一分钟就倒退回去
	{
		Screen_off_time = Screen_off_time -60; //得到正确的时间
	}
	
	usart_print_flag = 0;
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
	while (1)
  {
    /* USER CODE END WHILE */
		//传感器检测	
		Get_Sensor_data();

		/*主界面显示部分*/
		MENU_main();
		
		/*根据按键方向按键按下来进入应用界面*/
		MENU_APP(switch_value);
		
		/*处理后台运行的程序*/
		Background_detection(switch_value);

		/*检测按键以及处理自动熄屏和唤醒屏幕*/
		switch_value = Get_Key_value(1);

		if(	switch_value == 2)
		{
			/*熄灭屏幕*/
			__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_4, 0); //设置PWM的占空比，调节背光
			
			set_Screen_off_flag = 0; //代表已经熄灭了屏幕 熄灭屏幕的状态下不对按键等操作进行反应
		}
		
//		/*陀螺仪获取角度部分*/
//		if(	mpu_dmp_get_data(	&pitch,	&roll,	&yaw	)	==	0	)
//		{
//			if(usart_print_flag)
//			{
//				printf("%.2f %.2f %.2f \r\n",pitch,roll,yaw);
//			}
//		}

//		if(usart_print_flag)
//		{
//			printf("温度:%.1f 湿度:%.1f 电量百分比:%d	按键值:%d  日期:%d:%d:%d   时间:%d:%d:%d \r\n",
//								temperature,humidity,	Battery_voltage	,	
//								switch_value,	
//								sDate.Year,	sDate.Month,	sDate.Date,	
//								sTime.Hours, sTime.Minutes, sTime.Seconds);
//		}
		
    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = {0};

  /** Configure the main internal regulator output voltage 
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI|RCC_OSCILLATORTYPE_LSE;
  RCC_OscInitStruct.LSEState = RCC_LSE_ON;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 100;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_3) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_RTC;
  PeriphClkInitStruct.RTCClockSelection = RCC_RTCCLKSOURCE_LSE;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
/* USER CODE BEGIN 4 */
//void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
//{
//  /* Prevent unused argument(s) compilation warning */
//	int i;
//  UNUSED(huart);
//  /* NOTE: This function Should not be modified, when the callback is needed,
//           the HAL_UART_TxCpltCallback could be implemented in the user file
//   */
// if(Uart1_Rx_Cnt >= 255)  //溢出判断
// {
//  Uart1_Rx_Cnt = 0;
//  memset(Uart1_RxBuff,0x00,sizeof(Uart1_RxBuff));
//  HAL_UART_Transmit(&huart1, (uint8_t *)&cAlmStr, sizeof(cAlmStr),0xFFFF); 
// }
// else
// {
//  Uart1_RxBuff[Uart1_Rx_Cnt++] = aRxBuffer;   //接收数据转存
//  if((Uart1_RxBuff[Uart1_Rx_Cnt-1] == 0x0A)&&(Uart1_RxBuff[Uart1_Rx_Cnt-2] == 0x0D)) //判断结束位
//  {
//		for (i=0; i<sizeof(Uart1_RxBuff)-1; i++)
//		{	
//			Reve_Data[i] = Uart1_RxBuff[i]; 
//		}
//		HAL_UART_Transmit(&huart1, (uint8_t *)&Uart1_RxBuff, Uart1_Rx_Cnt,0xFFFF); //将收到的信息发送出去
//   Uart1_Rx_Cnt = 0;
//   memset(Uart1_RxBuff,0x00,sizeof(Uart1_RxBuff)); //清空数组
//  }
// }
// HAL_UART_Receive_IT(&huart1, (uint8_t *)&aRxBuffer, 1);   //再开启接收中断
//}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
