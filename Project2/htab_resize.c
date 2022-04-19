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
    htab_pair_t pair_arr[t->size];
    size_t pair_index = 0;
    for (size_t i = 0; i < t->arr_size; i++) {
        htab_item_t *tmp = t->arr_ptr[i];
        while (tmp != NULL) {
            pair_arr[pair_index].key = malloc(strlen(tmp->pair.key) + 1);
            pair_arr[pair_index].value = tmp->pair.value;
            strcpy((char *)pair_arr[pair_index++].key, tmp->pair.key);
            tmp = tmp->next;
        }
    }

    // CLEAR
    htab_item_t *item;
    htab_item_t *toFree;
    for(size_t i = 0; i < t->arr_size; i++){
        item = t->arr_ptr[i];
        while(item != NULL){
            toFree = item;
            item = item->next;
            free((char *)toFree->pair.key);
            free(toFree);
        }
        t->arr_ptr[i] = NULL;
    }
    // END CLEAR

    t->arr_ptr = realloc(t->arr_ptr, newn * sizeof(htab_item_t*));
    t->arr_size = newn;
    t->size = 0;
    for (size_t i = 0; i < t->arr_size; i++) {
        t->arr_ptr[i] = NULL;
    }
    for (size_t i = 0; i < pair_index; i++) {
        htab_insert(t, pair_arr[i].key);
        htab_find(t, pair_arr[i].key)->value = pair_arr[i].value;
    }
    for (size_t i = 0; i < pair_index; i++) {
        free((char *)pair_arr[i].key);
    }
}