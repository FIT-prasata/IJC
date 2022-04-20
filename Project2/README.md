# IJC PROJECT 2

My solution to second IJC project

## Compilation and build

ISO C11 for *.c files and ISO C++17 for *.cc files

```bash
make
```

## TASK A

Implement your own tail (prints last n number of lines in given file)

THIS IS NOT AN EQUIVALENT VERSION TO UNIX TAIL FUNCTION

### Windows run

```bash
tail.exe [params] [file]
```

### Linux run

```bash
./tail [params] [file]
```

### Usage

Line length implementation limit - 4095 characters

```c
arr[0] = char first_char;
// ...
arr[4094] = char last_char;
arr[4095] = '\n'; // new line character
arr[4096] = '\0'; // string end char
arr[4097] = '\0'; // Safety string end char
```

Prints warning message and continues with cut lines

```c
#define LINE_LENGTH_LIMIT 4098
```
For versions without param

```c
#define DEFAULT_LINES 10
```

Default stdin

```c
FILE *file = stdin;
```

```bash
tail <{filename} # STDIN
OR
tail {filename} # FILE
OR
tail -n {lines_num} <{filename} # STDIN WITH PARAM
OR
tail -n {lines_num} {filename} # FILE WITH PARAM
```

## TASK B

Rewrite C++ file (wordcount.cc) in C (wordcount.c) using hash table functions as a substitute for unordered_map C++ feature

### Windows run

Static library

```bash
wordcount.exe
```

Dynamic library

```bash
wordcount-dynamic.exe
```

### Linux run

```bash
./wordcount
```

Dynamic library

```bash
./wordcount-dynamic
```

### Usage

Word length implementation limit

```c
#define MAX_WORD_LEN 127
```

Default hash table size -> prime for more even item distribution

```c
#define HASH_TABLE_SIZE 4999
```

```bash
wordcount <{filename} # STDIN
OR
wordcount-dynamic <{filename} # STDIN
```

## Clean

### Windows

```bash
make win-clean
```

### Linux

```bash
make clean
```

## TODO

### testing
