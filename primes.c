// Name: primes.c
// IJC-DU1 Solution
// Task: A
// Start date: 26.2.2022
// Author: Lukáš Zavadil
// Faculty: FIT
// Compiled: gcc (GCC) 9.2.0
// Git repository: https://github.com/lukaszavadil1/IJC


#include "eratosthenes.h"
#include <time.h>

int main(void) {
    clock_t start;
    start = clock();
    
    bitset_alloc(set_name, 300000000);
    Eratosthenes(set_name);

    int last_primes[10];
    int primes_count = 0;
    for (bitset_index_t i = bitset_size(set_name)-1; i >= 2; i--) {
        if (bitset_getbit(set_name, i) == 0) {
            last_primes[primes_count] = i;
            primes_count++;
        }
        if (primes_count == 10) {
            break;
        }
    }
    for (int j = primes_count-1; j >= 0; j--) {
        printf("%d\n", last_primes[j]);
    }
    fprintf(stderr, "Time=%.3g\n", (double)(clock()-start)/CLOCKS_PER_SEC);
    free(set_name);
    return 0;
}