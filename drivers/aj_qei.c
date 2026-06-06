// GitHub Account: GitHub.com/AliRezaJoodi

#include <stdint.h>
#include "aj_qei_type.h"
#include "aj_qei_port.h"
#include "aj_qei.h"

//*************************************************
void AJ_QEI_Init(aj_QEI_t *qei){
    AJ_QEI_A_ConfigAsInput(qei);
    AJ_QEI_B_ConfigAsInput(qei);

#if (AJ_QEI_PULL_UP == 0U)
    AJ_QEI_A_ConfigAsPullNone(qei);
    AJ_QEI_B_ConfigAsPullNone(qei);
#else
    AJ_QEI_A_ConfigAsPullUp(qei);
    AJ_QEI_B_ConfigAsPullUp(qei);
#endif

    qei->count = 0;
    qei->last = 0;
}


