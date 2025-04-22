#include "ad9910.h"
#include "main.h"    // for HAL handles
#include "gpio.h"    // for CubeMX pin definitions

extern TIM_HandleTypeDef htim1;

void AD9910_DelayUs(uint8_t us) {
    __HAL_TIM_SET_COUNTER(&htim1, 0);
    while (__HAL_TIM_GET_COUNTER(&htim1) < us);
}

void AD9910_SendByte(uint8_t byte) {
    for (int bit = 0; bit < 8; ++bit) {
        HAL_GPIO_WritePin(SDIO_GPIO_Port, SDIO_Pin,
            (byte & (0x80 >> bit)) ? GPIO_PIN_SET : GPIO_PIN_RESET);
        AD9910_DelayUs(10);
        HAL_GPIO_WritePin(SCLK_GPIO_Port, SCLK_Pin, GPIO_PIN_SET);
        AD9910_DelayUs(10);
        HAL_GPIO_WritePin(SCLK_GPIO_Port, SCLK_Pin, GPIO_PIN_RESET);
    }
}

void AD9910_WriteRegister(uint8_t reg, int len, uint8_t *data) {
    HAL_GPIO_WritePin(CSB_GPIO_Port, CSB_Pin, GPIO_PIN_RESET);

    uint8_t instr = reg & ~0x80;
    AD9910_SendByte(instr);
    AD9910_DelayUs(20);

    for (int i = 0; i < len; ++i) {
        AD9910_SendByte(data[i]);
    }

    AD9910_DelayUs(10);
    HAL_GPIO_WritePin(CSB_GPIO_Port, CSB_Pin, GPIO_PIN_SET);
}

void AD9910_ReadRegister(uint8_t reg, int len, uint8_t *data) {
    HAL_GPIO_WritePin(CSB_GPIO_Port, CSB_Pin, GPIO_PIN_RESET);

    uint8_t instr = reg | 0x80;
    AD9910_SendByte(instr);
    AD9910_DelayUs(10);

#ifdef USE_BIDIRECTIONAL
    // Set SDIO to input mode manually if needed
    SDIO_GPIO_Port->CRL &= ~(0b1111 << (5 * 4));
    SDIO_GPIO_Port->CRL |= (0b1000 << (5 * 4));
#endif

    for (int i = 0; i < len; ++i) {
        data[i] = 0;
        for (int bit = 0; bit < 8; ++bit) {
            AD9910_DelayUs(10);
            HAL_GPIO_WritePin(SCLK_GPIO_Port, SCLK_Pin, GPIO_PIN_SET);
#ifdef USE_BIDIRECTIONAL
            data[i] |= HAL_GPIO_ReadPin(SDO_GPIO_Port, SDIO_Pin) << (7 - bit);
#else
            data[i] |= HAL_GPIO_ReadPin(SDO_GPIO_Port, SDO_Pin) << (7 - bit);
#endif
            AD9910_DelayUs(10);
            HAL_GPIO_WritePin(SCLK_GPIO_Port, SCLK_Pin, GPIO_PIN_RESET);
        }
    }

#ifdef USE_BIDIRECTIONAL
    // Revert SDIO back to output
    SDIO_GPIO_Port->CRL &= ~(0b1111 << (5 * 4));
    SDIO_GPIO_Port->CRL |= (0b0011 << (5 * 4));
#endif

    HAL_GPIO_WritePin(CSB_GPIO_Port, CSB_Pin, GPIO_PIN_SET);
}

void AD9910_CreateProfile(double frac, uint16_t ampl, uint16_t phase, uint8_t *profile) {
    profile[0] = ampl >> 8;
    profile[1] = ampl;
    profile[2] = phase >> 8;
    profile[3] = phase;

    uint32_t ftw = frac * (double)((uint64_t)1 << 32);
    profile[4] = ftw >> 24;
    profile[5] = ftw >> 16;
    profile[6] = ftw >> 8;
    profile[7] = ftw;
}

void AD9910_Init(void) {
    // Master Reset High
    HAL_GPIO_WritePin(MASTER_RST_GPIO_Port, MASTER_RST_Pin, GPIO_PIN_SET);

    // Set default pin states
    HAL_GPIO_WritePin(IO_UPDATE_GPIO_Port, IO_UPDATE_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(SCLK_GPIO_Port, SCLK_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(CSB_GPIO_Port, CSB_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(EXT_PWR_DWN_GPIO_Port, EXT_PWR_DWN_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(TX_ENABLE_GPIO_Port, TX_ENABLE_Pin, GPIO_PIN_RESET);

    // Set profile selection to 0
    HAL_GPIO_WritePin(PROFILE0_GPIO_Port, PROFILE0_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(PROFILE1_GPIO_Port, PROFILE1_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(PROFILE2_GPIO_Port, PROFILE2_Pin, GPIO_PIN_RESET);

    // Reset the AD9910
    HAL_Delay(100);
    HAL_GPIO_WritePin(MASTER_RST_GPIO_Port, MASTER_RST_Pin, GPIO_PIN_RESET);
    HAL_Delay(100);
}
