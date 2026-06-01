// GitHub Account: GitHub.com/AliRezaJoodi

#include <stdint.h>
#include "qei_type.h"
#include "qei_port.h"
#include "qei.h"

//*************************************************
void QEI_Init(QEI_t *qei){
    QEI_A_ConfigAsInput(qei);
    QEI_B_ConfigAsInput(qei);

#if (QEI_PULL_UP == 0U)
    QEI_A_ConfigAsPullNone(qei);
    QEI_B_ConfigAsPullNone(qei);
#else
    QEI_A_ConfigAsPullUp(qei);
    QEI_B_ConfigAsPullUp(qei);
#endif

    qei->count = 0;
    qei->last = 0;
}


