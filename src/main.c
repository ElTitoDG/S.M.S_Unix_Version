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
    printf("\n\n\t\t\t\t Universidad de Alicante\n\t\t\t");
    printChar('=', 39);
    printf("\n\n\t\t\tPulsa cualquier tecla para continuar");
    getchar();

    // endregion: --- Main Title TUI

    while (1)
    {
        title();
        mainMenu();

        scanf(" %c", &option);

        switch (option)
        {
        case '1':
            add();

            sleep(sleep_time);
            printf("\n\t\tPresione cualquier tecla para continuar");
            getchar();
            break;
        case '2':
            modStudent();

            sleep(sleep_time);
            printf("\n\t\tPresione cualquier tecla para continuar");
            getchar();
            break;
        case '3':
            show("db.txt");

            sleep(sleep_time);
            printf("\n\t\tPresione cualquier tecla para continuar");
            getchar();
            break;
        case '4':
            showStudent("db.txt");

            sleep(sleep_time);
            printf("\n\t\tPresione cualquier tecla para continuar");
            getchar();
            break;
        case '5':
            deleteStudent();

            sleep(sleep_time);
            printf("\n\t\tPresione cualquier tecla para continuar");
            getchar();
            break;
        case '6':
            password();

            sleep(sleep_time);
            printf("\n\t\tPresione cualquier tecla para continuar");
            getchar();
            break;
        case '7':
            if (checkIfFileExists("test/a.txt"))
                printFileContent("test/a.txt");
            else
                printf("not exits");

            sleep(sleep_time);
            printf("\n\t\tPresione cualquier tecla para continuar");
            getchar();
            break;
        case 'q':
            return EXIT_SUCCESS;
            break;
        default:
            printf("\n\t\tNinguna opcion seleccionada");
            printf("\n\t\tPresione cualquier tecla para continuar\n\n\n");
            sleep(sleep_time);
            getchar();
        }
    }
    return EXIT_FAILURE;
}
