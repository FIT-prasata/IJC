// Name: bitset.c
// IJC-DU1 Solution
// Task: A
// Start date: 26.2.2022
// Author: Lukáš Zavadil
// Faculty: FIT
// Compiled: gcc (GCC) 9.2.0
// Git repository: https://github.com/lukaszavadil1/IJC

#include "bitset.h"

extern inline void bitset_free(bitset_t set_name);
extern inline void bitset_size(bitset_t set_name);
extern inline void bitset_setbit(bitset_t set_name, long index, int expression);
extern inline void bitset_getbit(bitset_t set_name, long index);
