#include <stdio.h>
#include <stdlib.h>
#include<string.h>




void readFile(char *argv, char *search_term){
    FILE *f; 
    char *buffer = NULL; // line here
    size_t bufsize = 0;
    
    if(strcmp(argv,"stdin")==0){
        f = stdin;
        printf("Enter lines ('q' to quit): \n");
    }else{
        f = fopen(argv, "r"); 
        if(f == NULL) {
        perror("my-grep: cannot open file\n");
        exit(1);
        }
    }
    while( getline(&buffer, &bufsize, f)!=-1 ) {
        if (strcmp(buffer, "q\n") == 0){
            break;
        }
        if(strstr(buffer, search_term)){
            printf("%s\n",buffer);
    }
        }
        
    fclose(f);
    free(buffer);
    }

int main(int argc, char *argv[]){
    char *search_term = argv[1]; // First term after the program name is the search term, rest(if specified) are filenames
    int i = 2; 
    if(argc<2){ //no command line arguments
        printf("my-grep: searchterm [file ...]\n");
        exit(1);
    }else if (argc==2){ // only search term specified --> read from stdin
        readFile("stdin", search_term);
    }else{// search term and n amount of filenames given
        while(argv[i] != NULL){
        readFile(argv[i], search_term);
        i++; 
        }
    }

    return 0; 
}