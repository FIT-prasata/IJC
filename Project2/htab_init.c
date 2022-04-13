// Name: htab_init.c
// IJC-DU2 Solution
// Task: B
// Start date: 28.3.2022
// Author: Lukáš Zavadil
// Faculty: FIT
// Compiled: gcc (GCC) 9.2.0
// Git repository: https://github.com/lukaszavadil1/IJC

// LOCAL INCLUDES
#include "htab.h"
#include "structs.h"

// Allocates memory for the hash table struct and for its n items
htab_t *htab_init(size_t n) {
    htab_t *tbl = malloc(n * sizeof(struct htab_item) + sizeof(htab_t));
    if (tbl == 0) {
        return NULL;
    }
    
    tbl->size = 0;
    tbl->arr_size = n;
    for (int i = 0; i < n; i++) {
        tbl->arr_ptr[i] = NULL;
    }
    
    return tbl;