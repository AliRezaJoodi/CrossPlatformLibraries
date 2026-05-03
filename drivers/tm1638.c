// GitHub Account: GitHub.com/AliRezaJoodi

#include <stdint.h>
#include "hardware.h"   /**< Project-level overrides */
#include "utils/bit.h"
#include "utils/bit_value.h"
#include "tm1638_types.h"
#include "tm1638_port.h"
#include "drivers/tm1638.h"

#define TM1638_COMMAND_DATA_WRITE   0x40U  // Data command setting: Write data to display register
#define TM1638_COMMAND_DATA_READ    0x42U  // Data command setting: Read key scan data
#define TM1638_COMMAND_DISPLAY      0x80U  // Display control
#define TM1638_COMMAND_ADDRESS      0xC0U  // Address command setting

//#define CLK_IDLE            1U
//#define CLK_ACTIVE          0U

//#define DIO_IDLE            1U
//#define DIO_ACTIVE          0U

//#define STB_IDLE            1U
//#define STB_ACTIVE          0U

//***************************************
void TM1638_WriteByte(uint8_t data){
    uint8_t i = 0;

    //TM1638_DIO_Config(TM1638_PIN_OUTPUT);
    TM1638_DIO_ConfigOutput();

    for(i = 0; i < 8; i++) {
        //TM1638_CLK_Write(CLK_ACTIVE);
        TM1638_CLK_SetActive();
        //TM1638_DIO_Write(data & 0x01U);
        if ((data & 0x01U) == 1U){
            TM1638_DIO_SetIdle();
        }
        else{
            TM1638_DIO_SetActive();
        }
        TM1638_DELAY_US(TM1638_BIT_US);
        //TM1638_CLK_Write(CLK_IDLE);
        TM1638_CLK_SetIdle();
        TM1638_DELAY_US(TM1638_BIT_US);
        data = data >> 1;
    }
}

//***************************************
void TM1638_SendCommand(TM1638_t *tm, uint8_t command){
    //TM1638_STB_Write(tm, STB_ACTIVE);
    TM1638_STB_SetActive(tm);
    TM1638_WriteByte(command);
    //TM1638_STB_Write(tm, STB_IDLE);
    TM1638_STB_SetIdle(tm);
    TM1638_DELAY_US(TM1638_BIT_US);
}

//***************************************
uint8_t TM1638_SetDisplay(TM1638_t *tm, uint8_t onoff, uint8_t brightness){
    uint8_t error = 0;
    uint8_t command_display = TM1638_COMMAND_DISPLAY;

    if(onoff > 1){
        onoff = 1;
        SET_BIT(error, 0);
    }

    if(brightness > 0x07U){
        brightness = 0x07U;
        SET_BIT(error, 1);
    }

    command_display = WriteBit_u8(command_display, 3, onoff);
    command_display = WriteBit_u8(command_display, 0, brightness);

    //TM1638_STB_Write(tm, STB_ACTIVE);
    TM1638_STB_SetActive(tm);
    TM1638_WriteByte(command_display);
    //TM1638_STB_Write(tm, STB_IDLE);
    TM1638_STB_SetIdle(tm);
    TM1638_DELAY_US(TM1638_BIT_US);

    return error;
}

//***************************************
void TM1638_ClearDisplay(TM1638_t *tm){
    uint8_t i = 0;
    uint8_t command_address = TM1638_COMMAND_ADDRESS;

    //TM1638_STB_Write(tm, STB_ACTIVE);
    TM1638_STB_SetActive(tm);
    TM1638_WriteByte(TM1638_COMMAND_DATA_WRITE);
    //TM1638_STB_Write(tm, STB_IDLE);
    TM1638_STB_SetIdle(tm);
    TM1638_DELAY_US(TM1638_BIT_US);

	//TM1638_STB_Write(tm, STB_ACTIVE);
    TM1638_STB_SetActive(tm);
	TM1638_WriteByte(command_address);
	for(i=0; i<16; ++i){TM1638_WriteByte(0x00);}
	//TM1638_STB_Write(tm, STB_IDLE);
    TM1638_STB_SetIdle(tm);
    TM1638_DELAY_US(TM1638_BIT_US);
}

