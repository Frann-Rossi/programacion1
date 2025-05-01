#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pila.h"

int devolverArr (int arr[], int maxCantidad)
{
    int cantidad = 0;
    char control = 's';

    while(control == 's' && cantidad < maxCantidad)
    {
        printf("Ingrese un valor\n");
        scanf("%d", &arr[cantidad]);
        cantidad++;

        printf("¿Desea ingresar otro valor? (s/n): ");
        scanf(" %c", &control);
    }
    return cantidad;
}
int devolverArrChar (char arr[], int maxCantidad)
{
    int cantidad = 0;
    char control = 's';

    while(control == 's' && cantidad < maxCantidad)
    {
        printf("Ingrese un valor\n");
        scanf(" %c", &arr[cantidad]);
        cantidad++;

        printf("¿Desea ingresar otro valor? (s/n): ");
        scanf(" %c", &control);
    }
    return cantidad;
}

void mostrarArrChar (char arr[], int cantidad)
{
    printf("Elementos ingresados:\n");
    for (int i = 0; i < cantidad; i++)
    {
        printf("%c\n", arr[i]);
    }
}

void mostrarArr (int arr[], int cantidad)
{
    printf("Elementos ingresados:\n");
    for (int i = 0; i < cantidad; i++)
    {
        printf("%d\n", arr[i]);
    }
}

int sumarArr (int arr[], int cantidad)
{
    int sumar = 0;
    for (int i = 0; i < cantidad; i++)
    {
        sumar += arr[i];
    }
    return sumar;
}
void copiarArrPila (int arr[], int cantidad, Pila *dada)
{
    for(int i = 0; i < cantidad; i++)
    {
        apilar(dada,arr[i]);
    }
}

float sumarArr2 (float arr[], int cantidad)
{
    float sumar = 0;
    for (int i = 0; i < cantidad; i++)
    {
        sumar += arr[i];
    }
    return sumar;
}
void mostrarArr2 (float arr[], int cantidad)
{
    printf("Elementos ingresados:\n");
    for (int i = 0; i < cantidad; i++)
    {
        printf("%.2f\n", arr[i]);
    }
}
int devolverArr2 (float arr[], int maxCantidad)
{
    int cantidad = 0;
    char control = 's';

    while(control == 's' && cantidad < maxCantidad)
    {
        printf("Ingrese un valor\n");
        scanf("%f", &arr[cantidad]);
        cantidad++;

        printf("¿Desea ingresar otro valor? (s/n): ");
        scanf(" %c", &control);
    }
    return cantidad;
}

int elementoExiste (char *arr,int cantidad, char elemento)
{
    for (int i = 0; i < cantidad; i++)
    {
        if(arr[i] == elemento)
        {
            printf("El elemento %c existe en la lista.\n", elemento);
            return 1;
        }
        printf("El elemento %c no existe en la lista.\n", elemento);
        return 0;
    }
}

void fusionarArreglos(int arrA[], int sizeA, int arrB[], int sizeB, int arrC[])
{
    int i = 0, j = 0, k = 0;


    while (i < sizeA && j < sizeB)
    {
        if (arrA[i] < arrB[j])
        {
            arrC[k++] = arrA[i++];
        }
        else
        {
            arrC[k++] = arrB[j++];
        }
    }


    while (i < sizeA)
    {
        arrC[k++] = arrA[i++];
    }


    while (j < sizeB)
    {
        arrC[k++] = arrB[j++];
    }
}


int main()
{
    srand(time(NULL));
    int opcion = 0;
    char control = 's';
    while(control == 's')
    {
        printf("Ingrese un Numero para el ejercicio\n");
        printf("Ejercio 1 - ingrese 1 \n");
        printf("Ejercio 2 - ingrese 2 \n");
        printf("Ejercio 3 - ingrese 3 \n");
        printf("Ejercio 4 - ingrese 4 \n");
        printf("Ejercio 5 - ingrese 5 \n");
        printf("Ejercio 6 - ingrese 6 \n");
        scanf("%d", &opcion);
        switch(opcion)
        {
        case 1:
        {
            /*
            1. Hacer una función que reciba como parámetro un arreglo de números enteros y permita que
            el usuario ingrese valores al mismo por teclado. La función debe retornar la cantidad de
            elementos cargados en el arreglo (o pueden utilizar como puntero válidos).
            */
            int arr[10];
            int cantidad = devolverArr(arr, 5);

            printf("Se ingresaron %d elementos.\n", cantidad);
            break;
        }
        case 2:
        {
            /*
            2. Hacer una función que reciba como parámetro un arreglo y la cantidad de elementos (válidos)
            cargados en él y los muestre por pantalla.
            */
            int arr[10];
            int cantidad = devolverArr(arr, 5);

            printf("Se ingresaron %d elementos.\n", cantidad);
            mostrarArr(arr, cantidad);

            break;
        }
        case 3 :
        {
            /*
            3. Hacer una función que reciba como parámetro un arreglo y la cantidad de elementos (válidos)
            cargados en él y calcule la suma de sus elementos.
            */
            int arr[10];
            int cantidad = devolverArr(arr, 5);

            int suma = sumarArr(arr, cantidad);
            printf("La suma de los valores ingresados es: %d\n", suma);
            break;
        }
        case 4 :
        {
            /*4. Hacer una función que reciba como parámetro un arreglo, la cantidad de elementos (válidos)
            cargados en él y una Pila. La función debe copiar los elementos del arreglo en la pila.*/
            int arr[10];
            int cantidad = devolverArr(arr, 5);
            Pila dada;
            inicpila(&dada);
            copiarArrPila(arr,cantidad,&dada);
            mostrar(&dada);
            break;
        }
        case 5 :
        {
            /*5. Realizar una función que sume los elementos de un arreglo de números reales (float) de
            dimensión 100. (se recomienda hacer una función para cargar y otra para mostrar para este
            tipo de dato asociado al arreglo)
            */
            float arr[100];
            int cantidad;
            cantidad = devolverArr2(arr, 100);
            mostrarArr2(arr, cantidad);
            float suma = sumarArr2(arr, cantidad);
            printf("La suma de los elementos es: %.2f\n", suma);

            break;
        }
        case 6 :
        {
            char arr [10];
            int cantidad = devolverArrChar(arr,5);
            printf("Se ingresaron %d elementos.\n", cantidad);
            mostrarArrChar(arr,cantidad);
            char elemento= 'e';
            //printf("Ingrese el elemento a buscar: ");
            // scanf(" %c", &elemento);
            // getchar();
            elementoExiste(arr, cantidad, elemento);
            break;
        }
        case 12:
        {
            /*
            12. Dados dos arreglos ordenados alfabéticamente, crear un tercer arreglo con los elementos de
            los dos primeros intercalados, de manera que quede un arreglo también ordenado
            alfabéticamente.
            */
            int arrA[] = {1, 3, 5, 9, 10};
            int arrB[] = {2, 4, 6, 11, 14, 22, 35};

            int sizeA = sizeof(arrA) / sizeof(arrA[0]);
            int sizeB = sizeof(arrB) / sizeof(arrB[0]);
            int arrC [100];
            fusionarArreglos(arrA, sizeA, arrB, sizeB, arrC);

            // Imprimir el resultado
            printf("Arreglo intercalado y ordenado: ");
            for (int i = 0; i < sizeA + sizeB; i++)
            {
                printf("%d ", arrC[i]);
            }
            break;
        }
        default :
        {
            printf("Ingrese un valor valido\n");
        }
        }
        printf("Quiere seguir? Ingrese 's' para continuar o cualquier otra tecla para salir: ");
        scanf(" %c", &control);
    }
}




