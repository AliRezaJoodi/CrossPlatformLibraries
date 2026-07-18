// GitHub Account:  GitHub.com/AliRezaJoodi

#ifndef AJ_SPI_CONFIG_INCLUDED
#define AJ_SPI_CONFIG_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif


#include "hardware.h"   /**< Project-level overrides */

#ifndef AJ_SPI_CONFIG
#define AJ_SPI_CONFIG
    #define AJ_SPI_TIMEOUT              1000U   // A value of uint16_t

    #warning "AJ_SPI_CONFIG is not defined; default configuration will be used."
#endif


#ifdef __cplusplus
}
#endif

#endif  /* AJ_SPI_CONFIG_INCLUDED */
