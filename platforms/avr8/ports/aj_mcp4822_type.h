#ifndef AJ_MCP4822_TYPE_INCLUDED
#define AJ_MCP4822_TYPE_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

typedef enum {
    AJ_MCP4822_CH_A = 0U,
    AJ_MCP4822_CH_B = 1U
} aj_mcp4822_channel_t;

typedef enum {
    AJ_MCP4822_FS_4V096 = 0U,   /**< Full-Scale: 4.096V */
    AJ_MCP4822_FS_2V048 = 1U    /**< Full-Scale: 2.048V */
} aj_mcp4822_scale_t;

/**
 * @brief   MCP4822 GPIO pin descriptor
 *
 * Describes a GPIO pin used by the MCP4822 driver.
 * Contains registers and bit index for pin control.
 */
typedef struct {
    volatile uint8_t *ddr;
    volatile uint8_t *port;
    //const uint8_t    index;
    const uint8_t    mask;
} aj_mcp4822_pin_t;

/**
 * @brief   MCP4822 device handle
 *
 * Represents a single MCP4822 device with its control pins.
 * Contains CS and LDAC pin descriptors.
 *
 * @see Example section above
 */
typedef struct {
    const aj_mcp4822_pin_t cs;
    const aj_mcp4822_pin_t ldac;
} aj_mcp4822_t;

/**
 * @example
 * Example: initializing a structure
 *
 * @code
 *    static const aj_MCP4822_t dac1 = {
 *        .cs = {
 *            .ddr   = &AJ_MCP4822_CS_DDR,
 *            .port  = &AJ_MCP4822_CS_PORT,
 *            .mask  =  AJ_MCP4822_CS_MASK
 *        },
 *        .ldac = {
 *            .ddr   = &AJ_MCP4822_LDAC_DDR,
 *            .port  = &AJ_MCP4822_LDAC_PORT,
 *            .mask  =  AJ_MCP4822_LDAC_MASK
 *        }
 *    };
 * @endcode
 */

#ifdef __cplusplus
}
#endif

#endif
