#ifndef AJ_TM1638_PORT_INCLUDED
#define AJ_TM1638_PORT_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "aj_bit_reg.h"
#include "aj_compiler_port.h"
#include "aj_tm1638_hw.h"
#include "aj_tm1638_type.h"

#define AJ_TM1638_DELAY_US(VALUE)          AJ_DELAY_US(VALUE)

//***************************************
static inline void AJ_TM1638_STB_ConfigAsOutput(const aj_tm1638_t *tm){
    AJ_BitReg_SetBits_Mask(tm->stb.ddr, tm->stb.mask);
}

static inline void AJ_TM1638_STB_SetActive(const aj_tm1638_t *tm){
    AJ_BitReg_ClearBits_Mask(tm->stb.port, tm->stb.mask);
}

static inline void AJ_TM1638_STB_SetIdle(const aj_tm1638_t *tm){
    AJ_BitReg_SetBits_Mask(tm->stb.port, tm->stb.mask);
}

//***************************************
//static inline void TM1638_STB_Init(aj_tm1638_t *tm){
//    SetBit_Reg8(tm->stb.ddr, tm->stb.index);
//    //SetBit_Reg8(tm->stb.port, tm->stb.index);  // Idle bus
//}

//***************************************
//static inline void TM1638_STB_Write(aj_tm1638_t *tm, uint8_t status){
//    WriteBit_Reg8(tm->stb.port, tm->stb.index, status);
//}

//***************************************
static inline void AJ_TM1638_CLK_ConfigAsOutput(void){
    AJ_BitReg_SetBits_Mask(&AJ_TM1638_CLK_DDR, AJ_TM1638_CLK_MASK);
}

static inline void AJ_TM1638_CLK_SetActive(void){
    AJ_BitReg_ClearBits_Mask(&AJ_TM1638_CLK_PORT, AJ_TM1638_CLK_MASK);
}

static inline void AJ_TM1638_CLK_SetIdle(void){
    AJ_BitReg_SetBits_Mask(&AJ_TM1638_CLK_PORT, AJ_TM1638_CLK_MASK);
}

//***************************************
//static inline void TM1638_CLK_Init(void){
//    SetBit_Reg8(&AJ_TM1638_CLK_DDR, AJ_TM1638_CLK_POS);
//    //SetBit_Reg8(&AJ_TM1638_CLK_PORT, AJ_TM1638_CLK_POS); // Idle bus
//}

//***************************************
//static inline void TM1638_CLK_Write(uint8_t status){
//    WriteBit_Reg8(&AJ_TM1638_CLK_PORT, AJ_TM1638_CLK_POS, status);
//}

//***************************************
static inline void AJ_TM1638_DIO_ConfigAsOutput(void){
    AJ_BitReg_SetBits_Mask(&AJ_TM1638_DIO_DDR, AJ_TM1638_DIO_MASK);
}

static inline void AJ_TM1638_DIO_SetActive(void){
    AJ_BitReg_ClearBits_Mask(&AJ_TM1638_DIO_PORT, AJ_TM1638_DIO_MASK);
}

static inline void AJ_TM1638_DIO_SetIdle(void){
    AJ_BitReg_SetBits_Mask(&AJ_TM1638_DIO_PORT, AJ_TM1638_DIO_MASK);
}

static inline void AJ_TM1638_DIO_ConfigAsInput(void){
    AJ_BitReg_ClearBits_Mask(&AJ_TM1638_DIO_DDR, AJ_TM1638_DIO_MASK);
}

//***************************************
//static inline void TM1638_DIO_Config(uint8_t mode){
//    if(mode == TM1638_PIN_INPUT){
//        ClearBit_Reg8(&AJ_TM1638_DIO_DDR, AJ_TM1638_DIO_POS);
//        ClearBit_Reg8(&AJ_TM1638_DIO_PORT, AJ_TM1638_DIO_POS); // Disable pull-up
//    }
//    else{
//        SetBit_Reg8(&AJ_TM1638_DIO_DDR, AJ_TM1638_DIO_POS);
//        SetBit_Reg8(&AJ_TM1638_DIO_PORT, AJ_TM1638_DIO_POS); // Idle bus
//    }
//}

//***************************************
//static inline void TM1638_DIO_Write(uint8_t status){
//    WriteBit_Reg8(&AJ_TM1638_DIO_PORT, AJ_TM1638_DIO_POS, status);
//}

//***************************************
static inline uint8_t AJ_TM1638_DIO_Read(void){
    return AJ_BitReg_AreBitsSet_Mask(&AJ_TM1638_DIO_PIN, AJ_TM1638_DIO_MASK);
}

//static inline uint8_t AJ_TM1638_DIO_Read(void){
//    return Read8Bit_Reg8(&AJ_TM1638_DIO_PIN, AJ_TM1638_DIO_POS);
//}

#ifdef __cplusplus
}
#endif

#endif
