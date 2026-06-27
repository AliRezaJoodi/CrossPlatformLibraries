/**
 * @brief   MCP3201 12-bit ADC driver
 *
 * This library provides basic functions to interface with the MCP3201 ADC via SPI.
 *
 * @note
 * The SPI peripheral is NOT configured by this library.
 * The user must initialize and configure the SPI interface
 * according to the MCP3201 device requirements.
 *
 * Required SPI configuration for MCP3201:
 *   - Mode: 0 (CPOL = 0, CPHA = 0)
 *   - Data Order: MSB first
 *   - Clock Frequency:
 *       * up to 1.6 MHz @ Vdd = 5V
 *       * up to 0.8 MHz @ Vdd = 2.7V
 *
 * @warning
 * Incorrect SPI configuration may lead to invalid DAC output.
 *
 * @author  AliReza Joodi
 * @see     https://github.com/AliRezaJoodi
 */

#ifndef AJ_MCP3201_INCLUDED
#define AJ_MCP3201_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "aj_mcp3201_type.h"

/**
 * @brief   Initialize the MCP3201 instance
 *
 * This function initializes the MCP3201 by configuring the CS pin
 * and setting it to idle state.
 *
 * @param   mcp   Pointer to a valid MCP3201_t instance
 */
void AJ_MCP3201_Init(aj_mcp3201_t *mcp);

/**
 * @brief   Read raw ADC counts from MCP3201
 *
 * This function performs an SPI transaction to read the 12-bit ADC value
 * from the MCP3201 device.
 *
 * @param   mcp   Pointer to a valid MCP3201_t instance
 * @return  12-bit ADC value as uint16_t (0 to 4095)
 */
uint16_t AJ_MCP3201_ReadRaw(aj_mcp3201_t *mcp);

#ifdef __cplusplus
}
#endif

#endif

