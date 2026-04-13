// Editing…

#ifndef SHT1X_INCLUDED
#define SHT1X_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <io.h>
#include <delay.h>

#include "sht1x_port.h"

#ifndef SHTXX_HARDWARE
#define SHTXX_HARDWARE
    #define DATA_DDR    DDRC.1
    #define DATA_PORT   PORTC.1
    #define DATA_PIN    PINC.1

    #define SCK_DDR     DDRC.0
    #define SCK_PORT    PORTC.0
    #define SCK_PIN     PINC.0
#endif

#define MEASURE_TEMP    0b00000011
#define MEASURE_HUMI    0b00000101
#define RESET           0b00011110

void SHT1x_Init(SHT1x_t *sht);

void Transmission_Start(void);
void Connection_Reset_Sequence(void);
char Get_Ack(void);
void Write(unsigned char command);
void Send_Ack(char ack);
unsigned char Read(void);
void Soft_Reset();
unsigned int Full_Communication(int Reg);
float Get_Temp(void);
float Get_Humidity(void);

#ifdef __cplusplus
}
#endif

#endif

