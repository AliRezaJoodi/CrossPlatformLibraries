// GitHub Account:  GitHub.com/AliRezaJoodi

#include <stdint.h>
#include "timebase_config.h"
#include "timebase_type.h"
#include "timebase.h"

#if defined(TIMEBASE_REG8_U8) || defined(TIMEBASE_REG8_U16) || defined(TIMEBASE_REG8_U32)
    #include "compiler_port.h"
#endif

static volatile timebase_t ticks = 0;

void TimeBase_CountTicks(void) {
    ticks++;
}

timebase_t TimeBase_GetTicks(void) {
    timebase_t buffer;
	
    #if defined(TIMEBASE_REG8_U8) || defined(TIMEBASE_REG8_U16) || defined(TIMEBASE_REG8_U32)
			uint8_t sreg_save;
			INT_GLOBAL_SAVE(sreg_save);
			INT_GLOBAL_DISABLE();
    #endif

    buffer = ticks;

    #if defined(TIMEBASE_REG8_U8) || defined(TIMEBASE_REG8_U16) || defined(TIMEBASE_REG8_U32)
			INT_GLOBAL_RESTORE(sreg_save);
    #endif

    return buffer;
}

