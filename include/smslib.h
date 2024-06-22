#ifndef __SMSLIB_H__
#define __SMSLIB_H__

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <stdbool.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <curses.h>

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

struct TPassword
{
    char pass[25];
};

struct TStudent
{
    int id;
    char name[100];
    char dept[100];
};

void printChar(char ch, int n);
void title();
void mainMenu();
void password();
void add();
void modStudent();
void deleteStudent();
void showStudent(const char *filename);

#endif // __SMSLIB_H__
