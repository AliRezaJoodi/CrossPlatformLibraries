#ifndef AJ_MAX6675_TYPE_INCLUDED
#define AJ_MAX6675_TYPE_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "aj_max6675_type_platform.h"

typedef struct {
    const aj_max6675_pin_t cs;       /**< Chip Select pin */
} aj_max6675_t;

/**
 * @example Initializing a structure for AVR8
 *
 * @code
 *    static const aj_max6675_t max = {
 *        .cs = {
 *            .ddr  = &AJ_MAX6675_CS_DDR,
 *            .port = &AJ_MAX6675_CS_PORT,
 *            .mask = AJ_MAX6675_CS_MASK
 *        }
 *    };
 * @endcode
 */

#ifdef __cplusplus
}
#endif

#endif
