#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pelicula.h"
#include "actores.h"
#include "funcionesAux.h"

void mostrarActores(sActor lista[], int tam)
{
    int i;
    printf("%s %25s %35s\n","ID ACTOR","NOMBRE", "PAIS ORIGEN");
    for(i=0; i < tam; i++)
    {
        printf("%d %35s %35s\n", lista[i].idActor, lista[i].nombreActor, lista[i].paisOrigen);
    }
    //limpiarPantalla();
}
void mostrarActorSolo(sActor actor)
{
    printf("%d %20s %15s\n", actor.idActor, actor.nombreActor, actor.paisOrigen);
}

void sActor_Hardcoded(sActor lista[])
{
    int i;
    char nombre[5][50]= {"Julieta roberto", "Richar darin", "Nicole Kidman", "Tita merelo", "Natalia Oreiro"};
    int id[5] = {1, 2, 3, 4, 5};
    char paisOrigen[5][50]= {"EEUU", "Argentina", "Australiana", "Argentina", "Uruguay"};

    for(i=0; i < 5; i++)
    {
        lista[i].idActor = id[i];
        strcpy(lista[i].nombreActor, nombre[i]);
        strcpy(lista[i].paisOrigen, paisOrigen[i]);
    }
}
int ingresoActor(sActor listaActores[], int tamActores)
{
    int i;
    int idActor;
    int flag=0;
    int posicionActor;
    do
    {
    printf("Eliga un actor principal: ");
    idActor= ingresoNumero();
    for(i=0; i < tamActores; i++)
    {
        if(idActor == listaActores[i].idActor)
        {
            posicionActor= i;
            //lista[idProvista].actorPrincipal = listaActores[i];
            flag=1;
            printf("Actor valido\n");
            break;
        }
    }
    }while(flag == 0);

    return posicionActor;
}
int ordenarActoresPorOrigen(sActor listaActores[], int tamActores)
{
    int i, j;
    sActor aux;
    for(i=0; i<tamActores; i++)
        {
            if(listaActores[i].idActor > 0)
            {
                for(j=i+1; j<tamActores; j++)
                {
                    if(strcmp(listaActores[i].paisOrigen,listaActores[j].paisOrigen)>0)
                    {
                        aux= listaActores[i];
                        listaActores[i] = listaActores[j];
                        listaActores[j] =  aux;
                    }
                }
            }
        }
        return 0;
}
int ordenarCopiaActoresPorOrigen(sActor listaActores[], sActor copiaLista[], int tamActores)
{
    int i, j;
    sActor aux;
    for(i=0; i<tamActores; i++)
    {
        copiaLista[i]= listaActores[i];
    }

    //sActor_Hardcoded(copiaLista);
    for(i=0; i<tamActores; i++)
        {
            if(copiaLista[i].idActor > 0)
            {
                for(j=i+1; j<tamActores; j++)
                {
                    if(strcmp(copiaLista[i].paisOrigen,copiaLista[j].paisOrigen)>0)
                    {
                        aux= copiaLista[i];
                        copiaLista[i] = copiaLista[j];
                        copiaLista[j] =  aux;
                    }
                }
            }
        }
        return 0;
}
