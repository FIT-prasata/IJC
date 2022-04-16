// Name: htab_for_each.c
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


void htab_for_each(const htab_t * t, void (*f)(htab_pair_t *data)) {
    htab_pair_t *tmp_pair = malloc(sizeof(htab_pair_t));
    for (size_t i = 0; i < t->arr_size; i++) {
        htab_item_t *tmp = t->arr_ptr[i];
        while (tmp != NULL) {
            tmp_pair = (&tmp->pair);
            (f)(&tmp->pair);
            tmp->pair = *tmp_pair;
            print_pair(&tmp->pair);
            tmp = tmp->next;
            // TODO
        }
    }
    free(tmp_pair);
}