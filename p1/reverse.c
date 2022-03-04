#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct line
{
    struct line *pNext;
    char *line;
} LINE;

// Create new node to represent a line
LINE *newLine()
{
    LINE *new = (LINE *)malloc(sizeof(LINE));
    new->pNext = NULL;
    return new;
}

LINE *readFile(char *argv)
{
    FILE *f;
    char *buffer; // line here
    size_t bufsize = 32;
    size_t line;
    LINE *pStart = NULL, *ptr = NULL, *node;

    buffer = (char *)malloc(bufsize * sizeof(char));
    if (buffer == NULL)
    {
        fprintf(stderr, "malloc failed\n");
        exit(1);
    }

    if (strcmp(argv, "stdin") != 0)
    {
        f = fopen(argv, "r");
        if (f == NULL)
        {
            fprintf(stderr, "error: cannot open file %s\n", argv);
            exit(1);
        }
    }
    else
    {
        f = stdin;
        printf("Enter lines ('exit' to stop): \n");
    }

    while (line = getline(&buffer, &bufsize, f) != -1)
    {
        if (strcmp(buffer, "exit\n") == 0)
        {
            break;
        }
        node = newLine();
        node->line = strdup(buffer);

        if (pStart == NULL)
        {
            ptr = pStart = node;
        }
        else
        {
            ptr = ptr->pNext = node;
        }
    }

    fclose(f);
    free(buffer);

    return pStart;
}
void writeOutput(LINE *pStart, char *argv)
{
    LINE *ptr = pStart;
    FILE *f;
    if (strcmp(argv, "stdout") != 0) // check if outputstream is stdout or not
    {
        f = fopen(argv, "w");
    }
    else
    {
        f = stdout;
    }
    while (ptr != NULL)
    {
        fprintf(f, "%s\n", ptr->line);
        ptr = ptr->pNext;
    }
    fclose(f);
}
void reverseInput(LINE **pStart) // recursive function to reverse linked list
{

    if (pStart == NULL)
    {
        return;
    }
    LINE *first = *pStart;
    LINE *rest = first->pNext;
    if (rest == NULL)
    {
        return;
    }

    reverseInput(&rest);
    first->pNext->pNext = first;
    first->pNext = NULL;
    *pStart = rest;
}

int main(int argc, char *argv[])
{
    LINE *pStart = NULL;
    // argv[1] = input.txt & argv[2] = output.txt

    if (argc == 3) // write input file to output file in reverse order
    {

        if (strcmp(argv[1], argv[2]) == 0) // check that input and output files are not the same
        {
            fprintf(stderr, "Input and output file must differ\n");
            exit(1);
        }
        pStart = readFile(argv[1]);
        reverseInput(&pStart);
        writeOutput(pStart, argv[2]);
    }
    else if (argc == 2) // In absence of output file print reverse order to stdout
    {
        pStart = readFile(argv[1]);
        reverseInput(&pStart);
        writeOutput(pStart, "stdout");
    }
    else if (argc == 1) // read from stdin and write to stdout
    {
        pStart = readFile("stdin");
        reverseInput(&pStart);
        writeOutput(pStart, "stdout");
    }
    else if (argc > 3)
    {
        fprintf(stderr, " usage: reverse <input> <output>\n");
        exit(1);
    }
    free(pStart);
    return 0;
}