
#include <stdint.h>
#include "crc8.h"

//************************************************
static inline uint8_t Reflect8Bit(uint8_t x){
    x = (uint8_t)((x >> 4) | (x << 4));
    x = (uint8_t)(((x & 0xCCU) >> 2) | ((x & 0x33U) << 2));
    x = (uint8_t)(((x & 0xAAU) >> 1) | ((x & 0x55U) << 1));

    return x;
}

//************************************************
uint8_t CRC8_ATM(uint8_t crc, uint8_t data){
    uint8_t i = 0;

    crc ^= data;

    for (i = 0; i < 8; ++i){
        if ((crc & 0x80) == 0x80){
            crc = (crc << 1) ^ 0x07;
        }
        else{
            crc <<= 1;
        }
    }

    return crc;
}

//************************************************
uint8_t CRC8_Maxim(uint8_t crc, uint8_t data){
    uint8_t i = 0;

    crc  = Reflect8Bit(crc);
    data = Reflect8Bit(data);

    crc ^= data;

    for (i = 0; i < 8; ++i){
        if ((crc & 0x80) == 0x80){
            crc = (crc << 1) ^ 0x31;
        }
        else{
            crc <<= 1;
        }
    }

    crc = Reflect8Bit(crc);

    return crc;
}

//************************************************
uint8_t CRC8_J1850(uint8_t crc, uint8_t data){
    uint8_t i = 0;

    crc ^= data;

    for (i = 0; i < 8; ++i){
        if ((crc & 0x80) == 0x80){
            crc = (crc << 1) ^ 0x1D;
        }
        else{
            crc <<= 1;
        }
    }

    return crc;
}
