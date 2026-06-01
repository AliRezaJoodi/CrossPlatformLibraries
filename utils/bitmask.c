#include "bitmask.h"

//**************************************
uint8_t BitMask_CTZ8(uint8_t mask){
    if (mask == 0U)
        return 8U;

#if defined(__GNUC__) || defined(__clang__)
    return (uint8_t)__builtin_ctz((uint32_t)mask);
#else
    uint8_t count = 0U;

    while ((mask & 1U) == 0U) {
        mask >>= 1U;
        ++count;
    }

    return count;
#endif
}

//**************************************
uint8_t BitMask_First8(uint8_t mask){
    return BitMask_CTZ8(mask);
}
