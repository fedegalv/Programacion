#include "LinkedList.h"
#ifndef Empleados_H
#define Empleados_H
struct
{
    int id;
    char nombre[51];
    char empleo[51];
    int edad;
    int horasTrabajadas;
    char dedicacion[51];

}typedef sEmpleado;
#endif
sEmpleado* empleado_new();
int loadFromText(char* path, LinkedList* pArrayEmpleados);
sEmpleado* employee_newParametros(char* idStr,char* nombreStr,char* empleoStr, char* edadStr, char* horasTrabajadasStr, sEmpleado* pEmpleado);

void set_id(sEmpleado* pEmpleado, int id);
void set_nombre(sEmpleado* pEmpleado, char* nombre);
void set_empleo(sEmpleado* pEmpleado, char* empleo);
void set_edad(sEmpleado* pEmpleado, int edad);
void set_horasTrabajadas(sEmpleado* pEmpleado, int hsTrabajadas);
void set_dedicacion(sEmpleado* pEmpleado, char* dedicacion);

int asignacionDedicacion(void* aux);

int sortEmpleados(void* pAlumno1, void* pAlumno2);
int sortEmpleadosDedicacion(void* pAlumno1, void* pAlumno2);

int get_id(sEmpleado* pEmpleado);
void get_nombre(sEmpleado* pEmpleado, char* nombre);
void get_empleo(sEmpleado* pEmpleado, char* empleo);
void get_dedicacion(sEmpleado* pEmpleado, char* dedicacion);
int get_edad(sEmpleado* pEmpleado);
int get_hsTrabajadas(sEmpleado* pEmpleado);

int ListEmpleados(LinkedList* listaEmpleados, int isValid);
int ListEmpleadosFull(LinkedList* listaEmpleados, int isValid);
