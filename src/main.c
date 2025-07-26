#include <stdio.h>  // Required for printf
#include <stdlib.h> // Required for rand() and srand()
#include <time.h>   // Required for time() (used for seeding the random number generator)
#include "curses_data.h" // Required to access 'curses' array and 'NUM_CURSES'

int main() {
    /* Calculate random number between 0 and NUM_CURSES - 1 (inclusive) */

    // Seed the random number generator only once
    srand(time(NULL));

    // Generate a random index between 0 and NUM_CURSES - 1
    int rnum = rand() % NUM_CURSES;

    // Print the randomly selected curse string
    printf("%s\n", curses[rnum]); // Corrected 'print' to 'printf' and added newline

    return 0;
}
