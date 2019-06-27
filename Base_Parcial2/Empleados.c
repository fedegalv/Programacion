#include "Empleados.h"
#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "string.h"
sEmpleado* empleado_new()
{
    sEmpleado* empleado;
    empleado= (sEmpleado*) malloc(sizeof(sEmpleado)); // RESERVANDO ESPACIO EN MEMORIA PARA LA STRUCT EMPLEADO
    return empleado;
}

int loadFromText(char* path, LinkedList* pArrayEmpleados)
{
    // USAR fread para leer elementos en binario
    //wipeScreen();
    fflush(stdin);
    int valid=0;
    FILE* pArchivo;

    //ll_clear(pArrayEmpleados);
    pArchivo= fopen(path,"r");

    if(pArchivo!= NULL)
    {
        printf("ARCHIVO LEIDO\n");
        parser_EmployeeFromText(pArchivo,pArrayEmpleados); // LEE Y PARSEA LAS LINEAS DEL ARCHIVO
        valid= 1;
        fclose(pArchivo);

    }
    else{
        printf("ARHIVO NO LEIDO\n");
    }

    //wipeScreen();
    return valid;
}
sEmpleado* employee_newParametros(char* idStr,char* nombreStr,char* empleoStr, char* edadStr, char* horasTrabajadasStr, sEmpleado* pEmpleado)
{
    int id = atoi(idStr);
    int edad= atoi(edadStr);
    int horasTrabajadas= atoi(horasTrabajadasStr);
    //SETTER
    set_id(pEmpleado, id);
    set_nombre(pEmpleado, nombreStr);
    set_empleo(pEmpleado, empleoStr);
    set_edad(pEmpleado, edad);
    set_horasTrabajadas(pEmpleado, horasTrabajadas);
    return pEmpleado;
}

void set_id(sEmpleado* pEmpleado, int id)
{
    pEmpleado->id =id;
}
void set_nombre(sEmpleado* pEmpleado, char* nombre)
{
    strcpy(pEmpleado->nombre, nombre);
}
void set_empleo(sEmpleado* pEmpleado, char* empleo)
{
    strcpy(pEmpleado->empleo, empleo);
}
void set_dedicacion(sEmpleado* pEmpleado, char* dedicacion)
{
    strcpy(pEmpleado->dedicacion, dedicacion);
}
void set_edad(sEmpleado* pEmpleado, int edad)
{
    pEmpleado->edad =edad;
}
void set_horasTrabajadas(sEmpleado* pEmpleado, int hsTrabajadas)
{
    pEmpleado->horasTrabajadas = hsTrabajadas;
}

int sortEmpleados(void* pAlumno1, void* pAlumno2)
{

    if(strcmp( ((sEmpleado* )pAlumno1)->nombre, ((sEmpleado*) pAlumno2)->nombre) > 0)
    {
        return 1;
    }
    if(strcmp( ((sEmpleado* )pAlumno1)->nombre, ((sEmpleado*) pAlumno2)->nombre) == 0)
    {
        return 1;
    }
    if(strcmp( ((sEmpleado* )pAlumno1)->nombre, ((sEmpleado*) pAlumno2)->nombre) < 0)
    {
        return -1;
    }
    return 0;
}
int sortEmpleadosDedicacion(void* pAlumno1, void* pAlumno2)
{

    if( ((sEmpleado*)pAlumno1)->horasTrabajadas > ((sEmpleado*)pAlumno2)->horasTrabajadas)
    {
        return 1;
    }
    if(((sEmpleado* )pAlumno1)->horasTrabajadas < ((sEmpleado*)pAlumno2)->horasTrabajadas)
    {
        return -1;
    }
    return 0;
}
int get_id(sEmpleado* pEmpleado)
{
    int id= pEmpleado->id;
    return id;
}

