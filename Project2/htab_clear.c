// Name: htab_clear.c
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

// Deletes all hash table items
void htab_clear(htab_t * t) {
    htab_item_t *tmp;
    htab_item_t *curr;
    size_t before_size = t->arr_size;
    for (size_t i = 0; i < t->arr_size; i++) {
        if (t->arr_size != before_size) {
            i = 0;
            before_size = t->arr_size;
        }
        curr = t->arr_ptr[i];
        while (curr != NULL) {
            tmp = curr;
            curr = curr->next;
            if (htab_erase(t, tmp->pair.key) == false) fprintf(stderr, "Chyba mazani\n");
            if (before_size != t->arr_size) {
                i = -1;
                break;
            }
        }
    }
    t->size = 0;
}