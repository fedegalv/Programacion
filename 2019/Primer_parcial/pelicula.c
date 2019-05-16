#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ctype.h"
#include "pelicula.h"
#include "pelicula.h"
#include "funcionesAux.h"
#include "informes.h"

int sPelicula_Init( sPelicula listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            listado[i].estado= 0;
            listado[i].idPelicula= 0;
            listado[i].actorPrincipal.idActor = -1;
        }
    }
    return retorno;
}
int sPelicula_buscarLugarLibre(sPelicula listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        for(i=0; i<limite; i++)
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

int sPelicula_Hardcoded(sPelicula lista[], int idSemilla, sActor listaActores[])
{
    /*
    int idPelicula[5] = {1000, 1001, 1002, 1003, 1004};
    int codigoPelicula[5]= {123, 252, 458, 747, 196};
    char titulo[5][64]= {"Carnagedon","Sharko","Mulan","Avatar","Creeper"};
    int fechaEstreno[5] = {2000, 2010, 1950, 2012, 1980};
    char genero[5][64]= {"Accion","Accion","Cartoon","Sci fi","Terror"};
    */
    int idPelicula[8] = {1000, 1001, 1002, 1003, 1004, 1005, 1006, 1007 };
    int codigoPelicula[8]= {999, 666, 555, 777, 111, 222, 101, 202};
    char titulo[8][64]= {"terminator","thor","it","gladiator", "scary movie 4", "Yo soy asi", "scary movie 2", "sexto sentido"};
    int fechaEstreno[8] = {2000, 2010, 1950, 2012, 2012, 1990, 2015, 1999};
    char genero[8][64]= {"accion","accion","terror","romantica", "comedia", "otro", "comedia", "otro"};
    //int idActores[6]= {1, 2, 3, 4 ,4, 4};




    int i;
    for(i=0; i < 8; i++)
    {
        /*
        lista[i].actorPrincipal.idActor= listaActores[i].idActor; // ASIGNARA ACTORES de 0 a 4(POSICION)
        strcpy(lista[i].actorPrincipal.nombreActor, listaActores[i].nombreActor);
        strcpy(lista[i].actorPrincipal.paisOrigen, listaActores[i].paisOrigen);
        */
        if(i== 0)
        {
            lista[i].actorPrincipal.idActor= 1; // ASIGNARA ACTORES de 0 a 4(POSICION)
        strcpy(lista[i].actorPrincipal.nombreActor, listaActores[0].nombreActor);
        strcpy(lista[i].actorPrincipal.paisOrigen, listaActores[0].paisOrigen);
        }
        if(i== 1)
        {
            lista[i].actorPrincipal.idActor= 5; // ASIGNARA ACTORES de 0 a 4(POSICION)
        strcpy(lista[i].actorPrincipal.nombreActor, listaActores[4].nombreActor);
        strcpy(lista[i].actorPrincipal.paisOrigen, listaActores[4].paisOrigen);
        }
        if(i== 2)
        {
            lista[i].actorPrincipal.idActor= 4; // ASIGNARA ACTORES de 0 a 4(POSICION)
        strcpy(lista[i].actorPrincipal.nombreActor, listaActores[3].nombreActor);
        strcpy(lista[i].actorPrincipal.paisOrigen, listaActores[3].paisOrigen);
        }
        if(i== 3)
        {
            lista[i].actorPrincipal.idActor= 4; // ASIGNARA ACTORES de 0 a 4(POSICION)
        strcpy(lista[i].actorPrincipal.nombreActor, listaActores[3].nombreActor);
        strcpy(lista[i].actorPrincipal.paisOrigen, listaActores[3].paisOrigen);
        }
        if( i==4 || i==5)
        {
            lista[i].actorPrincipal.idActor= 4; // ASIGNARA ACTORES de 0 a 4(POSICION)
            strcpy(lista[i].actorPrincipal.nombreActor, listaActores[3].nombreActor);
            strcpy(lista[i].actorPrincipal.paisOrigen, listaActores[3].paisOrigen);
        }
        if( i==6 || i==7)
        {
            lista[i].actorPrincipal.idActor= 1; // ASIGNARA ACTORES de 0 a 4(POSICION)
            strcpy(lista[i].actorPrincipal.nombreActor, listaActores[0].nombreActor);
            strcpy(lista[i].actorPrincipal.paisOrigen, listaActores[0].paisOrigen);
        }

        strcpy(lista[i].titulo, titulo[i]);
        lista[i].fechaEstreno= fechaEstreno[i];
        strcpy(lista[i].genero, genero[i]);

        lista[i].codigoPelicula = codigoPelicula[i];
        lista[i].estado= 1;
        lista[i].idPelicula= idPelicula[i];//+1;
        idSemilla++;
    }
    return idSemilla;
}

int verificarCodigoPelicula(int codigoPelicula)
{
    int flag=0;
    do
    {
        if(codigoPelicula >= 100 && codigoPelicula < 1000)
        {
            flag =1;
        }
        if(flag == 0)
        {
            fflush(stdin);
            printf("\nCodigo Invalido, reingrese codigo de la pelicula: ");
            scanf("%d", &codigoPelicula);
        }
    }
    while(flag ==0);
    return codigoPelicula;
}
int verificarTitulo(char tituloPelicula[64])
{
    int flag=0;
    do
    {
        if(strlen(tituloPelicula) > 1 && ( isdigit( tituloPelicula[0])) == 0  ) /// SI ES DE 3 CIFRAS Y NO EMPIEZA CON NUMERO
        {
            flag =1;
        }
        else
        {
            fflush(stdin);
            printf("\nTitulo pelicula Invalido, reingrese titulo de la pelicula: ");
            gets(tituloPelicula);
        }
    }
    while(flag == 0);

    return 0;
}
int CodigoPeliculaRepetido(sPelicula lista[], int tam, int codigoPelicula)
{
    int codigoValido = 1;
    fflush(stdin);
    int i;
    do
    {
        if(codigoValido == 0)
        {
            printf("\nEl codigo ya exite. Reingrese codigo de la pelicula: ");
            scanf("%d", &codigoPelicula);
            verificarCodigoPelicula(codigoPelicula);
            codigoValido = 1;
        }

        for(i= 0; i < tam; i++)
        {
            if( lista[i].codigoPelicula == codigoPelicula )
            {
                codigoValido = 0;
                break;
            }
        }
    }
    while(codigoValido == 0);

    return codigoPelicula;
}


int altasPelicula(sPelicula lista[], sActor listaActores[], int idAsignada, int posicionLibre, int tamPeliculas)
{
    char tituloPelicula[64];
    int fechaEstreno;
    char genero[64];
    int codigoPelicula;
    int posicionActor;

    printf("ALTA PELICULA ID %d\n\n", idAsignada);
    fflush(stdin);
    printf("\nIngrese codigo de la pelicula: ");
    scanf("%d", &codigoPelicula );
    codigoPelicula= verificarCodigoPelicula(codigoPelicula);
    codigoPelicula= CodigoPeliculaRepetido(lista, tamPeliculas, codigoPelicula);

    fflush(stdin);
    printf("\nIngrese titulo de la pelicula: ");
    gets(tituloPelicula);
    verificarTitulo(tituloPelicula);

    fflush(stdin);
    printf("\nIngrese fecha de estreno: ");
    scanf("%d", &fechaEstreno);
    fechaEstreno= verificarFecha(fechaEstreno);

    fflush(stdin);
    printf("\nIngrese genero de la pelicula: ");
    seleccionGenero(genero);

    mostrarActores(listaActores, 5);
    posicionActor= ingresoActor(listaActores, 5);
////
    lista[posicionLibre].actorPrincipal.idActor= listaActores[posicionActor].idActor;
    strcpy(lista[posicionLibre].actorPrincipal.nombreActor, listaActores[posicionActor].nombreActor);
    strcpy(lista[posicionLibre].actorPrincipal.paisOrigen, listaActores[posicionActor].paisOrigen);
///
    strcpy(lista[posicionLibre].titulo, tituloPelicula);
    lista[posicionLibre].fechaEstreno= fechaEstreno;
    strcpy(lista[posicionLibre].genero, genero);

    lista[posicionLibre].codigoPelicula = codigoPelicula;
    lista[posicionLibre].estado= 1;
    lista[posicionLibre].idPelicula= idAsignada;//+1;
    printf("Alta exitosa\n");
    limpiarPantalla();
    return 0;
}
int seleccionGenero(char genero[])
{
    int opcion;
    printf("GENEROS: \n1- accion\n2- comedia\n3- terror\n4- otro\nOPCION SELECCIONADA: ");
    scanf("%d",&opcion);
    switch(opcion)
    {
    case 1:
        strcpy(genero, "accion");
        break;
        case 2:
            strcpy(genero, "comedia");
        break;
        case 3:
            strcpy(genero, "terror");
        break;
        case 4:
            strcpy(genero, "otro");
        break;
        default:
            printf("NO VALIDO\n");

    }
    printf("\n\n\n");
    return 0;
}
int verificarFecha(int fechaEstreno)
{
    int flag=0;
    do
    {
        if( fechaEstreno >= 1894 && fechaEstreno <= 2025 )
        {
            flag =1;
        }
        else
        {
            fflush(stdin);
            printf("\nFecha de estreno invalida, reingrese fecha de estreno: ");
            scanf("%d", &fechaEstreno);
        }
    }
    while(flag == 0);

    return fechaEstreno;
}
void mostrarsPelicula(sPelicula lista[], int tam)
{
    int i;
    printf("%s %15s %10s\n","ID","TITULO", "GENERO");
    for(i=0; i < tam; i++)
    {
        if(lista[i].estado == 1)
        {
            printf("%d %15s %10s\n", lista[i].idPelicula, lista[i].titulo, lista[i].genero);

        }
    }
}
void mostrarUnaPelicula(sPelicula pelicula)
{
    printf("%d %15d %15s %15d %15s\n", pelicula.idPelicula, pelicula.codigoPelicula, pelicula.titulo, pelicula.fechaEstreno, pelicula.genero);
}

int buscarsPeliculaID(sPelicula lista[], int tam)
{
    int id;
    int i;
    int posicionEncontrada= -1;
    printf("Ingrese id a buscar: ");
    id= ingresoNumero();
    for(i= 0; i < tam; i++)
    {
        if(lista[i].idPelicula == id && lista[i].estado == 1)
        {
            posicionEncontrada= i;
        }
    }
    return posicionEncontrada;
}
/*
int posicionsPeliculaID(sPelicula lista[], int tam, int idProvista)
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
*/

int modificarPelicula(sPelicula listaPeliculas[], int tamLista, sActor listaActores[], int tamActores)
{
    limpiarPantalla();
    printf("MODIFICACION DE DATOS\n");
    mostrarsPelicula(listaPeliculas, tamLista);
    int posicionEncontrada = buscarsPeliculaID(listaPeliculas, tamLista);
    if( posicionEncontrada != -1)
    {
        int opcion;
        char aux[64];
        int auxInt;
        int posicionActor;
        printf("SE VA A MODIFICAR: \n");
        mostrarEncabezado();
        mostrarUnaPelicula(listaPeliculas[posicionEncontrada]);
        printf("\n\n\nQUE ES LO QUE DESEA MODIFICAR?\n1- Titulo\n2- Actor\n3- Anio de estreno\nOPCION SELECCIONADA: ");
        scanf("%d", &opcion);
        switch(opcion)
        {
        case 1:
            fflush(stdin);
            printf("Ingrese nuevo titulo: ");
            gets(aux);
            verificarTitulo(aux);
            strcpy(listaPeliculas[posicionEncontrada].titulo, aux);
            printf("Cambio realizado con exito\n");
            break;
        case 2:
            fflush(stdin);
            printf("Seleccione un nuevo actor de la lista: \n");
            mostrarActores(listaActores, tamActores);
            posicionActor= ingresoActor(listaActores, tamActores);
            listaPeliculas[posicionEncontrada].actorPrincipal.idActor= listaActores[posicionActor].idActor;
            strcpy(listaPeliculas[posicionEncontrada].actorPrincipal.nombreActor, listaActores[posicionActor].nombreActor);
            strcpy(listaPeliculas[posicionEncontrada].actorPrincipal.paisOrigen, listaActores[posicionActor].paisOrigen);
            printf("Cambio realizado con exito\n");
            break;
        case 3:
            fflush(stdin);
            printf("\nIngrese nueva fecha de estreno: ");
            scanf("%d", &auxInt);
            auxInt= verificarFecha(auxInt);
            listaPeliculas[posicionEncontrada].fechaEstreno= auxInt;
            printf("Cambio realizado con exito\n");
            break;
        default:
            printf("OPCION NO VALIDA\n");
        }
    }
    else
    {
        printf("El id no es valido\n");
    }
    limpiarPantalla();
    return 0;
}
int bajaPelicula(sPelicula listaPeliculas[], int tamLista)
{
    limpiarPantalla();
    printf("BAJA DE PELICULA\n");
    mostrarsPelicula(listaPeliculas, tamLista);
    int posicionEncontrada = buscarsPeliculaID(listaPeliculas, tamLista);
    if( posicionEncontrada != -1)
    {
        printf("SE VA A DAR DE BAJA LO SIGUIENTE: \n");
        mostrarEncabezado();
        mostrarUnaPelicula(listaPeliculas[posicionEncontrada]);
        listaPeliculas[posicionEncontrada].estado= -1; // -1 DADO DE BAJA
        printf("\n\nBaja realizada con exito\n\n");
    }
    else
    {
        printf("\nEl id no es valido o no existe\n");
    }
    limpiarPantalla();
    return 0;
}
int ordenarPorAnioEstreno(sPelicula listaPeliculas[], int tamLista)
{
    int i;
    sPelicula aux;
    int j;
    for(i=0; i<tamLista; i++)
    {
        if(listaPeliculas[i].estado == 1)
        {
            for(j=i+1; j<tamLista; j++)
            {
                if( listaPeliculas[i].fechaEstreno > listaPeliculas[j].fechaEstreno)
                {
                    aux = listaPeliculas[i];
                    listaPeliculas[i] = listaPeliculas[j];
                    listaPeliculas[j] = aux;
                }
            }
        }
    }
    return 0;
}
int ordenarCopiaPorAnioEstreno(sPelicula listaPeliculas[], sPelicula copiaLista[], int tamLista)
{
    int i;
    sPelicula aux;
    int j;
    for(i=0; i<tamLista; i++)
    {
        copiaLista[i]= listaPeliculas[i];
    }
    for(i=0; i<tamLista; i++)
    {
        if(copiaLista[i].estado == 1)
        {
            for(j=i+1; j<tamLista; j++)
            {
                if( copiaLista[i].fechaEstreno > copiaLista[j].fechaEstreno)
                {
                    aux = copiaLista[i];
                    copiaLista[i] = copiaLista[j];
                    copiaLista[j] = aux;
                }
            }
        }
    }
    return 0;
}
