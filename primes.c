// Name: primes.c
// IJC-DU1 Solution
// Task: A
// Start date: 26.2.2022
// Author: Lukáš Zavadil
// Faculty: FIT
// Compiled: gcc (GCC) 9.2.0
// Git repository: https://github.com/lukaszavadil1/IJC

// LOCAL INCLUDES
#include "eratosthenes.h"

// EXTERNAL INCLUDES
#include <time.h>

// DEFINES
#define PRIMES_AMOUNT 10
#define PRIMES_RANGE 300000000

int main(void) {

    // Timer init
    clock_t start;
    start = clock();
    
    // Set init
    bitset_alloc(set_name, PRIMES_RANGE);

    Eratosthenes(set_name);

    // Temporary array for storing last primes from given range
    int primes_arr[PRIMES_AMOUNT];
    int counter = 0;
    for (bitset_index_t i = bitset_size(set_name)-1; i >= SMALLEST_PRIME; i--) {
        if (bitset_getbit(set_name, i) == 0) {
            primes_arr[counter++] = i;

            if (counter == PRIMES_AMOUNT) {
                break;
            }
        }
    }
    // Print primes to stdout
    for (int j = counter-1; j >= 0; j--) {
        printf("%d\n", primes_arr[j]);
    }
    fprintf(stderr, "Time=%.3g\n", (double)(clock()-start)/CLOCKS_PER_SEC);
    free(set_name);
    return 0;
}