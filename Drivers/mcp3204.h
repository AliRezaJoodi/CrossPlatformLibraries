/**
 * @brief   MCP3204 12-bit ADC driver
 *
 * This library provides basic functions to interface with the MCP3204 ADC via SPI.
 *
 * @note
 * SPI must be configured by the user before using this library.
 *
 * @author  AliReza Joodi
 * @see     https://github.com/AliRezaJoodi
 */

#ifndef MCP3204_INCLUDED
#define MCP3204_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "mcp3204_port.h"

/**
 * @brief Defines MCP3204 Channels.
 */
typedef enum {
    MCP3204_CH0         = 0U,   /**< CH0(IN+), GND(IN-)*/
    MCP3204_CH1         = 1U,   /**< CH1(IN+), GND(IN-)*/
    MCP3204_CH2         = 2U,   /**< CH2(IN+), GND(IN-)*/
    MCP3204_CH3         = 3U,   /**< CH3(IN+), GND(IN-)*/
    MCP3204_CH0CH1      = 4U,   /**< CH0(IN+), CH1(IN-)*/
    MCP3204_CH1CH0      = 5U,   /**< CH1(IN+), CH0(IN-)*/
    MCP3204_CH2CH3      = 6U,   /**< CH2(IN+), CH3(IN-)*/
    MCP3204_CH3CH2      = 7U    /**< CH3(IN+), CH2(IN-)*/
} MCP3204Channels_t;

/**
 * @brief   Initialize the MCP3204 instance
 *
 * This function initializes the MCP3204 by configuring the CS pin
 * and setting it to idle state.
 *
 * @param   mcp   Pointer to a valid MCP3204_t instance
 */
void MCP3204_Init(MCP3204_t *mcp);

/**
 * @brief   Read raw ADC counts from MCP3204
 *
 * This function performs an SPI transaction to read the 12-bit ADC value
 * from the MCP3204 device.
 *
 * @param   mcp   Pointer to a valid MCP3204_t instance
 * @return  12-bit ADC value as uint16_t (0 to 4095)
 */
uint16_t MCP3204_GetCounts(MCP3204_t *mcp, uint8_t ch);

#ifdef __cplusplus
}
#endif

#endif

