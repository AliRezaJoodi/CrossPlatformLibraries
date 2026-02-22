#ifndef SEG7_DRIVER_PORT_INCLUDED
#define SEG7_DRIVER_PORT_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <io.h>

#include "utility_bit.h"
#include "seg7_driver_hw.h"

static inline void Seg7_Digits_InitAllPins(void){
    SET_BIT(SEG7_DIGIT0_DDR,  SEG7_DIGIT0_BIT);
    //WRITE_BIT(SEG7_DIGIT0_PORT,  SEG7_DIGIT0_BIT,  !SEG7_ACTIVATE_DIGIT);   // Idle status

    SET_BIT(SEG7_DIGIT1_DDR,  SEG7_DIGIT1_BIT);
    //WRITE_BIT(SEG7_DIGIT1_PORT,  SEG7_DIGIT1_BIT,  !SEG7_ACTIVATE_DIGIT);  // Idle status
}

static inline void Seg7_Digits_DisableAllPins(void){
    WRITE_BIT(SEG7_DIGIT0_PORT,  SEG7_DIGIT0_BIT,  !SEG7_ACTIVATE_DIGIT);
    WRITE_BIT(SEG7_DIGIT1_PORT,  SEG7_DIGIT1_BIT,  !SEG7_ACTIVATE_DIGIT);
}

static inline void Seg7_Digit_EnablePin(uint8_t index){
    switch (index){
        case 0:
            WRITE_BIT(SEG7_DIGIT0_PORT,  SEG7_DIGIT0_BIT,  SEG7_ACTIVATE_DIGIT);
            break;
        case 1:
            WRITE_BIT(SEG7_DIGIT1_PORT,  SEG7_DIGIT1_BIT,  SEG7_ACTIVATE_DIGIT);
            break;
    }
}

static inline void Seg7_Segments_InitAllPins(void){
    SET_BIT(SEG7_A_DDR,  SEG7_A_BIT);
    //WRITE_BIT(SEG7_A_PORT,  SEG7_A_BIT,  !SEG7_ACTIVATE_SEGMENT);   // Idle status

    SET_BIT(SEG7_B_DDR,  SEG7_B_BIT);
    //WRITE_BIT(SEG7_B_PORT,  SEG7_B_BIT,  !SEG7_ACTIVATE_SEGMENT);

    SET_BIT(SEG7_C_DDR,  SEG7_C_BIT);
    //WRITE_BIT(SEG7_C_PORT,  SEG7_C_BIT,  !SEG7_ACTIVATE_SEGMENT);

    SET_BIT(SEG7_D_DDR,  SEG7_D_BIT);
    //WRITE_BIT(SEG7_D_PORT,  SEG7_D_BIT,  !SEG7_ACTIVATE_SEGMENT);

    SET_BIT(SEG7_E_DDR,  SEG7_E_BIT);
    //WRITE_BIT(SEG7_E_PORT,  SEG7_E_BIT,  !SEG7_ACTIVATE_SEGMENT);

    SET_BIT(SEG7_F_DDR,  SEG7_F_BIT);
    //WRITE_BIT(SEG7_F_PORT,  SEG7_F_BIT,  !SEG7_ACTIVATE_SEGMENT);

    SET_BIT(SEG7_G_DDR,  SEG7_G_BIT);
    //WRITE_BIT(SEG7_G_PORT,  SEG7_G_BIT,  !SEG7_ACTIVATE_SEGMENT);

    SET_BIT(SEG7_DP_DDR, SEG7_DP_BIT);
    //WRITE_BIT(SEG7_DP_PORT, SEG7_DP_BIT, !SEG7_ACTIVATE_SEGMENT);
}

static inline void Seg7_Segments_WriteAllPins(uint8_t buf){
    if(SEG7_ACTIVATE_SEGMENT == 0){buf = ~buf;}

    WRITE_BIT(SEG7_A_PORT,  SEG7_A_BIT,  GET_BIT(buf, 0));
    WRITE_BIT(SEG7_B_PORT,  SEG7_B_BIT,  GET_BIT(buf, 1));
    WRITE_BIT(SEG7_C_PORT,  SEG7_C_BIT,  GET_BIT(buf, 2));
    WRITE_BIT(SEG7_D_PORT,  SEG7_D_BIT,  GET_BIT(buf, 3));
    WRITE_BIT(SEG7_E_PORT,  SEG7_E_BIT,  GET_BIT(buf, 4));
    WRITE_BIT(SEG7_F_PORT,  SEG7_F_BIT,  GET_BIT(buf, 5));
    WRITE_BIT(SEG7_G_PORT,  SEG7_G_BIT,  GET_BIT(buf, 6));
    WRITE_BIT(SEG7_DP_PORT, SEG7_DP_BIT, GET_BIT(buf, 7));
}

#ifdef __cplusplus
}
#endif

#endif
