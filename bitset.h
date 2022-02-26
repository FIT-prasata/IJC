// Name: bitset.h
// IJC-DU1 Solution
// Task: A
// Start date: 26.2.2022
// Author: Lukáš Zavadil
// Faculty: FIT
// Compiled: gcc (GCC) 9.2.0
// Git repository: https://github.com/lukaszavadil1/IJC


typedef unsigned long bitset_t[];

// INITIALIZES SET WITH GIVEN NAME AND SIZE
// PARAMS: set_name - Name of the bit set |
//         size - Size of the bit set
void bitset_create(bitset_t set_name, unsigned long int size) {
    // TODO
}

// ALLOCATES MEMORY FOR SET WITH GIVEN NAME AND SIZE
// PARAMS: set_name - Name of the bit set |
//         size - Size of the bit set
void bitset_alloc(bitset_t set_name, unsigned long int size) {
    // TODO
}

// FREES ALLOCATED MEMORY FOR SET OF GIVEN NAME
// PARAMS: set_name - Name of the bit set
void bitset_free(bitset_t set_name) {
    //TODO
}

// RETURNS THE SIZE OF SET WITH GIVEN NAME
// PARAMS: set_name - Name of the bit set
void bitset_size(bitset_t set_name) {
    //TODO
}

// SETS THE VALUE OF BIT IN BIT SET
// PARAMS: set_name - Name of the bit set |
//         index - Index for setting bit |
//         expression - if 0 -> set bit value to 0, else set bit value to 1
void bitset_setbit(bitset_t set_name, long index, int expression) {
    //TODO
}

// GETS THE VALUE OF BIT IN BIT SET
// PARAMS: set_name - Name of the bit set |
//         index - Index for getting bit
void bitset_getbit(bitset_t set_name, long index) {
    //TODO
}