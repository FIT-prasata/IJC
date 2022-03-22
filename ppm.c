// Name: ppm.c
// IJC-DU1 Solution
// Task: B
// Start date: 26.2.2022
// Author: Lukáš Zavadil
// Faculty: FIT
// Compiled: gcc (GCC) 9.2.0
// Git repository: https://github.com/lukaszavadil1/IJC

// DEFINES
#define BUFFER_SIZE 3

// LOCAL INCLUDES
#include "ppm.h"
#include "error.h"

// PARAMS: filename - Name of the file
struct ppm * ppm_read(const char * filename) {

    struct ppm *p;
    unsigned xsize, ysize, color_range;
    char format[BUFFER_SIZE];

    // Open binary file in read mode 
    FILE * f = fopen(filename, "rb");
    
    // Check if path to file is correct
    if (f == NULL) { 
        warning_msg("ppm_read: Nelze otevrit soubor %s", filename);
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

    // Read size values and color range 
    fscanf(f, "%u %u %u", &xsize, &ysize, &color_range);

    // Check if image size is not exceeding the limit of (8000 * 8000 * 3)
    if ((xsize * ysize * 3) > SIZE_LIMIT) {
        fclose(f);
        warning_msg("ppm_read: Velikost souboru je vetsi nez pevne zadany limit");
    }

    // Skip the '\n' character so that the next fread() reads wanted file data
    while (fgetc(f) != '\n');

    // Struct memory alloc
    p = malloc((xsize * ysize * 3) + sizeof(struct ppm));
    if (p == NULL) {
        fclose(f);
        error_exit("ppm_read: Chyba alokace pameti");
    }

    // Set struct size values
    p->xsize = xsize;
    p->ysize = ysize;

    // Check if size defined in file header is matching the actual size of the file
    if (fread(p->data, sizeof(char), p->xsize * p->ysize * 3, f) != p->xsize * p->ysize * 3) {
        fclose(f);
        ppm_free(p);
        error_exit("ppm_read: Velikost dat v souboru se neshoduje s daty v hlavicce");
    }

    fclose(f);
    return p;
}

// Free the structure
void ppm_free(struct ppm *p) {
    free(p);
}
