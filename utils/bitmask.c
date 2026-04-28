#include "bitmask.h"

uint8_t BitMask_First8(uint8_t mask){
    if (mask == 0)
        return 8;

#if defined(__GNUC__)
    return (uint8_t)__builtin_ctz((uint32_t)mask);
#else
    uint8_t i = 0;
    while ((mask & 1) == 0) {
        mask >>= 1;
        i++;
    }
    return i;
#endif
}

