#ifndef AJ_MCP41010_CONFIG_PLATFORM_INCLUDED
#define AJ_MCP41010_CONFIG_PLATFORM_INCLUDED


#include "hardware.h"   /**< Project-level overrides */

#ifndef AJ_MCP41010_CONFIG_PLATFORM_EXTRA
#define AJ_MCP41010_CONFIG_PLATFORM_EXTRA
    #define AJ_MCP41010_CS_DDR            DDRB
    #define AJ_MCP41010_CS_PORT           PORTB
    #define AJ_MCP41010_CS_POS            4U
    #define AJ_MCP41010_CS_MASK           (1U << AJ_MCP41010_CS_POS)
#endif


#endif