//***************************************
void TM1638_Init(TM1638_t *tm){
    //TM1638_STB_Init(tm);
    TM1638_STB_ConfigOutput(tm);
    //TM1638_STB_Write(tm, STB_IDLE);
    TM1638_STB_SetIdle(tm);

    //TM1638_CLK_Init();
    TM1638_CLK_ConfigOutput();
    //TM1638_CLK_Write(CLK_IDLE);
    TM1638_CLK_SetIdle();

    //TM1638_DIO_Config(TM1638_PIN_OUTPUT);
    TM1638_DIO_ConfigOutput();
    //TM1638_DIO_Write(DIO_IDLE);
    TM1638_DIO_SetIdle();

    TM1638_ClearDisplay(tm);
    TM1638_SetDisplay(tm, 1, 7);
}

//***************************************
uint8_t TM1638_WriteDisplayRegister_AutoIncr(TM1638_t *tm, uint8_t segments[], uint8_t length, uint8_t address){
    uint8_t error = 0;
    uint8_t i = 0;
    uint8_t command_address = TM1638_COMMAND_ADDRESS;

    if(address > 15){
        address = 15;
        SET_BIT(error, 0);
    }

    if(length > (16-address)){
        length = 16 - address;
        SET_BIT(error, 1);
    }
    else if(length == 0){
        length = 1;
        SET_BIT(error, 2);
    }

    //WRITE_4BIT(command_address, 0, address);
    command_address = Write4Bit_u8(command_address, 0, address);

    //TM1638_STB_Write(tm, STB_ACTIVE);
    TM1638_STB_SetActive(tm);
    TM1638_WriteByte(TM1638_COMMAND_DATA_WRITE);
    //TM1638_STB_Write(tm, STB_IDLE);
    TM1638_STB_SetIdle(tm);
    TM1638_DELAY_US(TM1638_BIT_US);

	//TM1638_STB_Write(tm, STB_ACTIVE);
    TM1638_STB_SetActive(tm);
	TM1638_WriteByte(command_address);

	for (i=0; i < length; ++i){
	    TM1638_WriteByte(segments[i]);
    }

	//TM1638_STB_Write(tm, STB_IDLE);
    TM1638_STB_SetIdle(tm);
    TM1638_DELAY_US(TM1638_BIT_US);

    return error;
}

//***************************************
uint8_t TM1638_WriteDisplayRegister_Fixed(TM1638_t *tm, uint8_t data, uint8_t address){
    uint8_t error = 0;
    uint8_t command_address = TM1638_COMMAND_ADDRESS;

    if(address > 15){
        address = 15;
        SET_BIT(error, 0);
    }

    //WRITE_4BIT(command_address, 0, address);
    command_address = Write4Bit_u8(command_address, 0, address);

    //TM1638_STB_Write(tm, STB_ACTIVE);
    TM1638_STB_SetActive(tm);
    TM1638_WriteByte(TM1638_COMMAND_DATA_WRITE);
    //TM1638_STB_Write(tm, STB_IDLE);
    TM1638_STB_SetIdle(tm);
    TM1638_DELAY_US(TM1638_BIT_US);

	//TM1638_STB_Write(tm, STB_ACTIVE);
    TM1638_STB_SetActive(tm);
	TM1638_WriteByte(command_address);
    TM1638_DELAY_US(TM1638_BIT_US);
	TM1638_WriteByte(data);
	//TM1638_STB_Write(tm, STB_IDLE);
    TM1638_STB_SetIdle(tm);
    TM1638_DELAY_US(TM1638_BIT_US);

    return error;
};

