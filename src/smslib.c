#include "../include/smslib.h"
#include "../include/misclib.h"

/*
    Function: prints the app title
*/
void title()
{
    int ret = system("clear");
    if (ret != 0)
        fprintf(stderr, "Error limpiando la consola con el comando 'clear'.\n");
    printf(KCYN "\n\n\t");
    printChar('=', 19);
    printf(" Student Management System ");
    printChar('=', 19);
    printf(KNRM "\n");
}

/*
    Function: prints the main menu
*/
void mainMenu()
{
    printf("\n\t");
    printChar('*', 65);

    printf("\n\n\t\t\t\t1. Add Student");
    printf("\n\n\t\t\t\t2. Modify Student");
    printf("\n\n\t\t\t\t3. Show all Students");
    printf("\n\n\t\t\t\t4. Individual View");
    printf("\n\n\t\t\t\t5. Remove Student");
    printf("\n\n\t\t\t\t6. Change Password");
    printf("\n\n\t\t\t\t7. Info");
    printf("\n\n\t\t\t\tq. Logout\n\n\t");
    printChar('*', 65);

    printf("\n\n\t\t\t\tSelecciona una opción: ");
}

/*
    Function: manages password creation and modification
*/
void password()
{
    char c;
    struct TPassword newPassword;

    fflush(stdin);
    manageInput("\nNueva contraseña: ", "%s", newPassword.pass);

    fflush(stdin);
    manageInput("\nGuardar contraseña (s/n): ", "%c", &c);
    if (c == 's' || c == 'S')
    {
        FILE *fichero = fopen("password.txt", "w");
        fprintf(fichero, "%s", newPassword.pass);
        fclose(fichero);
        printf("\n\tContraseña guardada\n");
    }
    else
        printf("Contraseña no guardada: \n");
}

void studentInput(struct TStudent *stud)
{
    // Get the student's name
    printf("Ingrese el nombre del estudiante: ");
    if (fgets(stud->name, sizeof(stud->name), stdin) != NULL)
    {
        size_t len = strlen(stud->name);
        if (len > 0 && stud->name[len - 1] == '\n')
            stud->name[len - 1] = '\0';
    }

    // Take the student's career
    printf("Ingrese la carrera del estudiante: ");
    if (fgets(stud->dept, sizeof(stud->dept), stdin) != NULL)
    {
        size_t len = strlen(stud->dept);
        if (len > 0 && stud->dept[len - 1] == '\n')
            stud->dept[len - 1] = '\0';
    }
}

/*
    Function: adds a new student to the database/file
*/
void add()
{
    title();

    struct TStudent newStudent;
    newStudent.id = 100;
    fflush(stdin);

    // Open the file to search for the id and assign it
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

    studentInput(&newStudent);

    printf("Datos: %d. %s|%s\n", newStudent.id, newStudent.name, newStudent.dept);

    fichero = fopen("db.txt", "a+");
    if (fichero == NULL)
    {
        printf("No se puede abrir el archivo \n");
        return;
    }

    fprintf(fichero, "%d. %s|%s\n", newStudent.id, newStudent.name, newStudent.dept);
    fclose(fichero);
}

/*
    Function: opens a file and prints it line by line
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

            studentInput(&mStudent);

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
Function: function that deletes a student according to its id
            We create a temporary file to copy all but the request
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

void showStudent(const char *filename)
{
    char line[256];
    struct TStudent student;
    int found = 0, studentID;

    FILE *fichero = fopen(filename, "r");
    if (fichero == NULL)
    {
        perror("No se ha podido abrir el archivo\n");
        return;
    }

    manageInput("Introduzca el ID del estudiante a mostrar: ", "%d", &studentID);
    printf("\n");

    while (fgets(line, sizeof(line), fichero) != NULL)
    {
        sscanf(line, "%d. %[^|]|%[^\n]", &student.id, student.name, student.dept);
        if (student.id == studentID)
        {
            found = 1;
            printf("ID: %d\n Nombre: %s\n Carrera: %s\n", student.id, student.name, student.dept);
            break;
        }
    }

    if (!found)
        printf("Estudiente con ID %d no encontrado.\n", student.id);

    fclose(fichero);
}