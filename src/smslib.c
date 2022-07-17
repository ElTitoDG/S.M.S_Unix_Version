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

// endregion: --- Lib functions
