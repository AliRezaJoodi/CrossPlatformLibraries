/**
 * @brief   MCP3204 model-specific wrapper for `aj_mcp3204_3208.h`.
 *
 * @details
 * For driver requirements, usage notes, and the generic API description,
 * refer to `aj_mcp3204_3208.h`.
 *
 * If only `MCP3204` is used from this device family, the configuration macros
 * from `aj_mcp3204_3208_config.h` should be overridden as follows:
 * - `AJ_MCP3204_3208_CHANNELS` : `4U`
 *
 * @author  AliReza Joodi
 * @see     https://github.com/AliRezaJoodi
 */

#ifndef AJ_MCP3204_INCLUDED
#define AJ_MCP3204_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif


#include <stdint.h>
#include "aj_mcp3204_3208.h"
#include "aj_mcp3204_config_platform.h"        /**< refer to main.c*/

typedef aj_mcp3204_3208_t           aj_mcp3204_t;

/** Initializes the MCP3204 ADC. */
static inline void AJ_MCP3204_Init(aj_mcp3204_t *mcp){
    AJ_MCP3204_3208_Init(mcp);
}

/** Reads and returns the raw 12-bit ADC value from channel 0. */
static inline uint16_t AJ_MCP3204_ReadRaw_Ch0(aj_mcp3204_t *mcp){
    return AJ_MCP3204_3208_ReadRaw(mcp, AJ_MCP3204_3208_CH0);
}

/** Reads and returns the raw 12-bit ADC value from channel 1. */
static inline uint16_t AJ_MCP3204_ReadRaw_Ch1(aj_mcp3204_t *mcp){
    return AJ_MCP3204_3208_ReadRaw(mcp, AJ_MCP3204_3208_CH1);
}

/** Reads and returns the raw 12-bit ADC value from channel 2. */
static inline uint16_t AJ_MCP3204_ReadRaw_Ch2(aj_mcp3204_t *mcp){
    return AJ_MCP3204_3208_ReadRaw(mcp, AJ_MCP3204_3208_CH2);
}

/** Reads and returns the raw 12-bit ADC value from channel 3. */
static inline uint16_t AJ_MCP3204_ReadRaw_Ch3(aj_mcp3204_t *mcp){
    return AJ_MCP3204_3208_ReadRaw(mcp, AJ_MCP3204_3208_CH3);
}

/** Reads and returns the raw 12-bit ADC value for the CH0-positive/CH1-negative differential input. */
static inline uint16_t AJ_MCP3204_ReadRaw_Ch0Ch1(aj_mcp3204_t *mcp){
    return AJ_MCP3204_3208_ReadRaw(mcp, AJ_MCP3204_3208_CH0CH1);
}

/** Reads and returns the raw 12-bit ADC value for the CH1-positive/CH0-negative differential input. */
static inline uint16_t AJ_MCP3204_ReadRaw_Ch1Ch0(aj_mcp3204_t *mcp){
    return AJ_MCP3204_3208_ReadRaw(mcp, AJ_MCP3204_3208_CH1CH0);
}

/** Reads and returns the raw 12-bit ADC value for the CH2-positive/CH3-negative differential input. */
static inline uint16_t AJ_MCP3204_ReadRaw_Ch2Ch3(aj_mcp3204_t *mcp){
    return AJ_MCP3204_3208_ReadRaw(mcp, AJ_MCP3204_3208_CH2CH3);
}

/** Reads and returns the raw 12-bit ADC value for the CH3-positive/CH2-negative differential input. */
static inline uint16_t AJ_MCP3204_ReadRaw_Ch3Ch2(aj_mcp3204_t *mcp){
    return AJ_MCP3204_3208_ReadRaw(mcp, AJ_MCP3204_3208_CH3CH2);
}


#ifdef __cplusplus
}
#endif

#endif
