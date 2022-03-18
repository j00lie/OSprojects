#include <stdio.h>

int main(int argc, char *argv[], char * envp[]){

    printf("***Komentorivin parametrit alkaa***\n");
    for (int j = 0; argv[j] != NULL; j++){
        printf("\n%s\n",argv[j]); 
    }
    printf("\n***Komentorivin parametrit loppuu***\n");
    printf("***Ympäristomuuttujat alkaa***\n");
    for (int i = 0; envp[i] != NULL; i++)
        printf("\n%s", envp[i]);

    printf("\n***Ympäristomuuttujat loppuu***\n");
    return 0;
}