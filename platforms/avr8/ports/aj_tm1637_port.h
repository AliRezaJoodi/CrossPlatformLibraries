#ifndef AJ_TM1637_PORT_INCLUDED
#define AJ_TM1637_PORT_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif


#include <stdint.h>
#include "aj_compiler.h"
#include "aj_bit_reg.h"
#include "aj_tm1637_type.h"

#define AJ_TM1637_DELAY_US(VALUE)          AJ_DELAY_US(VALUE)

static inline void AJ_TM1637_CLK_SetActive(const aj_tm1637_t *tm){
    AJ_BitReg_SetBit_Mask(tm->clk.ddr,  tm->clk.mask);   /* Configure pin as output */
    AJ_BitReg_ClearBit_Mask(tm->clk.port, tm->clk.mask); /* Drive bus line low */
}

static inline void AJ_TM1637_CLK_SetIdle(const aj_tm1637_t *tm){
    AJ_BitReg_ClearBit_Mask(tm->clk.ddr,  tm->clk.mask);  /* Configure pin as input (high-Z) */
    AJ_BitReg_ClearBit_Mask(tm->clk.port, tm->clk.mask);  /* Disable internal pull-up */
}

static inline void AJ_TM1637_DIO_SetActive(const aj_tm1637_t *tm){
    AJ_BitReg_SetBit_Mask(tm->dio.ddr,  tm->dio.mask);   /* Configure pin as output */
    AJ_BitReg_ClearBit_Mask(tm->dio.port, tm->dio.mask); /* Drive bus line low */
}

static inline void AJ_TM1637_DIO_SetIdle(const aj_tm1637_t *tm){
    AJ_BitReg_ClearBit_Mask(tm->dio.ddr,  tm->dio.mask);  /* Configure pin as input (high-Z) */
    AJ_BitReg_ClearBit_Mask(tm->dio.port, tm->dio.mask);  /* Disable internal pull-up */
}

//***************************************
static inline void AJ_TM1637_DIO_ConfigAsInput(const aj_tm1637_t *tm){
    AJ_BitReg_ClearBit_Mask(tm->dio.ddr,  tm->dio.mask);  /* Configure pin as input (high-Z) */
    AJ_BitReg_ClearBit_Mask(tm->dio.port, tm->dio.mask);  /* Disable internal pull-up */
}

static inline uint8_t AJ_TM1637_DIO_Read(const aj_tm1637_t *tm){
    return AJ_BitReg_IsBitSet_Mask(tm->dio.pin, tm->dio.mask);
}


#ifdef __cplusplus
}
#endif

#endif
