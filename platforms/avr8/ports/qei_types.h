#ifndef QEI_TYPES_INCLUDED
#define QEI_TYPES_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

typedef struct {
    volatile uint8_t    *ddr;      /**< Data Direction Register */
    volatile uint8_t    *port;     /**< Port register */
    volatile uint8_t    *pin;      /**< Pin register */
    const uint8_t       index;    /**< Pin index number */
    const uint8_t       mask;
} QEI_Pin_t;

typedef struct {
    const QEI_Pin_t      chA;
    const QEI_Pin_t      chB;
    uint32_t             count;
    uint8_t              last;
} QEI_t;

/**
 * @example
 * Example: initializing a structure
 *
 * @code

 * @endcode
 */

#ifdef __cplusplus
}
#endif

#endif
