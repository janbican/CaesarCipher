# -*- MakeFile -*-

caesarcipher: main.o caesar_cipher.o
	gcc main.o caesar_cipher.o

main.o: main.c caesar_cipher.h
	gcc -c main.c

caesar_cipher.o: caesar_cipher.c caesar_cipher.h
	gcc -c caesar_cipher.c

clean:
	rm -f *.o a.out
