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
    Eratosthenes(set_name);
    int last_primes = 10;
    for (unsigned long int i = bitset_size(set_name)-1; i >= 2; i--) {
        if (last_primes > 0) {
            if (bitset_getbit(set_name, i) == 0) {
                printf("%lu\n", i);
                last_primes--;
            }
        }
        else break;

    }
    free(set_name);
    return 0;
}