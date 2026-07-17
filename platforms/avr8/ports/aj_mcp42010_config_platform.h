#ifndef AJ_MCP42010_CONFIG_PLATFORM_INCLUDED
#define AJ_MCP42010_CONFIG_PLATFORM_INCLUDED

#include "aj_compiler.h"
#include "hardware.h"   /**< Project-level overrides */
#include "aj_mcp41xxx_42xxx_config.h"

#ifndef AJ_MCP42010_CONFIG_PLATFORM_EXTRA
#define AJ_MCP42010_CONFIG_PLATFORM_EXTRA
    #define AJ_MCP42010_CS_DDR            DDRB
    #define AJ_MCP42010_CS_PORT           PORTB
    #define AJ_MCP42010_CS_POS            4U
    #define AJ_MCP42010_CS_MASK           (1U << AJ_MCP42010_CS_POS)

    #if (AJ_MCP41XXX_42XXX_SHDN_USED == 1U)
        #define AJ_MCP42010_SHDN_DDR          DDRB
        #define AJ_MCP42010_SHDN_PORT         PORTB
        #define AJ_MCP42010_SHDN_POS          3U
        #define AJ_MCP42010_SHDN_MASK         (1U << AJ_MCP42010_SHDN_POS)
    #endif

    #if (AJ_MCP41XXX_42XXX_RS_USED == 1U)
        #define AJ_MCP42010_RS_DDR            DDRB
        #define AJ_MCP42010_RS_PORT           PORTB
        #define AJ_MCP42010_RS_POS            2U
        #define AJ_MCP42010_RS_MASK           (1U << AJ_MCP42010_RS_POS)
    #endif
#endif


#endif
