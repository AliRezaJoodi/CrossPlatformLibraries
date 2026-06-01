#ifndef QEI_TYPE_INCLUDED
#define QEI_TYPE_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "qei_hw.h"

typedef struct {
    volatile uint8_t    *ddr;      /**< Data Direction Register */
    volatile uint8_t    *port;     /**< Port register */
    volatile uint8_t    *pin;      /**< Pin register */
    const uint8_t       index;    /**< Pin index number */
    const uint8_t       mask;
} QEI_Pin_t;

typedef struct {
    const QEI_Pin_t     chA;
    const QEI_Pin_t     chB;

    #if (QEI_Z == 1U)
    const QEI_Pin_t     chZ;
    #endif

    uint32_t            count;
    uint8_t             last;

    #if (QEI_Z == 1U)
    uint8_t             flag;
    #endif
} QEI_t;

/**
 * @example
 * Example: initializing a structure
 *
 * @code
 * QEI_t qei = {
 *     .chA = {
 *         .ddr   = &QEI_A_DDR,
 *         .port  = &QEI_A_PORT,
 *         .pin   = &QEI_A_PIN,
 *         .index = QEI_A_BIT,
 *         .mask  = QEI_A_MASK
 *     },
 *     .chB = {
 *         .ddr   = &QEI_B_DDR,
 *         .port  = &QEI_B_PORT,
 *         .pin   = &QEI_B_PIN,
 *         .index = QEI_B_BIT,
 *         .mask  = QEI_B_MASK
 *     },
 *     .count = 0U,
 *     .last  = 0U
 * };
 * @endcode
 */

#ifdef __cplusplus
}
#endif

#endif
