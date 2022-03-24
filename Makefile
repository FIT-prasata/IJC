CC=gcc
CFLAGS=-g -std=c11 -pedantic -Wall -Wextra -O2

LIBS=-lm
INLINE=-DUSE_INLINE

all: primes primes-i steg-decode

# RUN TASK A ON LINUX

run: primes primes-i
	./primes
	./primes-i

# RUN TASK A ON WINDOWS

win-run: primes primes-i
	primes.exe
	primes-i.exe

# GENERATE TASK A .o FILES

bitset.o: bitset.c
	$(CC) $(CFLAGS) bitset.c -c -o bitset.o

bitset-i.o: bitset.c
	$(CC) $(CFLAGS) $(INLINE) bitset.c -c -o bitset-i.o

eratosthenes.o: eratosthenes.c
	$(CC) $(CFLAGS) eratosthenes.c -c -o eratosthenes.o

eratosthenes-i.o: eratosthenes.c
	$(CC) $(CFLAGS) $(INLINE) eratosthenes.c -c -o eratosthenes-i.o

primes.o: primes.c
	$(CC) $(CFLAGS) primes.c -c -o primes.o

primes-i.o: primes.c
	$(CC) $(CFLAGS) $(INLINE) primes.c -c -o primes-i.o

error.o: error.c
	$(CC) $(CFLAGS) error.c -c -o error.o

error-i.o: error.c
	$(CC) $(CFLAGS) $(INLINE) error.c -c -o error-i.o

# BUILD TASK A EXECUTABLES

# ADD -Wl,--stack,38000000 BEHIND THE CFLAGS TO WORK ON WINDOWS OR ulimit -s 38000 FOR LINUX

primes: eratosthenes.o bitset.o primes.o error.o
	$(CC) $(CFLAGS) eratosthenes.o bitset.o primes.o error.o -o primes $(LIBS)

primes-i: eratosthenes-i.o bitset-i.o primes-i.o error-i.o
	$(CC) $(CFLAGS) $(INLINE) eratosthenes-i.o bitset-i.o primes-i.o error-i.o -o primes-i $(LIBS)

# GENERATE TASK B .o FILES

ppm.o: ppm.c
	$(CC) $(CFLAGS) ppm.c -c -o ppm.o

steg-decode.o: steg-decode.c
	$(CC) $(CFLAGS) steg-decode.c -c -o steg-decode.o

# BUILD TASK B EXECUTABLES

steg-decode: steg-decode.o ppm.o error.o eratosthenes.o
	$(CC) $(CFLAGS) steg-decode.o ppm.o eratosthenes.o error.o -o steg-decode $(LIBS)

# DELETE ALL .o FILES

clean:
	rm *.o

win-clean:
	del *.o