#include "../include/misclib.h"
#include "../include/smslib.h"



FILE *fptr;

void printChar(char ch, int n)
{
    while (n--)
    {
        putchar(ch);
    }
}

int checkIfFileExists(const char *filename)
{
    struct stat buffer;
    return stat(filename, &buffer);
}

void printFileContent(const char *filename)
{
    FILE *fptr;
    char c;

    // Open file
    fptr = fopen(filename, "r");
    if (fptr == NULL)
    {
        perror("\nCannot open the file \n");
        printf("\n");
        return;
    }

    // Read content of the file and print it

    while ((c = fgetc(fptr)) != EOF)
    {
        putchar(c);
    }
    putchar('\n');

    fclose(fptr);
}
