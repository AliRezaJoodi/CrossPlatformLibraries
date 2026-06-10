/**
 * @file    calendar_converter.h
 * @brief   Gregorian ? Jalaali (Persian) date conversion library
 *
 * This library provides lightweight functions to convert dates between
 * Gregorian and Jalaali (Persian) calendars.
 *
 * @note
 * - Year is stored as a 2-digit value (00–99).
 * - The valid range depends on the application and is not strictly enforced.
 * - Leap year handling is internally approximated using precomputed tables.
 *
 * @warning
 * - This library does NOT validate input dates.
 * - User must ensure that the input date is valid.
 */

#ifndef AJ_CALENDAR_CONVERTER_INCLUDED
#define AJ_CALENDAR_CONVERTER_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

typedef struct {
    uint8_t year;       /**< Year (00–99) */
    uint8_t month;      /**< Month (1–12) */
    uint8_t day;        /**< Day (1–31) */
} aj_date_t;

/**
 * @brief Convert Gregorian date to Jalaali date
 *
 * This function converts a given Gregorian date to its equivalent
 * Jalaali (Persian) date.
 *
 * @param   gc   Pointer to input Gregorian date
 * @param   jc   Pointer to output Jalaali date
 *
 * @note
 * Input date must be valid. No validation is performed.
 */
void AJ_Calendar_ConvertGregorianToJalaali(aj_date_t *gc, aj_date_t *jc);

/**
 * @brief Convert Jalaali date to Gregorian date
 *
 * This function converts a given Jalaali (Persian) date to its
 * equivalent Gregorian date.
 *
 * @param   jc   Pointer to input Jalaali date
 * @param   gc   Pointer to output Gregorian date
 *
 * @note
 * Input date must be valid. No validation is performed.
 */
void AJ_Calendar_ConvertJalaaliToGregorian(aj_date_t *jc, aj_date_t *gc);

#ifdef __cplusplus
}
#endif

#endif

