/**
 * @brief   Public interface for Microchip digital potentiometers.
 * * Supported Devices in the Family:
 * - `MCP4131 / MCP4132`
 * - `MCP4141 / MCP4142`
 * - `MCP4151 / MCP4152`
 * - `MCP4161 / MCP4162`
 * - `MCP4231 / MCP4232`
 * - `MCP4241 / MCP4242`
 * - `MCP4251 / MCP4252`
 * - `MCP4261 / MCP4262`
 *
 * Note:
 * Do not test this device with an ohmmeter.
 * Test it as a voltage divider: A = VDD, B = GND, measure W.
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
 * - `aj_mcp413x_426x.c`
 * - `aj_spi.c`
 *
 * -----------------------------------------------------------------------------
 * REQUIREMENT 3: Default Configuration
 * -----------------------------------------------------------------------------
 * The default driver macros are declared in the following headers:
 * - `aj_target.h`
 * - `aj_spi_config.h`
 * - `aj_mcp413x_426x_config.h`
 * - `aj_mcp413x_426x_config_platform.h`
 *
 * -----------------------------------------------------------------------------
 * REQUIREMENT 4: User Configuration Override
 * -----------------------------------------------------------------------------
 * This library's default configuration can be customized via the central
 * project hardware configuration file, which MUST be present alongside your
 * project source files. Override the macros inside it:
 * - `hardware.h`
 *
 * -----------------------------------------------------------------------------
 * EXAMPLE PROJECT
 * -----------------------------------------------------------------------------
 * @see    AVR8 training and MCP413x_426x usage example:
 *         https://github.com/AliRezaJoodi/AVR_Exercises/tree/main/DigitalPotentiometer_MCP413x_426x_SPI
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
#include "aj_mcp413x_426x_config_platform.h"        /**< refer to main.c*/
#include "aj_mcp413x_426x_type.h"

/** Initializes the device and optional control pins. */
void AJ_MCP413x_426x_Init(const aj_mcp413x_426x_t *mcp);

/** Writes a wiper value to potentiometer. */
void AJ_MCP413x_426x_WriteCount(const aj_mcp413x_426x_t *mcp, aj_mcp413x_426x_ch_t ch, uint8_t count);

/** Enables the selected terminal connection bits in the TCON register. */
void AJ_MCP413x_426x_EnableTerminalControl(const aj_mcp413x_426x_t *mcp, aj_mcp413x_426x_terminal_t mask);

/** Returns nonzero if the selected terminal connection bits are enabled. */
uint8_t AJ_MCP413x_426x_IsTerminalControlEnabled(const aj_mcp413x_426x_t *mcp, aj_mcp413x_426x_terminal_t mask);

/** Disables the selected terminal connection bits in the TCON register. */
void AJ_MCP413x_426x_DisableTerminalControl(const aj_mcp413x_426x_t *mcp, aj_mcp413x_426x_terminal_t mask);

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
