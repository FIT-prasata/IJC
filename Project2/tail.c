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

// EXTERNAL INCLUDES
#include <stdio.h>
#include <string.h>

// DEFINES
#define LINE_LENGTH_LIMIT 4095

void arr_init(circ_arr_t *c, int num_lines) {
    c->size = num_lines;
    c->lines = malloc(sizeof(char *) * c->size);
    c->start = 0;
    c->end = 0;
    c->input_num = 0;
}

bool is_empty_arr(circ_arr_t *c) {
    return (c->input_num == 0);
}

bool is_full_arr(circ_arr_t *c) {
    return (c->input_num == c->size);
}

void arr_dtor(circ_arr_t *c) {
    c->size = 0;
    free(c->lines);
    c->start = 0;
    c->end = 0;
    c->input_num = 0;
}

bool arr_add(circ_arr_t *c, line_t line) {
    if (is_full_arr(c)) return false;
    c->lines[c->end] = line;
    c->end = (c->end + 1) % c->size;
    c->input_num++;
}

int arr_rm(circ_arr_t *c) {
    line_t result;
    if (is_empty_arr(c)) return false;
    
    result = c->lines[c->start];
    c->start = (c->start + 1) % c->size;
    c->input_num--;

    return result;
}

int main(const int argc, const char **argv) {
    circ_arr_t c;
    init_arr(&c);
    add_arr(&c, "asDSADSADAS");
    add_arr(&c, "xDDDDDDDDDD");
    add_arr(&c, "SADASFASF");
}