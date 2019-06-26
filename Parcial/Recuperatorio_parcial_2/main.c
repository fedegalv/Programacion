#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include <ctype.h>
#include "reglasNegocio.h"
#include "Funcionex_aux.h"
#include "LinkedList.h"
#define PERSONAL 0
#define FAMILIAR 1
#define CORPORATIVO 2
/// FILTER TIPO DE ABONO
/// MAP DATOS
int main()
{
    int opcion;
    int esValido;
    int abonoValido;
    int validOP;
    LinkedList* listaClientes;
    LinkedList* listaAbonos;
    listaClientes= ll_newLinkedList();
    listaAbonos= ll_newLinkedList();
    LinkedList* listaCompleta;
    listaCompleta= ll_newLinkedList();
    do
    {
        fflush(stdin);
        printf("1-LEER CLIENTES\n2-GENERAR ABONOS\n3-LISTAR ABONOS ORDENADOS\n4-GENERAR ARCHIVOS\n5-SALIR\nSELECCIONE: ");
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            esValido= altasClientes(listaClientes);
            //printf("%d id mas alta\n", idMasAlta(listaClientes));
            wipeScreen();
            break;
        case 2:
            abonoValido= asignacionAbono(listaClientes,listaAbonos);
            break;
        case 3:
            validOP= crearAbonoCompleto(listaAbonos, listaClientes, listaCompleta,esValido,abonoValido);
            //ll_sort(listaClientes,comparaId,1 );
            //listarClientes(listaClientes, esValido);
            ll_sort(listaCompleta, sortImporte, 2);
            //listarAbonos(listaAbonos,listaClientes, esValido);
            listarAbonosCompletos(listaCompleta, validOP);
            break;
        case 4:
            saveAsCSV("abonos.CSV", listaAbonos, abonoValido);
            saveAsBinary("abonos.BIN", listaAbonos, abonoValido);
            break;
        case 5:
            exit(0);

        default:
            printf("Opcion no valida.\n");
            wipeScreen();
            break;
        }

    }
    while(opcion!= 10);

    return 0;
}
