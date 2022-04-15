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

// TYPES
typedef const char * htab_key_t;
typedef int htab_value_t;

// STRUCTS
struct htab {
    size_t size;
    size_t arr_size;
    htab_item_t **arr_ptr;
};

typedef struct htab_pair {
    htab_key_t key;
    htab_value_t value;
} htab_pair_t;

typedef struct htab_item {
    struct htab_pair pair;
    struct htab_item *next;
} htab_item_t;

#endif