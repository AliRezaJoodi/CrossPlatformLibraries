// GitHub Account: GitHub.com/AliRezaJoodi

#include <stdint.h>
#include "hardware.h"   /* Project-level overrides */
#include "qei_types.h"
#include "qei_port.h"
#include "qei.h"

//*************************************************
void QEI_Init(QEI_t *qei){
    QEI_A_ConfigInput(qei);
    QEI_B_ConfigInput(qei);

#if (QEI_PULL_UP == 0U)
    QEI_A_ConfigPullNone(qei);
    QEI_B_ConfigPullNone(qei);
#else
    QEI_A_ConfigPullUp(qei);
    QEI_B_ConfigPullUp(qei);
#endif

    qei->count = 0;
    qei->last = 0;
}


