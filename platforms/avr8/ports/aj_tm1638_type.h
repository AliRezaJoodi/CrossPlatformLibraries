#ifndef AJ_TM1638_TYPE_INCLUDED
#define AJ_TM1638_TYPE_INCLUDED

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
    //const uint8_t    index;
    const uint8_t    mask;
} aj_tm1638_pin_t;

/**
 * @brief TM1638 device handle.
 *
 * This structure holds STB pin that required
 * to control one TM1638 device instance.
 *
 * @see Example section below.
 */
typedef struct {
    const aj_tm1638_pin_t stb;
} aj_tm1638_t;

/**
 * @example
 * Example: initializing a structure
 *
 * @code
 *    static const aj_tm1638_t tm1 = {
 *        .stb = {
 *            .ddr   = &AJ_TM1638_STB_DDR,
 *            .port  = &AJ_TM1638_STB_PORT,
 *            .mask =  AJ_TM1638_STB_MASK
 *        }
 *    };
 * @endcode
 */

#ifdef __cplusplus
}
#endif

#endif
