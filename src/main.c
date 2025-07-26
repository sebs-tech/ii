#include <stdio.h>  
#include <stdlib.h> 
#include <time.h>   
#include "curses_data.h" 

int main() {
    // Seed the random number generator only once
    srand(time(NULL));

    // Generate a random index between 0 and NUM_CURSES - 1
    int rnum = rand() % NUM_CURSES;

    // Print the randomly selected curse string
    printf("%s\n", curses[rnum]); // Corrected 'print' to 'printf' and added newline

    /* exit */
	return 0;
}
