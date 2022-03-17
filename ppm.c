// Name: ppm.c
// IJC-DU1 Solution
// Task: B
// Start date: 26.2.2022
// Author: Lukáš Zavadil
// Faculty: FIT
// Compiled: gcc (GCC) 9.2.0
// Git repository: https://github.com/lukaszavadil1/IJC

// LOCAL INCLUDES
#include "ppm.h"
#include "error.h"

struct ppm * ppm_read(const char * filename) {

    struct ppm *p;
    unsigned xsize, ysize;
    char format[3];

    FILE * f = fopen(filename, "rb");
    
    // Check if path to file is correct
    if (f == NULL) { 
        warning_msg("ppm_read: Nelze otevrit soubor %s", filename);
        fclose(f);
        return NULL;
    }

    // Check for correct file suffix - must be ".ppm"
    const char *suffix = &filename[strlen(filename)-4];
    if (strcmp(suffix, ".ppm")) {
        warning_msg("ppm_read: Spatny format souboru");
        fclose(f);
        return NULL;
    }

    // Read PPM file header
    fread(format, sizeof(char), sizeof(format), f);

    // Check for correct PPM format - must be P6
    if (format[0] != 'P' || format[1] != '6') {
        warning_msg("ppm_read: Spatny typ PPM souboru");
        fclose(f);
        return NULL;
    }

    // Check if image size is not exceeding the limit of (8000 * 8000 * 3)
    fscanf(f, "%u %u", &xsize, &ysize);
    if ((xsize * ysize * 3) > SIZE_LIMIT) {
        fclose(f);
        error_exit("ppm_read: Velikost souboru je vetsi nez pevne zadany limit");
    }
    // Struct init
    p = malloc((xsize * ysize * 3) + sizeof(struct ppm));
    if (p == NULL) {
        fclose(f);
        error_exit("ppm_read: Chyba alokace pameti");
    }
    p->xsize = xsize;
    p->ysize = ysize;

    fscanf(f, "%*d");

    // Check if size defined in file header is matching the actual size of the file
    if (fread(p->data, sizeof(char), p->xsize * p->ysize * 3, f) != p->xsize * p->ysize * 3) {
        fclose(f);
        free(p);
        error_exit("ppm_read: Velikost dat v souboru se neshoduje s daty v hlavicce");
    }
    fclose(f);
    return p;
}

void ppm_free(struct ppm *p) {
    free(p);
}
