#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "producto.h"

eProducto pedirProducto()
{
    fflush(stdin);
    eProducto retorno;
    printf("\nIngrese nombre : ");
    gets(retorno.nombre);
    fflush(stdin);

    printf("Ingrese codigo de barra: ");
    gets(retorno.codigoDeBarra);
    fflush(stdin);

    printf("Ingrese fecha de vencimiento: ");
    gets(retorno.fechaDeVencimiento);
    fflush(stdin);

    printf("Ingrese proveedor: ");
    scanf("%d", &retorno.idProveedor);
    fflush(stdin);

    printf("Ingrese precio: ");
    scanf("%f", &retorno.precio);
    return retorno;
}
void mostrarProducto(eProducto producto)
{
    printf("\n\nNombre: %s\nCodigo de barra: %s\nFecha vencimiento: %s\nProveedor: %d\nPrecio: %.02f",
           producto.nombre, producto.codigoDeBarra, producto.fechaDeVencimiento,
           producto.productoID, producto.precio);
}
void mostrarProductoV2(eProducto producto, eProveedor listaProveedor[], int tam)
{

    printf("\n\nNombre: %s\nCodigo de barra: %s\nFecha vencimiento: %s\n",
           producto.nombre, producto.codigoDeBarra, producto.fechaDeVencimiento);
    mostrarInfoId(producto, listaProveedor, tam);
    printf("Precio: %.2f\n\n", producto.precio);

     //printf("%s\t %s\t %s\t %.2f", producto.nombre, producto.codigoDeBarra, producto.fechaDeVencimiento);
}
void mostrarInfoId(eProducto producto,eProveedor lista[], int tam)
{
    int i;

    for(i=0; i < tam; i++)
    {
        if(producto.idProveedor == lista[i].id)
        {
            printf("Descripcion: %s\n", lista[i].descripcion);
            printf("Localidad: %s\n", lista[i].localidad);
            printf("Due�o: %s\n", lista[i].duenio);
        }
    }
}
void cargarArray(int tam, eProducto arrayProductos[])
{
    int i;
    for(i= 0; i< tam; i++)
    {
        arrayProductos[i]= pedirProducto();
    }
}
void mostrarArray(eProducto arrayProductos[], int tam)
{
    int i;
    for(i= 0; i< tam; i++)
    {
        if(arrayProductos[i].estado == 1)
        {
            mostrarProducto(arrayProductos[i]);
        }

    }
}
void mostrarArrayV2(eProducto arrayProductos[], eProveedor arrayProveedor[] ,int tam, int tamProveedor)
{
    int i;
    for(i= 0; i< tam; i++)
    {
        if(arrayProductos[i].estado == 1)
        {
            mostrarProductoV2(arrayProductos[i], arrayProveedor, tamProveedor);
        }
    }
}

