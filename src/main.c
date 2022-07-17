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
        scanf("%d", &option);

        switch (option) {
            case 8:
                return 1;
                break;
            default:
                printf("\n\t\tNo action selected");
                printf("\n\t\tPress any key\n\n\n");
                sleep(1);
                getchar();
        }

    }
    return 1;
}
