/**
 * @brief   Driver interface for Microchip MCP42xxx dual digital potentiometers.
 *
 * @details
 * This file provides the public API for controlling Microchip MCP42xxx
 * digital potentiometers through an SPI interface.
 *
 * The driver supports writing independent wiper values to Potentiometer 0
 * and Potentiometer 1, writing both potentiometers simultaneously, and
 * executing software shutdown commands through SPI.
 *
 * Optional hardware control functions are also provided when enabled in the
 * hardware configuration layer:
 * - SHDN pin control for forcing and releasing hardware shutdown.
 * - RS pin control for performing a hardware reset.
 *
 * The low-level SPI transfer and GPIO handling are abstracted in
 * `aj_mcp42xxx_hw.h`, allowing the driver to remain portable across different
 * AVR projects and hardware configurations.
 *
 * @note
 * This driver does not configure the SPI peripheral.
 * SPI must be configured by the user application before using this driver.
 * The MCP42xxx serial interface supports:
 * - SPI mode 0 (CPOL = 0, CPHA = 0)
 * - SPI mode 3 (CPOL = 1, CPHA = 1)
 * - Data Order: MSB first
 *
 * @author  AliReza Joodi
 * @see     https://github.com/AliRezaJoodi
 */

#ifndef AJ_MCP42XXX_INCLUDED
#define AJ_MCP42XXX_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "aj_mcp42xxx_hw.h"
#include "aj_mcp42xxx_type.h"

/** Initializes the MCP42xxx driver and related control pins. */
void AJ_MCP42xxx_Init(aj_mcp42xxx_t *mcp);

/** Writes a wiper value to potentiometer 0. */
void AJ_MCP42xxx_WritePot0(aj_mcp42xxx_t *mcp, uint8_t count);

/** Writes a wiper value to potentiometer 1. */
void AJ_MCP42xxx_WritePot1(aj_mcp42xxx_t *mcp, uint8_t count);

/** Writes the same wiper value to both potentiometers. */
void AJ_MCP42xxx_WriteAll(aj_mcp42xxx_t *mcp, uint8_t count);

/** Executes software shutdown for potentiometer 0. */
void AJ_MCP42xxx_ShutdownPot0(aj_mcp42xxx_t *mcp);

/** Executes software shutdown for potentiometer 1. */
void AJ_MCP42xxx_ShutdownPot1(aj_mcp42xxx_t *mcp);

/** Executes software shutdown for both potentiometers. */
void AJ_MCP42xxx_ShutdownAll(aj_mcp42xxx_t *mcp);


#if (AJ_MCP42XXX_SUPPORT_PIN_SHDN == 1U)
/** Forces hardware shutdown using the SHDN pin. */
void AJ_MCP42xxx_ForceShutdown(aj_mcp42xxx_t *mcp);

/** Releases hardware shutdown using the SHDN pin. */
void AJ_MCP42xxx_ReleaseShutdown(aj_mcp42xxx_t *mcp);
#endif

#if (AJ_MCP42XXX_SUPPORT_PIN_RS == 1U)
/** Performs a hardware reset using the RS pin. */
void AJ_MCP42xxx_HardwareReset(aj_mcp42xxx_t *mcp);
#endif

#ifdef __cplusplus
}
#endif

#endif
