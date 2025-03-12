#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pila.h"

int main() {
    srand(time(NULL));

    int opcion = 0;
    char control = 's';

    while (control == 's') {
        printf("1 - Ej 1\n");
        printf("2 - Ej 2\n");
        printf("3 - Ej 3\n");
        printf("4 - Ej 4\n");
        printf("5 - Ej 5\n");
        printf("6 - Ej 6\n");
        printf("7 - Ej 7\n");
        printf("8 - Ej 8\n");
        printf("9 - Ej 9\n");
        printf("10 - Ej 10\n");
        printf("11 - Ej 11\n");
        printf("12 - Ej 12\n");
        printf("13 - Ej 13\n");
        printf("14 - Ej 14\n");
        printf("Ingrese el número del ejercicio que desea ejecutar: ");
        scanf("%d", &opcion);  // Leer opción del usuario

        switch (opcion) {
            case 1: {
                /*
                1.- Cargar desde el teclado una pila llamada DADA con 5 elementos. Pasar los tres
                primeros elementos que se encuentren en el tope a la pila AUX1 y los restantes a la
                pila AUX2, ambas pilas inicializadas.
                */
                Pila dada, aux1, aux2;
                inicpila(&dada);
                inicpila(&aux1);
                inicpila(&aux2);

                leer(&dada);
                leer(&dada);
                leer(&dada);
                leer(&dada);
                leer(&dada);

                apilar(&aux1, desapilar(&dada));
                apilar(&aux1, desapilar(&dada));
                apilar(&aux1, desapilar(&dada));
                apilar(&aux2, desapilar(&dada));
                apilar(&aux2, desapilar(&dada));

                mostrar(&dada);
                mostrar(&aux1);
                mostrar(&aux2);
                break;
            }
            case 2: {
                /*
                2.- Cargar desde el teclado una pila llamada ORIGEN e inicializar en vacío la pila
                DESTINO. Pasar todos los elementos de la pila ORIGEN a la pila DESTINO
                */
                Pila ORIGEN, DESTINO;
                inicpila(&ORIGEN);
                inicpila(&DESTINO);

                int continuar = 1;  // Bandera para seguir cargando valores
                while (continuar == 1) {
                    leer(&ORIGEN);  // Cargar un valor en ORIGEN
                    printf("¿Quiere seguir cargando valores? (1: Sí, 0: No): ");
                    scanf("%d", &continuar);
                }

                // Pasar elementos de ORIGEN a DESTINO
                while (!pilavacia(&ORIGEN)) {
                    apilar(&DESTINO, desapilar(&ORIGEN));
                }

                // Mostrar la pila DESTINO
                printf("Pila DESTINO después de la transferencia:\n");
                mostrar(&DESTINO);
                break;
            }
            case 3: {
                /*
                3.- Cargar desde teclado una pila DADA y pasar a la pila DISTINTOS todos aquellos
                elementos distintos al valor 8.
                */
                Pila DADA, DISTINTOS, AUXILIAR;
                inicpila(&DADA);
                inicpila(&DISTINTOS);
                inicpila(&AUXILIAR);

                int contador = 1;
                while (contador == 1) {
                    leer(&DADA);
                    printf("¿Quiere seguir cargando valores? (1: Sí, 0: No): ");
                    scanf("%d", &contador);
                }

                // Pasar los valores mientras reconstruimos DADA con solo los 8
                while (!pilavacia(&DADA)) {
                    int valor = desapilar(&DADA);
                    if (valor != 8) {
                        apilar(&DISTINTOS, valor);  // Los valores distintos de 8 van a DISTINTOS
                    } else {
                        apilar(&AUXILIAR, valor);   // Solo los 8 se guardan en AUXILIAR
                    }
                }

                // AUXILIAR ahora es la nueva DADA (contiene solo los 8)
                DADA = AUXILIAR;

                // Mostrar ambas pilas
                printf("Pila DISTINTOS después de la transferencia:\n");
                mostrar(&DISTINTOS);
                printf("Pila DADA después de la transferencia (debe contener solo los 8):\n");
                mostrar(&DADA);
                break;
            }
            case 4: {
                /*
                4.- Cargar desde el teclado la pila ORIGEN e inicializar en vacío la pila DESTINO.
                Pasar los elementos de la pila ORIGEN a la pila DESTINO, pero dejándolos en el
                mismo orden.
                */
                Pila ORIGEN, AUXILIAR, DESTINO;
                inicpila(&ORIGEN);
                inicpila(&AUXILIAR);
                inicpila(&DESTINO);

                // Paso 1: Pasamos ORIGEN a AUXILIAR para no modificar ORIGEN directamente
                while (!pilavacia(&ORIGEN)) {
                    apilar(&AUXILIAR, desapilar(&ORIGEN));
                }

                // Paso 2: Pasamos AUXILIAR a ORIGEN y DESTINO, manteniendo el orden original
                while (!pilavacia(&AUXILIAR)) {
                    int valor = desapilar(&AUXILIAR);
                    apilar(&ORIGEN, valor);
                    apilar(&DESTINO, valor);
                }

                // Mostrar ambas pilas
                printf("Pila ORIGEN después de la transferencia:\n");
                mostrar(&ORIGEN);
                printf("Pila DESTINO después de la transferencia (mismo orden que ORIGEN):\n");
                mostrar(&DESTINO);
                break;
            }
            case 5: {
                /*
                5.- Cargar desde el teclado la pila DADA. Invertir la pila de manera que DADA
                contenga los elementos cargados originalmente en ella, pero en orden inverso.
                */
                Pila dada, auxUno, auxDos;
                inicpila(&dada);
                inicpila(&auxUno);
                inicpila(&auxDos);
                int seguir = 1;
                int contador = 0;

                while (seguir) {
                    leer(&dada);
                    printf("¿Quiere seguir? 1(Si) - 0(No): ");
                    scanf("%i", &seguir);
                    contador++;
                }

                mostrar(&dada);

                for (int i = 0; i < contador; i++) {
                    apilar(&auxUno, desapilar(&dada));
                }

                for (int i = 0; i < contador; i++) {
                    apilar(&auxDos, desapilar(&auxUno));
                }

                for (int i = 0; i < contador; i++) {
                    apilar(&dada, desapilar(&auxDos));
                }

                mostrar(&dada);
                break;
            }
            case 6: {
                /*
                6.- Pasar el primer elemento (tope) de la pila DADA a su última posición (base),
                dejando los restantes elementos en el mismo orden.
                */
                Pila dada, auxUno;
                int seguir = 1;
                int nuevaBase;
                int contador = 0;

                inicpila(&dada);
                inicpila(&auxUno);

                while (seguir) {
                    leer(&dada);
                    printf("¿Quiere seguir? 1 (Si) - 0 (No): ");
                    scanf("%i", &seguir);
                    contador++;
                }

                mostrar(&dada);

                nuevaBase = desapilar(&dada);

                for (int i = 0; i < contador - 1; i++) {
                    apilar(&auxUno, desapilar(&dada));
                }

                apilar(&dada, nuevaBase);

                for (int i = 0; i < contador - 1; i++) {
                    apilar(&dada, desapilar(&auxUno));
                }

                mostrar(&dada);
                break;
            }
            case 7: {
                /*
                7.- Pasar el último elemento (base) de la pila DADA a su primera posición (tope),
                dejando los restantes elementos en el mismo orden.
                */
                Pila dada;
                int seguir = 1;
                int nuevoTope;
                int contador = 0;

                inicpila(&dada);

                printf("Ingrese un valor entero: ");
                scanf("%i", &nuevoTope);
                printf("¿Quiere seguir? 1 (Si) - 0 (No): ");
                scanf("%i", &seguir);

                while (seguir) {
                    leer(&dada);
                    printf("¿Quiere seguir? 1 (Si) - 0 (No): ");
                    scanf("%i", &seguir);
                    contador++;
                }

                apilar(&dada, nuevoTope);

                mostrar(&dada);
                break;
            }
            case 8: {
                /*
                8.- Repartir los elementos de la pila MAZO en las pilas JUGADOR1 y JUGADOR2
                en forma alternativa.
                */
                Pila mazo, jugUno, jugDos;
                inicpila(&mazo);
                inicpila(&jugUno);
                inicpila(&jugDos);

                for (int i = 0; i < 10; i++) {
                    apilar(&mazo, rand() % 10 + 1);
                }

                mostrar(&mazo);

                for (int i = 0; i < 5; i++) {
                    apilar(&jugUno, desapilar(&mazo));
                    apilar(&jugDos, desapilar(&mazo));
                }

                printf("Cartas del jugador Uno: \n");
                mostrar(&jugUno);

                printf("Cartas del jugador Dos: \n");
                mostrar(&jugDos);
                break;
            }
            case 9: {
                /*
                9.- Comparar la cantidad de elementos de las pilas A y B. Mostrar por pantalla el
                resultado. Recordar no utilizar para la resolución de los ejercicios variables
                que funcionen como contadores o acumuladores. La problemática debe
                resolverse aplicando pensamiento lógico.
                */
                Pila a, b, auxA, auxB;
                inicpila(&a);
                inicpila(&b);
                inicpila(&auxA);
                inicpila(&auxB);

                int seguirA = 1;
                int seguirB = 1;

                // Cargar la pila A
                printf("Ingrese los numeros de A: \n");
                while (seguirA) {
                    leer(&a);
                    printf("¿Quiere seguir? 1 (Si) - 0 (No): ");
                    scanf("%i", &seguirA);
                }

                // Cargar la pila B
                printf("Ingrese los numeros de B: \n");
                while (seguirB) {
                    leer(&b);
                    printf("¿Quiere seguir? 1 (Si) - 0 (No): ");
                    scanf("%i", &seguirB);
                }

                // Mostrar pilas iniciales
                printf("\nPila A:\n");
                mostrar(&a);

                printf("\nPila B:\n");
                mostrar(&b);

                // Comparar cantidad de elementos sin contadores
                while (!pilavacia(&a) && !pilavacia(&b)) {
                    apilar(&auxA, desapilar(&a));
                    apilar(&auxB, desapilar(&b));
                }

                // Verificar cuál tiene más elementos
                if (pilavacia(&a) && pilavacia(&b)) {
                    printf("Las pilas tienen la MISMA cantidad de elementos.\n");
                } else if (!pilavacia(&a)) {
                    printf("La pila A tiene MÁS elementos que B.\n");
                } else {
                    printf("La pila B tiene MÁS elementos que A.\n");
                }
                break;
            }
            case 10: {
                /*
                10.- Cargar las pilas A y B y luego compararlas, evaluando si son completamente
                iguales (en cantidad de elementos, valores que contienen y posición de los mismos).
                Mostrar por pantalla el resultado. Recordar no utilizar para la resolución de los
                ejercicios variables que funcionen como contadores o acumuladores. La
                problemática debe resolverse aplicando pensamiento lógico.
                */
                Pila a, b;
                inicpila(&a);
                inicpila(&b);

                int seguirA = 1;
                int seguirB = 1;

                // Cargar la pila A
                printf("Ingrese los numeros de A:\n");
                while (seguirA) {
                    leer(&a);
                    printf("¿Quiere seguir? 1 (Si) - 0 (No): ");
                    scanf("%d", &seguirA);
                }

                // Cargar la pila B
                printf("Ingrese los numeros de B:\n");
                while (seguirB) {
                    leer(&b);
                    printf("¿Quiere seguir? 1 (Si) - 0 (No): ");
                    scanf("%d", &seguirB);
                }

                // Comparar las pilas
                int sonIguales = 1; // Asumimos que las pilas son iguales al inicio

                while (!pilavacia(&a) && !pilavacia(&b)) {
                    int elemA = desapilar(&a);
                    int elemB = desapilar(&b);

                    if (elemA != elemB) {
                        sonIguales = 0; // Las pilas no son iguales
                        break; // Salimos del bucle
                    }
                }

                // Si una pila tiene más elementos que la otra, no son iguales
                if (!pilavacia(&a) || !pilavacia(&b)) {
                    sonIguales = 0;
                }

                // Mostrar el resultado
                if (sonIguales) {
                    printf("Las pilas A y B son completamente iguales.\n");
                } else {
                    printf("Las pilas A y B NO son iguales.\n");
                }
                break;
            }
            case 11: {
                /*
                11.- Suponiendo la existencia de una pila MODELO que no esté vacía, eliminar de la
                pila DADA todos los elementos que sean iguales al TOPE de la pila MODELO.
                */
                Pila MODELO, DADA, AUX;
                inicpila(&MODELO);
                inicpila(&DADA);
                inicpila(&AUX);

                // Cargar la pila MODELO con valores aleatorios
                for (int i = 0; i < 5; i++) {
                    apilar(&MODELO, rand() % 5 + 1); // Rango de 1 a 5
                }

                // Mostrar la pila MODELO
                printf("Pila MODELO:\n");
                mostrar(&MODELO);

                // Cargar la pila DADA con valores aleatorios
                for (int i = 0; i < 5; i++) {
                    apilar(&DADA, rand() % 5 + 1); // Rango de 1 a 5
                }

                // Mostrar la pila DADA antes de eliminar elementos
                printf("Pila DADA:\n");
                mostrar(&DADA);

                // Obtener el TOPE de la pila MODELO
                int topeModelo = tope(&MODELO);
                printf("El TOPE de la pila MODELO es: %d\n", topeModelo);

                // Eliminar de DADA los elementos iguales al TOPE de MODELO
                while (!pilavacia(&DADA)) {
                    int elemento = desapilar(&DADA); // Desapilar un elemento de DADA

                    if (elemento != topeModelo) {
                        apilar(&AUX, elemento); // Si no es igual, lo guardamos en la pila AUX
                    }
                }

                // Reconstruir la pila DADA con los elementos de AUX
                while (!pilavacia(&AUX)) {
                    apilar(&DADA, desapilar(&AUX));
                }

                // Mostrar la pila DADA después de eliminar elementos
                printf("Pila DADA después de eliminar elementos iguales al TOPE de MODELO:\n");
                mostrar(&DADA);
                break;
            }
            case 12: {
                /*
                12.- Suponiendo la existencia de una pila MODELO (vacía o no), eliminar de la pila
                DADA todos los elementos que existan en la pila MODELO.
                */
                Pila MODELO, DADA, AUX;
                inicpila(&MODELO);
                inicpila(&DADA);
                inicpila(&AUX);

                // Llenar MODELO con algunos valores
                for (int i = 1; i <= 5; i++) {
                    apilar(&MODELO, rand() % 5 + 1);
                }

                printf("MODELO:\n");
                mostrar(&MODELO);

                // Llenar DADA con algunos valores
                for (int i = 1; i <= 5; i++) {
                    apilar(&DADA, rand() % 5 + 1);
                }

                printf("DADA:\n");
                mostrar(&DADA);

                // Recorrer DADA y comparar con MODELO
                while (!pilavacia(&DADA)) {
                    int contenedorDada = desapilar(&DADA);  // Desapilamos un valor de DADA
                    int encontrado = 0;  // Variable que indica si encontramos el valor en MODELO

                    // Creamos una pila auxiliar para recorrer MODELO sin modificarla
                    Pila auxModelo;
                    inicpila(&auxModelo);

                    // Recorrer MODELO para ver si el valor está allí
                    while (!pilavacia(&MODELO)) {
                        int contenedorModelo = desapilar(&MODELO);
                        apilar(&auxModelo, contenedorModelo);  // Guardamos en auxModelo

                        if (contenedorDada == contenedorModelo) {
                            encontrado = 1;  // Lo encontramos en MODELO, no lo agregamos a AUX
                            break;
                        }
                    }

                    // Si no lo encontramos, lo apilamos en AUX
                    if (!encontrado) {
                        apilar(&AUX, contenedorDada);
                    }

                    // Restaurar MODELO
                    while (!pilavacia(&auxModelo)) {
                        apilar(&MODELO, desapilar(&auxModelo));  // Restauramos los valores en MODELO
                    }
                }

                // Mostrar el resultado
                printf("DADA después de eliminar los elementos que estaban en MODELO:\n");
                mostrar(&DADA);

                printf("AUX (conteniendo elementos no encontrados en MODELO):\n");
                mostrar(&AUX);
                break;
            }
            case 13: {
                /*
                13.- Suponiendo la existencia de una pila LÍMITE, pasar los elementos de la pila
                DADA que sean mayores o iguales que el tope de LIMITE a la pila MAYORES, y los
                elementos que sean menores a la pila MENORES.
                */
                Pila LIMITE, DADA, MAYORES, MENORES;
                inicpila(&LIMITE);
                inicpila(&DADA);
                inicpila(&MAYORES);
                inicpila(&MENORES);

                for (int i = 0; i < 3; i++) {
                    apilar(&LIMITE, rand() % 5 + 1);
                }
                printf("Limite:");
                mostrar(&LIMITE);
                int topeLimite = tope(&LIMITE);

                for (int i = 0; i < 5; i++) {
                    apilar(&DADA, rand() % 5 + 1);
                }
                printf("Dada:");
                mostrar(&DADA);

                while (!pilavacia(&DADA)) {
                    int contenedorDada = desapilar(&DADA);

                    if (contenedorDada >= topeLimite) {
                        apilar(&MAYORES, contenedorDada);
                    } else {
                        apilar(&MENORES, contenedorDada);
                    }
                }
                printf("Mayores:");
                mostrar(&MAYORES);
                printf("Menores:");
                mostrar(&MENORES);
                break;
            }
            case 14: {
                /*
                14.- Determinar si la cantidad de elementos de la pila DADA es par. Si es par, pasar
                el elemento del tope de la pila DADA a la pila PAR y si es impar pasar el tope a la
                pila IMPAR (el ejercicio debe ser realizado SIN contar los elementos)
                */
                Pila DADA, PAR, IMPAR, AUX;
                inicpila(&DADA);
                inicpila(&PAR);
                inicpila(&IMPAR);
                inicpila(&AUX);

                for (int i = 1; i <= 5; i++) {
                    apilar(&DADA, rand() % 5 + 1);
                }
                mostrar(&DADA);

                while (!pilavacia(&DADA)) {
                    int contenedorDada = desapilar(&DADA);
                    apilar(&AUX, contenedorDada);
                }

                int topeAux = tope(&AUX);

                if (topeAux % 2 == 0) {
                    apilar(&PAR, topeAux);
                } else {
                    apilar(&IMPAR, topeAux);
                }

                printf("PAR:");
                mostrar(&PAR);
                printf("IMPAR:");
                mostrar(&IMPAR);
                break;
            }
            default:
                printf("Ingrese un valor correcto\n");
        }

        printf("¿Quiere seguir? Ingrese 's' para continuar o cualquier otra tecla para salir: ");
        fflush(stdin);
        scanf(" %c", &control);
    }
    return 0;
}
