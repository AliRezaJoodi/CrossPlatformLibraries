#ifndef AJ_MCP413X_426X_CONFIG_PLATFORM_INCLUDED
#define AJ_MCP413X_426X_CONFIG_PLATFORM_INCLUDED


#include "hardware.h"   /**< Project-level overrides */
#include "aj_mcp413x_426x_config.h"

#ifndef AJ_MCP413X_426X_CONFIG_PLATFORM_EXTRA
#define AJ_MCP413X_426X_CONFIG_PLATFORM_EXTRA
    #define AJ_MCP413X_426X_CS_DDR          DDRB
    #define AJ_MCP413X_426X_CS_PORT         PORTB
    #define AJ_MCP413X_426X_CS_POS          4U
    #define AJ_MCP413X_426X_CS_MASK         (1U << AJ_MCP413X_426X_CS_POS)

    #if (AJ_MCP413X_426X_SHDN_USED == 1U)
        #define AJ_MCP413X_426X_SHDN_DDR        DDRB
        #define AJ_MCP413X_426X_SHDN_PORT       PORTB
        #define AJ_MCP413X_426X_SHDN_POS        3U
        #define AJ_MCP413X_426X_SHDN_MASK       (1U << AJ_MCP413X_426X_SHDN_POS)
    #endif

    #if (AJ_MCP413X_426X_WP_USED == 1U)
        #define AJ_MCP413X_426X_WP_DDR          DDRB
        #define AJ_MCP413X_426X_WP_PORT         PORTB
        #define AJ_MCP413X_426X_WP_POS          2U
        #define AJ_MCP413X_426X_WP_MASK         (1U << AJ_MCP413X_426X_WP_POS)
    #endif
#endif


#endif
