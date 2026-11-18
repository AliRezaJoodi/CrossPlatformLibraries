#ifndef AJ_RCC_TYPE_INCLUDED
#define AJ_RCC_TYPE_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif


#include <stdint.h>
#include <stm32f1xx.h>

/**
 * @brief HSE clock source options.
 */
typedef enum{
	AJ_RCC_HSE_CLKSOURCE_XTAL   = 0U,	/**< External oscillator not bypassed (two-pin crystal) */
	AJ_RCC_HSE_CLKSOURCE_EXTCLK = 1U	/**< External clock applied to OSC_IN (one-pin bypass) */
} aj_hse_clksource_t;



#ifdef __cplusplus
}
#endif

#endif  /* AJ_RCC_TYPE_INCLUDED */