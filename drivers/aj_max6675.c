// GitHub Account: GitHub.com/AliRezaJoodi

#include <stdint.h>
#include "aj_max6675_type.h"
#include "aj_max6675_port.h"
#include "aj_max6675.h"

#define AJ_MAX6675_ERROR        0x00U

//*************************************************************
void AJ_MAX6675_Init(aj_max6675_t *max){
    AJ_MAX6675_CS_ConfigAsOutput(max);
    AJ_MAX6675_CS_SetIdle(max);
}

//*************************************************************
uint16_t AJ_MAX6675_ReadRaw(aj_max6675_t *max){
    uint8_t msb, lsb;
    uint16_t data;

    AJ_MAX6675_CS_SetActive(max);
    AJ_MAX6675_DELAY_US(1U);

    msb = AJ_MAX6675_SPI_Receive();
    lsb  = AJ_MAX6675_SPI_Receive();

    AJ_MAX6675_DELAY_US(1U);
    AJ_MAX6675_CS_SetIdle(max);

    data = ((uint16_t)msb << 8) | lsb;

    if(data & 0x04){
        return AJ_MAX6675_ERROR;
    }

    return data >> 3;
}


