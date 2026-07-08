#ifndef AJ_MCP413X_426X_TYPE_PLATFORM_INCLUDED
#define AJ_MCP413X_426X_TYPE_PLATFORM_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif


#include <stdint.h>
#include "aj_mcp413x_426x_config.h"

typedef struct {
    volatile uint8_t *ddr;      /**< Data Direction Register for this pin */
    volatile uint8_t *port;     /**< PORT register for this pin */
    const uint8_t     mask;
} aj_mcp413x_426x_pin_t;

typedef struct {
    const aj_mcp413x_426x_pin_t cs;       /**< Chip Select pin */

    #if (AJ_MCP413X_426X_SHDN_USED == 1U)
    const aj_mcp413x_426x_pin_t shdn;
    #endif

    #if (AJ_MCP413X_426X_WP_USED == 1U)
    const aj_mcp413x_426x_pin_t wp;
    #endif
} aj_mcp413x_426x_t;

/**
 * @example Initializing a structure for AVR8
 *
 * @code
 *    static const aj_mcp413x_426x_t mcp = {
 *        .cs = {
 *            .ddr   = &AJ_MCP413X_426X_CS_DDR,
 *            .port  = &AJ_MCP413X_426X_CS_PORT,
 *            .mask = AJ_MCP413X_426X_CS_MASK
 *        },
 *       .shdn = {
 *           .ddr   = &AJ_MCP413X_426X_SHDN_DDR,
 *            .port  = &AJ_MCP413X_426X_SHDN_PORT,
 *            .mask = AJ_MCP413X_426X_SHDN_MASK
 *        },
 *        .wp = {
 *            .ddr   = &AJ_MCP413X_426X_WP_DDR,
 *            .port  = &AJ_MCP413X_426X_WP_PORT,
 *            .mask = AJ_MCP413X_426X_WP_MASK
 *        }
 *    };
 * @endcode
 */


#ifdef __cplusplus
}
#endif

#endif
