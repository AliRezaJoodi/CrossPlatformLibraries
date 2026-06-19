/**
 * @brief   Driver interface for Microchip MCP41xxx single digital potentiometers.
 *
 * @details
 * This file provides the public API for controlling Microchip MCP41xxx
 * digital potentiometers through an SPI interface.
 *
 * The driver supports writing independent wiper values to Potentiometer
 * and executing software shutdown commands through SPI.
 *
 * @note
 * This driver does not configure the SPI peripheral.
 * SPI must be configured by the user application before using this driver.
 * The MCP41xxx serial interface supports:
 * - SPI mode 0 (CPOL = 0, CPHA = 0)
 * - SPI mode 3 (CPOL = 1, CPHA = 1)
 *
 * @author  AliReza Joodi
 * @see     https://github.com/AliRezaJoodi
 */

#ifndef AJ_MCP41XXX_INCLUDED
#define AJ_MCP41XXX_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "aj_mcp41xxx_type.h"

/** Initializes the MCP41xxx driver and related control pins. */
void AJ_MCP41xxx_Init(aj_mcp41xxx_t *mcp);

/** Writes a wiper value to potentiometer. */
void AJ_MCP41xxx_Write(aj_mcp41xxx_t *mcp, uint8_t count);

/** Executes software shutdown for potentiometer. */
void AJ_MCP41xxx_Shutdown(aj_mcp41xxx_t *mcp);

#ifdef __cplusplus
}
#endif

#endif
