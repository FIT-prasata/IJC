// Name: structs.h
// IJC-DU2 Solution
// Task: B
// Start date: 28.3.2022
// Author: Lukáš Zavadil
// Faculty: FIT
// Compiled: gcc (GCC) 9.2.0
// Git repository: https://github.com/lukaszavadil1/IJC

#ifndef __STRUCTS_H__
#define __STRUCTS_H__

// LOCAL INCLUDES
#include "htab.h"

// STRUCTS
// HASH TABLE
struct htab {
    size_t size;
    size_t arr_size;
    htab_item_t **arr_ptr;
};

// HASH TABLE ITEM
struct htab_item {
    struct htab_pair pair;
    struct htab_item *next;
};

// HASH TABLE FUNCTIONS
htab_item_t *htab_item_init(htab_key_t key); 
void htab_print(htab_t *t);
bool htab_insert(htab_t *t, htab_key_t key);

#endif