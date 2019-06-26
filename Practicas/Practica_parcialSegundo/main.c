#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "LogLibrary.h"
#include "Funcionex_aux.h"

int main()
{

    int opcion;


    FILE* pLogFile;
    FILE* pServiceFile;
    LinkedList* listaLogs;
    LinkedList* listaServicios;
    listaLogs= ll_newLinkedList();
    listaServicios= ll_newLinkedList();
    //char logName[]={"E:\\Programacion\\2019 PROGRAMACION\\Programacion\\Practicas\\Practica_parcialSegundo"};
    //char serviceName[] = {"services"};
    do
    {
        fflush(stdin);
        printf("1-LEER LOG\n2-PROCESAR INFORMACION\n3-MOSTRAR ESTADISTICAS\n4-SALIR\nSELECCIONE: ");
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            pLogFile= fopen("log.csv", "r");
            if(pLogFile != NULL)
            {
                parser_LogEntryFromFILE(pLogFile, listaLogs);
                fclose(pLogFile);
            }
            else{
                printf("ERROR ABRIR LOG\n");
            }

            pServiceFile= fopen("services.csv", "r");
            if(pServiceFile != NULL)
            {
                parser_ServiceFromFILE(pServiceFile, listaServicios);
            fclose(pServiceFile);
            }
            else
            {
                printf("ERROR ABRIR SERVICES\n");
            }
            wipeScreen();
            break;
        case 2:
            procesarInformacion(listaLogs,listaServicios);
            wipeScreen();
            break;
        case 3:
            mostrarEstadisticas(listaLogs, listaServicios);
            break;
        default:
            printf("Opcion no valida.\n");
            wipeScreen();
            break;
        }

    }
    while(opcion!= 4);
    return 0;
}
