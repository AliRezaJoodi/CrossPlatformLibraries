// GitHub Account: GitHub.com/AliRezaJoodi

#include <stm32f1xx.h>
#include "AJ_Delay.h"

//****************************************
void AJ_Delay_ms(uint32_t delay){
	volatile uint32_t tmp = SysTick->CTRL;
	((void)tmp);

	if (delay < 0xFFFFFFFFU){delay++;}

	while (delay){
		if ((SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk) != 0U){
			delay--;
		}
	}
}

//****************************************
void AJ_Delay_us(uint32_t clk_hz, uint32_t delay){
	uint32_t cycle_delay = (clk_hz / 1000000U) * delay;
	if (cycle_delay == 0U){cycle_delay = 1U;}

	uint32_t start = DWT->CYCCNT;					// sample current cycle count
	while ((uint32_t)(DWT->CYCCNT - start) < cycle_delay){}		// spin until elapsed
}
