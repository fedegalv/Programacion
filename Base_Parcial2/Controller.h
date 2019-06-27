#include "LinkedList.h"
/** \brief Lee el archivo en modo texto, parsea y agrega los elementos al linked list.
 *
 * \param path char* Nombre del archivo a leer
 * \param pArrayListEmployee LinkedList* Array donde se cargaran los elementos
 * \param int* Flag para mostrar o no mensaje de sobre escritura, en [0] para mostrar, [-1] para no mostrar
 * \return int Devuelve [0] si la operacion fue realizada, [-1] si no lo fue.
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee, int* );



/** \brief Lee el archivo en modo binario, parsea y agrega los elementos al linked list
 *
 * \param path char* Nombre del archivo a leer
 * \param pArrayListEmployee LinkedList* Array donde se cargaran los elementos
 * \param int* Flag para mostrar o no mensaje de sobre escritura, en [0] para mostrar, [-1] para no mostrar. Si ejecuta mas de una vez esta funcion se mostrara mensaje sobre sobreescritura.
 * \return int Devuelve [0] si la operacion fue realizada, [-1] si no lo fue.
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee,int* );



/** \brief Agrega un empleado al linked list.
 *
 * \param pArrayListEmployee LinkedList* Array donde se cargaran los elementos
 * \return int Devuelve [0] si la operacion fue realizada, [-1] si no lo fue.
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee);



/** \brief Editar un empleado de la lista.
 *
 * \param pArrayListEmployee LinkedList* Array donde se cargaron los elementos
 * \param int Flag para permitir la edicion de un empleado. Se permetira la edicion si previamente 1- Se leyo del archivo, 2- Si se agrego empleados de manera manual. [0] Para permitir, [-1] para no permitir.
 * \return int Devuelve [0] si la operacion fue realizada.
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee,int );



/** \brief Remover un empleado de la lista.
 *
 * \param pArrayListEmployee LinkedList* Array donde se cargaran los elementos
 * \param int Flag para permitir la eliminacion de un empleado. Se permetira la eliminacion si previamente 1- Se leyo del archivo, 2- Si se agrego empleados de manera manual. [0] Para permitir, [-1] para no permitir.
 * \return int Devuelve [0] si la operacion fue realizada.
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee,int );



/** \brief Muestra la lista de empleados.
 *
 * \param pArrayListEmployee LinkedList* Array donde se cargaron los elementos
 * \param int Flag para mostrar la lista. Se mostrara la lista si previamente 1- Se leyo del archivo, 2- Si se agrego empleados de manera manual. [0] Para permitir, [-1] para no permitir.
 * \return int Devuelve [0] si la operacion fue realizada.
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee, int);



/** \brief Ordena la lista en orden [A-Z] o [Z-A], tiene la opcion de sobreescribir la lista original por la lista ordenada
 *
 * \param pArrayListEmployee LinkedList* Array donde se cargaron los elementos
 * \param int Flag para permitir el ordenamiento de  la lista. Se ordenara si previamente 1- Se leyo del archivo, 2- Si se agrego empleados de manera manual. [0] Para permitir, [-1] para no permitir.
 * \return int Devuelve [0] si ordeno la lista, [-1] si no lo ordeno.
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee,int );



/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char* Nombre del archivo donde se guardara la informacion.
 * \param pArrayListEmployee LinkedList* Array donde se cargaron los elementos
 * \return int Devuelve [0] si la operacion fue realizada.
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee,int );



/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char* Nombre del archivo donde se guardara la informacion.
 * \param pArrayListEmployee LinkedList* Array donde se cargaron los elementos
 * \return int Devuelve [0] si la operacion fue realizada.
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee,int );


