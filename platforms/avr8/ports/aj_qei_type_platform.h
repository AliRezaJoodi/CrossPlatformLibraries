#ifndef AJ_QEI_TYPE_PLATFORM_INCLUDED
#define AJ_QEI_TYPE_PLATFORM_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif


#include <stdint.h>

typedef struct {
    volatile uint8_t    *ddr;       /**< Data Direction Register */
    volatile uint8_t    *port;      /**< Port register */
    volatile uint8_t    *pin;       /**< Pin register */
    const uint8_t       pos;        /**< Pin position */
    const uint8_t       mask;
} aj_qei_pin_t;


#ifdef __cplusplus
}
#endif

#endif
