#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include <ctype.h>
#include <time.h>
#include "Alumnos.h"
#include "LinkedList.h"

sAlumno* alumno_new()
{
    sAlumno* alumno;
    alumno= (sAlumno*) malloc(sizeof(sAlumno)); // RESERVANDO ESPACIO EN MEMORIA PARA LA STRUCT EMPLEADO
    return alumno;
}
void wipeScreen(void)
{
    system("pause"); // pausa el programa, para limpiar
    system("cls"); // se limpia la consola
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
        if(r==5)
        {
            if(cont>0)
            {

                pAlumno= alumno_newParameters(id,nombre,nota1,nota2,notaFinal, pAlumno); // SE ENVIA LOS DATOS PARSEADOS PARA QUE SE AGREGEN A LA STRUCT
                ll_add(pArrayListAlumnos, pAlumno); // SE AGREGA LA STRUCT A EL ARRAY DE STRUCT
                printf("Alumno--%d AGREGADO\n", cont);
            }
            else
            {
                //printf("FORMATO: %s--%s--%s--%s \n", id, nombre, hsTrabajadas, sueldo);
            }
            cont++;

        }
        else
        {
            printf("ERROR AL PARSEAR\n");
        }
    }
    while(!feof(pFile));

    return 1;
}


int loadFromText(char* path, LinkedList* pArrayListAlumnos)
{
    // USAR fread para leer elementos en binario
    //wipeScreen();
    fflush(stdin);
    int valid=0;
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

sAlumno* alumno_newParameters(char* idStr,char* nombreStr,char* nota1Str, char* nota2Str,char* notaFinalStr, sAlumno* pAlumno)
{
    pAlumno->id = atoi(idStr);
    pAlumno->nota1= atoi(nota1Str);
    pAlumno->nota2= atoi(nota2Str);
    pAlumno->notaFinal= atoi(notaFinalStr);
    strcpy(pAlumno->name, nombreStr);
    return pAlumno;
}
int ListAlumnos(LinkedList* pArrayListAlumnos, int isValid)
{
    wipeScreen();
    int validList= 0;
    int listLen;
    int i;
    sAlumno* auxAlumno;
    auxAlumno= alumno_new();
    if(isValid == 1)
    {
        printf("LISTA DE EMPLEADOS: \n");
        printf("%5s %15s %10s %10s %14s \n", "ID","NOMBRE","NOTA 1","NOTA 2", "NOTA FINAL");
        listLen= ll_len(pArrayListAlumnos);
        for(i=0; i < listLen; i++)
        {
            auxAlumno= (sAlumno*) ll_get(pArrayListAlumnos, i);
            printf("%5d %15s %10d %10d %14d\n", auxAlumno->id, auxAlumno->name, auxAlumno->nota1, auxAlumno->nota2, auxAlumno->notaFinal);
        }
        validList= 1;
        printf("CANT ELEM LISTA : %d \n",listLen);
    }
    else
    {
        printf("NO HAY ELEMENTOS PARA MOSTRAR, O NO SE INGRESO ELEMENTOS PREVIAMENTE\n");
    }
    wipeScreen();
    return validList;
}

int sortAlumnos(void* pAlumno1, void* pAlumno2)
{

    if(strcmp( ((sAlumno* )pAlumno1)->name, ((sAlumno*) pAlumno2)->name) > 0)
    {
        return 1;
    }
    if(strcmp( ((sAlumno* )pAlumno1)->name, ((sAlumno*) pAlumno2)->name) < 0)
    {
        return -1;
    }
    return 0;
}
int calcularNotaFinal()
{
    //srand(time(NULL));
    int ranNumero = rand()% 10;
    return ranNumero;
}

int saveAsText(char* path, LinkedList* arrayEmpleados,int isValid, int promFinal)
{
    if(isValid == 1)
    {


        fflush(stdin);
        FILE* pFile;
        pFile= fopen(path,"w");
        wipeScreen();
        int listLen;
        int i;

        char sId[10];
        char sNota1[10];
        char sNota2[10];
        char sNotaFinal[10];



        sAlumno* auxAlumno;
        auxAlumno= alumno_new();
        printf("\nCopiando a archivo...\n");
        printf("PROMEDIO A SUPERAR: %d\n", promFinal);
        listLen= ll_len(arrayEmpleados);
        fprintf(pFile, "%s%s%s%s%s%s%s%s%s%s", "id", ",", "nombre", ",", "nota1", ",", "nota2", ",", "notaFinal","\n");
        for(i=0; i < listLen; i++)
        {
            auxAlumno= (sAlumno*) ll_get(arrayEmpleados, i);
            if(auxAlumno->notaFinal > promFinal)
            {
                printf("Nota promedio superada, escribiendo...\n");

                snprintf(sId, 10, "%d", auxAlumno->id );
                snprintf(sNota1, 10, "%d", auxAlumno->nota1 );
                snprintf(sNota2, 10, "%d", auxAlumno->nota2 );
                snprintf(sNotaFinal, 10, "%d", auxAlumno->notaFinal );
                fprintf(pFile, "%s%s%s%s%s%s%s%s%s%s", sId, ",", auxAlumno->name, ",", sNota1, ",", sNota2,",", sNotaFinal,"\n");
            }
            else
            {
                continue;
            }

        }
        fclose(pFile);
        printf("Archivo escrito de manera correcta!\n");

    }
    else
    {
        printf("NO HAY DATOS QUE GUARDAR!\n");
    }
    wipeScreen();

    return 0;
}
int calcularPromedio(LinkedList* arrayAlumnos)
{
    int listLen= ll_len(arrayAlumnos);
    int i;
    sAlumno* auxAlumno;
    int acumNotas;
    int promAlumno;
    int acumNotasTotal=0;
    int promedio= 0;
    for(i=0; i < listLen; i++)
    {
        acumNotas= 0;
        auxAlumno= (sAlumno*) ll_get(arrayAlumnos, i);
        acumNotas= auxAlumno->nota1 + auxAlumno->nota2;
        promAlumno= acumNotas/2;
        acumNotasTotal= acumNotasTotal+ promAlumno;
    }
    promedio= acumNotasTotal / listLen;
    printf("El promedio es: %d\n", promedio);
    return promedio;
}

int asignacionNota(LinkedList* arrayEmpleados, void* aux, int cont) // DEVUELVE 0 SI SALIO TODO BIEN
{
    int setOK;
    int randomNumber;
    sAlumno* auxAlumno;
    auxAlumno= (sAlumno*) aux;
    randomNumber= calcularNotaFinal();

    auxAlumno->notaFinal= randomNumber;
    setOK= ll_set(arrayEmpleados, cont, auxAlumno);


    return setOK;

}
