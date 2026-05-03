// GitHub Account: GitHub.com/AliRezaJoodi

#include <stdint.h>
#include "hardware.h"
#include "utils/bit_value.h"
#include "tm1637_port.h"
#include "drivers/tm1637.h"

#define TM1637_COMMAND_DATA_WRITE   0x40U   // Data command setting: Write data to display register
#define TM1637_COMMAND_DATA_READ    0x42U   // Data command setting: Read key scan data
#define TM1637_COMMAND_ADDRESS      0xC0U   // Address command setting
#define TM1637_COMMAND_DISPLAY      0x80U   // Display control

//#define CLK_IDLE            1U
//#define CLK_ACTIVE          0U

//#define DIO_IDLE            1U
//#define DIO_ACTIVE          0U

//***************************************
void TM1637_Start(TM1637_t *tm){
    //TM1637_CLK_Write(tm, CLK_IDLE);
    TM1637_CLK_SetIdle(tm);
    //TM1637_DIO_Write(tm, DIO_IDLE);
    TM1637_DIO_SetIdle(tm);
    TM1637_DELAY_US(TM1637_HALF_BIT_US*2);

    //TM1637_DIO_Write(tm, DIO_ACTIVE);
    TM1637_DIO_SetActive(tm);
    TM1637_DELAY_US(TM1637_HALF_BIT_US*2);
}

//***************************************
void TM1637_Stop(TM1637_t *tm){
    //TM1637_DIO_Write(tm, DIO_ACTIVE);
    TM1637_DIO_SetActive(tm);
    //TM1637_CLK_Write(tm, CLK_IDLE);
    TM1637_CLK_SetIdle(tm);
    TM1637_DELAY_US(TM1637_HALF_BIT_US*2);

    //TM1637_DIO_Write(tm, DIO_IDLE);
    TM1637_DIO_SetIdle(tm);
    TM1637_DELAY_US(TM1637_HALF_BIT_US*2);
}

//***************************************
uint8_t TM1637_WriteByte(TM1637_t *tm, uint8_t data){
    uint8_t i = 0;
    uint8_t ack = 0;

    for(i = 0; i < 8; i++) {
        //TM1637_CLK_Write(tm, CLK_ACTIVE);
        TM1637_CLK_SetActive(tm);
        TM1637_DELAY_US(TM1637_HALF_BIT_US);

        if (data & 0x01){
            TM1637_DIO_SetIdle(tm);
        }
        else{
            TM1637_DIO_SetActive(tm);
        }
        //TM1637_DIO_Write(tm, data & 0x01);
        TM1637_DELAY_US(TM1637_HALF_BIT_US);

        //TM1637_CLK_Write(tm, CLK_IDLE);
        TM1637_CLK_SetIdle(tm);
        TM1637_DELAY_US(TM1637_HALF_BIT_US*2);

        data = data >> 1;
    }

    //TM1637_CLK_Write(tm, CLK_ACTIVE);
    TM1637_CLK_SetActive(tm);
    TM1637_DIO_ConfigInput(tm);
    TM1637_DELAY_US(TM1637_HALF_BIT_US*4);

    //TM1637_CLK_Write(tm, CLK_IDLE);
    TM1637_CLK_SetIdle(tm);
    TM1637_DELAY_US(TM1637_HALF_BIT_US*2);
    ack = TM1637_DIO_Read(tm);
//    if(ack == 0){
//        TM1637_DIO_Write(tm, DIO_ACTIVE);       // check this line
//    }
    //TM1637_CLK_Write(tm, CLK_ACTIVE);
    TM1637_CLK_SetActive(tm);
    TM1637_DELAY_US(TM1637_HALF_BIT_US*2);

    return ack;
}

//***************************************
void TM1637_SendCommand(TM1637_t *tm, uint8_t command){
    TM1637_Start(tm);
    TM1637_WriteByte(tm, command);
    TM1637_Stop(tm);
}

//***************************************
uint8_t TM1637_SetDisplay(TM1637_t *tm, uint8_t onoff, uint8_t brightness){
    uint8_t error =0;
    uint8_t command_display = TM1637_COMMAND_DISPLAY;

    if ( onoff > 1 ){
        onoff = 1;
        SetBit_u8(error, 0);
    }

    if ( brightness > 0b111 ){
        brightness = 0b111;
        SetBit_u8(error, 1);
    }

    command_display = WriteBit_u8(command_display, 3, onoff);
    command_display = Write3Bit_u8(command_display, 0, brightness);

    TM1637_Start(tm);
    TM1637_WriteByte(tm, command_display);
    TM1637_Stop(tm);

    return error;
}

//***************************************
void TM1637_ClearDisplay(TM1637_t *tm){
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
void TM1637_Init(TM1637_t *tm){
    //TM1637_CLK_Write(tm, CLK_IDLE);
    TM1637_CLK_SetIdle(tm);
    //TM1637_DIO_Write(tm, DIO_IDLE);
    TM1637_DIO_SetIdle(tm);
    TM1637_DELAY_US(TM1637_HALF_BIT_US*2);

    TM1637_ClearDisplay(tm);
    TM1637_SetDisplay(tm, 1, 7);
}

//***************************************
uint8_t TM1637_WriteDisplayRegister_AutoIncr(TM1637_t *tm, uint8_t segments[], uint8_t length, uint8_t address){
    uint8_t error = 0;
    uint8_t i=0;
    uint8_t command_address = TM1637_COMMAND_ADDRESS;

    if( address > 5 ){
        address = 5;
        SetBit_u8(error, 0);
    }

    if( length > (6-address) ){
        length = 6 - address;
        SetBit_u8(error, 1);
    }
    else if( length == 0 ){
        length = 1;
        SetBit_u8(error, 2);
    }

    command_address = Write3Bit_u8(command_address, 0, address);

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
uint8_t TM1637_WriteDisplayRegister_Fixed(TM1637_t *tm, uint8_t data, uint8_t address){
    uint8_t error = 0;
    uint8_t command_address = TM1637_COMMAND_ADDRESS;

    if( address > 5 ){
        address = 5;
        SetBit_u8(error, 0);
    }

    command_address = Write3Bit_u8(command_address, 0, address);

    TM1637_Start(tm);
    TM1637_WriteByte(tm, command_address);
    TM1637_WriteByte(tm, data);
    TM1637_Stop(tm);

    return error;
}
