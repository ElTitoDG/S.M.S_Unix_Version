#include "../src/smslib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <curses.h>
#include <unistd.h>
#define sleep_time 1
// region: --- Lib functions

void title();
void mainmenu();
void printChar(char ch, int n);
int printFileContent(const char* filename);
int checkIfFileExists(const char* filename);
void password();
void add();


// endregion: --- Lib functions

int main() {

    // region: --- Main func variables

    int option;

    // endregion: --- Main func variables

    // region: --- Main Title TUI

    title();
    printf("\n\n\t\t\t\t2022-2023 Academic Year");
    printf("\n\n\t\t\t\t Julián Hinojosa Gil");
    printf("\n\n\t\t\t\t San Agustin Institute\n\t\t\t");
    printChar('=', 39);
    printf("\n\n\n\t\t\t press any key to enter");
    getchar();

    // endregion: --- Main Title TUI

    while (1) {

        title();
        mainmenu();

        scanf("%d", &option);

        switch (option) {
            case 1:
               add();
               sleep(sleep_time);
               getchar();
               break;
            case 6:
                password();
                sleep(sleep_time);
                printf("\n\t\tPress any key to continue\n\n\n");
                getchar();
                break;
            case 7:
                if (checkIfFileExists("test/a.txt")) {
                    printFileContent("test/a.txt");
                } else
                {
                    printf("not exits");
                }
                sleep(sleep_time);
                printf("\n\t\tPress any key to continue\n\n\n");
                getchar();
                break;
            case 8:
                return 1;
                break;
            default:
                printf("\n\t\tNo action selected");
                printf("\n\t\tPress any key to continue\n\n\n");
                sleep(sleep_time);
                getchar();
        }

    }
    return 1;
}
