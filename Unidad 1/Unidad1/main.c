#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
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
        printf("Ingrese el numero del ejercicio que desea ejecutar: \n");
        scanf("%d", &opcion);  // Leer opci�n del usuario
        switch(opcion){
            case 1 : {
                /*
                1. Desarrollar una función que devuelva un valor RANDOM en el rango de 0 a 100.
                */
                int resUno = numRandom();
                printf("El numero random es: %i\n", resUno);
                break;
            }
            case 2:{
                /*
                2. Diseñe una función que reciba 3 números enteros y muestre el mayor y el menor.
                */
                int numUno, numDos, numTres;
                printf("Ingrese tres numeros: \n");
                scanf("%d %d %d", &numUno, &numDos, &numTres);
                mostrarNum(numUno, numDos, numTres);
                break;
            }
            case 3: {
                /*
                3. Diseñe una función que reciba un número entero N y realice la suma de los números
                enteros positivos menores que N y lo retorne. N es un dato ingresado por el usuario en
                el main.
                */
                    int N;
                    printf("Ingrese un Numero entero positivo \n");
                    scanf("%d", &N);
                    int respuesta = sumaNum(N);

                    if(N > 0){
                        printf("La suma de los enteros menores que %d es: %d\n", N, respuesta);
                    } else {
                        printf("El número debe ser mayor que 0.\n");
                    }
                    break;
            }
            case 4:{
                /*
                4. Desarrollar una función que muestre la tabla de multiplicar de un número entero recibido por
                parámetro.
                */
                int num;
                printf("Ingrese un numero para ver su tabla de multiplicar:\n");
                scanf("%d",&num);
                tablaMultiplicar(num);
                break;
            }
            case 5: {
                /*
                5. Realice una pequeña calculadora, utilizando funciones (una función de suma, una de
                multiplicación, una de resta, una de división…)
                */
                int numUno, numDos;
                printf("Ingrese 2 numeros:\n");
                scanf("%d %d", &numUno, &numDos);
                calculadora(numUno , numDos);
                break;
            }
            case 6: {
                /*
                6. Realizar una función que reciba un número positivo entero por parámetro por referencia, y
                cambie su signo a negativo.
                */
                int num;
                printf("Ingrese un Numero:\n");
                scanf("%d",&num);
                numNegativo(&num);
                printf("%d\n", num);
                break;
            }
            case 7:{
                /*
                    7. Realizar una función que reciba dos números enteros por parámetro por referencia y cargue
                    sus valores el usuario dentro de la función.
                */
                int num,num2;
                printf ("Ingrese dos numeros:\n");
                scanf("%d",&num);
                scanf("%d",&num2);
                cargarNumero(&num,&num2);
                printf("Los valores cargados fueron: %d y %d\n", num, num2);
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

int numRandom (){
    srand(time(NULL));
    int num = rand()%101;
    return num;
}

void mostrarNum (int num1, int num2, int num3){
    int numMayor = num1;
    int numMenor= num1;

    if (num2 > numMayor) numMayor = num2;
    if (num3 > numMayor) numMayor = num3;

    if (num2 < numMenor) numMenor= num2;
    if (num3 < numMenor) numMenor = num3;

    printf("Mayor: %d\n", numMayor);
    printf("Menor: %d\n", numMenor);
}

int sumaNum (int N){
    int suma = 0;
    for(int i = 1; i < N; i++){
        suma += i;
    }
    return suma;
}

int tablaMultiplicar(int num){
    for(int i =0; i <= 10; i++){
        printf("%d * %d = %d\n",num,i, num * i);
    }
    return num;
}

void calculadora (int num, int num2){
    int opcion = 0;
    char control = 's';

    while (control == 's'){
        printf("1 - Suma\n");
        printf("2 - Resta\n");
        printf("3 - Multiplicacion\n");
        printf("4 - Division\n");
        printf("Ingrese el numero del ejercicio que desea ejecutar: \n");
        scanf("%d", &opcion);
        switch(opcion){
            case 1:{
                printf("%d + %d = %d\n", num, num2, num + num2);
                break;
            }
            case 2:{
                printf("%d - %d = %d\n", num, num2, num - num2);
                break;
            }
            case 3:
                printf("%d * %d = %d\n", num, num2, num * num2);
                break;
            case 4:
                if (num2 != 0) {
                    printf("%d / %d = %.2f\n", num, num2, (float)num / num2);
                } else {
                    printf("Error: No se puede dividir por 0.\n");
                }
                break;
            default:
                printf("Ingrese una opción válida.\n");
        }
        printf("Quiere seguir? Ingrese 's' para continuar o cualquier otra tecla para salir: ");
        scanf(" %c", &control);
    }
}

void numNegativo (int *num){
     *num = -*num;
}
void cargarNumero(int *num , int *num2){
    return  *num, *num2;
}
