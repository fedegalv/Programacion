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
    LinkedList* listaFiltrada;
    listaFiltrada= ll_newLinkedList();
    do
    {
        fflush(stdin);
        printf("1-LEER ARCHIVO\n2-LISTAR NOMBRES ORDENADOS\n3-CALCULAR NOTA FINAL\n4-GUARDAR EN ARCHIVO\nSELECCIONE: ");
            scanf("%d",&opcion);
        switch(opcion)
        {

        case 1:
            valid= loadFromText("data.csv", listaAlumnos); // CARGA DE ARCHIVO
            wipeScreen();
            break;
        case 2:
            ll_sort(listaAlumnos, sortAlumnos, 1); // CAMBIA ORDEN DE LA LISTA 1= A-Z, 0= Z-A
            ListAlumnos(listaAlumnos, valid); // LISTA ORDENADA
        break;
        case 3:
            mapValid= ll_map(listaAlumnos,asignacionNota ); // NOTA FINAL RANDOM
            if(mapValid== 0)
            {
                printf("Notas finales calculadas y asignadas correctamente.\n");
            }
            wipeScreen();
            break;
        case 4:
            /// SIN USAR GENERICO
            /*
            promedioFinal= calcularPromedio(listaAlumnos); // CALCULO PROMEDIO TOTAL
            saveAsText("Final.csv", listaAlumnos, valid, promedioFinal); // GUARDAR EN ARCHIVO FINAL
            */

            /// USANDO H_FILTER GENERICO
            promedioFinal= calcularPromedio(listaAlumnos);
            listaFiltrada= H_Filter(listaAlumnos, alumnosSuperanPromedio, promedioFinal); /// SEGUNDO PARAMETRO ES EL PUNTERO A FUNCION
            saveAsText("Final.csv", listaFiltrada, valid, promedioFinal);
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
