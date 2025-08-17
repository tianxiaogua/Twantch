#include "driver_usart.h"
#include "driver_tool.h"
#include "stdio.h"
#include <stdarg.h>

#include <stdarg.h>
#include <string.h>
#include <stdio.h>

#define DEBUG_BUF_LEN   (128)

typedef struct
{
	uint8 debug_buf[DEBUG_BUF_LEN];
}CTRL_DEBUG_MODE;

CTRL_DEBUG_MODE g_debug_ctl;


int fputc(int ch, FILE *f)
{
    HAL_UART_Transmit(&huart1, (uint8 *)&ch,1, 0xFFFF);
    return ch;
}

void debug_init(int32 SoftVersion, int32 HardVersion , char  *BuildDataStr , char *BuildTimeStr)
{
	debug_out("\r\n\r\n\033[32;0mversions[%06x] Hard[%06x]\r\n", SoftVersion, HardVersion);
	debug_out("build time[%s %s]\r\n", BuildDataStr, BuildTimeStr);
}

void debug_out(const char* fmt, ...)
{
	va_list ap;
	uint8 *pStr = g_debug_ctl.debug_buf;

	memset(g_debug_ctl.debug_buf, 0, DEBUG_BUF_LEN);
	va_start(ap, fmt);
	vsnprintf((char *)g_debug_ctl.debug_buf, DEBUG_BUF_LEN, fmt, ap); //格式化
	va_end(ap);

	HAL_UART_Transmit(&huart1, (uint8 *)pStr++, DEBUG_BUF_LEN, HAL_MAX_DELAY );
}


/*****************************************************************************
* @file   usart_device.c
* @brief  初始化串口和串口DMA中断
* @author Tianxiaogua
* @date   2023-04
****************************************************************************/
void strat_usart_interupt()
{
	HAL_UART_Receive_DMA(&huart1, Rx_Buf, Rx_Max);
	__HAL_UART_ENABLE_IT(&huart1, UART_IT_IDLE);
	HAL_UART_Receive_DMA(&huart2, Rx2_Buf, Rx_Max);
	__HAL_UART_ENABLE_IT(&huart2, UART_IT_IDLE);
//	HAL_UART_Receive_DMA(&huart3, Rx3_Buf, Rx_Max);
//		__HAL_UART_ENABLE_IT(&huart3, UART_IT_IDLE);
}


/*****************************************************************************
 * @file   usart_device.c
 * @brief  ͨDMA发送数据
 * @author Tianxiaogua
 * @date   2023-04
 ****************************************************************************/
void usart_driver_Transmit(uint8_t *buf, uint32_t len)
{
  HAL_UART_Transmit_DMA(&huart1, buf, len);
  // HAL_UART_Transmit(&huart1, buf, len, 0XFFFF);
}
void usart2_driver_Transmit(uint8_t *buf, uint32_t len)
{
  HAL_UART_Transmit_DMA(&huart2, buf, len);
}



/*

移植部分：

usart.c

uint8_t			Rx_Flag = 0;
uint16_t		Rx_Len = 0;
uint8_t			Rx_Buf[Rx_Max] = {0};

uint8_t			Rx2_Flag = 0;
uint16_t		Rx2_Len = 0;
uint8_t			Rx2_Buf[Rx_Max] = {0};

////////////////////////////////////////////
usart.h

#define Rx_Max 128
extern uint8_t		Rx_Flag;
extern uint16_t		Rx_Len;
extern uint8_t		Rx_Buf[Rx_Max];

extern uint8_t		Rx2_Flag;
extern uint16_t		Rx2_Len;
extern uint8_t		Rx2_Buf[Rx_Max];


////////////////////////////////////////////

stm32f1xxit.c

#include "usart.h"


void USART1_IRQHandler(void)
{



  HAL_UART_IRQHandler(&huart1);

  uint32_t temp;
	if((__HAL_UART_GET_FLAG(&huart1,UART_FLAG_IDLE) != RESET))
	{
		// 清除状寄存器和串口数据寄存器
		__HAL_UART_CLEAR_IDLEFLAG(&huart1);

		// 失能DMA接收
		HAL_UART_DMAStop(&huart1);

		// 读取接收长度，剩余大小
		temp = huart1.hdmarx->Instance->NDTR; // CNDTR
		Rx_Len = Rx_Max - temp;

		// 接收标志位置1
		Rx_Flag=1;

		// 使能接收DMA接收
		HAL_UART_Receive_DMA(&huart1,Rx_Buf,Rx_Max);
	}


}
///////////////////////////////////////////////////////////////////////////////////

main.c

strat_usart_interupt();


if(Rx_Flag){  // Receive flag
	Rx_Flag=0;	// clean flag
	HAL_UART_Transmit(&huart1, Rx_Buf, Rx_Len, 0xFFFF);
}


*/



