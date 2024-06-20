#include "../include/smslib.h"
#include "../include/misclib.h"

#define sleep_time 1

int main()
{
    // region: --- Main func variables

    char option;

    // endregion: --- Main func variables

    // region: --- Main Title TUI

    title();
    printf("\n\n\t\t\t\t2022-2023 Academic Year");
    printf("\n\n\t\t\t\t Julián Hinojosa Gil");
    printf("\n\n\t\t\t\t San Agustin Institute\n\t\t\t");
    printChar('=', 39);
    printf("\n\n\t\t\t\tpress any key to enter");
    getchar();

    // endregion: --- Main Title TUI

    while (1)
    {
        title();
        mainmenu();

        scanf(" %c", &option);

        switch (option)
        {
        case '1':
            add();
            sleep(sleep_time);
            printf("\t\tPress any key to continue");
            getchar();
            break;
        case '2':
            modStudent();
            sleep(sleep_time);
            printf("\t\tPress any key to continue");
            getchar();
            break;
        case '3':
            show();
            sleep(sleep_time);
            printf("\t\tPress any key to continue");
            getchar();
            break;
        case '6':
            password();
            sleep(sleep_time);
            printf("\t\tPress any key to continue");
            getchar();
            break;
        case '7':
            if (checkIfFileExists("test/a.txt"))
            {
                printFileContent("test/a.txt");
            }
            else
            {
                printf("not exits");
            }
            sleep(sleep_time);
            printf("\t\tPress any key to continue");
            getchar();
            break;
        case 'q':
            return EXIT_SUCCESS;
            break;
        default:
            printf("\n\t\tNo action selected");
            printf("\n\t\tPress any key to continue\n\n\n");
            sleep(sleep_time);
            getchar();
        }
    }
    return EXIT_FAILURE;
}
