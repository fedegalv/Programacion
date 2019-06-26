#include <stdio.h>
#include <stdlib.h>
#include "Productos.h"
#include "LinkedList.h"
#include "Funciones_aux.h"

int main()
{
    FILE* pFile;
    int opcion;
    LinkedList* listaProductos;
    LinkedList* listaOrdenada;
    listaProductos = ll_newLinkedList();
    sProducto* producto;
    int id=0;

    pFile= fopen("datos.dat","r");
    if(pFile != NULL) // NO HAY ARCHIVO ASI QUE EMPIEZA DE 1
    {
        parser_ProductoFromBinary(pFile, listaProductos);
        id= lastID(listaProductos);
    }/*
    else // PUEDO ABRIR ARCHIVO, ENCUENTRA LA ULTIMA ID Y LA USA PARA CONTINUAR
    {

    }*/

    do
    {
        fflush(stdin);
        printf("1-ALTA\n2-MODIFICAR\n3-BAJA LOGICA\n4-BAJA FISICA\n5-LISTAR\nSELECCIONE: ");
        scanf("%d",&opcion);
        switch(opcion)
        {

        case 1:

            producto= producto_new();
            id++;
            askData(producto,id);
            ll_add(listaProductos, producto);
            wipeScreen();
            pFile = fopen("datos.dat", "a");
            fwrite(producto, sizeof(sProducto), 1, pFile);
            fclose(pFile);
            break;
        case 2:
            modificarProducto(listaProductos);
            break;
        case 3:
            bajaLogica(listaProductos);
            break;
        case 4:
            bajaFisica(listaProductos);
            break;
        case 5:
            //listarProductos(listaProductos, 1);
            if(id>0)
            {
                listaOrdenada= ll_newLinkedList();
                pFile= fopen("datos.dat","r");
                parser_ProductoFromBinary(pFile, listaOrdenada);
                ll_sort(listaOrdenada, sorProductos, 1);
                listarProductos(listaOrdenada,1);
                ll_clear(listaOrdenada);
                fclose(pFile);
            }
            else{
                printf("No hay nada para mostrar\n");
                wipeScreen();
            }

            break;

        default:
            printf("Opcion no valida.\n");
            break;
        }

    }
    while(opcion!= 10);
    return 0;
}
