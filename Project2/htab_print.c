// Name: htab_print.c
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

// Prints the hash table
void htab_print(htab_t *t){
    for(int i = 0; i < (int)t->arr_size; i++){
        htab_item_t *tmp = t->arr_ptr[i];
        // Print all items in linked list
        while(tmp != NULL){
            printf("%s\t%d\n", tmp->pair.key, tmp->pair.value);
            tmp = tmp->next;
        }
    }
}