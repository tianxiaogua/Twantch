#include "adc.h"
#include "usart.h"
#include "gpio.h"
#include "driver_lowpower.h"
#include "driver_tool.h"

void init_lowpower(void)
{
    GUA_LOGI("init_lowpower");
    __HAL_RCC_PWR_CLK_ENABLE();//使能PWR时钟
    if (__HAL_PWR_GET_FLAG(PWR_FLAG_SB) != RESET) {//检查并检查系统是否从待机模式恢复
        __HAL_PWR_CLEAR_FLAG(PWR_FLAG_SB);
        GUA_LOGI("Clear Standby flag");
    }
    GUA_LOGI("init_lowpower ok");
}

void set_lowpower_sleep(void)
{
    HAL_Delay(1500);
    HAL_PWR_DisableWakeUpPin(PWR_WAKEUP_PIN1);//禁用所有使用的唤醒源:PWR_WAKEUP_PIN1 connected to PA.00
    __HAL_PWR_CLEAR_FLAG(PWR_FLAG_WU);//清除所有相关的唤醒标志
    HAL_PWR_EnableWakeUpPin(PWR_WAKEUP_PIN1);//启用连接到PA.00的WakeUp Pin
    HAL_PWR_EnterSTANDBYMode();//进入待机模式
}

void set_lowpower_sleep_(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

		/* Enable GPIOs clock */
    __HAL_RCC_GPIOB_CLK_ENABLE();
    __HAL_RCC_GPIOC_CLK_ENABLE();
    // __HAL_RCC_GPIOH_CLK_ENABLE();

    GPIO_InitStructure.Pin = GPIO_PIN_All;
    GPIO_InitStructure.Mode = GPIO_MODE_ANALOG;
    GPIO_InitStructure.Pull = GPIO_NOPULL;

    HAL_GPIO_Init(GPIOB, &GPIO_InitStructure);
    HAL_GPIO_Init(GPIOC, &GPIO_InitStructure);
    // HAL_GPIO_Init(GPIOH, &GPIO_InitStructure);

    /* Disable GPIOs clock */

    __HAL_RCC_GPIOB_CLK_DISABLE();
    __HAL_RCC_GPIOC_CLK_DISABLE();
    // __HAL_RCC_GPIOH_CLK_DISABLE();

		GPIO_InitStructure.Pin = GPIO_PIN_All;
    GPIO_InitStructure.Mode = GPIO_MODE_ANALOG;
    GPIO_InitStructure.Pull = GPIO_NOPULL;
		HAL_GPIO_Init(GPIOA, &GPIO_InitStructure);//
		__HAL_RCC_GPIOA_CLK_DISABLE();

	  /* 为节约功耗，适当配置对应的GPIO
			唤醒引脚，填充下拉控制寄存器并设置APC位 */

		__HAL_RCC_GPIOA_CLK_ENABLE();
		GPIO_InitStructure.Pin = GPIO_PIN_0;
		GPIO_InitStructure.Mode = GPIO_MODE_INPUT;
		GPIO_InitStructure.Pull = GPIO_NOPULL;
		HAL_GPIO_Init(GPIOA, &GPIO_InitStructure);


		/* Disable used wakeup source: PWR_WAKEUP_PIN1 */
    HAL_Delay(1500);
    HAL_PWR_DisableWakeUpPin(PWR_WAKEUP_PIN1);//禁用所有使用的唤醒源:PWR_WAKEUP_PIN1 connected to PA.00
    __HAL_PWR_CLEAR_FLAG(PWR_FLAG_WU);//清除所有相关的唤醒标志
    HAL_PWR_EnableWakeUpPin(PWR_WAKEUP_PIN1);//启用连接到PA.00的WakeUp Pin
    HAL_PWR_EnterSTANDBYMode();//进入待机模式
}


