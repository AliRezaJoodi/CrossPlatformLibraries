#ifndef SEG7_DRIVER_PORT_INCLUDED
#define SEG7_DRIVER_PORT_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "aj_compiler.h"
#include "aj_bit_reg.h"
#include "aj_bit_u8.h"
#include "aj_seg7_driver_hw.h"

/**
 * @brief Configure digit control pins as output.
 *
 * Initializes only the digits defined by AJ_SEG7_DIGITS_COUNT.
 * Unused digit pins are excluded at compile time.
 */
static inline void AJ_Seg7_Digits_ConfigAsOutput(void){
    #if AJ_SEG7_DIGITS_COUNT > 0
        AJ_BitReg_SetBit_Mask(&AJ_SEG7_DIGIT0_DDR, AJ_SEG7_DIGIT0_MASK);
    #endif

    #if AJ_SEG7_DIGITS_COUNT > 1
        AJ_BitReg_SetBit_Mask(&AJ_SEG7_DIGIT1_DDR, AJ_SEG7_DIGIT1_MASK);
    #endif

    #if AJ_SEG7_DIGITS_COUNT > 2
        AJ_BitReg_SetBit_Mask(&AJ_SEG7_DIGIT2_DDR, AJ_SEG7_DIGIT2_MASK);
    #endif

    #if AJ_SEG7_DIGITS_COUNT > 3
        AJ_BitReg_SetBit_Mask(&AJ_SEG7_DIGIT3_DDR, AJ_SEG7_DIGIT3_MASK);
    #endif

    #if AJ_SEG7_DIGITS_COUNT > 4
        AJ_BitReg_SetBit_Mask(&AJ_SEG7_DIGIT4_DDR, AJ_SEG7_DIGIT4_MASK);
    #endif

    #if AJ_SEG7_DIGITS_COUNT > 5
        AJ_BitReg_SetBit_Mask(&AJ_SEG7_DIGIT5_DDR, AJ_SEG7_DIGIT5_MASK);
    #endif

    #if AJ_SEG7_DIGITS_COUNT > 6
        AJ_BitReg_SetBit_Mask(&AJ_SEG7_DIGIT6_DDR, AJ_SEG7_DIGIT6_MASK);
    #endif

    #if AJ_SEG7_DIGITS_COUNT > 7
        AJ_BitReg_SetBit_Mask(&AJ_SEG7_DIGIT7_DDR, AJ_SEG7_DIGIT7_MASK);
    #endif
}

/**
 * @brief Activate a specific digit line.
 *
 * Sets the selected digit control pin to its active level
 * according to AJ_SEG7_DIGITS_ACTIVATE polarity.
 *
 * This function is typically used during multiplex scanning
 * after all digits have been disabled.
 *
 * @param index Digit index in range:
 *              0 to (AJ_SEG7_DIGITS_COUNT - 1).
 */
//static inline void Seg7_Digit_Write(uint8_t index, uint8_t status){
//    #if AJ_SEG7_DIGITS_COUNT > 0
//        if(index == 0){
//            WriteBit_Reg8(&AJ_SEG7_DIGIT0_PORT, AJ_SEG7_DIGIT0_POS, status);
//        }
//    #endif
//
//    #if AJ_SEG7_DIGITS_COUNT > 1
//        else if(index == 1){
//            WriteBit_Reg8(&AJ_SEG7_DIGIT1_PORT, AJ_SEG7_DIGIT1_POS, status);
//        }
//    #endif
//
//    #if AJ_SEG7_DIGITS_COUNT > 2
//        else if(index == 2){
//            WriteBit_Reg8(&AJ_SEG7_DIGIT2_PORT, AJ_SEG7_DIGIT2_POS, status);
//        }
//    #endif
//
//    #if AJ_SEG7_DIGITS_COUNT > 3
//        else if(index == 3){
//            WriteBit_Reg8(&AJ_SEG7_DIGIT3_PORT, AJ_SEG7_DIGIT3_POS, status);
//        }
//    #endif
//
//    #if AJ_SEG7_DIGITS_COUNT > 4
//        else if(index == 4){
//            WriteBit_Reg8(&AJ_SEG7_DIGIT4_PORT, AJ_SEG7_DIGIT4_POS, status);
//        }
//    #endif
//
//    #if AJ_SEG7_DIGITS_COUNT > 5
//        else if(index == 5){
//            WriteBit_Reg8(&AJ_SEG7_DIGIT5_PORT, AJ_SEG7_DIGIT5_POS, status);
//        }
//    #endif
//
//    #if AJ_SEG7_DIGITS_COUNT > 6
//        else if(index == 6){
//            WriteBit_Reg8(&AJ_SEG7_DIGIT6_PORT, AJ_SEG7_DIGIT6_POS, status);
//        }
//    #endif
//
//    #if AJ_SEG7_DIGITS_COUNT > 7
//        else if(index == 7){
//            WriteBit_Reg8(&AJ_SEG7_DIGIT7_PORT, AJ_SEG7_DIGIT7_POS, status);
//        }
//    #endif
//}

