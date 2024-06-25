#include "include/smslib.h"
#include "include/misclib.h"
#include "deps/GLFW/glfw3.h"
#define NK_IMPLEMENTATION
#include "deps/nuklear.h"

#define sleep_time 1

static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}

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
                glfwInit();

                GLFWwindow* window = glfwCreateWindow(640, 480, "Simple example", NULL, NULL);
                glfwSetErrorCallback(error_callback);
                if (!glfwInit())
                    return EXIT_FAILURE;
                if (!window)
                {
                    glfwTerminate();
                    return EXIT_FAILURE;
                }
                glfwMakeContextCurrent(window);
                glfwSetKeyCallback(window, key_callback);
                while (!glfwWindowShouldClose(window))
                {
                    glClear(GL_COLOR_BUFFER_BIT);
                    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

                    glfwPollEvents();
                    glfwSwapBuffers(window);
                }
                glfwDestroyWindow(window);
                glfwTerminate();
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

    return 0;
}
