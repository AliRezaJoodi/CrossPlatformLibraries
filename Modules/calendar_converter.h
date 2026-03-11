#ifndef CALENDAR_CONVERTER_INCLUDED
#define CALENDAR_CONVERTER_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

typedef struct {
    uint8_t year;
    uint8_t month;
    uint8_t day;
} date_t;

void Calendar_ConvertGregorianToJalaali(date_t *gc, date_t *jc);
void Calendar_ConvertJalaaliToGregorian(date_t *jc, date_t *gc);

#ifdef __cplusplus
}
#endif

#endif

