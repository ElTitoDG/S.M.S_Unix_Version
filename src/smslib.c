#include "../include/smslib.h"
#include "../include/misclib.h"
#include <stdio.h>
#include <string.h>

// region: --- Terminal Colors

#define KNRM "\x1B[0m"
#define KRED "\x1B[31m"
#define KGRN "\x1B[32m"
#define KYEL "\x1B[33m"
#define KBLU "\x1B[34m"
#define KMAG "\x1B[35m"
#define KCYN "\x1B[36m"
#define KWHT "\x1B[37m"

// endregion: --- Terminal Colors

FILE *fptr;

// region: --- Structures


// endregion: --- Structures

// region: --- Lib functions

void title()
{
    system("clear");
    printf(KCYN "\n\n\t");
    printChar('=', 19);
    printf(" Student Management System ");
    printChar('=', 19);
    printf(KNRM "\n");
}

void mainmenu()
{
    printf("\n\t");
    printChar('*', 65);

    printf("\n\n\t\t\t\t1. Add Student(WIP)");
    printf("\n\n\t\t\t\t2. Modify Student(WIP)");
    printf("\n\n\t\t\t\t3. Show all Students(WIP)");
    printf("\n\n\t\t\t\t4. Individual View(WIP)");
    printf("\n\n\t\t\t\t5. Remove Student(WIP)");
    printf("\n\n\t\t\t\t6. Change Password");
    printf("\n\n\t\t\t\t7. Info");
    printf("\n\n\t\t\t\t8. Logout\n\n\t");
    printChar('*', 65);

    printf("\n\n\t\t\t\tEnter your option: ");
}

void password()
{
    char c;
    struct TPassword newPassword;

    printf("\nEnter new password: ");
    fflush(stdin);
    fgets(newPassword.pass, sizeof(newPassword.pass), stdin);
    printf("\nSave Password (y/n): ");
    fflush(stdin);
    scanf("%c", &c);
    if (c == 'y' || c == 'Y')
    {
        fptr = fopen("password.txt", "w+");
        fwrite(&newPassword, sizeof(newPassword), 1, fptr);
        fclose(fptr);
        printf("\n\tPassword Saved\n");
    }
    else
    {
        printf("Password not saved: \n");
        printf("Press any key to continue:");
        getchar();
    }
}

void add()
{
    title();

    struct TStudent newStudent;

    // Solicitar al usuario que ingrese el nombre y el departamento
    printf("Ingrese el nombre del estudiante: ");
    scanf("%s", newStudent.name);

    printf("Ingrese la carrera: ");
    scanf("%s", newStudent.dept);

    printf("Datos: %s|%s", newStudent.name, newStudent.dept);

    FILE *fichero = fopen("db.txt", "a+");
    if (fichero == NULL)
    {
        printf("No se puede abrir el archivo \n");
        return;
    }

    fprintf(fichero, "%s|%s\n", newStudent.name, newStudent.dept);
    fclose(fichero);

    return;
}

void show()
{
    if (checkIfFileExists("../db.txt") == 0)
        printf("File doen't exist\n");
    else
        printFileContent("../db.txt");
}
// endregion: --- Lib functions
