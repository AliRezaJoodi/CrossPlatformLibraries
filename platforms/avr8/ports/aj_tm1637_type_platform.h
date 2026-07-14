#ifndef AJ_TM1637_TYPE_PLATFORM_INCLUDED
#define AJ_TM1637_TYPE_PLATFORM_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif


#include <stdint.h>

/**
 * @brief TM1637 GPIO pin descriptor.
 *
 * This structure describes a GPIO pin used by the TM1637 driver.
 */
typedef struct {
    volatile uint8_t *ddr;
    volatile uint8_t *port;
    volatile uint8_t *pin;
    const uint8_t    mask;
} aj_tm1637_pin_t;


#ifdef __cplusplus
}
#endif

#endif
