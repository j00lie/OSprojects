#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_RLEN 50


/* Returns the Run Length Encoded string for the
   source string src */
void encode(char* src){
    int rLen = 0;
    char count[MAX_RLEN];
    int len = strlen(src);

 
    int i = 0;
 
    /* traverse the input string one by one */
    for (i = 0; i < len; i++) {
 
        /* Count the number of occurrences of the new character */
        rLen = 1;
        while (i + 1 < len && src[i] == src[i + 1]) {
            rLen++;
            i++;
        }
 
        /* Store rLen in a character array count[] */
        sprintf(count, "%d", rLen);
        fwrite(&count, sizeof(rLen),1,stdout);
        fwrite(&src[i], 1, 1, stdout); 
    }
 
}
void remove_spaces(char* s) { //https://stackoverflow.com/questions/1726302/remove-spaces-from-a-string-in-c
    char* d = s;
    do {
        while (*d == ' ') { //Read spaces and increment pointer copy, assing stripped version at the end to the original string
            ++d;
        }
    } while ((*s++ = *d++));
}
void readFile(char *argv){
    FILE *f;
    
    char *buffer = NULL; // line here
    size_t bufsize = 0;
    ssize_t num_chars;
    f = fopen(argv, "r"); 
    
    if(f ==NULL) {
    perror("my-zip: cannot open file\n");
    exit(1);
    }
    
    while( (num_chars = getline(&buffer, &bufsize, f))!=-1 ) {
        /*
        Following can be used to produce a single stream of input wihtout spaces or newlines:

        if ((buffer)[num_chars - 1] == '\n') { // Remove newline characters
            (buffer)[num_chars - 1] = '\0';
            --num_chars;
        }
        remove_spaces(buffer);
        */
        encode(buffer);
        
    }
        
    fclose(f);
    free(buffer);
    }

int main(int argc, char *argv[]){
    int i = 1; 
    if(argc <2){
        printf("my-zip: file1 [file2 ...]\n");
        exit(1);
    }else{
        while(argv[i]!=NULL){
            readFile(argv[i]);
            
            i++;
        }
    }
    
    return 0; 
}