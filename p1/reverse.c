#define _POSIX_C_SOURCE 200809L
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
    LINE *new = malloc(sizeof(LINE));
    new->pNext = NULL;
    return new;
}

LINE *readFile(char *argv)
{
    FILE *f;
    char *buffer = NULL; // line here
    size_t bufsize = 0;

    LINE *pStart = NULL, *ptr = NULL, *node = NULL;

    if (strcmp(argv, "stdin") != 0) // check if input from file or stdin
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
        printf("Enter lines ('q' to quit): \n");
    }

    while (getline(&buffer, &bufsize, f) != -1) // read lines stop at EOF
    {

        if (strcmp(buffer, "q\n") == 0)
        {
            break;
        }
        node = newLine();

        if (node == NULL)
        {
            fprintf(stderr, "malloc failed\n");
            exit(1);
        }
        node->line = strdup(buffer); // Copy content of line to node of linked list

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
    free(buffer); // free memory allocated by getline

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
void iterReverse(LINE **pStart) // iterative function to reverse linked list: https://www.geeksforgeeks.org/reverse-a-linked-list/
{
    LINE *prev = NULL;
    LINE *current = *pStart;
    LINE *next = NULL;
    while (current != NULL)
    {
        // Store next
        next = current->pNext;

        // Reverse current node's pointer
        current->pNext = prev;

        // Move pointers one position ahead.
        prev = current;
        current = next;
    }
    *pStart = prev;
}
void freeList(LINE **pStart) // function to free memory allocated to  the linked list
{
    while (*pStart != NULL)
    {
        LINE *temp = *pStart;
        *pStart = (*pStart)->pNext;
        free(temp->line); // free memory allocated by strdup in readFile
        free(temp);
    }
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
        iterReverse(&pStart);
        writeOutput(pStart, argv[2]);
    }
    else if (argc == 2) // In absence of output file print reverse order to stdout
    {
        pStart = readFile(argv[1]);
        iterReverse(&pStart);
        writeOutput(pStart, "stdout");
    }
    else if (argc == 1) // read from stdin and write to stdout
    {
        pStart = readFile("stdin");
        iterReverse(&pStart);
        writeOutput(pStart, "stdout");
    }
    else if (argc > 3)
    {
        fprintf(stderr, " usage: reverse <input> <output>\n");
        exit(1);
    }
    freeList(&pStart);
    return 0;
}