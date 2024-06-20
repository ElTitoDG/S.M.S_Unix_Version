#include "../include/smslib.h"
#include "../include/misclib.h"
#include <stdio.h>
#include <sys/_types/_null.h>

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
    printf("\n\n\t\t\t\tq. Logout\n\n\t");
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
    newStudent.id = 100;
    fflush(stdin);

    FILE *fichero = fopen("db.txt", "r");
    if (fichero != NULL)
    {
        char line[256];
        while (fgets(line, sizeof(line), fichero))
        {
            int current_id;
            sscanf(line, "%d.", &current_id);
            if (current_id > newStudent.id)
                newStudent.id = current_id;
        }
        fclose(fichero);
    }
    newStudent.id++;

    printf("Ingrese el nombre del estudiante: ");
    if (fgets(newStudent.name, sizeof(newStudent.name), stdin) != NULL)
    {
        size_t len = strlen(newStudent.name);
        if (len > 0 && newStudent.name[len - 1] == '\n')
            newStudent.name[len - 1] = '\0';
    }

    printf("Ingrese la carrera del estudiante: ");
    if (fgets(newStudent.dept, sizeof(newStudent.dept), stdin) != NULL)
    {
        size_t len = strlen(newStudent.dept);
        if (len > 0 && newStudent.dept[len - 1] == '\n')
            newStudent.dept[len - 1] = '\0';
    }

    printf("Datos: %d. %s|%s\n", newStudent.id, newStudent.name, newStudent.dept);

    fichero = fopen("db.txt", "a+");
    if (fichero == NULL)
    {
        printf("No se puede abrir el archivo \n");
        return;
    }

    fprintf(fichero, "%d. %s|%s\n", newStudent.id, newStudent.name, newStudent.dept);
    fclose(fichero);

    return;
}

void show()
{
    if (checkIfFileExists("db.txt") == false)
        printf("File doen't exist\n");
    else
        printFileContent("db.txt");
}
// endregion: --- Lib functions
