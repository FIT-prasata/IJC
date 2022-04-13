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
    for (int i = 0; i < t->arr_size; i++) {
        if (htab_erase(t, t->arr_ptr[i]->pair.key) == 0) {
            fprintf(stderr, "Chyba smazani prvku tabulky");
        }
    }
    t->size = 0;
}