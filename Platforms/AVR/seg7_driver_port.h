#ifndef SEG7_DRIVER_PORT_INCLUDED
#define SEG7_DRIVER_PORT_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "utility_bit.h"
#include "seg7_driver_config.h"
#include "seg7_driver_hw.h"

/**
 * @brief Configure digit control pins as output.
 *
 * Initializes only the digits defined by SEG7_DIGITS_COUNT.
 * Unused digit pins are excluded at compile time.
 */
static inline void Seg7_InitDigits(void){
    #if SEG7_DIGITS_COUNT > 0
        SET_BIT(SEG7_DIGIT0_DDR, SEG7_DIGIT0_BIT);
    #endif

    #if SEG7_DIGITS_COUNT > 1
        SET_BIT(SEG7_DIGIT1_DDR, SEG7_DIGIT1_BIT);
    #endif

    #if SEG7_DIGITS_COUNT > 2
        SET_BIT(SEG7_DIGIT2_DDR, SEG7_DIGIT2_BIT);
    #endif

    #if SEG7_DIGITS_COUNT > 3
        SET_BIT(SEG7_DIGIT3_DDR, SEG7_DIGIT3_BIT);
    #endif

    #if SEG7_DIGITS_COUNT > 4
        SET_BIT(SEG7_DIGIT4_DDR, SEG7_DIGIT4_BIT);
    #endif

    #if SEG7_DIGITS_COUNT > 5
        SET_BIT(SEG7_DIGIT5_DDR, SEG7_DIGIT5_BIT);
    #endif

    #if SEG7_DIGITS_COUNT > 6
        SET_BIT(SEG7_DIGIT6_DDR, SEG7_DIGIT6_BIT);
    #endif

    #if SEG7_DIGITS_COUNT > 7
        SET_BIT(SEG7_DIGIT7_DDR, SEG7_DIGIT7_BIT);
    #endif
}

/**
 * @brief Deactivate all digit control lines.
 *
 * Forces all configured digits to their inactive state
 * according to SEG7_DIGITS_ACTIVATE polarity.
 *
 * The number of affected pins depends on SEG7_DIGITS_COUNT
 * and is resolved at compile time.
 */
static inline void Seg7_DisableAllDigits(void){
    #if SEG7_DIGITS_COUNT > 0
        WRITE_BIT(SEG7_DIGIT0_PORT, SEG7_DIGIT0_BIT, !SEG7_DIGITS_ACTIVATE);
    #endif

    #if SEG7_DIGITS_COUNT > 1
        WRITE_BIT(SEG7_DIGIT1_PORT, SEG7_DIGIT1_BIT, !SEG7_DIGITS_ACTIVATE);
    #endif

    #if SEG7_DIGITS_COUNT > 2
        WRITE_BIT(SEG7_DIGIT2_PORT, SEG7_DIGIT2_BIT, !SEG7_DIGITS_ACTIVATE);
    #endif

    #if SEG7_DIGITS_COUNT > 3
        WRITE_BIT(SEG7_DIGIT3_PORT, SEG7_DIGIT3_BIT, !SEG7_DIGITS_ACTIVATE);
    #endif

    #if SEG7_DIGITS_COUNT > 4
        WRITE_BIT(SEG7_DIGIT4_PORT, SEG7_DIGIT4_BIT, !SEG7_DIGITS_ACTIVATE);
    #endif

    #if SEG7_DIGITS_COUNT > 5
        WRITE_BIT(SEG7_DIGIT5_PORT, SEG7_DIGIT5_BIT, !SEG7_DIGITS_ACTIVATE);
    #endif

    #if SEG7_DIGITS_COUNT > 6
        WRITE_BIT(SEG7_DIGIT6_PORT, SEG7_DIGIT6_BIT, !SEG7_DIGITS_ACTIVATE);
    #endif

    #if SEG7_DIGITS_COUNT > 7
        WRITE_BIT(SEG7_DIGIT7_PORT, SEG7_DIGIT7_BIT, !SEG7_DIGITS_ACTIVATE);
    #endif
}

/**
 * @brief Activate a specific digit line.
 *
 * Sets the selected digit control pin to its active level
 * according to SEG7_DIGITS_ACTIVATE polarity.
 *
 * This function is typically used during multiplex scanning
 * after all digits have been disabled.
 *
 * @param index Digit index in range:
 *              0 to (SEG7_DIGITS_COUNT - 1).
 */
