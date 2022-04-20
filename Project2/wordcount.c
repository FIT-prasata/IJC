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

// DEFINES
#define MAX_WORD_LEN 127
#define HASH_TABLE_SIZE 4999 // Prime number, pick based on book sizes

// Counts the number of occurences for each word in the file
int main(void) {
    FILE *file = stdin;
    htab_t *table;
    htab_pair_t *pair;
    char output[MAX_WORD_LEN + 1];
    int word_len;
    bool first_longer = true;

    // Check for hash table allocation error
    if ((table = htab_init(HASH_TABLE_SIZE)) == NULL) {
        fprintf(stderr, "Chyba alokace");
        return -1;
    };

    // Adds item to hash table or only increases its value if it is already there
    while((word_len = read_word(output, MAX_WORD_LEN, file)) != EOF) {
        if ((word_len > MAX_WORD_LEN) && first_longer) {
            fprintf(stderr, "Radek je delsi jak implementacni limit, zbytek delsich radku bude zkracen\n");
            first_longer = false;
        }
        if ((pair = htab_lookup_add(table, output)) == NULL) {
            fprintf(stderr, "Chyba alokace pameti");
            return -1;
        }
        pair->value++;
    }

    // Print the hash table
    htab_print(table);

    // Frees all alocated memory
    htab_free(table);

    return 0;
}