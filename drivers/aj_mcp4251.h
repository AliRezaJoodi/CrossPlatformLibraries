/**
 * @brief   MCP4251 model-specific wrapper for `aj_mcp413x_426x.h`.
 *
 * @details
 * For driver requirements, usage notes, and the generic API description,
 * refer to `aj_mcp413x_426x.h`.
 *
 * If only `MCP4251` is used from this device family, the configuration macros
 * from `aj_mcp413x_426x_config.h` should be overridden as follows:
 * - `AJ_MCP413X_426X_BITS`          : `8U`
 * - `AJ_MCP413X_426X_P1_SUPPORTED`  : `1U`
 * - `AJ_MCP413X_426X_P0A_SUPPORTED` : `1U`
 * - `AJ_MCP413X_426X_P1A_SUPPORTED` : `1U`
 * - `AJ_MCP413X_426X_SHDN_USED`     : optional
 * - `AJ_MCP413X_426X_WP_USED`       : `0U`
 *
 * @author  AliReza Joodi
 * @see     https://github.com/AliRezaJoodi
 */

#ifndef AJ_MCP4251_INCLUDED
#define AJ_MCP4251_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif


#include <stdint.h>
#include "aj_mcp413x_426x.h"
#include "aj_mcp4251_config_platform.h"        /**< refer to main.c*/

typedef aj_mcp413x_426x_t           aj_mcp4251_t;
typedef aj_mcp413x_426x_terminal_t  aj_mcp4251_terminal_t;

/* Valid symbolic values for aj_mcp4251_tcon_t. */
#define AJ_MCP4251_TERMINAL_P0B     AJ_MCP413X_426X_TERMINAL_P0B
#define AJ_MCP4251_TERMINAL_P0W     AJ_MCP413X_426X_TERMINAL_P0W
#define AJ_MCP4251_TERMINAL_P0A     AJ_MCP413X_426X_TERMINAL_P0A
#define AJ_MCP4251_TERMINAL_P0HW    AJ_MCP413X_426X_TERMINAL_P0HW
#define AJ_MCP4251_TERMINAL_P1B     AJ_MCP413X_426X_TERMINAL_P1B
#define AJ_MCP4251_TERMINAL_P1W     AJ_MCP413X_426X_TERMINAL_P1W
#define AJ_MCP4251_TERMINAL_P1A     AJ_MCP413X_426X_TERMINAL_P1A
#define AJ_MCP4251_TERMINAL_P1HW    AJ_MCP413X_426X_TERMINAL_P1HW
#define AJ_MCP4251_TERMINAL_ALL     AJ_MCP413X_426X_TERMINAL_ALL

/* Initializes the MCP4251 device interface. */
static inline void AJ_MCP4251_Init(const aj_mcp4251_t *dev){
    AJ_MCP413x_426x_Init(dev);
}

/* Writes a new wiper value to potentiometer 0. */
static inline void AJ_MCP4251_WriteCount_Pot0(const aj_mcp4251_t *dev, uint8_t value){
    AJ_MCP413x_426x_WriteCount_Pot0(dev, value);
}

/* Writes a new wiper value to potentiometer 1. */
static inline void AJ_MCP4251_WriteCount_Pot1(const aj_mcp4251_t *dev, uint8_t value){
    AJ_MCP413x_426x_WriteCount_Pot1(dev, value);
}

/* Enables the selected terminal-control connections. */
static inline void AJ_MCP4251_EnableTerminalControl(const aj_mcp4251_t *dev, aj_mcp4251_terminal_t mask){
    AJ_MCP413x_426x_EnableTerminalControl(dev, mask);
}

/* Returns non-zero if the selected terminal-control connections are enabled. */
static inline uint8_t AJ_MCP4251_IsTerminalControlEnabled(const aj_mcp4251_t *dev, aj_mcp4251_terminal_t mask){
    return AJ_MCP413x_426x_IsTerminalControlEnabled(dev, mask);
}

/* Disables the selected terminal-control connections. */
static inline void AJ_MCP4251_DisableTerminalControl(const aj_mcp4251_t *dev, aj_mcp4251_terminal_t mask){
    AJ_MCP413x_426x_DisableTerminalControl(dev, mask);
}

#if (AJ_MCP413X_426X_SHDN_USED == 1U)
/* Forces the device into hardware shutdown mode. */
static inline void AJ_MCP4251_ForceShutdown(const aj_mcp4251_t *dev){
    AJ_MCP413x_426x_ForceShutdown(dev);
}

/* Releases the device from hardware shutdown mode. */
static inline void AJ_MCP4251_ReleaseShutdown(const aj_mcp4251_t *dev){
    AJ_MCP413x_426x_ReleaseShutdown(dev);
}
#endif


#ifdef __cplusplus
}
#endif

#endif
