# IJC
My solution to IJC projects

Compilation: gcc -g -std=c11 -pedantic -Wall -Wextra (optional -fsanitize=address for memory check)

## TASK A DONE

### Times:

1.88s on AMD Ryzen 5 3500U using macros

1.96s using inline functions

### Without optimalization, slower than -O2

```bash
gcc -O0
```

### How to start without make file on WINDOWS

```bash
gcc -g -std=c11 -pedantic -Wall -Wextra -O2 -lm -Wl,--stack,38000 bitset.c error.c eratosthenes.c primes.c -o primes

primes.exe
```

### How to start without make file on LINUX

```bash
gcc -g -std=c11 -pedantic -Wall -Wextra -O2 -lm ulimit -s 40000 bitset.c error.c eratosthenes.c primes.c -o primes

./primes
```

## TASK B TODO:

### Define RGB struct and essential functions

### Implement Eratosthenes algorithm

### Design data limits

### Make file :)