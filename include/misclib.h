#ifndef __MISCLIB_H__
#define __MISCLIB_H__

#include <stdio.h>
#include "../include/smslib.h"

void printChar(char ch, int n);
bool checkIfFileExists(const char *filename);
void printFileContent(const char *filename);

#endif // __MISCLIB_H__
