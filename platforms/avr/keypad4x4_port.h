#ifndef KEYPAD4X4_PORT_INCLUDED
#define KEYPAD4X4_PORT_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "compiler_port.h"
#include "utils/bit_register.h"
#include "keypad4x4_hw.h"

/* =========================================================
   Rows
   ========================================================= */

/* R1 */
static inline void Keypad4x4_R1_SetInput(void){
    ClearBit_Reg8(&KEYPAD4X4_R1_DDR, KEYPAD4X4_R1_BIT);
}

static inline void Keypad4x4_R1_SetPullUp(void){
    SetBit_Reg8(&KEYPAD4X4_R1_PORT, KEYPAD4X4_R1_BIT);
}

static inline uint8_t Keypad4x4_R1_Read(void){
    return ReadBit_Reg8(&KEYPAD4X4_R1_PIN, KEYPAD4X4_R1_BIT);
}

static inline void Keypad4x4_R1_SetOutput(void){
    SetBit_Reg8(&KEYPAD4X4_R1_DDR, KEYPAD4X4_R1_BIT);
}

static inline void Keypad4x4_R1_WriteLow(void){
    ClearBit_Reg8(&KEYPAD4X4_R1_PORT, KEYPAD4X4_R1_BIT);
}

static inline void Keypad4x4_R1_WriteHigh(void){
    SetBit_Reg8(&KEYPAD4X4_R1_PORT, KEYPAD4X4_R1_BIT);
}


/* R2 */
static inline void Keypad4x4_R2_SetInput(void){
    ClearBit_Reg8(&KEYPAD4X4_R2_DDR, KEYPAD4X4_R2_BIT);
}

static inline void Keypad4x4_R2_SetPullUp(void){
    SetBit_Reg8(&KEYPAD4X4_R2_PORT, KEYPAD4X4_R2_BIT);
}

static inline uint8_t Keypad4x4_R2_Read(void){
    return ReadBit_Reg8(&KEYPAD4X4_R2_PIN, KEYPAD4X4_R2_BIT);
}

static inline void Keypad4x4_R2_SetOutput(void){
    SetBit_Reg8(&KEYPAD4X4_R2_DDR, KEYPAD4X4_R2_BIT);
}

static inline void Keypad4x4_R2_WriteLow(void){
    ClearBit_Reg8(&KEYPAD4X4_R2_PORT, KEYPAD4X4_R2_BIT);
}

static inline void Keypad4x4_R2_WriteHigh(void){
    SetBit_Reg8(&KEYPAD4X4_R2_PORT, KEYPAD4X4_R2_BIT);
}


/* R3 */
static inline void Keypad4x4_R3_SetInput(void){
    ClearBit_Reg8(&KEYPAD4X4_R3_DDR, KEYPAD4X4_R3_BIT);
}

static inline void Keypad4x4_R3_SetPullUp(void){
    SetBit_Reg8(&KEYPAD4X4_R3_PORT, KEYPAD4X4_R3_BIT);
}

static inline uint8_t Keypad4x4_R3_Read(void){
    return ReadBit_Reg8(&KEYPAD4X4_R3_PIN, KEYPAD4X4_R3_BIT);
}

static inline void Keypad4x4_R3_SetOutput(void){
    SetBit_Reg8(&KEYPAD4X4_R3_DDR, KEYPAD4X4_R3_BIT);
}

static inline void Keypad4x4_R3_WriteLow(void){
    ClearBit_Reg8(&KEYPAD4X4_R3_PORT, KEYPAD4X4_R3_BIT);
}

static inline void Keypad4x4_R3_WriteHigh(void){
    SetBit_Reg8(&KEYPAD4X4_R3_PORT, KEYPAD4X4_R3_BIT);
}


/* R4 */
static inline void Keypad4x4_R4_SetInput(void){
    ClearBit_Reg8(&KEYPAD4X4_R4_DDR, KEYPAD4X4_R4_BIT);
}

static inline void Keypad4x4_R4_SetPullUp(void){
    SetBit_Reg8(&KEYPAD4X4_R4_PORT, KEYPAD4X4_R4_BIT);
}

static inline uint8_t Keypad4x4_R4_Read(void){
    return ReadBit_Reg8(&KEYPAD4X4_R4_PIN, KEYPAD4X4_R4_BIT);
}

static inline void Keypad4x4_R4_SetOutput(void){
    SetBit_Reg8(&KEYPAD4X4_R4_DDR, KEYPAD4X4_R4_BIT);
}

static inline void Keypad4x4_R4_WriteLow(void){
    ClearBit_Reg8(&KEYPAD4X4_R4_PORT, KEYPAD4X4_R4_BIT);
}

