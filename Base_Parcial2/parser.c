#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "LinkedList.h"
#include "Empleados.h"
#include "string.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int r;
    char id[10];
    char nombre[51];
    char empleo[51];
    char edad[10];
    char horasTrabajadas[10];
    int cont = 1;
    sEmpleado* pEmpleado;
    do
    {
        pEmpleado= empleado_new();
        r= fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, empleo, edad,horasTrabajadas);
        if(r==5)
        {
            //printf("ID STRING %s\n", id);
                employee_newParametros(id, nombre, empleo, edad, horasTrabajadas, pEmpleado); // SE ENVIA LOS DATOS PARSEADOS PARA QUE SE AGREGEN A LA STRUCT
               // printf("ID--%d \n", pEmpleado->id);
                ll_add(pArrayListEmployee, pEmpleado); // SE AGREGA LA STRUCT A EL ARRAY DE STRUCT
                //printf("EMPLEADO--%d AGREGADO\n", cont);
            cont++;

        }
        else
        {
            printf("ERROR AL PARSEAR\n");
        }
    }while(!feof(pFile));

    return 1;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
