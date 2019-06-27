#include <stdio.h>
#include <stdlib.h>
#include "Productos.h"
#include "LinkedList.h"
#include "Funciones_aux.h"
#include "string.h"
sProducto* producto_new()
{
    sProducto* producto;
    producto= (sProducto*) malloc(sizeof(sProducto)); // RESERVANDO ESPACIO EN MEMORIA PARA LA STRUCT EMPLEADO
    return producto;
}
int lastID(LinkedList* lista)
{
    int len= ll_len(lista);
    int id;
    sProducto* aux;
    aux= producto_new();
    int i;
    for(i=0; i<len; i++)
    {
        aux=ll_get(lista, i);
        if(aux->activo == 1)
        {
            id= aux->codigoProducto;
        }

    }
    return id;
}
void modificarProducto(LinkedList* lista)
{
    int idBuscar;
    printf("Ingrese id de producto a modificar: ");
    idBuscar= verifyNumber();
    int i;
    int opcion;
    int cambioOK= 0;
    FILE* pFile;
    for(i=0; i < ll_len(lista); i++)
    {
        sProducto* aux;
        aux= (sProducto*) malloc(sizeof(sProducto));
        aux= ll_get(lista, i);
        if(aux->codigoProducto == idBuscar)
        {
            fflush(stdin);
            printf("Que desea modificar:\n1-Descripcion\n2-Importe\n3-Cantidad\n");
            opcion= verifyNumber();
            switch(opcion)
            {
            case 1:
                cambioOK =1;
                char descripcion[51];
                verifyStringLen(descripcion);
                strcpy(aux->descripcion, descripcion);
                break;
            case 2:
                printf("Ingrese nuevo importe del producto: ");
                int importe;
                importe=verifyNumber();
                aux->importe= importe;
                cambioOK = 1;
                break;
            case 3:
                printf("Ingrese nuevo cantidad de producto: ");
                int cantidad;
                cantidad=verifyNumber();
                aux->cantidad = cantidad;
                cambioOK= 1;
                break;
            default:
                printf("Opcion invalida\n");
            }
            if(cambioOK)
            {
                ll_set(lista, i, aux);

                sProducto* aux2;
                aux2=producto_new();
                int j;
                pFile= fopen("datos.dat", "w");
                for(j=0; j<ll_len(lista); j++)
                {
                    aux2= ll_get(lista, j);
                    fwrite(aux2, sizeof(sProducto), 1, pFile);
                }
                fclose(pFile);
            }

        }
    }
    wipeScreen();


}
int sorProductos(void* pProducto1, void* pProducto2)
{

    if(strcmp( ((sProducto* )pProducto1)->descripcion, ((sProducto*) pProducto2)->descripcion) > 0)
    {
        return 1;
    }
    if(strcmp( ((sProducto* )pProducto1)->descripcion, ((sProducto*) pProducto2)->descripcion) < 0)
    {
        return -1;
    }
    return 0;
}
int listarProductos(LinkedList* listaProductos, int isValid)
{
    wipeScreen();
    int validList= 0;
    int listLen;
    int i;
    sProducto* auxProducto;
    auxProducto= producto_new();
    if(isValid == 1)
    {
        printf("LISTA DE PRODUCTOS: \n");
        printf("%5s %30s %10s %10s \n", "ID","DESCRIPCION","IMPORTE","CANTIDAD");
        listLen= ll_len(listaProductos);
        for(i=0; i < listLen; i++)
        {
            auxProducto= (sProducto*) ll_get(listaProductos, i);
            if(auxProducto->activo == 1)
            {
                printf("%5d %30s %10d %10d\n", auxProducto->codigoProducto, auxProducto->descripcion, auxProducto->importe, auxProducto->cantidad);
            }

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

int parser_ProductoFromBinary(FILE* pFile, LinkedList* listaProductos)
{
    //int cont = 0;
    sProducto* pProducto;
    //int y=0;
    do
    {

        pProducto= producto_new();
        fread(pProducto, sizeof(sProducto), 1, pFile);
        if(pProducto->activo == 1)
        {
            ll_add(listaProductos, pProducto);
        }

        //y++;

    }
    while(!feof(pFile));

    //printf("CUENTA AL LEER: %d", y);

    return 1;
}

int bajaLogica(LinkedList* listaProductos)
{
    int idBuscar;
    printf("Ingrese id de producto a dar de baja: ");
    idBuscar= verifyNumber();
    int i;
    for(i=0; i < ll_len(listaProductos); i++)
    {
        sProducto* aux;
        aux= (sProducto*) malloc(sizeof(sProducto));
        aux= ll_get(listaProductos, i);
        if(aux->codigoProducto == idBuscar)
        {
            printf("Producto encontrado, dando de baja...\n");
            aux->activo=0;

            sProducto* aux2;
            aux2=producto_new();

            FILE* pFile;
            int j;
            pFile= fopen("datos.dat", "w");
            for(j=0; j<ll_len(listaProductos); j++)
            {
                if(j != i)
                {
                    aux2= ll_get(listaProductos, j);
                    fwrite(aux2, sizeof(sProducto), 1, pFile);
                }

            }
            fclose(pFile);
        }
        ll_set(listaProductos, i, aux);

    }
    if(i > ll_len(listaProductos))
    {
        printf("Producto no encontrado\n");
    }
    wipeScreen();
    return idBuscar;
}
void bajaFisica(LinkedList* listaProductos)
{
    int idBuscar;
    printf("Ingrese id de producto a dar de baja: ");
    idBuscar= verifyNumber();
    int i;
    for(i=0; i < ll_len(listaProductos); i++)
    {
        sProducto* aux;
        aux= (sProducto*) malloc(sizeof(sProducto));
        aux= ll_get(listaProductos, i);
        if(aux->codigoProducto == idBuscar)
        {
            printf("Producto encontrado, dando de baja...\n");

            sProducto* aux;
            aux=producto_new();

            FILE* pFile;
            int j;
            pFile= fopen("datos.dat", "w");
            for(j=0; j<ll_len(listaProductos); j++)
            {
                if(j != i)
                {
                    aux= ll_get(listaProductos, j);
                    fwrite(aux, sizeof(sProducto), 1, pFile);
                }

            }
            fclose(pFile);
        }

    }
    if(i== ll_len(listaProductos))
    {
        printf("Producto no encontrado\n");
    }
    wipeScreen();
}

