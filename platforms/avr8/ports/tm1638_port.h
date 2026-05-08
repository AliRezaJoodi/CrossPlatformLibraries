#ifndef TM1638_PORT_INCLUDED
#define TM1638_PORT_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "bit_register8.h"
#include "compiler_port.h"
#include "tm1638_hw.h"
#include "tm1638_types.h"

#define TM1638_DELAY_US(VALUE)          DELAY_US(VALUE)

//***************************************
static inline void TM1638_STB_ConfigOutput(const TM1638_t *tm){
    SetBitMask_Reg8(tm->stb.ddr, tm->stb.mask);
}

static inline void TM1638_STB_SetActive(const TM1638_t *tm){
    ClearBitMask_Reg8(tm->stb.port, tm->stb.mask);
}

static inline void TM1638_STB_SetIdle(const TM1638_t *tm){
    SetBitMask_Reg8(tm->stb.port, tm->stb.mask);
}

//***************************************
//static inline void TM1638_STB_Init(TM1638_t *tm){
//    SetBit_Reg8(tm->stb.ddr, tm->stb.index);
//    //SetBit_Reg8(tm->stb.port, tm->stb.index);  // Idle bus
//}

//***************************************
//static inline void TM1638_STB_Write(TM1638_t *tm, uint8_t status){
//    WriteBit_Reg8(tm->stb.port, tm->stb.index, status);
//}

//***************************************
static inline void TM1638_CLK_ConfigOutput(void){
    SetBitMask_Reg8(&TM1638_CLK_DDR, TM1638_CLK_MASK);
}

static inline void TM1638_CLK_SetActive(void){
    ClearBitMask_Reg8(&TM1638_CLK_PORT, TM1638_CLK_MASK);
}

static inline void TM1638_CLK_SetIdle(void){
    SetBitMask_Reg8(&TM1638_CLK_PORT, TM1638_CLK_MASK);
}

//***************************************
//static inline void TM1638_CLK_Init(void){
//    SetBit_Reg8(&TM1638_CLK_DDR, TM1638_CLK_BIT);
//    //SetBit_Reg8(&TM1638_CLK_PORT, TM1638_CLK_BIT); // Idle bus
//}

//***************************************
//static inline void TM1638_CLK_Write(uint8_t status){
//    WriteBit_Reg8(&TM1638_CLK_PORT, TM1638_CLK_BIT, status);
//}

//***************************************
static inline void TM1638_DIO_ConfigOutput(void){
    SetBitMask_Reg8(&TM1638_DIO_DDR, TM1638_DIO_MASK);
}

static inline void TM1638_DIO_SetActive(void){
    ClearBitMask_Reg8(&TM1638_DIO_PORT, TM1638_DIO_MASK);
}

static inline void TM1638_DIO_SetIdle(void){
    SetBitMask_Reg8(&TM1638_DIO_PORT, TM1638_DIO_MASK);
}

static inline void TM1638_DIO_ConfigInput(void){
    ClearBitMask_Reg8(&TM1638_DIO_DDR, TM1638_DIO_MASK);
}

//***************************************
//static inline void TM1638_DIO_Config(uint8_t mode){
//    if(mode == TM1638_PIN_INPUT){
//        ClearBit_Reg8(&TM1638_DIO_DDR, TM1638_DIO_BIT);
//        ClearBit_Reg8(&TM1638_DIO_PORT, TM1638_DIO_BIT); // Disable pull-up
//    }
//    else{
//        SetBit_Reg8(&TM1638_DIO_DDR, TM1638_DIO_BIT);
//        SetBit_Reg8(&TM1638_DIO_PORT, TM1638_DIO_BIT); // Idle bus
//    }
//}

//***************************************
//static inline void TM1638_DIO_Write(uint8_t status){
//    WriteBit_Reg8(&TM1638_DIO_PORT, TM1638_DIO_BIT, status);
//}

//***************************************
static inline uint8_t TM1638_DIO_Read(void){
    return ReadBitMask_Reg8(&TM1638_DIO_PIN, TM1638_DIO_MASK);
}

//static inline uint8_t TM1638_DIO_Read(void){
//    return Read8Bit_Reg8(&TM1638_DIO_PIN, TM1638_DIO_BIT);
//}

#ifdef __cplusplus
}
#endif

#endif
