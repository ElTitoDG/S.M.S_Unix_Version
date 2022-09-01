#ifdef __SMSLIB_H__
#define __SMSLIB_H_

void printChar(char ch, int n);

void title();

void mainmenu();

int checkIfFileExists(const char* filename);

int printFileContent(const char* filename);

#endif // __SMSLIB_H__
