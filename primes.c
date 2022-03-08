// Name: primes.c
// IJC-DU1 Solution
// Task: A
// Start date: 26.2.2022
// Author: Lukáš Zavadil
// Faculty: FIT
// Compiled: gcc (GCC) 9.2.0
// Git repository: https://github.com/lukaszavadil1/IJC


#include "eratosthenes.h"

int main(void) {
    bitset_alloc(set_name, 100);
    eratosthenes(set_name);
    for (int i = 2; i < set_name[0]; i++) {
        if (bitset_get(set_name, i) == 0) {
            printf("%lu\n", i);
        }
    }
    free(set_name);
    return 0;
}