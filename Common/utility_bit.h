// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef _UTILITY_BIT_INCLUDED
#define _UTILITY_BIT_INCLUDED  


#define SET_BIT(ADDRESS, POS)               ((ADDRESS) |= (0x01UL << (POS)))    
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

#endif

    
    