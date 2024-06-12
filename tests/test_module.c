#include <string.h>
#include <stdio.h>

struct Stud
{
    char name[50];
    char dept[50];
};

int main()
{
    struct Stud student;

    printf("Nombre del estudiante: ");
    fgets(student.name, sizeof(student.name), stdin);

    printf("Carrera del estudiante: ");
    fgets(student.dept, sizeof(student.dept), stdin);

    student.name[strcspn(student.name, "\n")] = 0;
    student.dept[strcspn(student.dept, "\n")] = 0;

    FILE *fp = fopen("students.txt", "a");

    if (fp == NULL)
        {
            perror("No se pudo abrir el archivo\n");
            return 1;
        }

    fprintf(fp, "%s|%s\n", student.name, student.dept);

    fclose(fp);

    printf("Se ha escrito el archivo correctamente\n");

    return 0;
}