void get_nombre(sEmpleado* pEmpleado, char* nombre)
{
    strcpy(nombre, pEmpleado->nombre);
}
void get_empleo(sEmpleado* pEmpleado, char* empleo)
{
    strcpy(empleo, pEmpleado->empleo);
}
void get_dedicacion(sEmpleado* pEmpleado, char* dedicacion)
{
    strcpy(dedicacion, pEmpleado->dedicacion);
}
int get_edad(sEmpleado* pEmpleado)
{
    int edad= pEmpleado->edad;
    return edad;
}
int get_hsTrabajadas(sEmpleado* pEmpleado)
{
    int hsTrabajadas= pEmpleado->horasTrabajadas;
    return hsTrabajadas;
}

int ListEmpleados(LinkedList* listaEmpleados, int isValid)
{
    int validList= 0;
    int listLen;
    int id;
    int edad;
    int hsTrabajadas;
    char nombre[51];
    char empleo[51];
    int i;
    sEmpleado* auxEmployee;
    auxEmployee= empleado_new();
    if(isValid == 1)
    {
        printf("LISTA DE EMPLEADOS: \n");
        printf("%5s %15s %15s %8s %10s \n", "ID","NOMBRE","EMPLEO","EDAD", "HORAS TRABAJADAS");
        listLen= ll_len(listaEmpleados);
        for(i=0; i < listLen; i++)
        {
            auxEmployee= (sEmpleado*) ll_get(listaEmpleados, i);
            // GETTER
            id= get_id(auxEmployee);
            get_nombre(auxEmployee, nombre);
            get_empleo(auxEmployee, empleo);
            edad=get_edad(auxEmployee);
            hsTrabajadas= get_hsTrabajadas(auxEmployee);

            printf("%5d %15s %15s %8d %10d \n", id, nombre, empleo, edad, hsTrabajadas );
        }
        validList= 1;
        printf("CANT ELEM LISTA : %d \n",listLen);
    }
    else
    {
        printf("NO HAY ELEMENTOS PARA MOSTRAR, O NO SE INGRESO ELEMENTOS PREVIAMENTE\n");
    }
    return validList;
}

int ListEmpleadosFull(LinkedList* listaEmpleados, int isValid)
{
    int validList= 0;
    int listLen;
    int id;
    int edad;
    int hsTrabajadas;
    char nombre[51];
    char empleo[51];
    char dedicacion[51];
    int i;
    sEmpleado* auxEmployee;
    auxEmployee= empleado_new();
    if(isValid == 1)
    {
        printf("LISTA DE EMPLEADOS: \n");
        printf("%5s %15s %15s %8s %10s %10s \n", "ID","NOMBRE","EMPLEO","EDAD", "HORAS TRABAJADAS" ,"DEDICACION");
        listLen= ll_len(listaEmpleados);
        for(i=0; i < listLen; i++)
        {
            auxEmployee= (sEmpleado*) ll_get(listaEmpleados, i);
            // GETTER
            id= get_id(auxEmployee);
            get_nombre(auxEmployee, nombre);
            get_empleo(auxEmployee, empleo);
            edad=get_edad(auxEmployee);
            hsTrabajadas= get_hsTrabajadas(auxEmployee);
            get_dedicacion(auxEmployee, dedicacion);

            printf("%5d %15s %15s %8d %10d %10s \n", id, nombre, empleo, edad, hsTrabajadas , dedicacion);
        }
        validList= 1;
        printf("CANT ELEM LISTA : %d \n",listLen);
    }
    else
    {
        printf("NO HAY ELEMENTOS PARA MOSTRAR, O NO SE INGRESO ELEMENTOS PREVIAMENTE\n");
    }
    return validList;
}
int asignacionDedicacion(void* aux)
{
    sEmpleado* auxEmpleado;
    auxEmpleado= (sEmpleado*) aux;
    int hsTrabajadas = get_hsTrabajadas(auxEmpleado);
    if(hsTrabajadas >= 1 && hsTrabajadas <= 200)
    {
        set_dedicacion(auxEmpleado, "estandar");
    }
    else if(hsTrabajadas > 200 && hsTrabajadas <= 300)
    {
        set_dedicacion(auxEmpleado, "sobre la media");
    }
    else{
        set_dedicacion(auxEmpleado, "excesivo");
    }
    return 1;
}

