/**
 * @brief Bit manipulation helper macros.
 *
 * This header provides a collection of lightweight macros for common bit
 * operations such as setting, clearing, toggling, and reading bits.
 * The macros are generic and can operate on any modifiable integer object
 * (e.g., variables or memory-mapped registers).
 *
 * Unlike the higher-level register utilities, these macros do not enforce
 * type safety or register width constraints. They are intended to provide
 * minimal-overhead bit manipulation primitives.
 *
 * @section usage_constraints Usage Constraints & Safety
 *
 * @subsection mask_reqs Mask-based Operations
 * - @b Non-zero: Macros that accept a `mask` parameter expect the mask to be non-zero.
 * - @b Multi-bit: Masks may represent single or multiple bits.
 * - @b Field operations: If a mask is used to represent a bit-field, it should
 *   describe one contiguous region of bits.
 *
 * @subsection pos_reqs Position-based Operations
 * - The `pos` parameter is 0-indexed.
 * - The valid range of `pos` depends on the width of the target object:
 *   - 8-bit  object: 0�7
 *   - 16-bit object: 0�15
 *   - 32-bit object: 0�31
 *
 * @subsection macro_notes Macro Behavior
 * - These utilities are implemented as macros and may evaluate arguments
 *   multiple times. Avoid passing expressions with side effects
 *   (e.g., `x++`, function calls).
 * - The first parameter must be a modifiable lvalue (e.g., a variable or register).
 *
 * @author  AliReza Joodi
 * @see     https://github.com/AliRezaJoodi
 */

#ifndef AJ_BIT_MACRO_INCLUDED
#define AJ_BIT_MACRO_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif


#define AJ_SET_BIT_MASK(ADDRESS, MASK)             ((ADDRESS) |= (MASK))
#define AJ_SET_BIT_POS(ADDRESS, POS)               ((ADDRESS) |= (0x01UL << (POS)))

#define AJ_CLEAR_BIT_MASK(ADDRESS, MASK)           ((ADDRESS) &= ~(MASK))
#define AJ_CLEAR_BIT_POS(ADDRESS, POS)             ((ADDRESS) &= ~(0x01UL << (POS)))

#define AJ_TOGGLE_BIT_MASK(ADDRESS, MASK)          ((ADDRESS) ^= (MASK))
#define AJ_TOGGLE_BIT_POS(ADDRESS, POS)            ((ADDRESS) ^= (0x01UL << (POS)))

#if defined(__GNUC__) || defined(__clang__)
/* MASK must not be 0 */
#define AJ_WRITE_FIELD_MASK(ADDRESS, MASK, VALUE) \
    ((ADDRESS) = (((ADDRESS) & ~(MASK)) | (((VALUE) << (__builtin_ctz(MASK))) & (MASK))))
#endif

#define AJ_WRITE_BIT_POS(ADDRESS, POS, VALUE)      ((ADDRESS) = ((ADDRESS) & ~(0x01UL << (POS))) | ((0x01UL & (VALUE)) << (POS)))
#define AJ_WRITE_2BIT_POS(ADDRESS, POS, VALUE)     ((ADDRESS) = ((ADDRESS) & ~(0x03UL << (POS))) | ((0x03UL & (VALUE)) << (POS)))
#define AJ_WRITE_3BIT_POS(ADDRESS, POS, VALUE)     ((ADDRESS) = ((ADDRESS) & ~(0x07UL << (POS))) | ((0x07UL & (VALUE)) << (POS)))
#define AJ_WRITE_4BIT_POS(ADDRESS, POS, VALUE)     ((ADDRESS) = ((ADDRESS) & ~(0x0FUL << (POS))) | ((0x0FUL & (VALUE)) << (POS)))
#define AJ_WRITE_5BIT_POS(ADDRESS, POS, VALUE)     ((ADDRESS) = ((ADDRESS) & ~(0x1FUL << (POS))) | ((0x1FUL & (VALUE)) << (POS)))
#define AJ_WRITE_6BIT_POS(ADDRESS, POS, VALUE)     ((ADDRESS) = ((ADDRESS) & ~(0x3FUL << (POS))) | ((0x3FUL & (VALUE)) << (POS)))
#define AJ_WRITE_7BIT_POS(ADDRESS, POS, VALUE)     ((ADDRESS) = ((ADDRESS) & ~(0x7FUL << (POS))) | ((0x7FUL & (VALUE)) << (POS)))
#define AJ_WRITE_8BIT_POS(ADDRESS, POS, VALUE)     ((ADDRESS) = ((ADDRESS) & ~(0xFFUL << (POS))) | ((0xFFUL & (VALUE)) << (POS)))

#if defined(__GNUC__) || defined(__clang__)
/* mask must not be 0 */
#define AJ_GET_FIELD_MASK(ADDRESS, MASK)(        	((ADDRESS) & (MASK)) >> (__builtin_ctz(MASK)))
#endif

#define AJ_GET_BIT_POS(ADDRESS, POS)               (((ADDRESS) >> (POS)) & 0x01UL)
#define AJ_GET_2BIT_POS(ADDRESS, POS)              (((ADDRESS) >> (POS)) & 0x03UL)
#define AJ_GET_3BIT_POS(ADDRESS, POS)              (((ADDRESS) >> (POS)) & 0x07UL)
#define AJ_GET_4BIT_POS(ADDRESS, POS)              (((ADDRESS) >> (POS)) & 0x0FUL)
#define AJ_GET_5BIT_POS(ADDRESS, POS)              (((ADDRESS) >> (POS)) & 0x1FUL)
#define AJ_GET_6BIT_POS(ADDRESS, POS)              (((ADDRESS) >> (POS)) & 0x3FUL)
#define AJ_GET_7BIT_POS(ADDRESS, POS)              (((ADDRESS) >> (POS)) & 0x7FUL)
#define AJ_GET_8BIT_POS(ADDRESS, POS)              (((ADDRESS) >> (POS)) & 0xFFUL)


#ifdef __cplusplus
}
#endif

#endif


