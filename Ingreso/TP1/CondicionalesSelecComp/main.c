#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*
        C) PROBLEMAS CONDICIONALES SELECTIVOS COMPUESTOS
        9.- Leer 2 números. Si son iguales, multiplicarlos, si el primero es mayor que el
        segundo, restarlos, y si no, sumarlos.
    */
    /*
    int num1,num2;
    printf("Escriba 2 numeros:\n");
    scanf("%i",&num1);
    scanf("%i",&num2);

    if(num1 == num2){
        printf("Multiplicacion: %i",num1*num2);
    }else if(num1 > num2){
         printf("Resta: %i",num1-num2);
    }else{
          printf("Suma: %i",num1+num2);
    }
    */

    /*
        10.- Leer tres números diferentes e imprimir el mayor de ellos

    */
    int num1,num2,num3;
    printf("Escriba 3 numeros:\n");
    scanf("%i",&num1);
    scanf("%i",&num2);
    scanf("%i",&num3);

    if(num1 > num2 && num1 > num2){
        printf("El numero 1 es mayor: %i",num1);
    }else if(num2 > num1 && num2 > num3){
        printf("El numero 2 es mayor: %i",num2);
    }else{
         printf("El numero 3 es mayor: %i",num3);
    }

    return 0;
}
