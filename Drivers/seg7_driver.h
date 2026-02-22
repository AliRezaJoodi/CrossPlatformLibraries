#ifndef SEG7_DRIVER_INCLUDED
#define SEG7_DRIVER_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include "seg7_driver_config.h"
#include "seg7_driver_port.h"
#include "seg7_driver_hw.h"

void Seg7_Init(void);
void Seg7_SetBuffer(uint8_t *buffer);
void Seg7_Refresh(void);

#ifdef __cplusplus
}
#endif

#endif
