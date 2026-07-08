/**
 * @brief   Public interface for Microchip MCP413x/423x/425x/426x digital potentiometers.
 *
 * @details
 * This header declares the public API for controlling Microchip
 * MCP413x, MCP423x, MCP425x, and MCP426x digital potentiometers
 * over an SPI interface.
 *
 * The driver supports basic wiper control, terminal connection control
 * through the TCON register, and optional hardware pin features such as
 * shutdown and write protection when available in the hardware layer.
 *
 * @note
 * This driver does not configure the SPI peripheral.
 * The application must configure SPI before using this driver.
 *
 * Supported serial interface requirements:
 * - SPI mode 0 (CPOL = 0, CPHA = 0)
 * - SPI mode 3 (CPOL = 1, CPHA = 1)
 * - Data order: MSB first
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
#include "aj_mcp413x_426x_config.h"
#include "aj_mcp413x_426x_type.h"

/** Initializes the device and optional control pins. */
void AJ_MCP413x_426x_Init(const aj_mcp413x_426x_t *mcp);

/** Writes a wiper value to potentiometer 0. */
void AJ_MCP413x_426x_WritePot0(const aj_mcp413x_426x_t *mcp, uint8_t count);

#if (AJ_MCP413X_426X_P1_SUPPORTED == 1U)
/** Writes a wiper value to potentiometer 1. */
void AJ_MCP413x_426x_WritePot1(const aj_mcp413x_426x_t *mcp, uint8_t count);
#endif

/** Enables the selected terminal connection bits in the TCON register. */
void AJ_MCP413x_426x_EnableTerminalControl(const aj_mcp413x_426x_t *mcp, aj_mcp413x_426x_tcon_t mask);

/** Returns nonzero if the selected terminal connection bits are enabled. */
uint8_t AJ_MCP413x_426x_IsTerminalControlEnabled(const aj_mcp413x_426x_t *mcp, aj_mcp413x_426x_tcon_t mask);

/** Disables the selected terminal connection bits in the TCON register. */
void AJ_MCP413x_426x_DisableTerminalControl(const aj_mcp413x_426x_t *mcp, aj_mcp413x_426x_tcon_t mask);

#if (AJ_MCP413X_426X_SHDN_USED == 1U)
/** Forces hardware shutdown through the SHDN pin. */
void AJ_MCP413x_426x_ForceShutdown(const aj_mcp413x_426x_t *mcp);

/** Releases hardware shutdown through the SHDN pin. */
void AJ_MCP413x_426x_ReleaseShutdown(const aj_mcp413x_426x_t *mcp);
#endif

#if (AJ_MCP413X_426X_WP_USED == 1U)
/** Enables hardware write protection through the WP pin. */
void AJ_MCP413x_426x_EnableWriteProtect(const aj_mcp413x_426x_t *mcp);

/** Disables hardware write protection through the WP pin. */
void AJ_MCP413x_426x_DisableWriteProtect(const aj_mcp413x_426x_t *mcp);
#endif

#ifdef __cplusplus
}
#endif

#endif
