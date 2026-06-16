#ifndef AJ_MCP41XXX_TYPE_INCLUDED
#define AJ_MCP41XXX_TYPE_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

typedef struct {
    volatile uint8_t *ddr;      /**< Data Direction Register for this pin */
    volatile uint8_t *port;     /**< PORT register for this pin */
    const uint8_t     mask;
} aj_mcp41xxx_pin_t;

typedef struct {
    const aj_mcp41xxx_pin_t cs;       /**< Chip Select pin */
} aj_mcp41xxx_t;

#ifdef __cplusplus
}
#endif

#endif
