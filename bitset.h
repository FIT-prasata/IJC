// Name: bitset.h
// IJC-DU1 Solution
// Task: A
// Start date: 26.2.2022
// Author: Lukáš Zavadil
// Faculty: FIT
// Compiled: gcc (GCC) 9.2.0
// Git repository: https://github.com/lukaszavadil1/IJC

// LOCAL INCLUDES
#include "error.h"

// EXTERNAL INCLUDES
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>


typedef unsigned long bitset_t[];
typedef unsigned long bitset_index_t;

// Initializes set of given name and size
// PARAMS: set_name - Name of the bit set |
//         size - Size of the bit set
#define bitset_create(set_name, size) static_assert(size > 0, "Velikost pole musí být větší než 0"); \
            unsigned long set_name[ (size / (CHAR_BIT * sizeof(unsigned long))) + \
            ((size % (CHAR_BIT * sizeof(unsigned long))) ? 1 : 0) + 1 ] = { size }

// Allocates memory for set of given name and size
// PARAMS: set_name - Name of the bit set |
//         size - Size of the bit set
#define bitset_alloc(set_name, size) assert(size > 0); \
            unsigned long *set_name = calloc( (size / (CHAR_BIT * sizeof(unsigned long))) + \
            ((size % (CHAR_BIT * sizeof(unsigned long))) ? 1 : 0) + 1, sizeof(unsigned long) ); \
            if (set_name == NULL) { \
                error_exit("bitset_alloc: Chyba při alokaci paměti"); \
            }; \
            *set_name = size;

// Frees alocated memory for set of given name
// PARAMS: set_name - Name of the bit set
#ifdef USE_INLINE
    inline void bitset_free(bitset_t set_name) { free(set_name); }
#else
    #define bitset_free(set_name) free(set_name)
#endif

// Returns the size of set of given name
// PARAMS: set_name - Name of the bit set
#ifdef USE_INLINE
    inline unsigned long bitset_size(bitset_t set_name) { return set_name[0]; }
#else
    #define bitset_size(set_name) set_name[0]
#endif

// Sets the value of bit in bitset
// PARAMS: set_name - Name of the bit set |
//         index - Index for setting bit |
//         expression - if 0 -> set bit value to 0, else set bit value to 1
#ifdef USE_INLINE
    inline void bitset_setbit(bitset_t set_name, bitset_index_t index, int expression) {
        if (index < bitset_size(set_name)) {
            if (expression != 0) {
                set_name[(index / (sizeof(unsigned long) * CHAR_BIT)) + 1]
                |= ((unsigned long)1 << (index % (sizeof(unsigned long) * CHAR_BIT)));
            }
            else {
                set_name[(index / (sizeof(unsigned long) * CHAR_BIT)) + 1]
                &= ~((unsigned long)1 << (index % (sizeof(unsigned long) * CHAR_BIT)));
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
                |= ((unsigned long)1 << (index % (sizeof(unsigned long) * CHAR_BIT))); \
            } \
            else { \
                set_name[(index / (sizeof(unsigned long) * CHAR_BIT)) + 1] \
                &= ~((unsigned long)1 << (index % (sizeof(unsigned long) * CHAR_BIT))); \
            }
#endif

// Gets the value of bit in bit set
// PARAMS: set_name - Name of the bit set |
//         index - Index for getting bit
#ifdef USE_INLINE
    inline unsigned long bitset_getbit(bitset_t set_name, bitset_index_t index) {
        if (index < bitset_size(set_name)) {
            return set_name[(index / (sizeof(unsigned long) * CHAR_BIT)) + 1]
            & ((unsigned long)1 << (index % (sizeof(unsigned long) * CHAR_BIT))); 
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
        & ((unsigned long)1 << (index % (sizeof(unsigned long) * CHAR_BIT))))
#endif