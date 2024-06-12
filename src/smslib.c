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

#define Student struct Stud
#define Pass struct Pass

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
    Pass pa;

    printf("\nEnter new password: ");
    fflush(stdin);
    fgets(pa.pass, sizeof(pa.pass), stdin);
    printf("\nSave Password (y/n): ");
    fflush(stdin);
    scanf("%c", &c);
    if (c == 'y' || c == 'Y')
    {
        fptr = fopen("password.txt", "w+");
        fwrite(&pa, sizeof(pa), 1, fptr);
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

    char c;
    Student s;

    // Solicitar al usuario que ingrese el nombre y el departamento
    printf("Ingrese el nombre del estudiante: ");
    fgets(s.name, sizeof(s.name), stdin);

    printf("Ingrese el departamento del estudiante: ");
    fgets(s.dept, sizeof(s.dept), stdin);

    // Eliminar el carácter de nueva línea de los valores ingresados
    s.name[strcspn(s.name, "\n")] = 0;
    s.dept[strcspn(s.dept, "\n")] = 0;

    // Abrir el archivo en modo escritura
    FILE *fp = fopen("students.txt", "a");

    // Verificar si el archivo se abrió correctamente
    if (fp == NULL)
    {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    // Escribir la estructura en el archivo
    fprintf(fp, "Name: %s\nDepartment: %s\n", s.name, s.dept);

    // Cerrar el archivo
    fclose(fp);

    printf("Se ha escrito la información en el archivo.\n");
}

void show()
{
    if (checkIfFileExists("db.txt") == 0)
        printf("File doen't exist\n");
    else
        printFileContent("db.txt");
}
// endregion: --- Lib functions
