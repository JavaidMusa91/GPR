/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    gpio.c
  * @brief   This file provides code for the configuration
  *          of all used GPIO pins.
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

/* Includes ------------------------------------------------------------------*/
#include "gpio.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/*----------------------------------------------------------------------------*/
/* Configure GPIO                                                             */
/*----------------------------------------------------------------------------*/
/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/** Configure pins as
        * Analog
        * Input
        * Output
        * EVENT_OUT
        * EXTI
*/
void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, SDIO_Pin|SCLK_Pin|CSB_Pin|MASTER_RST_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, ADC08200_Power_Down_Pin|GPIO_PIN_5, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, IO_UPDATE_Pin|EXT_PWR_DWN_Pin|TX_ENABLE_Pin|PROFILE0_Pin
                          |PROFILE1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(PROFILE2_GPIO_Port, PROFILE2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : ADC_Data_Bit_0_Pin ADC_Data_Bit_1_Pin ADC_Data_Bit_2_Pin ADC_Data_Bit_3_Pin
                           ADC_Data_Bit_4_Pin ADC_Data_Bit_5_Pin ADC_Data_Bit_6_Pin ADC_Data_Bit_7_Pin */
  GPIO_InitStruct.Pin = ADC_Data_Bit_0_Pin|ADC_Data_Bit_1_Pin|ADC_Data_Bit_2_Pin|ADC_Data_Bit_3_Pin
                          |ADC_Data_Bit_4_Pin|ADC_Data_Bit_5_Pin|ADC_Data_Bit_6_Pin|ADC_Data_Bit_7_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : SDIO_Pin SCLK_Pin CSB_Pin MASTER_RST_Pin */
  GPIO_InitStruct.Pin = SDIO_Pin|SCLK_Pin|CSB_Pin|MASTER_RST_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : SDO_Pin */
  GPIO_InitStruct.Pin = SDO_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(SDO_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : ADC08200_Power_Down_Pin PB5 */
  GPIO_InitStruct.Pin = ADC08200_Power_Down_Pin|GPIO_PIN_5;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : IO_UPDATE_Pin EXT_PWR_DWN_Pin TX_ENABLE_Pin PROFILE0_Pin
                           PROFILE1_Pin */
  GPIO_InitStruct.Pin = IO_UPDATE_Pin|EXT_PWR_DWN_Pin|TX_ENABLE_Pin|PROFILE0_Pin
                          |PROFILE1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pin : PROFILE2_Pin */
  GPIO_InitStruct.Pin = PROFILE2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(PROFILE2_GPIO_Port, &GPIO_InitStruct);

  /*AnalogSwitch Config */
  HAL_SYSCFG_AnalogSwitchConfig(SYSCFG_SWITCH_PA1, SYSCFG_SWITCH_PA1_CLOSE);

}

/* USER CODE BEGIN 2 */

/* USER CODE END 2 */
