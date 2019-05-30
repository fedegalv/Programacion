#include <stdio.h>
#include <stdlib.h>
#include "alumno.h"
#include "string.h"
#define ARCHIVO "alumnos.csv"


int main()
{
    FILE* pArchivo;
    sAlumno alumno;
    /*
    strcpy(alumno.nombre, "Fernando");
    alumno.legajo =1;
    alumno.nota = 9;
*/
    //printf("%s, %d, %d\n",alumno.nombre, alumno.nota, alumno.legajo);
    if( (pArchivo= fopen(ARCHIVO, "w")) == NULL)
       {
           printf("NO SE PUDO LEER\n");
       }
        else{
            printf("ARCHIVO ABIERTO\n");
            //fwrite(&alumno, sizeof(alumno), 1, pArchivo);
            char texto[]= "mcmcmmmc;555;10\n"; /// ; SIRVE PARA SEPARAR POR COLUMNAS EN EXCEL

            fwrite(texto, sizeof(char),strlen(texto), pArchivo);
        }
    fclose(pArchivo);





     if( (pArchivo= fopen(ARCHIVO, "r")) == NULL)
     {
         printf("ARCHIVO NO PUEDE SER ABIERTO\n");
         exit(1);
     }
     else{
            char renglon[70];
        while( !feof(pArchivo) )
        {
            int cant;
            //cant = fread(renglon, sizeof(char), 70, pArchivo);
            //printf("cantidad %d y texto %s \n",cant, renglon);
            char nombre[50];
            char legajo[50];
            char nota[50];
            fscanf(pArchivo, "%[^;];%[^;];%[^\n]\n", nombre, legajo, nota);
            printf("DATOS PARSEADOS\nNOMBRE:%s\nLEGAJO: %s\nNOTA: %s\n\n\n",nombre, legajo, nota);
            strcpy(alumno.nombre, nombre);
            alumno.legajo = atoi(legajo);
            alumno.nota = atoi(nota);
            printf("DATOS CONVERTIDOS\nNOMBRE:%s\nLEGAJO: %d\nNOTA: %d",alumno.nombre, alumno.legajo, alumno.nota);

        }
     }

     fclose(pArchivo);
    return 0;
}
