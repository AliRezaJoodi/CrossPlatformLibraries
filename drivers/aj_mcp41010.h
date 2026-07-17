/**
 * @brief   MCP41010 model-specific wrapper for `aj_mcp41xxx_42xxx.h`.
 *
 * @details
 * For driver requirements, usage notes, and the generic API description,
 * refer to `aj_mcp41xxx_42xxx.h`.
 *
 * If `MCP41010` is used from this device family, the configuration macros
 * from `aj_mcp41xxx_42xxx_config.h` should be overridden as follows:
 * - `AJ_MCP41XXX_42XXX_POT1_SUPPORTED` : `0U`
 * - `AJ_MCP41XXX_42XXX_SHDN_USED` : `0U`
 * - `AJ_MCP41XXX_42XXX_RS_USED` : `0U`
 *
 * @author  AliReza Joodi
 * @see     https://github.com/AliRezaJoodi
 */

#ifndef AJ_MCP41010_INCLUDED
#define AJ_MCP41010_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif


#include <stdint.h>
#include "aj_mcp41xxx_42xxx.h"
#include "aj_mcp41010_config_platform.h"        /**< refer to main.c*/

typedef aj_mcp41xxx_42xxx_t             aj_mcp41010_t;

static inline void AJ_MCP41010_Init(aj_mcp41010_t *mcp){
    AJ_MCP41xxx_42xxx_Init(mcp);
}

/** Writes a wiper value to potentiometer 0. */
static inline void AJ_MCP41010_WriteCount_Pot0(aj_mcp41010_t *mcp, uint8_t count){
    AJ_MCP41xxx_42xxx_WriteCount(mcp, AJ_MCP41XXX_42XXX_POT0, count);
}

/** Executes software shutdown for potentiometer 0. */
static inline void AJ_MCP41010_Shutdown_Pot0(aj_mcp41010_t *mcp){
    AJ_MCP41xxx_42xxx_Shutdown(mcp, AJ_MCP41XXX_42XXX_POT0);
}


#ifdef __cplusplus
}
#endif

#endif

