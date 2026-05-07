#ifndef KEYPAD4X4_PORT_INCLUDED
#define KEYPAD4X4_PORT_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "compiler_port.h"
#include "utils/bit_register.h"
#include "keypad4x4_hw.h"

/* Rows ----------------------------------------------------- */

/* R1 */
static inline void Keypad4x4_R1_ConfigInput(void){
    ClearBitMask_Reg8(&KEYPAD4X4_R1_DDR, KEYPAD4X4_R1_MASK);
}

static inline void Keypad4x4_R1_ConfigPullUp(void){
    SetBitMask_Reg8(&KEYPAD4X4_R1_PORT, KEYPAD4X4_R1_MASK);
}

static inline uint8_t Keypad4x4_R1_Read(void){
    return ReadBitMask_Reg8(&KEYPAD4X4_R1_PIN, KEYPAD4X4_R1_MASK);
}

static inline void Keypad4x4_R1_ConfigOutput(void){
    SetBitMask_Reg8(&KEYPAD4X4_R1_DDR, KEYPAD4X4_R1_MASK);
}

static inline void Keypad4x4_R1_Clear(void){
    ClearBitMask_Reg8(&KEYPAD4X4_R1_PORT, KEYPAD4X4_R1_MASK);
}

static inline void Keypad4x4_R1_Set(void){
    SetBitMask_Reg8(&KEYPAD4X4_R1_PORT, KEYPAD4X4_R1_MASK);
}


/* R2 */
static inline void Keypad4x4_R2_ConfigInput(void){
    ClearBitMask_Reg8(&KEYPAD4X4_R2_DDR, KEYPAD4X4_R2_MASK);
}

static inline void Keypad4x4_R2_ConfigPullUp(void){
    SetBitMask_Reg8(&KEYPAD4X4_R2_PORT, KEYPAD4X4_R2_MASK);
}

static inline uint8_t Keypad4x4_R2_Read(void){
    return ReadBitMask_Reg8(&KEYPAD4X4_R2_PIN, KEYPAD4X4_R2_MASK);
}

static inline void Keypad4x4_R2_ConfigOutput(void){
    SetBitMask_Reg8(&KEYPAD4X4_R2_DDR, KEYPAD4X4_R2_MASK);
}

static inline void Keypad4x4_R2_Clear(void){
    ClearBitMask_Reg8(&KEYPAD4X4_R2_PORT, KEYPAD4X4_R2_MASK);
}

static inline void Keypad4x4_R2_Set(void){
    SetBitMask_Reg8(&KEYPAD4X4_R2_PORT, KEYPAD4X4_R2_MASK);
}


/* R3 */
static inline void Keypad4x4_R3_ConfigInput(void){
    ClearBitMask_Reg8(&KEYPAD4X4_R3_DDR, KEYPAD4X4_R3_MASK);
}

static inline void Keypad4x4_R3_ConfigPullUp(void){
    SetBitMask_Reg8(&KEYPAD4X4_R3_PORT, KEYPAD4X4_R3_MASK);
}

static inline uint8_t Keypad4x4_R3_Read(void){
    return ReadBitMask_Reg8(&KEYPAD4X4_R3_PIN, KEYPAD4X4_R3_MASK);
}

static inline void Keypad4x4_R3_ConfigOutput(void){
    SetBitMask_Reg8(&KEYPAD4X4_R3_DDR, KEYPAD4X4_R3_MASK);
}

static inline void Keypad4x4_R3_Clear(void){
    ClearBitMask_Reg8(&KEYPAD4X4_R3_PORT, KEYPAD4X4_R3_MASK);
}

static inline void Keypad4x4_R3_Set(void){
    SetBitMask_Reg8(&KEYPAD4X4_R3_PORT, KEYPAD4X4_R3_MASK);
}


/* R4 */
static inline void Keypad4x4_R4_ConfigInput(void){
    ClearBitMask_Reg8(&KEYPAD4X4_R4_DDR, KEYPAD4X4_R4_MASK);
}

static inline void Keypad4x4_R4_ConfigPullUp(void){
    SetBitMask_Reg8(&KEYPAD4X4_R4_PORT, KEYPAD4X4_R4_MASK);
}

static inline uint8_t Keypad4x4_R4_Read(void){
    return ReadBitMask_Reg8(&KEYPAD4X4_R4_PIN, KEYPAD4X4_R4_MASK);
}

static inline void Keypad4x4_R4_ConfigOutput(void){
    SetBitMask_Reg8(&KEYPAD4X4_R4_DDR, KEYPAD4X4_R4_MASK);
}

static inline void Keypad4x4_R4_Clear(void){
    ClearBitMask_Reg8(&KEYPAD4X4_R4_PORT, KEYPAD4X4_R4_MASK);
}

static inline void Keypad4x4_R4_Set(void){
    SetBitMask_Reg8(&KEYPAD4X4_R4_PORT, KEYPAD4X4_R4_MASK);
}


