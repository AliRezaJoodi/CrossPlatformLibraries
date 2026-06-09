#include "aj_array_u16.h"

//*************************************************************
uint16_t AJ_ArrayU16_Min(const uint16_t *arr, uint16_t len){
    uint16_t i = 0;
    uint16_t min = 0;

    if (arr == NULL || len == 0){
        return 0xFFFF;
    }

    min = arr[0];

    for(i = 1; i < len; i++){
        if(arr[i] < min){
            min = arr[i];
        }
    }

    return min;
}

//*************************************************************
uint16_t AJ_ArrayU16_Max(const uint16_t *arr, uint16_t len){
    uint16_t i = 0;
    uint16_t max = 0;

    if (arr == NULL || len == 0){
        return 0xFFFF;
    }

    max = arr[0];

    for(i = 1; i < len; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }

    return max;
}

//*************************************************************
uint16_t AJ_ArrayU16_Average(const uint16_t *arr, uint16_t len){
    uint32_t sum = 0;
    uint16_t i = 0;

    if (arr == NULL || len == 0){
        return 0xFFFF;
    }

    for(i = 0; i < len; i++){
        sum += arr[i];
    }

    return (uint16_t)(sum / len);
}

//*************************************************************
uint16_t AJ_ArrayU16_Find(const uint16_t *arr, uint16_t len, uint16_t value){
    uint16_t i;

    if (arr == NULL || len == 0){
        return 0xFFFF;
    }

    for(i = 0; i < len; i++){
        if(arr[i] == value){
            return i;
        }
    }

    return AJ_ARRAY_U16_ERROR;
}

//*************************************************************
void AJ_ArrayU16_Reverse(uint16_t *arr, uint16_t len){
    uint16_t i = 0;
    uint16_t tmp = 0;

    if (arr == NULL || len < 2){
        return;
    }

    for(i = 0; i < len / 2; i++){
        tmp = arr[i];
        arr[i] = arr[len - 1 - i];
        arr[len - 1 - i] = tmp;
    }
}

//*************************************************************
void AJ_ArrayU16_Clear(uint16_t *arr, uint16_t len){
    uint16_t i = 0;


    if (arr == NULL || len == 0){
        return;
    }

    for(i = 0; i < len; i++){
        arr[i] = 0;
    }
}