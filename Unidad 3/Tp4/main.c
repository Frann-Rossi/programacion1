#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int const columnas = 5;
int const filas = 5;
int const dimFila = 10;
const int dimPalabra = 20;
/*
1. Hacer una función que reciba como parámetro una matriz de números enteros
y permita que el usuario ingrese valores al mismo por teclado. La función
debe cargar la matriz por completo.
*/
void devuelveMatriz (int matrix[filas][columnas])
{
    for(int f = 0; f < filas; f++)
    {
        for(int c = 0; c < columnas; c++)
        {
            matrix[f][c] = rand()%100;
        }
    }
}
/*
2. Hacer una función que reciba como parámetro una matriz de números enteros
y la muestre por pantalla (en formato matricial).
*/
void mostrarMatriz (int matrix[filas][columnas])
{
    printf("Contenido de la matriz:\n");
    for(int f = 0; f < filas; f++)
    {
        for(int c = 0; c < columnas; c++)
        {
            printf("[%3d]", matrix[f][c]);
        }
        printf("\n");
    }
}
/*
4. Hacer una función tipo int que sume el contenido total de una matriz de
números enteros.
*/
int sumarMatriz(int matrix[filas][columnas])
{
    int suma = 0;
    for(int f = 0; f < filas; f++)
    {
        for(int c = 0; c < columnas; c++)
        {
            suma += matrix[f][c] ;
        }

    }
    return suma;
}

/*
5. Hacer una función tipo float que calcule el promedio de una matriz de
números enteros.
*/
float promedioMatriz (int matrix[filas][columnas])
{
    int suma = sumarMatriz(matrix);
    int totalElementos = filas * columnas;
    return (float)suma / totalElementos;
}
/*
6. Hacer una función que determine si un elemento se encuentra dentro de una
matriz de números enteros. La función recibe la matriz y el dato a buscar.
*/
int buscarNumMatriz (int matrix[filas][columnas],int dato)
{
    for(int f = 0; f < filas; f++)
    {
        for(int c = 0; c < columnas; c++)
        {
            if(matrix[f][c] == dato)
            {
                return 1;
            }
        }
    }
    return 0;
}
/*
7. Hacer una función que cargue un arreglo de palabras (strings). La función
debe retornar cuantas palabras se cargaron. (puede ser a través del
parámetro como puntero).
*/
int cargarStrings (char arrPalabras[][dimPalabra], int *dimFila)
{
    int i = 0;
    int continuar = 1;

    while(i < dimFila && continuar == 1)
    {
        printf("\nIngrese una palabra: \n");
        scanf("%s",arrPalabras[i]);

        i++;
        if (i < dimFila)
        {
            printf("¿Desea seguir ingresando palabras? (1: si / 0: no): ");
            scanf("%d", &continuar);
        }
    }
    return i;
}
/*8. Hacer una función que muestre un arreglo de palabras.*/

void mostrarString (char arrPalabras[][dimPalabra], int val)
{
    printf("\nPalabras ingresadas:\n");
    for(int i = 0; i < val ; i++)
    {
        printf("\n%s\n", arrPalabras[i]);
    }
}

/*
9. Hacer una función que determine si un string se encuentra dentro de un
arreglo de strings. La función recibe el arreglo, la cantidad de palabras que
contiene y la palabra a buscar. ///devuelve el índice de la fila en que se
encuentra, de lo contrario retorna -1
*/
int buscarStrMatriz (char arrPalabras[][dimPalabra],int cantidad,char buscada[dimPalabra])
{
    for(int i = 0; i < cantidad; i++)
    {
        if(strcmp(arrPalabras[i], buscada) == 0)
        {
            return i;
        }
    }
    return -1;
}

/*
10. Hacer una función que determine si un string se encuentra dentro de un
arreglo de strings ordenado alfabéticamente. La función recibe el arreglo, la
cantidad de palabras que contiene y el string a buscar. ///devuelve el índice
de la fila en que se encuentra, de lo contrario retorna -1
*/
int ordenadoStrMatriz (char arrPalabras[][dimPalabra],int cantidad,char buscada[dimPalabra])
{
    for(int i = 0; i < cantidad; i++)
    {
        int ordenado = buscarStrMatriz(arrPalabras, cantidad,buscada)

        if(strcmp(arrPalabras[i], ordenado) == 0)
        {

        }
    }

    return -1;
}

int main()
{
    char control = 's';
    int opcion = 0;
    int matriz [filas][columnas];
    srand(time(NULL));

    while(control == 's')
    {
        printf("Ingrese un Numero para seleccionar el ejercicio\n");
        printf("1: Cargar matriz con números aleatorios y mostrarla\n");
        printf("2: Cargar matriz y mostrar la suma de todos los elementos\n");
        printf("3: Cargar matriz, mostrarla y mostrar el promedio de sus elementos\n");
        printf("4: Cargar matriz, mostrarla y buscar un valor en ella\n");
        printf("5: Cargar palabras, mostrarlas y buscar\n");
        scanf(" %d",&opcion);
        switch(opcion)
        {
        case 1 :
        {
            devuelveMatriz(matriz);
            mostrarMatriz(matriz);
            break;
        }
        case 2 :
        {
            devuelveMatriz(matriz);
            int total = sumarMatriz(matriz);
            printf("La suma total de los elementos es: %d\n", total);
            break;
        }
        case 3 :
        {
            devuelveMatriz(matriz);
            mostrarMatriz(matriz);
            printf("Promedio: %.2f\n", promedioMatriz(matriz));
            break;
        }
        case 4 :
        {
            devuelveMatriz(matriz);
            mostrarMatriz(matriz);

            int valor;
            printf("Ingrese el valor a buscar: ");
            scanf("%d", &valor);

            if (buscarNumMatriz(matriz, valor))
            {
                printf("El valor %d SI se encuentra en la matriz.\n", valor);
            }
            else
            {
                printf("El valor %d NO está en la matriz.\n", valor);
            }
            break;
        }
        case 5:
        {
            char palabras[dimFila][dimPalabra];
            int cantidad = cargarStrings(palabras, dimFila);
            mostrarString(palabras, cantidad);

            char palabraABuscar[dimPalabra];
            printf("\nIngrese la palabra a buscar: ");
            scanf("%s", palabraABuscar);

            int indice = buscarStrMatriz(palabras, cantidad, palabraABuscar);

            if (indice != -1)
            {
                printf("La palabra '%s' se encuentra en la posicion %d.\n", palabraABuscar, indice);
            }
            else
            {
                printf("La palabra '%s' no se encontro en el arreglo.\n", palabraABuscar);
            }

            break;
        }
        default:
        {
            printf("Ingrese un valor valido\n");
        }
        }
        printf("Quiere continuar Ingrese s\n");
        scanf(" %c",&control);
    }
    return 0;
}
