# -*- MakeFile -*-

CC = gcc

caesarcipher: main.o caesar_cipher.o
	$(CC) main.o caesar_cipher.o -o output

main.o: main.c caesar_cipher.h
	$(CC) -c main.c

caesar_cipher.o: caesar_cipher.c caesar_cipher.h
	$(CC) -c caesar_cipher.c

clean:
	rm -f *.o output
