// Name: htab_resize.c
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

// Changes the size of hash table based on the newn parameter
void htab_resize(htab_t *t, size_t newn) {
    htab_t *tbl = realloc(t->size * sizeof(struct htab_item) + sizeof(htab_t), newn * sizeof(struct htab_item) + sizeof(htab_t));
    if (tbl == 0) {
        return t;
    }
    
    tbl->arr_size = newn;
    return tbl;
}