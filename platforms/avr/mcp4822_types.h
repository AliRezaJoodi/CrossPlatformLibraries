#ifndef MCP4822_TYPES_INCLUDED
#define MCP4822_TYPES_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

/**
 * @brief   MCP4822 GPIO pin descriptor
 *
 * Describes a GPIO pin used by the MCP4822 driver.
 * Contains registers and bit index for pin control.
 */
typedef struct {
    volatile uint8_t *ddr;
    volatile uint8_t *port;
    const uint8_t    index;
} MCP4822_Pin_t;

/**
 * @brief   MCP4822 device handle
 *
 * Represents a single MCP4822 device with its control pins.
 * Contains CS and LDAC pin descriptors.
 *
 * @see Example section above
 */
typedef struct {
    const MCP4822_Pin_t cs;
    const MCP4822_Pin_t ldac;
} MCP4822_t;

/**
 * @example
 * Example: initializing a structure
 *
 * @code
 *    MCP4822_t dac1 = {
 *        .cs = {
 *            .ddr   = &MCP4822_CS_DDR,
 *            .port  = &MCP4822_CS_PORT,
 *            .index =  MCP4822_CS_BIT
 *        },
 *        .ldac = {
 *            .ddr   = &MCP4822_LDAC_DDR,
 *            .port  = &MCP4822_LDAC_PORT,
 *            .index =  MCP4822_LDAC_BIT
 *        }
 *    };
 * @endcode
 */

#ifdef __cplusplus
}
#endif

#endif
