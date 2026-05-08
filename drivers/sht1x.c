// GitHub Account: GitHub.com/AliRezaJoodi

#include <stdio.h>
#include <stdlib.h>

#include "hardware.h"
#include "sht1x.h"

#define SCK_IDLE                    0U
#define SCK_ACTIVE                  1U
#define DATA_IDLE                   1U



#if   (SHT1X_VDD == SHT1X_VDD_5V)
    #define SHT1X_D1   ((int32_t)(-40.1f * 100.0f))
#elif (SHT1X_VDD == SHT1X_VDD_4V)
    #define SHT1X_D1   ((int32_t)(-39.8f * 100.0f))
#elif (SHT1X_VDD == SHT1X_VDD_3V5)
    #define SHT1X_D1   ((int32_t)(-39.7f * 100.0f))
#elif (SHT1X_VDD == SHT1X_VDD_3V)
    #define SHT1X_D1   ((int32_t)(-39.6f * 100.0f))
#elif (SHT1X_VDD == SHT1X_VDD_2V5)
    #define SHT1X_D1   ((int32_t)(-39.4f * 100.0f))
#else
    #error "Invalid SHT1X_VDD selection!"
#endif

#define SHT1X_D2_14BIT      ((int32_t)(0.01f * 100.0f))
#define SHT1X_D2_12BIT      ((int32_t)(0.04f * 100.0f))

//DATA = 1
//SCK = 1
//DATA = 0
//SCK = 0
//SCK = 1
//DATA = 1
//SCK = 0

//***************************************
static void StartTransmission(SHT1x_t *sht){
    SHT1x_DATA_WritePin(sht, 1);
    SHT1x_SCK_WritePin(sht, SCK_ACTIVE);
    SHT1X_DELAY_MIN();

    SHT1x_DATA_WritePin(sht, 0);
    SHT1X_DELAY_MIN();

    SHT1x_SCK_WritePin(sht, SCK_IDLE);
    SHT1X_DELAY_MIN();

    SHT1x_SCK_WritePin(sht, SCK_ACTIVE);
    SHT1X_DELAY_MIN();

    SHT1x_DATA_WritePin(sht, 1);
    SHT1X_DELAY_MIN();

    SHT1x_SCK_WritePin(sht, SCK_IDLE);
    SHT1X_DELAY_MIN();
}

//****************************************************
void SHT1x_ResetConnection(SHT1x_t *sht){
    uint8_t i = 0;

    SHT1x_DATA_WritePin(sht, DATA_IDLE);
    SHT1x_SCK_WritePin(sht, SCK_IDLE);
    SHT1X_DELAY_MIN();

    for(i = 0; i < 9; i++) {
        SHT1x_SCK_WritePin(sht, SCK_ACTIVE);
        SHT1X_DELAY_MIN();
        SHT1x_SCK_WritePin(sht, SCK_IDLE);
        SHT1X_DELAY_MIN();
    }

    StartTransmission(sht);
}

//****************************************************
static void WriteByte(SHT1x_t *sht, uint8_t command){
    ///int8_t i = 7;
    uint8_t i = 0;

    SHT1x_SCK_WritePin(sht, SCK_IDLE);
    //SHT1X_DELAY_MIN();

    ///for(i = 7; i >= 0; --i){
    for(i = 0; i <= 7; ++i){
        SHT1x_DATA_WritePin(sht, GET_BIT(command, 7 - i));
        SHT1X_DELAY_MIN();

        SHT1x_SCK_WritePin(sht, SCK_ACTIVE);
        SHT1X_DELAY_MIN();

        SHT1x_SCK_WritePin(sht, SCK_IDLE);
        SHT1X_DELAY_MIN();
    }

    ///SHT1x_DATA_SetInput(sht);
}

