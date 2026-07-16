#ifndef AJ_MCP3208_INCLUDED
#define AJ_MCP3208_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif


#include <stdint.h>
#include "aj_mcp3204_3208.h"
#include "aj_mcp3208_config_platform.h"        /**< refer to main.c*/

/* Valid symbolic values for aj_mcp3204_3208_channel_t. */
#define AJ_MCP3208_CH0                  AJ_MCP3204_3208_CH0
#define AJ_MCP3208_CH1                  AJ_MCP3204_3208_CH1
#define AJ_MCP3208_CH2                  AJ_MCP3204_3208_CH2
#define AJ_MCP3208_CH3                  AJ_MCP3204_3208_CH3
#define AJ_MCP3208_CH4                  AJ_MCP3204_3208_CH4
#define AJ_MCP3208_CH5                  AJ_MCP3204_3208_CH5
#define AJ_MCP3208_CH6                  AJ_MCP3204_3208_CH6
#define AJ_MCP3208_CH7                  AJ_MCP3204_3208_CH7
#define AJ_MCP3208_CH0CH1               AJ_MCP3204_3208_CH0CH1
#define AJ_MCP3208_CH1CH0               AJ_MCP3204_3208_CH1CH0
#define AJ_MCP3208_CH2CH3               AJ_MCP3204_3208_CH2CH3
#define AJ_MCP3208_CH3CH2               AJ_MCP3204_3208_CH3CH2
#define AJ_MCP3208_CH4CH5               AJ_MCP3204_3208_CH4CH5
#define AJ_MCP3208_CH5CH4               AJ_MCP3204_3208_CH5CH4
#define AJ_MCP3208_CH6CH7               AJ_MCP3204_3208_CH6CH7
#define AJ_MCP3208_CH7CH6               AJ_MCP3204_3208_CH7CH6

typedef aj_mcp3204_3208_t               aj_mcp3208_t;
typedef aj_mcp3204_3208_channel_t       aj_mcp3208_channel_t;

static inline void AJ_MCP3208_Init(aj_mcp3208_t *mcp){
    AJ_MCP3204_3208_Init(mcp);
}

static inline uint16_t AJ_MCP3208_ReadRaw(aj_mcp3208_t *mcp, aj_mcp3208_channel_t ch){
    return AJ_MCP3204_3208_ReadRaw(mcp, ch);
}

#ifdef __cplusplus
}
#endif

#endif
