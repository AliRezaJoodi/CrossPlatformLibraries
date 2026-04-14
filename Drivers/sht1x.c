// GitHub Account: GitHub.com/AliRezaJoodi

#include "hardware.h"
#include "sht1x.h"

#define SCK_IDLE                    0U
#define SCK_ACTIVE                  1U
#define DATA_IDLE                   1U

#define CMD_MEASURE_TEMPERATURE     0x03U
#define CMD_MEASURE_HUMIDITY        0x05U
#define CMD_SOFT_RESET              0x1EU

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
    SHT1x_SCK_WritePin(sht, 1);
    SHT1X_DELAY_MIN();

    SHT1x_DATA_WritePin(sht, 0);
    SHT1X_DELAY_MIN();

    SHT1x_SCK_WritePin(sht, 0);
    SHT1X_DELAY_MIN();

    SHT1x_SCK_WritePin(sht, 1);
    SHT1X_DELAY_MIN();

    SHT1x_DATA_WritePin(sht, 1);
    SHT1X_DELAY_MIN();

    SHT1x_SCK_WritePin(sht, 0);
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
    int8_t i = 7;

    SHT1x_SCK_WritePin(sht, SCK_IDLE);
    SHT1X_DELAY_MIN();

    for(i = 7; i >= 0; --i){
        SHT1x_DATA_WritePin(sht, GET_BIT(command, i));
        SHT1X_DELAY_MIN();

        SHT1x_SCK_WritePin(sht, SCK_ACTIVE);
        SHT1X_DELAY_MIN();

        SHT1x_SCK_WritePin(sht, SCK_IDLE);
        SHT1X_DELAY_MIN();
    }
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
    SHT1X_DELAY_MIN();

    SHT1x_SCK_WritePin(sht, SCK_ACTIVE);
    SHT1X_DELAY_MIN();

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
    SHT1X_DELAY_MS(11+1);
}

//***************************************
void SHT1x_Init(SHT1x_t *sht){
    SHT1x_SCK_InitPin(sht);
    SHT1x_SCK_WritePin(sht, SCK_IDLE);

    SHT1x_DATA_SetInput(sht);
    SHT1x_DATA_WritePin(sht, DATA_IDLE);

    SHT1x_SoftReset(sht);
}

//****************************************************
// Read the sensor value. Reg is register to read from
unsigned int Full_Communication(SHT1x_t *sht, int Reg){
    char error=1;
    unsigned char msb=0, lsb=0, crc=0;
    unsigned int value=0;

    //Transmission_Start();
    StartTransmission(sht);
    WriteByte(sht, Reg);
    error = GetAck(sht); //error=1;
    if(error==0){
        while(DATA_PIN);
        msb = ReadByte(sht); SendAck(sht, 0);
        lsb = ReadByte(sht); SendAck(sht, 0);
        crc = ReadByte(sht); SendAck(sht, 1);  //crc will use for nev version.
        value=(msb*256)+lsb;
    }

    return value;
}

//****************************************************
float Get_Temp(SHT1x_t *sht){
    unsigned int so_t=0;
    float temp=0;

    so_t = Full_Communication(sht, CMD_MEASURE_TEMPERATURE);
    if(so_t != 0){
        temp = -40.1 + (0.01*so_t);  //VDD=5V
    }

    return temp;
}

//****************************************************
float Get_Humidity(SHT1x_t *sht){
    unsigned int  so_rh=0;
    float rh_linear=0, temp=0, rh_true=0;

    so_rh = Full_Communication(sht, CMD_MEASURE_HUMIDITY);
    if (so_rh !=0){
        rh_linear= -2.0468+(0.0367*so_rh)+((-1.5955E-6)*so_rh*so_rh);
        SHT1X_DELAY_MS(1);
        temp=Get_Temp(sht);
        rh_true=((temp-25)*(0.01+0.00008*so_rh))+rh_linear;
    }

    return rh_true;
}
