#ifndef KEYPAD4x4_PORT_INCLUDED
#define KEYPAD4x4_PORT_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "utility_bit.h"
#include "compiler_port.h"
#include "keypad4x4_hw.h"

#define KEYPAD4X4_DELAY_US(VALUE)          DELAY_US(VALUE)


//static inline void Keypad4x4_ConfigPin(volatile uint8_t *ddr,
//                                        volatile uint8_t *port,
//                                        uint8_t index,
//                                        uint8_t mode)
//{
//    if(mode){
//        SET_BIT(*ddr, KEYPAD_R1_BIT);
//        CLEAR_BIT(*port, KEYPAD_R1_BIT);
//    }
//    else{
//        CLEAR_BIT(*ddr, KEYPAD_R1_BIT);
//        SET_BIT(*port, KEYPAD_R1_BIT);
//    }
//}

static inline void Keypad4x4_R1_ConfigPin(uint8_t mode){
    if(mode){
        SET_BIT(KEYPAD_R1_DDR, KEYPAD_R1_BIT);
        CLEAR_BIT(KEYPAD_R1_PORT, KEYPAD_R1_BIT);
    }
    else{
        CLEAR_BIT(KEYPAD_R1_DDR, KEYPAD_R1_BIT);
        SET_BIT(KEYPAD_R1_PORT, KEYPAD_R1_BIT);
    }
}

static inline void Keypad4x4_R2_ConfigPin(uint8_t mode){
    if(mode){
        SET_BIT(KEYPAD_R2_DDR, KEYPAD_R2_BIT);
        CLEAR_BIT(KEYPAD_R2_PORT, KEYPAD_R2_BIT);
    }
    else{
        CLEAR_BIT(KEYPAD_R2_DDR, KEYPAD_R2_BIT);
        SET_BIT(KEYPAD_R2_PORT, KEYPAD_R2_BIT);
    }
}

static inline void Keypad4x4_R3_ConfigPin(uint8_t mode){
    if(mode){
        SET_BIT(KEYPAD_R3_DDR, KEYPAD_R3_BIT);
        CLEAR_BIT(KEYPAD_R3_PORT, KEYPAD_R3_BIT);
    }
    else{
        CLEAR_BIT(KEYPAD_R3_DDR, KEYPAD_R3_BIT);
        SET_BIT(KEYPAD_R3_PORT, KEYPAD_R3_BIT);
    }
}

static inline void Keypad4x4_R4_ConfigPin(uint8_t mode){
    if(mode){
        SET_BIT(KEYPAD_R4_DDR, KEYPAD_R4_BIT);
        CLEAR_BIT(KEYPAD_R4_PORT, KEYPAD_R4_BIT);
    }
    else{
        CLEAR_BIT(KEYPAD_R4_DDR, KEYPAD_R4_BIT);
        SET_BIT(KEYPAD_R4_PORT, KEYPAD_R4_BIT);
    }
}

static inline void Keypad4x4_C1_ConfigPin(uint8_t mode){
    if(mode){
        SET_BIT(KEYPAD_C1_DDR, KEYPAD_C1_BIT);
        CLEAR_BIT(KEYPAD_C1_PORT, KEYPAD_C1_BIT);
    }
    else{
        CLEAR_BIT(KEYPAD_C1_DDR, KEYPAD_C1_BIT);
        SET_BIT(KEYPAD_C1_PORT, KEYPAD_C1_BIT);
    }
}

static inline void Keypad4x4_C2_ConfigPin(uint8_t mode){
    if(mode){
        SET_BIT(KEYPAD_C2_DDR, KEYPAD_C2_BIT);
        CLEAR_BIT(KEYPAD_C2_PORT, KEYPAD_C2_BIT);
    }
    else{
        CLEAR_BIT(KEYPAD_C2_DDR, KEYPAD_C2_BIT);
        SET_BIT(KEYPAD_C2_PORT, KEYPAD_C2_BIT);
    }
}

static inline void Keypad4x4_C3_ConfigPin(uint8_t mode){
    if(mode){
        SET_BIT(KEYPAD_C3_DDR, KEYPAD_C3_BIT);
        CLEAR_BIT(KEYPAD_C3_PORT, KEYPAD_C3_BIT);
    }
    else{
        CLEAR_BIT(KEYPAD_C3_DDR, KEYPAD_C3_BIT);
        SET_BIT(KEYPAD_C3_PORT, KEYPAD_C3_BIT);
    }
}

static inline void Keypad4x4_C4_ConfigPin(uint8_t mode){
    if(mode){
        SET_BIT(KEYPAD_C4_DDR, KEYPAD_C4_BIT);
        CLEAR_BIT(KEYPAD_C4_PORT, KEYPAD_C4_BIT);
    }
    else{
        CLEAR_BIT(KEYPAD_C4_DDR, KEYPAD_C4_BIT);
        SET_BIT(KEYPAD_C4_PORT, KEYPAD_C4_BIT);
    }
}

#ifdef __cplusplus
}
#endif

#endif
