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

// Executes given function for each item of the hash table
void htab_for_each(const htab_t * t, void (*f)(htab_pair_t *data)) {
    htab_key_t tmp_key;

    for (size_t i = 0; i < t->arr_size; i++) {
        htab_item_t *tmp = t->arr_ptr[i];
        while (tmp != NULL) {

            // Loads key values to tmp variable
            tmp_key = tmp->pair.key;

            // Function call
            (f)(&tmp->pair);

            // Preserves key values by rewriting them
            tmp->pair.key = tmp_key;
            tmp = tmp->next;
        }
    }
}