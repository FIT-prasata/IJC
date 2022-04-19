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
#define HASH_TABLE_SIZE 31

int main(void) {
    FILE *file;
    file = stdin;

    htab_t *table;
    if ((table = htab_init(HASH_TABLE_SIZE)) == NULL) {
        fprintf(stderr, "Chyba alokace");
        return -1;
    };
    char output[MAX_WORD_LEN + 1];
    while(read_word(output, MAX_WORD_LEN, file) != EOF) {
        htab_lookup_add(table, output)->value++;
    }
    htab_print(table);
    htab_free(table);

    return 0;
}