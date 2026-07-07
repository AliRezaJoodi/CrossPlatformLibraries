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

#ifndef AJ_MCP413X_426X_INCLUDED
#define AJ_MCP413X_426X_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "aj_mcp413x_426x_hw.h"
#include "aj_mcp413x_426x_type.h"

/** Initializes the MCP42xxx driver and related control pins. */
void AJ_MCP413x_426x_Init(aj_mcp413x_426x_t *mcp);

/** Writes a wiper value to potentiometer 0. */
void AJ_MCP413x_426x_WritePot0(aj_mcp413x_426x_t *mcp, uint8_t count);

/** Writes a wiper value to potentiometer 1. */
void AJ_MCP413x_426x_WritePot1(aj_mcp413x_426x_t *mcp, uint8_t count);

//uint8_t AJ_MCP413x_426x_ReadTerminalControl(aj_mcp413x_426x_t *mcp);
void AJ_MCP413x_426x_EnableTerminalControl(aj_mcp413x_426x_t *mcp, aj_mcp413x_426x_tcon_t mask);
uint8_t AJ_MCP413x_426x_IsTerminalControlEnabled(aj_mcp413x_426x_t *mcp, aj_mcp413x_426x_tcon_t mask);
void AJ_MCP413x_426x_DisableTerminalControl(aj_mcp413x_426x_t *mcp, aj_mcp413x_426x_tcon_t mask);

///** Executes software shutdown for potentiometer 0. */
//void AJ_MCP413x_426x_ShutdownPot0(aj_mcp413x_426x_t *mcp);
//
///** Executes software shutdown for potentiometer 1. */
//void AJ_MCP413x_426x_ShutdownPot1(aj_mcp413x_426x_t *mcp);
//
///** Executes software shutdown for both potentiometers. */
//void AJ_MCP413x_426x_ShutdownAll(aj_mcp413x_426x_t *mcp);


#if (AJ_MCP413X_426X_SHDN_USED == 1U)
/** Forces hardware shutdown using the SHDN pin. */
void AJ_MCP413x_426x_ForceShutdown(aj_mcp413x_426x_t *mcp);

/** Releases hardware shutdown using the SHDN pin. */
void AJ_MCP413x_426x_ReleaseShutdown(aj_mcp413x_426x_t *mcp);
#endif

#ifdef __cplusplus
}
#endif

#endif
