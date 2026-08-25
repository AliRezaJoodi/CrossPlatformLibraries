// GitHub Account:  GitHub.com/AliRezaJoodi

#include <stdint.h>
#include "aj_timebase_type.h"
#include "aj_timebase.h"

#if (AJ_TARGET_MCU_BITS == 8U)
    #include "aj_compiler.h"
#endif

///static volatile aj_timebase_t ticks = 0;
volatile aj_timebase_t timebase_tick = 0;

//void AJ_TimeBase_Handler(void) {
//    timebase_tick++;
//}

aj_timebase_t AJ_TimeBase_GetTick(void) {
    aj_timebase_t buffer;

    #if (AJ_TARGET_MCU_BITS == 8U)
        #if (AJ_TARGET_TICK_BITS == 16U) || (AJ_TARGET_TICK_BITS == 32U)
            uint8_t sreg_save;
            AJ_INT_GLOBAL_SAVE(sreg_save);
            AJ_INT_GLOBAL_DISABLE();
        #endif
    #endif

    buffer = timebase_tick;

    #if (AJ_TARGET_MCU_BITS == 8U)
        #if (AJ_TARGET_TICK_BITS == 16U) || (AJ_TARGET_TICK_BITS == 32U)
			AJ_INT_GLOBAL_RESTORE(sreg_save);
        #endif
    #endif

    return buffer;
}

