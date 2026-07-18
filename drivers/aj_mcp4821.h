/**
 * @brief   MCP4821 model-specific wrapper for `aj_mcp4821_4822.h`.
 *
 * @details
 * For driver requirements, usage notes, and the generic API description,
 * refer to `aj_mcp4821_4822.h`.
 *
 * If only `MCP4821` is used from this device family, the configuration macros
 * from `aj_mcp4821_4822_config.h` should be overridden as follows:
 * - `AJ_MCP4821_4822_CHB_SUPPORTED` : `1U`
 * - `AJ_MCP4821_4822_SHDN_USED` : `Optional`
 *
 * @author  AliReza Joodi
 * @see     https://github.com/AliRezaJoodi
 */

#ifndef AJ_MCP4821_INCLUDED
#define AJ_MCP4821_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif


#include <stdint.h>
#include "aj_mcp4821_4822.h"
#include "aj_mcp4821_4822_config.h"
#include "aj_mcp4821_config_platform.h"     /**< refer to main.c*/

typedef aj_mcp4821_4822_t           aj_mcp4821_t;

static inline void AJ_MCP4821_Init(aj_mcp4821_t *dac){
    AJ_MCP4821_4822_Init(dac);
}

/**
 * @brief   Set output value for channel A with 1x gain
 * This is a convenience wrapper for AJ_MCP4821_4822_WriteCount() that selects channel A and 1x gain automatically.
 *
 * @param[in] dac    Pointer to MCP4821_4822 device handle
 * @param[in] value  12-bit DAC value (0 to 4095)
 */
static inline void AJ_MCP4821_WriteCount_ChA_2V048(aj_mcp4821_t *dac, uint16_t count){
    AJ_MCP4821_4822_WriteCount(dac, AJ_MCP4821_4822_CH_A, AJ_MCP4821_4822_FS_2V048, count);
}

/**
 * @brief   Set output value for channel A with 2x gain
 * This is a convenience wrapper for AJ_MCP4821_4822_WriteCount() that selects channel A and 2x gain automatically.
 *
 * @param[in] dac    Pointer to MCP4821_4822 device handle
 * @param[in] value  12-bit DAC value (0 to 4095)
 */
static inline void AJ_MCP4821_WriteCount_ChA_4V096(aj_mcp4821_t *dac, uint16_t count){
    AJ_MCP4821_4822_WriteCount(dac, AJ_MCP4821_4822_CH_A, AJ_MCP4821_4822_FS_4V096, count);
}

/**
 * @brief   Disable output for channel A
 * This is a convenience wrapper for AJ_MCP4821_4822_Shutdown() that selects channel A automatically.
 *
 * @param[in] dac   Pointer to MCP4821_4822 device handle
 */
static inline void AJ_MCP4821_Shutdown_ChA(aj_mcp4821_t *dac){
    AJ_MCP4821_4822_Shutdown(dac, AJ_MCP4821_4822_CH_A);
}

#if (AJ_MCP4821_4822_SHDN_USED == 1U)
/** Forces hardware shutdown using the SHDN pin. */
static inline void AJ_MCP4821_ForceShutdown(aj_mcp4821_t *mcp){
    AJ_MCP4821_4822_ForceShutdown(mcp);
}

/** Releases hardware shutdown using the SHDN pin. */
static inline void AJ_MCP4821_ReleaseShutdown(aj_mcp4821_t *mcp){
    AJ_MCP4821_4822_ReleaseShutdown(mcp);
}
#endif


#ifdef __cplusplus
}
#endif

#endif