//****************************************************
static uint8_t ReadByte(SHT1x_t *sht){
    uint8_t i = 0;
    uint8_t value = 0;

    SHT1x_DATA_SetInput(sht);
    SHT1x_SCK_WritePin(sht, SCK_IDLE);
    SHT1X_DELAY_MIN();

    for(i = 0; i <= 7; ++i){
        SHT1x_SCK_WritePin(sht, SCK_ACTIVE);
        SHT1X_DELAY_MIN();

        value <<= 1;
        if(SHT1x_DATA_GetPin(sht)){
            value |= 1;
        }

        SHT1x_SCK_WritePin(sht, SCK_IDLE);
        SHT1X_DELAY_MIN();
    }

    return value;
}

//****************************************************
static uint8_t GetAck(SHT1x_t *sht){
    uint8_t ack = 1;

    SHT1x_DATA_SetInput(sht);
    ///SHT1X_DELAY_MIN();

    SHT1x_SCK_WritePin(sht, SCK_ACTIVE);
    SHT1X_DELAY_MIN();
    //SHT1X_DELAY_US(2);

    ack = SHT1x_DATA_GetPin(sht);

    SHT1x_SCK_WritePin(sht, SCK_IDLE);
    SHT1X_DELAY_MIN();

    return ack;
}

//****************************************************
static void SendAck(SHT1x_t *sht, uint8_t ack){
    SHT1x_DATA_WritePin(sht, ack);
    SHT1X_DELAY_MIN();

    SHT1x_SCK_WritePin(sht, SCK_ACTIVE);
    SHT1X_DELAY_MIN();

    SHT1x_SCK_WritePin(sht, SCK_IDLE);
    SHT1X_DELAY_MIN();
}

//***************************************
void SHT1x_SoftReset(SHT1x_t *sht){
    StartTransmission(sht);
    WriteByte(sht, CMD_SOFT_RESET);
    SHT1X_DELAY_MS(11);
}

//***************************************
void SHT1x_Init(SHT1x_t *sht){
    SHT1x_SCK_InitPin(sht);
    SHT1x_SCK_WritePin(sht, SCK_IDLE);

    ///SHT1x_DATA_SetInput(sht);
    SHT1x_DATA_WritePin(sht, DATA_IDLE);

    SHT1x_SoftReset(sht);
}

// CRC-8 Sensirion (SHT1x/SHT7x family)
//****************************************************
static uint8_t CalculateCRC8(uint8_t crc, uint8_t data){
    uint8_t i = 0;

    crc ^= data;

    for (i = 0; i < 8; ++i) {
        if ((crc & 0x80) == 0x80){
            crc = (crc << 1) ^ 0x31;   // Polynomial = 0x31
        }
        else{
            crc <<= 1;
        }
    }

    return crc;
}

//****************************************************
uint8_t SHT1x_StartMeasurement(SHT1x_t *sht, uint8_t command){
    //uint8_t ack = 1;
    uint16_t timeout = 0;

    StartTransmission(sht);
    WriteByte(sht, command);

    //ack = GetAck(sht); //ack=1;
    if (GetAck(sht) != 0) {
        return 1U;
    }

    while(SHT1x_DATA_GetPin(sht) == 0){
        timeout += 1;
        if (timeout > 100U){
            return 2U;
        }
    }

    return 0;
}

//****************************************************
uint16_t ReadSO(SHT1x_t *sht, uint8_t command){
    uint8_t msb = 0, lsb = 0;
    uint8_t crc8 = 0, crc8_calc = 0;
    uint16_t value = 0;

    msb = ReadByte(sht); SendAck(sht, 0);
    lsb = ReadByte(sht); SendAck(sht, 0);
    crc8 = ReadByte(sht); SendAck(sht, 1);

    crc8_calc = 0x00;
    crc8_calc = CalculateCRC8(crc8_calc, command);
    crc8_calc = CalculateCRC8(crc8_calc, msb);
    crc8_calc = CalculateCRC8(crc8_calc, lsb);

    if (crc8 != crc8_calc) {
        return 0x7FFFU;
    }

    value = (uint16_t)(((uint16_t)msb << 8) | lsb);
    return value;
}

