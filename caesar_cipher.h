#ifndef CAESAR_CIPHER_H
#define CAESAR_CIPHER_H

extern char *encrypt(char *plain_text, int shift);
extern char *decrypt(char *cipher_text, int shift);

#endif
