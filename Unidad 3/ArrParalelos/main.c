#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int dimCol = 30;
const int dimElementos = 20;

int  cargarUsuario(int legajos[dimElementos],char nombres[dimElementos][dimCol], int anios[dimElementos])
{
    int validos = 0;
    char control = 's';
    while(control == 's')
    {
        printf("Ingrese legajo:\n");
        scanf("%d",&legajos[validos]);
        printf("Ingrese nombre:\n");
        scanf("%s",&nombres[validos]);
        printf("Ingrese anio:\n");
        scanf("%d",&anios[validos]);
        printf("Desea continuar ingrese 's' sino 'n' para salir:\n");
        scanf(" %c",&control);
        validos++;
    }
    return validos;
}

void mostrarUsuarios(int legajos[dimElementos], char nombres[dimElementos][dimCol], int anios[dimElementos],int validos)
{
    for(int i = 0; i < validos; i++)
    {
        printf("Legajo: %d || Nombre: %s || Anios: %d\n",legajos[i],nombres[i],anios[i]);
    }
}

int devolverLegajo (int legajos[dimElementos], int validos)
{
    int numLegajo = -1;
    int i = 0;
    printf("Ingrese el numero de legajo a buscar:\n");
    scanf("%d", &numLegajo);

    while(i < validos && legajos[i] != numLegajo)
    {
        i++;
    }

    if(i == validos)
    {
        return  -1;
    }
    return i;

}
int devolverElMenor(char nombres[dimElementos][dimCol],int validos,int posInicial)
{
    char menor[dimElementos];
    int posMenor = posInicial;
    strcpy( menor, nombres[posInicial]);

    for(int i = posInicial + 1; i < validos ; i++)
    {
        if(strcmp (nombres[i], menor]) < 0)
        {
            posMenor = i;
        }
    }
    return posMenor;
}

int main()
{
    int legajos[dimElementos];
    char nombres[dimElementos][dimCol];
    int anios[dimElementos];

    int seguir = 1;
    int opcion = 0;
    int val = 0;

    while(seguir)
    {
        printf("Ingrese un Numero para el ejercio\n");
        printf("ejercio 1\n");
        printf("ejercio 2\n");
        printf("ejercio 3\n");
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
        {
            val = cargarUsuario(legajos,nombres,anios);
            break;
        }
        case 2:
        {
            mostrarUsuarios(legajos,nombres,anios,val);
            break;
        }

        case 3:
        {
            int pos = devolverLegajo(legajos, val);
            if (pos != -1)
            {
                printf("Legajo encontrado en la posicion:%d\n", pos);
            }
            else
            {
                printf("Legajo no encontrado.\n");
            }

            break;
        }
        case 4:
        {
            int pos = devolverLegajo(legajos, val);
            if (pos != -1)
            {
                printf("Legajo encontrado: %d || Nombre: %s || Anio: %d\n", legajos[pos], nombres[pos], anios[pos]);
            }
            else
            {
                printf("Legajo no encontrado.\n");
            }

            break;
        }
        case 5:
        {

            break;
        }
        default:
        {
            printf("Ingrese un valor valido:\n");
            break;
        }
        scanf("%d",&seguir);
        }
    }


    return 0;
}
