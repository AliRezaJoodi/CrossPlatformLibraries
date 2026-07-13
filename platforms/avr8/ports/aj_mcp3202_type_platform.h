#ifndef AJ_MCP3202_TYPE_PLATFORM_INCLUDED
#define AJ_MCP3202_TYPE_PLATFORM_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif


#include <stdint.h>

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
    const uint8_t     mask;
} aj_mcp3202_pin_t;


#ifdef __cplusplus
}
#endif

#endif
