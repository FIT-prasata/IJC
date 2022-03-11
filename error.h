// Name: error.h
// IJC-DU1 Solution
// Task: B
// Start date: 26.2.2022
// Author: Lukáš Zavadil
// Faculty: FIT
// Compiled: gcc (GCC) 9.2.0
// Git repository: https://github.com/lukaszavadil1/IJC

// EXTERNAL INCLUDES
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

void warning_msg(const char *fmt, ...);

void error_exit(const char *fmt, ...);