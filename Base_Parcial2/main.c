#include <stdio.h>
#include <stdlib.h>
#include "Funciones_aux.h"
#include "Controller.h"
#include "LinkedList.h"
#include "Empleados.h"
#include "parser.h"

int main()
{
    int valid;
    int opcion=0;
    LinkedList* listaEmpleados;
    listaEmpleados= ll_newLinkedList();

    do
    {
        fflush(stdin);
        printf("1-LEER ARCHIVO\n2-LISTAR EMPLEADOS ORDENADOS\n3-CARGAR DEDICACION\n4-LISTAR ORDENADOS POR DEDICACION \nSELECCIONE: ");
            scanf("%d",&opcion);
        switch(opcion)
        {

        case 1:
            valid= loadFromText("archivo.txt", listaEmpleados); // CARGA DE ARCHIVO
            wipeScreen();
            break;
        case 2:
            //controller_ListEmployee(listaEmpleados, valid);
            //listaOrdenada= ll_clone(listaEmpleados);

            ll_sort(listaEmpleados, sortEmpleados, 1); // CAMBIA ORDEN DE LA LISTA 1= A-Z, 0= Z-A
            //controller_ListEmployee(listaEmpleados, valid);
            ListEmpleados(listaEmpleados, valid);
            //ll_clear(listaOrdenada);
            wipeScreen();
        break;
        case 3:
            ll_map(listaEmpleados, asignacionDedicacion);
            printf("Dedicacion cargada\n");
            wipeScreen();
            break;
        case 4:
            ll_sort(listaEmpleados, sortEmpleadosDedicacion, 0);
            //controller_ListEmployee(listaEmpleados, valid);
            ListEmpleadosFull(listaEmpleados, valid);
            wipeScreen();
            break;

        default:
            printf("Opcion no valida.\n");
            wipeScreen();
            break;
        }

    }
    while(opcion!= 10);

    return 0;
}
