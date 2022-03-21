# IJC
My solution to IJC projects

Compilation: gcc -g -std=c11 -pedantic -Wall -Wextra (optional -fsanitize=address for memory check)

## TASK A DONE

### Times for task A:

1.88s on AMD Ryzen 5 3500U using macros

1.96s using inline functions

## TASK  B DONE

### Task B secret message

Obrázek "Lenna" (zdroj: Wikipedie).

Používáme metodu podobnou steganografii - viz

http://en.wikipedia.org/wiki/Steganography

### Without optimalization, slower than -O2

```bash
gcc -O0
```

### Might need to switch to UTF-8 for task B to work properly

```bash
chcp 65001
```

### How to start task A without make file on WINDOWS

```bash
gcc -g -std=c11 -pedantic -Wall -Wextra -O2 -lm -Wl,--stack,38000 bitset.c error.c eratosthenes.c primes.c -o primes

primes.exe
```

### How to start task A without make file on LINUX

```bash
gcc -g -std=c11 -pedantic -Wall -Wextra -O2 -lm ulimit -s 40000 bitset.c error.c eratosthenes.c primes.c -o primes

./primes
```

### How to start task B without make file on WINDOWS

```bash
gcc -g -std=c11 -pedantic -Wall -Wextra -O2 -lm error.c eratosthenes.c steg-decode.c ppm.c -o steg-decode

steg-decode {filename}.ppm
```

### How to start task B without make file on WINDOWS

```bash
gcc -g -std=c11 -pedantic -Wall -Wextra -O2 -lm error.c eratosthenes.c steg-decode.c ppm.c -o steg-decode

./steg-decode {filename}.ppm
```

## TODO:

### Make file :)