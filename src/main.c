#include <smslib.h>
#include <misclib.h>
#include <raylib.h>
#define RAYGUI_IMPLEMENTATION
#include <raygui.h>

#define sleep_time 1

int main(void)
{
    char option;

    title();
    printf("\n\n\t\t\t\t2022-2023 Academic Year");
    printf("\n\n\t\t\t\t Julián Hinojosa Gil");
    printf("\n\n\t\t\t\t Universidad de Alicante\n\t\t\t");
    printChar('=', 39);
    printf("\n\n\t\t\tPulsa cualquier tecla para continuar");
    getchar();

    InitWindow(400, 200, "raygui - controls test suite");
    SetTargetFPS(60);
    bool showMessageBox = false;
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

            case '8':
                while (!WindowShouldClose())
                {
                    // Draw
                    //----------------------------------------------------------------------------------
                    BeginDrawing();
                    ClearBackground(GetColor(GuiGetStyle(DEFAULT, BACKGROUND_COLOR)));

                    if (GuiButton((Rectangle){ 24, 24, 120, 30 }, "#191#Show Message")) showMessageBox = true;

                    if (showMessageBox)
                    {
                        int result = GuiMessageBox((Rectangle){ 85, 70, 250, 100 },
                                                   "#191#Message Box", "Hi! This is a message!", "Nice;Cool");

                        if (result >= 0) showMessageBox = false;
                    }

                    EndDrawing();
                }
                CloseWindow();
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
