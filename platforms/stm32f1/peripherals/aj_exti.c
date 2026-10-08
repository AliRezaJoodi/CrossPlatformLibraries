// GitHub Account: GitHub.com/AliRezaJoodi

//#include <stdint.h>
#include <stm32f1xx.h>
//#include "aj_type.h"
//#include "aj_exti_type.h"
#include "aj_exti.h"

/******************************************************************************/
/* De-initialization                                                          */
/******************************************************************************/
void AJ_EXTI_DeInit(void){
	/* Interrupt mask register set to default reset values */
	EXTI->IMR = 0x00000000U;
	/* Event mask register set to default reset values */
	EXTI->EMR = 0x00000000U;
	/* Rising trigger selection register set to default reset values */
	EXTI->RTSR = 0x00000000U;
	/* Falling trigger selection register set to default reset values */
	EXTI->FTSR = 0x00000000U;
	/* Software interrupt event register set to default reset values */
	EXTI->SWIER = 0x00000000U;
	/* Pending register clear */
	EXTI->PR = 0x000FFFFFU;
}