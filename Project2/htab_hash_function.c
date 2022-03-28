// Name: htab_hash_function.c
// IJC-DU2 Solution
// Task: B
// Start date: 28.3.2022
// Author: Lukáš Zavadil
// Faculty: FIT
// Compiled: gcc (GCC) 9.2.0
// Git repository: https://github.com/lukaszavadil1/IJC

// LOCAL INCLUDES
#include "htab.h"

size_t htab_hash_function(const char *str) {
          uint32_t h = 0;
          const unsigned char *p;
          for(p = (const unsigned char*)str; *p != '\0'; p++)
              h = 65599 * h + *p;
          return h;
        }