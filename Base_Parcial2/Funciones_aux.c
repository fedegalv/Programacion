#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include <ctype.h>
#include <time.h>
#include "LinkedList.h"
#include "Empleados.h"
int mostrarMenu(void)
{
    int opcion;
    printf("***** MENU PRINCIPAL ESTACIONAMIENTO**** \n\n");
        printf("1- INGRESO DE DATOS DE PROPIETARIOS"
               "\n2- MODIFICAR DATOS DEL PROPIETARIO"
               "\n3- BAJA DEL PROPIETARIO"
               "\n4- LISTAR PROPIETARIOS"
               "\n5- INGRESO DE AUTOMOVIL"
               "\n6- EGRESO DE AUTOMOVIL"
               "\n7- MOSTRAR AUTOS ESTACIONADO"
               "\n8- RECAUDACION TOTAL ESTACIONAMIENTO"
               "\n9- RECAUDACION POR MARCA"
               "\n10- AUTOS POR PROPIETARIOS"
               "\n11- LISTADO DE AUTOS AUDI"
               "\n12- LISTADO DE AUTOS ESTACIONADO CON LOS DATOS DE  SUS PROPIETARIOS, ORDENADO POR PATENTE"
               "\n13- SALIR DEL PROGRAMA\n"
               "\nOPCIONES SELECCIONADA: ");
        scanf("%d",&opcion);
        return opcion;
}

/*
int getLastID(LinkedList* pArrayListEmployee)
{
    int cantElementos;
    int lastID= 0;
    int i;
    cantElementos= ll_len(pArrayListEmployee);
    Employee* auxEmployee;

    if(cantElementos == 0)
    {
        lastID= 1;
    }
    else
    {
        for(i=0; i< cantElementos; i++)
        {
            auxEmployee= (Employee*) ll_get(pArrayListEmployee, i);

                if(auxEmployee->id >= lastID)
                {
                    lastID= auxEmployee->id +1;
                }

        }
    }


    return lastID;
}
*/
void wipeScreen(void)
{
    system("pause"); // pausa el programa, para limpiar
    system("cls"); // se limpia la consola
}
int verifyNumber()
{
    int numero;
    int esNumero; // esNumero funcionara como booleano, para validar si el numero es valido o no, en caso que no sea valido se volvera a pedirlo
    int numeroDevolver; // Numero a devolver
    do
    {
        //COMPROBACION DEL NUMERO INGRESADO
        char aux;
        if(scanf("%d%c", &numero, &aux) != 2 || aux != '\n') // Comprueba si lo ingresado valido o no
        {
            esNumero= 0;
            printf("No ingreso un numero valido. Reintentelo otra vez\n");
            fflush(stdin); // Limpiar el buffer de teclado
        }
        else
        {
            esNumero =1;
            numeroDevolver = numero; // Variable que guarda el numero a retornar
            fflush(stdin); // Limpiar el buffer de teclado
        }
    }
    while(esNumero == 0); // Realizar el pedido mientras el numero no sea valido.

    return numeroDevolver;
}

int verifyString(char cadena[51])
{
    int largoCadena;
    int i;
    largoCadena= strlen(cadena); // SE TOMA EL LARGO DEL NOMBRE
    int banderaCadena=0; // BANDERA PARA MARCAR QUE SE ENCONTRO UN CARACTER NO ALFABETICO, INICIALIZADO EN 0
    do
    {

        fflush(stdin);
        for(i=0; i<largoCadena; i++) // RECORRE EL STRING
        {
            if( isalpha(cadena[i]) || isspace(cadena[i]) ) // isalpha DEVUELVE UN VALOR DISTINTO A CERO SI EL CARACTER ES ALFABETICO, SI NO 0
            {
                banderaCadena = 1; // banderaCadena MARCARA 1 SI ES QUE EL CARACTER ANALIZADO ES ALFABETICO
            }
            else
            {
                banderaCadena=0; // EN CASO DE ENCONTRAR UN CARACTER NO ALFABETICO , SE BAJA LA BANDERA
                break;
            }
        }
        if(banderaCadena== 0) // SI EN ALGUN MOMENTO LA BANDERA FUE BAJADA, O NUNCA FUE SUBIDA, SE PIDE QUE REINGRESE EL NOMBRE Y SE VERIFICARA EN EL PROXIMO LOOP
        {
            printf("INGRESO ALGUN CARACTER INVALIDO. Reingrese de manera correcta:");
            scanf("%[^\n]",cadena);
        }
        //banderaCadena= 0;
        largoCadena= strlen(cadena); // SE VUELVE A MEDIR EL LARGO DEL NUEVO STRING

    }
    while(banderaCadena == 0);

    return 0;
}

