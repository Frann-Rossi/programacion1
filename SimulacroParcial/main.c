#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pila.h"

//Rossi Franco Matias
//Com 7

/*EJERCICIO 1*/
void cargarPila (Pila *dada)
{

    char control = 's';
    while(control == 's')
    {
        leer(dada);
        leer(dada);
        fflush(stdin);
        printf("Ingrese 's' si quiere continuar\n");
        scanf("%c",&control);
    }
    mostrar(dada);
}

/*EJERCICIO 2*/
void copiarElementos (Pila dada, int arr[])
{
    int cont = 0;
    while(!pilavacia(&dada))
    {
        if(tope(&dada) % 5 == 0)
        {
            arr[cont] = tope(&dada);
            cont++;
        }
        desapilar(&dada);
    }
}

/*EJERCICIO 3*/
int posicionMenor (int arr[], int elemento)
{
    int numMenor = arr[0];
    int pos = 0;
    for(int i = 0; i < elemento; i++)
    {
        if(arr[i] < numMenor)
        {
            numMenor = arr[i];
            pos = i;
        }
    }
    return pos;
}

/*EJERCICIO 4*/
const int filas = 3;
const int columnas = 3;
void cargarMatriz(int matriz[filas][columnas])
{
    int valor = 0;
    for(int f = 0; f < filas; f++)
    {
        for(int c = 0; c < columnas; c++)
        {
            printf("Cargue valores");
            scanf("%d",&valor);
            matriz[f][c] = valor;
        }
    }
}
void mostrarMatriz (int matriz[filas][columnas])
{
    for(int f = 0; f < filas; f++)
    {
        for(int c = 0; c < columnas; c++)
        {
            printf("|%i|",matriz[f][c]);

        }
        printf("\n");
    }
}

/*EJERCICIO 5*/
int pedirPosicion (int arr[],int validos)
{
    int pos = 0;
    do
    {
        printf("Ingrese una posicion:\n");
        scanf("%d",&pos);
        if(pos > validos || pos < 0)
        {
            printf("Error fuera de rango\n");
        }
    }
    while(pos > validos || pos < 0 );
    return pos;
}
void devolverPosicion (int arr[], int validos){
    int pos = pedirPosicion(arr,validos);
    printf("Su posicion es:%d\n",arr[pos]);
}

int main()
{
    int arr[5];
    pedirPosicion(arr,2);
    devolverPosicion(arr,2);

    return 0;
}
