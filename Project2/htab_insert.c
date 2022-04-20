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
	// If item already exists, returns false
	if (t->arr_ptr == NULL) { return false; }

	// Initializes hash table item
	htab_item_t *tmp = htab_item_init(key);

	// Inserts item to the front of the linked list
	int index = (htab_hash_function(key) % t->arr_size);
	tmp->next = t->arr_ptr[index];
	t->arr_ptr[index] = tmp;

    t->size++;

	return true;
}