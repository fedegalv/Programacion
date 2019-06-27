#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parser.h"
/*

int loadFromText(char* path, LinkedList* pArrayListAlumnos)
{
    // USAR fread para leer elementos en binario
    //wipeScreen();
    fflush(stdin);
    int valid;
    FILE* pArchivo;

    ll_clear(pArrayListAlumnos);
    pArchivo= fopen(path,"r");

    if(pArchivo!= NULL)
    {
        parser_AlumnoFromText(pArchivo,pArrayListAlumnos); // LEE Y PARSEA LAS LINEAS DEL ARCHIVO
        valid= 1;
        fclose(pArchivo);

    }

    //wipeScreen();
    return valid;
}

int parser_AlumnoFromText(FILE* pFile, LinkedList* pArrayListAlumnos)
{
    int r;
    char id[10];
    char nombre[30];
    char nota1[10];
    char nota2[10];
    char notaFinal[10];
    int cont = 0;
    sAlumno* pAlumno;
    do
    {
        pAlumno= alumno_new();
        r= fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, nota1, nota2,notaFinal);
        if(r==4)
        {
            if(cont>0)
            {

                pAlumno= alumno_newParameters(id,nombre,nota1,nota2,notaFinal, pAlumno); // SE ENVIA LOS DATOS PARSEADOS PARA QUE SE AGREGEN A LA STRUCT
                ll_add(pArrayListAlumnos, pAlumno); // SE AGREGA LA STRUCT A EL ARRAY DE STRUCT
                printf("EMPLEADO--%d AGREGADO\n", cont);
            }
            else{
                    //printf("FORMATO: %s--%s--%s--%s \n", id, nombre, hsTrabajadas, sueldo);
            }
            cont++;

        }
        else
        {
            printf("ERROR AL PARSEAR\n");
        }
    }while(!feof(pFile));

    return 1;
}
*/
