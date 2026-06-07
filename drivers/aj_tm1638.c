// GitHub Account: GitHub.com/AliRezaJoodi

#include <stdint.h>
#include "aj_bit_u8.h"
#include "aj_tm1638_type.h"
#include "aj_tm1638_port.h"
#include "aj_tm1638.h"

#define TM1638_COMMAND_DATA_WRITE   0x40U  // Data command setting: Write data to display register
#define TM1638_COMMAND_DATA_READ    0x42U  // Data command setting: Read key scan data
#define TM1638_COMMAND_DISPLAY      0x80U  // Display control
#define TM1638_COMMAND_ADDRESS      0xC0U  // Address command setting

//***************************************
void TM1638_WriteByte(uint8_t data){
    uint8_t i = 0;

    AJ_TM1638_DIO_ConfigAsOutput();

    for(i = 0; i < 8; i++) {
        AJ_TM1638_CLK_SetActive();
        if ((data & 0x01U) == 1U){
            AJ_TM1638_DIO_SetIdle();
        }
        else{
            AJ_TM1638_DIO_SetActive();
        }
        AJ_TM1638_DELAY_US(AJ_TM1638_BIT_US);
        AJ_TM1638_CLK_SetIdle();
        AJ_TM1638_DELAY_US(AJ_TM1638_BIT_US);
        data = data >> 1;
    }
}

//***************************************
void AJ_TM1638_SendCommand(aj_tm1638_t *tm, uint8_t command){
    AJ_TM1638_STB_SetActive(tm);
    TM1638_WriteByte(command);
    AJ_TM1638_STB_SetIdle(tm);
    AJ_TM1638_DELAY_US(AJ_TM1638_BIT_US);
}

//***************************************
uint8_t AJ_TM1638_SetDisplay(aj_tm1638_t *tm, uint8_t onoff, uint8_t brightness){
    uint8_t error = 0;
    uint8_t command_display = TM1638_COMMAND_DISPLAY;

    if(onoff > 1){
        onoff = 1;
        AJ_BitU8_SetBit_Position(error, 0);
    }

    if(brightness > 0x07U){
        brightness = 0x07U;
        AJ_BitU8_SetBit_Position(error, 1);
    }

    command_display = AJ_BitU8_WriteBit_Position(command_display, 3, onoff);
    command_display = AJ_BitU8_WriteBit_Position(command_display, 0, brightness);

    AJ_TM1638_STB_SetActive(tm);
    TM1638_WriteByte(command_display);
    AJ_TM1638_STB_SetIdle(tm);
    AJ_TM1638_DELAY_US(AJ_TM1638_BIT_US);

    return error;
}

//***************************************
void AJ_TM1638_ClearDisplay(aj_tm1638_t *tm){
    uint8_t i = 0;
    uint8_t command_address = TM1638_COMMAND_ADDRESS;

    AJ_TM1638_STB_SetActive(tm);
    TM1638_WriteByte(TM1638_COMMAND_DATA_WRITE);
    AJ_TM1638_STB_SetIdle(tm);
    AJ_TM1638_DELAY_US(AJ_TM1638_BIT_US);

    AJ_TM1638_STB_SetActive(tm);
	TM1638_WriteByte(command_address);
	for(i=0; i<16; ++i){TM1638_WriteByte(0x00);}
    AJ_TM1638_STB_SetIdle(tm);
    AJ_TM1638_DELAY_US(AJ_TM1638_BIT_US);
}

//***************************************
void AJ_TM1638_Init(aj_tm1638_t *tm){
    AJ_TM1638_STB_ConfigAsOutput(tm);
    AJ_TM1638_STB_SetIdle(tm);

    AJ_TM1638_CLK_ConfigAsOutput();
    AJ_TM1638_CLK_SetIdle();

    AJ_TM1638_DIO_ConfigAsOutput();
    AJ_TM1638_DIO_SetIdle();

    AJ_TM1638_ClearDisplay(tm);
    AJ_TM1638_SetDisplay(tm, 1, 7);
}

//***************************************
uint8_t AJ_TM1638_WriteDisplayRegister_AutoIncr(aj_tm1638_t *tm, uint8_t segments[], uint8_t length, uint8_t address){
    uint8_t error = 0;
    uint8_t i = 0;
    uint8_t command_address = TM1638_COMMAND_ADDRESS;

    if(address > 15){
        address = 15;
        AJ_BitU8_SetBit_Position(error, 0);
    }

    if(length > (16-address)){
        length = 16 - address;
        AJ_BitU8_SetBit_Position(error, 1);
    }
    else if(length == 0){
        length = 1;
        AJ_BitU8_SetBit_Position(error, 2);
    }

    command_address = AJ_BitU8_Write4Bits_Position(command_address, 0, address);

    AJ_TM1638_STB_SetActive(tm);
    TM1638_WriteByte(TM1638_COMMAND_DATA_WRITE);
    AJ_TM1638_STB_SetIdle(tm);
    AJ_TM1638_DELAY_US(AJ_TM1638_BIT_US);

    AJ_TM1638_STB_SetActive(tm);
	TM1638_WriteByte(command_address);

	for (i=0; i < length; ++i){
	    TM1638_WriteByte(segments[i]);
    }

    AJ_TM1638_STB_SetIdle(tm);
    AJ_TM1638_DELAY_US(AJ_TM1638_BIT_US);

    return error;
}

