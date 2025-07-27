// output_formats.h
#ifndef STRING_UTILS_H
#define STRING_UTILS_H

#include <string.h>
#include <stdlib.h>
#include <ctype.h> 

// Capitalise the first letter in a word
void capitalise(char *str);

// Capitalises all letters of a word or sentence
	void captital_all_letters(char *str);

// Captalises every second letter of a word or sentence
void capitalise_every_second_char(char *str);

// Censor insult: m*********r 
void censor(char *str);

#endif // STRING_UTILS_H

