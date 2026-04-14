// Editing…

#ifndef SHT1X_INCLUDED
#define SHT1X_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
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

void SHT1x_Init(SHT1x_t *sht);
void SHT1x_ResetConnection(SHT1x_t *sht);
void SHT1x_SoftReset(SHT1x_t *sht);

float Get_Temp(SHT1x_t *sht);
float Get_Humidity(SHT1x_t *sht);

#ifdef __cplusplus
}
#endif

#endif

