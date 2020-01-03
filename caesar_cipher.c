#include <stdio.h>
#include <string.h>
#include <ctype.h>

static void *allocate_memory(int size);

char *encrypt(char *plain_text, int shift) {
  int length = strlen(plain_text);
  char *cipher_text = allocate_memory(length+1);
  for (int i = 0; plain_text[i] != '\0'; i++) {
    if (isalpha(plain_text[i])) {
      cipher_text[i] = encrypt_char(plain_text[i], shift);
    } else {
      cipher_text[i] = plain_text[i];
    }
  }
  return cipher_text;
}

static void *allocate_memory(int size) {
  void *memory;
  if ((memory = malloc(size)) == NULL) {
    fprintf(stderr, "not enough memory, exiting...\n");
    exit(1);
  }
  return memory;
}

static char enrypt_char(char c, int shift) {
  return c + shift;
}
