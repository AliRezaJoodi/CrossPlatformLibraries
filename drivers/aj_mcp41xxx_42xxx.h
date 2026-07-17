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
 * -----------------------------------------------------------------------------
 * REQUIREMENT 1: SPI Configuration
 * -----------------------------------------------------------------------------
 * This library does not configure the microcontroller's SPI peripheral.
 * The application must initialize and enable SPI before using this driver.
 * The SPI interface must meet these parameters:
 * - SPI mode 0 (CPOL = 0, CPHA = 0) or
 * - SPI mode 3 (CPOL = 1, CPHA = 1)
 * - Data order: MSB first
 *
 * -----------------------------------------------------------------------------
 * REQUIREMENT 2: Compilation & Linkage
 * -----------------------------------------------------------------------------
 * The following source files must be compiled and linked in the project:
 * - `aj_spi.c`
 * - `aj_mcp41xxx_42xxx.c`
 *
 * -----------------------------------------------------------------------------
 * REQUIREMENT 3: Configuration Override
 * -----------------------------------------------------------------------------
 * The default driver macros are declared in the following headers:
 * - `aj_target.h`
 * - `aj_spi_config.h`
 * - `aj_mcp41xxx_42xxx_config.h`
 * - `aj_mcp41xxx_42xxx_config_platform.h`
 *
 * To customize these configurations, override them inside the central project
 * hardware configuration file:
 * - `hardware.h`
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

/** Initializes the control pins. */
void AJ_MCP41xxx_42xxx_Init(aj_mcp41xxx_42xxx_t *mcp);

/** Writes a wiper value to potentiometer. */
void AJ_MCP41xxx_42xxx_WriteCount(aj_mcp41xxx_42xxx_t *mcp, aj_mcp41xxx_42xxx_ch_t ch, uint8_t count);

/** Executes software shutdown for potentiometer. */
void AJ_MCP41xxx_42xxx_Shutdown(aj_mcp41xxx_42xxx_t *mcp, aj_mcp41xxx_42xxx_ch_t ch);

/** Writes a wiper value to potentiometer 0. */
static inline void AJ_MCP41xxx_42xxx_WriteCount_Pot0(aj_mcp41xxx_42xxx_t *mcp, uint8_t count){
    AJ_MCP41xxx_42xxx_WriteCount(mcp, AJ_MCP41XXX_42XXX_POT0, count);
}

#if (AJ_MCP41XXX_42XXX_POT1_SUPPORTED == 1U)
/** Writes a wiper value to potentiometer 1. */
static inline void AJ_MCP41xxx_42xxx_WriteCount_Pot1(aj_mcp41xxx_42xxx_t *mcp, uint8_t count){
    AJ_MCP41xxx_42xxx_WriteCount(mcp, AJ_MCP41XXX_42XXX_POT1, count);
}

/** Writes the same wiper value to both potentiometers. */
static inline void AJ_MCP41xxx_42xxx_WriteCount_All(aj_mcp41xxx_42xxx_t *mcp, uint8_t count){
    AJ_MCP41xxx_42xxx_WriteCount(mcp, AJ_MCP41XXX_42XXX_ALL, count);
}
#endif

/** Executes software shutdown for potentiometer 0. */
static inline void AJ_MCP41xxx_42xxx_Shutdown_Pot0(aj_mcp41xxx_42xxx_t *mcp){
    AJ_MCP41xxx_42xxx_Shutdown(mcp, AJ_MCP41XXX_42XXX_POT0);
}

#if (AJ_MCP41XXX_42XXX_POT1_SUPPORTED == 1U)
/** Executes software shutdown for potentiometer 1. */
static inline void AJ_MCP41xxx_42xxx_Shutdown_Pot1(aj_mcp41xxx_42xxx_t *mcp){
    AJ_MCP41xxx_42xxx_Shutdown(mcp, AJ_MCP41XXX_42XXX_POT1);
}

/** Executes software shutdown for both potentiometers. */
static inline void AJ_MCP41xxx_42xxx_Shutdown_All(aj_mcp41xxx_42xxx_t *mcp){
    AJ_MCP41xxx_42xxx_Shutdown(mcp, AJ_MCP41XXX_42XXX_ALL);
}
#endif

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
