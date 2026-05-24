// GitHub Account:  GitHub.com/AliRezaJoodi

#include <stdint.h>
#include "hardware.h"
#include "timebase.h"

#if defined(TIMEBASE_REG8_U32)
    #include "compiler_port.h"
#endif

#if defined(TIMEBASE_REG32_U32) || defined(TIMEBASE_REG8_U32)
    static volatile uint32_t ticks = 0;

#elif defined(TIMEBASE_REG8_U8)
    static volatile uint8_t ticks = 0;

#else
    #error "None TIMEBASE configurations defined!"

#endif

void TimeBase_CountTicks(void) {
    ticks++;
}

#if defined(TIMEBASE_REG32_U32)
    uint32_t TimeBase_GetTicks(void) {
        return ticks;
    }

#elif defined(TIMEBASE_REG8_U32)
    uint32_t TimeBase_GetTicks(void) {
        uint32_t buffer;

        INTERRUPTS_SAVE();
        INTERRUPTS_DISABLE();
        buffer = ticks;
        INTERRUPTS_RESTORE();
        return buffer;
    }

#elif defined(TIMEBASE_REG8_U8)
    uint8_t TimeBase_GetTicks(void) {
        return ticks;
    }

#else
    #error "None TIMEBASE configurations defined!"

#endif
