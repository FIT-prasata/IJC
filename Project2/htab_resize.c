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
    htab_pair_t tmp_pair[t->size];
    size_t pair_index = 0;

    // Loads all pairs to temp array
    for (size_t i = 0; i < t->arr_size; i++) {
        htab_item_t *tmp = t->arr_ptr[i];
        while (tmp != NULL) {
            tmp_pair[pair_index].key = malloc(strlen(tmp->pair.key) + 1);
            tmp_pair[pair_index].value = tmp->pair.value;
            strcpy((char *)tmp_pair[pair_index++].key, tmp->pair.key);
            tmp = tmp->next;
        }
    }

    // Deletes all items from the hash table
    htab_item_t *curr, *prev;
    for(size_t i = 0; i < t->arr_size; i++){
        curr = t->arr_ptr[i];
        while(curr != NULL){
            prev = curr;
            curr = curr->next;
            free((char *)prev->pair.key);
            free(prev);
        }
        t->arr_ptr[i] = NULL;
    }

    // Array resize
    t->arr_ptr = realloc(t->arr_ptr, newn * sizeof(htab_item_t*));
    t->arr_size = newn;
    t->size = 0;

    // Sets all item pointers to NULL
    for (size_t i = 0; i < t->arr_size; i++) {
        t->arr_ptr[i] = NULL;
    }

    // Inserts all pairs saved in temp array into the hash table
    for (size_t i = 0; i < pair_index; i++) {
        htab_insert(t, tmp_pair[i].key);
        htab_find(t, tmp_pair[i].key)->value = tmp_pair[i].value;
    }

    // Frees allocated memory for temp array keys
    for (size_t i = 0; i < pair_index; i++) {
        free((char *)tmp_pair[i].key);
    }
}