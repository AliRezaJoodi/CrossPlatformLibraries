#ifndef AJ_MCP413X_426X_TYPE_INCLUDED
#define AJ_MCP413X_426X_TYPE_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "aj_mcp413x_426x_config.h"
#include "aj_mcp413x_426x_type_platform.h"

typedef enum{
    AJ_MCP413X_426X_TCON_P0B  = (1U << 0),
    AJ_MCP413X_426X_TCON_P0W  = (1U << 1),

    #if (AJ_MCP413X_426X_P0A_SUPPORTED == 1U)
    AJ_MCP413X_426X_TCON_P0A  = (1U << 2),
    #endif  /**< AJ_MCP413X_426X_P0A_SUPPORTED */

    AJ_MCP413X_426X_TCON_P0HW = (1U << 3),

    #if (AJ_MCP413X_426X_P1_SUPPORTED == 1U)
    AJ_MCP413X_426X_TCON_P1B  = (1U << 4),
    AJ_MCP413X_426X_TCON_P1W  = (1U << 5),

    #if (AJ_MCP413X_426X_P1A_SUPPORTED == 1U)
    AJ_MCP413X_426X_TCON_P1A  = (1U << 6),
    #endif  /**< AJ_MCP413X_426X_P1A_SUPPORTED */

    AJ_MCP413X_426X_TCON_P1HW = (1U << 7),
    #endif  /**< AJ_MCP413X_426X_P1_SUPPORTED */

    AJ_MCP413X_426X_TCON_ALL  = 0xFFU
} aj_mcp413x_426x_tcon_t;


#ifdef __cplusplus
}
#endif

#endif
