#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include <ctype.h>
#include "Funcionex_aux.h"
void wipeScreen(void)
{
    system("pause"); // pausa el programa, para limpiar
    system("cls"); // se limpia la consola
}
int verificarCadena(char cadena[51])
{
    int largoCadena;
    int i;
    int retorno=0;
    largoCadena= strlen(cadena); // SE TOMA EL LARGO DEL NOMBRE

        fflush(stdin);
        for(i=0; i<largoCadena; i++) // RECORRE EL STRING
        {
            if( isalpha(cadena[i]) || isspace(cadena[i]) ) // isalpha DEVUELVE UN VALOR DISTINTO A CERO SI EL CARACTER ES ALFABETICO, SI NO 0
            {
                retorno = 1; // banderaCadena MARCARA 1 SI ES QUE EL CARACTER ANALIZADO ES ALFABETICO
            }
            else
            {
                retorno=0; // EN CASO DE ENCONTRAR UN CARACTER NO ALFABETICO , SE BAJA LA BANDERA
                break;
            }
        }

    return retorno;
}

int verificarDate(char telefono[11] )
{
    int retorno=0;
    if(strlen(telefono) < 11)
    {
        retorno= 1;
    }

    return retorno;
}
int verificarTime (char nombre[6] )
{
    int retorno=0;
    if(strlen(nombre) < 6)
    {
        retorno= 1;
    }
    return retorno;
}
int verificarMsg(char nombre[65])
{
    int retorno=0;
    if(strlen(nombre) < 65)
    {
        retorno= 1;
    }
    return retorno;
}
