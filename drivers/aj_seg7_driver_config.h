#ifndef AJ_SEG7_DRIVER_CONFIG_INCLUDED
#define AJ_SEG7_DRIVER_CONFIG_INCLUDED


#include "hardware.h"			    /* Project-level overrides */

#ifndef AJ_SEG7_DRIVER_CONFIG
#define AJ_SEG7_DRIVER_CONFIG
    #define AJ_SEG7_DIGITS_COUNT       8U   /**< Number of multiplexed digits */
    #define AJ_SEG7_DIGITS_ACTIVATE    1U   /**< Digit active level: 1=Active High, 0=Active Low */
    #define AJ_SEG7_SEGMENTS_ACTIVATE  0U   /**< Segment active level: 1=Active High, 0=Active Low */
#endif

/******************************************************************************/
/* Compile-time configuration validation and normalization                    */
/******************************************************************************/
#if ((AJ_SEG7_DIGITS_ACTIVATE != 0U) && (AJ_SEG7_DIGITS_ACTIVATE != 1U))
    #error "AJ_SEG7_DIGITS_ACTIVATE must be 0U or 1U."
#endif

#if ((AJ_SEG7_SEGMENTS_ACTIVATE != 0U) && (AJ_SEG7_SEGMENTS_ACTIVATE != 1U))
    #error "AJ_SEG7_SEGMENTS_ACTIVATE must be 0U or 1U."
#endif


#endif
