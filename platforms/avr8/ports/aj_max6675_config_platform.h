#ifndef AJ_MAX6675_CONFIG_PLATFORM_INCLUDED
#define AJ_MAX6675_CONFIG_PLATFORM_INCLUDED

#include "hardware.h"   /**< Project-level overrides */

#ifndef AJ_MAX6675_CONFIG_PLATFORM_EXTRA
#define AJ_MAX6675_CONFIG_PLATFORM_EXTRA
    #define AJ_MAX6675_CS_DDR           DDRB
    #define AJ_MAX6675_CS_PORT          PORTB
    #define AJ_MAX6675_CS_POS           4U
    #define AJ_MAX6675_CS_MASK          (1U << AJ_MAX6675_CS_POS)
#endif

#endif      /* AJ_MAX6675_CONFIG_PLATFORM_INCLUDED */
