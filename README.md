# IJC
My solution to IJC projects

Compilation: gcc -g -std=c11 -pedantic -Wall -Wextra (optional -fsanitize=address for memory check)

## TODO TASK A

### Check if works on 32 bit machine

```bash
gcc -m32
```

### Create first version of make file

```bash
gcc -DUSE_INLINE
```
### Stack expand for Windows

```bash
gcc -Wl,--stack,38000000
```

### Final version

```bash
gcc -g -std=c11 -pedantic -Wall -Wextra -O2 -lm -Wl,--stack,38000000 bitset.c error.c eratosthenes.c primes.c -o primes
```