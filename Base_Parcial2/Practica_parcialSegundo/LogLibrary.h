#include "LinkedList.h"
struct
{
    char date[11];
    char time[6];
    int serviceId;
    int gravedad;
    char msg[65];

}typedef s_LogEntry;

struct
{
    int id;
    char name[33];
    char email[65];

}typedef s_Service;

s_LogEntry* log_new();
s_Service* service_new();
s_LogEntry* log_newParameters(char* date,char* time,char* serviceID, char* gravedad,char* msg, s_LogEntry* pLog);
s_Service* service_newParameters(char* id,char* name,char* email, s_Service* pService);
int parser_LogEntryFromFILE(FILE* pFile, LinkedList* pLogsList);
int parser_ServiceFromFILE(FILE* pFile, LinkedList* pServiceList);
void procesarInformacion(LinkedList* listaLogs, LinkedList* listaServicios);
void mostrarEstadisticas(LinkedList* listaLogs, LinkedList* listaServicios);
