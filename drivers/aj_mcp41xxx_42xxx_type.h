#ifndef AJ_MCP41XXX_42XXX_TYPE_INCLUDED
#define AJ_MCP41XXX_42XXX_TYPE_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif


#include <stdint.h>
#include "aj_mcp41xxx_42xxx_config.h"
#include "aj_mcp41xxx_42xxx_type_platform.h"

typedef enum{
    AJ_MCP41XXX_42XXX_POT0 = 0x01U,
    AJ_MCP41XXX_42XXX_POT1 = 0x02U,
    AJ_MCP41XXX_42XXX_ALL  = 0x03U
} aj_mcp41xxx_42xxx_ch_t;

typedef struct {
    const aj_mcp41xxx_42xxx_pin_t cs;       /**< Chip Select pin */

    #if (AJ_MCP41XXX_42XXX_SHDN_USED == 1U)
    const aj_mcp41xxx_42xxx_pin_t shdn;
    #endif

    #if (AJ_MCP41XXX_42XXX_RS_USED == 1U)
    const aj_mcp41xxx_42xxx_pin_t rs;
    #endif
} aj_mcp41xxx_42xxx_t;

/**
 * @example Initializing a structure for AVR8
 *
 * @code
 *    static const aj_mcp41xxx_42xxx_t mcp = {
 *        .cs = {
 *            .ddr   = &AJ_MCP41XXX_42XXX_CS_DDR,
 *            .port  = &AJ_MCP41XXX_42XXX_CS_PORT,
 *            .mask = AJ_MCP41XXX_42XXX_CS_MASK
 *        },
 *       .shdn = {
 *           .ddr   = &AJ_MCP41XXX_42XXX_SHDN_DDR,
 *            .port  = &AJ_MCP41XXX_42XXX_SHDN_PORT,
 *            .mask = AJ_MCP41XXX_42XXX_SHDN_MASK
 *        },
 *        .rs = {
 *            .ddr   = &AJ_MCP41XXX_42XXX_RS_DDR,
 *            .port  = &AJ_MCP41XXX_42XXX_RS_PORT,
 *            .mask = AJ_MCP41XXX_42XXX_RS_MASK
 *        }
 *    };
 * @endcode
 */


#ifdef __cplusplus
}
#endif

#endif
