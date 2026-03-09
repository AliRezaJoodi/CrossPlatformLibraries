/**
 * @brief   MCP4822 12-bit DAC driver
 *
 * This library provides basic functions to interface with the MCP4822 DAC via SPI.
 *
 * @note
 * SPI must be configured by the user before using this library.
 *
 * @author  AliReza Joodi
 * @see     https://github.com/AliRezaJoodi
 */

#ifndef MCP4822_INCLUDED
#define MCP4822_INCLUDED

#include <stdint.h>
#include "mcp4822_port.h"

#define MCP4822_OUTPUT_A    0U
#define MCP4822_OUTPUT_B    1U

#define MCP4822_GAIN_1X     1U  /**< Vout: 0 to 2.048V */
#define MCP4822_GAIN_2X     0U  /**< Vout: 0 to 4.096V */

void MCP4822_Init(MCP4822_t *dac);
void MCP4822_SetOutput(MCP4822_t *dac, uint8_t ch, uint8_t gain, uint16_t value);
void MCP4822_DisableOutput(MCP4822_t *dac, uint8_t ch);

static inline void MCP4822_SetOutputA(MCP4822_t *dac, uint8_t gain, uint16_t value){
    MCP4822_SetOutput(dac, MCP4822_OUTPUT_A, gain, value);
}

static inline void MCP4822_SetOutputA_1xGain(MCP4822_t *dac, uint16_t value){
    MCP4822_SetOutput(dac, MCP4822_OUTPUT_A, MCP4822_GAIN_1X, value);
}

static inline void MCP4822_SetOutputA_2xGain(MCP4822_t *dac, uint16_t value){
    MCP4822_SetOutput(dac, MCP4822_OUTPUT_A, MCP4822_GAIN_2X, value);
}

static inline void MCP4822_SetOutputB(MCP4822_t *dac, uint8_t gain, uint16_t value){
    MCP4822_SetOutput(dac, MCP4822_OUTPUT_B, gain, value);
}

static inline void MCP4822_SetOutputB_1xGain(MCP4822_t *dac, uint16_t value){
    MCP4822_SetOutput(dac, MCP4822_OUTPUT_B, MCP4822_GAIN_1X, value);
}

static inline void MCP4822_SetOutputB_2xGain(MCP4822_t *dac, uint16_t value){
    MCP4822_SetOutput(dac, MCP4822_OUTPUT_B, MCP4822_GAIN_2X, value);
}

static inline void MCP4822_DisableOutputA(MCP4822_t *dac){
    MCP4822_DisableOutput(dac, MCP4822_OUTPUT_A);
}

static inline void MCP4822_DisableOutputB(MCP4822_t *dac){
    MCP4822_DisableOutput(dac, MCP4822_OUTPUT_B);
}

#endif

