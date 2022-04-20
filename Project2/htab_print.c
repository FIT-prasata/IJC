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
    printf("Start of hash table\n");
    for(int i = 0; i < (int)t->arr_size; i++){

        // Print array pointer to zero items
        if (t->arr_ptr[i] == NULL){ printf("\t%i\t---\n", i); }

        // Print all items in linked list
        else{
            printf("\t%i\t ", i);
            htab_item_t *tmp = t->arr_ptr[i];
            while(tmp != NULL){
                printf("[%s\t%d] - ", tmp->pair.key, tmp->pair.value);
                tmp = tmp->next;
            }
            printf("\n");
        }
    }
    printf("End of hash table\n");
}