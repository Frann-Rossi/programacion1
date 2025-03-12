#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
    srand(time(NULL));
    int opcion = 0;
    char control = 's';
    while (control == 's'){
        printf("1 - Ej 1\n");
        printf("2 - Ej 2\n");
        printf("3 - Ej 3\n");
        printf("4 - Ej 4\n");
        printf("5 - Ej 5\n");
        printf("6 - Ej 6\n");
        printf("7 - Ej 7\n");
        printf("8 - Ej 8\n");
        printf("9 - Ej 9\n");
        printf("Ingrese el numero del ejercicio que desea ejecutar: \n");
        scanf("%d", &opcion);  // Leer opci�n del usuario


        switch(opcion){
            case 1: {
                /*
                    1.- Sumar los elementos de una pila (usar variables enteras)
                */
                Pila DADA;
                inicpila(&DADA);

                for(int i = 0; i < 5;  i++){
                    apilar(&DADA, rand()%20 +1);
                }
                mostrar(&DADA);
                int dadaSuma = 0;

                while(!pilavacia(&DADA)){
                    dadaSuma += desapilar(&DADA);
                }
                printf("%i\n", dadaSuma);
                break;
            }
            case 2:{
                /*
                    2.- Contar los elementos de una pila (usar variables enteras)
                */
                Pila DADA;
                inicpila(&DADA);

                int i = 0;
                while (i < 5){
                    apilar(&DADA, rand()%20 + 1);
                    i++;
                }

                mostrar(&DADA);

                int contador = 0;
                while(!pilavacia(&DADA)){
                    desapilar(&DADA);
                    contador++;
                }
                printf("La cantidad de elementos en la pila es: %i \n", contador);
                break;
            }
            case 3:{
                /*
                    3.- Calcular el promedio de los valores de una pila (usar variables)
                */

                Pila PROMEDIO;
                inicpila(&PROMEDIO);

                int i = 0;
                while(i < 5){
                    apilar(&PROMEDIO, rand() % 20 + 1);
                    i++;
                }
                mostrar(&PROMEDIO);
                int sumPromedio = 0;
                int vueltas = 0;
                while(!pilavacia(&PROMEDIO)){
                    sumPromedio += desapilar(&PROMEDIO);
                    vueltas++;
                }
                float resultado = (float)sumPromedio / vueltas;
                printf("El promedio de la pila es: %.2f\n", resultado);
                break;
            }
            case 4:{
                /*
                    4.- Determinar si un elemento buscado está dentro de una pila. Al encontrarlo,
                        finalizar la búsqueda.
                */

                Pila BUSQUEDA;
                inicpila(&BUSQUEDA);

                for(int i = 0; i < 5; i++){
                    apilar(&BUSQUEDA, rand()%10 + 1);
                }
                mostrar(&BUSQUEDA);
                int elementoBuscado = 8;
                int encontrado  = 0;
                while(!pilavacia(&BUSQUEDA)){
                    int contenedorDesapilar = desapilar(&BUSQUEDA);
                    if(contenedorDesapilar == elementoBuscado){
                        printf("Elemento encontrado en la pila era: %i\n", elementoBuscado);
                        encontrado = 1;
                        break;
                    }
                }
                    if(!encontrado){
                        printf("Elemento %i no encontrado en la pila.\n", elementoBuscado);
                    }
                break;
            }
            case 5:{
                /*
                5.- Eliminar un elemento de una pila. Al eliminarlo, finalizar el recorrido y dejar el
                    resto de los elementos de la pila en el mismo orden.
                */

                Pila INICIO, AUX;
                inicpila(&INICIO);
                inicpila(&AUX);

                for(int i = 0; i < 5; i++){
                    apilar(&INICIO, rand()%10 + 1);
                }
                mostrar(&INICIO);

                int elemBuscado = 8;
                int encontrado = 0;
                while(!pilavacia(&INICIO)){
                    int contenedor = desapilar(&INICIO);
                    if(contenedor == elemBuscado && !encontrado){
                        encontrado = 1;
                        continue;
                    }
                    apilar(&AUX, contenedor);
                }
                mostrar(&AUX);
                while(!pilavacia(&AUX)){
                    apilar(&INICIO,desapilar(&AUX));
                }
                mostrar(&INICIO);

                break;
            }
            case 6:{
                /*
                    6.- Verificar si una pila DADA es capicúa.
                */
                Pila INICIO, AUX, TEMP;
                inicpila(&INICIO);
                inicpila(&AUX);
                inicpila(&TEMP);

                int contador = 0;
                int seguir = 1;
                while(seguir == 1){
                    leer(&INICIO);
                    printf("Quiere contiuar ingrese '1' o '0' para salir\n");
                    scanf("%i",&seguir);
                    contador++;
                }
                mostrar(&INICIO);

                while(!pilavacia(&INICIO)){
                    int valor = desapilar(&INICIO);
                    apilar(&AUX, valor);
                    apilar(&TEMP, valor);
                }

                while (!pilavacia(&TEMP)){
                    apilar(&INICIO,desapilar(&TEMP));
                }
                mostrar(&AUX);

                int esCapicua = 1;
                while(!pilavacia(&INICIO) && !pilavacia(&AUX)){
                    int valor1 = desapilar(&INICIO);
                    int valor2 = desapilar(&AUX);

                    if(valor1 != valor2){
                        esCapicua = 0;
                        break;
                    }
                }
                if(esCapicua){
                    printf("La pila es capicua.\n");
                }else{
                    printf("La pila no es capicua.\n");
                }
                break;
            }
            case 7:{
                /*
                    7.- Dadas dos pilas A y B que simulan conjuntos (cada conjunto no tiene elementos
                        repetidos sobre sí mismo), realizar un programa que calcule en la pila C la
                        operación de unión.
                */

            Pila a, b, c, aux;

            inicpila(&a);
            inicpila(&b);
            inicpila(&c);
            inicpila(&aux); // Pila auxiliar para evitar duplicados

            int seguir = 1;
            int numero;

            // Carga de la pila A sin repetir elementos
            while (seguir) {
                printf("Ingrese un numero entero para A: ");
                scanf("%i", &numero);
            // Verificar que no esté repetido en A
            int repetido = 0;
            while (!pilavacia(&a)) {
                if (tope(&a) == numero) {
                    repetido = 1;
            }
            apilar(&aux, desapilar(&a));
            }
            while (!pilavacia(&aux)) {
                apilar(&a, desapilar(&aux));
            }

            if (!repetido) {
                apilar(&a, numero);
            } else {
                printf("Ese valor ya está en la pila A\n");
            }

            printf("Quiere seguir agregando a A? 1 (Si) - 0 (No): ");
            scanf("%i", &seguir);
        }

    // Carga de la pila B sin repetir elementos
    seguir = 1;
    while (seguir) {
        printf("Ingrese un numero entero para B: ");
        scanf("%i", &numero);

        // Verificar que no esté repetido en B
        int repetido = 0;
        while (!pilavacia(&b)) {
            if (tope(&b) == numero) {
                repetido = 1;
            }
            apilar(&aux, desapilar(&b));
        }
        while (!pilavacia(&aux)) {
            apilar(&b, desapilar(&aux));
        }

        if (!repetido) {
            apilar(&b, numero);
        } else {
            printf("Ese valor ya está en la pila B\n");
        }

        printf("Quiere seguir agregando a B? 1 (Si) - 0 (No): ");
        scanf("%i", &seguir);
    }

    // Pasar todos los elementos de A a C
    while (!pilavacia(&a)) {
        apilar(&c, desapilar(&a));
    }

    // Pasar los elementos de B a C sin repetir valores
    while (!pilavacia(&b)) {
        int valor = desapilar(&b);
        int estaEnC = 0;

        // Verificar si el valor ya está en C
        while (!pilavacia(&c)) {
            if (tope(&c) == valor) {
                estaEnC = 1;
            }
            apilar(&aux, desapilar(&c));
        }
        while (!pilavacia(&aux)) {
            apilar(&c, desapilar(&aux));
        }

        // Si el valor no está en C, lo apilamos
        if (!estaEnC) {
            apilar(&c, valor);
        }
    }

    // Mostrar la pila C (unión de A y B)
    printf("La union de las pilas A y B es:\n");
    mostrar(&c);
                break;
            }
            case 8:{
                /*
                    8.- Intercalar dos pilas ordenadas en forma creciente (ORDENADA1 y
                        ORDENADA2) dejando el resultado en una pila también ordenada en forma
                        creciente (ORDENADAFINAL).
                */
                break;
            }
            case 9:{
                /*
                    9.- Suponer un juego de cartas en el que en cada mano se reparten dos cartas por
                        jugador. Un jugador gana la mano cuando la suma de sus cartas es mayor que las
                        del contrario y al hacerlo coloca todas las cartas (las de él y las de su rival) en su
                        pila de puntos. En caso de empate (y para simplificar) siempre gana el jugador1.
                        Simular la ejecución del juego de tal manera que dada una pila MAZO (con un
                        número de elementos múltiplo de cuatro) distribuya las cartas en las pilas
                        PUNTOSJUG1 y PUNTOSJUG2 como si estos hubieran jugado. Utilizar las pilas
                        auxiliares que crea conveniente.

                */
                break;
            }
            default:
                printf("Ingrese un valor valido\n");
        }
        printf("Quiere seguir? Ingrese 's' para continuar o cualquier otra tecla para salir: ");
        fflush(stdin);
        scanf("%c", &control);
    }
    return 0;
}
