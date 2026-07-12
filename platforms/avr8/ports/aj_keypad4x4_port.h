#ifndef AJ_KEYPAD4X4_PORT_INCLUDED
#define AJ_KEYPAD4X4_PORT_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "aj_compiler.h"
#include "aj_bit_reg.h"
#include "aj_keypad4x4_config_platform.h"

/******************************************************************************/
/* Rows                                                                       */
/******************************************************************************/
/* R1 */
static inline void AJ_Keypad4x4_R1_ConfigAsInput(void){
    AJ_BitReg_ClearBit_Mask(&AJ_KEYPAD4X4_R1_DDR, AJ_KEYPAD4X4_R1_MASK);
}

static inline void AJ_Keypad4x4_R1_ConfigAsPullUp(void){
    AJ_BitReg_SetBit_Mask(&AJ_KEYPAD4X4_R1_PORT, AJ_KEYPAD4X4_R1_MASK);
}

static inline uint8_t AJ_Keypad4x4_R1_Read(void){
    return AJ_BitReg_IsBitSet_Mask(&AJ_KEYPAD4X4_R1_PIN, AJ_KEYPAD4X4_R1_MASK);
}

static inline void AJ_Keypad4x4_R1_ConfigAsOutput(void){
    AJ_BitReg_SetBit_Mask(&AJ_KEYPAD4X4_R1_DDR, AJ_KEYPAD4X4_R1_MASK);
}

static inline void AJ_Keypad4x4_R1_Clear(void){
    AJ_BitReg_ClearBit_Mask(&AJ_KEYPAD4X4_R1_PORT, AJ_KEYPAD4X4_R1_MASK);
}

static inline void AJ_Keypad4x4_R1_Set(void){
    AJ_BitReg_SetBit_Mask(&AJ_KEYPAD4X4_R1_PORT, AJ_KEYPAD4X4_R1_MASK);
}


/* R2 */
static inline void AJ_Keypad4X4_R2_ConfigAsInput(void){
    AJ_BitReg_ClearBit_Mask(&AJ_KEYPAD4X4_R2_DDR, AJ_KEYPAD4X4_R2_MASK);
}

static inline void AJ_Keypad4X4_R2_ConfigAsPullUp(void){
    AJ_BitReg_SetBit_Mask(&AJ_KEYPAD4X4_R2_PORT, AJ_KEYPAD4X4_R2_MASK);
}

static inline uint8_t AJ_Keypad4X4_R2_Read(void){
    return AJ_BitReg_IsBitSet_Mask(&AJ_KEYPAD4X4_R2_PIN, AJ_KEYPAD4X4_R2_MASK);
}

static inline void AJ_Keypad4X4_R2_ConfigAsOutput(void){
    AJ_BitReg_SetBit_Mask(&AJ_KEYPAD4X4_R2_DDR, AJ_KEYPAD4X4_R2_MASK);
}

static inline void AJ_Keypad4X4_R2_Clear(void){
    AJ_BitReg_ClearBit_Mask(&AJ_KEYPAD4X4_R2_PORT, AJ_KEYPAD4X4_R2_MASK);
}

static inline void AJ_Keypad4X4_R2_Set(void){
    AJ_BitReg_SetBit_Mask(&AJ_KEYPAD4X4_R2_PORT, AJ_KEYPAD4X4_R2_MASK);
}


/* R3 */
static inline void AJ_Keypad4X4_R3_ConfigAsInput(void){
    AJ_BitReg_ClearBit_Mask(&AJ_KEYPAD4X4_R3_DDR, AJ_KEYPAD4X4_R3_MASK);
}

static inline void AJ_Keypad4X4_R3_ConfigAsPullUp(void){
    AJ_BitReg_SetBit_Mask(&AJ_KEYPAD4X4_R3_PORT, AJ_KEYPAD4X4_R3_MASK);
}

static inline uint8_t AJ_Keypad4X4_R3_Read(void){
    return AJ_BitReg_IsBitSet_Mask(&AJ_KEYPAD4X4_R3_PIN, AJ_KEYPAD4X4_R3_MASK);
}

