#include "seoane.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void getInt (char* mensaje, int* entero)
{
    printf(mensaje);
    scanf("%d", entero);
}

void getFloat (char* mensaje, float* flotante)
{
    printf(mensaje);
    scanf("%f", flotante);
}

void getString(char* mensaje, char* cadena)
{
    printf(mensaje);
    fflush(stdin);
    gets(cadena);
}

void getChar (char* mensaje, char* caracter)
{
    printf(mensaje);
    fflush(stdin);
    scanf("%c", caracter);
}

void validarMenu (int opcion, int opcionMenor, int opcionMayor)
{
    if(opcion <opcionMenor || opcion >opcionMayor)
    {
        puts("\nLa opcion ingresada es incorrecta.");
    }
}

void limpiarPantalla ()
{
    fflush(stdin);
    getchar();
    system("cls");
}

int validarSalir()
{
    int validarSalir;
    int retorno = 1;

    getInt("\n***** ESTA A PUNTO DE CERRAR EL PROGRAMA *****\n"
           "\nTodos los descuentos aplicados que no haya guardado en el archivo mapeado.csv "
           "\nse perderan una vez que cierre el programa.\n"
           "\nEsta seguro que desea salir? ingrese 1 para si o cualquier otro numero para no: ", &validarSalir);

    if(validarSalir==1)
    {
        printf("\nGracias por utilizar el programa!"
               "\nHasta luego.\n");
        retorno = 6;
    }
    else
    {
        puts("\nCierre cancelado.");
    }

    return retorno;
}
