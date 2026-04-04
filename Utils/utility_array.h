#ifndef UTILITY_ARRAY_INCLUDED
#define UTILITY_ARRAY_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

static inline uint16_t Array_Min_u16(const uint16_t *arr, uint16_t len){
    uint16_t i;
    uint16_t min = arr[0];

    for(i = 1; i < len; i++){
        if(arr[i] < min){
            min = arr[i];
        }
    }

    return min;
}

static inline uint16_t Array_Max_u16(const uint16_t *arr, uint16_t len){
    uint16_t i;
    uint16_t max = arr[0];

    for(i = 1; i < len; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }

    return max;
}

static inline uint16_t Array_Average_u16(const uint16_t *arr, uint16_t len){
    uint32_t sum = 0;
    uint16_t i;

    for(i = 0; i < len; i++){
        sum += arr[i];
    }

    return (uint16_t)(sum / len);
}

static inline int16_t Array_Find_u16(const uint16_t *arr, uint16_t len, uint16_t value){
    uint16_t i;

    for(i = 0; i < len; i++){
        if(arr[i] == value){
            return (int16_t)i;
        }
    }

    return -1;
}

static inline void Array_Reverse_u8(uint8_t *arr, uint16_t len){
    uint16_t i;
    uint8_t tmp;

    for(i = 0; i < len / 2; i++){
        tmp = arr[i];
        arr[i] = arr[len - 1 - i];
        arr[len - 1 - i] = tmp;
    }
}

static inline void Array_Clear_u8(uint8_t *arr, uint16_t len){
    uint16_t i;

    for(i = 0; i < len; i++){
        arr[i] = 0;
    }
}

#ifdef __cplusplus
}
#endif

#endif
