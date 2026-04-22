/**
 * @brief   MCP3202 12-bit ADC driver
 *
 * This library provides basic functions to interface with the MCP3202 ADC via SPI.
 *
 * @note
 * The SPI peripheral is NOT configured by this library.
 * The user must initialize and configure the SPI interface
 * according to the MCP3202 device requirements.
 *
 * Required SPI configuration for MCP3202:
 *   - Mode: 0 (CPOL = 0, CPHA = 0)
 *   - Data Order: MSB first
 *   - Clock Frequency:
 *       * up to 1.6 MHz @ Vdd = 5V
 *       * up to 0.8 MHz @ Vdd = 2.7V
 *
 * @warning
 * Incorrect SPI configuration may lead to invalid ADC readings.
 *
 * @author  AliReza Joodi
 * @see     https://github.com/AliRezaJoodi
 */

#ifndef MCP3202_INCLUDED
#define MCP3202_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "mcp3202_types.h"

/**
 * @brief Defines MCP3202 Channels.
 */
typedef enum {
    MCP3202_CH0         = 0U,   /**< CH0(IN+), GND(IN-)*/
    MCP3202_CH1         = 1U,   /**< CH1(IN+), GND(IN-)*/
    MCP3202_CH0CH1      = 2U,   /**< CH0(IN+), CH1(IN-)*/
    MCP3202_CH1CH0      = 3U    /**< CH1(IN+), CH0(IN-)*/
} MCP3202_Channel_t;

/**
 * @brief   Initialize the MCP3202 instance
 *
 * This function initializes the MCP3202 by configuring the CS pin
 * and setting it to idle state.
 *
 * @param   mcp   Pointer to a valid MCP3202_t instance
 */
void MCP3202_Init(MCP3202_t *mcp);

/**
 * @brief   Read raw ADC counts from MCP3202
 *
 * This function performs an SPI transaction to read the 12-bit ADC value
 * from the MCP3202 device.
 *
 * @param   mcp   Pointer to a valid MCP3202_t instance
 * @param   ch    Input channel selection (single-ended or differential)
 * @return  12-bit ADC value as uint16_t (0 to 4095)
 */
uint16_t MCP3202_GetCounts(MCP3202_t *mcp, MCP3202_Channel_t ch);

#ifdef __cplusplus
}
#endif

#endif

