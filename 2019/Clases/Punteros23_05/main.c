#include <stdio.h>
#include <stdlib.h>
#include "persona.h"
int main()
{
    //sPersona persona;
    sPersona *pArrayPersonas;

    printf("array: %p\n", &pArrayPersonas);
    pArrayPersonas= malloc(sizeof(sPersona));
    printf("malloc: %p", &pArrayPersonas);
/*
    persona= damePersona();
    mostrarPersona(persona);

    modificarPerson(&persona); /// Pasa la direccion de mem de la struct persona
    mostrarPersona(persona);
    persona= damePersona();
    agregarPersonaArray(persona, pArrayPersonas, 0);

    persona= damePersona();
    agregarPersonaArray(persona, pArrayPersonas, 1);


    mostrarPersona(pArrayPersonas[0]);
    mostrarPersona(pArrayPersonas[1]);
    */

    cargarArrayArimeticaPunteros(pArrayPersonas);
    mostrarPersonasPunteros(pArrayPersonas, 5);
    return 0;
}
