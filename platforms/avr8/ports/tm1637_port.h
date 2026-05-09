#ifndef TM1637_PORT_INCLUDED
#define TM1637_PORT_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "compiler_port.h"
#include "bit_register8.h"
#include "tm1637_hw.h"
#include "tm1637_types.h"

#define TM1637_DELAY_US(VALUE)          DELAY_US(VALUE)

//#define TM1637_CLK_LOW(tm)      ( \
//                                *(tm->clk.ddr) |= (tm->clk.mask); \
//                                *(tm->clk.port) &= ~(tm->clk.mask) \
//                                )
//
//#define TM1637_CLK_SetIdle(tm)  ( \
//                                *(tm->clk.ddr) &= ~(tm->clk.mask); \
//                                *(tm->clk.port) &= ~(tm->clk.mask) \
//                                )

static inline void TM1637_CLK_SetActive(const TM1637_t *tm){
    SetBitMask_Reg8(tm->clk.ddr,  tm->clk.mask);   /* Configure pin as output */
    ClearBitMask_Reg8(tm->clk.port, tm->clk.mask); /* Drive bus line low */
}

static inline void TM1637_CLK_SetIdle(const TM1637_t *tm){
    ClearBitMask_Reg8(tm->clk.ddr,  tm->clk.mask);  /* Configure pin as input (high-Z) */
    ClearBitMask_Reg8(tm->clk.port, tm->clk.mask);  /* Disable internal pull-up */
}

//static inline void TM1637_CLK_SetActive(TM1637_t *tm){
//    *(tm->clk.ddr)  |=  tm->clk.mask;     /* Configure pin as output */
//    *(tm->clk.port) &= ~tm->clk.mask;     /* Drive bus line low */
//}

//static inline void TM1637_CLK_SetIdle(TM1637_t *tm){
//    *(tm->clk.ddr)  &= ~tm->clk.mask;     /* Configure pin as input (hig-Z) */
//    *(tm->clk.port) &= ~tm->clk.mask;     /* Disable internal pull-up */
//}

//***************************************
//static inline void TM1637_CLK_Write(TM1637_t *tm, uint8_t status){
//    if(status == 1){
//        ClearBit_Reg8(tm->clk.ddr, tm->clk.index);
//        ClearBit_Reg8(tm->clk.port, tm->clk.index);
//    }
//    else{
//        SetBit_Reg8(tm->clk.ddr, tm->clk.index);
//        ClearBit_Reg8(tm->clk.port, tm->clk.index);
//    }
//}

static inline void TM1637_DIO_SetActive(const TM1637_t *tm){
    SetBitMask_Reg8(tm->dio.ddr,  tm->dio.mask);   /* Configure pin as output */
    ClearBitMask_Reg8(tm->dio.port, tm->dio.mask); /* Drive bus line low */
}

static inline void TM1637_DIO_SetIdle(const TM1637_t *tm){
    ClearBitMask_Reg8(tm->dio.ddr,  tm->dio.mask);  /* Configure pin as input (high-Z) */
    ClearBitMask_Reg8(tm->dio.port, tm->dio.mask);  /* Disable internal pull-up */
}

//***************************************
static inline void TM1637_DIO_ConfigInput(const TM1637_t *tm){
    ClearBitMask_Reg8(tm->dio.ddr,  tm->dio.mask);  /* Configure pin as input (high-Z) */
    ClearBitMask_Reg8(tm->dio.port, tm->dio.mask);  /* Disable internal pull-up */
}

//***************************************
//static inline void TM1637_DIO_Write(TM1637_t *tm, uint8_t status){
//    if(status == 1){
//        TM1637_DIO_ConfigInput(tm);
//    }
//    else{
//        SetBit_Reg8(tm->dio.ddr, tm->dio.index);
//        ClearBit_Reg8(tm->dio.port, tm->dio.index);
//    }
//}

//***************************************
//static inline uint8_t TM1637_DIO_Read(TM1637_t *tm){
//    return ReadBit_Reg8(tm->dio.pin, tm->dio.index);
//}

static inline uint8_t TM1637_DIO_Read(const TM1637_t *tm){
    //return ((*(tm->dio.pin) & tm->dio.mask) != 0U);
    return GetBitMask_Reg8(tm->dio.pin, tm->dio.mask);
}

#ifdef __cplusplus
}
#endif

#endif
