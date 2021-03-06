// Name: htab_item_init.c
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

// Initializes hash table item
htab_item_t *htab_item_init(htab_key_t key) {
	// Allocates memory for new item
	htab_item_t *item = malloc(sizeof(htab_item_t));
	if (item == 0) return NULL;

	// Allocates memory for new key
	char *tmp = malloc(strlen(key) + 1);
	strcpy(tmp, key);

	// Initializes item
	item->pair.key = tmp;
	item->next = NULL;
	item->pair.value = 0;

	return item;
}