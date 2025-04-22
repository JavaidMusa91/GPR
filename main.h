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
#include "stm32h7xx_hal.h"

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
#define ADC_Data_Bit_0_Pin GPIO_PIN_0
#define ADC_Data_Bit_0_GPIO_Port GPIOC
#define ADC_Data_Bit_1_Pin GPIO_PIN_1
#define ADC_Data_Bit_1_GPIO_Port GPIOC
#define ADC_Data_Bit_2_Pin GPIO_PIN_2
#define ADC_Data_Bit_2_GPIO_Port GPIOC
#define ADC_Data_Bit_3_Pin GPIO_PIN_3
#define ADC_Data_Bit_3_GPIO_Port GPIOC
#define SDIO_Pin GPIO_PIN_1
#define SDIO_GPIO_Port GPIOA
#define SCLK_Pin GPIO_PIN_2
#define SCLK_GPIO_Port GPIOA
#define CSB_Pin GPIO_PIN_3
#define CSB_GPIO_Port GPIOA
#define MASTER_RST_Pin GPIO_PIN_4
#define MASTER_RST_GPIO_Port GPIOA
#define SDO_Pin GPIO_PIN_5
#define SDO_GPIO_Port GPIOA
#define ADC_Data_Bit_4_Pin GPIO_PIN_4
#define ADC_Data_Bit_4_GPIO_Port GPIOC
#define ADC_Data_Bit_5_Pin GPIO_PIN_5
#define ADC_Data_Bit_5_GPIO_Port GPIOC
#define ADC08200_Power_Down_Pin GPIO_PIN_0
#define ADC08200_Power_Down_GPIO_Port GPIOB
#define ADC_Data_Bit_6_Pin GPIO_PIN_6
#define ADC_Data_Bit_6_GPIO_Port GPIOC
#define ADC_Data_Bit_7_Pin GPIO_PIN_7
#define ADC_Data_Bit_7_GPIO_Port GPIOC
#define IO_UPDATE_Pin GPIO_PIN_8
#define IO_UPDATE_GPIO_Port GPIOC
#define EXT_PWR_DWN_Pin GPIO_PIN_9
#define EXT_PWR_DWN_GPIO_Port GPIOC
#define TX_ENABLE_Pin GPIO_PIN_10
#define TX_ENABLE_GPIO_Port GPIOC
#define PROFILE0_Pin GPIO_PIN_11
#define PROFILE0_GPIO_Port GPIOC
#define PROFILE1_Pin GPIO_PIN_12
#define PROFILE1_GPIO_Port GPIOC
#define PROFILE2_Pin GPIO_PIN_2
#define PROFILE2_GPIO_Port GPIOD

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
