// GitHub Account: GitHub.com/AliRezaJoodi

#include <stm32f1xx.h>
#include "aj_dwt_delay.h"

//****************************************
void AJ_DelayWithDWT_us(uint32_t clk_hz, uint32_t us){
	uint32_t cycle_delay = (clk_hz / 1000000U) * us;
	if (cycle_delay == 0U){cycle_delay = 1U;}

	uint32_t start = DWT->CYCCNT;					// sample current cycle count
	while ((uint32_t)(DWT->CYCCNT - start) < cycle_delay){}		// spin until elapsed
}