//****************************************************
uint16_t ReadSensorOutput(SHT1x_t *sht, uint8_t command){
    uint8_t ack = 1;
    uint8_t msb = 0, lsb = 0;
    uint8_t crc8 = 0, crc8_calc = 0;
    uint16_t value = 0;
    //char txt[20];

//    StartTransmission(sht);
//    WriteByte(sht, command);
//
//    ack = GetAck(sht); //ack=1;
    ack = SHT1x_StartMeasurement(sht, command);
    if (ack != 0) {
        return SHT1X_ERROR_ACK;
    }
    ///SHT1x_StartMeasurement(sht, command);

    //delay_ms(500);
    while(SHT1x_DATA_GetPin(sht));  // Will Edit to non-blocking polling
    msb = ReadByte(sht); SendAck(sht, 0);
    lsb = ReadByte(sht); SendAck(sht, 0);
    crc8 = ReadByte(sht); SendAck(sht, 1);

    crc8_calc = 0x00;
    crc8_calc = CalculateCRC8(crc8_calc, command);
    crc8_calc = CalculateCRC8(crc8_calc, msb);
    crc8_calc = CalculateCRC8(crc8_calc, lsb);

    if (crc8 != crc8_calc) {
//        putsf("\r CRC-8 ERROR");
        return SHT1X_ERROR_CRC;
    }

//    putsf("\r");
//    putsf("command:"); itoa(command, txt); puts(txt); putsf("\r");
//    putsf("msb:"); itoa(msb, txt); puts(txt); putsf("\r");
//    putsf("lsb:"); itoa(lsb, txt); puts(txt); putsf("\r");
//    putsf("crc8:"); itoa(crc8, txt); puts(txt); putsf("\r");
//    putsf("crc8_calc:"); itoa(crc8_calc, txt); puts(txt); putsf("\r");

    value = (uint16_t)(((uint16_t)msb << 8) | lsb);

    return value;
}

//****************************************************
uint16_t SHT1x_GetTemperature(SHT1x_t *sht){
    uint16_t so_t = 10;
    int16_t temp = 100;
    int16_t so2_t = 6500;

    so_t = ReadSensorOutput(sht, CMD_MEASURE_TEMPERATURE);

//    if(so_t == SHT1X_ERROR_ACK){
//        return -1;
//    }
//
//    if(so_t == SHT1X_ERROR_CRC){
//        return 1;
//    }

    //so_t = so_t & 0x3FFF;
    //temp = so_t - 4010;
    //delay_ms(1);
    return so_t;
}

//****************************************************
float SHT1x_GetTemperature_(SHT1x_t *sht){
    uint16_t so_t = 0;
    float temp = 0;

    so_t = ReadSensorOutput(sht, CMD_MEASURE_TEMPERATURE);

    if(so_t == SHT1X_ERROR_ACK){
        return 0;
    }

    if(so_t == SHT1X_ERROR_CRC){
        return 1;
    }

    so_t = so_t & 0x3FFF;
    //temp = (int16_t)so_t + SHT1X_D1;
    temp = -40.1 + (0.01*so_t);

    return temp;
}

//****************************************************
float Get_Humidity(SHT1x_t *sht){
    uint16_t so_rh = 0;
    float rh_linear = 0, rh_true = 0;
    float temp = 0;

    so_rh = ReadSensorOutput(sht, CMD_MEASURE_HUMIDITY);

    if(so_rh == SHT1X_ERROR_ACK){
        return 0;
    }

    if (so_rh !=0){
        so_rh = so_rh & 0x0FFF;
        rh_linear = -2.0468+(0.0367*so_rh)+((-1.5955E-6)*so_rh*so_rh);
        ///SHT1X_DELAY_MS(1);
        temp = SHT1x_GetTemperature_(sht); // ADD SHT1X_ERROR_ACK
        rh_true=((temp-25)*(0.01+0.00008*so_rh))+rh_linear;
    }

    return rh_linear;
}