static inline void Keypad4x4_R4_WriteHigh(void){
    SetBit_Reg8(&KEYPAD4X4_R4_PORT, KEYPAD4X4_R4_BIT);
}


/* =========================================================
   Columns
   ========================================================= */

/* C1 */
static inline void Keypad4x4_C1_SetInput(void){
    ClearBit_Reg8(&KEYPAD4X4_C1_DDR, KEYPAD4X4_C1_BIT);
}

static inline void Keypad4x4_C1_SetPullUp(void){
    SetBit_Reg8(&KEYPAD4X4_C1_PORT, KEYPAD4X4_C1_BIT);
}

static inline uint8_t Keypad4x4_C1_Read(void){
    return ReadBit_Reg8(&KEYPAD4X4_C1_PIN, KEYPAD4X4_C1_BIT);
}

static inline void Keypad4x4_C1_SetOutput(void){
    SetBit_Reg8(&KEYPAD4X4_C1_DDR, KEYPAD4X4_C1_BIT);
}

static inline void Keypad4x4_C1_WriteLow(void){
    ClearBit_Reg8(&KEYPAD4X4_C1_PORT, KEYPAD4X4_C1_BIT);
}

static inline void Keypad4x4_C1_WriteHigh(void){
    SetBit_Reg8(&KEYPAD4X4_C1_PORT, KEYPAD4X4_C1_BIT);
}


/* C2 */
static inline void Keypad4x4_C2_SetInput(void){
    ClearBit_Reg8(&KEYPAD4X4_C2_DDR, KEYPAD4X4_C2_BIT);
}

static inline void Keypad4x4_C2_SetPullUp(void){
    SetBit_Reg8(&KEYPAD4X4_C2_PORT, KEYPAD4X4_C2_BIT);
}

static inline uint8_t Keypad4x4_C2_Read(void){
    return ReadBit_Reg8(&KEYPAD4X4_C2_PIN, KEYPAD4X4_C2_BIT);
}

static inline void Keypad4x4_C2_SetOutput(void){
    SetBit_Reg8(&KEYPAD4X4_C2_DDR, KEYPAD4X4_C2_BIT);
}

static inline void Keypad4x4_C2_WriteLow(void){
    ClearBit_Reg8(&KEYPAD4X4_C2_PORT, KEYPAD4X4_C2_BIT);
}

static inline void Keypad4x4_C2_WriteHigh(void){
    SetBit_Reg8(&KEYPAD4X4_C2_PORT, KEYPAD4X4_C2_BIT);
}


/* C3 */
static inline void Keypad4x4_C3_SetInput(void){
    ClearBit_Reg8(&KEYPAD4X4_C3_DDR, KEYPAD4X4_C3_BIT);
}

static inline void Keypad4x4_C3_SetPullUp(void){
    SetBit_Reg8(&KEYPAD4X4_C3_PORT, KEYPAD4X4_C3_BIT);
}

static inline uint8_t Keypad4x4_C3_Read(void){
    return ReadBit_Reg8(&KEYPAD4X4_C3_PIN, KEYPAD4X4_C3_BIT);
}

static inline void Keypad4x4_C3_SetOutput(void){
    SetBit_Reg8(&KEYPAD4X4_C3_DDR, KEYPAD4X4_C3_BIT);
}

static inline void Keypad4x4_C3_WriteLow(void){
    ClearBit_Reg8(&KEYPAD4X4_C3_PORT, KEYPAD4X4_C3_BIT);
}

static inline void Keypad4x4_C3_WriteHigh(void){
    SetBit_Reg8(&KEYPAD4X4_C3_PORT, KEYPAD4X4_C3_BIT);
}


/* C4 */
static inline void Keypad4x4_C4_SetInput(void){
    ClearBit_Reg8(&KEYPAD4X4_C4_DDR, KEYPAD4X4_C4_BIT);
}

static inline void Keypad4x4_C4_SetPullUp(void){
    SetBit_Reg8(&KEYPAD4X4_C4_PORT, KEYPAD4X4_C4_BIT);
}

static inline uint8_t Keypad4x4_C4_Read(void){
    return ReadBit_Reg8(&KEYPAD4X4_C4_PIN, KEYPAD4X4_C4_BIT);
}

static inline void Keypad4x4_C4_SetOutput(void){
    SetBit_Reg8(&KEYPAD4X4_C4_DDR, KEYPAD4X4_C4_BIT);
}

static inline void Keypad4x4_C4_WriteLow(void){
    ClearBit_Reg8(&KEYPAD4X4_C4_PORT, KEYPAD4X4_C4_BIT);
}

static inline void Keypad4x4_C4_WriteHigh(void){
    SetBit_Reg8(&KEYPAD4X4_C4_PORT, KEYPAD4X4_C4_BIT);
}

#ifdef __cplusplus
}
#endif

#endif
