#include <stdio.h>
#include <stdlib.h>
#include "producto.h"
// MOSTRAR TODOS PRODUCTOS
// MOSTRAR PROVEDORES Y SUS PRODUCTOS ORDENADOS
// MOSTRAR EL MAXIMO Y EL MINIMO

//ORDENAMIENTO POR PROVEEDORES Y PRODUCTOS
int main()
{
    //eProducto unProducto;
    eProducto arrayProductos[10];
    eProveedor arrayProveedores[3];
    //unProducto= pedirProducto();
    //mostrarProducto(unProducto);
    inicializarProveedores(arrayProveedores, 3);
    construirArray(arrayProductos, 10);
    inicializarProductos(arrayProductos, 10);
    //mostrarArray(arrayProductos, 10);
    //mostrarArrayV2(arrayProductos, arrayProveedores, 10, 3);
    //mostrarProveedoresYProductos(arrayProductos, arrayProveedores, 10, 3);
    //cargarArray(2, arrayProductos);
    //mostrarArray(arrayProductos, 2);
    //ordenarProveedores(arrayProveedores, 3);
    //ordenarProductos(arrayProductos, 10);
    mostrarMaximo(arrayProductos, 10);
    mostrarMinimo(arrayProductos,10);
    return 0;
}
