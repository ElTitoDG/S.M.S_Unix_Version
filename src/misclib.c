#include "../include/misclib.h"

/*
    Function: prints X characters N times
    -ch: character to print
    -n: times to print
*/
void printChar(char ch, int n)
{
    while (n--)
    {
        putchar(ch);
    }
}

/*
    Function: checks if a file exists
    -filename: file to search for
    return: exits variable to false if you can't open it, true if you can open it
*/
bool checkIfFileExists(const char *filename)
{
    FILE *fichero = fopen(filename, "r");
    bool exits = false;
    if (fichero != NULL)
    {
        exits = true;
        fclose(fichero);
    }
    return exits;
}

/*
    Function: opens a file and prints it line by line
    -filename: file to print
*/
void printFileContent(const char *filename)
{
    fflush(stdin);
    FILE *fichero;
    char buffer[256];

    fichero = fopen(filename, "r");
    if (fichero == NULL)
    {
        perror("\nNo se puede abrir el archivo\n");
        return;
    }

    while (fgets(buffer, sizeof(buffer), fichero) != NULL)
        printf("%s", buffer); // lee linea a linea

    fclose(fichero);
}

/*
    Function: handles basic input requests
    -prompt: string that writes the message to be written on the screen
    -format: the data format -> "%d", "%f"...
    -data: where to save what is being requested
*/
void manageInput(const char *prompt, const char *format, void *data)
{
    printf("%s", prompt);
    if (scanf(format, data) != 1)
    {
        fprintf(stderr, "Error leyendo el input. Pruebe otra vez.\n");
        while (getchar() != '\n');
    }
    while (getchar() != '\n');
}

/*
    Function: display a file on the screen
*/
void show(const char *filename)
{
    if (checkIfFileExists(filename) == false)
        printf("El archivo no existe\n");
    else
        printFileContent(filename);
}