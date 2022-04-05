#include <stdio.h>
#include <stdlib.h>

void readFile(char *argv){
    FILE *f = fopen(argv, "r"); 
    char str[100]; 
    if(f == NULL) {
      perror("my-cat: cannot open file\n");
      exit(1);
   }
   while( fgets (str, 100, f)!=NULL ) {
      printf("%s",str);
   }
   printf("\n");
   fclose(f);

}

int main(int argc, char *argv[]){
    int i = 1; 
    if(argc > 1){
        while(argv[i] != NULL){
        readFile(argv[i]);
        i++; 
        }
    }
    return 0; 
}