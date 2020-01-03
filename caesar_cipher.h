//
// caesar_cipher head file
//
// caesar cipher explanation
// https://en.wikipedia.org/wiki/Caesar_cipher
//
// encrypts and decrypts only lowercase characters
// other characters just copies
//
// encrypt, decrypt returns dynamiclly allocated strings
// it is up to user to free the memory
//

#ifndef CAESAR_CIPHER_H
#define CAESAR_CIPHER_H

extern char *encrypt(char *plain_text, int shift);
extern char *decrypt(char *cipher_text, int shift);

#endif
