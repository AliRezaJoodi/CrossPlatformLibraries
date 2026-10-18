// GitHub Account: GitHub.com/AliRezaJoodi

#include <stm32f1xx.h>
#include "aj_pwr.h"

/******************************************************************************/
/* De-initialization                                                          */
/******************************************************************************/
void AJ_PWR_DeInit(void){
	PWR->CR = 0x00000000U;
	PWR->CSR = 0x00000000U;
}
