#ifndef SHT1X_PORT_INCLUDED
#define SHT1X_PORT_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "utility_bit.h"
#include "compiler_port.h"
#include "sht1x_hw.h"

#define SHT1X_DELAY_US(VALUE)           DELAY_US(VALUE)
#define SHT1X_DELAY_MS(VALUE)           DELAY_MS(VALUE)

#define SHT1X_DELAY_MIN()               DELAY_US(1)
//#define SHT1X_DELAY_MIN()               ((void)0)

typedef struct {
    volatile uint8_t *ddr;
    volatile uint8_t *port;
    volatile uint8_t *pin;
    const uint8_t    index;
} SHT1x_Pin_t;

typedef struct {
    const SHT1x_Pin_t sck;
    const SHT1x_Pin_t data;
} SHT1x_t;

//***************************************
static inline void SHT1x_SCK_InitPin(SHT1x_t *sht){
    BM_SET_BIT(*(sht->sck.ddr), sht->sck.index);
    BM_CLEAR_BIT(*(sht->sck.port), sht->sck.index);  // Idle bus
}

//***************************************
static inline void SHT1x_SCK_WritePin(SHT1x_t *sht, uint8_t status){
    BM_WRITE_BIT( *(sht->sck.port), sht->sck.index, status );
}

//***************************************
static inline void SHT1x_DATA_SetInput(SHT1x_t *sht){
    BM_CLEAR_BIT(*(sht->data.ddr), sht->data.index);
    BM_CLEAR_BIT(*(sht->data.port), sht->data.index);
}

//***************************************
static inline void SHT1x_DATA_WritePin(SHT1x_t *sht, uint8_t status){
    if(status == 1){
        SHT1x_DATA_SetInput(sht);
    }
    else{
        BM_SET_BIT(*(sht->data.ddr), sht->data.index);
        BM_CLEAR_BIT(*(sht->data.port), sht->data.index);
    }
}

//***************************************
static inline uint8_t SHT1x_DATA_GetPin(SHT1x_t *sht){
    //return BM_GET_BIT(*(sht->data.pin), sht->data.index);
    return (*(sht->data.pin) >> sht->data.index) & 0x01U;
}

#ifdef __cplusplus
}
#endif

#endif
