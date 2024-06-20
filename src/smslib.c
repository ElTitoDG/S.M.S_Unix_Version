#include "../include/smslib.h"
#include "../include/misclib.h"

// region: --- Lib functions

/*
    Función: imprime el titulo de la app
*/
void title()
{
    system("clear");
    printf(KCYN "\n\n\t");
    printChar('=', 19);
    printf(" Student Management System ");
    printChar('=', 19);
    printf(KNRM "\n");
}

/*
    Función: imprime el menu principal
*/
void mainmenu()
{
    printf("\n\t");
    printChar('*', 65);

    printf("\n\n\t\t\t\t1. Add Student");
    printf("\n\n\t\t\t\t2. Modify Student");
    printf("\n\n\t\t\t\t3. Show all Students");
    printf("\n\n\t\t\t\t4. Individual View(WIP)");
    printf("\n\n\t\t\t\t5. Remove Student");
    printf("\n\n\t\t\t\t6. Change Password");
    printf("\n\n\t\t\t\t7. Info");
    printf("\n\n\t\t\t\tq. Logout\n\n\t");
    printChar('*', 65);

    printf("\n\n\t\t\t\tEnter your option: ");
}

/*
    Función: gestiona la creacion y modificacion de la contraseña
*/
void password()
{
    char c;
    struct TPassword newPassword;

    fflush(stdin);
    manageInput("\nEnter new password: ", "%s", &newPassword.pass);

    fflush(stdin);
    manageInput("\nSave Password (y/n): ", "%c", &c);
    if (c == 'y' || c == 'Y')
    {
        FILE *fichero = fopen("password.txt", "w");
        fprintf(fichero, "%s", newPassword.pass);
        fclose(fichero);
        printf("\n\tPassword Saved\n");
    }
    else
    {
        printf("Password not saved: \n");
        printf("Press any key to continue:");
        getchar();
    }
}

/*
    Función: añade un nuevo estudiante a la base de datos/archivo
*/
void add()
{
    title();

    struct TStudent newStudent;
    newStudent.id = 100;
    fflush(stdin);

    // Abre el archivo para buscar el id y asignarlo
    FILE *fichero = fopen("db.txt", "r");
    if (fichero != NULL)
    {
        char line[256];
        while (fgets(line, sizeof(line), fichero))
        {
            int current_id;
            sscanf(line, "%d.", &current_id);
            if (current_id > newStudent.id)
                newStudent.id = current_id;
        }
        fclose(fichero);
    }
    newStudent.id++;

    // Coje el nombre del estudiante
    printf("Ingrese el nombre del estudiante: ");
    if (fgets(newStudent.name, sizeof(newStudent.name), stdin) != NULL)
    {
        size_t len = strlen(newStudent.name);
        if (len > 0 && newStudent.name[len - 1] == '\n')
            newStudent.name[len - 1] = '\0';
    }

    // Coje la carrera del estudiante
    printf("Ingrese la carrera del estudiante: ");
    if (fgets(newStudent.dept, sizeof(newStudent.dept), stdin) != NULL)
    {
        size_t len = strlen(newStudent.dept);
        if (len > 0 && newStudent.dept[len - 1] == '\n')
            newStudent.dept[len - 1] = '\0';
    }

    printf("Datos: %d. %s|%s\n", newStudent.id, newStudent.name, newStudent.dept);

    fichero = fopen("db.txt", "a+");
    if (fichero == NULL)
    {
        printf("No se puede abrir el archivo \n");
        return;
    }

    fprintf(fichero, "%d. %s|%s\n", newStudent.id, newStudent.name, newStudent.dept);
    fclose(fichero);

    return;
}

/*
    Función: abre un archivo y lo imprime linea a linea
*/
void modStudent()
{
    title();

    FILE * fichero = fopen("db.txt", "r+");
    if (fichero == NULL)
    {
        perror("\nNo se puede abrir el archivo\n");
        return;
    }

    char line[256];
    struct TStudent mStudent;
    int found = 0, studentID;
    long int pos;

    manageInput("Introduzca el ID del estudiante a modificar: ", "%d", &studentID);

    while (fgets(line, sizeof(line), fichero) != NULL)
    {
        pos = ftell(fichero);
        sscanf(line, "%d. %[^|]|%[^\n]", &mStudent.id, mStudent.name, mStudent.dept);

        if (mStudent.id == studentID)
        {
            found = 1;

            printf("Ingrese el nuevo nombre: ");
            if (fgets(mStudent.name, sizeof(mStudent.name), stdin) != NULL)
            {
                size_t len = strlen(mStudent.name);
                if (len > 0 && mStudent.name[len - 1] == '\n')
                    mStudent.name[len - 1] = '\0';
            }

            printf("Ingrese la nueva carrera: ");
            if (fgets(mStudent.dept, sizeof(mStudent.dept), stdin) != NULL)
            {
                size_t len = strlen(mStudent.dept);
                if (len > 0 && mStudent.dept[len - 1] == '\n')
                    mStudent.dept[len - 1] = '\0';
            }

            printf("Datos: %d. %s|%s\n", mStudent.id, mStudent.name, mStudent.dept);

            fseek(fichero, pos - strlen(line), SEEK_SET);
            fprintf(fichero, "%d. %s|%s", mStudent.id, mStudent.name, mStudent.dept);
            break;
        }
    }

    fprintf(fichero, "\n");
    fclose(fichero);

    if (!found)
        printf("Estudiante con ID <%d> no encontrado.\n", studentID);
    else
        printf("Estudiante con ID <%d> actualizado correctamente.\n", studentID);
}

/*
    Función: funcion que borra un estudiante segun su id
             Creamos un archivo temporal para copiar todos menos el pedido
*/
void deleteStudent()
{
    FILE *fichero = fopen("db.txt", "r");
    if (fichero == NULL)
    {
        perror("\nNo se puede abrir el archivo\n");
        return;
    }

    FILE *temp = fopen("temp.txt", "w");
    if (temp == NULL)
    {
        perror("\nNo se puede crear el archivo temporal\n");
        fclose(fichero);
        return;
    }

    char line[256];
    struct TStudent delStudent;
    int found = 0, studentID;

    manageInput("Introduzca el ID del estudiante a eliminar: ", "%d", &studentID);

    while (fgets(line, sizeof(line), fichero) != NULL)
    {
        sscanf(line, "%d. %[^|]|%[^\n]", &delStudent.id, delStudent.name, delStudent.dept);

        if (delStudent.id == studentID)
            found = -1;
        else
            fprintf(temp, "%s", line);
    }

    fclose(fichero);
    fclose(temp);

    if (!found)
    {
        printf("Estudiante con ID <%d> no encontrado.\n", studentID);
        remove("temp.txt");
    } else
    {
        remove("db.txt");
        rename("temp.txt", "db.txt");
        printf("Estudiante con ID <%d> eliminado correctamente.\n", studentID);
    }

}
// endregion: --- Lib functions
