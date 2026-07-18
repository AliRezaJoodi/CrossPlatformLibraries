/**
 * @brief   MCP4822 model-specific wrapper for `aj_mcp4821_4822.h`.
 *
 * @details
 * For driver requirements, usage notes, and the generic API description,
 * refer to `aj_mcp4821_4822.h`.
 *
 * If only `MCP4822` is used from this device family, the configuration macros
 * from `aj_mcp4821_4822_config.h` should be overridden as follows:
 * - `AJ_MCP4821_4822_CHB_SUPPORTED` : `1U`
 * - `AJ_MCP4821_4822_SHDN_USED` : `0U`
 *
 * @author  AliReza Joodi
 * @see     https://github.com/AliRezaJoodi
 */

#ifndef AJ_MCP4822_INCLUDED
#define AJ_MCP4822_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif


#include <stdint.h>
#include "aj_mcp4821_4822.h"
#include "aj_mcp4822_config_platform.h"     /**< refer to main.c*/

typedef aj_mcp4821_4822_t           aj_mcp4822_t;

static inline void AJ_MCP4822_Init(aj_mcp4821_4822_t *dac){
    AJ_MCP4821_4822_Init(dac);
}

/**
 * @brief   Set output value for channel A with 1x gain
 * This is a convenience wrapper for AJ_MCP4821_4822_WriteCount() that selects channel A and 1x gain automatically.
 *
 * @param[in] dac    Pointer to MCP4821_4822 device handle
 * @param[in] value  12-bit DAC value (0 to 4095)
 */
static inline void AJ_MCP4822_WriteCount_ChA_2V048(aj_mcp4822_t *dac, uint16_t count){
    AJ_MCP4821_4822_WriteCount(dac, AJ_MCP4821_4822_CH_A, AJ_MCP4821_4822_FS_2V048, count);
}

/**
 * @brief   Set output value for channel A with 2x gain
 * This is a convenience wrapper for AJ_MCP4821_4822_WriteCount() that selects channel A and 2x gain automatically.
 *
 * @param[in] dac    Pointer to MCP4821_4822 device handle
 * @param[in] value  12-bit DAC value (0 to 4095)
 */
static inline void AJ_MCP4822_WriteCount_ChA_4V096(aj_mcp4822_t *dac, uint16_t count){
    AJ_MCP4821_4822_WriteCount(dac, AJ_MCP4821_4822_CH_A, AJ_MCP4821_4822_FS_4V096, count);
}

/**
 * @brief   Set output value for channel B with 1x gain
 * This is a convenience wrapper for AJ_MCP4821_4822_WriteCount() that selects channel B and 1x gain automatically.
 *
 * @param[in] dac    Pointer to MCP4821_4822 device handle
 * @param[in] value  12-bit DAC value (0 to 4095)
 */
static inline void AJ_MCP4822_WriteCount_ChB_2V048(aj_mcp4822_t *dac, uint16_t count){
    AJ_MCP4821_4822_WriteCount(dac, AJ_MCP4821_4822_CH_B, AJ_MCP4821_4822_FS_2V048, count);
}

/**
 * @brief   Set output value for channel B with 2x gain
 * This is a convenience wrapper for AJ_MCP4821_4822_WriteCount() that selects channel B and 2x gain automatically.
 *
 * @param[in] dac    Pointer to MCP4821_4822 device handle
 * @param[in] value  12-bit DAC value (0 to 4095)
 */
static inline void AJ_MCP4822_WriteCount_ChB_4V096(aj_mcp4822_t *dac, uint16_t count){
    AJ_MCP4821_4822_WriteCount(dac, AJ_MCP4821_4822_CH_B, AJ_MCP4821_4822_FS_4V096, count);
}

/**
 * @brief   Disable output for channel A
 * This is a convenience wrapper for AJ_MCP4821_4822_Shutdown() that selects channel A automatically.
 *
 * @param[in] dac   Pointer to MCP4821_4822 device handle
 */
static inline void AJ_MCP4822_Shutdown_ChA(aj_mcp4822_t *dac){
    AJ_MCP4821_4822_Shutdown(dac, AJ_MCP4821_4822_CH_A);
}

/**
 * @brief   Disable output for channel B
 * This is a convenience wrapper for MCP4821_4822_ShutdownChannel() that selects channel B automatically.
 *
 * @param[in] dac   Pointer to MCP4821_4822 device handle
 */
static inline void AJ_MCP4822_Shutdown_ChB(aj_mcp4822_t *dac){
    AJ_MCP4821_4822_Shutdown(dac, AJ_MCP4821_4822_CH_B);
}


#ifdef __cplusplus
}
#endif

#endif
