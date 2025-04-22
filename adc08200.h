#ifndef ADC08200_H
#define ADC08200_H

#include "stm32h7xx_hal.h"  // Adjust based on your MCU series

// --- Configuration ---
#define SAMPLE_COUNT 1024

// --- External Buffer ---
extern uint8_t adc_samples[SAMPLE_COUNT];

// --- API Functions ---
void ADC08200_GPIO_Init(void);
void ADC08200_PowerOn(void);
uint8_t ADC08200_ReadByte(void);
void ADC08200_SampleManual(void);

#endif // ADC08200_H
