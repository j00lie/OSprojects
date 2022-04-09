#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Decompress files encoded with RLE
void decode(char *src)
{
    FILE *f;
    char buffer[100];
    unsigned char c;
    f = fopen(src, "r");

    if (f == NULL)
    {
        perror("my-unzip: cannot open file\n");
        exit(1);
    }
    /* Encoded file to be read has the following format:
    4-byte integer in binary format followed by the single character in ASCII*/
    while (fread(&buffer, 4, 1, f) > 0)
    {
        // printf("BUFFER:%s\n",buffer);
        fread(&c, 1, 1, f);
        char ch = c; // Get the charachter from ASCII value
        for (int i = 0; i < atoi(buffer); i++)
        {
            printf("%c", ch);
        }
        // printf("\n");
    }
    fclose(f);
}

int main(int argc, char *argv[])
{
    // Unzip one ore mutltiple files
    int i = 1;
    if (argc < 2)
    {
        printf("my-unzip: file1 [file2 ...]\n");
        exit(1);
    }
    else
    {
        while (argv[i] != NULL)
        {
            decode(argv[i]);
            i++;
        }
    }
    return 0;
}