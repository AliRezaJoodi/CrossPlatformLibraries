
#include <stdint.h>
#include "hardware.h"
#include "timebase.h"

//#if defined(__AVR__) || defined(__CODEVISIONAVR__) || defined(__ICCAVR__)
//#include "compiler_port.h"
//#endif


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
    #error "Pending function!"
#elif defined(TIMEBASE_REG8_U8)
    uint8_t TimeBase_GetTicks(void) {
        return ticks;
    }
#else
    #error "None TIMEBASE configurations defined!"
#endif

//uint32_t TimeBase_GetTicks(void) {
//    #if defined(__AVR__) || defined(__CODEVISIONAVR__) || defined(__ICCAVR__)
//        uint32_t buffer;
//        uint8_t sreg = SREG;
//        SREG &= ~(1U << 7);
//        buffer = ticks;
//        SREG = sreg;
//        return buffer;
//    #else
//        return ticks;
//    #endif
//}
