// Name: htab.h
// IJC-DU2 Solution
// Task: B
// Start date: 28.3.2022
// Author: Lukáš Zavadil
// Faculty: FIT
// Compiled: gcc (GCC) 9.2.0
// Git repository: https://github.com/lukaszavadil1/IJC

#ifndef __HTAB_H__
#define __HTAB_H__

// EXTERNAL INCLUDES
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// DEFINES
#define AVG_LEN_MIN 2
#define AVG_LEN_MAX 10

// HASH TABLE
struct htab;
typedef struct htab htab_t;

// HASH TABLE ITEM
struct htab_item;
typedef struct htab_item htab_item_t;

// HASH TABLE PAIR
typedef const char * htab_key_t;
typedef int htab_value_t;

typedef struct htab_pair {
    htab_key_t key;
    htab_value_t value;
} htab_pair_t;

// HASH FUNCTION
size_t htab_hash_function(htab_key_t str);

// HASH TABLE CONSTRUCTOR
htab_t *htab_init(size_t n);

// RETURNS NUMBER OF HASH TABLE ITEMS
size_t htab_size(const htab_t * t);

// RETURNS NUMBER OF HASH TABLE ITEM POINTERS
size_t htab_bucket_count(const htab_t * t);

// HASH TABLE RESIZE
void htab_resize(htab_t *t, size_t newn);

// HASH TABLE FIND ITEM
htab_pair_t * htab_find(htab_t * t, htab_key_t key);

// HASH TABLE FIND OR ADD ITEM
htab_pair_t * htab_lookup_add(htab_t * t, htab_key_t key);

// HASH TABLE ERASE ITEM
bool htab_erase(htab_t * t, htab_key_t key);

// CALLS FUNCTION FOR EACH HASH TABLE ITEM
void htab_for_each(const htab_t * t, void (*f)(htab_pair_t *data));

// DELTES ALL ITEMS IN HASH TABLE
void htab_clear(htab_t * t);

// DELETES HASH TABLE
void htab_free(htab_t * t);

#endif
