#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Empleados.h"
#include "Funciones_aux.h"
#include "parser.h"
#include <string.h>
#include "Controller.h"
#define VALID 1
#define INVALID -1

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee,int* pOverwrite)
{
    // USAR fread para leer elementos en binario
    wipeScreen();
    fflush(stdin);
    int opcion;
    int valid;
    FILE* pArchivo;
    if(*pOverwrite == 1)
    {
        printf("El archivo ya fue abierto con anterioridad, desea leerlo nuevamente? \nEsto borrara cualquier cambio realizado que no haya sido guardado en el archivo.\n1-SI\n2-NO\nOPCION SELECCIONADA:");
        scanf("%d", &opcion);
        switch(opcion)
        {
        case 1:
            ll_clear(pArrayListEmployee);
            pArchivo= fopen(path,"r");

            if(pArchivo!= NULL)
            {
                parser_EmployeeFromText(pArchivo,pArrayListEmployee); // LEE Y PARSEA LAS LINEAS DEL ARCHIVO
                valid= VALID;
                *pOverwrite= 1;
                printf("Empleados ah sido sobreescrito!\n");
                fclose(pArchivo);
            }
            else
            {
                valid= INVALID;
                *pOverwrite= 1;
            }
            break;
        case 2:
            valid= 0;
            printf("Cancelando...\n");
            break;
        default:
            printf("Opcion no valida\n");
            break;

        }
    }
    else if(*pOverwrite == -1)
    {


        pArchivo= fopen(path,"r");

        if(pArchivo!= NULL)
        {
            parser_EmployeeFromText(pArchivo,pArrayListEmployee); // LEE Y PARSEA LAS LINEAS DEL ARCHIVO
            valid= VALID;
            *pOverwrite= 1;
            printf("Archivo abierto!\n");
            fclose(pArchivo);
        }
        else
        {
            valid= INVALID;
            *pOverwrite= -1;
        }
    }

    wipeScreen();
    return valid;
}


