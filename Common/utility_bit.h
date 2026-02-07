// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef UTILITY_BIT_INCLUDED
#define UTILITY_BIT_INCLUDED  

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#define SET_BIT(ADDRESS, POS)               ((ADDRESS) |= (0x01UL << (POS))) 
#define SET_BIT_OVERWRITE(ADDRESS, POS)     ((ADDRESS)  = (0x01UL << (POS)))    
#define CLEAR_BIT(ADDRESS, POS)             ((ADDRESS) &= ~(0x01UL << (POS)))
#define TOGGLE_BIT(ADDRESS, POS)            ((ADDRESS) ^= (0x01UL << (POS)))
#define TOGGLE_DATA(ADDRESS)                (~(ADDRESS))

#define WRITE_BIT( ADDRESS, POS, VALUE)     ((ADDRESS) = ((ADDRESS) & ~(0x01UL << (POS))) | ((0x01UL & (VALUE)) << (POS)))
#define WRITE_2BIT(ADDRESS, POS, VALUE)     ((ADDRESS) = ((ADDRESS) & ~(0x03UL << (POS))) | ((0x03UL & (VALUE)) << (POS)))
#define WRITE_3BIT(ADDRESS, POS, VALUE)     ((ADDRESS) = ((ADDRESS) & ~(0x07UL << (POS))) | ((0x07UL & (VALUE)) << (POS)))
#define WRITE_4BIT(ADDRESS, POS, VALUE)     ((ADDRESS) = ((ADDRESS) & ~(0x0FUL << (POS))) | ((0x0FUL & (VALUE)) << (POS)))
#define WRITE_5BIT(ADDRESS, POS, VALUE)     ((ADDRESS) = ((ADDRESS) & ~(0x1FUL << (POS))) | ((0x1FUL & (VALUE)) << (POS)))
#define WRITE_6BIT(ADDRESS, POS, VALUE)     ((ADDRESS) = ((ADDRESS) & ~(0x3FUL << (POS))) | ((0x3FUL & (VALUE)) << (POS)))
#define WRITE_7BIT(ADDRESS, POS, VALUE)     ((ADDRESS) = ((ADDRESS) & ~(0x7FUL << (POS))) | ((0x7FUL & (VALUE)) << (POS)))
#define WRITE_8BIT(ADDRESS, POS, VALUE)     ((ADDRESS) = ((ADDRESS) & ~(0xFFUL << (POS))) | ((0xFFUL & (VALUE)) << (POS)))

#define GET_BIT( ADDRESS, POS)              (((ADDRESS) >> (POS)) & 0x01UL)
#define GET_2BIT(ADDRESS, POS)              (((ADDRESS) >> (POS)) & 0x03UL)
#define GET_3BIT(ADDRESS, POS)              (((ADDRESS) >> (POS)) & 0x07UL)
#define GET_4BIT(ADDRESS, POS)              (((ADDRESS) >> (POS)) & 0x0FUL)
#define GET_5BIT(ADDRESS, POS)              (((ADDRESS) >> (POS)) & 0x1FUL)
#define GET_6BIT(ADDRESS, POS)              (((ADDRESS) >> (POS)) & 0x3FUL)
#define GET_7BIT(ADDRESS, POS)              (((ADDRESS) >> (POS)) & 0x7FUL)
#define GET_8BIT(ADDRESS, POS)              (((ADDRESS) >> (POS)) & 0xFFUL)


static inline void write_bit_u8(volatile uint8_t *reg, uint8_t pos, uint8_t val){
    *reg =  (uint8_t)(
            (*reg & (uint8_t)~(uint8_t)(1U << pos)) |
            ((uint8_t)(val & 1U) << pos)
            );
}

static inline void write_bit_u16(volatile uint16_t *reg, uint8_t pos, uint8_t val){
    *reg =  (uint16_t)(
            (*reg & (uint16_t)~(uint16_t)(1U << pos)) |
            ((uint16_t)(val & 1U) << pos)
            );
}

static inline void write_bit_u32(volatile uint32_t *reg, uint8_t pos, uint8_t val){
    *reg =  (*reg & ~(1UL << pos)) |
            ((uint32_t)(val & 1U) << pos);
}


#ifdef __cplusplus
}
#endif

#endif

    
    