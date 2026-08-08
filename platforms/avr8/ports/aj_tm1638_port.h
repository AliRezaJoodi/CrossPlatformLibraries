#ifndef AJ_TM1638_PORT_INCLUDED
#define AJ_TM1638_PORT_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif


#include <stdint.h>
#include "aj_bit_reg.h"
#include "aj_compiler.h"
#include "aj_tm1638_config_platform.h"
#include "aj_tm1638_type.h"

#define AJ_TM1638_DELAY_US(VALUE)          AJ_DELAY_US(VALUE)

//***************************************
static inline void AJ_TM1638_STB_ConfigAsOutput(aj_tm1638_t *tm){
    AJ_BitReg_SetBit_Mask(tm->stb.ddr, tm->stb.mask);
}

static inline void AJ_TM1638_STB_SetActive(aj_tm1638_t *tm){
    AJ_BitReg_ClearBit_Mask(tm->stb.port, tm->stb.mask);
}

static inline void AJ_TM1638_STB_SetIdle(aj_tm1638_t *tm){
    AJ_BitReg_SetBit_Mask(tm->stb.port, tm->stb.mask);
}

//***************************************
static inline void AJ_TM1638_CLK_ConfigAsOutput(void){
    AJ_BitReg_SetBit_Mask(&AJ_TM1638_CLK_DDR, AJ_TM1638_CLK_MASK);
}

static inline void AJ_TM1638_CLK_SetActive(void){
    AJ_BitReg_ClearBit_Mask(&AJ_TM1638_CLK_PORT, AJ_TM1638_CLK_MASK);
}

static inline void AJ_TM1638_CLK_SetIdle(void){
    AJ_BitReg_SetBit_Mask(&AJ_TM1638_CLK_PORT, AJ_TM1638_CLK_MASK);
}

//***************************************
static inline void AJ_TM1638_DIO_ConfigAsOutput(void){
    AJ_BitReg_SetBit_Mask(&AJ_TM1638_DIO_DDR, AJ_TM1638_DIO_MASK);
}

static inline void AJ_TM1638_DIO_SetActive(void){
    AJ_BitReg_ClearBit_Mask(&AJ_TM1638_DIO_PORT, AJ_TM1638_DIO_MASK);
}

static inline void AJ_TM1638_DIO_SetIdle(void){
    AJ_BitReg_SetBit_Mask(&AJ_TM1638_DIO_PORT, AJ_TM1638_DIO_MASK);
}

static inline void AJ_TM1638_DIO_ConfigAsInput(void){
    AJ_BitReg_ClearBit_Mask(&AJ_TM1638_DIO_DDR, AJ_TM1638_DIO_MASK);
}

static inline uint8_t AJ_TM1638_DIO_Read(void){
    return AJ_BitReg_IsBitSet_Mask(&AJ_TM1638_DIO_PIN, AJ_TM1638_DIO_MASK);
}


#ifdef __cplusplus
}
#endif

#endif
