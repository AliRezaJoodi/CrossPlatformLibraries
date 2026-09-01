// GitHub Account: GitHub.com/AliRezaJoodi

#include <stm32f1xx.h>
#include "AJ_Delay.h"

//****************************************
void AJ_Delay_ms(uint32_t ms){
	volatile uint32_t tmp = SysTick->CTRL;
	((void)tmp);

	if (ms < 0xFFFFFFFFU){ms++;}

	while (ms){
		if ((SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk) != 0U){
			ms--;
		}
	}
}

//****************************************
// SysTick-based blocking delay; does not modify any register (reads only).
// Accumulates wrap-arounds, so it works for delays longer than one period too.
void AJ_Delay_us(uint32_t clk_hz, uint32_t us){
	uint32_t tick_delay = (clk_hz / 1000000U) * us;    // ticks to wait
	uint32_t period     = SysTick->LOAD + 1U;             // ticks per full period
	uint32_t last       = SysTick->VAL;                   // last sampled count
	uint32_t elapsed 		= 0U;
	
	while (elapsed < tick_delay){
		uint32_t now = SysTick->VAL;
		if (now > last){
			elapsed += last + (period - now);             // wrapped through zero
		}
		else{
			elapsed += last - now;                        // normal counting down
		}
		last = now;
	}
}

//****************************************
void AJ_DelayWithDWT_us(uint32_t clk_hz, uint32_t us){
	uint32_t cycle_delay = (clk_hz / 1000000U) * us;
	if (cycle_delay == 0U){cycle_delay = 1U;}

	uint32_t start = DWT->CYCCNT;					// sample current cycle count
	while ((uint32_t)(DWT->CYCCNT - start) < cycle_delay){}		// spin until elapsed
}
