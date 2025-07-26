# Captain Haddock's Random Curse Generator

Need a quick, random, Captain Haddock-inspired insult? This simple C program
provides just that! It selects one of his iconic curses from a list and prints
it, adding Tintin-esque flair to your command line.

## Features

* **Random Selection:** Delivers a different curse each time you
    run it.
* **Captain Haddock's Repertoire:** A curated list of classic Haddock
    insults.
* **Lightweight C Program:** Fast and efficient, just like a
    well-aimed insult.

## Project Structure

```
.ii
├── curses_data.c
├── include
│   └── curses_data.h
└── main.c
```

## How to Compile

1.  **Compile using `make`:** Open your terminal or command prompt, navigate to
the root directory of your project (where the `Makefile` is located), and run:

    ```bash make ``` This command will use the `Makefile` to compile your source
files and link them together to create an executable named `ii` (as defined in
the `Makefile`).

## How to Run

Once compiled, you can unleash the Captain's wrath!

```bash 
./ii 
```

## Example Usage

```bash 
$ ./ii You miserable macrocephalic!

$ ./ii You blithering bashi-bazouk!

$ ./ii You walking anachronism!  
```
*(Note: You can customize the available curses by editing the list in
curses_data.c.)*

## Credits

* **Captain Haddock:** For his unparalleled mastery of colorful
    language.
* **Hergé:** The brilliant creator of Tintin and the unforgettable
    Captain Haddock.
* **My wife** for pointing out that foul language can be funny. 
* **A chap from Scotland** I tested some of these insults on. 

## License

This project is open-source and available under the [MIT
License](https://opensource.org/licenses/MIT). Feel free to use, modify, and
distribute it, you twenty-thousand filthy fancy-dress fanatics!
