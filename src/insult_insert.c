#include <stdio.h>  
#include <stdlib.h> 
#include <ctype.h>  
#include <string.h> 
#include <time.h>  

#define MAX_LINE_LENGTH 256 

// Main
int main(int argc, char *argv[]) {
  FILE *file_pointer;                
  char filename[100];                
  char line_buffer[MAX_LINE_LENGTH];
                                     
  int total_lines = 0;
                                    
  int random_line_number;
  int current_line_count = 0;
  int current_vim_column = 1;

  // Check if a column argument was provided
  if (argc > 1) {
    current_vim_column = atoi(argv[1]);
    // Basic validation: ensure column is at least 1
    if (current_vim_column < 1) {
      current_vim_column = 1;
    }
  }

  // 1. Manually specify the filename
  /*
	How about you make something like a config file?
  */
  strcpy(filename,
         "/home/seb/GitHub/insult_insert.vim/data/new/captain_haddock.txt");

  // 2. Open the file in read mode ("r") for the first pass (counting lines)
  /*
	Yeah ok, but why 2 passes ? 
	Why not get the file, count the lines, re-use it?
	Maybe because the architecture of this software is not that nice?
  */
  file_pointer = fopen(filename, "r");

  // 3. Error handling: Check if the file was opened successfully
  if (file_pointer == NULL) {
    fprintf(stderr,
            "Error: Could not open file '%s'. Make sure the file exists "
            "and you have read permissions.\n",
            filename);
    return EXIT_FAILURE; // Exit the program with an an error code
  }

  // First pass: Count the total number of lines in the file
  /* And why 2 passes? */
  while (fgets(line_buffer, MAX_LINE_LENGTH, file_pointer) != NULL) {
    total_lines++;
  }

  // Close the file after counting
  fclose(file_pointer);

  /* Handle empty file case */
  if (total_lines == 0) {
    /*
	Maybe it would be a good idea here to return a general curse 
	and remind the user the file is empty ? 
	And print some sort of a stderr message? 
	I don't like this below. Make it funky. Why not?
    */
    fprintf(stderr, "The file '%s' is empty or could not be read.\n", filename);
    return 0; // Exit successfully, but with no output
  }

  /*
	random seed. 
	Is there a better way to get a random number ? 

  */
  srand(time(NULL));

  /*
	Generate a random line number between 1 and total_line
	Move this to a function ?
  */
  random_line_number = (rand() % total_lines) + 1;

  // Re-open the file for the second pass (reading the specific line)
  /* 
   Ccc...not the second time, please ?
  */
  file_pointer = fopen(filename, "r");
  if (file_pointer == NULL) {
    fprintf(stderr,
            "Error: Could not re-open file '%s'. This should not happen "
            "if it opened successfully the first time.\n",
            filename);
    return EXIT_FAILURE;
  }

  // Second pass: Read lines until the random line is reached
  /*
	Refactor this!
	Make the code modular!
	Make everything better 
  */ 
  while (fgets(line_buffer, MAX_LINE_LENGTH, file_pointer) != NULL) {
    current_line_count++;
    if (current_line_count == random_line_number) {
      // Remove the trailing newline character from the buffer if it exists.
      line_buffer[strcspn(line_buffer, "\n")] = 0;

      // IMPORTANT CHANGE: Adjust case of the first character and add space
      if (strlen(line_buffer) > 0) { // Ensure the line is not empty
        if (current_vim_column == 1) {
          // If at the beginning of the line, capitalize the first letter
          line_buffer[0] = toupper((unsigned char)line_buffer[0]);
          printf("%s", line_buffer); // No leading space
        } else {
          // If not at the beginning, lowercase the first letter and add a space
          line_buffer[0] = tolower((unsigned char)line_buffer[0]);
          printf(" %s", line_buffer); // Add leading space
        }
      } else {
        // If the line is empty, just print it (or nothing)
        printf("%s", line_buffer);
      }
      break; // Exit the loop once the random line is found and printed
    }
  }

  // 5. Close the file
  fclose(file_pointer);
  /* 
 	Overall, some more checks for errors; 
	

  */ 
  return 0; // Indicate successful execution
}
