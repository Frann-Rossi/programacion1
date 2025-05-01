#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int matricula;
    char nombre[30];
    char genero; //m, f, o
} stAlumno;

stAlumno cargarAlumno ()
{
    stAlumno alumno;
    printf("Matricula del Alumno:\n");
    scanf("%d",&alumno.matricula);
    printf("Nombre del Alumno:\n");
    scanf(" %s",&alumno.nombre);
    printf("Genero del Alumno:\n");
    scanf(" %c",&alumno.genero);
    return alumno;
}

int cargarAlumnos (stAlumno alumno[], int dim)
{
    int i = 0;
    int control = 1;
    while(i < dim && control)
    {
        printf("Ingrese los datos de un Alumno:\n");
        alumno[i] = cargarAlumno();
        i++;
        printf("Quiere seguir ingrese 1 sino 0 para salir:\n");
        scanf("%d",&control);
    }

    return i;
}

void mostrarAlumno(stAlumno alumno)
{
    printf("Matricula:%d || Nombre:%s || Genero:%c\n", alumno.matricula,alumno.nombre,alumno.genero);
}
void mostrarAlumnos(stAlumno alumno[], int val)
{
    for(int i = 0; i < val; i++)
    {
        mostrarAlumno(alumno[i]);
    }
}

int encontrarMatricula(stAlumno alumno[], int val, int matriculaBuscada)
{
    int bandera = 0;
    for(int i = 0; i < val; i++)
    {
        if(alumno[i].matricula == matriculaBuscada)
            bandera = 1;

    }
    return bandera;
}

int main()
{
    stAlumno alumnos[30];
    int cargados = 0;
    int matricula = 0;

    char control = 's';
    int opcion = 0;
    while (control == 's')
    {
        printf("Ingrese un Numero para el ejercicio\n");
        printf("ejercicio 1\n");
        printf("ejercicio 2\n");
        printf("ejercicio 3\n");
        printf("ejercicio 4\n");
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
        {
            cargados = cargarAlumnos(alumnos,30);

            break;
        }
        case 2:
        {
            mostrarAlumnos(alumnos,cargados);
            break;
        }
        case 3:
        {
            printf("Ingrese matricula del alumno a buscar");
            scanf("%d",&matricula);
            int matriculaBuscada = encontrarMatricula(alumnos,cargados, matricula);
            printf("El alumno esta en la pos: %d\n",matriculaBuscada);
            break;
        }
        default:
        {
            printf("Ingrese un valor valido\n");
        }
        }
        printf("Desea continuar ingrese 's' sino 'n'\n");
        scanf(" %c",&control);
    }
    return 0;
}
