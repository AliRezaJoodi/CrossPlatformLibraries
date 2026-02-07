// GitHub Account:  GitHub.com/AliRezaJoodi

#ifndef CHANGED_INCLUDED
#define CHANGED_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

uint8_t Changed_UpdateExact_u16(uint16_t value, uint16_t *value_last);
uint8_t Changed_UpdateThreshold_u16(uint16_t value, uint16_t *value_last, uint16_t threshold);
uint8_t Changed_UpdateThreshold_f32(float value, float *value_last, float threshold);

#ifdef __cplusplus
}
#endif
   
#endif
