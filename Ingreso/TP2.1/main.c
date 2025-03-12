#include <stdio.h>
#include <stdlib.h>
#include "pila.h".

int main()
{
     srand(time(NULL));

    /*

18.- Dada una pila DADA, calcular la suma de todos sus elementos sin utilizar variables acumuladoras.

19.- Dada una pila con números enteros, encontrar el valor máximo y mínimo usando solo pilas auxiliares.

20.- Dada una pila DADA, intercalar sus elementos en dos pilas AUX1 y AUX2 de forma alternada (el primer elemento en AUX1, el segundo en AUX2, el tercero en AUX1, etc.).

21.- Dada una pila DADA, eliminar los valores mayores a un número X ingresado por el usuario.

22.- Crear un procedimiento que reciba dos pilas A y B y devuelva una pila C con la combinación ordenada de ambas sin modificar A ni B.

23.- Implementar una función que compare dos pilas y determine si son espejadas (es decir, si una es la inversa de la otra).

24.- Dada una pila DADA, contar cuántos elementos tiene sin utilizar una variable contadora.

Estos ejercicios van aumentando en dificultad y te ayudarán a mejorar el manejo de pilas. ¿Te gustaría que te guíe con alguno en particular?
    */


    /*
         15.- Cargar una pila DADA con valores ingresados por el usuario.
            Luego, eliminar todos los elementos duplicados dentro de la pila, dejando solo una ocurrencia de cada número.
    Pila DADA, AUX, TEMP;
    inicpila(&DADA);
    inicpila(&AUX);
    inicpila(&TEMP);

    int i = 1;

    while(i == 1){
        leer(&DADA);
        printf("Quiere seguir apriete 1 sino cualquier otro numero para salir \n");
        scanf("%i",&i);
    }
    mostrar(&DADA);



    while(!pilavacia(&DADA)){
        int contenedor = desapilar(&DADA);
        int repetido = 0;

        while(!pilavacia(&AUX)){
            int auxElemento = desapilar(&AUX);
            if(auxElemento == contenedor){
                repetido = 1;
            }
            apilar(&TEMP,auxElemento);
        }

          while (!pilavacia(&TEMP)) {
        apilar(&AUX, desapilar(&TEMP));
    }

      if (!repetido) {
        apilar(&AUX, contenedor);
    }
    }
    mostrar(&AUX);
    */

    /*
        16.- Dada una pila DADA, dividirla en dos pilas PARES e IMPARES según los valores que contenga.

    Pila DADA, PARES, IMPARES;
    inicpila(&DADA);
    inicpila(&PARES);
    inicpila(&IMPARES);

    for(int i = 0; i < 5; i++){
        apilar(&DADA, rand() %5 +1);
    }
    mostrar(&DADA);

    while(!pilavacia(&DADA)){
        int contenedor = desapilar(&DADA);
        if(contenedor %2 == 0){
            apilar(&PARES, contenedor);
        }else{
             apilar(&IMPARES, contenedor);
        }
    }

    mostrar(&PARES);
    mostrar(&IMPARES);
    */

    /*
        17.- Dada una pila DADA, verificar si está ordenada de forma ascendente (de menor a mayor).
    */

    Pila DADA;

    inicpila(&DADA);

    int i = 1;

       while(i == 1) {
        leer(&DADA);
        printf("Para continuar ingrese 1, sino cualquier otro numero para salir: \n");
        scanf("%i", &i);
    }
    mostrar(&DADA);

     if (!pilavacia(&DADA)) {
        int topeSiguiente = desapilar(&DADA);  // Saco el primer elemento
        int ordenado = 1;  // Bandera: 1 = ordenado, 0 = desordenado

        while(!pilavacia(&DADA)) {
            int topeActual = desapilar(&DADA);

            if(topeActual > topeSiguiente) {
                ordenado = 0;  // Encontré un número desordenado
            }

            topeSiguiente = topeActual;  // Actualizo el tope para la siguiente comparación
        }

        if(ordenado) {
            printf("La pila está ordenada de forma ascendente.\n");
        } else {
            printf("La pila NO está ordenada de forma ascendente.\n");
        }
    }

    return 0;
}
