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
    const char *key_arr[t->size];
    size_t key_num = 0;
    for (size_t i = 0; i < t->arr_size; i++) {
        htab_item_t *tmp = t->arr_ptr[i];
        while (tmp != NULL) {
            key_arr[key_num++] = tmp->pair.key;
            tmp = tmp->next;
        }
    }
    htab_clear(t);
    t->arr_ptr = realloc(t->arr_ptr, newn * sizeof(htab_item_t*));
    t->arr_size = newn;
    t->size = 0;
    for (size_t i = 0; i < t->arr_size; i++) {
        t->arr_ptr[i] = NULL;
    }
    for (size_t i = 0; i < key_num; i++) {
        htab_insert(t, key_arr[i]);
    }
}