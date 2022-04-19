// Name: read_word.c
// IJC-DU2 Solution
// Task: B
// Start date: 28.3.2022
// Author: Lukáš Zavadil
// Faculty: FIT
// Compiled: gcc (GCC) 9.2.0
// Git repository: https://github.com/lukaszavadil1/IJC

// LOCAL INCLUDES
#include "io.h"

// Reads one word from the given file and returns its length if the file is not empty, else returns EOF
int read_word(char *s, int max, FILE *f) {
    int word_char, word_len = 0;
    bool is_empty = true;
    while (isspace(word_char = getc(f)) && word_char != EOF);
    s[word_len++] = word_char;
    while ((word_char = getc(f)) != EOF) {
        if (isspace(word_char)) { break; }
        s[word_len++] = word_char;
        if (is_empty) { is_empty = false; }
        if (word_len == (max - 1)) { 
            while (!isspace(word_char = getc(f)) && word_char != EOF);
            break;
        }
    }
    if (is_empty) {word_len = EOF; }
    else {
        if (word_len >= max) {
            fprintf(stderr, "Slovo %s prekrocilo implementacni limit maximalni delky %d znaku\n", s, max);
            word_len = max;
        }
        s[word_len] = '\0';
    }
    return word_len;
}