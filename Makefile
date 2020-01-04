# -*- MakeFile -*-

CC = gcc

all: caesarcipher test

caesarcipher: main.o caesar_cipher.o
	$(CC) main.o caesar_cipher.o -o output

main.o: main.c caesar_cipher.h
	$(CC) -c main.c

caesar_cipher.o: caesar_cipher.c caesar_cipher.h
	$(CC) -c caesar_cipher.c

test: test.o caesar_cipher.o
	$(CC) test.o caesar_cipher.o -o tests

test.o: test.c
	$(CC) -c test.c

clean:
	rm -f *.o output tests
