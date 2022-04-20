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
    htab_pair_t *tmp_pair;

    // Inserts new item into the hash table and returns pointer to it
    if (htab_find(t, key) == NULL) {
        if (htab_insert(t, key) == false) return NULL;

        // Checks if the hash table needs to be resized
        if ((t->size / t->arr_size) > AVG_LEN_MAX) { htab_resize(t, 2 * t->arr_size); } 

        tmp_pair = htab_find(t, key);
        return tmp_pair;
    }

    // Returns pointer to already existing item
    tmp_pair = htab_find(t, key);
    
    return tmp_pair;
}
