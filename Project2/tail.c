// Name: tail.c
// IJC-DU2 Solution
// Task: A
// Start date: 28.3.2022
// Author: Lukáš Zavadil
// Faculty: FIT
// Compiled: gcc (GCC) 9.2.0
// Git repository: https://github.com/lukaszavadil1/IJC

// LOCAL INCLUDES
#include "structs.h"

// DEFINES
#define LINE_LENGTH_LIMIT 4095
#define DEFAULT_LINES 10

void arr_init(circ_arr_t *c, int num_lines) {
    c->size = num_lines;
    c->lines = malloc(sizeof(char *) * c->size);
    c->end = 0;
    c->input_num = 0;
}

void arr_dtor(circ_arr_t *c) {
    c->size = 0;
    free(c->lines);
    c->end = 0;
    c->input_num = 0;
}

void arr_add(circ_arr_t *c, line_t line) {
    line_t new_line = malloc(strlen(line) + 1);
    strcpy(new_line, line);
    c->lines[c->end] = new_line;
    c->end = (c->end + 1) % c->size;
    c->input_num++;
}

int main(const int argc, const char **argv) {
    FILE *file;
    char *buf[LINE_LENGTH_LIMIT];
    circ_arr_t c;
    switch (argc) {
        case 1:
            while (fgets(buf, LINE_LENGTH_LIMIT, stdin) != NULL) {
                arr_init(&c, DEFAULT_LINES);
                arr_add(&c, buf);
            }
        case 2:
            file = fopen(argv[1], "r");
            if (file == 0) {
                fprintf(stderr, "Nelze otevrit soubor %s", argv[1]);
                return -1;
            }
            while (fgets(buf, LINE_LENGTH_LIMIT, file) != EOF) {
                arr_init(&c, DEFAULT_LINES);
                arr_add(&c, buf);
            }
        case 3:
            if (strcmp(argv[1], "-n") == 1) {
                    fprintf(stderr, "Spatny argument %s", argv[1]);
            }
            if (argv[2][0] == "-") {
                // VALIDATE
            }
        case 4:
            if (strcmp(argv[1], "-n") == 1) {
                fprintf(stderr, "Spatny argument %s", argv[1]);
            }
            if (argv[2][0] == "-") {
                // VALIDATE
            }
            file = fopen(argv[3], "r");
            if (file == 0) {
                fprintf(stderr, "Nelze otevrit soubor %s", argv[3]);
                return -1;
            }
            while (fgets(buf, LINE_LENGTH_LIMIT, file) != EOF) {
                arr_init(&c, DEFAULT_LINES);
                arr_add(&c, buf);
            }
    }
    arr_dtor(&c);
}