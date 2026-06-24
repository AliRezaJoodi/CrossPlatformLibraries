#ifndef AJ_BUS_TYPE_INCLUDED
#define AJ_BUS_TYPE_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stm32f4xx.h>

typedef enum {
	AJ_BUS_CLOCK_DISABLE = 0U,
	AJ_BUS_CLOCK_ENABLE  = 1U
} aj_bus_clock_state_t;

typedef enum {
	AJ_BUS_AHB1_ALL = 0xFFFFFFFFU
} aj_bus_ahb1_mask_t;	

typedef enum {
	AJ_BUS_AHB2_ALL = 0xFFFFFFFFU
} aj_bus_ahb2_mask_t;	

typedef enum {
	AJ_BUS_AHB3_ALL = 0xFFFFFFFFU
} aj_bus_ahb3_mask_t;	

typedef enum {
	AJ_BUS_APB1_ALL = 0xFFFFFFFFU
} aj_bus_apb1_mask_t;	

typedef enum {
	AJ_BUS_APB2_ALL = 0xFFFFFFFFU
} aj_bus_apb2_mask_t;	

#ifdef __cplusplus
}
#endif

#endif  /* AJ_BUS_TYPE_INCLUDED */