//***************************************
uint8_t TM1637_WriteDigits(TM1638_t *tm, uint8_t segments[], uint8_t length, uint8_t pos){
    uint8_t error = 0;
    uint8_t address = 0;
    uint8_t i=0;

    if(pos > 7){
        pos = 7;
        SET_BIT(error, 0);
    }

    if(length > (8-pos)){
        length = 8 - pos;
        SET_BIT(error, 1);
    }
    else if(length == 0){
        length = 1;
        SET_BIT(error, 2);
    }

    address = pos * 2;

    for(i=0; i<length; ++i){
        TM1638_WriteDisplayRegister_Fixed(tm, segments[i], address);
        address = address + 2;
    }

    return error;
}

//***************************************
void TM1637_Write4Digits_G1G4(TM1638_t *tm, uint8_t segments[]){
    uint8_t i = 0;

    for(i=0; i<4; ++i){
        TM1638_WriteDisplayRegister_Fixed(tm, segments[i], i*2);
    }

//    TM1638_WriteDisplayRegister_Fixed(tm, segments[0], 0);
//    TM1638_WriteDisplayRegister_Fixed(tm, segments[1], 2);
//    TM1638_WriteDisplayRegister_Fixed(tm, segments[2], 4);
//    TM1638_WriteDisplayRegister_Fixed(tm, segments[3], 6);
}

//***************************************
void TM1637_Write4Digits_G5G8(TM1638_t *tm, uint8_t segments[]){
    uint8_t i = 0;

    for(i=0; i<4; ++i){
        TM1638_WriteDisplayRegister_Fixed(tm, segments[i], (i+4)*2);
    }

//    TM1638_WriteDisplayRegister_Fixed(tm, segments[0], 8);
//    TM1638_WriteDisplayRegister_Fixed(tm, segments[1], 10);
//    TM1638_WriteDisplayRegister_Fixed(tm, segments[2], 12);
//    TM1638_WriteDisplayRegister_Fixed(tm, segments[3], 14);
}

//***************************************
void TM1638_Set8Leds_S9S10x4(TM1638_t *tm, uint8_t data){
    uint8_t i = 0;

    for(i=0; i<=3; ++i){
        TM1638_WriteDisplayRegister_Fixed(tm, GET_2BIT(data, i*2), (i*2)+1);
    }

//    TM1638_WriteDisplayRegister_Fixed(tm, GET_2BIT(data, 0), 1);
//    TM1638_WriteDisplayRegister_Fixed(tm, GET_2BIT(data, 2), 3);
//    TM1638_WriteDisplayRegister_Fixed(tm, GET_2BIT(data, 4), 5);
//    TM1638_WriteDisplayRegister_Fixed(tm, GET_2BIT(data, 6), 7);
}

//***************************************
void TM1638_Set8Leds_S9x8(TM1638_t *tm, uint8_t data){
    uint8_t i = 0;

    for(i=0; i<=7; ++i){
        TM1638_WriteDisplayRegister_Fixed(tm, GET_BIT(data, i), (i*2)+1);
    }

//    TM1638_WriteDisplayRegister_Fixed(tm, GET_BIT(data, 0), 1);
//    TM1638_WriteDisplayRegister_Fixed(tm, GET_BIT(data, 1), 3);
//    TM1638_WriteDisplayRegister_Fixed(tm, GET_BIT(data, 2), 5);
//    TM1638_WriteDisplayRegister_Fixed(tm, GET_BIT(data, 3), 7);
//    TM1638_WriteDisplayRegister_Fixed(tm, GET_BIT(data, 4), 9);
//    TM1638_WriteDisplayRegister_Fixed(tm, GET_BIT(data, 5), 11);
//    TM1638_WriteDisplayRegister_Fixed(tm, GET_BIT(data, 6), 13);
//    TM1638_WriteDisplayRegister_Fixed(tm, GET_BIT(data, 7), 15);
}

