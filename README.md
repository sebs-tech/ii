# Captain Haddock's Random Insult Generator

Want to avoid profanities yet maintain a stylish line of insults? This simple 
C program provides just that! It selects one of Captain Haddock's iconic insults 
from a list and prints it, adding Tintin-esque flair to your command line, email
or chat. 

## Features

* **Random Selection:** Delivers a different curse each time you
    run it.
* **Captain Haddock's Repertoire:** A curated list of classic Haddock
    insults.
* **Lightweight C Program:** Fast and efficient, just like a
    well-aimed insult.

## Project Structure

```
.
├── Makefile
├── README.md
└── src
    ├── curses_data.c
    ├── include
    │   ├── curses_data.h
    │   └── output_formats.h
    ├── main.c
    └── output_formats.c
```

## How to Compile & Install

```bash 
$ make 
$ sudo make install
```
The install path is: 
```
/usr/local/bin/ii
```
## How to Run

Once compiled, you can unleash the Captain's wrath!

```bash 
$ ii 
$ ii -c # Will capitalise the first letter. 
$ ii -a # Will capitalise all letters. 
$ ii -r # Will capitalise every 2nd letter. 
$ ii -x # Will censor all letters except the first and last one.
```

## Example Usage

```bash 
$ ii
freshwater swabs

$ ii -c
Iconoclasts

$ ii -a
CENTIPEDE

$ ii -r
oPhIcLeIdEs

$ ii -x
c*******e
```
*(Note: You can customize the available curses by editing the list in
curses_data.c.)*

## Vim integration

I run `ii` directly from vim (my main text editor). That happens via a handy
script in `~/.vimrc`. You can append the necessary stuff like this: 

```
cat vimrc >> ~/.vimrc
```

and run it: 

```
:II -flag 
```


## Credits
* **My wife** for pointing out that foul language can and must be funny. 
* **Captain Haddock / Hergé:** For his unparalleled mastery of colorful
    language.
* **A chap from Scotland** I tested some of these insults on. 

## License

This project is open-source and available under the [MIT
License](https://opensource.org/licenses/MIT). Feel free to use, modify, and
distribute it, you twenty-thousand filthy fancy-dress fanatics!
