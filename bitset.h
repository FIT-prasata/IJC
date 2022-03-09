// Name: bitset.h
// IJC-DU1 Solution
// Task: A
// Start date: 26.2.2022
// Author: Lukáš Zavadil
// Faculty: FIT
// Compiled: gcc (GCC) 9.2.0
// Git repository: https://github.com/lukaszavadil1/IJC

#include <stdio.h>
#include "error.h"
#include <stdlib.h>
#include <assert.h>
#include <limits.h>

#define USE_INLINE true

typedef unsigned long bitset_t[];
typedef unsigned long bitset_index_t;

// INITIALIZES SET WITH GIVEN NAME AND SIZE
// PARAMS: set_name - Name of the bit set |
//         size - Size of the bit set

#define bitset_create(set_name, size) static_assert(size > 0, "Velikost pole musí být větší než 0"); \
                                    unsigned long set_name[(size / (CHAR_BIT * sizeof(unsigned long))) + \
                                    ((size % (CHAR_BIT * sizeof(unsigned long))) ? 1 : 0) + 1] = { size }

// ALLOCATES MEMORY FOR SET WITH GIVEN NAME AND SIZE
// PARAMS: set_name - Name of the bit set |
//         size - Size of the bit set
#define bitset_alloc(set_name, size) assert(size > 0); \
                                    unsigned long *set_name = calloc((size / (CHAR_BIT * sizeof(unsigned long))) + \
                                    ((size % (CHAR_BIT * sizeof(unsigned long))) ? 1 : 0) + 1, sizeof(unsigned long)); \
                                    if (set_name == NULL) { printf("Chyba při alokaci paměti"); }; \
                                    *set_name = size;

// FREES ALLOCATED MEMORY FOR SET OF GIVEN NAME
// PARAMS: set_name - Name of the bit set
#ifdef USE_INLINE
    inline void bitset_free(bitset_t set_name) { free(set_name); }
#else
    #define bitset_free(set_name) free(set_name)
#endif

// RETURNS THE SIZE OF SET WITH GIVEN NAME
// PARAMS: set_name - Name of the bit set
#ifdef USE_INLINE
    inline unsigned long bitset_size(bitset_t set_name) { return set_name[0]; }
#else
    #define bitset_size(set_name) set_name[0]
#endif

// SETS THE VALUE OF BIT IN BIT SET
// PARAMS: set_name - Name of the bit set |
//         index - Index for setting bit |
//         expression - if 0 -> set bit value to 0, else set bit value to 1
#ifdef USE_INLINE
    inline void bitset_setbit(bitset_t set_name, bitset_index_t index, int expression) {
        if (index < bitset_size(set_name)) {
            if (expression != 0) {
                set_name[(index / (sizeof(unsigned long) * CHAR_BIT)) + 1]
                |= (1 << (index % (sizeof(unsigned long) * CHAR_BIT)));
            }
            else {
                set_name[(index / (sizeof(unsigned long) * CHAR_BIT)) + 1]
                &= ~(1 << (index % (sizeof(unsigned long) * CHAR_BIT)));
            }
        }
        else {
            error_exit("bitset_setbit: Index %lu mimo rozsah 0..%lu",
               (unsigned long)index, (unsigned long)bitset_size(set_name));
        }
    }
#else
    #define bitset_setbit(set_name, index, expression) \
            if (expression != 0) { \
                set_name[(index / (sizeof(unsigned long) * CHAR_BIT)) + 1] \
                |= (1 << (index % (sizeof(unsigned long) * CHAR_BIT))); \
            } \
            else { \
                set_name[(index / (sizeof(unsigned long) * CHAR_BIT)) + 1] \
                &= ~(1 << (index % (sizeof(unsigned long) * CHAR_BIT))); \
            }
#endif

// GETS THE VALUE OF BIT IN BIT SET
// PARAMS: set_name - Name of the bit set |
//         index - Index for getting bit
#ifdef USE_INLINE
    inline unsigned long bitset_getbit(bitset_t set_name, bitset_index_t index) {
        if (index < bitset_size(set_name)) {
            return set_name[(index / (sizeof(unsigned long) * CHAR_BIT)) + 1]
            & (1 << (index % (sizeof(unsigned long) * CHAR_BIT))); 
        }
        else {
            error_exit("bitset_getbit: Index %lu mimo rozsah 0..%lu",
               (unsigned long)index, (unsigned long)bitset_size(set_name));
            return 1;
        }
    }
#else
    #define bitset_getbit(set_name, index) \
        ((set_name[(index / (sizeof(unsigned long) * CHAR_BIT)) + 1]) \
        & (1 << (index % (sizeof(unsigned long) * CHAR_BIT))))
#endif