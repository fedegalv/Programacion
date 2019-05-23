#include <stdio.h>
#include <stdlib.h>
#include "persona.h"
#include "string.h"


sPersona damePersona()
{
    fflush(stdin);
    sPersona persona;
    printf("\n\nIngrese edad: ");
    scanf("%d", &persona.edad);
    fflush(stdin);
    printf("Ingrese nombre: ");
    gets(persona.nombre);

    return persona;
}
void mostrarPersona(sPersona persona)
{
    printf("\nEdad: %d\nNombre: %s",persona.edad, persona.nombre);
}

/// Recibe direcion de mem, no retorna la struct ya que se modifica mediante punteros
void modificarPerson(sPersona* pPersona)
{
    pPersona->edad = 100; /// Modifica atributo
}

void agregarPersonaArray(sPersona persona, sPersona* arrayPersonas,int pos)
{
    if(arrayPersonas != NULL)
    {
        arrayPersonas[pos] = persona;
    }
}
void cargarArrayArimeticaPunteros(sPersona* arrayPersonas)
{
    int i;
    int auxNuevaLongitud;
    sPersona *pAuxPersona;
    if(arrayPersonas == NULL)
    {
        printf("Sin espacio");
        exit(0);
    }

    for(i=0;i < 5; i++)
    {
        (arrayPersonas+i)->edad= i;
        strcpy( (arrayPersonas+i)->nombre, "mmPP");

        auxNuevaLongitud= sizeof(sPersona) * i;
        pAuxPersona= realloc(arrayPersonas, auxNuevaLongitud);
        if(pAuxPersona == NULL)
        {
            printf("NO hay lugar en mem\n");
            break;
        }
        arrayPersonas = pAuxPersona;
    }
}

void mostrarPersonasPunteros(sPersona* arrayPersona, int cant)
{
    int i;
    for(i=0; i < cant; i++)
    {
        mostrarPersonaPuntero( arrayPersona+i );
    }
}

void mostrarPersonaPuntero(sPersona *unaPersona)
{
    printf("\n %s      %d: ", unaPersona->nombre, unaPersona->edad);
}
