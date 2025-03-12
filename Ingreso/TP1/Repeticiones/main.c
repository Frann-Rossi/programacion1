#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*
    11.- Calcular el promedio de un estudiante que tiene 7 calificaciones en la materia
    Programación A.
    */
    /*
    float nota;
    float notaFinal;

    printf("Escriba la nota del alumno: \n");
    for(int i = 1; i <= 7; i++){
        printf("Nota %i: ", i);
        scanf("%f",&nota);
        notaFinal += nota;
    }
    notaFinal = notaFinal / 7;
    printf("Promedio de nota: %2.f",notaFinal);
    */


    /*
        12.- Leer 10 números y obtener su cubo y su cuarta.
    */

    /*
    int numero;
    int cubo = 0;
    int cuarta = 0;

    printf("Escriba 10 numero:\n");

    for(int i = 1; i <= 10; i++){
        printf("Numero %d: ", i);
        scanf("%i", &numero);

        cubo = numero * numero * numero;
        cuarta = numero * numero * numero * numero;

        printf("Cubo de %i: %i\n", numero, cubo);
        printf("Cuarta de %i: %i\n", numero, cuarta);
    }
    */


    /*
          13.- Leer 10 números e imprimir solamente los positivos.
    */

    /*
    int num;

    printf("Escriba 10 numeros: \n");
    for(int i = 1; i <= 10; i++){
        scanf("%i",&num);
        if(num > 0){
            printf("Numero positivo: %i\n",num);
        }else{
            printf("Escriba otro numero\n");
        }
    }
    */

    /*
         14.- Leer 15 números, convertirlos en positivos e imprimirlos.
    */

    /*
    int num;

    printf("Escriba 15 numeros:\n");
    for(int i = 1; i <= 15; i++){
        scanf("%i",&num);
        num = abs(num);

         if (num < 0) {
            num = -num;  // Si es negativo, lo convertimos a positivo
        }
        printf("Numero: %i\n",num);
    }
    */

    /*

    15.- Suponga que se tiene un conjunto de calificaciones de un grupo de 40
    estudiantes. Realizar un algoritmo para calcular la calificación promedio y la
    calificación más baja de todo el grupo.s
    */

    /*
    int estudiantes = 10;
    float notas;
    float promedio = 0;
    float notaMasBaja;

    printf("Escriba las notas de los alumnos:\n");
    for(int i = 1; i <= estudiantes; i++){
        scanf("%f",&notas);
        promedio += notas;

        if(nota == 0){
            notaMasBaja = nota;
        }
        if(notas < notaMasBaja){
            notaMasBaja = notas;
        }
    }
        promedio = promedio / estudiantes;
        printf("El promedio de la clase es: %.2f\n", promedio);
        printf("La calificación más baja es: %.2f\n", notaMasBaja);
    */

    /*
    16.- Calcular e imprimir la tabla de multiplicar de un número cualquiera. Imprimir el
    multiplicando, el multiplicador y el producto.
    */
    int num;

    printf("Escriba el numero de la tabla que quiera:\n");
    scanf("%d", &num);
    for(int i = 0; i <= 10; i++){
        printf("%d x %d = %d\n", num, i, num * i);
    }
    return 0;
}
