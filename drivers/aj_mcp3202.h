/**
 * @brief   MCP3202 12-bit ADC driver
 *
 * This library provides basic functions to interface with the MCP3202 ADC via SPI.
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
 * - `aj_mcp3202.c`
 *
 * -----------------------------------------------------------------------------
 * REQUIREMENT 3: Configuration Override
 * -----------------------------------------------------------------------------
 * The default driver macros are declared in the following headers:
 * - `aj_target.h`
 * - `aj_spi_config.h`
 * - `aj_mcp3202_config_platform.h`
 *
 * To customize these configurations, override them inside the central project
 * hardware configuration file:
 * - `hardware.h`
 *
 * @author  AliReza Joodi
 * @see     https://github.com/AliRezaJoodi
 */

#ifndef AJ_MCP3202_INCLUDED
#define AJ_MCP3202_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif


#include <stdint.h>
#include "aj_mcp3202_type.h"
#include "aj_mcp3202_config_platform.h"     /**< refer to main.c*/

/** Initializes the MCP3202 by configuring the CS pin and setting it to idle state. */
void AJ_MCP3202_Init(aj_mcp3202_t *mcp);

/** Reads and returns the raw 12-bit ADC value from channel 0. */
uint16_t AJ_MCP3202_ReadRaw_Ch0(aj_mcp3202_t *mcp);

/** Reads and returns the raw 12-bit ADC value from channel 1. */
uint16_t AJ_MCP3202_ReadRaw_Ch1(aj_mcp3202_t *mcp);

/** Reads and returns the raw 12-bit ADC value from differential channel CH0-CH1. */
uint16_t AJ_MCP3202_ReadRaw_Ch0Ch1(aj_mcp3202_t *mcp);

/** Reads and returns the raw 12-bit ADC value from differential channel CH1-CH0. */
uint16_t AJ_MCP3202_ReadRaw_Ch1Ch0(aj_mcp3202_t *mcp);


#ifdef __cplusplus
}
#endif

#endif