//static inline void Seg7_Digit_Write(uint8_t index, uint8_t status){
//    switch(index){
//
//    #if AJ_SEG7_DIGITS_COUNT > 0
//        case 0:
//            WriteBit_Reg8(&AJ_SEG7_DIGIT0_PORT, AJ_SEG7_DIGIT0_POS, status);
//            break;
//    #endif
//
//    #if AJ_SEG7_DIGITS_COUNT > 1
//        case 1:
//            WriteBit_Reg8(&AJ_SEG7_DIGIT1_PORT, AJ_SEG7_DIGIT1_POS, status);
//            break;
//    #endif
//
//    #if AJ_SEG7_DIGITS_COUNT > 2
//        case 2:
//            WriteBit_Reg8(&AJ_SEG7_DIGIT2_PORT, AJ_SEG7_DIGIT2_POS, status);
//            break;
//    #endif
//
//    #if AJ_SEG7_DIGITS_COUNT > 3
//        case 3:
//            WriteBit_Reg8(&AJ_SEG7_DIGIT3_PORT, AJ_SEG7_DIGIT3_POS, status);
//            break;
//    #endif
//
//    #if AJ_SEG7_DIGITS_COUNT > 4
//        case 4:
//            WriteBit_Reg8(&AJ_SEG7_DIGIT4_PORT, AJ_SEG7_DIGIT4_POS, status);
//            break;
//    #endif
//
//    #if AJ_SEG7_DIGITS_COUNT > 5
//        case 5:
//            WriteBit_Reg8(&AJ_SEG7_DIGIT5_PORT, AJ_SEG7_DIGIT5_POS, status);
//            break;
//    #endif
//
//    #if AJ_SEG7_DIGITS_COUNT > 6
//        case 6:
//            WriteBit_Reg8(&AJ_SEG7_DIGIT6_PORT, AJ_SEG7_DIGIT6_POS, status);
//            break;
//    #endif
//
//    #if AJ_SEG7_DIGITS_COUNT > 7
//        case 7:
//            WriteBit_Reg8(&AJ_SEG7_DIGIT7_PORT, AJ_SEG7_DIGIT7_POS, status);
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
 *               0 to (AJ_SEG7_DIGITS_COUNT - 1).
 */
