#include "../include/misclib.h"

void printChar(char ch, int n)
{
    while (n--)
    {
        putchar(ch);
    }
}

bool checkIfFileExists(const char *filename)
{
    FILE *fp = fopen(filename, "r");
    bool exits = false;
    if (fp != NULL)
    {
        exits = true;
        fclose(fp);
    }
    return exits;
}

void printFileContent(const char *filename)
{
    fflush(stdin);
    FILE *fptr;
    char buffer[256];

    fptr = fopen(filename, "r");
    if (fptr == NULL)
    {
        perror("\nNo se puede abrir el archivo\n");
        return;
    }

    while (fgets(buffer, sizeof(buffer), fptr) != NULL)
        printf("%s", buffer); // Reads line by line

    fclose(fptr);
}

void manageInput(const char *prompt, const char *format, void *data)
{
    printf("%s", prompt);
    scanf(format, data);
    while (getchar() != '\n');
}