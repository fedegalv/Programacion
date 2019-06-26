#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include <ctype.h>
#include "LogLibrary.h"
#include "Funcionex_aux.h"
#include "LinkedList.h"
s_LogEntry* log_new()
{
    s_LogEntry* log;
    log= (s_LogEntry*) malloc(sizeof(s_LogEntry)); // RESERVANDO ESPACIO EN MEMORIA PARA LA STRUCT
    return log;
}
s_Service* service_new()
{
    s_Service* service;
    service= (s_Service*) malloc(sizeof(s_Service)); // RESERVANDO ESPACIO EN MEMORIA PARA LA STRUCT
    return service;
}

s_LogEntry* log_newParameters(char* date,char* time,char* serviceID, char* gravedad,char* msg, s_LogEntry* pLog)
{
    pLog->serviceId = atoi(serviceID);
    pLog->gravedad = atoi(gravedad);
    if(verificarDate(date) == 1)
    {
        strcpy(pLog->date, date);
    }
    if(verificarTime(time) == 1)
    {
        strcpy(pLog->time, time);
    }
    if(verificarMsg(msg) == 1)
    {
        strcpy(pLog->msg, msg);
    }

    return pLog;
}
s_Service* service_newParameters(char* id,char* name,char* email, s_Service* pService)
{
    pService->id = atoi(id);
    strcpy(pService->name, name);
    strcpy(pService->email, email);
    return pService;
}
int parser_LogEntryFromFILE(FILE* pFile, LinkedList* pLogsList)
{
    int r;
    char date[11];
    char time[6];
    char serviceID[5];
    char gravedad[5];
    char msg[65];
    int cont = 0;
    s_LogEntry* logAux;
    if(pFile != NULL)
    {
        printf("PARSEANDO ARCHIVO\n");
        do
        {
            logAux= log_new();
            r= fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", date, time, serviceID, gravedad, msg);
            if(r==5)
            {
                if(cont>0) // SALTEA PRIMERA LINEA
                {
                    //printf("%s %s %s %s %s",date, time, serviceID, gravedad, msg);
                    logAux= log_newParameters(date,time,serviceID,gravedad,msg, logAux); // SE ENVIA LOS DATOS PARSEADOS PARA QUE SE AGREGEN A LA STRUCT

                    ll_add(pLogsList, logAux); // SE AGREGA LA STRUCT A EL ARRAY DE STRUCT
                    printf("Log--%d AGREGADO\n", cont);
                }
                else
                {
                    //printf("FORMATO: %s--%s--%s--%s \n", id, nombre, hsTrabajadas, sueldo);
                }
                cont++;

            }
            else
            {
                printf("ERROR AL PARSEAR LOG\n");
            }
        }
        while(!feof(pFile));
    }
    return 1;
}
int parser_ServiceFromFILE(FILE* pFile, LinkedList* pServiceList)
{
    int r;
    char id[5];
    char name[33];
    char email[65];
    int cont = 0;
    s_Service* serviceAux;

        do
        {
            serviceAux= service_new();
            r= fscanf(pFile, "%[^,],%[^,],%[^\n]\n", id, name, email);
            if(r==3)
            {
                if(cont>0) // SALTEA PRIMERA LINEA
                {

                    serviceAux= service_newParameters(id,name,email,serviceAux); // SE ENVIA LOS DATOS PARSEADOS PARA QUE SE AGREGEN A LA STRUCT
                    ll_add(pServiceList, serviceAux); // SE AGREGA LA STRUCT A EL ARRAY DE STRUCT
                    printf("Service--%d AGREGADO\n", cont);
                }
                else
                {
                    //printf("FORMATO: %s--%s--%s--%s \n", id, nombre, hsTrabajadas, sueldo);
                }
                cont++;

            }
            else
            {
                printf("ERROR AL PARSEAR SERVICE\n");
            }
        }
        while(!feof(pFile));
    return 1;
}

