#include "actores.h"
#include "pelicula.h"

void listaPeliculaSinActores(sPelicula lista[], int cantPel);
void listaPeliculaConActores(sPelicula lista[], int cantPel);
void mostrarPeliculasYActores(sPelicula listaPeliculas[], sActor listaActores[], int tamPeliculas, int tamActores);
void mostrarEncabezado(void);
void filtroPeliculas(sPelicula listaPeliculas[], int tamPeliculas);
void filtroActores(sActor listaActores[], int tamActores);

void filtroActorPeliculas(sActor listaActores[], sPelicula listaPeliculas[], int tamPeliculas);