static inline void AJ_Seg7_Digit_Clear(const uint8_t index){
    switch(index){

    #if AJ_SEG7_DIGITS_COUNT > 0
        case 0:
            AJ_BitReg_ClearBit_Mask(&AJ_SEG7_DIGIT0_PORT, AJ_SEG7_DIGIT0_MASK);
            break;
    #endif

    #if AJ_SEG7_DIGITS_COUNT > 1
        case 1:
            AJ_BitReg_ClearBit_Mask(&AJ_SEG7_DIGIT1_PORT, AJ_SEG7_DIGIT1_MASK);
            break;
    #endif

    #if AJ_SEG7_DIGITS_COUNT > 2
        case 2:
            AJ_BitReg_ClearBit_Mask(&AJ_SEG7_DIGIT2_PORT, AJ_SEG7_DIGIT2_MASK);
            break;
    #endif

    #if AJ_SEG7_DIGITS_COUNT > 3
        case 3:
            AJ_BitReg_ClearBit_Mask(&AJ_SEG7_DIGIT3_PORT, AJ_SEG7_DIGIT3_MASK);
            break;
    #endif

    #if AJ_SEG7_DIGITS_COUNT > 4
        case 4:
            AJ_BitReg_ClearBit_Mask(&AJ_SEG7_DIGIT4_PORT, AJ_SEG7_DIGIT4_MASK);
            break;
    #endif

    #if AJ_SEG7_DIGITS_COUNT > 5
        case 5:
            AJ_BitReg_ClearBit_Mask(&AJ_SEG7_DIGIT5_PORT, AJ_SEG7_DIGIT5_MASK);
            break;
    #endif

    #if AJ_SEG7_DIGITS_COUNT > 6
        case 6:
            AJ_BitReg_ClearBit_Mask(&AJ_SEG7_DIGIT6_PORT, AJ_SEG7_DIGIT6_MASK);
            break;
    #endif

    #if AJ_SEG7_DIGITS_COUNT > 7
        case 7:
            AJ_BitReg_ClearBit_Mask(&AJ_SEG7_DIGIT7_PORT, AJ_SEG7_DIGIT7_MASK);
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
 *               0 to (AJ_SEG7_DIGITS_COUNT - 1).
 */
static inline void AJ_Seg7_Digit_Set(const uint8_t index){
    switch(index){

    #if AJ_SEG7_DIGITS_COUNT > 0
        case 0:
            AJ_BitReg_SetBit_Mask(&AJ_SEG7_DIGIT0_PORT, AJ_SEG7_DIGIT0_MASK);
            break;
    #endif

    #if AJ_SEG7_DIGITS_COUNT > 1
        case 1:
            AJ_BitReg_SetBit_Mask(&AJ_SEG7_DIGIT1_PORT, AJ_SEG7_DIGIT1_MASK);
            break;
    #endif

    #if AJ_SEG7_DIGITS_COUNT > 2
        case 2:
            AJ_BitReg_SetBit_Mask(&AJ_SEG7_DIGIT2_PORT, AJ_SEG7_DIGIT2_MASK);
            break;
    #endif

    #if AJ_SEG7_DIGITS_COUNT > 3
        case 3:
            AJ_BitReg_SetBit_Mask(&AJ_SEG7_DIGIT3_PORT, AJ_SEG7_DIGIT3_MASK);
            break;
    #endif

    #if AJ_SEG7_DIGITS_COUNT > 4
        case 4:
            AJ_BitReg_SetBit_Mask(&AJ_SEG7_DIGIT4_PORT, AJ_SEG7_DIGIT4_MASK);
            break;
    #endif

    #if AJ_SEG7_DIGITS_COUNT > 5
        case 5:
            AJ_BitReg_SetBit_Mask(&AJ_SEG7_DIGIT5_PORT, AJ_SEG7_DIGIT5_MASK);
            break;
    #endif

    #if AJ_SEG7_DIGITS_COUNT > 6
        case 6:
            AJ_BitReg_SetBit_Mask(&AJ_SEG7_DIGIT6_PORT, AJ_SEG7_DIGIT6_MASK);
            break;
    #endif

    #if AJ_SEG7_DIGITS_COUNT > 7
        case 7:
            AJ_BitReg_SetBit_Mask(&AJ_SEG7_DIGIT7_PORT, AJ_SEG7_DIGIT7_MASK);
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
static inline void AJ_Seg7_Segments_ConfigAsOutput(void){
    AJ_BitReg_SetBit_Mask(&AJ_SEG7_A_DDR, AJ_SEG7_A_MASK);
    AJ_BitReg_SetBit_Mask(&AJ_SEG7_B_DDR, AJ_SEG7_B_MASK);
    AJ_BitReg_SetBit_Mask(&AJ_SEG7_C_DDR, AJ_SEG7_C_MASK);
    AJ_BitReg_SetBit_Mask(&AJ_SEG7_D_DDR, AJ_SEG7_D_MASK);
    AJ_BitReg_SetBit_Mask(&AJ_SEG7_E_DDR, AJ_SEG7_E_MASK);
    AJ_BitReg_SetBit_Mask(&AJ_SEG7_F_DDR, AJ_SEG7_F_MASK);
    AJ_BitReg_SetBit_Mask(&AJ_SEG7_G_DDR, AJ_SEG7_G_MASK);
    AJ_BitReg_SetBit_Mask(&AJ_SEG7_DP_DDR, AJ_SEG7_DP_MASK);
}

/**
 * @brief Write a byte to the 7-segment display segments.
 *
 * The value in `buf` is directly output to segment pins.
 * If AJ_SEG7_SEGMENTS_ACTIVATE is 0, the bits are inverted.
 *
 * @param buf Segment states as a byte.
 */
static inline void AJ_Seg7_Segments_Write(uint8_t buf){
    #if (AJ_SEG7_SEGMENTS_ACTIVATE == 0U)
        buf = (uint8_t)~buf;
    #endif

    AJ_BitReg_WriteBit_Position(&AJ_SEG7_A_PORT, AJ_SEG7_A_POS, AJ_BitU8_IsBitSet_Mask(buf, 0x01));
    AJ_BitReg_WriteBit_Position(&AJ_SEG7_B_PORT, AJ_SEG7_B_POS, AJ_BitU8_IsBitSet_Mask(buf, 0x02));
    AJ_BitReg_WriteBit_Position(&AJ_SEG7_C_PORT, AJ_SEG7_C_POS, AJ_BitU8_IsBitSet_Mask(buf, 0x04));
    AJ_BitReg_WriteBit_Position(&AJ_SEG7_D_PORT, AJ_SEG7_D_POS, AJ_BitU8_IsBitSet_Mask(buf, 0x08));
    AJ_BitReg_WriteBit_Position(&AJ_SEG7_E_PORT, AJ_SEG7_E_POS, AJ_BitU8_IsBitSet_Mask(buf, 0x10));
    AJ_BitReg_WriteBit_Position(&AJ_SEG7_F_PORT, AJ_SEG7_F_POS, AJ_BitU8_IsBitSet_Mask(buf, 0x20));
    AJ_BitReg_WriteBit_Position(&AJ_SEG7_G_PORT, AJ_SEG7_G_POS, AJ_BitU8_IsBitSet_Mask(buf, 0x40));
    AJ_BitReg_WriteBit_Position(&AJ_SEG7_DP_PORT, AJ_SEG7_DP_POS, AJ_BitU8_IsBitSet_Mask(buf, 0x80));
}

#ifdef __cplusplus
}
#endif

#endif
