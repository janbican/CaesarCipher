//
// tests for caesar_cipher.c
// naming_ function_name__input__result
//

#include <stdio.h>
#include <string.h>
#include "minunit/minunit.h"
#include "caesar_cipher.h"

int tests_run = 0;

static char *encrypt__valid_input__cipher_text() {
  char plain_text[] = "hello world";
  char cipher_text[] = "rovvy gybvn";
  int shift = 10;
  mu_assert("encrypt__returns_cipher_text",
            strcmp(cipher_text, encrypt(plain_text, shift)) == 0);
  return 0;
}

static char *encrypt__empty_string__empty_string() {
  mu_assert("encrypt__empty_string__empty_string",
            strcmp("", encrypt("", 10)) == 0);
  return 0;
}

static char *encrypt__zero_shift__input() {
  char plain_text[] = "hello world";
  mu_assert("encrypt__zero_shift__input",
            strcmp(plain_text, encrypt(plain_text, 0)) == 0);
  return 0;
}

static char *decrypt__valid_input__plain_text() {
  char plain_text[] = "this is test";
  char cipher_text[] = "hvwg wg hsgh";
  int shift = 14;
  mu_assert("decrypt__valid_input__plain_text",
            strcmp(plain_text, decrypt(cipher_text, shift)) == 0);
  return 0;
}

static char *decrypt__empty_string__empty_string() {
  mu_assert("decrypt__empty_string__empty_string",
            strcmp("", decrypt("", 10)) == 0);
  return 0;
}

static char *decrypt__zero_shift__input() {
  char cipher_text[] = "hvwg wg hsgh";
  mu_assert("decrypt__zero_shift__input",
            strcmp(cipher_text, decrypt(cipher_text, 0)) == 0);
  return 0;
}

static char *all_tests() {
  mu_run_test(encrypt__valid_input__cipher_text);
  mu_run_test(encrypt__empty_string__empty_string);
  mu_run_test(encrypt__zero_shift__input);
  mu_run_test(decrypt__valid_input__plain_text);
  mu_run_test(decrypt__empty_string__empty_string);
  mu_run_test(decrypt__zero_shift__input);
  return 0;
}

int main(int argc, char **argv) {
  char *result = all_tests();
    if (result != 0) {
      printf("ERROR:\n%s\n", result);
    } else {
      printf("ALL TESTS PASSED\n");
    }
    printf("Tests run: %d\n", tests_run);
    return result != 0;
}
