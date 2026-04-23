#ifndef TM1637_PORT_INCLUDED
#define TM1637_PORT_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "compiler_port.h"
#include "utils/bit_register.h"
#include "tm1637_hw.h"
#include "tm1637_types.h"

#define TM1637_DELAY_US(VALUE)          DELAY_US(VALUE)

//***************************************
static inline void TM1637_CLK_Write(TM1637_t *tm, uint8_t status){
    if(status == 1){
        ClearBit_Reg8(tm->clk.ddr, tm->clk.index);
        ClearBit_Reg8(tm->clk.port, tm->clk.index);
    }
    else{
        SetBit_Reg8(tm->clk.ddr, tm->clk.index);
        ClearBit_Reg8(tm->clk.port, tm->clk.index);
    }
}

//***************************************
static inline void TM1637_DIO_SetInput(TM1637_t *tm){
    ClearBit_Reg8(tm->dio.ddr, tm->dio.index);
    ClearBit_Reg8(tm->dio.port, tm->dio.index);
}

//***************************************
static inline void TM1637_DIO_Write(TM1637_t *tm, uint8_t status){
    if(status == 1){
        TM1637_DIO_SetInput(tm);
    }
    else{
        SetBit_Reg8(tm->dio.ddr, tm->dio.index);
        ClearBit_Reg8(tm->dio.port, tm->dio.index);
    }
}

//***************************************
static inline uint8_t TM1637_DIO_Read(TM1637_t *tm){
    return ReadBit_Reg8(tm->dio.pin, tm->dio.index);
}

#ifdef __cplusplus
}
#endif

#endif
