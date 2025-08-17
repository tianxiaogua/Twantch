/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define BLE_KEY_Pin GPIO_PIN_1
#define BLE_KEY_GPIO_Port GPIOC
#define BLE_REST_Pin GPIO_PIN_2
#define BLE_REST_GPIO_Port GPIOC
#define KEY1_Pin GPIO_PIN_0
#define KEY1_GPIO_Port GPIOA
#define SPI1_CS_Pin GPIO_PIN_4
#define SPI1_CS_GPIO_Port GPIOA
#define LCD_DC_Pin GPIO_PIN_4
#define LCD_DC_GPIO_Port GPIOC
#define LCD_RES_Pin GPIO_PIN_5
#define LCD_RES_GPIO_Port GPIOC
#define LCD_CS_Pin GPIO_PIN_0
#define LCD_CS_GPIO_Port GPIOB
#define MIC_EN_Pin GPIO_PIN_13
#define MIC_EN_GPIO_Port GPIOB
#define BLE_LINK_Pin GPIO_PIN_15
#define BLE_LINK_GPIO_Port GPIOA
#define BLE_STA_Pin GPIO_PIN_10
#define BLE_STA_GPIO_Port GPIOC
#define MAX30103_INT_Pin GPIO_PIN_11
#define MAX30103_INT_GPIO_Port GPIOC
#define POWER_KEY_Pin GPIO_PIN_12
#define POWER_KEY_GPIO_Port GPIOC
#define USB_KEY_Pin GPIO_PIN_2
#define USB_KEY_GPIO_Port GPIOD
#define KEY3_Pin GPIO_PIN_3
#define KEY3_GPIO_Port GPIOB
#define KEY2_Pin GPIO_PIN_4
#define KEY2_GPIO_Port GPIOB
#define MPU_INT_Pin GPIO_PIN_5
#define MPU_INT_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
