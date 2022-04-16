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
htab_pair_t *htab_find(htab_t * t, htab_key_t key) {
    int index = (htab_hash_function(key) % t->arr_size);
    htab_item_t *tmp = t->arr_ptr[index]; 
    while (tmp != NULL && strcmp(tmp->pair.key, key) != 0) {
        tmp = tmp->next;
    }
    if (tmp == NULL) { return NULL; }

    htab_pair_t *pair_ptr = &(tmp->pair);
    return pair_ptr;
}