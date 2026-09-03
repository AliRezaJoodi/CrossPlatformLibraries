// GitHub Account: GitHub.com/AliRezaJoodi

#include <stm32f1xx.h>
#include "aj_target.h"
#include "aj_systick_delay.h"

//****************************************
void AJ_SysTick_Delay_ms(uint32_t ms){
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
void AJ_SysTick_Delay_us(uint32_t us){
	uint32_t tick 		= (AJ_TARGET_CORE_CLOCK_HZ / 1000000U) * us;    // ticks to wait
	uint32_t period     = SysTick->LOAD + 1U;							// ticks per full period
	uint32_t last       = SysTick->VAL;                					// last sampled count
	uint32_t elapsed	= 0U;
	
	while (elapsed < tick){
		uint32_t now = SysTick->VAL;
		if (now > last){
			elapsed += last + (period - now);             				// wrapped through zero
		}
		else{
			elapsed += last - now;                        // normal counting down
		}
		last = now;
	}
}
