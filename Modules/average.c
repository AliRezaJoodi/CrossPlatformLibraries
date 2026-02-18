// GitHub Account:  GitHub.com/AliRezaJoodi

#include "average.h"

/* ---- Power of two detection ---- */
#define IS_POWER_OF_TWO(x)   (((x) != 0) && (((x) & ((x) - 1)) == 0))

#if IS_POWER_OF_TWO(AVERAGE_COUNT)
    #if (AVERAGE_COUNT == 1)
        #define AVERAGE_SHIFT 0
    #elif (AVERAGE_COUNT == 2)
        #define AVERAGE_SHIFT 1
    #elif (AVERAGE_COUNT == 4)
        #define AVERAGE_SHIFT 2
    #elif (AVERAGE_COUNT == 8)
        #define AVERAGE_SHIFT 3
    #elif (AVERAGE_COUNT == 16)
        #define AVERAGE_SHIFT 4
    #elif (AVERAGE_COUNT == 32)
        #define AVERAGE_SHIFT 5
    #elif (AVERAGE_COUNT == 64)
        #define AVERAGE_SHIFT 6
    #elif (AVERAGE_COUNT == 128)
        #define AVERAGE_SHIFT 7
    #endif

    #define AVERAGE_DIV(sum)   ((sum) >> AVERAGE_SHIFT)
#else
    #define AVERAGE_DIV(sum)   ((sum) / AVERAGE_COUNT)
    #warning "average library: using more CPU cycles because AVERAGE_COUNT is not a power of two"
#endif

/* Average Block Update */
/***************************************************************/
uint16_t Average_BlockUpdate(uint16_t value, AverageBlock_t *avg){
    avg->sum += value;
    avg->count ++;

    if(avg->count >= AVERAGE_COUNT){
        avg->average = (uint16_t)AVERAGE_DIV(avg->sum);
        avg->sum = 0;
        avg->count = 0;
    }

    return avg->average;
}

/* Moving Average Method with Circular Buffer */
/***************************************************************/
uint16_t Average_MovingUpdate(uint16_t value, AverageMoving_t *avg){
    avg->sum -= avg->buf[avg->index];
    avg->buf[avg->index] = value;
    avg->sum += value;

    avg->index ++;
    if(avg->index >= AVERAGE_COUNT){
        avg->index = 0;
        avg->full = 1;  /* Mark buffer as full, steady-state averaging begins */
    }

    /* Steady-state: buffer full, use fixed-size optimized division */
    if (avg->full){
        return (uint16_t)AVERAGE_DIV(avg->sum);
    }

    /* Divide by current sample count during startup to avoid initial averaging bias */
    return (uint16_t)(avg->sum / avg->index);
}