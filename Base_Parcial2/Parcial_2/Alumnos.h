#include "LinkedList.h"
struct
{
    int id;
    char name[51];
    int nota1;
    int nota2;
    int notaFinal;

}typedef sAlumno;


sAlumno* alumno_newParameters(char* idStr,char* nombreStr,char* nota1Str, char* nota2Str,char* notaFinalStr, sAlumno* pAlumno);
int loadFromText(char* path, LinkedList* pArrayListAlumnos);
sAlumno* nuevoAlumno(int id, char name[],int, int nota1, int nota2, int notaFinal);
sAlumno* alumno_new();
int parser_AlumnoFromText(FILE* pFile, LinkedList* pArrayListAlumnos);
void wipeScreen(void);
int ListAlumnos(LinkedList* pArrayListAlumnos, int );
int sortAlumnos(void* , void* );
int calcularNotaFinal();
int saveAsText(char* path, LinkedList* arrayEmpleados,int isValid, int);
int calcularPromedio(LinkedList* arrayAlumnos);
int asignacionNota(LinkedList* , void* , int );
int alumnosSuperanPromedio(LinkedList* ,int, int );
int saveAsTextFilteredList(char* path, LinkedList* arrayEmpleados,int isValid, int promFinal);