/* Columns ----------------------------------------------------- */

/* C1 */
static inline void Keypad4x4_C1_ConfigInput(void){
    ClearBitMask_Reg8(&KEYPAD4X4_C1_DDR, KEYPAD4X4_C1_MASK);
}

static inline void Keypad4x4_C1_ConfigPullUp(void){
    SetBitMask_Reg8(&KEYPAD4X4_C1_PORT, KEYPAD4X4_C1_MASK);
}

static inline uint8_t Keypad4x4_C1_Read(void){
    return ReadBitMask_Reg8(&KEYPAD4X4_C1_PIN, KEYPAD4X4_C1_MASK);
}

static inline void Keypad4x4_C1_ConfigOutput(void){
    SetBitMask_Reg8(&KEYPAD4X4_C1_DDR, KEYPAD4X4_C1_MASK);
}

static inline void Keypad4x4_C1_Clear(void){
    ClearBitMask_Reg8(&KEYPAD4X4_C1_PORT, KEYPAD4X4_C1_MASK);
}

static inline void Keypad4x4_C1_Set(void){
    SetBitMask_Reg8(&KEYPAD4X4_C1_PORT, KEYPAD4X4_C1_MASK);
}


/* C2 */
static inline void Keypad4x4_C2_ConfigInput(void){
    ClearBitMask_Reg8(&KEYPAD4X4_C2_DDR, KEYPAD4X4_C2_MASK);
}

static inline void Keypad4x4_C2_ConfigPullUp(void){
    SetBitMask_Reg8(&KEYPAD4X4_C2_PORT, KEYPAD4X4_C2_MASK);
}

static inline uint8_t Keypad4x4_C2_Read(void){
    return ReadBitMask_Reg8(&KEYPAD4X4_C2_PIN, KEYPAD4X4_C2_MASK);
}

static inline void Keypad4x4_C2_ConfigOutput(void){
    SetBitMask_Reg8(&KEYPAD4X4_C2_DDR, KEYPAD4X4_C2_MASK);
}

static inline void Keypad4x4_C2_Clear(void){
    ClearBitMask_Reg8(&KEYPAD4X4_C2_PORT, KEYPAD4X4_C2_MASK);
}

static inline void Keypad4x4_C2_Set(void){
    SetBitMask_Reg8(&KEYPAD4X4_C2_PORT, KEYPAD4X4_C2_MASK);
}


/* C3 */
static inline void Keypad4x4_C3_ConfigInput(void){
    ClearBitMask_Reg8(&KEYPAD4X4_C3_DDR, KEYPAD4X4_C3_MASK);
}

static inline void Keypad4x4_C3_ConfigPullUp(void){
    SetBitMask_Reg8(&KEYPAD4X4_C3_PORT, KEYPAD4X4_C3_MASK);
}

static inline uint8_t Keypad4x4_C3_Read(void){
    return ReadBitMask_Reg8(&KEYPAD4X4_C3_PIN, KEYPAD4X4_C3_MASK);
}

static inline void Keypad4x4_C3_ConfigOutput(void){
    SetBitMask_Reg8(&KEYPAD4X4_C3_DDR, KEYPAD4X4_C3_MASK);
}

static inline void Keypad4x4_C3_Clear(void){
    ClearBitMask_Reg8(&KEYPAD4X4_C3_PORT, KEYPAD4X4_C3_MASK);
}

static inline void Keypad4x4_C3_Set(void){
    SetBitMask_Reg8(&KEYPAD4X4_C3_PORT, KEYPAD4X4_C3_MASK);
}


/* C4 */
static inline void Keypad4x4_C4_ConfigInput(void){
    ClearBitMask_Reg8(&KEYPAD4X4_C4_DDR, KEYPAD4X4_C4_MASK);
}

static inline void Keypad4x4_C4_ConfigPullUp(void){
    SetBitMask_Reg8(&KEYPAD4X4_C4_PORT, KEYPAD4X4_C4_MASK);
}

static inline uint8_t Keypad4x4_C4_Read(void){
    return ReadBitMask_Reg8(&KEYPAD4X4_C4_PIN, KEYPAD4X4_C4_MASK);
}

static inline void Keypad4x4_C4_ConfigOutput(void){
    SetBitMask_Reg8(&KEYPAD4X4_C4_DDR, KEYPAD4X4_C4_MASK);
}

static inline void Keypad4x4_C4_Clear(void){
    ClearBitMask_Reg8(&KEYPAD4X4_C4_PORT, KEYPAD4X4_C4_MASK);
}

static inline void Keypad4x4_C4_Set(void){
    SetBitMask_Reg8(&KEYPAD4X4_C4_PORT, KEYPAD4X4_C4_BIT);
}

#ifdef __cplusplus
}
#endif

#endif
