#include <stdint.h>
#include "aj_change_u16.h"

/********************************************************************************/
uint8_t AJ_ChangeU16_Exact(aj_change_u16_t *obj, uint16_t value){
    if (value == obj->previous){
        return AJ_CHANGE_U16_NO;
    }

    obj->previous = value;
    return AJ_CHANGE_U16_YES;
}

/********************************************************************************/
uint8_t AJ_ChangeU16_Threshold(aj_change_u16_t *obj, uint16_t value, uint16_t threshold){
    uint16_t prev = obj->previous;
    uint16_t diff = 0;

    if (value > prev){
        diff = value - prev;
    }
    else {
        diff = prev - value;
    }

    if (diff < threshold){
        return AJ_CHANGE_U16_NO;
    }

    obj->previous = value;
    return AJ_CHANGE_U16_YES;
}

