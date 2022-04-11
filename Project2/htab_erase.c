// Name: htab_erase.c
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

// EXTERNAL INCLUDES
#include <stdbool.h>

bool htab_erase(htab_t * t, htab_key_t key) {
    int index = (htab_hash_function(key) % t->arr_size);
    if ((t->arr_ptr[index] == NULL) || strncmp(t->arr_ptr[index]->pair.key, key, t->arr_size) != 0) {
        return false;
    }
    free(t->arr_ptr[index]->pair.key);
    free(t->arr_ptr[index]->pair);  
    t->arr_ptr[index] = NULL;
    return true;
}