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

// Erases hash table item from the hash table based on given key
bool htab_erase(htab_t * t, htab_key_t key) {
    int index = (htab_hash_function(key) % t->arr_size);
    htab_item_t *tmp = t->arr_ptr[index];
    htab_item_t *prev = NULL;
    while (tmp != NULL && strncmp(tmp->pair.key, key, t->arr_size) != 0) {
        prev = tmp;
        tmp = tmp->next;
    }
    if (tmp == NULL) { return false; }
    if (prev == NULL) { t->arr_ptr[index] = tmp->next; }
    else { prev->next = tmp->next; }
    free(t->arr_ptr[index]->pair.key);
    free(t->arr_ptr[index]->pair);  
    free(t->arr_ptr[index]);
    return true;
}