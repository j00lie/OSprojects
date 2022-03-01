#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct line
{
    struct line *pNext;
    char line[];
} LINE;

// Create new node to represent a line
LINE *newLine()
{
    LINE *new = (LINE *)malloc(sizeof(LINE));
    new->pNext = NULL;
    return new;
}

LINE *readFile()
{
    FILE *f;
    char *buffer; // line here
    size_t bufsize = 32;
    size_t line;
    LINE *pStart = NULL, *ptr = NULL, *pNew;

    buffer = (char *)malloc(bufsize * sizeof(char));
    f = fopen("input.txt", "r");
    while (line = getline(&buffer, &bufsize, f) != -1)
    {
        if (pStart == NULL)
        {
            pStart = newLine();
            strcpy(pStart->line, buffer);
            // printf("rivi: %s", ptr->line);
            ptr = pStart;
        }
        else
        {
            pNew = newLine();
            ptr->pNext = pNew;
            strcpy(pNew->line, buffer);
            ptr = ptr->pNext;
        }
    }

    fclose(f);
    free(ptr);
    return pStart;
}
void printList(LINE *ptr)
{
    while (ptr != NULL)
    {
        printf("%s\n", ptr->line);
        ptr = ptr->pNext;
    }
}

int main(void)
{
    LINE *ptr = NULL;
    ptr = readFile(ptr);
    printList(ptr);
    free(ptr);
    return 0;
}