static inline void AJ_Keypad4X4_R3_ConfigAsOutput(void){
    AJ_BitReg_SetBit_Mask(&AJ_KEYPAD4X4_R3_DDR, AJ_KEYPAD4X4_R3_MASK);
}

static inline void AJ_Keypad4X4_R3_Clear(void){
    AJ_BitReg_ClearBit_Mask(&AJ_KEYPAD4X4_R3_PORT, AJ_KEYPAD4X4_R3_MASK);
}

static inline void AJ_Keypad4X4_R3_Set(void){
    AJ_BitReg_SetBit_Mask(&AJ_KEYPAD4X4_R3_PORT, AJ_KEYPAD4X4_R3_MASK);
}


/* R4 */
static inline void AJ_Keypad4x4_R4_ConfigAsInput(void){
    AJ_BitReg_ClearBit_Mask(&AJ_KEYPAD4X4_R4_DDR, AJ_KEYPAD4X4_R4_MASK);
}

static inline void AJ_Keypad4x4_R4_ConfigAsPullUp(void){
    AJ_BitReg_SetBit_Mask(&AJ_KEYPAD4X4_R4_PORT, AJ_KEYPAD4X4_R4_MASK);
}

static inline uint8_t AJ_Keypad4x4_R4_Read(void){
    return AJ_BitReg_IsBitSet_Mask(&AJ_KEYPAD4X4_R4_PIN, AJ_KEYPAD4X4_R4_MASK);
}

static inline void AJ_Keypad4x4_R4_ConfigAsOutput(void){
    AJ_BitReg_SetBit_Mask(&AJ_KEYPAD4X4_R4_DDR, AJ_KEYPAD4X4_R4_MASK);
}

static inline void AJ_Keypad4x4_R4_Clear(void){
    AJ_BitReg_ClearBit_Mask(&AJ_KEYPAD4X4_R4_PORT, AJ_KEYPAD4X4_R4_MASK);
}

static inline void AJ_Keypad4x4_R4_Set(void){
    AJ_BitReg_SetBit_Mask(&AJ_KEYPAD4X4_R4_PORT, AJ_KEYPAD4X4_R4_MASK);
}


/******************************************************************************/
/* Columns                                                                    */
/******************************************************************************/
/* C1 */
static inline void AJ_Keypad4x4_C1_ConfigAsInput(void){
    AJ_BitReg_ClearBit_Mask(&AJ_KEYPAD4X4_C1_DDR, AJ_KEYPAD4X4_C1_MASK);
}

static inline void AJ_Keypad4x4_C1_ConfigAsPullUp(void){
    AJ_BitReg_SetBit_Mask(&AJ_KEYPAD4X4_C1_PORT, AJ_KEYPAD4X4_C1_MASK);
}

static inline uint8_t AJ_Keypad4x4_C1_Read(void){
    return AJ_BitReg_IsBitSet_Mask(&AJ_KEYPAD4X4_C1_PIN, AJ_KEYPAD4X4_C1_MASK);
}

static inline void AJ_Keypad4x4_C1_ConfigAsOutput(void){
    AJ_BitReg_SetBit_Mask(&AJ_KEYPAD4X4_C1_DDR, AJ_KEYPAD4X4_C1_MASK);
}

static inline void AJ_Keypad4x4_C1_Clear(void){
    AJ_BitReg_ClearBit_Mask(&AJ_KEYPAD4X4_C1_PORT, AJ_KEYPAD4X4_C1_MASK);
}

static inline void AJ_Keypad4x4_C1_Set(void){
    AJ_BitReg_SetBit_Mask(&AJ_KEYPAD4X4_C1_PORT, AJ_KEYPAD4X4_C1_MASK);
}


/* C2 */
static inline void AJ_Keypad4x4_C2_ConfigAsInput(void){
    AJ_BitReg_ClearBit_Mask(&AJ_KEYPAD4X4_C2_DDR, AJ_KEYPAD4X4_C2_MASK);
}

