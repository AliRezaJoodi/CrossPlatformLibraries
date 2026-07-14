#ifndef AJ_MCP3204_3208_CONFIG_PLATFORM_INCLUDED
#define AJ_MCP3204_3208_CONFIG_PLATFORM_INCLUDED


#include "hardware.h"       /**< Project-level overrides */

#ifndef AJ_MCP3204_3208_CONFIG_PLATFORM_EXTRA
#define AJ_MCP3204_3208_CONFIG_PLATFORM_EXTRA
    #define AJ_MCP3204_3208_CS_DDR          DDRB
    #define AJ_MCP3204_3208_CS_PORT         PORTB
    #define AJ_MCP3204_3208_CS_POS          4U
    #define AJ_MCP3204_3208_CS_MASK         (1U << AJ_MCP3204_3208_CS_POS)
#endif


#endif
