#ifndef AJ_FLASH_TYPE_INCLUDED
#define AJ_FLASH_TYPE_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif


#include <stdint.h>

typedef enum {
    AJ_FLASH_LATENCY_0 = 0x00U,		/*< Zero wait state, if 0 < SYSCLK < 24 MHz */
    AJ_FLASH_LATENCY_1 = 0x01U,		/*< One wait state, if 24 MHz < SYSCLK < 48 MHz */
    AJ_FLASH_LATENCY_2 = 0x02U		/*< Two wait states, if 48 MHz < SYSCLK < 72 MHz */
} aj_flash_latency_t;


#ifdef __cplusplus
}
#endif

#endif /* AJ_FLASH_TYPE_INCLUDED */
