// curses_data.h

#ifndef CURSES_DATA_H // This is a header guard to prevent multiple inclusions
#define CURSES_DATA_H

// Declare the array of constant character pointers (strings)
// 'extern' keyword tells the compiler that this array is defined in another source file.
// You don't specify the size here, as it's a declaration.
extern const char *curses[];

// If you also need the size of the array in other files, you can declare it here too.
// It's good practice to make the size constant.
extern const int NUM_CURSES;

#endif // CURSES_DATA_H
