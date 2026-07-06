#ifndef AJ_MCP413X_426X_TYPE_INCLUDED
#define AJ_MCP413X_426X_TYPE_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "aj_mcp413x_426x_hw.h"

typedef enum{
    AJ_MCP413X_426X_TCON_P0B  = (1U << 0),
    AJ_MCP413X_426X_TCON_P0W  = (1U << 1),
    AJ_MCP413X_426X_TCON_P0A  = (1U << 2),
    AJ_MCP413X_426X_TCON_P0HW = (1U << 3),
    AJ_MCP413X_426X_TCON_P1B  = (1U << 4),
    AJ_MCP413X_426X_TCON_P1W  = (1U << 5),
    AJ_MCP413X_426X_TCON_P1A  = (1U << 6),
    AJ_MCP413X_426X_TCON_P1HW = (1U << 7),
    AJ_MCP413X_426X_TCON_ALL  = 0xFFU
} aj_mcp413x_426x_tcon_t;

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
 * @example Initializing a structure
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
