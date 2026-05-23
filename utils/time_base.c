
#include <stdint.h>
#include "time_base.h"

#if defined(__AVR__) || defined(__CODEVISIONAVR__) || defined(__ICCAVR__)
#include "compiler_port.h"
#endif

static volatile uint32_t ticks = 0;

void TimeBase_Refresh(void) {
    ticks++;
}

uint32_t TimeBase_GetTicks(void) {
    #if defined(__AVR__) || defined(__CODEVISIONAVR__) || defined(__ICCAVR__)
        uint32_t buffer;
        uint8_t sreg = SREG;
        SREG &= ~(1U << 7);
        buffer = ticks;
        SREG = sreg;
        return buffer;
    #else
        return ticks;
    #endif
}
