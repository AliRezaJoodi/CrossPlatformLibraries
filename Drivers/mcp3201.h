/**
 * @file    mcp3201.h
 * @brief   MCP3201 12-bit ADC driver
 *
 * This library provides basic functions to interface with the MCP3201 ADC
 * via SPI. It includes reading raw counts and converting to millivolts.
 *
 * @note
 * SPI must be configured by the user before using this library.
 *
 * @author  AliReza Joodi
 * @see     https://github.com/AliRezaJoodi
 */

#ifndef MCP3201_INCLUDED
#define MCP3201_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "mcp3201_config.h"
#include "mcp3201_port.h"

/**
 * @brief   Initialize the MCP3201 instance
 *
 * This function initializes the MCP3201 by configuring the CS pin
 * and setting it to idle state.
 *
 * @param   mcp   Pointer to a valid MCP3201_t instance
 */
void MCP3201_Init(MCP3201_t *mcp);

/**
 * @brief   Read raw ADC counts from MCP3201
 *
 * This function performs an SPI transaction to read the 12-bit ADC value
 * from the MCP3201 device.
 *
 * @param   mcp   Pointer to a valid MCP3201_t instance
 * @return  12-bit ADC value as uint16_t (0..4095)
 */
uint16_t MCP3201_GetCounts(MCP3201_t *mcp);

/**
 * @brief   Convert MCP3201 raw ADC counts to millivolts
 *
 * This function reads the 12-bit ADC value and converts it to voltage
 * using the configured reference (MCP3201_GAIN).
 *
 * @param   mcp   Pointer to a valid MCP3201_t instance
 * @return  ADC voltage in millivolts as float
 */
float MCP3201_GetMilliVolt(MCP3201_t *mcp);

/**
 * @brief   Convert raw ADC counts to millivolts
 *
 * This function converts a given 12-bit ADC value into millivolts
 * using the configured reference (MCP3201_GAIN). Counts exceeding
 * the ADC resolution are clamped to the maximum.
 *
 * @param   counts  12-bit ADC value (0..4095)
 * @return  Voltage in millivolts as float
 */
float MCP3201_ConvertCountsToMilliVolt(uint16_t counts);

#ifdef __cplusplus
}
#endif

#endif

