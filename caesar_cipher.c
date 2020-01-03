#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define lowercase_char_index(c) ((c) - 97);

static void *allocate_memory(int size);
static char encrypt_char(char c, int shift);
static int  mod(int x, int y);
static char decrypt_char(char c, int shift);

static char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
static int  alphabet_len = 26;

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
  cipher_text[length] = '\0';
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

static char encrypt_char(char c, int shift) {
  int char_index = lowercase_char_index(c);
  return alphabet[mod(char_index + shift, alphabet_len)];
}

static int mod(int x, int y) {
  int result = x % y;
  return (result < 0) ? result + y : result;
}

char *decrypt(char *cipher_text, int shift) {
  int length = strlen(cipher_text);
  char *plain_text = allocate_memory(length+1);
  for (int i = 0; cipher_text[i] != '\0'; i++) {
    char c = cipher_text[i];
    if (isalpha(c) && islower(c)) {
      plain_text[i] = decrypt_char(c, shift);
    } else {
      plain_text[i] = c;
    }
  }
  plain_text[length] = '\0';
  return plain_text;
}

static char decrypt_char(char c, int shift) {
  int char_index = lowercase_char_index(c);
  return alphabet[mod(char_index - shift, alphabet_len)];
}
