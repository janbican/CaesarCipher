#include <stdio.h>
#include <stdlib.h>
#include "caesar_cipher.h"

#define SHIFT 5

int main(void) {

  char *cipher_text = encrypt("hello world", SHIFT);
  char *plain_text = decrypt(cipher_text, SHIFT);

  printf("%s decrypted to %s\n", cipher_text, plain_text);

  free(cipher_text);
  free(plain_text);

  return 0;
}
