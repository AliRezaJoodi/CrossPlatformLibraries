#ifndef AJ_TM1637_TYPE_INCLUDED
#define AJ_TM1637_TYPE_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif


#include <stdint.h>
#include "aj_tm1637_type_platform.h"

/**
 * @brief TM1637 device handle.
 *
 * This structure holds all configuration data required
 * to control one TM1637 device instance.
 *
 * @see Example section below.
 */
typedef struct {
    const aj_tm1637_pin_t clk;
    const aj_tm1637_pin_t dio;
} aj_tm1637_t;

/**
 * @example
 * Example: initializing a structure for AVR8
 *
 * @code
 *    static const aj_tm1637_t tm1 = {
 *        .clk = {
 *            .ddr   = &AJ_TM1637_CLK_DDR,
 *            .port  = &AJ_TM1637_CLK_PORT,
 *            .pin   = &AJ_TM1637_CLK_PIN,
 *            .mask =   AJ_TM1637_CLK_MASK
 *        },
 *        .dio = {
 *            .ddr   = &AJ_TM1637_DIO_DDR,
 *            .port  = &AJ_TM1637_DIO_PORT,
 *            .pin   = &AJ_TM1637_DIO_PIN,
 *            .mask =   AJ_TM1637_DIO_MASK
 *        }
 *    };
 * @endcode
 */


#ifdef __cplusplus
}
#endif

#endif
