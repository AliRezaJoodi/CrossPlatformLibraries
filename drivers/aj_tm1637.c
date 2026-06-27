// GitHub Account: GitHub.com/AliRezaJoodi

#include <stdint.h>
#include "aj_bit_u8.h"
#include "aj_tm1637_type.h"
#include "aj_tm1637_port.h"
#include "aj_tm1637.h"

/**
 * @brief Half bit delay time in microseconds.
 *
 * This value defines the TM1637 clock timing.
 * One full clock period is equal to (AJ_TM1637_HALF_BIT_US * 4).
 *
 * @note Typical clock frequency is 450 kHz
 * @note Maximum clock frequency is 500 kHz
 */
#define AJ_TM1637_HALF_BIT_US       1U

#define TM1637_COMMAND_DATA_WRITE   0x40U   // Data command setting: Write data to display register
#define TM1637_COMMAND_DATA_READ    0x42U   // Data command setting: Read key scan data
#define TM1637_COMMAND_ADDRESS      0xC0U   // Address command setting
#define TM1637_COMMAND_DISPLAY      0x80U   // Display control

//***************************************
void TM1637_Start(aj_tm1637_t *tm){
    AJ_TM1637_CLK_SetIdle(tm);
    AJ_TM1637_DIO_SetIdle(tm);
    AJ_TM1637_DELAY_US(AJ_TM1637_HALF_BIT_US*2);

    AJ_TM1637_DIO_SetActive(tm);
    AJ_TM1637_DELAY_US(AJ_TM1637_HALF_BIT_US*2);
}

//***************************************
void TM1637_Stop(aj_tm1637_t *tm){
    AJ_TM1637_DIO_SetActive(tm);
    AJ_TM1637_CLK_SetIdle(tm);
    AJ_TM1637_DELAY_US(AJ_TM1637_HALF_BIT_US*2);

    AJ_TM1637_DIO_SetIdle(tm);
    AJ_TM1637_DELAY_US(AJ_TM1637_HALF_BIT_US*2);
}

//***************************************
uint8_t TM1637_WriteByte(aj_tm1637_t *tm, uint8_t data){
    uint8_t i = 0;
    uint8_t ack = 0;

    for(i = 0; i < 8; i++) {
        AJ_TM1637_CLK_SetActive(tm);
        AJ_TM1637_DELAY_US(AJ_TM1637_HALF_BIT_US);

        if (data & 0x01){
            AJ_TM1637_DIO_SetIdle(tm);
        }
        else{
            AJ_TM1637_DIO_SetActive(tm);
        }
        AJ_TM1637_DELAY_US(AJ_TM1637_HALF_BIT_US);

        AJ_TM1637_CLK_SetIdle(tm);
        AJ_TM1637_DELAY_US(AJ_TM1637_HALF_BIT_US*2);

        data = data >> 1;
    }

    AJ_TM1637_CLK_SetActive(tm);
    AJ_TM1637_DIO_ConfigAsInput(tm);
    AJ_TM1637_DELAY_US(AJ_TM1637_HALF_BIT_US*4);

    AJ_TM1637_CLK_SetIdle(tm);
    AJ_TM1637_DELAY_US(AJ_TM1637_HALF_BIT_US*2);
    ack = AJ_TM1637_DIO_Read(tm);
//    if(ack == 0){
//        TM1637_DIO_Write(tm, DIO_ACTIVE);       // check this line
//    }
    //TM1637_CLK_Write(tm, CLK_ACTIVE);
    AJ_TM1637_CLK_SetActive(tm);
    AJ_TM1637_DELAY_US(AJ_TM1637_HALF_BIT_US*2);

    return ack;
}

//***************************************
void AJ_TM1637_SendCommand(aj_tm1637_t *tm, uint8_t command){
    TM1637_Start(tm);
    TM1637_WriteByte(tm, command);
    TM1637_Stop(tm);
}

//***************************************
uint8_t AJ_TM1637_SetDisplay(aj_tm1637_t *tm, uint8_t onoff, uint8_t brightness){
    uint8_t error =0;
    uint8_t command_display = TM1637_COMMAND_DISPLAY;

    if ( onoff > 1 ){
        onoff = 1;
        AJ_BitU8_SetBit_Position(error, 0);
    }

    if ( brightness > 0b111 ){
        brightness = 0b111;
        AJ_BitU8_SetBit_Position(error, 1);
    }

    command_display = AJ_BitU8_WriteBit_Position(command_display, 3, onoff);
    command_display = AJ_BitU8_Write3Bit_Position(command_display, 0, brightness);

    TM1637_Start(tm);
    TM1637_WriteByte(tm, command_display);
    TM1637_Stop(tm);

    return error;
}

//***************************************
void AJ_TM1637_ClearDisplay(aj_tm1637_t *tm){
    uint8_t i=0;

    TM1637_Start(tm);
    TM1637_WriteByte(tm, TM1637_COMMAND_DATA_WRITE);
    TM1637_Stop(tm);

    TM1637_Start(tm);
    TM1637_WriteByte(tm, TM1637_COMMAND_ADDRESS);
    for (i=0; i < 6; ++i){
        TM1637_WriteByte(tm, 0x00);
    }
    TM1637_Stop(tm);
}

//***************************************
void AJ_TM1637_Init(aj_tm1637_t *tm){
    AJ_TM1637_CLK_SetIdle(tm);
    AJ_TM1637_DIO_SetIdle(tm);
    AJ_TM1637_DELAY_US(AJ_TM1637_HALF_BIT_US*2);

    AJ_TM1637_ClearDisplay(tm);
    AJ_TM1637_SetDisplay(tm, 1, 7);
}

//***************************************
uint8_t AJ_TM1637_WriteDisplayRegister_AutoIncr(aj_tm1637_t *tm, uint8_t segments[], uint8_t length, uint8_t address){
    uint8_t error = 0;
    uint8_t i=0;
    uint8_t command_address = TM1637_COMMAND_ADDRESS;

    if( address > 5 ){
        address = 5;
        AJ_BitU8_SetBit_Position(error, 0);
    }

    if( length > (6-address) ){
        length = 6 - address;
        AJ_BitU8_SetBit_Position(error, 1);
    }
    else if( length == 0 ){
        length = 1;
        AJ_BitU8_SetBit_Position(error, 2);
    }

    command_address = AJ_BitU8_Write3Bit_Position(command_address, 0, address);

    TM1637_Start(tm);
    TM1637_WriteByte(tm, TM1637_COMMAND_DATA_WRITE);
    TM1637_Stop(tm);

    TM1637_Start(tm);
    TM1637_WriteByte(tm, command_address);
    for (i=0; i < length; ++i){
        TM1637_WriteByte(tm, segments[i]);
    }
    TM1637_Stop(tm);

    return error;
}

//***************************************
uint8_t AJ_TM1637_WriteDisplayRegister_Fixed(aj_tm1637_t *tm, uint8_t data, uint8_t address){
    uint8_t error = 0;
    uint8_t command_address = TM1637_COMMAND_ADDRESS;

    if( address > 5 ){
        address = 5;
        AJ_BitU8_SetBit_Position(error, 0);
    }

    command_address = AJ_BitU8_Write3Bit_Position(command_address, 0, address);

    TM1637_Start(tm);
    TM1637_WriteByte(tm, command_address);
    TM1637_WriteByte(tm, data);
    TM1637_Stop(tm);

    return error;
}