//***************************************
uint8_t AJ_TM1638_WriteDisplayRegister_Fixed(aj_tm1638_t *tm, uint8_t data, uint8_t address){
    uint8_t error = 0;
    uint8_t command_address = TM1638_COMMAND_ADDRESS;

    if(address > 15){
        address = 15;
        AJ_BitU8_SetBit_Position(error, 0);
    }

    command_address = AJ_BitU8_Write4Bits_Position(command_address, 0, address);

    AJ_TM1638_STB_SetActive(tm);
    TM1638_WriteByte(TM1638_COMMAND_DATA_WRITE);
    AJ_TM1638_STB_SetIdle(tm);
    AJ_TM1638_DELAY_US(AJ_TM1638_BIT_US);

    AJ_TM1638_STB_SetActive(tm);
	TM1638_WriteByte(command_address);
    AJ_TM1638_DELAY_US(AJ_TM1638_BIT_US);
	TM1638_WriteByte(data);
    AJ_TM1638_STB_SetIdle(tm);
    AJ_TM1638_DELAY_US(AJ_TM1638_BIT_US);

    return error;
};

//***************************************
uint8_t AJ_TM1637_WriteDigits(aj_tm1638_t *tm, uint8_t segments[], uint8_t length, uint8_t pos){
    uint8_t error = 0;
    uint8_t address = 0;
    uint8_t i=0;

    if(pos > 7){
        pos = 7;
        AJ_BitU8_SetBit_Position(error, 0);
    }

    if(length > (8-pos)){
        length = 8 - pos;
        AJ_BitU8_SetBit_Position(error, 1);
    }
    else if(length == 0){
        length = 1;
        AJ_BitU8_SetBit_Position(error, 2);
    }

    address = pos * 2;

    for(i=0; i<length; ++i){
        AJ_TM1638_WriteDisplayRegister_Fixed(tm, segments[i], address);
        address = address + 2;
    }

    return error;
}

//***************************************
void AJ_TM1637_Write4Digits_G1G4(aj_tm1638_t *tm, uint8_t segments[]){
    uint8_t i = 0;

    for(i=0; i<4; ++i){
        AJ_TM1638_WriteDisplayRegister_Fixed(tm, segments[i], i*2);
    }

//    AJ_TM1638_WriteDisplayRegister_Fixed(tm, segments[0], 0);
//    AJ_TM1638_WriteDisplayRegister_Fixed(tm, segments[1], 2);
//    AJ_TM1638_WriteDisplayRegister_Fixed(tm, segments[2], 4);
//    AJ_TM1638_WriteDisplayRegister_Fixed(tm, segments[3], 6);
}

//***************************************
void AJ_TM1637_Write4Digits_G5G8(aj_tm1638_t *tm, uint8_t segments[]){
    uint8_t i = 0;

    for(i=0; i<4; ++i){
        AJ_TM1638_WriteDisplayRegister_Fixed(tm, segments[i], (i+4)*2);
    }

//    AJ_TM1638_WriteDisplayRegister_Fixed(tm, segments[0], 8);
//    AJ_TM1638_WriteDisplayRegister_Fixed(tm, segments[1], 10);
//    AJ_TM1638_WriteDisplayRegister_Fixed(tm, segments[2], 12);
//    AJ_TM1638_WriteDisplayRegister_Fixed(tm, segments[3], 14);
}

//***************************************
void AJ_TM1638_Set8Leds_S9S10x4(aj_tm1638_t *tm, uint8_t data){
    uint8_t i = 0;

    for(i=0; i<=3; ++i){
        AJ_TM1638_WriteDisplayRegister_Fixed(tm, AJ_BitU8_Get2Bits_Position(data, i*2), (i*2)+1);
    }

//    AJ_TM1638_WriteDisplayRegister_Fixed(tm, GET_2BIT(data, 0), 1);
//    AJ_TM1638_WriteDisplayRegister_Fixed(tm, GET_2BIT(data, 2), 3);
//    AJ_TM1638_WriteDisplayRegister_Fixed(tm, GET_2BIT(data, 4), 5);
//    AJ_TM1638_WriteDisplayRegister_Fixed(tm, GET_2BIT(data, 6), 7);
}

