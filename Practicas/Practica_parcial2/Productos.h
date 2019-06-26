#include "LinkedList.h"
struct
{
    int codigoProducto;
    char descripcion[51];
    int importe;
    int cantidad;
    int activo;

}typedef sProducto;

sProducto* producto_new();
void modificarProducto(LinkedList* lista);
int listarProductos(LinkedList* listaProductos, int isValid);
int lastID(LinkedList* lista);
int parser_ProductoFromBinary(FILE* pFile, LinkedList* listaProductos);
int sorProductos(void* pProducto1, void* pProducto2);
int bajaLogica(LinkedList* listaProductos);
void bajaFisica(LinkedList* listaProductos);
