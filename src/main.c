#include "../include/smslib.h"
#include "../include/misclib.h"

#define sleep_time 1

int main()
{
    char option;

    title();
    printf("\n\n\t\t\t\t2022-2023 Academic Year");
    printf("\n\n\t\t\t\t Julián Hinojosa Gil");
    printf("\n\n\t\t\t\t Universidad de Alicante\n\t\t\t");
    printChar('=', 39);
    printf("\n\n\t\t\tPulsa cualquier tecla para continuar");
    getchar();

    while (1)
    {
        title();
        mainMenu();

        if (scanf(" %c", &option) != 1)
        {
            fprintf(stderr, "Error leyendo el input. Pruebe otra vez.\n");
            while (getchar() != '\n');
            return EXIT_FAILURE;
        }

        switch (option)
        {
            case '1':
                add("db.txt");
                break;
            case '2':
                modStudent("db.txt");
                break;
            case '3':
                show("db.txt");
                break;
            case '4':
                showStudent("db.txt");
                break;
            case '5':
                deleteStudent("db.txt");

                break;
            case '6':
                password();
                break;
            case '7':
                if (checkIfFileExists("test/a.txt"))
                    printFileContent("test/a.txt");
                else
                    printf("not exits");
                break;
            case 'q':
                return EXIT_SUCCESS;
            default:
                printf("\n\t\tNinguna opción seleccionada");
                sleep(sleep_time);
        }
        sleep(sleep_time);
        printf("\n\t\tPresione cualquier tecla para continuar");
        getchar();
    }
}
