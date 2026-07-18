/**
 * @brief   MCP4821_4822 12-bit DAC driver
 *
 * This library provides basic functions to interface with the MCP4821_4822 DAC via SPI.
 *
 * -----------------------------------------------------------------------------
 * REQUIREMENT 1: SPI Configuration
 * -----------------------------------------------------------------------------
 * This library does not configure the microcontroller's SPI peripheral.
 * The application must initialize and enable SPI before using this driver.
 * The SPI interface must meet these parameters:
 * - SPI mode 0 (CPOL = 0, CPHA = 0) or
 * - SPI mode 3 (CPOL = 1, CPHA = 1)
 * - Data order: MSB first
 *
 * -----------------------------------------------------------------------------
 * REQUIREMENT 2: Compilation & Linkage
 * -----------------------------------------------------------------------------
 * The following source files must be compiled and linked in the project:
 * - `aj_spi.c`
 * - `aj_mcp4821_4822.c`
 *
 * -----------------------------------------------------------------------------
 * REQUIREMENT 3: Configuration Override
 * -----------------------------------------------------------------------------
 * The default driver macros are declared in the following headers:
 * - `aj_target.h`
 * - `aj_spi_config.h`
 * - `aj_mcp4821_4822_config.h`
 * - `aj_mcp4821_4822_config_platform.h`
 *
 * To customize these configurations, override them inside the central project
 * hardware configuration file:
 * - `hardware.h`
 *
 * @author  AliReza Joodi
 * @see     https://github.com/AliRezaJoodi
 */

#ifndef AJ_MCP4821_4822_INCLUDED
#define AJ_MCP4821_4822_INCLUDED

#include <stdint.h>
#include "aj_mcp4821_4822_type.h"
#include "aj_mcp4821_4822_config.h"
#include "aj_mcp4821_4822_config_platform.h"        /**< refer to main.c*/

/**
 * @brief   Initialize MCP4821_4822 control pins
 *
 * This function initializes the required GPIO pins for the MCP4821_4822 device,
 * including Chip Select (CS) and Load DAC (LDAC), and sets them to their
 * default idle states.
 *
 * @param[in] dac   Pointer to MCP4821_4822 device handle
 *
 * @note
 * This function only initializes GPIO control pins. The SPI peripheral
 * must be configured separately before using other functions.
 *
 * @warning
 * The 'dac' pointer must be properly initialized before calling this function.
 */
void AJ_MCP4821_4822_Init(aj_mcp4821_4822_t *dac);

/**
 * @brief   Set DAC output value for a selected channel
 *
 * This function updates the output value of the specified MCP4821_4822 channel
 * (A or B) using SPI communication. The output is latched using the LDAC pin.
 *
 * @param[in] dac    Pointer to MCP4821_4822 device handle
 * @param[in] ch    Output channel:
 *                  - MCP4821_4822_CH_A
 *                  - MCP4821_4822_CH_B
 * @param[in] gain   Output gain selection:
 *                   - AJ_MCP4821_4822_FS_2V048: Vout = 0 to 2.048V
 *                   - AJ_MCP4821_4822_FS_4V096: Vout = 0 to 4.096V
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
void AJ_MCP4821_4822_WriteCount(aj_mcp4821_4822_t *dac, aj_mcp4821_4822_ch_t ch, aj_mcp4821_4822_scale_t fs, uint16_t count);

/**
 * @brief   Disable DAC output for a selected channel
 *
 * This function disables the specified MCP4821_4822 channel (A or B) by putting
 * it into shutdown mode via SPI command. In this state, the output is
 * internally disconnected and driven to high impedance.
 *
 * @param[in] dac   Pointer to MCP4821_4822 device handle
 * @param[in] ch    Output channel:
 *                  - MCP4821_4822_CH_A
 *                  - MCP4821_4822_CH_B
 *
 * @note
 * This function does not set the output value to zero. Instead, it places the DAC channel in shutdown mode.
 *
 * @warning
 * Invalid channel values may lead to undefined behavior.
 */
void AJ_MCP4821_4822_Shutdown(aj_mcp4821_4822_t *dac, aj_mcp4821_4822_ch_t ch);


#endif

