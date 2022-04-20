CC=gcc
CFLAGS=-g -std=c11 -pedantic -Wall -Wextra
FPIC=-fPIC
SHARED=-shared
NOLINK=-c
LIB=htab.h structs.h
XLOGIN=xzavad20

OFILES=htab_bucket_count.o htab_clear.o htab_erase.o htab_find.o htab_for_each.o htab_free.o htab_hash_function.o htab_init.o htab_insert.o htab_item_init.o htab_lookup_add.o htab_print.o htab_resize.o htab_size.o io.o wordcount.o

all: tail wordcount wordcount-dynamic libhtab.so libhtab.a

# GENERATE TASK A .o FILES

tail.o: tail.c
	$(CC) $(CFLAGS) $(NOLINK) $< -o $@

# BUILD TASK A EXECUTABLES

tail: tail.o
	$(CC) $(CFLAGS) $< -o $@

# GENERATE TASK B .o FILES

htab_bucket_count.o: htab_bucket_count.c $(LIB)
	$(CC) $(CFLAGS) $(NOLINK) $(FPIC) $< -o $@

htab_clear.o: htab_clear.c $(LIB)
	$(CC) $(CFLAGS) $(NOLINK) $(FPIC) $< -o $@

htab_erase.o: htab_erase.c $(LIB)
	$(CC) $(CFLAGS) $(NOLINK) $(FPIC) $< -o $@

htab_find.o: htab_find.c $(LIB)
	$(CC) $(CFLAGS) $(NOLINK) $(FPIC) $< -o $@

htab_for_each.o: htab_for_each.c $(LIB)
	$(CC) $(CFLAGS) $(NOLINK) $(FPIC) $< -o $@

htab_free.o: htab_free.c $(LIB)
	$(CC) $(CFLAGS) $(NOLINK) $(FPIC) $< -o $@

htab_hash_function.o: htab_hash_function.c $(LIB)
	$(CC) $(CFLAGS) $(NOLINK) $(FPIC) $< -o $@

htab_init.o: htab_init.c $(LIB)
	$(CC) $(CFLAGS) $(NOLINK) $(FPIC) $< -o $@

htab_insert.o: htab_insert.c $(LIB)
	$(CC) $(CFLAGS) $(NOLINK) $(FPIC) $< -o $@

htab_item_init.o: htab_item_init.c $(LIB)
	$(CC) $(CFLAGS) $(NOLINK) $(FPIC) $< -o $@

htab_lookup_add.o: htab_lookup_add.c $(LIB)
	$(CC) $(CFLAGS) $(NOLINK) $(FPIC) $< -o $@

htab_print.o: htab_print.c $(LIB)
	$(CC) $(CFLAGS) $(NOLINK) $(FPIC) $< -o $@

htab_resize.o: htab_resize.c $(LIB)
	$(CC) $(CFLAGS) $(NOLINK) $(FPIC) $< -o $@

htab_size.o: htab_size.c $(LIB)
	$(CC) $(CFLAGS) $(NOLINK) $(FPIC) $< -o $@

wordcount.o: wordcount.c
	$(CC) $(CFLAGS) $(NOLINK) $(FPIC) $< -o $@

io.o: io.c io.h
	$(CC) $(CFLAGS) $(NOLINK) $(FPIC) $< -o $@

# LIBRARIES

libhtab.so: $(OFILES)
	$(CC) $(CFLAGS) $(FPIC) $(SHARED) $(OFILES) -o $@

libhtab.a: $(OFILES)
	ar rcs libhtab.a $(OFILES)

# BUILD TASK B EXECUTABLES

wordcount: $(OFILES) libhtab.a
	$(CC) $(CFLAGS) $^ -o $@

wordcount-dynamic: $(OFILES) libhtab.so
	$(CC) $(CFLAGS) $^ -o $@

# DELETE ALL .o FILES, EXECUTABLES AND LIBRARIES

clean:
	rm *.o tail wordcount wordcount-dynamic libhtab.so libhtab.a

win-clean:
	del *.o tail.exe wordcount.exe wordcount-dynamic.exe libhtab.so libhtab.a

pack:
	zip $(XLOGIN) *.c *.h Makefile README.md

unpack:
	unzip $(XLOGIN).zip
	rm $(XLOGIN).zip