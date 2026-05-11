// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef BIT_MACRO_INCLUDED
#define BIT_MACRO_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#define BM_SET_BITMASK(ADDRESS, MASK)          ((ADDRESS) |= (MASK))
#define BM_SET_BIT(ADDRESS, POS)               ((ADDRESS) |= (0x01UL << (POS)))

#define BM_CLEAR_BITMASK(ADDRESS, MASK)        ((ADDRESS) &= ~(MASK))
#define BM_CLEAR_BIT(ADDRESS, POS)             ((ADDRESS) &= ~(0x01UL << (POS)))

#define BM_TOGGLE_BITMASK(ADDRESS, MASK)       ((ADDRESS) ^= (MASK))
#define BM_TOGGLE_BIT(ADDRESS, POS)            ((ADDRESS) ^= (0x01UL << (POS)))

#if defined(__GNUC__) || defined(__clang__)
/* MASK must not be 0 */
#define BM_WRITE_FIELD(ADDRESS, MASK, VALUE) \
    ((ADDRESS) = (((ADDRESS) & ~(MASK)) | (((VALUE) << (__builtin_ctz(MASK))) & (MASK))))
#endif

#define BM_WRITE_BIT( ADDRESS, POS, VALUE)     ((ADDRESS) = ((ADDRESS) & ~(0x01UL << (POS))) | ((0x01UL & (VALUE)) << (POS)))
#define BM_WRITE_2BIT(ADDRESS, POS, VALUE)     ((ADDRESS) = ((ADDRESS) & ~(0x03UL << (POS))) | ((0x03UL & (VALUE)) << (POS)))
#define BM_WRITE_3BIT(ADDRESS, POS, VALUE)     ((ADDRESS) = ((ADDRESS) & ~(0x07UL << (POS))) | ((0x07UL & (VALUE)) << (POS)))
#define BM_WRITE_4BIT(ADDRESS, POS, VALUE)     ((ADDRESS) = ((ADDRESS) & ~(0x0FUL << (POS))) | ((0x0FUL & (VALUE)) << (POS)))
#define BM_WRITE_5BIT(ADDRESS, POS, VALUE)     ((ADDRESS) = ((ADDRESS) & ~(0x1FUL << (POS))) | ((0x1FUL & (VALUE)) << (POS)))
#define BM_WRITE_6BIT(ADDRESS, POS, VALUE)     ((ADDRESS) = ((ADDRESS) & ~(0x3FUL << (POS))) | ((0x3FUL & (VALUE)) << (POS)))
#define BM_WRITE_7BIT(ADDRESS, POS, VALUE)     ((ADDRESS) = ((ADDRESS) & ~(0x7FUL << (POS))) | ((0x7FUL & (VALUE)) << (POS)))
#define BM_WRITE_8BIT(ADDRESS, POS, VALUE)     ((ADDRESS) = ((ADDRESS) & ~(0xFFUL << (POS))) | ((0xFFUL & (VALUE)) << (POS)))

#if defined(__GNUC__) || defined(__clang__)
/* mask must not be 0 */
#define BM_GET_FIELD(ADDRESS, MASK)(        	 ((ADDRESS) & (MASK)) >> (__builtin_ctz(MASK)))
#endif

#define BM_GET_BIT( ADDRESS, POS)              (((ADDRESS) >> (POS)) & 0x01UL)
#define BM_GET_2BIT(ADDRESS, POS)              (((ADDRESS) >> (POS)) & 0x03UL)
#define BM_GET_3BIT(ADDRESS, POS)              (((ADDRESS) >> (POS)) & 0x07UL)
#define BM_GET_4BIT(ADDRESS, POS)              (((ADDRESS) >> (POS)) & 0x0FUL)
#define BM_GET_5BIT(ADDRESS, POS)              (((ADDRESS) >> (POS)) & 0x1FUL)
#define BM_GET_6BIT(ADDRESS, POS)              (((ADDRESS) >> (POS)) & 0x3FUL)
#define BM_GET_7BIT(ADDRESS, POS)              (((ADDRESS) >> (POS)) & 0x7FUL)
#define BM_GET_8BIT(ADDRESS, POS)              (((ADDRESS) >> (POS)) & 0xFFUL)

#ifdef __cplusplus
}
#endif

#endif


