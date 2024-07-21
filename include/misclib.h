#ifndef __MISCLIB_H__
#define __MISCLIB_H__

#include "smslib.h"

void printChar(char ch, int n);
bool checkIfFileExists(const char *filename);
void printFileContent(const char *filename);
void manageInput(const char *prompt, const char *format, void *data);
void show(const char *filename);
void gui();

#endif // __MISCLIB_H__