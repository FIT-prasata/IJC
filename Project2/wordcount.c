// Name: wordcount.c
// IJC-DU2 Solution
// Task: B
// Start date: 28.3.2022
// Author: Lukáš Zavadil
// Faculty: FIT
// Compiled: gcc (GCC) 9.2.0
// Git repository: https://github.com/lukaszavadil1/IJC

// C version of wordcount.cc

// LOCAL INCLUDES
#include "htab.h"
#include "structs.h"
#include "io.h"

// EXTERNAL INCLUDES
#include <stdlib.h>

// DEFINES
#define MAX_WORD_LEN 127
#define HASH_TABLE_SIZE 4999 // NEEDS TESTING

// Counts the number of occurences for each word in the file
int main(void) {
    FILE *file = stdin;
    htab_t *table;
    char output[MAX_WORD_LEN + 1];

    // Check for hash table allocation error
    if ((table = htab_init(HASH_TABLE_SIZE)) == NULL) {
        fprintf(stderr, "Chyba alokace");
        return -1;
    };

    // Adds item to hash table or only increases its value if it is already there
    while(read_word(output, MAX_WORD_LEN, file) != EOF) {
        htab_lookup_add(table, output)->value++;
    }

    // Print the hash table
    htab_print(table);

    // Frees all alocated memory
    htab_free(table);

    return 0;
}