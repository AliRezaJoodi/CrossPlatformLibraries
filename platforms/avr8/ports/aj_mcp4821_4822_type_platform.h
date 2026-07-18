#ifndef AJ_MCP4821_4822_TYPE_PLATFORM_INCLUDED
#define AJ_MCP4821_4822_TYPE_PLATFORM_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif


#include <stdint.h>

/**
 * @brief   MCP4821_4822 GPIO pin descriptor
 *
 * Describes a GPIO pin used by the MCP4821_4822 driver.
 * Contains registers and bit index for pin control.
 */
typedef struct {
    volatile uint8_t *ddr;
    volatile uint8_t *port;
    const uint8_t    mask;
} aj_mcp4821_4822_pin_t;


#ifdef __cplusplus
}
#endif

#endif
