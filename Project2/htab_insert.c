// Name: htab_insert.c
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

// Inserts an item to hash table
bool htab_insert(htab_t *t, htab_key_t key) {
	if (t->arr_ptr == NULL) { return false; }
	htab_item_t *tmp = htab_item_init(key);
	int index = (htab_hash_function(key) % t->arr_size);
	tmp->next = t->arr_ptr[index];
	t->arr_ptr[index] = tmp;
    t->size++;
	return true;
}