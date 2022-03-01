#include <stdio.h>
#include <stdlib.h>
#define _POSIX_C_SOURCE 200809L

void readFile()
{
    FILE *f;
    char *buffer; // lines here
    size_t bufsize = 32;
    size_t lines;

    buffer = (char *)malloc(bufsize * sizeof(char));
    f = fopen("input.txt", "r");
    while ((lines = getline(&buffer, &bufsize, f)) != -1)
    {
        printf("%s", buffer);
    }
    fclose(f);
}

int main(void)
{
    readFile();
    return 0;
}