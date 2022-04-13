// Name: htab_find.c
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

// Returns the item linked to a given key if it exists
htab_pair_t * htab_find(htab_t * t, htab_key_t key) {
    int index = (htab_hash_function(key) % t->arr_size);
    if ((t->arr_ptr[index] == NULL) || strncmp(t->arr_ptr[index]->pair.key, key, t->arr_size) != 0) {
        return NULL;
    }
    return t->arr_ptr[index];
}