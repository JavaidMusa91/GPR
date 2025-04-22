#ifndef AD9910_H
#define AD9910_H

#include "stm32h7xx_hal.h"  // or the appropriate HAL header for your MCU

// Uncomment if using bidirectional SDIO
// #define USE_BIDIRECTIONAL

#ifdef __cplusplus
extern "C" {
#endif

// --- Public Functions ---
void AD9910_Init(void);
void AD9910_WriteRegister(uint8_t reg, int len, uint8_t *data);
void AD9910_ReadRegister(uint8_t reg, int len, uint8_t *data);
void AD9910_CreateProfile(double frac, uint16_t ampl, uint16_t phase, uint8_t *profile);
void AD9910_DelayUs(uint8_t us);
void AD9910_SendByte(uint8_t byte);

#ifdef __cplusplus
}
#endif

#endif // AD9910_H
