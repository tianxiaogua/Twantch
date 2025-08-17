#include "driver_delay.h"
#include "driver_manage.h"
#include <stdlib.h>
#include "cmsis_os.h"
/*******************************************************************************
 * @file   : tools.c
 * @brief  : 微妙延时函数
 * @input  : delay:输入的延时时间 单位 微妙
 * @author : LiChuan
 * @date   : 2023-04
 ******************************************************************************/
void delay_us(__IO uint32_t delay)
{
    int last, curr, val;
    int temp;

    while (delay != 0)
    {
        temp = delay > 900 ? 900 : delay;
        last = SysTick->VAL;
        curr = last - CPU_FREQUENCY_MHZ * temp;
        if (curr >= 0)
        {
            do
            {
                val = SysTick->VAL;
            }
            while ((val < last) && (val >= curr));
        }
        else
        {
            curr += CPU_FREQUENCY_MHZ * 1000;
            do
            {
                val = SysTick->VAL;
            }
            while ((val <= last) || (val > curr));
        }
        delay -= temp;
    }
}

//延时nms
//nms:要延时的ms数
void delay_ms(uint16_t nms)
{
	// delay_us((u32)(nms*1000));				//普通方式延时
	// HAL_Delay(nms);
	osDelay(nms);
}


