#include "actores.h"
#include "pelicula.h"

void listaPeliculaSinActores(sPelicula lista[], int cantPel);
void listaPeliculaConActores(sPelicula lista[], int cantPel);
void mostrarPeliculasYActores(sPelicula listaPeliculas[], sActor listaActores[], int tamPeliculas, int tamActores);
void mostrarEncabezado(void);
void filtroPeliculas(sPelicula listaPeliculas[], int tamPeliculas);
void filtroActores(sActor listaActores[], int tamActores);

void filtroActorPeliculas(sActor listaActores[], sPelicula listaPeliculas[], int tamPeliculas);

void filtroPeliculasYGenero(sActor listaActores[], sPelicula listaPeliculas[], int tamPeliculas);
void filtroActoresNacionalidad(sActor listaActores[],sPelicula listaPeliculas[], int tamPeliculas);
void filtroGenero(sActor listaActores[], sPelicula listaPeliculas[], int tamPeliculas);
int recorreLista(sPelicula listaPeliculas[], int tamPeliculas, char cadenaChar[]);
int contadorGeneroPeliculas(sPelicula listaPeliculas[], int tamPeliculas, char cadenaChar[]);

int filtroIngresadoPorConsola(sPelicula listaPeliculas[], int tamPeliculas, sActor listaActores[]);
void filtroGeneroPeliculas(sActor listaActores[], sPelicula listaPeliculas[], int tamPeliculas);
int recorreListaPeliculas(sPelicula listaPeliculas[], int tamPeliculas, char cadenaChar[]);
int recorreListaPeliculasContador(sPelicula listaPeliculas[], int tamPeliculas, char cadenaChar[]);
void filtroGeneroPeliculasContador(sActor listaActores[], sPelicula listaPeliculas[], int tamPeliculas);
int filtroActoresCantidadPeliculas(sPelicula listaPeliculas[], int tamPeliculas, sActor listaActores[], int tamActores);
void filtroGenerosMenosPeliculas(sPelicula listaPeliculas[], int tamPeliculas);