void construirArray(eProducto arrayProductos[],int tam)
{
     int i;
    for(i= 0; i< tam; i++)
    {
        arrayProductos[i].estado = 0;
    }
}
int insertProducto(eProducto elProducto, eProducto arrayProductos[], int tam)
{
    int indice;
    indice=dameLugarLibre(arrayProductos, tam);
    if(indice != -1)
    {
        arrayProductos[indice]=elProducto;
    }
    return indice;
}
int dameLugarLibre(eProducto arrayProducto[], int tam)
{
    int indice =-1;
    int i;
    for(i=0; i< tam; i++)
    {
        if(arrayProducto[i].estado == 0)
        {
            indice=i;
            break;
        }
    }

    return indice;
}
int existeProducto(eProducto elProducto, eProducto arrayProductos[], int tam)
{
    int indice= -1;
    int i;
    for(i=0; i < tam; i++)
    {

        if( strcmp(elProducto.nombre, arrayProductos[i].nombre) )
        {
            indice = i;
        break;
        }
    }
    return indice;
}
int borrarProducto(eProducto elProducto, eProducto arrayProducto[], int tam)
{
    int indice;
    indice= existeProducto(elProducto, arrayProducto, tam);
    if(indice != -1)
    {
        arrayProducto[indice].estado= -1;
    }
    return indice;
}
/*
int editarProducto(eProducto, eProducto[])
{
    return 1;
}
*/
void inicializarProductos(eProducto arrayProductos[], int tam)
{
    int ids[10]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    char codigoDeBarras[10][13]= {"100", "101", "102", "103", "104", "105", "106", "107", "108", "109"};
    float precios[10]= {42, 43 , 44 , 40, 41, 42, 35, 36, 37, 38};
    char nombres[10][50]= {"INFINIA", "AXION POWER", "D-POWER", "INFINIA DIESEL", "AXION DIESEL", "V-POWER DIESEL", "SUPER", "AXION SUPER", "NORMAL", "QUEROSENE"};
    char fechaVencimientos[10][50]= { "1/3/2020", "1/4/2020", "1/5/2020" , "1/6/2020", "1/7/2020" , "1/8/2020", "1/9/2020", "1/10/2020", "1/11/2020", "1/12/2020"};
    int idProveedores[10]= {1, 2, 3, 1, 2, 3, 1, 2, 3, 1};
    int i;
    for(i=0; i < tam; i++)
    {
        arrayProductos[i].productoID= ids[i];
        strcpy(arrayProductos[i].codigoDeBarra, codigoDeBarras[i]);
        arrayProductos[i].precio= precios[i];
        strcpy(arrayProductos[i].nombre, nombres[i]);
        strcpy(arrayProductos[i].fechaDeVencimiento, fechaVencimientos[i]);
        arrayProductos[i].idProveedor= idProveedores[i];
        arrayProductos[i].estado= 1;
    }
}
void inicializarProveedores(eProveedor arrayProveedores[], int tam)
{
    char cuit[3][12]= {"444", "555", "666"};
    int ids[3]= {1, 2, 3};
    char descripcion[3][50]= {"PETROLERA", "PETROLERA", "PETROLERA"};
    char duenios[3][50]= {"YPF", "AXION", "SHELL"};
    char localidades[3][50]= {"Avellaneda", "Bahia Blanca", "Rio negro"};
    int i;
    for(i=0; i < tam; i++)
    {
        arrayProveedores[i].id= ids[i];
        strcpy(arrayProveedores[i].descripcion, descripcion[i]);
        strcpy(arrayProveedores[i].duenio, duenios[i]);
        strcpy(arrayProveedores[i].localidad, localidades[i]);
        strcpy(arrayProveedores[i].cuit, cuit[i]);
    }
}
void mostrarProveedoresYProductos(eProducto listaProductos[], eProveedor listaProveedor[], int tamProducto, int tamProveedor)
{
    int i;
    int j;
    printf("LISTA DE PRODUCTOS POR PROVEEDOR: \n\n");
    for(i=0; i< tamProveedor; i++)
    {
        printf("------------Duenio: %s--------------------------\n", listaProveedor[i].duenio);
        //printf("Nombre\t Codigo de barra\t Fecha vencimiento\t Precio\t Descripcion\t");
        for(j=0; j< tamProducto; j++)
        {
            if( listaProveedor[i].id == listaProductos[j].idProveedor) // IF TRUE
            {
                mostrarProductoV2(listaProductos[j], listaProveedor, tamProveedor);
            }
        }

    }
}
// EJEMPLO CLASE
/*
void mostrarArrayProductosConProveedores(eProducto listaProductos[], int tamProd, eProveedor listaProveedor[], int tamProv)
{
    int i;
    int j;
    for(i=0; i < tamProd; i++)
    {
        mostrarProducto(listaProductos[i]);
        for(j=0; j< tamProv; j++)
        {
            // CREAR FUNCION LUEGO
            //mostrarProveedor(listaProveedor[j]);
        }
    }
}
*/
void ordenarProveedores(eProveedor listaProveedores[], int tamProveedor)
{
    int i;
    int j;
    eProveedor aux;
    for(i=0; i< tamProveedor; i++)
    {
        for(j=i+1; j<tamProveedor; j++)
        {
            if( strcmp(listaProveedores[i].duenio, listaProveedores[j].duenio)> 0 )
            {
                aux= listaProveedores[i];
                listaProveedores[i]= listaProveedores[j];
                listaProveedores[j]= aux;

            }
        }
    }
    for(i=0; i < tamProveedor; i++)
    {
        printf("%s\n",listaProveedores[i].duenio);
    }
}

void ordenarProductos(eProducto listaProductos[], int tamProductos)
{
    int i;
    int j;
    eProducto aux;
    for(i=0; i< tamProductos; i++)
    {
        for(j=i+1; j<tamProductos; j++)
        {
            if( strcmp(listaProductos[i].nombre, listaProductos[j].nombre) >0 )
            {
                aux= listaProductos[i];
                listaProductos[i]= listaProductos[j];
                listaProductos[j]= aux;

            }
        }
    }
    for(i=0; i < tamProductos; i++)
    {
        printf("%s\n",listaProductos[i].nombre);
    }
}

void mostrarMaximo(eProducto listaProductos[], int tamProductos)
{
    int i;
    float maxPrecio= 0;
    int idMaxPrecio;
    for(i=0; i< tamProductos; i++)
    {
        if(listaProductos[i].precio > maxPrecio && listaProductos[i].estado == 1)
        {
            maxPrecio= listaProductos[i].precio;
            idMaxPrecio= listaProductos[i].productoID;
        }
    }
    printf("\n\nEl precio maximo es %.2f del producto:", maxPrecio);
    for(i=0; i < tamProductos; i++)
    {
        if(listaProductos[i].productoID == idMaxPrecio)
        {
            mostrarProducto(listaProductos[i]);
        }
    }
}

void mostrarMinimo(eProducto listaProductos[], int tamProductos)
{
    int i;
    float minPrecio= 0;
    int idMinPrecio;
    int flag=0;
    for(i=0; i< tamProductos; i++)
    {
        if(flag== 0)
        {
            minPrecio= listaProductos[i].precio;
            idMinPrecio= listaProductos[i].productoID;
            flag=1;
        }
        else{

        if(listaProductos[i].precio < minPrecio && listaProductos[i].estado == 1)
        {
            minPrecio= listaProductos[i].precio;
            idMinPrecio= listaProductos[i].productoID;
        }
        }

    }
    printf("\n\nEl precio minmo es %.2f del producto:", minPrecio);
    for(i=0; i < tamProductos; i++)
    {
        if(listaProductos[i].productoID == idMinPrecio)
        {
            mostrarProducto(listaProductos[i]);
        }
    }
}
