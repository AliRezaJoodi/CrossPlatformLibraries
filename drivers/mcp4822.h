/**
 * @brief   MCP4822 12-bit DAC driver
 *
 * This library provides basic functions to interface with the MCP4822 DAC via SPI.
 *
 * @note
 * The SPI peripheral is NOT configured by this library.
 * The user must initialize and configure the SPI interface
 * according to the MCP4822 device requirements.
 *
 * Required SPI configuration for MCP4822:
 *   - Mode: 0 (CPOL = 0, CPHA = 0)
 *   - Data Order: MSB first
 *   - Clock Frequency: up to 20 MHz (see datasheet, depends on Vdd)
 *
 * @warning
 * Incorrect SPI configuration may lead to invalid DAC output.
 *
 * @author  AliReza Joodi
 * @see     https://github.com/AliRezaJoodi
 */

#ifndef MCP4822_INCLUDED
#define MCP4822_INCLUDED

#include <stdint.h>
#include "mcp4822_types.h"

typedef enum {
    MCP4822_OUTPUT_A = 0U,
    MCP4822_OUTPUT_B = 1U
} MCP4822_Channel_t;

typedef enum {
    MCP4822_GAIN_2X = 0U,   /**< Vout: 0 to 4.096V */
    MCP4822_GAIN_1X = 1U    /**< Vout: 0 to 2.048V */
} MCP4822_Gain_t;

/**
 * @brief   Initialize MCP4822 control pins
 *
 * This function initializes the required GPIO pins for the MCP4822 device,
 * including Chip Select (CS) and Load DAC (LDAC), and sets them to their
 * default idle states.
 *
 * @param[in] dac   Pointer to MCP4822 device handle
 *
 * @note
 * This function only initializes GPIO control pins. The SPI peripheral
 * must be configured separately before using other functions.
 *
 * @warning
 * The 'dac' pointer must be properly initialized before calling this function.
 */
void MCP4822_Init(MCP4822_t *dac);

/**
 * @brief   Set DAC output value for a selected channel
 *
 * This function updates the output value of the specified MCP4822 channel
 * (A or B) using SPI communication. The output is latched using the LDAC pin.
 *
 * @param[in] dac    Pointer to MCP4822 device handle
 * @param[in] ch    Output channel:
 *                  - MCP4822_OUTPUT_A
 *                  - MCP4822_OUTPUT_B
 * @param[in] gain   Output gain selection:
 *                   - MCP4822_GAIN_1X: Vout = 0 to 2.048V
 *                   - MCP4822_GAIN_2X: Vout = 0 to 4.096V
 * @param[in] value  12-bit DAC value (0 to 4095)
 *
 * @note
 * The input value is 12-bit. Higher bits (if any) are ignored.
 *
 * @note
 * The output is updated after LDAC pulse. Ensure LDAC pin is properly connected
 * and controlled for correct operation.
 *
 * @warning
 * Invalid channel or gain values may lead to undefined behavior.
 *
 */
void MCP4822_SetOutput(MCP4822_t *dac, MCP4822_Channel_t ch, MCP4822_Gain_t gain, uint16_t value);

/**
 * @brief   Disable DAC output for a selected channel
 *
 * This function disables the specified MCP4822 channel (A or B) by putting
 * it into shutdown mode via SPI command. In this state, the output is
 * internally disconnected and driven to high impedance.
 *
 * @param[in] dac   Pointer to MCP4822 device handle
 * @param[in] ch    Output channel:
 *                  - MCP4822_OUTPUT_A
 *                  - MCP4822_OUTPUT_B
 *
 * @note
 * This function does not set the output value to zero. Instead, it places the DAC channel in shutdown mode.
 *
 * @warning
 * Invalid channel values may lead to undefined behavior.
 */
void MCP4822_DisableOutput(MCP4822_t *dac, MCP4822_Channel_t ch);

