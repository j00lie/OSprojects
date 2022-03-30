#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_RLEN 50


/* Returns the Run Length Encoded string for the
   source string src */
char* encode(char* src)
{
    int rLen;
    char count[MAX_RLEN];
    int len = strlen(src);
 
    /* If all characters in the source string are different,
    then size of destination string would be twice of input string.
    For example if the src is "abcd", then dest would be "a1b1c1d1"
    For other inputs, size would be less than twice.  */
    char* dest = (char*)malloc(sizeof(char) * (len * 2 + 1));
 
    int i, j = 0, k;
 
    /* traverse the input string one by one */
    for (i = 0; i < len; i++) {
 
        /* Copy the first occurrence of the new character */
        dest[j++] = src[i];
 
        /* Count the number of occurrences of the new character */
        rLen = 1;
        while (i + 1 < len && src[i] == src[i + 1]) {
            rLen++;
            i++;
        }
 
        /* Store rLen in a character array count[] */
        sprintf(count, "%d", rLen);
 
        /* Copy the count[] to destination */
        for (k = 0; *(count + k); k++, j++) {
            dest[j] = count[k];
        }
    }
 
    /*terminate the destination string */
    dest[j] = '\0';
    return dest;
}
void readFile(char *argv){
    FILE *f;
    FILE *output_file; 
    char *buffer = NULL; // line here
    size_t bufsize = 0;
    ssize_t num_chars;
    f = fopen(argv, "r"); 
    output_file = fopen("output.txt","w");
    if(output_file == NULL || f ==NULL) {
    perror("my-zip: cannot open file\n");
    exit(1);
    }
    
    while( (num_chars = getline(&buffer, &bufsize, f))!=-1 ) {
        if ((buffer)[num_chars - 1] == '\n') { // Remove newline charachters
            (buffer)[num_chars - 1] = '\0';
            --num_chars;
        }
        char *str = encode(buffer);
        printf("%s\n",str);
        fwrite(str, 5,sizeof(str),output_file);
    }
        
    fclose(f);
    fclose(output_file);
    free(buffer);
    }

int main(int argc, char *argv[]){

    readFile(argv[1]);
    return 0; 
}