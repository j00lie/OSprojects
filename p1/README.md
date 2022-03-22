## Project 1: Warmup to C and Unix programming

### Description
A command line program for reversing a given input file and subsequently writing the reversed input on a chosen output stream.

### Prerequisites
- OS: Linux
- gcc or other C-compiler
- In case you're using windows look into [using gcc with MinGW](https://code.visualstudio.com/docs/cpp/config-mingw)

### Installation
- Download the [driver code](https://github.com/j00lie/OSprojects/blob/main/p1/reverse.c)
- Compile with: `gcc reverse.c -o example_executable -std=c99`

### Running the program
- The program can be invoked in the following ways: 
- `./reverse` without any additional arguments the input stream is stdin and output stream is stdout.
-  `./reverse input.txt` with one additional argument the program recognizes the parameter as the input file.
-  `./reverse input.txt output.txt`With two command line arguments the first one designates the input file and the second is used as the output file. 