/**
 * @brief   Set output value for channel A
 * This is a convenience wrapper for MCP4822_SetOutput() that selects channel A automatically.
 *
 * @param[in] dac    Pointer to MCP4822 device handle
 * @param[in] gain   Output gain selection:
 *                   - MCP4822_GAIN_1X
 *                   - MCP4822_GAIN_2X
 * @param[in] value  12-bit DAC value (0 to 4095)
 */
static inline void MCP4822_SetOutputA(MCP4822_t *dac, MCP4822_Gain_t gain, uint16_t value){
    MCP4822_SetOutput(dac, MCP4822_OUTPUT_A, gain, value);
}

/**
 * @brief   Set output value for channel A with 1x gain
 * This is a convenience wrapper for MCP4822_SetOutput() that selects channel A and 1x gain automatically.
 *
 * @param[in] dac    Pointer to MCP4822 device handle
 * @param[in] value  12-bit DAC value (0 to 4095)
 */
static inline void MCP4822_SetOutputA_1xGain(MCP4822_t *dac, uint16_t value){
    MCP4822_SetOutput(dac, MCP4822_OUTPUT_A, MCP4822_GAIN_1X, value);
}

/**
 * @brief   Set output value for channel A with 2x gain
 * This is a convenience wrapper for MCP4822_SetOutput() that selects channel A and 2x gain automatically.
 *
 * @param[in] dac    Pointer to MCP4822 device handle
 * @param[in] value  12-bit DAC value (0 to 4095)
 */
static inline void MCP4822_SetOutputA_2xGain(MCP4822_t *dac, uint16_t value){
    MCP4822_SetOutput(dac, MCP4822_OUTPUT_A, MCP4822_GAIN_2X, value);
}

/**
 * @brief   Set output value for channel B
 * This is a convenience wrapper for MCP4822_SetOutput() that selects channel B automatically.
 *
 * @param[in] dac    Pointer to MCP4822 device handle
 * @param[in] gain   Output gain selection:
 *                   - MCP4822_GAIN_1X
 *                   - MCP4822_GAIN_2X
 * @param[in] value  12-bit DAC value (0 to 4095)
 */
static inline void MCP4822_SetOutputB(MCP4822_t *dac, MCP4822_Gain_t gain, uint16_t value){
    MCP4822_SetOutput(dac, MCP4822_OUTPUT_B, gain, value);
}

/**
 * @brief   Set output value for channel B with 1x gain
 * This is a convenience wrapper for MCP4822_SetOutput() that selects channel B and 1x gain automatically.
 *
 * @param[in] dac    Pointer to MCP4822 device handle
 * @param[in] value  12-bit DAC value (0 to 4095)
 */
static inline void MCP4822_SetOutputB_1xGain(MCP4822_t *dac, uint16_t value){
    MCP4822_SetOutput(dac, MCP4822_OUTPUT_B, MCP4822_GAIN_1X, value);
}

/**
 * @brief   Set output value for channel B with 2x gain
 * This is a convenience wrapper for MCP4822_SetOutput() that selects channel B and 2x gain automatically.
 *
 * @param[in] dac    Pointer to MCP4822 device handle
 * @param[in] value  12-bit DAC value (0 to 4095)
 */
static inline void MCP4822_SetOutputB_2xGain(MCP4822_t *dac, uint16_t value){
    MCP4822_SetOutput(dac, MCP4822_OUTPUT_B, MCP4822_GAIN_2X, value);
}

/**
 * @brief   Disable output for channel A
 * This is a convenience wrapper for MCP4822_DisableOutput() that selects channel A automatically.
 *
 * @param[in] dac   Pointer to MCP4822 device handle
 */
static inline void MCP4822_DisableOutputA(MCP4822_t *dac){
    MCP4822_DisableOutput(dac, MCP4822_OUTPUT_A);
}

/**
 * @brief   Disable output for channel B
 * This is a convenience wrapper for MCP4822_DisableOutput() that selects channel B automatically.
 *
 * @param[in] dac   Pointer to MCP4822 device handle
 */
static inline void MCP4822_DisableOutputB(MCP4822_t *dac){
    MCP4822_DisableOutput(dac, MCP4822_OUTPUT_B);
}

#endif

