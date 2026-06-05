// GitHub Account:  GitHub.com/AliRezaJoodi

#include <stdint.h>
#include "aj_timebase_config.h"
#include "aj_timebase_type.h"
#include "aj_timebase.h"

#if defined(AJ_TIMEBASE_REG8_U8) || defined(AJ_TIMEBASE_REG8_U16) || defined(AJ_TIMEBASE_REG8_U32)
    #include "aj_compiler_port.h"
#endif

static volatile aj_timebase_t ticks = 0;

void AJ_TimeBase_CountTicks(void) {
    ticks++;
}

aj_timebase_t AJ_TimeBase_GetTicks(void) {
    aj_timebase_t buffer;

    #if defined(AJ_TIMEBASE_REG8_U8) || defined(AJ_TIMEBASE_REG8_U16) || defined(AJ_TIMEBASE_REG8_U32)
			uint8_t sreg_save;
			AJ_INT_GLOBAL_SAVE(sreg_save);
			AJ_INT_GLOBAL_DISABLE();
    #endif

    buffer = ticks;

    #if defined(AJ_TIMEBASE_REG8_U8) || defined(AJ_TIMEBASE_REG8_U16) || defined(AJ_TIMEBASE_REG8_U32)
			AJ_INT_GLOBAL_RESTORE(sreg_save);
    #endif

    return buffer;
}