void procesarInformacion(LinkedList* listaLogs, LinkedList* listaServicios)
{
    int i;
    int j;
    s_LogEntry* auxLog;
    s_Service* auxService;
    auxLog= log_new();
    auxService = service_new();

    FILE* fWarning;
    char sGravedad[10];
    char sMailServicio[65];
    char sNombreServicio[33];
    for(i=0; i < ll_len(listaLogs); i++)
    {
        auxLog= ll_get(listaLogs, i);
        if(auxLog->gravedad == 3 && auxLog->serviceId != 45) // COPIAR A WARNING.TXT
        {
            for(j= 0; j < ll_len(listaServicios); j++)
            {
                auxService= ll_get(listaServicios, j);
                if(auxLog->serviceId == auxService->id)
                {
                    strcpy(sMailServicio, auxService->email);
                    strcpy(sNombreServicio, auxService->name);
                }
            }
            fWarning= fopen("warning.txt", "a");
            snprintf(sGravedad, 10, "%d", auxLog->gravedad );
            fprintf(fWarning, "%s%s%s%s%s%s%s%s%s%s%s", "\n",auxLog->date, ";", auxLog->time, ";", sNombreServicio, ";", auxLog->msg,";", sMailServicio, "\n");
            fclose(fWarning);
        }

        else if (auxLog->gravedad >= 4 && auxLog->gravedad <= 7)
            {
                for(j= 0; j < ll_len(listaServicios); j++)
                {
                    auxService= ll_get(listaServicios, j);
                    if(auxLog->serviceId == auxService->id)
                    {
                        strcpy(sMailServicio, auxService->email);
                        strcpy(sNombreServicio, auxService->name);
                    }

                }
                printf("FECHA   HORA    NOMBRE SERVICIO     MENSAJE ERROR   GRAVEDAD\n");
                printf("%s\t%s\t%s\t%s\t%d\n", auxLog->date, auxLog->time, sNombreServicio, auxLog->msg, auxLog->gravedad);
            }
        else if(auxLog->gravedad > 7 ) // COPIAR A ERRORS.TXT
        {
            for(j= 0; j < ll_len(listaServicios); j++)
            {
                auxService= ll_get(listaServicios, j);
                if(auxLog->serviceId == auxService->id)
                {
                    strcpy(sMailServicio, auxService->email);
                    strcpy(sNombreServicio, auxService->name);
                }
            }
            fWarning= fopen("errors.txt", "a");
            snprintf(sGravedad, 10, "%d", auxLog->gravedad );
            fprintf(fWarning, "%s%s%s%s%s%s%s%s%s%s%s","\n", auxLog->date, ";", auxLog->time, ";", sNombreServicio, ";", auxLog->msg,";", sMailServicio, "\n");
            fclose(fWarning);
        }

    }
}

void mostrarEstadisticas(LinkedList* listaLogs, LinkedList* listaServicios)
{

    int i;
    int j;
    s_LogEntry* auxLog;
    s_Service* auxService;
    auxLog= log_new();
    auxService= service_new();
    int logLen= ll_len(listaLogs);
    int serviciosLen= ll_len(listaServicios);

    int cantidadFallos= 0;
    int cantidadMaximaFallos= 0;
    char nombreFallo[33];

    for(i=0; i < serviciosLen; i++)
    {
        auxService= ll_get(listaServicios, i);
        for(j=0; j < logLen; j++)
        {
            auxLog= ll_get(listaLogs, j);
            if(auxService->id == auxLog->serviceId)
            {
                cantidadFallos++;
            }
        }
        if(cantidadFallos > cantidadMaximaFallos)
        {
            cantidadMaximaFallos= cantidadFallos;
            strcpy(nombreFallo, auxService->name);
        }
        cantidadFallos=0;
    }

    int erroresMenoresTres= 0;
    int erroresTres=0;
    int erroresEntreCuatroYSIete=0;
    int erroresMayorSiete= 0;


    for(i=0; i < logLen; i++)
    {
        auxLog= ll_get(listaLogs, i);
        if(auxLog->gravedad < 3)
        {
            erroresMenoresTres++;
        }
        else if(auxLog->gravedad == 3)
        {
            erroresTres++;
        }
        else if(auxLog->gravedad >= 4 && auxLog->gravedad <= 7)
        {
            erroresEntreCuatroYSIete++;
        }
        else if(auxLog->gravedad > 7)
        {
            erroresMayorSiete++;
        }
    }


    printf("El servicio que mas fallos tiene es %s con %d fallos\n\n", nombreFallo, cantidadMaximaFallos);
    printf("Cantidad de fallos segun gravedad:\nMenores a 3: %d\nIguales a 3: %d\nEntre 4 y 7: %d\nMayores a 7: %d\n", erroresMenoresTres, erroresTres, erroresEntreCuatroYSIete, erroresMayorSiete);

    wipeScreen();
}


