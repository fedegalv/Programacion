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
int verificarSexo(char sexo[])
{
    int retorno=0;
    if(strcmp(sexo,"F") == 0 || strcmp(sexo, "M") == 0)
    {
        retorno= 1;
    }

    return retorno;
}
int validarTelefono(char telefono[21] )
{
    int retorno=0;
    if(strlen(telefono) < 21)
    {
        retorno= 1;
    }

    return retorno;
}
int verificarNombre (char nombre[51] )
{
    int retorno=0;
    if(strlen(nombre) < 51)
    {
        retorno= 1;
    }
    return retorno;
}
int verificarImporte(int importe)
{
    int retorno=0;
    if(importe >= 0)
    {
        retorno=1;
    }
    return retorno;
}
