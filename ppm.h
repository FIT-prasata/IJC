// Name: ppm.h
// IJC-DU1 Solution
// Task: B
// Start date: 26.2.2022
// Author: Lukáš Zavadil
// Faculty: FIT
// Compiled: gcc (GCC) 9.2.0
// Git repository: https://github.com/lukaszavadil1/IJC

// LOCAL INCLUDES
#include "error.h"
#include "bitset.h"

// EXTERNAL INCLUDES
#include <string.h>

// DEFINES
#define SIZE_LIMIT (8000 * 8000 * 3)

struct ppm {
    unsigned xsize;
    unsigned ysize;
    char data[];
};

struct ppm * ppm_read(const char * filename);

// Frees memory allocated in ppm_read
void ppm_free(struct ppm *p);