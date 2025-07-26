# Captain Haddock's Random Curse Generator

Welcome, you blithering bashi-bazouk! This is a simple C program
designed to bring a touch of Captain Haddock's legendary linguistic
flair to your command line. Ever needed a quick, random, and
wonderfully imaginative insult? Look no further, you miserable
macrocephalic!

This project randomly selects one of Captain Haddock's iconic curses
from a predefined list and prints it to your console. Perfect for
adding some Tintin-esque charm to your scripts or just for a good
laugh.

## Features

* **Random Selection:** Delivers a different curse each time you
    run it.
* **Captain Haddock's Repertoire:** A curated list of classic Haddock
    insults.
* **Lightweight C Program:** Fast and efficient, just like a
    well-aimed insult.

## Project Structure

This project is organized to use a `Makefile` for compilation and
separates header files into an `include` directory.

```
.
├── Makefile
├── main.c
├── curses_data.c
└── include/
    └── curses_data.h
```

* `Makefile`: Automates the compilation process.
* `main.c`: Contains the `main` function where the random curse is
    generated and printed.
* `curses_data.c`: Defines the array of curse strings and their
    total count.
* `include/curses_data.h`: Declares the `curses` array and
    `NUM_CURSES` for use in other source files.

## How to Compile

To compile this magnificent piece of code, you'll need a C compiler
(like GCC) and `make` installed on your system.

1.  **Organize your files:**
    * Place `main.c` and `curses_data.c` in the root directory of
        your project.
    * Create a directory named `include` in the root directory.
    * Place `curses_data.h` inside the `include` directory.
    * Place the provided `Makefile` in the root directory.

    Your directory structure should look like the example above.

2.  **Compile using `make`:**
    Open your terminal or command prompt, navigate to the root
    directory of your project (where the `Makefile` is located),
    and run:

    ```bash
    make
    ```
    This command will use the `Makefile` to compile your source files
    and link them together to create an executable named `ii` (as
    defined in the `Makefile`).

## How to Run

Once compiled, you can unleash the Captain's wrath!

```bash
./ii
```

## Example Usage

```bash
$ ./ii
You miserable macrocephalic!

$ ./ii
You blithering bashi-bazouk!

$ ./ii
You walking anachronism!
```

*(Note: The actual curses might vary based on the specific list you've
populated in `curses_data.c`)*

## Cleaning Up

To remove the compiled object files and the executable, you can use
the `clean` target in the Makefile:

```bash
make clean
```

## Credits

* **Captain Haddock:** For his unparalleled mastery of colorful
    language.
* **Hergé:** The brilliant creator of Tintin and the unforgettable
    Captain Haddock.

## License

This project is open-source and available under the
[MIT License](https://opensource.org/licenses/MIT). Feel free to use,
modify, and distribute it, you twenty-thousand filthy fancy-dress
fanatics!

