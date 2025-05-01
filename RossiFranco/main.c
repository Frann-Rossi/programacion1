#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "pila.h"

void crearArr(int arr[],int validos)
{
    for(int i = 0; i < validos ; i++)
    {
        arr[i] =rand() % 11;
        printf("|%d|\n",arr[i]);
    }

}

/**Ej 1**/
void  cargarPila (Pila* pila)
{
    int control = 1;
    while(control)
    {
        leer(pila);
        leer(pila);
        printf("Desea continuar ingrese 1 sino 0 para salir\n");
        scanf("%d",&control);
    }
    mostrar(pila);
}

/**Ej 2**/
void copiarMultiplosDeCinco (Pila pila,int arr[])
{
    int contador = 0;
    while(!pilavacia(&pila))
    {
        int numero = desapilar(&pila);
        if(numero % 5 == 0)
        {
            arr[contador] = numero;
            contador++;
        }

    }
    for(int i = 0; i < contador ; i++)
    {
        printf("Los numero Multiplos de 5 son |%d|\n", arr[i]);
    }
}

/**Ej 3**/
int menorElemento(int arr[], int validos)
{
    int menorNumero = arr[0];
    int posicion = 0;
    for(int i =0; i < validos; i++)
    {
        if(arr[i] < menorNumero)
        {
            menorNumero = arr[i];
            posicion = i;
        }
    }
    return posicion;
}

/**Ej 4**/
const int filas = 3;
const int columnas = 3;
void cargarMatriz (int matriz[filas][columnas])
{
    for(int f = 0; f < filas; f++)
    {
        for(int c = 0; c < columnas; c++)
        {
            matriz[f][c] = rand() % 10;
        }
    }
}
void mostrarMatriz(int matriz[filas][columnas])
{
    for(int f = 0; f < filas; f++)
    {
        for(int c = 0; c < columnas; c++)
        {
            printf("|%d|", matriz[f][c]);
        }
        printf("\n");
    }
}

/**Ej 5**/
int posicionArreglo (int arr[], int validos)
{
    int posicion = 0;
    do
    {
        printf("Ingrese un numero\n");
        scanf("%d",&posicion);
        if (posicion < 0)
            printf("\nError: Posición negativa\n");
        else if (posicion >= validos)
            printf("\nError: Posición mayor al rango\n");
    }
    while(posicion < 0 || posicion >= validos);
    return posicion;
}
void mostrarPosicion(int arr[],int validos)
{
    int posicion = posicionArreglo(arr,validos);
    printf("El valor en esa posicion es: %d\n",arr[posicion]);
}
/**Ej 6**/
int devolverMenor(Pila* pila)
{
    Pila aux;
    inicpila(&aux);
    int numeroMenor = tope(pila);
    while(!pilavacia(pila))
    {
        if(numeroMenor < tope(pila))
        {
            apilar(&aux,desapilar(pila));
        }
        else
        {
            numeroMenor = tope(pila);
            apilar(&aux,desapilar(pila));
        }
    }
    while(!pilavacia(&aux))
    {
        if(numeroMenor == tope(&aux))
        {
            desapilar(&aux);
        }
        else
            apilar(pila, desapilar(&aux));
    }
    return numeroMenor;
}
void ordenamientoPorSeleccion (Pila* pila, Pila* pilaOrdenada)
{
    while(!pilavacia(pila))
    {
        int numeroMenor = devolverMenor(pila);
        apilar(pilaOrdenada, numeroMenor);
    }
    mostrar(pilaOrdenada);
}
/**Ej 7**/
int sumarMatriz (int matriz[filas][columnas])
{
    int contadorSuma = 0;

    for(int f = 0; f < filas; f++)
    {
        for(int c = 0; c < columnas; c++)
        {
            contadorSuma += matriz[f][c];
        }
    }
    return contadorSuma;
}
float promedioMatriz (int matriz[filas][columnas])
{
    float promedio = (float)sumarMatriz(matriz) / (filas * columnas);
    return promedio;
}

