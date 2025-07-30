#include "curses_data.h"
#include "output_formats.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MAX_STRING_LENGTH 80

int main(int argc, char *argv[]) {

  char temp_buffer[MAX_STRING_LENGTH + 1];

  // Seed the random number generator only once
  srand(time(NULL));

  // Generate a random index between 0 and NUM_CURSES - 1
  int rnum = rand() % NUM_CURSES;

  // store random insult to a buffer
  // temp_buffer becomes single source of truth
  strncpy(temp_buffer, curses[rnum], MAX_STRING_LENGTH);
  temp_buffer[MAX_STRING_LENGTH] = '\0'; // Ensure null-termination

  if (argc == 1) {
    /*
            No action needed.
    */
  } else if (argc > 1) {
    // -c flag
    if (strcmp(argv[1], "-c") == 0) {
      capitalise(temp_buffer);
    }

    // -a flag
    if (strcmp(argv[1], "-a") == 0) {
      capitalise_all_letters(temp_buffer);
    }

    // -r flag
    if (strcmp(argv[1], "-r") == 0) {
      capitalise_every_second_char(temp_buffer);
    }

    // -x flag
    if (strcmp(argv[1], "-x") == 0) {
      censor(temp_buffer);
    }
  }

  /* Print output */
  if (isatty(STDOUT_FILENO)) {
    printf("%s\n", temp_buffer); // Add newline if outputting to a terminal
  } else {
    printf("%s  ", temp_buffer); // No newline if outputting to pipe/file
  }

  /* exit */
  return 0;
}
