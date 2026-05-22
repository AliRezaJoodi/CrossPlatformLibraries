#ifndef TIME_BASE_INCLUDED
#define TIME_BASE_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

void TimeBase_Refresh(void);
uint32_t TimeBase_GetTicks(void);

#ifdef __cplusplus
}
#endif

#endif

