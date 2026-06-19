#ifndef AJ_MAX6675_TYPE_INCLUDED
#define AJ_MAX6675_TYPE_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

typedef struct {
    volatile uint8_t *ddr;      /**< Data Direction Register for this pin */
    volatile uint8_t *port;     /**< PORT register for this pin */
    const uint8_t     mask;
} aj_max6675_pin_t;

typedef struct {
    const aj_max6675_pin_t cs;       /**< Chip Select pin */
} aj_max6675_t;

/**
 * @example Initializing a structure
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
