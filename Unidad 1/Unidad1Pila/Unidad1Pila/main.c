#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pila.h"

int main()
{
    srand(time(NULL));
    int opcion = 0;
    char control = 's';
    while(control == 's')
    {
        printf("1 - Ej 1\n");
        printf("2 - Ej 2\n");
        printf("3 - Ej 3\n");
        printf("4 - Ej 4\n");
        printf("5 - Ej 5\n");
        printf("Ingrese el numero del ejercicio que desea ejecutar: \n");
        scanf("%d", &opcion);
        switch(opcion)
        {
        case 1:
        {
            /*
                1. Hacer una función que permita ingresar varios elementos a una pila, tanto como quiera el
                usuario
            */
            ingresarNum();
            break;
        }
        case 2:
        {
            /*
                2. Hacer una función que pase todos los elementos de una pila a otra
            */
            Pila dada, aux;
            inicpila(&dada);
            inicpila(&aux);
            for(int i = 0; i < 5; i++)
            {
                apilar(&dada, rand()%11);
            }
            printf("dada");
            mostrar(&dada);
            pasarElementos(&dada,&aux);
            break;
        }
        case 3:
        {
            /*
            3. Hacer una función que pase todos los elementos de una pila a otra, pero conservando el orden
            */
            Pila dada, aux, aux2;
            inicpila(&dada);
            inicpila(&aux);
            inicpila(&aux2);
            for(int i = 0; i < 5; i++)
            {
                apilar(&dada, rand()%11);
            }
            printf("dada:");
            mostrar(&dada);
            pasarElementos(&dada,&aux);
            pilaOrdenada(&aux,&aux2);
            break;
        }
        case 4:
        {
            /*
            4. Hacer una función que encuentre el menor elemento de una pila y lo retorna. La
            misma debe eliminar ese dato de la pila.
            */
            Pila dada, aux;
            inicpila(&dada);
            inicpila(&aux);
            for(int i = 0; i < 5; i++)
            {
                apilar(&dada, rand()%11);
            }
            printf("dada:\n");
            mostrar(&dada);

            int menor =  numeroMenor(&dada,&aux);
            mostrar(&aux);
            printf("El numero mas chico que se saco es %d\n",menor);
            break;
        }
        case 5 :
        {
            /*
                5. Hacer una función que pase los elementos de una pila a otra, de manera que se genere una
                nueva pila ordenada. Usar la función del ejercicio 4. (Ordenamiento por selección)
            */
            Pila dada, aux;
            inicpila(&dada);
            inicpila(&aux);
            for(int i = 0; i < 5; i++)
            {
                apilar(&dada, rand()%11);
            }
            printf("Pila dada:\n");
            mostrar(&dada);

            ordenada(&dada, &aux);
            break;
        }
        case 6:
        {
            /*
            6. Hacer una función que inserta en una pila ordenada un nuevo elemento, conservando el orden
            de ésta.
            */
            Pila dada, aux;
            inicpila(&dada);
            inicpila(&aux);
            for(int i = 0; i < 5; i++)
            {
                apilar(&dada, rand()%11);
            }
            ordenada(&dada, &aux);

            int nuevoElemento;
            printf("Ingrese un número para insertar en la pila ordenada: ");
            scanf("%d", &nuevoElemento);
            //tomarNum(&dada);

            insertarOrdenado(&dada, nuevoElemento);
            break;
        }
        default:
            printf("Ingrese un valor valido\n");
        }
        printf("Quiere seguir? Ingrese 's' para continuar o cualquier otra tecla para salir: ");
        scanf(" %c", &control);
    }
    return 0;
}

void ingresarNum ()
{
    Pila num;
    inicpila(&num);

    char control = 's';
    while (control == 's')
    {
        leer(&num);
        mostrar(&num);
        printf("Quiere seguir? Ingrese 's' para continuar o cualquier otra tecla para salir: ");
        scanf(" %c", &control);
    }
}

void pasarElementos(Pila *dada, Pila *aux)
{
    while(!pilavacia(dada))
    {
        int control = desapilar(dada);
        apilar(aux, control);
    }
    printf("aux");
    mostrar(aux);
}

void pilaOrdenada (Pila *aux, Pila *aux2)
{
    while(!pilavacia(aux))
    {
        int control = desapilar(aux);
        apilar(aux2, control);
    }
    printf("aux2");
    mostrar(aux2);
}

int numeroMenor (Pila *dada, Pila *aux)
{
    int menor = desapilar(dada);
    while(!pilavacia(dada))
    {
        int valor = desapilar(dada);
        if(valor < menor)
        {
            apilar(aux, menor);
            menor = valor;
        }
        else
        {
            apilar(aux, valor);
        }


    }

    return menor;
}

void ordenada (Pila *dada, Pila *aux)
{
    Pila ordenada;
    inicpila(&ordenada);
    while (!pilavacia(dada))
    {
        int menor = numeroMenor(dada, aux);
        apilar(&ordenada, menor);
        while (!pilavacia(aux))
        {
            apilar(dada, desapilar(aux));
        }
    }
    printf("Pila ordenada:\n");
    mostrar(&ordenada);

    while (!pilavacia(&ordenada))
    {
        apilar(dada, desapilar(&ordenada));
    }
}


void insertarOrdenado(Pila *dada, int nuevoElemento)
{
    Pila aux;
    inicpila(&aux);
    while (!pilavacia(dada) && tope(dada) < nuevoElemento)
    {
        apilar(&aux, desapilar(dada));
    }
    apilar(dada, nuevoElemento);
    while (!pilavacia(&aux))
    {
        apilar(dada, desapilar(&aux));
    }
    mostrar(dada);
}


void tomarNum(Pila *dada)
{
    char control = 's';
    int nuevoElemento;

    while (control == 's' || control == 'S')
    {
        // Solicitar el número al usuario
        printf("Ingrese un número para insertar en la pila ordenada: ");
        scanf("%d", &nuevoElemento);

        // Insertar el número en la pila ordenada
        insertarOrdenado(dada, nuevoElemento);

        // Preguntar si desea ingresar otro número
        printf("¿Desea ingresar otro número? (s/n): ");
        scanf(" %c", &control);  // Se agrega el espacio antes de %c para evitar problemas con el buffer
    }
}

