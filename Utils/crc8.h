#ifndef CRC8_INCLUDED
#define CRC8_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

uint8_t CRC8_ATM(uint8_t crc, uint8_t data);
uint8_t CRC8_Maxim(uint8_t crc, uint8_t data);
uint8_t CRC8_J1850(uint8_t crc, uint8_t data);

#ifdef __cplusplus
}
#endif

#endif
