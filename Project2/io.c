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
    int character, arr_index = 0;

    // Searches for first char of word
    while (isspace(character = getc(f)) && character != EOF);
    s[arr_index++] = character;

    // Loads characters to array until it reaches isspace character or EOF
    while ((isspace(character = getc(f))) == 0)
    {
        if (character == EOF)
            return EOF;

        s[arr_index++] = character;

        // Longer strings handle
        if (arr_index == (max - 1))
        {
            // Skips rest of the characters after reaching word size implementation limit
            while (isspace(character = getc(f)) && character != EOF);

            // Closes longer strings
            s[arr_index++] = '\0';
            return arr_index;
        }
    }
    // Closes strings if they somehow miss the '\0' character
    s[arr_index++] = '\0';
    return arr_index; 
}