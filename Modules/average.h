// GitHub Account:  GitHub.com/AliRezaJoodi

#ifndef AVERAGE_INCLUDED
#define AVERAGE_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include <average_config.h>

typedef struct {
    uint32_t sum;
    uint8_t count;
    uint16_t average;
} AverageBlock_u16_t;

typedef struct {
    uint16_t buf[AVERAGE_COUNT];
    uint8_t  index;
    uint32_t sum;
    uint8_t  count;
} AverageMoving_u16_t;

uint16_t Average_BlockUpdate_u16(uint16_t value, AverageBlock_u16_t *avgBlock);
uint16_t Average_MovingWithCircularBuffer_u16(uint16_t value, AverageMoving_u16_t *avgMoving);

#ifdef __cplusplus
}
#endif
  
#endif
