#ifndef AJ_TYPEDEF_INCLUDED
#define AJ_TYPEDEF_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif


#include <stdint.h>
#include "aj_target.h"

#if AJ_TARGET_MCU_BITS == 32U
    typedef uint32_t aj_uint_t;
    typedef volatile uint32_t aj_volatile_uint_t;
    typedef const volatile uint32_t aj_const_volatile_uint_t;
#elif AJ_TARGET_MCU_BITS == 16U
    typedef uint16_t aj_uint_t;
    typedef volatile uint16_t aj_volatile_uint_t;
    typedef const volatile uint16_t aj_const_volatile_uint_t;
#elif AJ_TARGET_MCU_BITS == 8U
    typedef uint8_t aj_uint_t;
    typedef volatile uint8_t aj_volatile_uint_t;
    #if defined(__CODEVISIONAVR__)
        typedef volatile uint8_t aj_const_volatile_uint_t;
    #else
        typedef const volatile uint8_t aj_const_volatile_uint_t;
    #endif
#endif

typedef enum {
  AJ_CLEAR = 0U, 
  AJ_SET = 1U
} aj_state_flag_t;

typedef enum {
  AJ_DISABLE = 0U, 
  AJ_ENABLE = 1U
} aj_state_operational_t;

typedef enum{
  AJ_SUCCESS = 0U,
  AJ_ERROR = 1U
} aj_result_t;

typedef enum {
  AJ_ACTIVE = 0U,
  AJ_IDLE = 1U
} aj_state_line_t;

typedef enum {
  AJ_SELECT = 0U,
  AJ_DESELECT = 1U
} aj_state_chip_t;


#ifdef __cplusplus
}
#endif

#endif  /* AJ_TYPEDEF_INCLUDED */