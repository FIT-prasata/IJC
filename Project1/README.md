# IJC PROJECT 1
My solution to first IJC project

## Compilation:

```bash
gcc -g -std=c11 -pedantic -Wall -Wextra (optional -fsanitize=address for memory check)
```

## TASK A

Print the last 10 prime numbers from 300 milion number range using bit field to use minimal amount of memory

### Times for task A:

1.88s on AMD Ryzen 5 3500U using macros

1.96s using inline functions

### Task A build on Windows

Automated build and run of both primes file versions

```bash
make win-run
```

OR

```bash
make

primes.exe

primes-i.exe
```

for automated build and manual run option

### Task A build on Linux

Automated build and run of both primes file versions

```bash
make run
```

OR

```bash
make

./primes

./primes-i
```

for automated build and manual run option

## TASK B

Decode a secret message from the .ppm file using Eratosthenes algorithm from task A 

### Task B secret message

Obrázek "Lenna" (zdroj: Wikipedie).

Používáme metodu podobnou steganografii - viz

http://en.wikipedia.org/wiki/Steganography

### Task B build on Windows

```bash
make

steg-decode.exe {filename}.ppm
```

### Task B build on Linux

```bash
make

./steg-decode {filename}.ppm
```

## Useful stuff

### Test correctness of prime numbers

Works only on Linux

```bash
./primes | factor
```

OR

```bash
./primes-i | factor
```

### Might need to switch to UTF-8 encoding for task B to work properly

```bash
chcp 65001
```

### Destroy .o files
```bash
make clean
```

### Enlarge stack for Windows
```bash
-Wl,--stack,38000000
```

### Enlarge stack for Linux
```bash
ulimit -s 38000 
```