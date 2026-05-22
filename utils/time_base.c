
#include "time_base.h"

static volatile uint32_t ticks = 0;

void TimeBase_Refresh(void) {
    ticks++;
}

uint32_t TimeBase_GetTicks(void) {
    return ticks;
}
