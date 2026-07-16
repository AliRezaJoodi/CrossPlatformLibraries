/**
 * @brief   Driver interface for Microchip MCP41XXX_42XXX dual digital potentiometers.
 *
 * @details
 * This file provides the public API for controlling Microchip MCP41XXX_42XXX
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
 * `aj_mcp41XXX_42XXX_hw.h`, allowing the driver to remain portable across different
 * AVR projects and hardware configurations.
 *
 * @note
 * This driver does not configure the SPI peripheral.
 * SPI must be configured by the user application before using this driver.
 * The MCP41XXX_42XXX serial interface supports:
 * - SPI mode 0 (CPOL = 0, CPHA = 0)
 * - SPI mode 3 (CPOL = 1, CPHA = 1)
 * - Data Order: MSB first
 *
 * @author  AliReza Joodi
 * @see     https://github.com/AliRezaJoodi
 */

#ifndef AJ_MCP41XXX_42XXX_INCLUDED
#define AJ_MCP41XXX_42XXX_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif


#include <stdint.h>
#include "aj_mcp41xxx_42xxx_config.h"
#include "aj_mcp41xxx_42xxx_type.h"
#include "aj_mcp41xxx_42xxx_port.h"
#include "aj_mcp41xxx_42xxx_config_platform.h"      /**< refer to main.c*/

/** Initializes the MCP41XXX_42XXX driver and related control pins. */
void AJ_MCP41xxx_42xxx_Init(aj_mcp41xxx_42xxx_t *mcp);

void AJ_MCP41xxx_42xxx_WriteCount(aj_mcp41xxx_42xxx_t *mcp, aj_mcp41xxx_42xxx_ch_t ch, uint8_t count);

void AJ_MCP41xxx_42xxx_Shutdown(aj_mcp41xxx_42xxx_t *mcp, aj_mcp41xxx_42xxx_ch_t ch);

static inline void AJ_MCP41xxx_42xxx_WriteCount_Pot0(aj_mcp41xxx_42xxx_t *mcp, uint8_t count){
    AJ_MCP41xxx_42xxx_WriteCount(mcp, AJ_MCP41XXX_42XXX_POT0, count);
}

static inline void AJ_MCP41xxx_42xxx_WriteCount_Pot1(aj_mcp41xxx_42xxx_t *mcp, uint8_t count){
    AJ_MCP41xxx_42xxx_WriteCount(mcp, AJ_MCP41XXX_42XXX_POT1, count);
}

static inline void AJ_MCP41xxx_42xxx_WriteCount_All(aj_mcp41xxx_42xxx_t *mcp, uint8_t count){
    AJ_MCP41xxx_42xxx_WriteCount(mcp, AJ_MCP41XXX_42XXX_ALL, count);
}

static inline void AJ_MCP41xxx_42xxx_Shutdown_Pot0(aj_mcp41xxx_42xxx_t *mcp){
    AJ_MCP41xxx_42xxx_Shutdown(mcp, AJ_MCP41XXX_42XXX_POT0);
}

static inline void AJ_MCP41xxx_42xxx_Shutdown_Pot1(aj_mcp41xxx_42xxx_t *mcp){
    AJ_MCP41xxx_42xxx_Shutdown(mcp, AJ_MCP41XXX_42XXX_POT1);
}

static inline void AJ_MCP41xxx_42xxx_Shutdown_All(aj_mcp41xxx_42xxx_t *mcp){
    AJ_MCP41xxx_42xxx_Shutdown(mcp, AJ_MCP41XXX_42XXX_ALL);
}
/** Writes a wiper value to potentiometer 0. */
//void AJ_MCP41xxx_42xxx_WritePot0(aj_mcp41xxx_42xxx_t *mcp, uint8_t count);

/** Writes a wiper value to potentiometer 1. */
//void AJ_MCP41xxx_42xxx_WritePot1(aj_mcp41xxx_42xxx_t *mcp, uint8_t count);

/** Writes the same wiper value to both potentiometers. */
//void AJ_MCP41xxx_42xxx_WriteAll(aj_mcp41xxx_42xxx_t *mcp, uint8_t count);

/** Executes software shutdown for potentiometer 0. */
//void AJ_MCP41xxx_42xxx_ShutdownPot0(aj_mcp41xxx_42xxx_t *mcp);

/** Executes software shutdown for potentiometer 1. */
//void AJ_MCP41xxx_42xxx_ShutdownPot1(aj_mcp41xxx_42xxx_t *mcp);

/** Executes software shutdown for both potentiometers. */
//void AJ_MCP41xxx_42xxx_ShutdownAll(aj_mcp41xxx_42xxx_t *mcp);


#if (AJ_MCP41XXX_42XXX_SHDN_USED == 1U)
/** Forces hardware shutdown using the SHDN pin. */
static inline void AJ_MCP41xxx_42xxx_ForceShutdown(aj_mcp41xxx_42xxx_t *mcp){
    AJ_MCP41xxx_42xxx_SHDN_SetActive(mcp);
}

/** Releases hardware shutdown using the SHDN pin. */
static inline void AJ_MCP41xxx_42xxx_ReleaseShutdown(aj_mcp41xxx_42xxx_t *mcp){
    AJ_MCP41xxx_42xxx_SHDN_SetIdle(mcp);
}
#endif

#if (AJ_MCP41XXX_42XXX_RS_USED == 1U)
/** Performs a hardware reset using the RS pin. */
static inline void AJ_MCP41xxx_42xxx_HardwareReset(aj_mcp41xxx_42xxx_t *mcp){
    AJ_MCP41xxx_42xxx_RS_SetActive(mcp);
    AJ_MCP41XXX_42XXX_DELAY_US(1);
    AJ_MCP41xxx_42xxx_RS_SetIdle(mcp);
}
#endif


#ifdef __cplusplus
}
#endif

#endif
