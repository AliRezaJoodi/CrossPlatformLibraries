#ifndef AJ_MCP3202_TYPE_INCLUDED
#define AJ_MCP3202_TYPE_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

/**
 * @brief Defines MCP3202 Channels.
 */
typedef enum {
    AJ_MCP3202_CH0         = 0U,   /**< CH0(IN+), GND(IN-)*/
    AJ_MCP3202_CH1         = 1U,   /**< CH1(IN+), GND(IN-)*/
    AJ_MCP3202_CH0CH1      = 2U,   /**< CH0(IN+), CH1(IN-)*/
    AJ_MCP3202_CH1CH0      = 3U    /**< CH1(IN+), CH0(IN-)*/
} aj_mcp3202_channel_t;

/**
 * @brief   GPIO representation for a single MCP3202 pin
 *
 * This struct maps a microcontroller pin for use by the MCP3202 driver.
 * It contains pointers to the DDR and PORT registers, and the bit index
 * of the pin within those registers.
 *
 * @note    All pointers must point to valid registers before use.
 */
typedef struct {
    volatile uint8_t *ddr;      /**< Data Direction Register for this pin */
    volatile uint8_t *port;     /**< PORT register for this pin */
    //const uint8_t     index;    /**< Bit position within DDR/PORT (0..7) */
    const uint8_t     mask;
} aj_mcp3202_pin_t;

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
 * Example: initializing a structure
 *
 * @code
 *    static const aj_MCP3202_t mcp1 = {
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
