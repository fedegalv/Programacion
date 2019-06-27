#include "LinkedList.h"
/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char* Nombre del archivo
 * \param pArrayListEmployee LinkedList* Array donde se cargaran los elementos
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);


/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char* Nombre del archivo
 * \param pArrayListEmployee LinkedList* Array donde se cargaran los elementos
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);