//***************************************
void AJ_TM1638_Set8Leds_S9x8(aj_tm1638_t *tm, uint8_t data){
    uint8_t i = 0;

    for(i=0; i<=7; ++i){
        AJ_TM1638_WriteDisplayRegister_Fixed(tm, AJ_BitU8_IsBitSet_Position(data, i), (i*2)+1);
    }

//    AJ_TM1638_WriteDisplayRegister_Fixed(tm, GET_BIT(data, 0), 1);
//    AJ_TM1638_WriteDisplayRegister_Fixed(tm, GET_BIT(data, 1), 3);
//    AJ_TM1638_WriteDisplayRegister_Fixed(tm, GET_BIT(data, 2), 5);
//    AJ_TM1638_WriteDisplayRegister_Fixed(tm, GET_BIT(data, 3), 7);
//    AJ_TM1638_WriteDisplayRegister_Fixed(tm, GET_BIT(data, 4), 9);
//    AJ_TM1638_WriteDisplayRegister_Fixed(tm, GET_BIT(data, 5), 11);
//    AJ_TM1638_WriteDisplayRegister_Fixed(tm, GET_BIT(data, 6), 13);
//    AJ_TM1638_WriteDisplayRegister_Fixed(tm, GET_BIT(data, 7), 15);
}

//***************************************
void AJ_TM1638_SetLeds(aj_tm1638_t *tm, uint16_t data){
    uint8_t i = 0;

    for(i=0; i<=7; ++i){
        AJ_TM1638_WriteDisplayRegister_Fixed(tm, AJ_BitU8_Get2Bits_Position(data, i*2), (i*2)+1);
    }

//    AJ_TM1638_WriteDisplayRegister_Fixed(tm, GET_2BIT(data, 0), 1);
//    AJ_TM1638_WriteDisplayRegister_Fixed(tm, GET_2BIT(data, 2), 3);
//    AJ_TM1638_WriteDisplayRegister_Fixed(tm, GET_2BIT(data, 4), 5);
//    AJ_TM1638_WriteDisplayRegister_Fixed(tm, GET_2BIT(data, 6), 7);
//    AJ_TM1638_WriteDisplayRegister_Fixed(tm, GET_2BIT(data, 8), 9);
//    AJ_TM1638_WriteDisplayRegister_Fixed(tm, GET_2BIT(data, 10), 11);
//    AJ_TM1638_WriteDisplayRegister_Fixed(tm, GET_2BIT(data, 12), 13);
//    AJ_TM1638_WriteDisplayRegister_Fixed(tm, GET_2BIT(data, 14), 15);
}

//***************************************
uint8_t TM1638_ReadByte(void){
    uint8_t i = 0;
    uint8_t data = 0;
    uint8_t buf = 0;

    AJ_TM1638_DIO_ConfigAsInput();

    for(i=0; i<8; ++i) {
        AJ_TM1638_CLK_SetActive();
        AJ_TM1638_DELAY_US(AJ_TM1638_BIT_US);
        AJ_TM1638_CLK_SetIdle();
        AJ_TM1638_DELAY_US(AJ_TM1638_BIT_US);

        buf = AJ_TM1638_DIO_Read();
        AJ_BitU8_WriteBit_Position(data, i, buf);
    }

    return data;
}

//***************************************
void AJ_TM1638_GetKeys(aj_tm1638_t *tm, uint8_t *key){
    uint8_t i = 0;

    AJ_TM1638_STB_SetActive(tm);
    TM1638_WriteByte(TM1638_COMMAND_DATA_READ);
    AJ_TM1638_DIO_ConfigAsInput();
    AJ_TM1638_DELAY_US(AJ_TM1638_BIT_US*2);  // Twait

    for (i=0; i<4; ++i){
        AJ_TM1638_DELAY_US(AJ_TM1638_BIT_US);
	    *(key + i) = TM1638_ReadByte();
    }

    AJ_TM1638_DELAY_US(AJ_TM1638_BIT_US*2);
    AJ_TM1638_STB_SetIdle(tm);
    AJ_TM1638_DELAY_US(AJ_TM1638_BIT_US*2);
    AJ_TM1638_DIO_ConfigAsOutput();
    AJ_TM1638_DIO_SetIdle();
}

//***************************************
uint8_t AJ_TM1638_GetKeys_K3(aj_tm1638_t *tm){
    uint8_t i = 0;
    uint8_t data = 0;
    uint8_t buf = 0;

    AJ_TM1638_STB_SetActive(tm);
    TM1638_WriteByte(TM1638_COMMAND_DATA_READ);
    AJ_TM1638_DIO_ConfigAsInput();
    AJ_TM1638_DELAY_US(AJ_TM1638_BIT_US*2);  // Twait

    for (i=0; i<4; ++i){
        AJ_TM1638_DELAY_US(AJ_TM1638_BIT_US);
	    buf = TM1638_ReadByte();
        data = data | (buf<<i);
    }

    AJ_TM1638_DELAY_US(AJ_TM1638_BIT_US*2);
    AJ_TM1638_STB_SetIdle(tm);
    AJ_TM1638_DELAY_US(AJ_TM1638_BIT_US*2);
    AJ_TM1638_DIO_ConfigAsOutput();
    AJ_TM1638_DIO_SetIdle();

    return data;
}