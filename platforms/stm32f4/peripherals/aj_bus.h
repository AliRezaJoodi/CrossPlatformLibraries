#ifndef AJ_BUS_INCLUDED
#define AJ_BUS_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stm32f4xx.h>
#include "aj_bit_reg.h"
#include "aj_bus_type.h"

static inline void AJ_BUS_AHB1_EnableClock(aj_bus_ahb1_mask_t periphs){
}

static inline void AJ_BUS_AHB1_DisableClock(aj_bus_ahb1_mask_t periphs){
}

static inline aj_bus_clock_state_t AJ_BUS_AHB1_IsClockEnabled(aj_bus_ahb1_mask_t periphs){
	return 0;
}

static inline void AJ_BUS_AHB1_ForceReset(aj_bus_ahb1_mask_t periphs){	
}

static inline void AJ_BUS_AHB1_ReleaseReset(aj_bus_ahb1_mask_t periphs){
}

static inline void AJ_BUS_AHB1_EnableClockInLowPower(aj_bus_ahb1_mask_t periphs){
}

static inline void AJ_BUS_AHB1_DisableClockInLowPower(aj_bus_ahb1_mask_t periphs){
}

#ifdef __cplusplus
}
#endif

#endif  /* AJ_BUS_INCLUDED */
