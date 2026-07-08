#ifndef AJ_MCP413X_426X_TYPE_PLATFORM_INCLUDED
#define AJ_MCP413X_426X_TYPE_PLATFORM_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

typedef struct {
    volatile uint8_t *ddr;      /**< Data Direction Register for this pin */
    volatile uint8_t *port;     /**< PORT register for this pin */
    const uint8_t     mask;
} aj_mcp413x_426x_pin_t;

#ifdef __cplusplus
}
#endif

#endif
