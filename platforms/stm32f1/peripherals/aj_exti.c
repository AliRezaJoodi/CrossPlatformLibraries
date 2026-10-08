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
	EXTI->IMR = 0x00000000U;
	EXTI->EMR = 0x00000000U;
	EXTI->RTSR = 0x00000000U;
	EXTI->FTSR = 0x00000000U;
	EXTI->SWIER = 0x00000000U;
	EXTI->PR = 0x000FFFFFU;
}