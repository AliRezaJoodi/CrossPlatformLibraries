#ifndef AJ_SYSTICK_TYPE_INCLUDED
#define AJ_SYSTICK_TYPE_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif


#include <stdint.h>

typedef enum{
	AJ_SYSTICK_CLKSOURCE_EXTERNAL = 0U,	/**< External reference clock (HCLK/8) */
	AJ_SYSTICK_CLKSOURCE_CORE     = 1U	/**< Processor clock (HCLK) */
} aj_systick_clksource_t;


#ifdef __cplusplus
}
#endif

#endif	/* AJ_SYSTICK_TYPE_INCLUDED */
