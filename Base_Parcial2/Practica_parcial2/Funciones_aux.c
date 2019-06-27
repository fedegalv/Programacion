#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Productos.h"
#include "string.h"
int showMenu()
{
    int option;
    fflush(stdin);
    printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n"
           "2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n"
           "3. Alta de empleado\n"
           "4. Modificar datos de empleado\n"
           "5. Baja de empleado\n"
           "6. Listar empleados\n"
           "7. Ordenar empleados\n"
           "8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n"
           "9. Guardar los datos de los empleados en el archivo data.bin (modo binario).\n"
           "10. Salir\n"
           "OPCION SELECCIONADA: ");
    scanf("%d", &option);
    return option;
}
/*
int getLastID(LinkedList* pArrayListEmployee)
{
    int cantElementos;
    int lastID;
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
            if(i== 0)
            {
                lastID= auxEmployee->id;
            }
            else{
                if(auxEmployee->id > lastID)
                {
                    lastID= auxEmployee->id;
                }
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
void verifyStringLen(char cadena[51])
{
    int len;
    do
    {
        printf("Ingrese descripcion del producto: ");
        gets(cadena);
        len= strlen(cadena);
        if(len>50)
        {
            printf("Descripcion supero el limite de caracteres(50)\n");
        }
    }while(len>50);

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

int askData(sProducto* pEmpleado, int id)
{
    char descripcion[51];
    int importe;
    int cantidad;
    int askDataOK= -1;
    printf("EMPLEADO NUMERO DE ID: %d\n", id);
    fflush(stdin);

    verifyStringLen(descripcion);


    fflush(stdin);

    printf("Ingrese importe del producto: ");
    importe=verifyNumber();

    printf("Ingrese cantidad de producto: ");
    cantidad=verifyNumber();
    pEmpleado->codigoProducto = id;
    strcpy(pEmpleado->descripcion, descripcion);
    pEmpleado->importe= importe;
    pEmpleado->cantidad= cantidad;
    pEmpleado->activo= 1;

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
