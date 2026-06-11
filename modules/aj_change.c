#include <stdint.h>
#include "aj_change.h"

/********************************************************************************/
uint8_t AJ_Change_Exact(aj_change_t *obj, uint16_t value){
    if (value == obj->previous){
        return AJ_CHANGE_NO;
    }

    obj->previous = value;
    return AJ_CHANGE_YES;
}

/********************************************************************************/
uint8_t AJ_Change_Threshold(aj_change_t *obj, uint16_t value, uint16_t threshold){
    uint16_t prev = obj->previous;
    uint16_t diff = 0;

    if (value > prev){
        diff = value - prev;
    }
    else {
        diff = prev - value;
    }

    if (diff < threshold){
        return AJ_CHANGE_NO;
    }

    obj->previous = value;
    return AJ_CHANGE_YES;
}

