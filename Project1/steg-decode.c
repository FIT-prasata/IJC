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
#include "eratosthenes.h"

// EXTERNAL INCLUDES
#include <stdio.h>

// DEFINES
#define HEX_ONE 0x01
#define HEX_ZERO 0x00
#define START_INDEX 29

int main(int argc, char* argv[]) {
    if (argc == 2) {
        unsigned long bit_shift = 0, is_valid_string = 0;
        char secret_message[1] = {HEX_ZERO};

        // Struct init
        struct ppm *p = ppm_read(argv[1]);

        // Bit set init
        bitset_alloc(set_name, p->xsize * p->ysize * 3);
        Eratosthenes(set_name);
        
        // Loop through the characters on prime indexes
        for (unsigned long i = START_INDEX; i < (p->xsize * p->ysize * 3); i++) {
            if (bitset_getbit(set_name, i) == 0) {

                // Store the LSB of character on index from 0 to 7 based on the value of bit_shift
                *secret_message |= ((p->data[i] & HEX_ONE) << ((unsigned long)bit_shift++));

                // Separate 8 bit characters
                if ((bit_shift % CHAR_BIT) == 0) {
                    bit_shift = 0;

                    // Validates string if its last char == '\0'
                    if (*secret_message == 0) {
                        is_valid_string = 1;
                        break;
                    }

                    // Prints character to stdout and resets secret_message
                    putchar(*secret_message);
                    *secret_message = HEX_ZERO;
                }
            }
        }

        // Check if the string is valid
        if (is_valid_string == 0) {
                ppm_free(p);
                bitset_free(set_name);
                error_exit("main: Nenalezen konec retezce");
        }

        // New line after secret message for linux
        putchar('\n');

        // Free allocated memory
        ppm_free(p);
        bitset_free(set_name);
    }
    else {
        error_exit("Spatny pocet argumentu");
    }
    return 0;
}