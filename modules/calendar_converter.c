
#include <stdint.h>
#include "calendar_converter.h"

static const uint8_t table_jalaali[6][12] = {
    {11, 10, 10,  9,  9,  9,  8,  9,  9, 10, 11,  9},
    {20, 20, 21, 21, 22, 22, 22, 22, 21, 21, 20, 19},
    {11, 10, 10,  9,  9,  9,  8,  9,  9, 10, 11, 10},
    {20, 20, 21, 21, 22, 22, 22, 22, 21, 21, 20, 19},
    {12, 11, 11, 10, 10, 10,  9, 10, 10, 11, 12, 10},
    {19, 19, 20, 20, 21, 21, 21, 21, 20, 20, 19, 18}
};

static const uint8_t table_gregorian[6][12] = {
    {20, 19, 19, 19, 20, 20, 21, 21, 21, 21, 20, 20},
    {10, 11, 10, 12, 11, 11, 10, 10, 10,  9, 10, 10},
    {19, 18, 20, 20, 21, 21, 22, 22, 22, 22, 21, 21},
    {11, 12, 10, 11, 10, 10,  9,  9,  9,  8,  9,  9},
    {20, 19, 20, 20, 21, 21, 22, 22, 22, 22, 21, 21},
    {10, 11,  9, 11, 10, 10,  9,  9,  9,  8,  9,  9}
};

//***************************************************************
void Calendar_ConvertGregorianToJalaali(date_t *gc, date_t *jc){
    uint8_t k = 0;
    uint8_t t1 = 0;
    uint8_t t2 = 0;

    k = gc->year & 0x03;    // gc->year % 4
    if(k == 3){k = 2;};
    k *= 2;
    t1 = table_gregorian[k][gc->month - 1];
    t2 = table_gregorian[k+1][gc->month - 1];

    if(gc->month < 3 || (gc->month == 3 && gc->day <= table_gregorian[k][gc->month-1])){
        jc->year = gc->year + 78;
    }
    else{
        jc->year = gc->year + 79;
    }

    //jc->year = jc->year % 100;
    if (jc->year >= 100) jc->year -= 100;

    if(gc->day <= t1){
        jc->day = gc->day + t2;
        //jc->month = (gc->month + 8) % 12 + 1;
        jc->month = gc->month + 9;
        if (jc->month > 12) {
            jc->month -= 12;
        }
    }
    else{
        jc->day = gc->day - t1;
        //jc->month = (gc->month + 9) % 12 + 1;
        jc->month = gc->month + 10;
        if (jc->month > 12){
            jc->month -= 12;
        }
    }
}

//***************************************************************
void Calendar_ConvertJalaaliToGregorian(date_t *jc, date_t *gc){
    uint8_t k = 0;
    uint8_t t1 = 0;
    uint8_t t2 = 0;

    k = (jc->year + 100) & 0x03;    //  % 4
    if(k == 0){
        k = 2;
    }
    else{
        k = k + k;
    }

    t1 = table_jalaali[k-2][jc->month - 1];
    t2 = table_jalaali[k-1][jc->month - 1];

    if(jc->month < 10 || (jc->month == 10 && jc->day <= table_jalaali[k-2][jc->month-1])){
        //gc->year = (jc->year + 100) - 79;
        gc->year = jc->year + 21;
    }
    else{
        //gc->year = (jc->year + 100) - 78;
        gc->year = jc->year + 22;
    }

    //gc->year = gc->year % 100;
    if (gc->year >= 100){
        gc->year -= 100;
    }

    if(jc->day <= t1){
        gc->day = jc->day + t2;
        //gc->month = (jc -> month + 1) % 12 + 1;
        gc->month = jc->month + 2;
        if (gc->month > 12){
            gc->month -= 12;
        }
    }
    else{
        gc->day = jc->day - t1;
        //gc->month = (jc->month + 2) % 12 + 1;
        gc->month = jc->month + 3;
        if (gc->month > 12){
            gc->month -= 12;
        }
    }
}


