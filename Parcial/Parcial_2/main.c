#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Alumnos.h"
#include "LinkedList.h"


int main()
{
    int valid;
    int opcion=0;
    int mapValid;
    int promedioFinal;
    LinkedList* listaAlumnos;
    listaAlumnos= ll_newLinkedList();
    do
    {
        fflush(stdin);
        printf("1- LEER ARCHIVO\n2-LISTAR NOMBRES\n3-Calcular nota final\n4-Guardar archivo\nSELECCIONE: ");
            scanf("%d",&opcion);
        switch(opcion)
        {

        case 1:
            valid= loadFromText("data.csv", listaAlumnos); // CARGA DE ARCHIVO
            wipeScreen();
            break;
        case 2:
            ll_sort(listaAlumnos, sortAlumnos, 1); // Z-A, CAMBIAR A A-Z SI SE PREFIERE
            ListAlumnos(listaAlumnos, valid); // LISTA ORDENADA
        break;
        case 3:
            mapValid= ll_map(listaAlumnos,asignacionNota ); // NOTA FINAL RANDOM
            if(mapValid== 0)
            {
                printf("Notas finales asignadas correctamente\n");
            }
            wipeScreen();
            break;
        case 4:
            promedioFinal= calcularPromedio(listaAlumnos); // CALCULO PROMEDIO TOTAL
            saveAsText("Final.csv", listaAlumnos, valid, promedioFinal); // GUARDAR EN ARCHIVO FINAL
            break;
        default:
            break;
        }

    }
    while(opcion!= 10);

    return 0;
}
