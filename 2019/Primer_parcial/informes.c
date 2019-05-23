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
    limpiarPantalla();
}

void mostrarPeliculasYActores(sPelicula listaPeliculas[], sActor listaActores[], int tamPeliculas, int tamActores)
{
    int i;
    for(i=0; i<tamPeliculas; i++)
    {
        if(listaPeliculas[i].estado == 1)
        {

            mostrarEncabezado();
            mostrarUnaPelicula(listaPeliculas[i]);
            printf("\n%s %15s %15s\n","ID ","NOMBRE", "PAIS ORIGEN");
            mostrarActorSolo( listaPeliculas[i].actorPrincipal );
            printf("-------------------------------------------------------------------\n");
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
void filtroPeliculasYGenero(sActor listaActores[], sPelicula listaPeliculas[], int tamPeliculas)
{
    int i;
    limpiarPantalla();
    for(i=0; i<tamPeliculas; i++)
    {
        if( listaPeliculas[i].estado == 1 )
        {
            /*
             printf("%s","Genero:");
             printf("%s\n",listaPeliculas[i].genero);
             printf("\n%s %15s %15s\n","ID","NOMBRE", "PAIS ORIGEN");
             mostrarActorSolo( listaPeliculas[i].actorPrincipal );
             printf("----------------------------------------------------\n");
             */
            if( strcmp(listaPeliculas[i].genero, "accion"))
            {
                printf("\n%s %15s %15s\n","ID","NOMBRE", "PAIS ORIGEN");
                mostrarActorSolo( listaPeliculas[i].actorPrincipal );
            }
            else if( strcmp(listaPeliculas[i].genero, "comedia"))
            {
                printf("\n%s %15s %15s\n","ID","NOMBRE", "PAIS ORIGEN");
                mostrarActorSolo( listaPeliculas[i].actorPrincipal );
            }
            else if(strcmp(listaPeliculas[i].genero, "terror"))
            {
                printf("\n%s %15s %15s\n","ID","NOMBRE", "PAIS ORIGEN");
                mostrarActorSolo( listaPeliculas[i].actorPrincipal );
            }
            else
            {
                printf("%s","Genero:");
                printf("%s\n",listaPeliculas[i].genero);
            }
        }
    }
    limpiarPantalla();
}

void filtroActoresNacionalidad(sActor listaActores[],sPelicula listaPeliculas[], int tamPeliculas)
{
    limpiarPantalla();
    int i;
    printf("PELICULAS CUYA NACIONALIDAD DEL ACTOR SEA EEUU:\n");
    mostrarEncabezado();
    for(i=0; i<tamPeliculas; i++)
    {
        //strcmp(listaActores[i].paisOrigen, "EEUU") == 0
        if(listaPeliculas[i].estado == 1 && strcmp(listaPeliculas[i].actorPrincipal.paisOrigen, "EEUU") == 0)
        {
            mostrarUnaPelicula(listaPeliculas[i]);
        }
    }
    limpiarPantalla();
}
void filtroGenero(sActor listaActores[], sPelicula listaPeliculas[], int tamPeliculas)
{
    limpiarPantalla();
    recorreLista(listaPeliculas, tamPeliculas, "accion");
    printf("-------------------------------------------\n");
    recorreLista(listaPeliculas, tamPeliculas, "comedia");
    printf("-------------------------------------------\n");
    recorreLista(listaPeliculas, tamPeliculas, "terror");
    printf("-------------------------------------------\n");
    recorreLista(listaPeliculas, tamPeliculas, "romantica");
    printf("-------------------------------------------\n");
    recorreLista(listaPeliculas, tamPeliculas, "otro");

}
int recorreLista(sPelicula listaPeliculas[], int tamPeliculas, char cadenaChar[])
{
    int i;
    int cont=0;
    printf("GENERO %s\n", cadenaChar);
    for(i=0; i<tamPeliculas; i++)
    {
        if( listaPeliculas[i].estado == 1 && strcmp(listaPeliculas[i].genero, cadenaChar)== 0)
        {
            printf("\n%s %15s %15s\n","ID","NOMBRE", "PAIS ORIGEN");
            mostrarActorSolo( listaPeliculas[i].actorPrincipal );
            cont++;
        }
    }
    if(cont == 0)
    {
        printf("N/A\n");
    }
    return 0;
}
int filtroIngresadoPorConsola(sPelicula listaPeliculas[], int tamPeliculas, sActor listaActores[])
{
    char opcion[64];
    int i;
    int cont=0;
    printf("Ingrese pais para mostrar peliculas: ");
    fflush(stdin);
    gets(opcion);
    mostrarEncabezado();
    for(i=0; i < tamPeliculas; i++)
    {
        if( strcmpi(listaPeliculas[i].actorPrincipal.paisOrigen, opcion) == 0 && listaPeliculas[i].estado == 1)
        {
            mostrarUnaPelicula(listaPeliculas[i]);
            cont++;
        }
    }
    if( cont == 0)
    {
        printf("\n-----\nNo se ha encontrado peliculas validas!\n-----\n");
    }
    limpiarPantalla();
    return 0;
}
void filtroGeneroPeliculas(sActor listaActores[], sPelicula listaPeliculas[], int tamPeliculas)
{
    limpiarPantalla();
    recorreListaPeliculas(listaPeliculas, tamPeliculas, "accion");
    printf("-------------------------------------------\n");
    recorreListaPeliculas(listaPeliculas, tamPeliculas, "comedia");
    printf("-------------------------------------------\n");
    recorreListaPeliculas(listaPeliculas, tamPeliculas, "terror");
    printf("-------------------------------------------\n");
    recorreListaPeliculas(listaPeliculas, tamPeliculas, "romantica");
    printf("-------------------------------------------\n");
    recorreListaPeliculas(listaPeliculas, tamPeliculas, "otro");

}
int recorreListaPeliculas(sPelicula listaPeliculas[], int tamPeliculas, char cadenaChar[])
{
    int i;
    int cont=0;
    printf("GENERO %s\n\n", cadenaChar);
    mostrarEncabezado();
    for(i=0; i<tamPeliculas; i++)
    {
        if( listaPeliculas[i].estado == 1 && strcmp(listaPeliculas[i].genero, cadenaChar)== 0)
        {
            mostrarUnaPelicula(listaPeliculas[i]);
            cont++;
        }
    }
    if(cont == 0)
    {
        printf("N/A\n");
    }
    return 0;
}

void filtroGeneroPeliculasContador(sActor listaActores[], sPelicula listaPeliculas[], int tamPeliculas)
{
    limpiarPantalla();
    recorreListaPeliculasContador(listaPeliculas, tamPeliculas, "accion");
    printf("-------------------------------------------\n");
    recorreListaPeliculasContador(listaPeliculas, tamPeliculas, "comedia");
    printf("-------------------------------------------\n");
    recorreListaPeliculasContador(listaPeliculas, tamPeliculas, "terror");
    printf("-------------------------------------------\n");
    recorreListaPeliculasContador(listaPeliculas, tamPeliculas, "romantica");
    printf("-------------------------------------------\n");
    recorreListaPeliculasContador(listaPeliculas, tamPeliculas, "otro");

}
int recorreListaPeliculasContador(sPelicula listaPeliculas[], int tamPeliculas, char cadenaChar[])
{
    int i;
    int cont=0;
    printf("GENERO %s\n\n", cadenaChar);
    for(i=0; i<tamPeliculas; i++)
    {
        if( listaPeliculas[i].estado == 1 && strcmp(listaPeliculas[i].genero, cadenaChar)== 0)
        {
            cont++;
        }

    }

    if(cont == 0)
    {
        printf("N/A\n");
    }
    else
    {
        printf("CANTIDAD DE PELICULAS DEL GENERO: %d\n\n", cont);
    }
    return 0;
}
int contadorGeneroPeliculas(sPelicula listaPeliculas[], int tamPeliculas, char cadenaChar[])
{
    int i;
    int cont=0;
    for(i=0; i<tamPeliculas; i++)
    {
        if( listaPeliculas[i].estado == 1 && strcmp(listaPeliculas[i].genero, cadenaChar)== 0)
        {
            cont++;
        }

    }
    return cont;
}
int filtroActoresCantidadPeliculas(sPelicula listaPeliculas[], int tamPeliculas, sActor listaActores[], int tamActores)
{
    int i, j;
    char actorMasPopular[64];
    int contMasPopular =0;
    int contActor =0;


    for(i=0; i < tamActores; i++)
    {
        for(j=0; j < tamPeliculas; j++)
        {
            if( listaPeliculas[j].estado == 1 && ( listaActores[i].idActor == listaPeliculas[j].actorPrincipal.idActor) )
            {
                contActor++;
            }
        }
        if(contActor > contMasPopular)
        {
            contMasPopular= contActor;
            strcpy(actorMasPopular, listaActores[i].nombreActor);

        }
        contActor = 0;
    }
    printf("Actor que mas peliculas protagonizo es %s con %d peliculas\n",actorMasPopular, contMasPopular);
    return 0;
}
void filtroGenerosMenosPeliculas(sPelicula listaPeliculas[], int tamPeliculas)
{
    int contadorGeneros[5];
    char genero[5][64]= {"accion","comedia","terror","romantica", "otros"};
    int i;
    int contGeneroMenosPopular= 0;
    int posMenosPopular;

    contadorGeneros[0]= contadorGeneroPeliculas(listaPeliculas, tamPeliculas, "accion");

    contadorGeneros[1]=contadorGeneroPeliculas(listaPeliculas, tamPeliculas, "comedia");

    contadorGeneros[2]=contadorGeneroPeliculas(listaPeliculas, tamPeliculas, "terror");

    contadorGeneros[3]=contadorGeneroPeliculas(listaPeliculas, tamPeliculas, "romantica");

    contadorGeneros[4]=contadorGeneroPeliculas(listaPeliculas, tamPeliculas, "otro");

    for(i=0; i < 5; i++)
    {
        if(i == 0)
        {
            contGeneroMenosPopular = contadorGeneros[0];
            posMenosPopular= i;
        }
        else if( contadorGeneros[i] < contGeneroMenosPopular )
        {
            contGeneroMenosPopular= contadorGeneros[i];
            posMenosPopular= i;
        }
    }

    printf("El genero con menos peliculas es %s con %d peliculas\n", genero[posMenosPopular], contGeneroMenosPopular);

}





