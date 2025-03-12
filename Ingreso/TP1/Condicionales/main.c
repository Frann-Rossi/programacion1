#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    /*
    B) PROBLEMAS CONDICIONALES SELECTIVOS SIMPLES
    */

    /*
    4.- Determinar si un estudiante aprueba o reprueba un curso, sabiendo que
    aprobará si su promedio de tres calificaciones es mayor o igual a 7. Caso contrario
    reprueba.
    */
    /*
    char aprobado[] = "aprobado x Chayanne";
    char desaprobado[] = "desaprobado x Chayanne";
    float notaAlumno;


    printf("Nota Alumno: ");
    scanf("%f",&notaAlumno);

        if((notaAlumno >= 7) && (notaAlumno <= 10)) {
        printf("%s\n",aprobado);
    }
        else{
        printf("%s\n",desaprobado);
    }
    */

    /*

    5.- En un almacén se hace un 20% de descuento a los clientes cuya compra supere
    los $5.000. Se desea saber cuál será la cantidad que pagará una persona por su
    compra.
    */

    /*
    float compra;
    float compraSuperior = 5000;
    float descuento = 0.2;
    printf("Gasto el cliente: ");
    scanf("%f", &compra);


    if(compra >= compraSuperior){
        float total = compra - (compra * descuento);
        printf("El cliente debe pagar: %.2f",total);
    }else{
        printf("El cliente debe pagar: %.2f",compra);
    }
    */

    /*
        6.- Un obrero necesita calcular su salario semanal, el cual se obtiene de la siguiente
        manera: si trabaja 40 horas o menos se le paga $300 por hora, si trabaja más de 40
        horas se le paga $300 por cada una de las primeras 40 horas y $400 por cada hora
        extra.
    */

    /*
    int horaPaga = 300;
    int horaExtraPaga = 400;
    int horasTrabajadas;
    int total;
    printf("Horas trabajadas: ");
    scanf("%i",&horasTrabajadas);


    if(horasTrabajadas > 40 ){
        int horasExtras = horasTrabajadas - 40;
        total = ((40 * horaPaga) + (horasExtras * horaExtraPaga)) ;
        printf("Total a pagar: %i", total);
    }else{
        total = horasTrabajadas * horaPaga;
        printf("Total a pagar: $%i\n", total);
    }
    */

    /*
        7.- Desarrolle un algoritmo que lea dos números y los imprima en forma ascendente.
    */

    /*
    int num1 , num2;
    printf("Escriba 2 Numeros: \n");

    scanf("%i",&num1);
    scanf("%i",&num2);

     if (num1 < num2) {
        printf("Los numeros en orden ascendente son: %i, %i\n", num1, num2);
    } else {
        printf("Los numeros en orden ascendente son: %i, %i\n", num2, num1);
    };
    */

    /*
        8.- Hacer un algoritmo que calcule el total a pagar por la compra de camisas. Si se
        compran tres camisas o más se aplica un descuento del 20% sobre el total de la
        compra, y si son menos de tres camisas un descuento del 10%.


    float descuentoUno = 0.20;
    float descuentoDos = 0.10;
    int camisas;
    int valorCamisa = 100;
    float total;

    printf("Ingrese la cantidad de camisas que compro: ");
    scanf("%i", &camisas);

    if (camisas >= 3) {
        total = (valorCamisa * camisas) * (1 - descuentoUno);
    } else {
        total = (valorCamisa * camisas) * (1 - descuentoDos);
    }

    printf("El valor a pagar va ser de: $%.2f\n", total);
    */

    int num = 0;
    int esPrimo = 1;
    printf("Escriba un numero: \n");
    scanf("%i", &num);

    if(num <= 1){
        esPrimo = 0;
    }else{
          for(int i = 2; i <= sqrt(num); i++){
        if(num %i == 0){
            esPrimo = 0;
            break;
        }
    }
    }

      if (esPrimo) {
        printf("%i es primo.\n", num);
    } else {
        printf("%i no es primo.\n", num);
    }



    return 0;
}

