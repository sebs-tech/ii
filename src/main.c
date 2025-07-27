#include "curses_data.h"
#include "output_formats.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

/* 
  if (argc > 1) {
    // arugments found, vim mode (most likely) 
    if (atoi(argv[1]) == 0) {
      capitalise(temp_buffer);
    } else {
      // Middle of the line, don't capitalise 
      printf("With argument !0, %s ", curses[rnum]);
    }
  } else {
    // no arguments, terminal mode 
    capitalise(curses[rnum]);
    printf("%s ", curses[rnum]);
  }

*/

  // capitalise_all_letters(temp_buffer);

  printf("%s ", temp_buffer);

  /* exit */
  return 0;
}
