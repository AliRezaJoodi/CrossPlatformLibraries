#ifndef TM1638_TYPES_INCLUDED
#define TM1638_TYPES_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

//typedef enum{
//    TM1638_PIN_INPUT = 0U,
//    TM1638_PIN_OUTPUT = 1U
//} TM1638_PinMode_t;


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
} TM1638_Pin_t;

/**
 * @brief TM1638 device handle.
 *
 * This structure holds STB pin that required
 * to control one TM1638 device instance.
 *
 * @see Example section below.
 */
typedef struct {
    const TM1638_Pin_t stb;
} TM1638_t;

/**
 * @example
 * Example: initializing a structure
 *
 * @code
 *    TM1638_t tm1 = {
 *        .stb = {
 *            .ddr   = &TM1638_STB_DDR,
 *            .port  = &TM1638_STB_PORT,
 *            .mask =  TM1638_STB_MASK
 *        }
 *    };
 * @endcode
 */

#ifdef __cplusplus
}
#endif

#endif
