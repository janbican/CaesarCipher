#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define lowercase_char_index(c) ((c) - 97);

typedef char (* convert_char_func)(char, int);

static char *convert(char *text, int shift, convert_char_func func);
static void *allocate_memory(int size);
static char encrypt_char(char c, int shift);
static int  mod(int x, int y);
static char decrypt_char(char c, int shift);

static char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
static int  alphabet_len = 26;

char *encrypt(char *plain_text, int shift) {
  return convert(plain_text, shift, encrypt_char);
}

char *convert(char *text, int shift, convert_char_func func) {
  int length = strlen(text);
  char *result_text = allocate_memory(length+1);
  for (int i = 0; text[i] != '\0'; i++) {
    result_text[i] = func(text[i], shift);
  }
  result_text[length] = '\0';
  return result_text;
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
  if (!islower(c)) return c;
  int char_index = lowercase_char_index(c);
  return alphabet[mod(char_index + shift, alphabet_len)];
}

static int mod(int x, int y) {
  int result = x % y;
  return (result < 0) ? result + y : result;
}

char *decrypt(char *cipher_text, int shift) {
  return convert(cipher_text, shift, decrypt_char);
}

static char decrypt_char(char c, int shift) {
  if (!islower(c)) return c;
  int char_index = lowercase_char_index(c);
  return alphabet[mod(char_index - shift, alphabet_len)];
}
