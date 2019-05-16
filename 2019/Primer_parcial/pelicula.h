#include "actores.h"
#ifndef pelicula_H
#define pelicula_H
typedef struct
{
    int idPelicula;
    int codigoPelicula;
    char titulo[64];
    int fechaEstreno;
    char genero[64];
    sActor actorPrincipal;
    int estado;

} sPelicula;

int sPelicula_Init( sPelicula listado[],int limite);
int sPelicula_Hardcoded(sPelicula lista[], int idSemilla, sActor listaActores[]);
int sPelicula_buscarLugarLibre(sPelicula listado[],int limite);
int altasPelicula(sPelicula lista[], sActor listaActores[], int idAsignada, int posicionLibre, int tamPeliculas);
void mostrarsPelicula(sPelicula lista[], int tam);
int verificarTitulo(char tituloPelicula[]);
int verificarCodigoPelicula(int codigoPelicula);
void mostrarUnaPelicula(sPelicula pelicula);
int modificarPelicula(sPelicula listaPeliculas[], int tamLista, sActor listaActores[], int tamActores);
int CodigoPeliculaRepetido(sPelicula lista[], int tam, int codigoPelicula);
int verificarFecha(int fechaEstreno);
int bajaPelicula(sPelicula listaPeliculas[], int tamLista);
int ordenarPorAnioEstreno(sPelicula listaPeliculas[], int tamLista);
int ordenarCopiaPorAnioEstreno(sPelicula listaPeliculas[], sPelicula copiaLista[], int tamLista);
int seleccionGenero(char genero[]);


#endif
