// GitHub Account: GitHub.com/AliRezaJoodi

#include "hardware.h"
#include "sht1x.h"

#define SCK_IDLE        0U
#define SCK_ACTIVE      1U
#define DATA_IDLE       1U

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

//***************************************
void SHT1x_Init(SHT1x_t *sht){
    SHT1x_SCK_InitPin(sht);
    SHT1x_SCK_WritePin(sht, SCK_IDLE);

    SHT1x_DATA_SetInput(sht);
    SHT1x_DATA_WritePin(sht, DATA_IDLE);

    SHT1x_ResetConnection(sht);
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
char Get_Ack(void){
    char ack=1;
    DATA_DDR = 0;
    SCK_PORT = 1;
    ack = DATA_PIN;
    SCK_PORT = 0;
    return ack;
}

//****************************************************
void Send_Ack(char ack){
    DATA_DDR = 1; DATA_PORT = ack;
    SCK_PORT = 1; SCK_PORT = 0;
}

//****************************************************
//Soft reset, resets the interface, clears the status register to default values.
void Soft_Reset(SHT1x_t *sht){
    //Transmission_Start();
    StartTransmission(sht);
    WriteByte(sht, RESET);
    SHT1X_DELAY_MS(20);
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
    error = Get_Ack(); //error=1;
    if(error==0){
        while(DATA_PIN);
        msb = ReadByte(sht); Send_Ack(0);
        lsb = ReadByte(sht); Send_Ack(0);
        crc = ReadByte(sht); Send_Ack(1);  //crc will use for nev version.
        value=(msb*256)+lsb;
    }

    return value;
}

//****************************************************
float Get_Temp(SHT1x_t *sht){
    unsigned int so_t=0;
    float temp=0;

    so_t = Full_Communication(sht, MEASURE_TEMP);
    if(so_t != 0){
        temp = -40.1 + (0.01*so_t);  //VDD=5V
    }

    return temp;
}

//****************************************************
float Get_Humidity(SHT1x_t *sht){
    unsigned int  so_rh=0;
    float rh_linear=0, temp=0, rh_true=0;

    so_rh = Full_Communication(sht, MEASURE_HUMI);
    if (so_rh !=0){
        rh_linear= -2.0468+(0.0367*so_rh)+((-1.5955E-6)*so_rh*so_rh);
        SHT1X_DELAY_MS(1);
        temp=Get_Temp(sht);
        rh_true=((temp-25)*(0.01+0.00008*so_rh))+rh_linear;
    }

    return rh_true;
}
