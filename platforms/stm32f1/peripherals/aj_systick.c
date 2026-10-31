#include "aj_systick.h"

/******************************************************************************/
/* Init                                                                       */
/******************************************************************************/
void AJ_SysTick_Init_1ms(uint32_t clk_hz){
	AJ_SysTick_ConfigureEnableState(AJ_DISABLE);
	AJ_SysTick_ConfigureInterruptState(AJ_DISABLE);
	AJ_SysTick_ConfigureClockSource(AJ_SYSTICK_CLKSOURCE_CORE);
	AJ_SysTick_WriteLoad((clk_hz / 1000U) - 1U);
	AJ_SysTick_ClearValue();
	AJ_SysTick_ConfigureEnableState(AJ_ENABLE);
}
