/**
 * @brief   MCP3204_3208 12-bit ADC driver
 *
 * This library provides basic functions to interface with the MCP3204_3208 ADC via SPI.
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
 * - `aj_mcp3204_3208.c`
 *
 * -----------------------------------------------------------------------------
 * REQUIREMENT 3: Configuration Override
 * -----------------------------------------------------------------------------
 * The default driver configuration macros are declared in the following headers:
 * - `aj_target.h`
 * - `aj_spi_config.h`
 * - `aj_mcp3204_3208_config.h`
 * - `aj_mcp3204_3208_config_platform.h`
 *
 * To customize these configurations, override them inside the central project
 * hardware configuration file:
 * - `hardware.h`
 *
 * If the driver is accessed through a device-specific wrapper, use the
 * corresponding wrapper configuration interface instead of directly
 * overriding macros from `aj_mcp3204_3208_config_platform.h`:
 * - `aj_mcp3204_config_platform.h` when using the `aj_mcp3204` wrapper
 * - `aj_mcp3208_config_platform.h` when using the `aj_mcp3208` wrapper
 *
 * @author  AliReza Joodi
 * @see     https://github.com/AliRezaJoodi
 */

#ifndef AJ_MCP3204_3208_INCLUDED
#define AJ_MCP3204_3208_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif


#include <stdint.h>
#include "aj_mcp3204_3208_config_platform.h"        /**< refer to main.c*/
#include "aj_mcp3204_3208_type.h"

/**
 * @brief   Initialize the MCP3204_3208 instance
 *
 * This function initializes the MCP3204_3208 by configuring the CS pin
 * and setting it to idle state.
 *
 * @param   mcp   Pointer to a valid MCP3204_3208_t instance
 */
void AJ_MCP3204_3208_Init(aj_mcp3204_3208_t *mcp);

/**
 * @brief   Read raw ADC counts from MCP3204_3208
 *
 * This function performs an SPI transaction to read the 12-bit ADC value
 * from the MCP3204_3208 device.
 *
 * @param   mcp   Pointer to a valid and initialized MCP3204_3208_t instance
 * @param   ch    Input channel selection (single-ended or differential)
 * @return  12-bit ADC value as uint16_t (0 to 4095)
 */
uint16_t AJ_MCP3204_3208_ReadRaw(aj_mcp3204_3208_t *mcp, aj_mcp3204_3208_ch_t ch);


#ifdef __cplusplus
}
#endif

#endif

