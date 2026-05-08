#include <stdint.h>
#include "changed.h"

/********************************************************************************/
uint8_t Changed_Exact(uint16_t value, uint16_t *previous){
    if (value == *previous){
        return 0;
    }

    *previous = value;
    return 1;
}

/********************************************************************************/
uint8_t Changed_Threshold(uint16_t value, uint16_t *previous, uint16_t threshold){
    uint16_t prev = *previous;
    uint16_t diff = 0;

    if (value > prev){
        diff = value - prev;
    }
    else {
        diff = prev - value;
    }

    if (diff < threshold){
        return 0;
    }

    *previous = value;
    return 1;
}

