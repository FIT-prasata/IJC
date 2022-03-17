// Name: steg-decode.c
// IJC-DU1 Solution
// Task: B
// Start date: 26.2.2022
// Author: Lukáš Zavadil
// Faculty: FIT
// Compiled: gcc (GCC) 9.2.0
// Git repository: https://github.com/lukaszavadil1/IJC


// LOCAL INCLUDES
#include "ppm.h"

// EXTERNAL INCLUDES
#include <stdio.h>

int main(int argc, char* argv[]) {
    if (argc == 2) {
        struct ppm *p;
        p = ppm_read(argv[1]);

        // Bit set init
        bitset_alloc(set_name, p->xsize * p->ysize * 3);
        Eratosthenes(set_name);

        char *secret_message = (char *)malloc(sizeof(char));
        if (secret_message == NULL) {
            ppm_free(p);
            error_exit("Chyba alokace pameti");
        }

        int bit_shift = 0, pos = 0;
        for (int i = 29; i < p->xsize * p->ysize * 3; i++) {
            if (bitset_getbit(set_name, i) == 0) {
                // TODO
            }
        }

        ppm_free(p);
        bitset_free(set_name);
    }
    else {
        error_exit("Spatny pocet argumentu");
    }
}