## Project 2: Unix utilities

### Description
#### My-cat
Command line utility resembling Unix utility cat. Reads input file(s) and outputs them to stdout. 
#### My-grep
Command line utility resembling Unix utility grep. Reads input file(s), searches line contents for given search term and outputs matching lines to stdout. 
#### My-zip
Command line utility resembling Unix utility zip. Reads input file(s) and compresses them using run length encoding (RLE). 
#### My-unzip
Command line utility resembling Unix utility unzip. Reads compressed input file(s), decompresses them and outputs them to stdout.

### Prerequisites
- OS: Linux
- gcc or other C-compiler
- In case you're using windows look into [using gcc with MinGW](https://code.visualstudio.com/docs/cpp/config-mingw)

### Installation
- My-cat:
  - Download the [My-cat driver code](https://github.com/j00lie/OSprojects/blob/main/p1/reverse.c)
  - Compile with: `gcc reverse.c -o example_executable -std=c99`

### Running the program
- The program can be invoked in the following ways: 
- `./reverse` without any additional arguments the input stream is stdin and output stream is stdout.
-  `./reverse input.txt` with one additional argument the program recognizes the parameter as the input file.
-  `./reverse input.txt output.txt`With two command line arguments the first one designates the input file and the second is used as the output file. 


