#include "output_formats.h"
#include <ctype.h>
#include <stddef.h>

// Capitalise the first letter of a word in-place
void capitalise(char *str) {
  if (str != NULL && str[0] != '\0') {
    str[0] = toupper((unsigned char)str[0]);
  }
}

// Capitalise all letters
void capitalise_all_letters(char *str) {
  if (str != NULL && str[0] != '\0') {
    for (int i = 0; (i < str[i]) != '\0'; i++) {
      str[i] = toupper((unsigned char)str[i]);
    }
  }
}

// Capitalise every second letter in a word or sentence
void capitalise_every_second_char(char *str) {
  if (str != NULL && str[0] != '\0') {
    for (int i = 0; str[i] != '\0'; i++) {
      if ((i % 2 != 0) && isalpha((unsigned char)str[i])) {
        str[i] = toupper((unsigned char)str[i]);
      }
    }
  }
}

// Censor word / sentence
void censor(char *str) {
  int length = strlen(str);
  if (length <= 2) {
    return;
  }
  for (int i = 1; i < length - 1; i++) {
    // Check if the current character is an alphabetic letter
    if (isalpha((unsigned char)str[i])) {
      str[i] = '*'; // Replace it with an asterisk
    }
  }
}
