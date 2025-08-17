#include "driver_gpio.h"
#include "usart.h"
#include "gpio.h"
#include "driver_tool.h"
#include "stdio.h"
#include "driver_usart.h"

void init_gpio(void)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : PtPin */
  GPIO_InitStruct.Pin = LED0_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LED0_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : PA0 */
  GPIO_InitStruct.Pin = GPIO_PIN_0;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

}


void init_key_gpio(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  GPIO_InitStruct.Pin = KEY1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  HAL_GPIO_Init(KEY1_GPIO_Port, &GPIO_InitStruct);

  GPIO_InitStruct.Pin = KEY2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  HAL_GPIO_Init(KEY2_GPIO_Port, &GPIO_InitStruct);

  GPIO_InitStruct.Pin = KEY3_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  HAL_GPIO_Init(KEY3_GPIO_Port, &GPIO_InitStruct);
}


int32_t get_key1(void)
{
  int32 ret = HAL_GPIO_ReadPin(KEY1_GPIO_Port, KEY1_Pin);
  if (ret == GPIO_PIN_SET) {
    GUA_LOGI("key1 down!\r\n");
    return LEY_DOWN_GET;
  } else {
    return KEY_UP_GET;
  }
}


int32_t get_key2(void)
{
  int32 ret = HAL_GPIO_ReadPin(KEY2_GPIO_Port, KEY2_Pin);
  if (ret == GPIO_PIN_SET) {
		GUA_LOGI("key2 down!\r\n");
    return LEY_DOWN_GET;
  } else {
    return KEY_UP_GET;
  }
}


int32_t get_key3(void)
{
  int32 ret = HAL_GPIO_ReadPin(KEY3_GPIO_Port, KEY3_Pin);
  if (ret == GPIO_PIN_SET) {
    GUA_LOGI("key3 down!\r\n");
    return LEY_DOWN_GET;
  } else {
    return KEY_UP_GET;
  }
}


int32_t get_power_key(void)
{
  int32 ret = HAL_GPIO_ReadPin(KEY1_GPIO_Port, KEY1_Pin);
  if (ret == GPIO_PIN_SET) {
    GUA_LOGI("key1 down!\r\n");
    return LEY_DOWN_GET;
  } else {
    return KEY_UP_GET;
  }
}


int32_t mcu_power_set_ctol(uint8_t user_ctl)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin : LED0_Pin */
  GPIO_InitStruct.Pin = POWER_KEY_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(POWER_KEY_GPIO_Port, &GPIO_InitStruct);

  if (user_ctl) {
    HAL_GPIO_WritePin(POWER_KEY_GPIO_Port, POWER_KEY_Pin, GPIO_PIN_SET);
  } else {
    HAL_GPIO_WritePin(POWER_KEY_GPIO_Port, POWER_KEY_Pin, GPIO_PIN_RESET);
  }

	return 0;
}


/* 关机 */
int32_t muc_power_set_shutdown(void)
{
  return mcu_power_set_ctol(0);
}


/* 开机 */
int32_t muc_power_set_starting(uint8_t user_ctl)
{
	uint8_t key_time = 0;

  if (user_ctl == 1) {
    GUA_LOGE("Forced startup"); // 强制开机
    return mcu_power_set_ctol(1);
  }

  HAL_Delay(100); // 延时100ms消抖
	GUA_LOGI("mcu get up\r\n");

	while(get_power_key() == LEY_DOWN_GET) { // 按键按下的时候是0
		HAL_Delay(100); // 延时100ms消抖
    GUA_LOGI("..\r\n");
		key_time++;
		if(key_time > 20){ // 超过2秒开机
			GUA_LOGI("start muc\n");
			return mcu_power_set_ctol(1);
		}
	}

	GUA_LOGI("start muc fause, shutdown...\n");
  return mcu_power_set_ctol(0);
}
