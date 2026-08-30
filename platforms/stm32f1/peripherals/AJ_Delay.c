// GitHub Account: GitHub.com/AliRezaJoodi

#include <stm32f1xx.h>
#include "AJ_Delay.h"

//****************************************
void AJ_Delay_ms(uint32_t delay){
	volatile uint32_t tmp = SysTick->CTRL;
	((void)tmp);

	if (delay < 0xFFFFFFFFU){delay++;}

	while (delay){
		if ((SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk) != 0U){delay--;}
	}
}