/**Ej 8**/
const int dimFilas = 5;
const int dimColumnas = 10;
int cargarPalabrasMatriz (char matrizPalabra[dimFilas][dimColumnas])
{
    int seguir = 1;
    int cont = 0;

    while(seguir && cont < dimFilas)
    {

        printf("Ingrese una frase\n");
        fflush(stdin);
        scanf("%s",&matrizPalabra[cont]);
        printf("Quiere seguir ingrese 1 sino 0 para salir:\n");
        scanf("%d", &seguir);
        cont ++;
    }

    return cont;
}

void mostrarPalabraMatriz(char matrizPalabra[dimFilas][dimColumnas], int validos)
{
    for(int i = 0; i < validos; i++)
    {
        printf("Las palbras cargadas son:%s\n",matrizPalabra[i]);
    }
}

/**Ej 9**/
int coincidenciaMatriz(char palabraBuscar[dimColumnas],char arrayPalabra2[dimFilas][dimColumnas],int validos)
{
    int palabrasRepetidas = 0;
    for(int i = 0; i < validos; i++)
    {
        if( strcmp(palabraBuscar,arrayPalabra2[i])==0)
        {
            palabrasRepetidas++;
        }
    }
    return palabrasRepetidas;

}



int totalCoincidencia(char arrPalabra[dimFilas][dimColumnas], char arrayPalabra2[dimFilas][dimColumnas], int validos, int validos2)
{
    int cont = 0;

    for(int i = 0; i < validos; i++)
    {
        cont += coincidenciaMatriz(arrPalabra[i],arrayPalabra2,validos2);
    }
    return cont;
}
int main()
{
    Pila pila;
    Pila pilaOrdenada;
    inicpila(&pila);
    inicpila(&pilaOrdenada);
    int arr [20];
    int matriz[filas][columnas];
    char matrizPalabra[dimFilas][dimColumnas];
    char matrizPalabra2[dimFilas][dimColumnas];
    int res, res2 = 0;

    srand(time(NULL));
    char control = 's';
    int opcion = 0;

    while(control == 's')
    {
        printf("Ingrese un Numero para el ejercicio\n");
        printf("Ejercicio 1\n");
        printf("Ejercicio 2\n");
        printf("Ejercicio 3\n");
        printf("Ejercicio 4\n");
        printf("Ejercicio 5\n");
        printf("Ejercicio 6\n");
        printf("Ejercicio 7\n");
        printf("Ejercicio 8\n");
        printf("Ejercicio 9\n");
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
        {
            cargarPila(&pila);
            break;
        }
        case 2:
        {

            copiarMultiplosDeCinco(pila, arr);
            break;
        }

        case 3:
        {

            crearArr(arr,5);
            int pos = menorElemento(arr,5);
            printf("El numero %d se encuentra en la posicion %d\n",arr[pos],pos);
            break;
        }
        case 4:
        {

            cargarMatriz(matriz);
            mostrarMatriz(matriz);
            break;
        }
        case 5:
        {
            crearArr(arr, 5);
            mostrarPosicion(arr, 5);
            break;
        }
        case 6:
        {
            mostrar(&pila);
            ordenamientoPorSeleccion(&pila, &pilaOrdenada);
            break;
        }
        case 7:
        {
            float promedio = promedioMatriz(matriz);
            printf("El promedio es: %2.f\n", promedio);
            break;
        }
        case 8:
        {
            res = cargarPalabrasMatriz(matrizPalabra);
            mostrarPalabraMatriz(matrizPalabra, res);
            res2 = cargarPalabrasMatriz(matrizPalabra2);
            mostrarPalabraMatriz(matrizPalabra2, res2);
            break;
        }
        case 9:
        {
            int respuesta = totalCoincidencia(matrizPalabra,matrizPalabra2, res,res2);
            printf("Total de coincidencia es: %d",respuesta);
            break;
        }
        default:
        {
            printf("Valor invalido ingrese un valor correcto\n");
        }
        }
        printf("Desea continuar ingrese 's' sino 'n' para salir\n");
        scanf(" %c",&control);
    }

    return 0;
}
