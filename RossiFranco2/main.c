#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "pila.h"

void recuperarPila(Pila* pila, Pila* aux)
{
    while(!pilavacia(aux))
    {
        apilar(pila,desapilar(aux));
    }
}

/**Ej 1**/
void cargarElementos(Pila* pila)
{
    int control = 1;
    while(control)
    {
        leer(pila);
        printf("Quiere seguir ingrese 1 sino 0 para salir\n");
        scanf("%d",&control);
    }
    mostrar(pila);
}

void calcularCarga(Pila* pila, int* suma, int* cantidad)
{
    Pila aux;
    inicpila(&aux);
    *suma = 0;
    *cantidad = 0;
    while(!pilavacia(pila))
    {
        int valor = desapilar(pila);
        *suma += valor;
        apilar(&aux, valor);
        (*cantidad)++;

    }
    recuperarPila(pila,&aux);
}
/**Ej 2**/
void ordenarPorInsercion (Pila* pila, Pila* pilaOrdenada)
{

    while(!pilavacia(pila))
    {
        int num = desapilar(pila);
        insertar(pilaOrdenada, num);
    }
    mostrar(pilaOrdenada);
}

void insertar (Pila* pilaOrdenada, int elemento)
{
    Pila aux;
    inicpila(&aux);
    while(!pilavacia(pilaOrdenada) && tope(pilaOrdenada) < elemento)
    {
        apilar(&aux,desapilar(pilaOrdenada));
    }
    apilar(pilaOrdenada, elemento);

    recuperarPila(pilaOrdenada,&aux);
}

/**Ej 3**/



int main()
{
    Pila pila;
    Pila pilaOrdenada;
    inicpila(&pila);
    inicpila(&pilaOrdenada);
    int sumaPila, cantidadPila;
    int arr[20];

    char control = 's';
    int opcion = 0;
    while(control == 's')
    {
        printf("Seleccione un ejercicio:\n");
        printf("Ejercicio 1:\n");
        scanf("%d",&opcion);
        switch(opcion )
        {
        case 1:
        {
            cargarElementos(&pila);
            calcularCarga(&pila, &sumaPila, &cantidadPila);
            printf("La suma total fue de: %d || Y la cantidad de elementos son: %d\n", sumaPila, cantidadPila);
            break;
        }
        case 2:
        {
            ordenarPorInsercion(&pila,&pilaOrdenada);
            break;

        }
        default:
        {
            printf("Ingrese un valor valido");
        }
        }
        printf("Desea continuar ingrese 's' sino 'n' para salir ");
        fflush(stdin);
        scanf("%c",&control);
    }
    return 0;
}
