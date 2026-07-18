#ifndef AJ_MCP4822_CONFIG_PLATFORM_INCLUDED
#define AJ_MCP4822_CONFIG_PLATFORM_INCLUDED


#include "hardware.h"       /**< Project-level overrides */

#ifndef AJ_MCP4822_CONFIG_PLATFORM_EXTRA
#define AJ_MCP4822_CONFIG_PLATFORM_EXTRA
    #define AJ_MCP4822_CS_DDR               DDRB
    #define AJ_MCP4822_CS_PORT              PORTB
    #define AJ_MCP4822_CS_POS               4U
    #define AJ_MCP4822_CS_MASK              (1U << AJ_MCP4822_CS_POS)

    #define AJ_MCP4822_LDAC_DDR             DDRB
    #define AJ_MCP4822_LDAC_PORT            PORTB
    #define AJ_MCP4822_LDAC_POS             3U
    #define AJ_MCP4822_LDAC_MASK            (1U << AJ_MCP4822_LDAC_POS)
#endif


#endif
