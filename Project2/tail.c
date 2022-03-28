// Name: tail.c
// IJC-DU2 Solution
// Task: A
// Start date: 28.3.2022
// Author: Lukáš Zavadil
// Faculty: FIT
// Compiled: gcc (GCC) 9.2.0
// Git repository: https://github.com/lukaszavadil1/IJC

#include <stdio.h>

#define LINE_LENGTH_LIMIT 4095

int main(const int argc, const char **argv) {
    if (argc == 1) {
        // TODO - READ STDIN
    }
    else if (argc == 2) {
        // TODO - READ FILE
    }
    else if (argc == 3) {
        // TODO - READ FILE WITH -n num ARGUMENT
    }
    else {
        fprintf(stderr, "Spatny pocet argumentu");
    }
    return 0;
}