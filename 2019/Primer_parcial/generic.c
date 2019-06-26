#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include ".h"
#include ".h"
#include "funcionesAux.h"
int sGenerico_Init( sGenerico listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            listado[i].estado= 0;
            listado[i].idCliente= 0;
        }
    }
    return retorno;
}
int sGenerico_buscarLugarLibre(sGenerico listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(listado[i].estado == 0)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}
void sGenericoHardcoded(sGenerico lista[])
{
    char textoAvisos[5][50]= {"TEXTO PRUEBA 1", "TEXTO PRUEBA 2", "TEXTO PRUEBA 3", "TEXTO PRUEBA 4", "TEXTO PRUEBA 5"};
    int id[5] = {1, 2, 3, 4, 3};
    int numeroAviso[5] = {2, 2, 3, 3, 5};

    for(int i=0; i < 5; i++)
    {
        lista[i].idCliente = id[i];
        lista[i].numeroRubro = numeroAviso[i];
        strcpy(lista[i].textoAviso, textoAvisos[i]);
        lista[i].estado= 1;
    }
}

int altaGenerica(sGenerico lista[], int idAsignada)
{
    char nombre[50];
    char apellido[50];
    int cuit;
    printf("\nIngrese : ");
    gets(nombre);
    verificarCadena(nombre);

    printf("\nIngrese : ");
    gets(apellido);
    verificarCadena(apellido);

    printf("\nIngrese : ");
    cuit= ingresoNumero();

    strcpy(lista[idAsignada].nombre, nombre);
    strcpy(lista[idAsignada].apellido, apellido);
    lista[idAsignada].cuit = cuit;
    lista[idAsignada].estado= 1;
    lista[idAsignada].idCliente= idAsignada+1;
    printf("Alta exitosa\n");
    limpiarPantalla();
    return 0;
}

void mostrarAvisos(sAvisos lista[], int tam)
{
    printf("%10s %10s %20s\n","ID CLIENTE","NRO RUBRO", "TEXTO AVISO");
    for(int i=0; i < tam; i++)
    {
        if(lista[i].estado == 1)
        {
            printf("%10d %10d %20s\n", lista[i].idCliente, lista[i].numeroRubro, lista[i].textoAviso);

        }
    }
    limpiarPantalla();
}
int buscarGenericoID(sGenerico lista[], int tam)
{
    int id;
    int posicionEncontrada= -1;
    printf("Ingrese id a buscar: ");
    id= ingresoNumero();
    for(int i= 0; i < tam; i++)
    {
        if(lista[i].idCliente == id && lista[i].estado == 1)
        {
            posicionEncontrada= i;
        }
    }
    return posicionEncontrada;
}
int posicionGenericoID(sGenerico lista[], int tam, int idProvista)
{
    int posicionEncontrada= -1;
    for(int i= 0; i < tam; i++)
    {
        if(lista[i].idCliente == idProvista && lista[i].estado == 1)
        {
            posicionEncontrada= i;
        }
    }
    return posicionEncontrada;
}
