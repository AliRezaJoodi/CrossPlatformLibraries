#ifndef SEG7_DRIVER_PORT_INCLUDED
#define SEG7_DRIVER_PORT_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "compiler_port.h"
#include "bit_register8.h"
#include "bit_value8.h"
#include "seg7_driver_hw.h"

/**
 * @brief Configure digit control pins as output.
 *
 * Initializes only the digits defined by SEG7_DIGITS_COUNT.
 * Unused digit pins are excluded at compile time.
 */
static inline void Seg7_Digits_ConfigAsOutput(void){
    #if SEG7_DIGITS_COUNT > 0
        SetBitMask_Reg8(&SEG7_DIGIT0_DDR, SEG7_DIGIT0_MASK);
    #endif

    #if SEG7_DIGITS_COUNT > 1
        SetBitMask_Reg8(&SEG7_DIGIT1_DDR, SEG7_DIGIT1_MASK);
    #endif

    #if SEG7_DIGITS_COUNT > 2
        SetBitMask_Reg8(&SEG7_DIGIT2_DDR, SEG7_DIGIT2_MASK);
    #endif

    #if SEG7_DIGITS_COUNT > 3
        SetBitMask_Reg8(&SEG7_DIGIT3_DDR, SEG7_DIGIT3_MASK);
    #endif

    #if SEG7_DIGITS_COUNT > 4
        SetBitMask_Reg8(&SEG7_DIGIT4_DDR, SEG7_DIGIT4_MASK);
    #endif

    #if SEG7_DIGITS_COUNT > 5
        SetBitMask_Reg8(&SEG7_DIGIT5_DDR, SEG7_DIGIT5_MASK);
    #endif

    #if SEG7_DIGITS_COUNT > 6
        SetBitMask_Reg8(&SEG7_DIGIT6_DDR, SEG7_DIGIT6_MASK);
    #endif

    #if SEG7_DIGITS_COUNT > 7
        SetBitMask_Reg8(&SEG7_DIGIT7_DDR, SEG7_DIGIT7_MASK);
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
//static inline void Seg7_Digit_Write(uint8_t index, uint8_t status){
//    #if SEG7_DIGITS_COUNT > 0
//        if(index == 0){
//            WriteBit_Reg8(&SEG7_DIGIT0_PORT, SEG7_DIGIT0_BIT, status);
//        }
//    #endif
//
//    #if SEG7_DIGITS_COUNT > 1
//        else if(index == 1){
//            WriteBit_Reg8(&SEG7_DIGIT1_PORT, SEG7_DIGIT1_BIT, status);
//        }
//    #endif
//
//    #if SEG7_DIGITS_COUNT > 2
//        else if(index == 2){
//            WriteBit_Reg8(&SEG7_DIGIT2_PORT, SEG7_DIGIT2_BIT, status);
//        }
//    #endif
//
//    #if SEG7_DIGITS_COUNT > 3
//        else if(index == 3){
//            WriteBit_Reg8(&SEG7_DIGIT3_PORT, SEG7_DIGIT3_BIT, status);
//        }
//    #endif
//
//    #if SEG7_DIGITS_COUNT > 4
//        else if(index == 4){
//            WriteBit_Reg8(&SEG7_DIGIT4_PORT, SEG7_DIGIT4_BIT, status);
//        }
//    #endif
//
//    #if SEG7_DIGITS_COUNT > 5
//        else if(index == 5){
//            WriteBit_Reg8(&SEG7_DIGIT5_PORT, SEG7_DIGIT5_BIT, status);
//        }
//    #endif
//
//    #if SEG7_DIGITS_COUNT > 6
//        else if(index == 6){
//            WriteBit_Reg8(&SEG7_DIGIT6_PORT, SEG7_DIGIT6_BIT, status);
//        }
//    #endif
//
//    #if SEG7_DIGITS_COUNT > 7
//        else if(index == 7){
//            WriteBit_Reg8(&SEG7_DIGIT7_PORT, SEG7_DIGIT7_BIT, status);
//        }
//    #endif
//}

//static inline void Seg7_Digit_Write(uint8_t index, uint8_t status){
//    switch(index){
//
//    #if SEG7_DIGITS_COUNT > 0
//        case 0:
//            WriteBit_Reg8(&SEG7_DIGIT0_PORT, SEG7_DIGIT0_BIT, status);
//            break;
//    #endif
//
//    #if SEG7_DIGITS_COUNT > 1
//        case 1:
//            WriteBit_Reg8(&SEG7_DIGIT1_PORT, SEG7_DIGIT1_BIT, status);
//            break;
//    #endif
//
//    #if SEG7_DIGITS_COUNT > 2
//        case 2:
//            WriteBit_Reg8(&SEG7_DIGIT2_PORT, SEG7_DIGIT2_BIT, status);
//            break;
//    #endif
//
//    #if SEG7_DIGITS_COUNT > 3
//        case 3:
//            WriteBit_Reg8(&SEG7_DIGIT3_PORT, SEG7_DIGIT3_BIT, status);
//            break;
//    #endif
//
//    #if SEG7_DIGITS_COUNT > 4
//        case 4:
//            WriteBit_Reg8(&SEG7_DIGIT4_PORT, SEG7_DIGIT4_BIT, status);
//            break;
//    #endif
//
//    #if SEG7_DIGITS_COUNT > 5
//        case 5:
//            WriteBit_Reg8(&SEG7_DIGIT5_PORT, SEG7_DIGIT5_BIT, status);
//            break;
//    #endif
//
//    #if SEG7_DIGITS_COUNT > 6
//        case 6:
//            WriteBit_Reg8(&SEG7_DIGIT6_PORT, SEG7_DIGIT6_BIT, status);
//            break;
//    #endif
//
//    #if SEG7_DIGITS_COUNT > 7
//        case 7:
//            WriteBit_Reg8(&SEG7_DIGIT7_PORT, SEG7_DIGIT7_BIT, status);
//            break;
//    #endif
//
//        default:
//            break;
//    }
//}

/**
 * @brief Drive the selected digit control line to logic LOW.
 *
 * @param index  Digit index in the range:
 *               0 to (SEG7_DIGITS_COUNT - 1).
 */
static inline void Seg7_Digit_Clear(const uint8_t index){
    switch(index){

    #if SEG7_DIGITS_COUNT > 0
        case 0:
            ClearBitMask_Reg8(&SEG7_DIGIT0_PORT, SEG7_DIGIT0_MASK);
            break;
    #endif

    #if SEG7_DIGITS_COUNT > 1
        case 1:
            ClearBitMask_Reg8(&SEG7_DIGIT1_PORT, SEG7_DIGIT1_MASK);
            break;
    #endif

    #if SEG7_DIGITS_COUNT > 2
        case 2:
            ClearBitMask_Reg8(&SEG7_DIGIT2_PORT, SEG7_DIGIT2_MASK);
            break;
    #endif

    #if SEG7_DIGITS_COUNT > 3
        case 3:
            ClearBitMask_Reg8(&SEG7_DIGIT3_PORT, SEG7_DIGIT3_MASK);
            break;
    #endif

    #if SEG7_DIGITS_COUNT > 4
        case 4:
            ClearBitMask_Reg8(&SEG7_DIGIT4_PORT, SEG7_DIGIT4_MASK);
            break;
    #endif

    #if SEG7_DIGITS_COUNT > 5
        case 5:
            ClearBitMask_Reg8(&SEG7_DIGIT5_PORT, SEG7_DIGIT5_MASK);
            break;
    #endif

    #if SEG7_DIGITS_COUNT > 6
        case 6:
            ClearBitMask_Reg8(&SEG7_DIGIT6_PORT, SEG7_DIGIT6_MASK);
            break;
    #endif

    #if SEG7_DIGITS_COUNT > 7
        case 7:
            ClearBitMask_Reg8(&SEG7_DIGIT7_PORT, SEG7_DIGIT7_MASK);
            break;
    #endif

        default:
            break;
    }
}

/**
 * @brief Drive the selected digit control line to logic High.
 *
 * @param index  Digit index in the range:
 *               0 to (SEG7_DIGITS_COUNT - 1).
 */
static inline void Seg7_Digit_Set(const uint8_t index){
    switch(index){

    #if SEG7_DIGITS_COUNT > 0
        case 0:
            SetBitMask_Reg8(&SEG7_DIGIT0_PORT, SEG7_DIGIT0_MASK);
            break;
    #endif

    #if SEG7_DIGITS_COUNT > 1
        case 1:
            SetBitMask_Reg8(&SEG7_DIGIT1_PORT, SEG7_DIGIT1_MASK);
            break;
    #endif

    #if SEG7_DIGITS_COUNT > 2
        case 2:
            SetBitMask_Reg8(&SEG7_DIGIT2_PORT, SEG7_DIGIT2_MASK);
            break;
    #endif

    #if SEG7_DIGITS_COUNT > 3
        case 3:
            SetBitMask_Reg8(&SEG7_DIGIT3_PORT, SEG7_DIGIT3_MASK);
            break;
    #endif

    #if SEG7_DIGITS_COUNT > 4
        case 4:
            SetBitMask_Reg8(&SEG7_DIGIT4_PORT, SEG7_DIGIT4_MASK);
            break;
    #endif

    #if SEG7_DIGITS_COUNT > 5
        case 5:
            SetBitMask_Reg8(&SEG7_DIGIT5_PORT, SEG7_DIGIT5_MASK);
            break;
    #endif

    #if SEG7_DIGITS_COUNT > 6
        case 6:
            SetBitMask_Reg8(&SEG7_DIGIT6_PORT, SEG7_DIGIT6_MASK);
            break;
    #endif

    #if SEG7_DIGITS_COUNT > 7
        case 7:
            SetBitMask_Reg8(&SEG7_DIGIT7_PORT, SEG7_DIGIT7_MASK);
            break;
    #endif

        default:
            break;
    }
}


/**
 * @brief Initialize the GPIO pins for all 7-segment display segments.
 *
 * Configures the data direction registers (DDR) for all segment control pins
 * (A to G, and DP) to output mode. This allows the microcontroller to control
 * each segment individually to drive the display.
 *
 */
static inline void Seg7_Segments_ConfigAsOutput(void){
    SetBitMask_Reg8(&SEG7_A_DDR, SEG7_A_MASK);
    SetBitMask_Reg8(&SEG7_B_DDR, SEG7_B_MASK);
    SetBitMask_Reg8(&SEG7_C_DDR, SEG7_C_MASK);
    SetBitMask_Reg8(&SEG7_D_DDR, SEG7_D_MASK);
    SetBitMask_Reg8(&SEG7_E_DDR, SEG7_E_MASK);
    SetBitMask_Reg8(&SEG7_F_DDR, SEG7_F_MASK);
    SetBitMask_Reg8(&SEG7_G_DDR, SEG7_G_MASK);
    SetBitMask_Reg8(&SEG7_DP_DDR, SEG7_DP_MASK);
}

/**
 * @brief Write a byte to the 7-segment display segments.
 *
 * The value in `buf` is directly output to segment pins.
 * If SEG7_SEGMENTS_ACTIVATE is 0, the bits are inverted.
 *
 * @param buf Segment states as a byte.
 */
static inline void Seg7_Segments_Write(uint8_t buf){
    #if (SEG7_SEGMENTS_ACTIVATE == 0U)
        buf = (uint8_t)~buf;
    #endif

    WriteBit_Reg8(&SEG7_A_PORT, SEG7_A_BIT, IsBitMaskSet_u8(buf, 0x01));
    WriteBit_Reg8(&SEG7_B_PORT, SEG7_B_BIT, IsBitMaskSet_u8(buf, 0x02));
    WriteBit_Reg8(&SEG7_C_PORT, SEG7_C_BIT, IsBitMaskSet_u8(buf, 0x04));
    WriteBit_Reg8(&SEG7_D_PORT, SEG7_D_BIT, IsBitMaskSet_u8(buf, 0x08));
    WriteBit_Reg8(&SEG7_E_PORT, SEG7_E_BIT, IsBitMaskSet_u8(buf, 0x10));
    WriteBit_Reg8(&SEG7_F_PORT, SEG7_F_BIT, IsBitMaskSet_u8(buf, 0x20));
    WriteBit_Reg8(&SEG7_G_PORT, SEG7_G_BIT, IsBitMaskSet_u8(buf, 0x40));
    WriteBit_Reg8(&SEG7_DP_PORT, SEG7_DP_BIT, IsBitMaskSet_u8(buf, 0x80));
}

#ifdef __cplusplus
}
#endif

#endif
