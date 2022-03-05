// Name: bitset.h
// IJC-DU1 Solution
// Task: A
// Start date: 26.2.2022
// Author: Lukáš Zavadil
// Faculty: FIT
// Compiled: gcc (GCC) 9.2.0
// Git repository: https://github.com/lukaszavadil1/IJC

#include <stdio.h>

#define USE_INLINE true
#define BYTE_SIZE 8

typedef unsigned long bitset_t[];

// INITIALIZES SET WITH GIVEN NAME AND SIZE
// PARAMS: set_name - Name of the bit set |
//         size - Size of the bit set

#define bitset_create(set_name, size) set_name[(size / (BYTE_SIZE * sizeof(unsigned long))) + \
                                    ((size % (BYTE_SIZE * sizeof(unsigned long))) ? 1 : 0) + 1] = { size };

// ALLOCATES MEMORY FOR SET WITH GIVEN NAME AND SIZE
// PARAMS: set_name - Name of the bit set |
//         size - Size of the bit set
#define bitset_alloc(set_name, size) unsigned long *set_name = calloc((size / (BYTE_SIZE * sizeof(unsigned long))) + \
                                    ((size % (BYTE_SIZE * sizeof(unsigned long))) ? 1 : 0) + 1, sizeof(unsigned long)); \
                                    if (set_name == NULL) {printf("Chyba při alokaci paměti")}; \
                                    *set_name = size;

// FREES ALLOCATED MEMORY FOR SET OF GIVEN NAME
// PARAMS: set_name - Name of the bit set
#ifdef USE_INLINE
    static inline void bitset_free(bitset_t set_name) { free(set_name); }
#else
    #define bitset_free(set_name) free(set_name);
#endif

// RETURNS THE SIZE OF SET WITH GIVEN NAME
// PARAMS: set_name - Name of the bit set
#ifdef USE_INLINE
    static inline void bitset_size(bitset_t set_name) { set_name[0]; }
#else
    #define bitset_size(set_name) set_name[0];
#endif

// SETS THE VALUE OF BIT IN BIT SET
// PARAMS: set_name - Name of the bit set |
//         index - Index for setting bit |
//         expression - if 0 -> set bit value to 0, else set bit value to 1
#ifdef USE_INLINE
    static inline void bitset_setbit(bitset_t set_name, long index, int expression) {
        if (expression != 0) {
            set_name[(index / (sizeof(unsigned long) * BYTE_SIZE)) + 1]
            |= (1 << (index % (sizeof(unsigned long) * BYTE_SIZE)));
        }
        else {
             set_name[(index / (sizeof(unsigned long) * BYTE_SIZE)) + 1]
            &= ~(1 << (index % (sizeof(unsigned long) * BYTE_SIZE)));
        }
    }
#else
    #define bitset_setbit(set_name, index, expression);
#endif

// GETS THE VALUE OF BIT IN BIT SET
// PARAMS: set_name - Name of the bit set |
//         index - Index for getting bit
#ifdef USE_INLINE
    static inline void bitset_getbit(bitset_t set_name, long index) {
        return set_name[(index / (sizeof(unsigned long) * BYTE_SIZE)) + 1]
        & (1 << (index % (sizeof(unsigned long) * BYTE_SIZE))); 
    }
#else
    #define bitset_getbit(set_name, index);
#endif