static inline void Seg7_EnableDigit(uint8_t index){
    #if SEG7_DIGITS_COUNT > 0
        if(index == 0){
            WRITE_BIT(SEG7_DIGIT0_PORT, SEG7_DIGIT0_BIT, SEG7_DIGITS_ACTIVATE);
        }
    #endif

    #if SEG7_DIGITS_COUNT > 1
        if(index == 1){
            WRITE_BIT(SEG7_DIGIT1_PORT, SEG7_DIGIT1_BIT, SEG7_DIGITS_ACTIVATE);
        }
    #endif

    #if SEG7_DIGITS_COUNT > 2
        if(index == 2){
            WRITE_BIT(SEG7_DIGIT2_PORT, SEG7_DIGIT2_BIT, SEG7_DIGITS_ACTIVATE);
        }
    #endif

    #if SEG7_DIGITS_COUNT > 3
        if(index == 3){
            WRITE_BIT(SEG7_DIGIT3_PORT, SEG7_DIGIT3_BIT, SEG7_DIGITS_ACTIVATE);
        }
    #endif

    #if SEG7_DIGITS_COUNT > 4
        if(index == 4){
            WRITE_BIT(SEG7_DIGIT4_PORT, SEG7_DIGIT4_BIT, SEG7_DIGITS_ACTIVATE);
        }
    #endif

    #if SEG7_DIGITS_COUNT > 5
        if(index == 5){
            WRITE_BIT(SEG7_DIGIT5_PORT, SEG7_DIGIT5_BIT, SEG7_DIGITS_ACTIVATE);
        }
    #endif

    #if SEG7_DIGITS_COUNT > 6
        if(index == 6){
            WRITE_BIT(SEG7_DIGIT6_PORT, SEG7_DIGIT6_BIT, SEG7_DIGITS_ACTIVATE);
        }
    #endif

    #if SEG7_DIGITS_COUNT > 7
        if(index == 7){
            WRITE_BIT(SEG7_DIGIT7_PORT, SEG7_DIGIT7_BIT, SEG7_DIGITS_ACTIVATE);
        }
    #endif
}

/**
 * @brief Initialize the GPIO pins for all 7-segment display segments.
 *
 * Configures the data direction registers (DDR) for all segment control pins
 * (A to G, and DP) to output mode. This allows the microcontroller to control
 * each segment individually to drive the display.
 *
 */
static inline void Seg7_InitSegments(void){
    SET_BIT(SEG7_A_DDR, SEG7_A_BIT);
    SET_BIT(SEG7_B_DDR, SEG7_B_BIT);
    SET_BIT(SEG7_C_DDR, SEG7_C_BIT);
    SET_BIT(SEG7_D_DDR, SEG7_D_BIT);
    SET_BIT(SEG7_E_DDR, SEG7_E_BIT);
    SET_BIT(SEG7_F_DDR, SEG7_F_BIT);
    SET_BIT(SEG7_G_DDR, SEG7_G_BIT);
    SET_BIT(SEG7_DP_DDR, SEG7_DP_BIT);
}

/**
 * @brief Write a byte to the 7-segment display segments.
 *
 * The value in `buf` is directly output to segment pins.
 * If SEG7_SEGMENTS_ACTIVATE is 0, the bits are inverted.
 *
 * @param buf Segment states as a byte.
 */
static inline void Seg7_WriteSegments(uint8_t buf){
    if(SEG7_SEGMENTS_ACTIVATE == 0){buf = ~buf;}

    WRITE_BIT(SEG7_A_PORT, SEG7_A_BIT, GET_BIT(buf, 0));
    WRITE_BIT(SEG7_B_PORT, SEG7_B_BIT, GET_BIT(buf, 1));
    WRITE_BIT(SEG7_C_PORT, SEG7_C_BIT, GET_BIT(buf, 2));
    WRITE_BIT(SEG7_D_PORT, SEG7_D_BIT, GET_BIT(buf, 3));
    WRITE_BIT(SEG7_E_PORT, SEG7_E_BIT, GET_BIT(buf, 4));
    WRITE_BIT(SEG7_F_PORT, SEG7_F_BIT, GET_BIT(buf, 5));
    WRITE_BIT(SEG7_G_PORT, SEG7_G_BIT, GET_BIT(buf, 6));
    WRITE_BIT(SEG7_DP_PORT, SEG7_DP_BIT, GET_BIT(buf, 7));
}

#ifdef __cplusplus
}
#endif

#endif