/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

 /*
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    wipeScreen();
    int id;
    int addOK;

    id=getLastID(pArrayListEmployee); // SE OBTIENE LA ID MAS ALTA
    if(id > 1)
    {
        id= id+1;
    }
    Employee* pEmpleado;
    pEmpleado = employee_new(); // CREA NUEVO EMPLEADO
    askData(pEmpleado,id); // PIDE DATOS QUE QUE SE INGRESARAN A EL NUEVO EMPLEADO
    addOK= ll_add(pArrayListEmployee, pEmpleado); // SE AGREGA EMPLEADO AL ARRAY DE EMPLEADOS
    wipeScreen();
    //printf("estado de ADD %d \n", addOK);
    return addOK;
}
*/
/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
 /*
int controller_editEmployee(LinkedList* pArrayListEmployee,int isValid)
{
    wipeScreen();
    int providedID;
    int idFound;
    int* pIdFound= &idFound;
    int option;

    char newNombre[50];
    int newHorasTrabajadas;
    int newSueldo;

    if(isValid == VALID)
    {
        Employee* auxEmployee;
        auxEmployee= employee_new();
        int respuesta;

        printf("Desea ver la lista de empleados?\n"
               "1-SI\n2-NO\n"
               "OPCION SELECCIONADA: ");
        scanf("%d",&respuesta);
        fflush(stdin);
        if(respuesta == 1)
        {
            controller_ListEmployee(pArrayListEmployee, VALID);
        }


        printf("Ingrese ID a editar: ");
        scanf("%d", &providedID);
        auxEmployee= employee_checkId(pArrayListEmployee,providedID,pIdFound);
        if( idFound == 0)
        {
            printf("********** EMPLEADO ENCONTRADO **********\n\n"
                   "%5s %15s %15s %8s \n", "ID","NOMBRE","HS TRABAJADAS","SUELDO");
            printf("%5d %15s %15d %8d \n\n", auxEmployee->id, auxEmployee->nombre, auxEmployee->horasTrabajadas, auxEmployee->sueldo);
            printf("QUE DATO DESEA MODIFICAR?\n"
                   "1- Nombre\n"
                   "2- Horas trabajados\n"
                   "3- Sueldo\n"
                   "4- Cancelar modificacion\n"
                   "OPCION ELEGIDA: ");
            scanf("%d", &option);
            fflush(stdin);

            switch(option)
            {
            case 1:

                fflush(stdin);
                printf("Ingrese el nuevo nombre: ");
                gets(newNombre);
                verifyString(newNombre);
                if( editAskIfSure() == 1 )
                {
                    employee_setNombre(auxEmployee,newNombre);
                    printf("CAMBIOS REALIZADOS CON EXITO!\n");
                }
                else
                {
                    printf("OPERACION CANCELADA...\n");
                }

                break;

            case 2:
                printf("Ingrese las nuevas horas trabajadas: ");
                newHorasTrabajadas= verifyNumber();
                if( editAskIfSure() == 1 )
                {
                    employee_setHorasTrabajadas(auxEmployee,newHorasTrabajadas);
                    printf("CAMBIOS REALIZADOS CON EXITO!\n");
                }
                else
                {
                    printf("OPERACION CANCELADA...\n");
                }

                break;
            case 3:

                printf("Ingrese nuevo sueldo: ");
                newSueldo= verifyNumber();
                if( editAskIfSure() == 1 )
                {
                    employee_setSueldo(auxEmployee, newSueldo);
                    printf("CAMBIOS REALIZADOS CON EXITO!\n");
                }
                else
                {
                    printf("OPERACION CANCELADA...\n");
                }

                break;
            case 4:
                printf("CANCELANDO OPERACION...\n");
                break;

            default:
                printf("OPCION INVALIDA\n");
                break;
            }



        }
        else
        {
            printf("ID NO ENCONTRADA\n");
        }

    }
    else
    {
        printf("NO HAY ELEMENTOS PARA EDITAR\n");
    }


    wipeScreen();
    return 0;
}
*/
/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
*/
/*
int controller_removeEmployee(LinkedList* pArrayListEmployee, int isValid)
{
    wipeScreen();
    int providedID;
    int idFound;
    int* pIdFound= &idFound;
    int option;
    int index;
    int removeOK;

    if(isValid == VALID)
    {
        Employee* auxEmployee;
        auxEmployee= employee_new();
        int respuesta;

        printf("Desea ver la lista de empleados?\n"
               "1-SI\n2-NO\n"
               "OPCION SELECCIONADA: ");
        scanf("%d",&respuesta);
        fflush(stdin);
        if(respuesta == 1)
        {
            controller_ListEmployee(pArrayListEmployee, VALID);
        }

        printf("Ingrese ID a eliminar: ");
        scanf("%d", &providedID);
        auxEmployee= employee_checkId(pArrayListEmployee,providedID,pIdFound);
        fflush(stdin);
        if( idFound == VALID)
        {
            printf("********** EMPLEADO ENCONTRADO **********\n\n"
                   "%5s %15s %15s %8s \n", "ID","NOMBRE","HS TRABAJADAS","SUELDO");
            printf("%5d %15s %15d %8d \n\n", auxEmployee->id, auxEmployee->nombre, auxEmployee->horasTrabajadas, auxEmployee->sueldo);
            printf("ESTA SEGURO DE QUE DESEA ELIMINAR EL EMPLEADO?\n"
                   "1- SI\n"
                   "2- NO\n"
                   "OPCION ELEGIDA: ");
            scanf("%d", &option);
            if(option == 1)
            {
                index= ll_indexOf(pArrayListEmployee, auxEmployee);
                //printf("INDEX EN ARRAY %d\n", index);
                removeOK= ll_remove(pArrayListEmployee, index);
                if(removeOK== VALID)
                {
                    printf("EL EMPLEADO FUE ELIMINADO DE MANERA CORRECTA\n");
                }
                else
                {
                    printf("ERROR AL ELIMINAR EL EMPLEADO\n");
                }
            }
            else
            {
                printf("CANCELANDO OPERACION\n");
            }

        }
        else
        {
            printf("********** EMPLEADO NO ENCONTRADO *********\n");
        }

    }
    else
    {
        printf("NO HAY ELEMENTOS PARA ELIMINAR!\n");
    }


    wipeScreen();
    return 0;
}
*/

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_ListEmployee(LinkedList* pArrayListEmployee, int isValid)
{
    wipeScreen();
    int validList= INVALID;
    int listLen;
    int i;
    int id;
    int edad;
    int hsTrabajadas;
    char nombre[51];
    char empleo[51];
    sEmpleado* auxEmployee;
    auxEmployee= empleado_new();
    if(isValid == VALID)
    {
        printf("LISTA DE EMPLEADOS: \n");
        printf("%5s %15s %15s %8s %10s \n", "ID","NOMBRE","EMPLEO","EDAD", "HORAS TRABAJADAS");
        listLen= ll_len(pArrayListEmployee);
        for(i=0; i < listLen; i++)
        {
            auxEmployee= (sEmpleado*) ll_get(pArrayListEmployee, i);
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
    wipeScreen();
    return validList;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
 /*
int controller_sortEmployee(LinkedList* pArrayListEmployee,int isValid)
{
    int sorted= INVALID;
    if(isValid == VALID)
    {
        int len = ll_len(pArrayListEmployee);
        Employee* auxEmployee1;
        Employee* auxEmployee2;
        Employee* auxEmployee3;
        auxEmployee1= employee_new();
        auxEmployee2= employee_new();
        auxEmployee3= employee_new();
        int i;
        int j;
        int opcion;
        fflush(stdin);
        printf("\n\n\nSELECCIONE DE QUE MANERA QUIERE ORDENAR LA LISTA\n\n"
               "1- (A-Z)\n2- (Z-A)\nOPCION SELECCIONADA: ");
        scanf("%d",&opcion);
        //ORDEN ASCENDENTE
        if(opcion == 1)
        {
            printf("Ordenando, espere un momento...\n");
            for(i=0; i<len; i++)
            {
                for(j=i+1; j<len; j++)
                {
                    auxEmployee1= ll_get(pArrayListEmployee, i);
                    auxEmployee2= ll_get(pArrayListEmployee, j);
                    if(strcmp(auxEmployee1->nombre,auxEmployee2->nombre)>0)
                    {
                        auxEmployee3 = auxEmployee1;
                        ll_set(pArrayListEmployee,i, auxEmployee2);
                        ll_set(pArrayListEmployee,j, auxEmployee3);
                    }
                }
            }
            sorted= VALID;
        }
        // ORDEN DESCENDENTE
        else if(opcion == 2)
        {
            printf("Ordenando, espere un momento...\n");
            for(i=0; i<len; i++)
            {
                for(j=i+1; j<len; j++)
                {
                    auxEmployee1= ll_get(pArrayListEmployee, i);
                    auxEmployee2= ll_get(pArrayListEmployee, j);
                    if(strcmp(auxEmployee1->nombre,auxEmployee2->nombre)<0)
                    {
                        auxEmployee3 = auxEmployee1;
                        ll_set(pArrayListEmployee,i, auxEmployee2);
                        ll_set(pArrayListEmployee,j, auxEmployee3);
                    }
                }
            }
            sorted= VALID;

        }
        else
        {
            printf("OPCION NO VALIDA\n");
        }
    }


    return sorted;
}
*/

/*
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee,int isValid)
{
    int opcion;
    if(isValid == VALID)
    {


        fflush(stdin);
        printf("Esta operacion sobreescribira el archivo, esta seguro que desea seguir?\n1- Si\n2- No\nOpcion seleccionada: ");
        scanf("%d", &opcion);
        if(opcion == 1)
        {
            FILE* pFile;
            pFile= fopen(path,"w");
            wipeScreen();
            int listLen;
            int i;

            char sId[10];
            char sHsTrabajadas[10];
            char sSalario[20];



            Employee* auxEmployee;
            auxEmployee= employee_new();
            printf("\nCopiando a archivo...\n");

            listLen= ll_len(pArrayListEmployee);
            fprintf(pFile, "%s%s%s%s%s%s%s%s", "id", ",", "nombre", ",", "horasTrabajadas", ",", "sueldo","\n");
            for(i=0; i < listLen; i++)
            {

                auxEmployee= (Employee*) ll_get(pArrayListEmployee, i);
                snprintf(sId, 10, "%d", auxEmployee->id );
                snprintf(sHsTrabajadas, 10, "%d", auxEmployee->horasTrabajadas );
                snprintf(sSalario, 20, "%d", auxEmployee->sueldo );
                fprintf(pFile, "%s%s%s%s%s%s%s%s", sId, ",", auxEmployee->nombre, ",", sHsTrabajadas, ",", sSalario,"\n");
            }
            fclose(pFile);
            printf("Archivo escrito de manera correcta!\n");
        }
        else if(opcion == 2)
        {
            printf("Cancelando operacion...");
        }
        else
        {
            printf("Opcion invalida");
        }
    }
    else
    {
        printf("NO HAY DATOS QUE GUARDAR!\n");
    }
    wipeScreen();

    return 0;
}
*/
/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

