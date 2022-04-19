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
#include <string.h>     // size_t
#include <stdbool.h>    // bool
#include <stdint.h>     // uintX_t -> hash_function 
#include <stdio.h>      // stderr
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

// Funkce pro práci s tabulkou:
htab_t *htab_init(size_t n);                    // konstruktor tabulky

size_t htab_size(const htab_t * t);             // počet záznamů v tabulce

size_t htab_bucket_count(const htab_t * t);     // velikost pole

void htab_resize(htab_t *t, size_t newn);       // změna velikosti pole
                                                // (umožňuje rezervaci místa)

htab_pair_t * htab_find(htab_t * t, htab_key_t key);  // hledání
htab_pair_t * htab_lookup_add(htab_t * t, htab_key_t key);

bool htab_erase(htab_t * t, htab_key_t key);    // ruší zadaný záznam

// for_each: projde všechny záznamy a zavolá na ně funkci f
// Pozor: f nesmí měnit klíč .key ani přidávat/rušit položky
void htab_for_each(const htab_t * t, void (*f)(htab_pair_t *data));

void htab_clear(htab_t * t);    // ruší všechny záznamy
void htab_free(htab_t * t);     // destruktor tabulky

#endif // __HTAB_H__
