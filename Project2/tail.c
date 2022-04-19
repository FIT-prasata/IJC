// Name: tail.c
// IJC-DU2 Solution
// Task: A
// Start date: 28.3.2022
// Author: Lukáš Zavadil
// Faculty: FIT
// Compiled: gcc (GCC) 9.2.0
// Git repository: https://github.com/lukaszavadil1/IJC

// EXTERNAL INCLUDES
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// DEFINES, TYPEDEFS AND STRUCTS
#define LINE_LENGTH_LIMIT 127
#define DEFAULT_LINES 10

typedef char ** lines_t;
typedef char * line_t;

typedef struct circ_arr {
    lines_t lines;
    size_t end;
    size_t size;
} circ_arr_t;

// Array init function
void arr_init(circ_arr_t *c, int num_lines) {
    c->size = num_lines;
    c->lines = malloc(sizeof(char *) * c->size);
    for (size_t i = 0; i < c->size; i++) {
        c->lines[i] = NULL;
    }
    c->end = 0;
}

// Array destructor function
void arr_dtor(circ_arr_t *c) {
    for (size_t i = 0; i < c->size; i++) {
        free(c->lines[i]);
    }
    free(c->lines);
    c->size = 0;
    c->end = 0;
}

// Adds line to circullar array
void arr_add(circ_arr_t *c, line_t line) {
    line_t new_line = realloc(c->lines[c->end], strlen(line) + 1);
    c->lines[c->end] = new_line;
    strcpy(new_line, line);
    c->end = (c->end + 1) % c->size;
}

// Print all lines from circullar array
void arr_print(circ_arr_t *c) {
    size_t index = c->end;
    for (size_t i = 0; i < c->size; i++) {
        if (c->lines[index] != NULL) {
            printf("%s", c->lines[index]);
        }
        index++;
        index %= c->size;
    }
}

int main(const int argc, const char **argv) {
    FILE *file = stdin;
    circ_arr_t c;
    char buf[LINE_LENGTH_LIMIT] = {'\0'};
    char *end_ptr;
    int n, ch;
    bool overflow = false;

    switch (argc) {
        case 1: // Usage: <[filename]

            // Array init
            arr_init(&c, DEFAULT_LINES);

            // Copy lines to array from stdin
            while (fgets(buf, LINE_LENGTH_LIMIT, file) != NULL) {
                if (buf[LINE_LENGTH_LIMIT-2] != '\0') {
                    if (overflow == false) {
                        fprintf(stderr, "Radek presahuje maximalni limit znaku, radky budou zkraceny\n");
                        overflow = true;
                    }
                    buf[LINE_LENGTH_LIMIT-3] = '\n';
                    buf[LINE_LENGTH_LIMIT-2] = '\0';
                    while ((ch = fgetc(file)) != '\n' && ch != EOF);
                }
                arr_add(&c, buf);
            }

            break;
        case 2: // Usage: [filename]

            // First argument validation
            file = fopen(argv[1], "r");
            if (file == 0) {
                fprintf(stderr, "Nelze otevrit soubor %s", argv[1]);
                fclose(file);
                return -1;
            }

            // Array init
            arr_init(&c, DEFAULT_LINES);

            // Copy lines to array from file
            while (fgets(buf, LINE_LENGTH_LIMIT, file) != NULL) {
                if (buf[LINE_LENGTH_LIMIT-2] != '\0') {
                    if (overflow == false) {
                        fprintf(stderr, "Radek presahuje maximalni limit znaku, radky budou zkraceny\n");
                        overflow = true;
                    }
                    buf[LINE_LENGTH_LIMIT-3] = '\n';
                    buf[LINE_LENGTH_LIMIT-2] = '\0';
                    while ((ch = fgetc(file)) != '\n' && ch != EOF);
                }
                arr_add(&c, buf);
            }

            break;
        case 3: // Usage: [-n] [number of lines] <[filename]

            // First argument validation
            if (strcmp(argv[1], "-n") != 0) {
                fprintf(stderr, "Spatny argument %s\n", argv[1]);
                return -1;
            }

            // Second argument validation
            n = strtoul(argv[2], &end_ptr, 10);
            if (strcmp(end_ptr, "") != 0) {
                fprintf(stderr, "Spatny argument %s\n", argv[2]);
                return -1;
            }

            // Array init
            arr_init(&c, abs(n));

            // Copy lines to array from stdin
            while (fgets(buf, LINE_LENGTH_LIMIT, file) != NULL) {
                if (buf[LINE_LENGTH_LIMIT-2] != '\0') {
                    if (overflow == false) {
                        fprintf(stderr, "Radek presahuje maximalni limit znaku, radky budou zkraceny\n");
                        overflow = true;
                    }
                    buf[LINE_LENGTH_LIMIT-3] = '\n';
                    buf[LINE_LENGTH_LIMIT-2] = '\0';
                    while ((ch = fgetc(file)) != '\n' && ch != EOF);
                }
                arr_add(&c, buf);
            }

            break;
        case 4: // Usage: [-n] [number of lines] [filename]

            // First argument validation
            if (strcmp(argv[1], "-n") != 0) {
                fprintf(stderr, "Spatny argument %s\n", argv[1]);
                return 1;
            }

            // Second argument validation
            n = strtoul(argv[2], &end_ptr, 10);
            if (strcmp(end_ptr, "") != 0) {
                fprintf(stderr, "Spatny argument %s\n", argv[2]);
                return -1;
            }

            // Third argument validation
            file = fopen(argv[3], "r");
            if (file == 0) {
                fprintf(stderr, "Nelze otevrit soubor %s\n", argv[3]);
                fclose(file);
                return -1;
            }

            // Array init
            arr_init(&c, abs(n));

            // Copy lines to array from file
            while (fgets(buf, LINE_LENGTH_LIMIT, file) != NULL) {
                if (buf[LINE_LENGTH_LIMIT-2] != '\0') {
                    if (overflow == false) {
                        fprintf(stderr, "Radek presahuje maximalni limit znaku, radky budou zkraceny\n");
                        overflow = true;
                    }
                    buf[LINE_LENGTH_LIMIT-3] = '\n';
                    buf[LINE_LENGTH_LIMIT-2] = '\0';
                    while ((ch = fgetc(file)) != '\n' && ch != EOF);
                }
                arr_add(&c, buf);
            }

            break;
    }

    // Print last n lines of the file
    arr_print(&c);

    // Array destructor
    arr_dtor(&c);
    fclose(file);
}