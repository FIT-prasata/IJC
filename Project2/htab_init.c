// Name: htab_init.c
// IJC-DU2 Solution
// Task: B
// Start date: 28.3.2022
// Author: Lukáš Zavadil
// Faculty: FIT
// Compiled: gcc (GCC) 9.2.0
// Git repository: https://github.com/lukaszavadil1/IJC

// LOCAL INCLUDES
#include "htab.h"
#include "structs.h"

// Allocates memory for the hash table struct and for its n items
htab_t *htab_init(size_t n) {
  // Memory allocation
  htab_t *tbl = malloc(sizeof(htab_t));
  if (tbl == 0) {
    return NULL;
  }
  
  // Hash table values initialization
  tbl->size = 0;
  tbl->arr_size = n;
  tbl->arr_ptr = malloc(sizeof(htab_item_t*) * tbl->arr_size);

  // Linked list pointers initialization
  for (size_t i = 0; i < tbl->arr_size; i++) {
    tbl->arr_ptr[i] = NULL;
  }
    
  return tbl;
}