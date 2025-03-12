
#include <iostream>

using namespace std;

int main()
{
/*
    A) PROBLEMAS SECUENCIALES

1.- Una persona va a invertir su capital en un banco y desea saber cuánto dinero ganará
después de un mes si el banco paga el 2% mensual.

*/

    //  1

    /*
    float inversion;
    printf("Ingrese su inversión deseada: ");
    scanf("%f", &inversion);

    float tasa = 0.02;
    float interesMensual = inversion * tasa;
    float inversionFinal = inversion + interesMensual;

    printf("Inversion inicial: %.2f\n", inversion);
    printf("Interes en 30 dias: %.2f\n", interesMensual);
    printf("Inversion Final: %.2f\n", inversionFinal);


    float valorProducto;
    printf("Valor del producto: ");
    */

    //2.- Una tienda ofrece un descuento del 15% sobre el total de la compra y un cliente
    //desea saber cuánto deberá pagar finalmente por su compra.


    /*
    float valorProductro;
    printf("Ingrese el valor de Producto: ");
    scanf("%f", &valorProductro);

    float descunto = 0.15;

    float valorFinal = valorProductro - (valorProductro * descunto);
    printf("El pruducto quedo en: %.2f\n", valorFinal);
    */

    //3.- Un maestro desea saber qué porcentaje de hombres y de mujeres hay en un grupo de estudiante

    int mujeres,hombres;


    printf("Ingrese cuantas mujeres hay: ");
    scanf("%i", &mujeres);

    printf("Ingrese cuantos hombres hay: ");
    scanf("%i", &hombres);

    int total = mujeres + hombres;

    float porcentajeMujeres = ((float)mujeres / total) * 100;
    float porcentajeHombres = ((float)hombres / total) * 100;


    printf("Porcentaje de mujeres: %.2f%%\n", porcentajeMujeres);
    printf("Porcentaje de hombres: %.2f%%\n", porcentajeHombres);


    return 0;

}
