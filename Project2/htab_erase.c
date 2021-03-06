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
    htab_item_t *curr = t->arr_ptr[index];
    htab_item_t *prev = NULL;

    // Searches for the item in linked list
    while (curr != NULL && strcmp(curr->pair.key, key) != 0) {
        prev = curr;
        curr = curr->next;
    }

    // Returns false if the item is not found
    if (curr == NULL) { return false; }

    // Item on first index handle
    if (prev == NULL) { t->arr_ptr[index] = curr->next; }
    else { prev->next = curr->next; }
    curr->next = NULL;

    // Frees allocated memory
    free((char *)curr->pair.key);
    free(curr);

    t->size--;

    // Checks if the hash table needs to be resized
    if (((t->size / t->arr_size) < AVG_LEN_MIN) && t->arr_size > 1) { htab_resize(t, t->arr_size / 2); }

    return true;
}