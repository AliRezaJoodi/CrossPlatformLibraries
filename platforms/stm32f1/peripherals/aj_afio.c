// GitHub Account: GitHub.com/AliRezaJoodi

#include <stm32f1xx.h>
#include "aj_afio.h"

/******************************************************************************/
/* De-initialization                                                          */
/******************************************************************************/
void AJ_AFIO_EXTI_DeInit(void){
	AFIO->EXTICR[0] = 0x00000000U;
	AFIO->EXTICR[1] = 0x00000000U;
	AFIO->EXTICR[2] = 0x00000000U;
	AFIO->EXTICR[3] = 0x00000000U;
}