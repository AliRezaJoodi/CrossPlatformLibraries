/**
 * @brief   Configuration file for Seg7 driver.
 *
 * Modify the following macros to match your hardware setup.
 * These settings control digit count and signal polarity.
 */

#ifndef SEG7_DRIVER_CONFIG_INCLUDED
#define SEG7_DRIVER_CONFIG_INCLUDED

/** @brief Include user-overridable hardware macros. */
//#include "hardware.h"

#ifndef SEG7_DRIVER_CONFIG
#define SEG7_DRIVER_CONFIG
    #define SEG7_DIGITS_COUNT       8   /* Number of multiplexed digits */
    #define SEG7_DIGITS_ACTIVATE    1   /* Digit active level: 1=Active High, 0=Active Low */
    #define SEG7_SEGMENTS_ACTIVATE  0   /* Segment active level: 1=Active High, 0=Active Low */

    #warning "SEG7_DRIVER_CONFIG is not defined; default configuration will be used."
#endif

#endif
