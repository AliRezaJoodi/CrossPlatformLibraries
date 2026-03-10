#ifndef CONVERTER_CALENDAR_INCLUDED
#define CONVERTER_CALENDAR_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

typedef struct {
    uint8_t year;
    uint8_t month;
    uint8_t day;
} date_t;

void ConvertCalendar_GregorianToJalaali(date_t *gc, date_t *jc);
void ConvertCalendar_JalaaliToGregorian(date_t *jc, date_t *gc);

#ifdef __cplusplus
}
#endif

#endif

