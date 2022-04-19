// Name: htab_lookup_add.c
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

// Returns item linked to given key if it exists, otherwise creates a new item
htab_pair_t *htab_lookup_add(htab_t * t, htab_key_t key) {
    htab_pair_t *pair_ptr;
    if (htab_find(t, key) == NULL) {
        if (htab_insert(t, key) == false) return NULL;
        if ((t->size / t->arr_size) > AVG_LEN_MAX) { htab_resize(t, 2 * t->arr_size); } 
        pair_ptr = htab_find(t, key);
        return pair_ptr;
    }
    pair_ptr = htab_find(t, key);
    return pair_ptr;
}
