#include "aj_systick.h"

/******************************************************************************/
/* Init                                                                       */
/******************************************************************************/
void AJ_SysTick_Init_1ms(uint32_t clk_hz){
	AJ_SysTick_ConfigEnableState(AJ_DISABLE);
	AJ_SysTick_ConfigInterruptState(AJ_DISABLE);
	AJ_SysTick_ConfigClockSource(AJ_SYSTICK_CLKSOURCE_CORE);
	AJ_SysTick_WriteLoad((clk_hz / 1000U) - 1U);
	AJ_SysTick_ClearValue();
	AJ_SysTick_ConfigEnableState(AJ_ENABLE);
}
