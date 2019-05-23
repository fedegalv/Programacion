#ifndef actores_H
#define actores_H
typedef struct
{
    int idActor;
    char nombreActor[64];
    char paisOrigen[64];

} sActor;

void mostrarActores(sActor lista[], int tam);
void sActor_Hardcoded(sActor lista[]);
int ingresoActor(sActor listaActores[], int tamActores);
int ordenarActoresPorOrigen(sActor listaActores[], int tamActores);
int ordenarCopiaActoresPorOrigen(sActor listaActores[], sActor copiaLista[], int tamActores);
void mostrarActorSolo(sActor actor);
#endif

