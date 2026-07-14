#ifndef AJ_TM1638_TYPE_PLATFORM_INCLUDED
#define AJ_TM1638_TYPE_PLATFORM_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif


#include <stdint.h>

/**
 * @brief TM1638 GPIO pin descriptor.
 *
 * This structure describes a GPIO pin used by the TM1638 driver.
 */
typedef struct {
    volatile uint8_t *ddr;
    volatile uint8_t *port;
    const uint8_t    mask;
} aj_tm1638_pin_t;


#ifdef __cplusplus
}
#endif

#endif
