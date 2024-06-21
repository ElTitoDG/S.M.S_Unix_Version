#include "../include/misclib.h"

/*
    Función: imprime X carateres N veces
    -ch: caracter a imprimir
    -n: veces a imprimir
*/
void printChar(char ch, int n)
{
    while (n--)
    {
        putchar(ch);
    }
}

/*
    Función: comprueba si un archivo existe
    -filename: archivo a buscar
    return: la variable exits en falso si no lo puede abrir, true si lo puede abrir
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
    Función: abre un archivo y lo imprime linea a linea
    -filename: archivo a imprimir
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
    Función: gestiona las peticiones basicas de input
    -prompt: string que escribe el mensaje por pantalla a escribir
    -format: el formato de dato -> "%d", "%f"...
    -data: donde se va a guardar lo que se pide
*/
void manageInput(const char *prompt, const char *format, void *data)
{
    printf("%s", prompt);
    scanf(format, data);
    while (getchar() != '\n');
}

/*
    Función: saaca por pantalla un archivo
*/
void show(const char *filename)
{
    if (checkIfFileExists(filename) == false)
        printf("El archivo no existe\n");
    else
        printFileContent(filename);
}