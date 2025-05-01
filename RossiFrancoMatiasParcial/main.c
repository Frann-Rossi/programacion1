#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pila.h"

//Rossi Franco Matias
//Com 7

/**Ejercio 1**/
int cargarKm (int arr[])
{
    int control = 's';
    int km = 0;
    int i = 0;
    while(control == 's')
    {
        for(int j = 0; j < 5; j++)
        {
            printf("Cuantos km hizo en la vuelta %d:\n", i+1);
            scanf("%d", &arr[i]);
            i++;
        }
        printf("Desea seguir ingrese 's' sino 'n' para terminar\n");
        scanf(" %c", &control);

    }
    return i;
}

int tramoMayor (int arr[], int val)
{
    int i = 0;
    int posTramo = 0;
    for(i; i < val; i++)
    {
        if(arr[posTramo] < arr[i])
        {
            posTramo = i ;
        }
    }
    return posTramo;
}

void mostrarTramo (int arr[], int val)
{
    for(int i = 0; i < val; i++)
    {
        if(arr[i] != 0)
        {
            printf("Vuelta %d: KM:%d\n",i + 1, arr[i]);
        }

        if(i % 5 == 0)
        {
            printf("\n");
        }

    }
}

void kmRecorridos (int arr[], int val, Pila pila)
{
    int suma = 0;
    int contador = 0;
    for(int i = 0; i < val; i++)
    {
        suma += arr[i];
        contador++;

        if (contador == 5)
        {
            apilar(&pila, suma);
            suma = 0;
            contador = 0;
        }
    }
    mostrar(&pila);
}

int main()
{
    Pila pila;
    inicpila(&pila);
    int arr[20];
    int val = 0;

    int opcion = 0;
    char control = 's';
    while(control == 's')
    {
        printf("Ej 1\n");
        printf("Ej 2\n");
        printf("Ej 2\n");
        scanf("%d", &opcion);
        switch(opcion)
        {
        case 1:
        {
            val = cargarKm(arr);
            for(int i = 0; i < val; i++)
            {
                printf("Vuelta %d: KM:%d\n",i + 1, arr[i]);
            }
            break;
        }
        case 2:
        {
            int posMayor = tramoMayor(arr, val);
            printf("El tramo mayor fue de: %d en el dia %d\n",arr[posMayor],posMayor/5);
            break;
        }
        case 3:
        {
            mostrarTramo(arr,val);
            break;
        }
        case 4:
        {
            kmRecorridos(arr,val, pila);
            break;
        }
         case 5:
        {

            break;
        }
        default:
        {
            printf("Ingrese un Valor valido\n");
        }
        }
        printf("Desea continuar ingrese 's' sino 'n' para salir\n");
        scanf(" %c", &control);
    }

    return 0;
}