//***************************************
void TM1638_SetLeds(TM1638_t *tm, uint16_t data){
    uint8_t i = 0;

    for(i=0; i<=7; ++i){
        TM1638_WriteDisplayRegister_Fixed(tm, GET_2BIT(data, i*2), (i*2)+1);
    }

//    TM1638_WriteDisplayRegister_Fixed(tm, GET_2BIT(data, 0), 1);
//    TM1638_WriteDisplayRegister_Fixed(tm, GET_2BIT(data, 2), 3);
//    TM1638_WriteDisplayRegister_Fixed(tm, GET_2BIT(data, 4), 5);
//    TM1638_WriteDisplayRegister_Fixed(tm, GET_2BIT(data, 6), 7);
//    TM1638_WriteDisplayRegister_Fixed(tm, GET_2BIT(data, 8), 9);
//    TM1638_WriteDisplayRegister_Fixed(tm, GET_2BIT(data, 10), 11);
//    TM1638_WriteDisplayRegister_Fixed(tm, GET_2BIT(data, 12), 13);
//    TM1638_WriteDisplayRegister_Fixed(tm, GET_2BIT(data, 14), 15);
}

//***************************************
uint8_t TM1638_ReadByte(void){
    uint8_t i = 0;
    uint8_t data = 0;
    uint8_t buf = 0;

    //TM1638_DIO_Config(TM1638_PIN_INPUT);
    TM1638_DIO_ConfigInput();

    for(i=0; i<8; ++i) {
        //TM1638_CLK_Write(0);
        TM1638_CLK_SetActive();
        TM1638_DELAY_US(TM1638_BIT_US);
        //TM1638_CLK_Write(1);
        TM1638_CLK_SetIdle();
        TM1638_DELAY_US(TM1638_BIT_US);

        buf = TM1638_DIO_Read();
        WRITE_BIT(data, i, buf);

        //TM1638_DELAY_US(TM1638_BIT_US);
    }

    return data;
}

//***************************************
void TM1638_GetKeys(TM1638_t *tm, uint8_t *key){
    uint8_t i = 0;

    //TM1638_STB_Write(tm, STB_ACTIVE);
    TM1638_STB_SetActive(tm);
    TM1638_WriteByte(TM1638_COMMAND_DATA_READ);
    //TM1638_DIO_Config(TM1638_PIN_INPUT);
    TM1638_DIO_ConfigInput();
    TM1638_DELAY_US(TM1638_BIT_US*2);  // Twait

    for (i=0; i<4; ++i){
        TM1638_DELAY_US(TM1638_BIT_US);
	    *(key + i) = TM1638_ReadByte();
    }

    TM1638_DELAY_US(TM1638_BIT_US*2);
    //TM1638_STB_Write(tm, STB_IDLE);
    TM1638_STB_SetIdle(tm);
    TM1638_DELAY_US(TM1638_BIT_US*2);
    //TM1638_DIO_Config(TM1638_PIN_OUTPUT);
    TM1638_DIO_ConfigOutput();
    //TM1638_DIO_Write(DIO_IDLE);
    TM1638_DIO_SetIdle();
}

//***************************************
uint8_t TM1638_GetKeys_K3(TM1638_t *tm){
    uint8_t i = 0;
    uint8_t data = 0;
    uint8_t buf = 0;

    //TM1638_STB_Write(tm, STB_ACTIVE);
    TM1638_STB_SetActive(tm);
    TM1638_WriteByte(TM1638_COMMAND_DATA_READ);
    //TM1638_DIO_Config(TM1638_PIN_INPUT);
    TM1638_DIO_ConfigInput();
    TM1638_DELAY_US(TM1638_BIT_US*2);  // Twait

    for (i=0; i<4; ++i){
        TM1638_DELAY_US(TM1638_BIT_US);
	    buf = TM1638_ReadByte();
        data = data | (buf<<i);
    }

    TM1638_DELAY_US(TM1638_BIT_US*2);
    //TM1638_STB_Write(tm, STB_IDLE);
    TM1638_STB_SetIdle(tm);
    TM1638_DELAY_US(TM1638_BIT_US*2);
    //TM1638_DIO_Config(TM1638_PIN_OUTPUT);
    TM1638_DIO_ConfigOutput();
    //TM1638_DIO_Write(DIO_IDLE);
    TM1638_DIO_SetIdle();

    return data;
}