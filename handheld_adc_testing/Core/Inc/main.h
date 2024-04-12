/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
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
#include "stm32u5xx_hal.h"

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

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define PWR_LED_Pin GPIO_PIN_13
#define PWR_LED_GPIO_Port GPIOC
#define GPS_EN_Pin GPIO_PIN_2
#define GPS_EN_GPIO_Port GPIOA
#define BUZZER_Pin GPIO_PIN_3
#define BUZZER_GPIO_Port GPIOA
#define EN_5V_Pin GPIO_PIN_4
#define EN_5V_GPIO_Port GPIOA
#define LCD_CS_Pin GPIO_PIN_0
#define LCD_CS_GPIO_Port GPIOB
#define LCD_DC_Pin GPIO_PIN_1
#define LCD_DC_GPIO_Port GPIOB
#define LCD_BKLITE_Pin GPIO_PIN_2
#define LCD_BKLITE_GPIO_Port GPIOB
#define LCD_RST_Pin GPIO_PIN_10
#define LCD_RST_GPIO_Port GPIOB
#define NRF24_CS_Pin GPIO_PIN_6
#define NRF24_CS_GPIO_Port GPIOC
#define NRF24_CE_Pin GPIO_PIN_7
#define NRF24_CE_GPIO_Port GPIOC
#define NRF24_IRQ_Pin GPIO_PIN_8
#define NRF24_IRQ_GPIO_Port GPIOC
#define SD_CS_Pin GPIO_PIN_15
#define SD_CS_GPIO_Port GPIOA
#define SD_CD_Pin GPIO_PIN_2
#define SD_CD_GPIO_Port GPIOD
#define BTN_RGT_Pin GPIO_PIN_3
#define BTN_RGT_GPIO_Port GPIOB
#define BTN_SEL_Pin GPIO_PIN_4
#define BTN_SEL_GPIO_Port GPIOB
#define BTN_DWN_Pin GPIO_PIN_5
#define BTN_DWN_GPIO_Port GPIOB
#define BTN_UP_Pin GPIO_PIN_6
#define BTN_UP_GPIO_Port GPIOB
#define BTN_PWR_Pin GPIO_PIN_7
#define BTN_PWR_GPIO_Port GPIOB
#define BTN_LFT_Pin GPIO_PIN_8
#define BTN_LFT_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