void formatString(char* texto)
{
    int i; // VARIABLE CONTROL
    int largo; // VARIABLE ALMACENA LARGO DEL STRING
    for(i = 0; texto[i]; i++) // POR SI ACASO PASAMOS TODOS LOS CARACTERES A MINUSCULA
    {
        texto[i] = tolower(texto[i]);
    }
    texto[0]=toupper(texto[0]); // SE CAMBIA LA PRIMERA LETRA A MAYUSCULA
    largo = strlen(texto); // SE ALMACENA EN largo LA CANTIDAD DE CARACTERES DEL STRING
    for(i=0; i< largo; i++) // SE RECORRE EL STRING
    {
        if(texto[i]==' ') // SI ENCUENTRA UN ESPACIO EN LA CADENA, ENTRA EN EL IF
        {
            texto[i+1]=toupper(texto[i+1]); // SE PONE EN MAYUSCULA EL CARACTER QUE LE SIGUE A EL ESPACIO(i ES EL ESPACIO, i+1 ES EL CARACTER QUE LE SIGUE)
        }
    }

}
/*
int askData(Employee* pEmpleado, int id)
{
    char nombre[51];
    int sueldo;
    int hsTrabajadas;
    int askDataOK= -1;
    printf("EMPLEADO NUMERO DE ID: %d\n", id);
    fflush(stdin);

    printf("Ingrese nombre del empleado: ");
    gets(nombre);
    verifyString(nombre);
    formatString(nombre);

    fflush(stdin);

    printf("Ingrese salario del empleado: ");
    sueldo=verifyNumber();

    printf("Ingrese horas trabajadas del empleado: ");
    hsTrabajadas=verifyNumber();
    employee_newVerifiedParametros(id, nombre, hsTrabajadas, sueldo, pEmpleado);
    askDataOK= 0;
    return askDataOK;
}

int editAskIfSure(void)
{
    int option;
    fflush(stdin);
    printf("ESTA SEGURO DE QUE DESEA EDITAR EL EMPLEADO?\n"
                   "1- SI\n"
                   "2- NO\n"
                   "OPCION ELEGIDA: ");
            scanf("%d", &option);
    return option;
}
*/
LinkedList* saveSortedList(LinkedList* pSortedList,LinkedList* pArrayListEmployeeOriginal, int sorted)
{
    int opcion;
    LinkedList* aux = ll_newLinkedList();
    if(sorted == 0)
    {
        printf("\nDesea guardar la lista ordenada? Esto reemplazara a la anterior\n1-SI\n2-NO\nOPCION SELECCIONADA: ");
        scanf("%d",&opcion);
        if(opcion == 1)
        {
            printf("\nLista ordenada guardada con exito\n");
            aux= ll_clone(pSortedList);
        }
        else if (opcion == 2)
        {
            aux= ll_clone(pArrayListEmployeeOriginal);
            printf("\nNo se guardara la lista ordenada, volviendo al menu...\n");
        }
        else
        {
            aux= ll_clone(pArrayListEmployeeOriginal);
            printf("\nOPCION INVALIDA\n");
        }
    }
    wipeScreen();
    return aux;
}
/*
void cleanBinary(LinkedList* pArrayListEmployee)
{
    int index;
    Employee* auxEmployee;
    auxEmployee= employee_new();
    int idFound;
    int* pIdFound= &idFound;
    auxEmployee= employee_checkId(pArrayListEmployee,0,pIdFound);
    index= ll_indexOf(pArrayListEmployee, auxEmployee);
    ll_remove(pArrayListEmployee, index);
}
*/
