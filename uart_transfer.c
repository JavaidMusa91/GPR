#include "uart_transfer.h"
#include "adc08200.h"
#include "usart.h"  // CubeMX auto-generated
#include <stdio.h>
void UART_Send_ADC_Data(void)
{
    char buffer[16];

    for (int i = 0; i < SAMPLE_COUNT; i++) {
        int len = snprintf(buffer, sizeof(buffer), "%u,", adc_samples[i]);
        HAL_UART_Transmit(&huart1, (uint8_t*)buffer, len, HAL_MAX_DELAY);
    }

    const char endline[] = "\r\n";
    HAL_UART_Transmit(&huart1, (uint8_t*)endline, sizeof(endline) - 1, HAL_MAX_DELAY);
}
