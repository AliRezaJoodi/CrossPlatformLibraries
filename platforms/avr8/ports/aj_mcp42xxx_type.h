#ifndef AJ_MCP42XXX_TYPE_INCLUDED
#define AJ_MCP42XXX_TYPE_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "aj_mcp42xxx_hw.h"

typedef struct {
    volatile uint8_t *ddr;      /**< Data Direction Register for this pin */
    volatile uint8_t *port;     /**< PORT register for this pin */
    const uint8_t     mask;
} aj_mcp42xxx_pin_t;

typedef struct {
    const aj_mcp42xxx_pin_t cs;       /**< Chip Select pin */

    #if (AJ_MCP42XXX_SHDN_USED == 1U)
    const aj_mcp42xxx_pin_t shdn;
    #endif

    #if (AJ_MCP42XXX_RS_USED == 1U)
    const aj_mcp42xxx_pin_t rs;
    #endif
} aj_mcp42xxx_t;

/**
 * @example Initializing a structure
 *
 * @code
 *    static const aj_mcp42xxx_t mcp = {
 *        .cs = {
 *            .ddr   = &AJ_MCP42XXX_CS_DDR,
 *            .port  = &AJ_MCP42XXX_CS_PORT,
 *            .mask = AJ_MCP42XXX_CS_MASK
 *        },
 *       .shdn = {
 *           .ddr   = &AJ_MCP42XXX_SHDN_DDR,
 *            .port  = &AJ_MCP42XXX_SHDN_PORT,
 *            .mask = AJ_MCP42XXX_SHDN_MASK
 *        },
 *        .rs = {
 *            .ddr   = &AJ_MCP42XXX_RS_DDR,
 *            .port  = &AJ_MCP42XXX_RS_PORT,
 *            .mask = AJ_MCP42XXX_RS_MASK
 *        }
 *    };
 * @endcode
 */

#ifdef __cplusplus
}
#endif

#endif
