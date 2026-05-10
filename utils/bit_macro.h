// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef BIT_MACRO_INCLUDED
#define BIT_MACRO_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#define SET_BITMASK(ADDRESS, MASK)          ((ADDRESS) |= (MASK))
#define SET_BIT(ADDRESS, POS)               ((ADDRESS) |= (0x01UL << (POS)))

#define SET_BITMASK_DIRECT(ADDRESS, MASK)   ((ADDRESS) = (MASK))
#define SET_BIT_DIRECT(ADDRESS, POS)        ((ADDRESS)  = (0x01UL << (POS)))
//#define SET_2BIT(ADDRESS, POS)              ((ADDRESS) |= (0x03UL << (POS)))
//#define SET_3BIT(ADDRESS, POS)              ((ADDRESS) |= (0x07UL << (POS)))
//#define SET_4BIT(ADDRESS, POS)              ((ADDRESS) |= (0x0FUL << (POS)))
//#define SET_5BIT(ADDRESS, POS)              ((ADDRESS) |= (0x1FUL << (POS)))
//#define SET_6BIT(ADDRESS, POS)              ((ADDRESS) |= (0x3FUL << (POS)))
//#define SET_7BIT(ADDRESS, POS)              ((ADDRESS) |= (0x7FUL << (POS)))
//#define SET_8BIT(ADDRESS, POS)              ((ADDRESS) |= (0xFFUL << (POS)))

#define CLEAR_BITMASK(ADDRESS, MASK)        ((ADDRESS) &= ~(MASK))
#define CLEAR_BIT(ADDRESS, POS)             ((ADDRESS) &= ~(0x01UL << (POS)))
//#define CLEAR_2BIT(ADDRESS, POS)            ((ADDRESS) &= ~(0x03UL << (POS)))
//#define CLEAR_3BIT(ADDRESS, POS)            ((ADDRESS) &= ~(0x07UL << (POS)))
//#define CLEAR_4BIT(ADDRESS, POS)            ((ADDRESS) &= ~(0x0FUL << (POS)))
//#define CLEAR_5BIT(ADDRESS, POS)            ((ADDRESS) &= ~(0x1FUL << (POS)))
//#define CLEAR_6BIT(ADDRESS, POS)            ((ADDRESS) &= ~(0x3FUL << (POS)))
//#define CLEAR_7BIT(ADDRESS, POS)            ((ADDRESS) &= ~(0x7FUL << (POS)))
//#define CLEAR_8BIT(ADDRESS, POS)            ((ADDRESS) &= ~(0xFFUL << (POS)))

#define TOGGLE_BITMASK(ADDRESS, MASK)       ((ADDRESS) ^= (MASK))
#define TOGGLE_BIT(ADDRESS, POS)            ((ADDRESS) ^= (0x01UL << (POS)))
//#define TOGGLE_2BIT(ADDRESS, POS)           ((ADDRESS) ^= (0x03UL << (POS)))
//#define TOGGLE_3BIT(ADDRESS, POS)           ((ADDRESS) ^= (0x07UL << (POS)))
//#define TOGGLE_4BIT(ADDRESS, POS)           ((ADDRESS) ^= (0x0FUL << (POS)))
//#define TOGGLE_5BIT(ADDRESS, POS)           ((ADDRESS) ^= (0x1FUL << (POS)))
//#define TOGGLE_6BIT(ADDRESS, POS)           ((ADDRESS) ^= (0x3FUL << (POS)))
//#define TOGGLE_7BIT(ADDRESS, POS)           ((ADDRESS) ^= (0x7FUL << (POS)))
//#define TOGGLE_8BIT(ADDRESS, POS)           ((ADDRESS) ^= (0xFFUL << (POS)))

#define WRITE_BIT( ADDRESS, POS, VALUE)     ((ADDRESS) = ((ADDRESS) & ~(0x01UL << (POS))) | ((0x01UL & (VALUE)) << (POS)))
#define WRITE_2BIT(ADDRESS, POS, VALUE)     ((ADDRESS) = ((ADDRESS) & ~(0x03UL << (POS))) | ((0x03UL & (VALUE)) << (POS)))
#define WRITE_3BIT(ADDRESS, POS, VALUE)     ((ADDRESS) = ((ADDRESS) & ~(0x07UL << (POS))) | ((0x07UL & (VALUE)) << (POS)))
#define WRITE_4BIT(ADDRESS, POS, VALUE)     ((ADDRESS) = ((ADDRESS) & ~(0x0FUL << (POS))) | ((0x0FUL & (VALUE)) << (POS)))
#define WRITE_5BIT(ADDRESS, POS, VALUE)     ((ADDRESS) = ((ADDRESS) & ~(0x1FUL << (POS))) | ((0x1FUL & (VALUE)) << (POS)))
#define WRITE_6BIT(ADDRESS, POS, VALUE)     ((ADDRESS) = ((ADDRESS) & ~(0x3FUL << (POS))) | ((0x3FUL & (VALUE)) << (POS)))
#define WRITE_7BIT(ADDRESS, POS, VALUE)     ((ADDRESS) = ((ADDRESS) & ~(0x7FUL << (POS))) | ((0x7FUL & (VALUE)) << (POS)))
#define WRITE_8BIT(ADDRESS, POS, VALUE)     ((ADDRESS) = ((ADDRESS) & ~(0xFFUL << (POS))) | ((0xFFUL & (VALUE)) << (POS)))

#if defined(__GNUC__) || defined(__clang__)
#define GET_FIELD(ADDRESS, MASK)(          ((ADDRESS) & (MASK)) >> (__builtin_ctz(MASK)))
#endif

#define GET_BIT( ADDRESS, POS)              (((ADDRESS) >> (POS)) & 0x01UL)
#define GET_2BIT(ADDRESS, POS)              (((ADDRESS) >> (POS)) & 0x03UL)
#define GET_3BIT(ADDRESS, POS)              (((ADDRESS) >> (POS)) & 0x07UL)
#define GET_4BIT(ADDRESS, POS)              (((ADDRESS) >> (POS)) & 0x0FUL)
#define GET_5BIT(ADDRESS, POS)              (((ADDRESS) >> (POS)) & 0x1FUL)
#define GET_6BIT(ADDRESS, POS)              (((ADDRESS) >> (POS)) & 0x3FUL)
#define GET_7BIT(ADDRESS, POS)              (((ADDRESS) >> (POS)) & 0x7FUL)
#define GET_8BIT(ADDRESS, POS)              (((ADDRESS) >> (POS)) & 0xFFUL)

#ifdef __cplusplus
}
#endif

#endif


