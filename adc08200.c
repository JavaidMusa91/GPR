#include "adc08200.h"
#include "gpio.h"  // Needed for CubeMX pin defines

// --- Sample Buffer ---
uint8_t adc_samples[SAMPLE_COUNT];

void ADC08200_GPIO_Init(void) {
    // All GPIO configuration is already handled by MX_GPIO_Init()
    // No need to manually reconfigure here
}

void ADC08200_PowerOn(void) {
    HAL_GPIO_WritePin(ADC08200_Power_Down_GPIO_Port, ADC08200_Power_Down_Pin, GPIO_PIN_RESET); // Active LOW
    HAL_Delay(1); // Wait for ADC to stabilize
}

uint8_t ADC08200_ReadByte(void) {
    uint8_t val = 0;

    val |= HAL_GPIO_ReadPin(ADC_Data_Bit_0_GPIO_Port, ADC_Data_Bit_0_Pin) << 0;
    val |= HAL_GPIO_ReadPin(ADC_Data_Bit_1_GPIO_Port, ADC_Data_Bit_1_Pin) << 1;
    val |= HAL_GPIO_ReadPin(ADC_Data_Bit_2_GPIO_Port, ADC_Data_Bit_2_Pin) << 2;
    val |= HAL_GPIO_ReadPin(ADC_Data_Bit_3_GPIO_Port, ADC_Data_Bit_3_Pin) << 3;
    val |= HAL_GPIO_ReadPin(ADC_Data_Bit_4_GPIO_Port, ADC_Data_Bit_4_Pin) << 4;
    val |= HAL_GPIO_ReadPin(ADC_Data_Bit_5_GPIO_Port, ADC_Data_Bit_5_Pin) << 5;
    val |= HAL_GPIO_ReadPin(ADC_Data_Bit_6_GPIO_Port, ADC_Data_Bit_6_Pin) << 6;
    val |= HAL_GPIO_ReadPin(ADC_Data_Bit_7_GPIO_Port, ADC_Data_Bit_7_Pin) << 7;

    return val;
}

void ADC08200_SampleManual(void) {
    for (int i = 0; i < SAMPLE_COUNT; i++) {
        adc_samples[i] = ADC08200_ReadByte();
        for (volatile int j = 0; j < 100; j++); // crude delay
    }
}
