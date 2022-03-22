// Name: eratosthenes.c
// IJC-DU1 Solution
// Task: A
// Start date: 26.2.2022
// Author: Lukáš Zavadil
// Faculty: FIT
// Compiled: gcc (GCC) 9.2.0
// Git repository: https://github.com/lukaszavadil1/IJC

// LOCAL INCLUDES
#include "eratosthenes.h"

// Eratosthenes algorithm function
// Print last 10 prime numbers from the given range, each on a new line in ascending order
void Eratosthenes(bitset_t set_name) {
    
    // Pre-setting numbers 0 and 1 as non prime
    bitset_setbit(set_name, 0, 1);
    bitset_setbit(set_name, 1, 1);
    for (bitset_index_t i = SMALLEST_PRIME; i < sqrt(bitset_size(set_name)); i++) {
        if (bitset_getbit(set_name, i) == 0) {

            // Setting indexes of prime multiples to 1
            for (long unsigned int j = i; (j * i) < bitset_size(set_name); j++) {
                bitset_setbit(set_name, i * j, 1);
            }
        }
    }
}