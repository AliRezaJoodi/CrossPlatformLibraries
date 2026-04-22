/**
 * @brief   MCP3208 12-bit ADC driver
 *
 * This library provides basic functions to interface with the MCP3208 ADC via SPI.
 *
 * @note
 * The SPI peripheral is NOT configured by this library.
 * The user must initialize and configure the SPI interface
 * according to the MCP3208 device requirements.
 *
 * Required SPI configuration for MCP3208:
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

#ifndef MCP3208_INCLUDED
#define MCP3208_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "mcp3208_types.h"

/**
 * @brief Defines MCP3208 Channels.
 */
typedef enum {
    MCP3208_CH0         = 0U,   /**< CH0(IN+), GND(IN-)*/
    MCP3208_CH1         = 1U,   /**< CH1(IN+), GND(IN-)*/
    MCP3208_CH2         = 2U,   /**< CH2(IN+), GND(IN-)*/
    MCP3208_CH3         = 3U,   /**< CH3(IN+), GND(IN-)*/
    MCP3208_CH4         = 4U,   /**< CH4(IN+), GND(IN-)*/
    MCP3208_CH5         = 5U,   /**< CH5(IN+), GND(IN-)*/
    MCP3208_CH6         = 6U,   /**< CH6(IN+), GND(IN-)*/
    MCP3208_CH7         = 7U,   /**< CH7(IN+), GND(IN-)*/
    MCP3208_CH0CH1      = 8U,   /**< CH0(IN+), CH1(IN-)*/
    MCP3208_CH1CH0      = 9U,   /**< CH1(IN+), CH0(IN-)*/
    MCP3208_CH2CH3      = 10U,  /**< CH2(IN+), CH3(IN-)*/
    MCP3208_CH3CH2      = 11U,  /**< CH3(IN+), CH2(IN-)*/
    MCP3208_CH4CH5      = 12U,  /**< CH4(IN+), CH5(IN-)*/
    MCP3208_CH5CH4      = 13U,  /**< CH5(IN+), CH4(IN-)*/
    MCP3208_CH6CH7      = 14U,  /**< CH6(IN+), CH7(IN-)*/
    MCP3208_CH7CH6      = 15U   /**< CH7(IN+), CH6(IN-)*/
} MCP3208_Channel_t;

/**
 * @brief   Initialize the MCP3208 instance
 *
 * This function initializes the MCP3208 by configuring the CS pin
 * and setting it to idle state.
 *
 * @param   mcp   Pointer to a valid MCP3208_t instance
 */
void MCP3208_Init(MCP3208_t *mcp);

/**
 * @brief   Read raw ADC counts from MCP3208
 *
 * This function performs an SPI transaction to read the 12-bit ADC value
 * from the MCP3208 device.
 *
 * @param   mcp   Pointer to a valid and initialized MCP3208_t instance
 * @param   ch    Input channel selection (single-ended or differential)
 * @return  12-bit ADC value as uint16_t (0 to 4095)
 */
uint16_t MCP3208_GetCounts(MCP3208_t *mcp, MCP3208_Channel_t ch);

#ifdef __cplusplus
}
#endif

#endif

