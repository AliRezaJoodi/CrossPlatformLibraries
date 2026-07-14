#ifndef AJ_MCP3202_TYPE_INCLUDED
#define AJ_MCP3202_TYPE_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "aj_mcp3202_type_platform.h"

/**
 * @brief Defines MCP3202 Channels.
 */
typedef enum {
    AJ_MCP3202_CH0      = ((1U << 7U) | (0U << 6U)),   /**< CH0(IN+), GND(IN-)*/
    AJ_MCP3202_CH1      = ((1U << 7U) | (1U << 6U)),   /**< CH1(IN+), GND(IN-)*/
    AJ_MCP3202_CH0CH1   = ((0U << 7U) | (0U << 6U)),   /**< CH0(IN+), CH1(IN-)*/
    AJ_MCP3202_CH1CH0   = ((0U << 7U) | (1U << 6U))    /**< CH1(IN+), CH0(IN-)*/
} aj_mcp3202_channel_t;

/**
 * @brief   MCP3202 instance structure
 *
 * Contains all pins used by a single MCP3201 device.
 */
typedef struct {
    const aj_mcp3202_pin_t cs;       /**< Chip Select pin */
} aj_mcp3202_t;

/**
 * @example
 * Example: initializing a structure for AVR8
 *
 * @code
 *    static const aj_mcp3202_t mcp1 = {
 *        .cs = {
 *            .ddr   = &AJ_MCP3202_CS_DDR,
 *            .port  = &AJ_MCP3202_CS_PORT,
 *            .mask = AJ_MCP3202_CS_MASK
 *        }
 *    };
 * @endcode
 */

#ifdef __cplusplus
}
#endif

#endif
