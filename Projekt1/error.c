// Name: error.c
// IJC-DU1 Solution
// Task: B
// Start date: 26.2.2022
// Author: Lukáš Zavadil
// Faculty: FIT
// Compiled: gcc (GCC) 9.2.0
// Git repository: https://github.com/lukaszavadil1/IJC

// LOCAL INCLUDES
#include "error.h"

// Error handling function with warning message
void warning_msg(const char *fmt, ...) {
    va_list msg;
    va_start(msg, fmt);
    fprintf(stderr, "CHYBA: ");
    vfprintf(stderr, fmt, msg);
    va_end(msg);
}

// Error handling function with return value 1
void error_exit(const char *fmt, ...) {
    va_list msg;
    va_start(msg, fmt);
    fprintf(stderr, "CHYBA: ");
    vfprintf(stderr, fmt, msg);
    va_end(msg);
    exit(1);
}