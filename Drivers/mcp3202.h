/**
 * @brief   MCP3202 12-bit ADC driver
 *
 * This library provides basic functions to interface with the MCP3202 ADC via SPI.
 *
 * @note
 * SPI must be configured by the user before using this library.
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
#include "utility_bit.h"
#include "mcp3202_port.h"

/**
 * @brief Defines MCP3202 Channels.
 */
typedef enum {
    MCP3202_CH0         = 0U,   /**< CH0(IN+), GND(IN-)*/
    MCP3202_CH1         = 1U,   /**< CH1(IN+), GND(IN-)*/
    MCP3202_CH0CH1      = 2U,   /**< CH0(IN+), CH1(IN-)*/
    MCP3202_CH1CH0      = 3U    /**< CH1(IN+), CH0(IN-)*/
} MCP3202Channels_t;

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
 * @return  12-bit ADC value as uint16_t (0 to 4095)
 */
uint16_t MCP3202_GetCounts(MCP3202_t *mcp, uint8_t ch);

#ifdef __cplusplus
}
#endif

#endif

