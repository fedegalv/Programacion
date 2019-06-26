/** \brief Muestra menu principal
 *
 * \param void
 * \return int Opcion seleccionada por el usuario.
 *
 */
int showMenu(void);


/** \brief Obtiene la ID mas alta de la lista
 *
 * \param LinkedList* Array donde se cargaron los elementos
 * \return int ID mas alta
 *
 */
int getLastID(LinkedList* );


/** \brief Limpiar pantalla
 *
 * \param void
 * \return void
 *
 */
void wipeScreen(void);




/** \brief Verifica que el numero sea valido
 *
 * \param void
 * \return int Numero verificado
 *
 */
int verifyNumber(void);




/** \brief Verifica que el string sea valido.
 *
 * \param  char* Cadena verificada
 * \return int
 *
 */
int verifyString(char *);

char verifyStringLen(char cadena[]);



/** \brief Da formato a la cadena, pone en mayuscula el primer caracter de la cadena
 *
 * \param char* Cadena a dar formato.
 * \return void
 *
 */
void formatString(char*);


/** \brief Pide informacion que sera agregada a un empleado
 *
 * \param Employee* Empleado al cual se le agregara la informacion
 * \param int ID asignada a este empleado.
 * \return int Si se pudo realizar la operacion es [0], en otro caso [-1]
 *
 */
//int askData(Employee*, int);



/** \brief Pregunta si esta seguro de realizar los cambios
 *
 * \param void
 * \return int Opcion seleccionada
 *
 */
int editAskIfSure(void);



/** \brief Pregunta si quiere sobreescribir la lista original por la lista ordenada
 *
 * \param LinkedList* Lista ordenada
 * \param LinkedList* Lista original
 * \param int Flag que indica si fue ordenada previamente
 * \return LinkedList*
 *
 */
LinkedList* saveSortedList(LinkedList* ,LinkedList* ,int );

void cleanBinary(LinkedList* pArrayListEmployee);
int askData(sProducto* pEmpleado, int id);
