#ifndef AJ_MAX6675_TYPE_PLATFORM_INCLUDED
#define AJ_MAX6675_TYPE_PLATFORM_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif


#include <stdint.h>

typedef struct {
    volatile uint8_t *ddr;      /**< Data Direction Register for this pin */
    volatile uint8_t *port;     /**< PORT register for this pin */
    const uint8_t     mask;
} aj_max6675_pin_t;


#ifdef __cplusplus
}
#endif

#endif
