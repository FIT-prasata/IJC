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
    int c;
    int index = 0;

    while (isspace(c = getc(f)) && c != EOF);
    s[index++] = c;

    while (!(isspace(c = getc(f))))
    {
        if (c == EOF)
            return EOF;
        s[index++] = c;
        if (index == max - 1)
        {
            while (isspace(c = getc(f)) && c != EOF);
            s[index] = '\0';
            return index + 1;
        }
    }
    s[index] = '\0';
    return index + 1; 
}