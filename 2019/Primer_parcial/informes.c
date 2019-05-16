#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "ctype.h"
#include "funcionesAux.h"
#include "informes.h"
#include "pelicula.h"

void listaPeliculaSinActores(sPelicula lista[], int cantPel)
{
    int i;
    printf("\nMOSTRAR PELICULAS SIN ACTORES\n\n");
    {
        for(i=0; i < cantPel; i++)
            {
                if(lista[i].actorPrincipal.idActor == -1 && lista[i].estado ==1)
                {
                    mostrarUnaPelicula(lista[i]);
                }
            }
            limpiarPantalla();
    }

}
void listaPeliculaConActores(sPelicula lista[], int cantPel)
{
    int i;
    //printf("\nMOSTRAR PELICULAS CON ACTORES\n\n");
    //printf("%10s %10s %20s\n", "ID", "COD PEL", "TITULO");
    mostrarEncabezado();
    for(i=0; i < cantPel; i++)
    {
        if(lista[i].actorPrincipal.idActor != -1 && lista[i].estado ==1)
        {
            mostrarUnaPelicula(lista[i]);
        }
    }
    printf("\n\n");
    limpiarPantalla();
}

void mostrarPeliculasYActores(sPelicula listaPeliculas[], sActor listaActores[], int tamPeliculas, int tamActores)
{
    int i;
    limpiarPantalla();
    for(i=0; i<tamPeliculas; i++)
    {
         if(listaPeliculas[i].estado == 1)
         {

             mostrarEncabezado();
             mostrarUnaPelicula(listaPeliculas[i]);
             printf("\n%s %15s %15s\n","ID ","NOMBRE", "PAIS ORIGEN");
             mostrarActorSolo( listaPeliculas[i].actorPrincipal );
             printf("--------------------------------------------------------------------------------------\n");
         }

    }
    limpiarPantalla();
}

void mostrarEncabezado()
{
    printf("\n\n%s %15s %15s %15s %15s\n", "ID", "COD PEL", "TITULO", "F. Estreno", "Genero");
}

void filtroPeliculas(sPelicula listaPeliculas[], int tamPeliculas)
{
    int i;
    mostrarEncabezado();
    for(i=0; i<tamPeliculas; i++)
    {
        if(listaPeliculas[i].fechaEstreno > 2000 && listaPeliculas[i].estado == 1)
        {
            mostrarUnaPelicula(listaPeliculas[i]);
        }
    }
    limpiarPantalla();
}

void filtroActores(sActor listaActores[], int tamActores)
{
    int i;
    printf("%s %15s %15s\n","ID","NOMBRE", "PAIS ORIGEN");
    for(i=0; i<tamActores; i++)
    {
        if( strcmp(listaActores[i].paisOrigen, "Argentina") == 0)
        {
            mostrarActorSolo(listaActores[i]);
        }
    }
    limpiarPantalla();
}
void filtroActorPeliculas(sActor listaActores[], sPelicula listaPeliculas[], int tamPeliculas)
{
    int i;
    for(i=0; i<tamPeliculas; i++)
    {
        if( listaPeliculas[i].fechaEstreno > 2000 && listaPeliculas[i].estado == 1 && strcmpi(listaPeliculas[i].actorPrincipal.paisOrigen, "Argentina") == 0 )
        {
             mostrarEncabezado();
             mostrarUnaPelicula(listaPeliculas[i]);
             printf("\n%s %15s %15s\n","ID","NOMBRE", "PAIS ORIGEN");
             mostrarActorSolo( listaPeliculas[i].actorPrincipal );
             printf("------------------------------------------------------\n");
        }
    }
    limpiarPantalla();
}
