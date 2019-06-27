#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
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
    char nombre[30];
    char hsTrabajadas[10];
    char sueldo[30];
    int cont = 0;
    Employee* pEmpleado;
    do
    {
        pEmpleado= employee_new();
        r= fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, hsTrabajadas, sueldo);
        if(r==4)
        {
            if(cont>0)
            {

                employee_newParametros(id,nombre,hsTrabajadas,sueldo,pEmpleado); // SE ENVIA LOS DATOS PARSEADOS PARA QUE SE AGREGEN A LA STRUCT
                ll_add(pArrayListEmployee, pEmpleado); // SE AGREGA LA STRUCT A EL ARRAY DE STRUCT
                //printf("EMPLEADO--%d AGREGADO\n", cont);
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

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    //int cont = 0;
    Employee* pEmpleado;
    int y=0;
        do
        {

            pEmpleado= employee_new();
            fread(pEmpleado, sizeof(Employee), 1, pFile);
            ll_add(pArrayListEmployee, pEmpleado);
            y++;

        }while(!feof(pFile));

    //printf("CUENTA AL LEER: %d", y);

    return 1;
}
