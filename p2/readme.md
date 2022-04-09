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
  - Download the [My-cat driver code](https://github.com/j00lie/OSprojects/blob/main/p2/my-cat.c)
  - Compile with: `gcc my-cat.c -o example_executable -Wall -Werror`
- My-grep:
  - Download the [My-grep driver code](https://github.com/j00lie/OSprojects/blob/main/p2/my-grep.c)
  - Compile with: `gcc my-grep.c -o example_executable -Wall -Werror`
 - My-zip:
   - Download the [My-zip driver code](https://github.com/j00lie/OSprojects/blob/main/p2/my-zip.c)
   - Compile with: `gcc my-zip.c -o example_executable -Wall -Werror`
 - My-unzip:
   - Download the [My-unzip driver code](https://github.com/j00lie/OSprojects/blob/main/p2/my-unzip.c)
   - Compile with: `gcc my-unzip.c -o example_executable -Wall -Werror`

### Running the program
- my-cat:
  - `./my-cat file_1 (file_2..)`
- my-grep:
  - `./my-grep search_term file_1 (file_2..)`
- my-zip:
  - `./my-zip file_1 (file_2..) > zipped_file.zip`
- my-unzip:
  - `./my-unzip file_1 (file_2..)`


