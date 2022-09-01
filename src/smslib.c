#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../src/smslib.h"
#include <sys/stat.h>

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

struct pass
{
    char pass[25];

}pa;

// endregion: --- Structures

// region: --- Lib functions

void printChar(char ch, int n)
{
    while (n--) {
        putchar(ch);
    }
}

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
    printf("\n\n\t\t\t\t6. Change Password(WIP)");
    printf("\n\n\t\t\t\t7. Info(WIP)");
    printf("\n\n\t\t\t\t8. Logout\n\n\t");
    printChar('*', 65);

    printf("\n\n\t\t\t\tEnter your option: ");
}

int checkIfFileExists(const char* filename)
{
    struct stat buffer;
    int exist = stat(filename, &buffer);
    if (exist == 0)
    {
        return 1;
    }
    else
    {
        printf("File doesn't exists\n");
        return 0;
    }
}

int printFileContent(const char* filename)
{
    char c;

//    printf("\n");
//    printf("Enter the filename to open: ");
//    scanf("%s", filename);

    //Open file
    fptr = fopen(filename, "r");
    if (fptr == NULL)
    {
        printf("\nCannot open the file \n");
        printf("\n");
        exit(0);
    }

    //Read content of the file and print it
    c = fgetc(fptr);
    while (c != EOF)
    {
        printf("%c", c);
        c = fgetc(fptr);
    }
    printf("\n");

    fclose(fptr);
    return 0;
}

void password()
{
    char c;
    printf("\nEnter new password: ");
}

// endregion: --- Lib functions
