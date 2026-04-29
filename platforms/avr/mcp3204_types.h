#ifndef MCP3204_TYPES_INCLUDED
#define MCP3204_TYPES_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

/**
 * @brief   GPIO representation for a single MCP3204 pin
 *
 * This struct maps a microcontroller pin for use by the MCP3204 driver.
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
} MCP3204_Pin_t;

/**
 * @brief   MCP3204 instance structure
 *
 * Contains all pins used by a single MCP3201 device.
 */
typedef struct {
    const MCP3204_Pin_t cs;       /**< Chip Select pin */
} MCP3204_t;

/**
 * @example
 * Example: initializing a structure
 *
 * @code
 *    MCP3204_t mcp1 = {
 *        .cs = {
 *            .ddr   = &MCP3204_CS_DDR,
 *            .port  = &MCP3204_CS_PORT,
 *            .mask = MCP3204_CS_MASK
 *        }
 *    };
 * @endcode
 */

#ifdef __cplusplus
}
#endif

#endif
