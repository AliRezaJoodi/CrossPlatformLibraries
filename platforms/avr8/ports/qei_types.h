#ifndef QEI_TYPES_INCLUDED
#define QEI_TYPES_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

/** @brief Configures the pull resistor mode for a encoder pin. */
//typedef enum{
//    QEI_PULL_NONE = 0U,   /**< No pull resistor */
//    QEI_PULL_UP   = 1U,   /**< No pull resistor */
//} QEI_PullMode_t;

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
    const uint8_t       config;
    uint32_t            count;
    uint8_t             last;
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
