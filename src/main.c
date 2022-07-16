#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <curses.h>
#include <unistd.h>
#include "../src/smslib.h"

void title();
void printChar(char ch, int n);

int main() {

    title();
    printf("\n\n\t\t\t\t2022-2023 Academic Year");
    printf("\n\n\t\t\t\t Julián Hinojosa Gil");
    printf("\n\n\t\t\t\t San Agustin Institute\n\t\t\t");
    printChar('=', 39);
    printf("\n\n\n\t\t\t press any key to enter");
    getchar();

    return 1;
}
