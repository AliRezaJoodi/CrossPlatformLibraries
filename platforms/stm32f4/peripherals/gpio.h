#ifndef GPIO_INCLUDED
#define GPIO_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stm32f4xx.h>	
#include "bit.h"

typedef enum{
	GPIO_PIN_0  = 0U,
	GPIO_PIN_1  = 1U,
	GPIO_PIN_2  = 2U,
	GPIO_PIN_3  = 3U,
	GPIO_PIN_4  = 4U,
	GPIO_PIN_5  = 5U,
	GPIO_PIN_6  = 6U,
	GPIO_PIN_7  = 7U,
	GPIO_PIN_8  = 8U,
	GPIO_PIN_9  = 9U,
	GPIO_PIN_10 = 10U,
	GPIO_PIN_11 = 11U,
	GPIO_PIN_12 = 12U,
	GPIO_PIN_13 = 13U,
	GPIO_PIN_14 = 14U,
	GPIO_PIN_15 = 15U
} GPIO_Pin_t;

typedef enum{
	GPIO_PINMASK_0  = (1UL << 0),
	GPIO_PINMASK_1  = (1UL << 1),
	GPIO_PINMASK_2  = (1UL << 2),
	GPIO_PINMASK_3  = (1UL << 3),
	GPIO_PINMASK_4  = (1UL << 4),
	GPIO_PINMASK_5  = (1UL << 5),
	GPIO_PINMASK_6  = (1UL << 6),
	GPIO_PINMASK_7  = (1UL << 7),
	GPIO_PINMASK_8  = (1UL << 8),
	GPIO_PINMASK_9  = (1UL << 9),
	GPIO_PINMASK_10 = (1UL << 10),
	GPIO_PINMASK_11 = (1UL << 11),
	GPIO_PINMASK_12 = (1UL << 12),
	GPIO_PINMASK_13 = (1UL << 13),
	GPIO_PINMASK_14 = (1UL << 14),
	GPIO_PINMASK_15 = (1UL << 15)
} GPIO_PinMask_t;



#ifdef __cplusplus
}
#endif

#endif