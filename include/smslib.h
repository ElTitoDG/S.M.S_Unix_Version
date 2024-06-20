#ifndef __SMSLIB_H__
#define __SMSLIB_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <curses.h>

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
void mainmenu();
void password();
void add();
void show();

#endif // __SMSLIB_H__
