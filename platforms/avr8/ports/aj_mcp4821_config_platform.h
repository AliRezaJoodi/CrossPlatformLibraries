#ifndef AJ_MCP4821_CONFIG_PLATFORM_INCLUDED
#define AJ_MCP4821_CONFIG_PLATFORM_INCLUDED


#include "hardware.h"       /**< Project-level overrides */
#include "aj_mcp4821_4822_config.h"

#ifndef AJ_MCP4821_CONFIG_PLATFORM_EXTRA
#define AJ_MCP4821_CONFIG_PLATFORM_EXTRA
    #define AJ_MCP4821_CS_DDR               DDRB
    #define AJ_MCP4821_CS_PORT              PORTB
    #define AJ_MCP4821_CS_POS               4U
    #define AJ_MCP4821_CS_MASK              (1U << AJ_MCP4821_CS_POS)

    #define AJ_MCP4821_LDAC_DDR             DDRB
    #define AJ_MCP4821_LDAC_PORT            PORTB
    #define AJ_MCP4821_LDAC_POS             3U
    #define AJ_MCP4821_LDAC_MASK            (1U << AJ_MCP4821_LDAC_POS)

    #if (AJ_MCP4821_4822_SHDN_USED == 1U)
        #define AJ_MCP4821_SHDN_DDR             DDRB
        #define AJ_MCP4821_SHDN_PORT            PORTB
        #define AJ_MCP4821_SHDN_POS             2U
        #define AJ_MCP4821_SHDN_MASK            (1U << AJ_MCP4821_SHDN_POS)
    #endif
#endif


#endif
