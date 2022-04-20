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

    // Loops through all items
    for (size_t i = 0; i < t->arr_size; ++i) {
        curr = t->arr_ptr[i];

        // Loops through all items of the linked list
        while (curr != NULL) {
            tmp = curr;
            curr = curr->next;

            // Erase hash table item
            if (htab_erase(t, tmp->pair.key) == false) fprintf(stderr, "Chyba mazani\n");

            // Check if the hash table has resized
            if (before_size != t->arr_size) {

                // Starts looping from the first index
                i = -1;

                // Saves current size to temp variable
                before_size = t->arr_size;

                break;
            }
        }
    }
    
    t->size = 0;
}