static inline void AJ_Keypad4x4_C2_ConfigAsPullUp(void){
    AJ_BitReg_SetBit_Mask(&AJ_KEYPAD4X4_C2_PORT, AJ_KEYPAD4X4_C2_MASK);
}

static inline uint8_t AJ_Keypad4x4_C2_Read(void){
    return AJ_BitReg_IsBitSet_Mask(&AJ_KEYPAD4X4_C2_PIN, AJ_KEYPAD4X4_C2_MASK);
}

static inline void AJ_Keypad4x4_C2_ConfigAsOutput(void){
    AJ_BitReg_SetBit_Mask(&AJ_KEYPAD4X4_C2_DDR, AJ_KEYPAD4X4_C2_MASK);
}

static inline void AJ_Keypad4x4_C2_Clear(void){
    AJ_BitReg_ClearBit_Mask(&AJ_KEYPAD4X4_C2_PORT, AJ_KEYPAD4X4_C2_MASK);
}

static inline void AJ_Keypad4x4_C2_Set(void){
    AJ_BitReg_SetBit_Mask(&AJ_KEYPAD4X4_C2_PORT, AJ_KEYPAD4X4_C2_MASK);
}


/* C3 */
static inline void AJ_Keypad4x4_C3_ConfigAsInput(void){
    AJ_BitReg_ClearBit_Mask(&AJ_KEYPAD4X4_C3_DDR, AJ_KEYPAD4X4_C3_MASK);
}

static inline void AJ_Keypad4x4_C3_ConfigAsPullUp(void){
    AJ_BitReg_SetBit_Mask(&AJ_KEYPAD4X4_C3_PORT, AJ_KEYPAD4X4_C3_MASK);
}

static inline uint8_t AJ_Keypad4x4_C3_Read(void){
    return AJ_BitReg_IsBitSet_Mask(&AJ_KEYPAD4X4_C3_PIN, AJ_KEYPAD4X4_C3_MASK);
}

static inline void AJ_Keypad4x4_C3_ConfigAsOutput(void){
    AJ_BitReg_SetBit_Mask(&AJ_KEYPAD4X4_C3_DDR, AJ_KEYPAD4X4_C3_MASK);
}

static inline void AJ_Keypad4x4_C3_Clear(void){
    AJ_BitReg_ClearBit_Mask(&AJ_KEYPAD4X4_C3_PORT, AJ_KEYPAD4X4_C3_MASK);
}

static inline void AJ_Keypad4x4_C3_Set(void){
    AJ_BitReg_SetBit_Mask(&AJ_KEYPAD4X4_C3_PORT, AJ_KEYPAD4X4_C3_MASK);
}


/* C4 */
static inline void AJ_Keypad4x4_C4_ConfigAsInput(void){
    AJ_BitReg_ClearBit_Mask(&AJ_KEYPAD4X4_C4_DDR, AJ_KEYPAD4X4_C4_MASK);
}

static inline void AJ_Keypad4x4_C4_ConfigAsPullUp(void){
    AJ_BitReg_SetBit_Mask(&AJ_KEYPAD4X4_C4_PORT, AJ_KEYPAD4X4_C4_MASK);
}

static inline uint8_t AJ_Keypad4x4_C4_Read(void){
    return AJ_BitReg_IsBitSet_Mask(&AJ_KEYPAD4X4_C4_PIN, AJ_KEYPAD4X4_C4_MASK);
}

static inline void AJ_Keypad4x4_C4_ConfigAsOutput(void){
    AJ_BitReg_SetBit_Mask(&AJ_KEYPAD4X4_C4_DDR, AJ_KEYPAD4X4_C4_MASK);
}

static inline void AJ_Keypad4x4_C4_Clear(void){
    AJ_BitReg_ClearBit_Mask(&AJ_KEYPAD4X4_C4_PORT, AJ_KEYPAD4X4_C4_MASK);
}

static inline void AJ_Keypad4x4_C4_Set(void){
    AJ_BitReg_SetBit_Mask(&AJ_KEYPAD4X4_C4_PORT, AJ_KEYPAD4X4_C4_POS);
}

#ifdef __cplusplus
}
#endif

#endif
