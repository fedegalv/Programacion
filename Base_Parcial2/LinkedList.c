#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Empleados.h"

int (*pFunc)(void*,void*);
static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;
    this = (LinkedList *)malloc(sizeof(LinkedList));
    if(this != NULL)
    {
        this->size=0;
        this->pFirstNode = NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux= -1;
    if(this != NULL)
    {

        returnAux=  this->size;
    }

    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{

    Node* pNode= NULL;
    int cont= 0;
    if(this != NULL)
    {

        if(nodeIndex < this->size && nodeIndex>=0) // nodeIndex TIENE QUE SER MENOR A SIZE Y MAYOR O IGUAL A 0
        {
            pNode=  this->pFirstNode;
            while(pNode->pNextNode != NULL)
            {
                if ( cont == nodeIndex)
                {
                    break;
                }
                pNode= pNode->pNextNode;
                cont++;
            }
        }
        else
        {
            pNode = NULL;
        }

    }

    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{

    int returnAux = -1;
    int cont;

    if(this!= NULL )
    {
        if(nodeIndex>=0 && nodeIndex <= this->size)
        {
            Node* newNode;
            newNode= (Node*) malloc(sizeof(Node));
            newNode->pElement= pElement;
            newNode->pNextNode= NULL;
            //CREO UN NUEVO NODO newNode, AL CUAL LE ASIGNO pElement
            if(nodeIndex == 0)
            {
                newNode->pNextNode=this->pFirstNode; // newNode ENLAZA COMO pNextNode A LA RAIZ ANTERIOR o pFirstNode ANTERIOR
                this->pFirstNode=newNode;// newNode SE INSERTA EN LA POSICION DE RAIZ O pFirstNode
                returnAux=0;
            }
            else
            {
                Node* currentNode;
                Node* lastNode;
                currentNode= (Node*) malloc(sizeof(Node));
                lastNode= (Node*) malloc(sizeof(Node));
                //CREO 2 NODOS AUXILIARES, QUE GUARDARAN EL NODO ACTUAL Y NODO ANTERIOR
                currentNode= this->pFirstNode;//
                for(cont=1; cont <= nodeIndex; cont++) // SE CUENTA A PARTIR DE 1, 0 YA ESTA CUBIERTA EN EL OTRA OPCION. RECORRERA HASTA LLEGAR A nodeIndex
                {
                    lastNode= currentNode; // GUARDAMOS EL NODO ACTUAL en lastNode
                    if(cont == nodeIndex)
                    {
                        currentNode= newNode; // SI cont Y nodeIndex COINCIDEN ASIGNAR A currentNode -> newNode
                        lastNode->pNextNode= currentNode; // EL NODO ANTERIOR ENLAZA COMO pNextNode A currentNode
                        break;
                    }
                    currentNode=currentNode->pNextNode;
                }
                returnAux=0;

            }
            this->size++;
        }
    }
    return returnAux;
}


/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int cont=0;
    LinkedList* lista;
    lista= malloc(sizeof(LinkedList));
    lista= this; // <^^ ESTO SE PUEDE ELIMINAR

    Node* newNode;
    Node* currentNode;

    newNode= (Node*)malloc(sizeof(Node));
    currentNode= (Node*)malloc(sizeof(Node));
    newNode->pElement =NULL;
    newNode->pNextNode= NULL;
    if(lista != NULL)
    {
        if(lista->pFirstNode == NULL) // SI pFirstNode ES NULL, SE GUARDARA AHI newNode
        {
            lista->pFirstNode= newNode;
            lista->pFirstNode->pElement= pElement,
                               lista->size= lista->size +1;
            returnAux = 0;
        }
        else
        {
            currentNode= lista->pFirstNode;
            cont++;
            while(currentNode->pNextNode != NULL)
            {
                currentNode= currentNode->pNextNode;
                cont++;
            }
            addNode(lista,cont,pElement);
            returnAux = 0;
        }

    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{

    void* returnAux = NULL;
    //Node* pNode = NULL;
    Node* pNodeAux; // NODO AUXILIAR QUE VA A CONTENER EL RESULTADO DE getNode
    if( this!= NULL )
    {

        if(index>=0 && index < this->size)
        {
            pNodeAux=getNode(this,index);
            returnAux=pNodeAux->pElement; // SE ASIGNA A returnAux EL ELEMENTO DE pNodeAux ANTERIORMENTE OBTENIDO, VALIDO O NO(NUll)
        }
    }

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    //int cont =0 ;
    LinkedList* lista;
    lista=this;
    int returnAux = -1;
    Node* pNodeAux;

    if(lista!= NULL)
    {

        if(index>=0 && index < lista->size) // VERIFICACIONES
        {
            pNodeAux=getNode(lista, index); // pNodeAux OBTIENE EL ELEMENTO EN EL NODO INDICADO POR EL INDICE
            pNodeAux->pElement=pElement; // CAMBIA EL ELEMENTO AL CUAL HACE REFERENCIA
            returnAux=0;
        }
    }
    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    int cont;
    Node* currentNode;
    Node* nextNode;
    Node* lastNode;
    if(this != NULL && index >= 0 && index < this->size)
    {
        if(index == 0)
        {
            currentNode= this->pFirstNode; // CURRENT ES EL PRIMER NODO
            nextNode= currentNode->pNextNode; // nextNode ES EL SIGUENTE NODO(currentNode->pNextNode)
            this->pFirstNode= nextNode; // el pFirstNode DE LA LISTA APUNTA A NEXT NODE, YA QUE EL PRIMER NODO ANTERIOR SERA BORRADO
            free(currentNode);
            returnAux=0;
            this->size--;
        }
        else
        {
            currentNode= this->pFirstNode; //CURRENT SE ESTABLECE COMO PRIMER NODO
            lastNode= this->pFirstNode;// lastNode SE ESTABLECE COMO PRIMER NODO (EJ NODO 0)
            currentNode= currentNode->pNextNode; // currentNode AVANZA UN NODO (EJ NODO 1
            nextNode= currentNode->pNextNode; //nextNode SE ESTABLECE COMO EL NODO SIGUIENTE A CURRENT(Ej NODO 2)

            for(cont=1; cont <= index; cont++) // SE CUENTA A PARTIR DE 1, 0 YA ESTA CUBIERTA EN EL OTRA OPCION. RECORRERA HASTA LLEGAR A nodeIndex
            {
                if(cont== index) // EJ CONT ES 1 Y INDEX ES 1
                {
                    lastNode->pNextNode= nextNode; // LAST NODE APUNTARA A NEXT NODE, DEJANDO DE DE APUNTAR A CURRENT NODE(EJ NODO 0 APUNTA A NODO 2, QUEDANDO NODO 1 FUERA)
                    free(currentNode); //SE LIBERA currentNode(EJ NODO 1)
                    returnAux=0; // OPERACION CORRECTA
                    this->size--; // SE REDUCE LA CANTIDAD DE ELEMENTOS EN LA LISTA
                    break; // SALE DEL LOOP
                }
                //SI CONT != INDEX, SE AVANZA UN NODO EN LOS AUXILIARES
                lastNode=lastNode->pNextNode; // lastNode AVANZA UN NODO ( EJ DE NODO 0 ---> NODO 1)
                currentNode=currentNode->pNextNode; // currentNode AVANZA UN NODO( EJ DE NODO 1 ---> NODO 2)
                nextNode=nextNode->pNextNode; // nextNode AVANZA UN NODO ( EJ DE NODO 2 ---> NODO 3)
            }

        }
    }


    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    Node* currentNode;
    Node* nextNode;

    if(this != NULL)
    {
        currentNode= this->pFirstNode; // currentNode ES EL PRIMER NODO( EJ currentNode= NODO 0)
        while (currentNode != NULL)
        {
            // ITERARA LA LISTA, BORRANDO ELEMENTO POR ELEMENTO
            nextNode = currentNode->pNextNode;// nextNode ES EL NODO SIGUIENTE A curretNode (EJ currentNode=NODO 1)
            free(currentNode); // SE ELIMINA CONTENIDO DE currentNode(EJ NODO 0), SE ANULA LA RESERVA DE MEMORIA(LIBERA LA MEMORIA)
            currentNode = nextNode; // curretNode AHORA ES NEXT NODE (AHJORA currentNode= NODO1)
            /* PRIMERA ITERACION
                currentNode= NODO 0
                nextNode= NODO 1
                SE ELIMINA NODO 0

               SEGUNDA ITERACION
                currentNode= NODO 1
                nextNode= NODO 2
                SE ELIMINA NODO 1

            Y ASI SUCESIVAMENTE HASTA ELIMINAR TODOS LOS NODOS
            */
        }
        this->pFirstNode = NULL;
        this->size= 0;// SE CAMBIA EL size A 0, PARA QUE TENGA 0 ELEMENTOS
        returnAux=0;
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
        ll_clear(this);
        free(this);
        returnAux= 0;
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int cont= 0;
    void* aux;
    if(this != NULL)
    {
        Node* currentNode;
        currentNode= this->pFirstNode;
        do
        {
            aux= ll_get(this, cont);
            if(aux == pElement)
            {
                returnAux= cont;
                break;
            }

            cont++;
            currentNode= currentNode->pNextNode;
        }
        while(currentNode != NULL);
    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
        if(this->size > 0)
        {
            returnAux = 0;
        }
        else if( this-> size == 0)
        {
            returnAux= 1;
        }
    }

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    int cont;

    if(this != NULL && index>=0 && index <= this->size)
    {
        if(index == this->size)
        {
            ll_add(this,pElement);// SI INDEX Y SIZE SON IGUALES, LLAMA A ADD( AGREGA AL FINAL DE LA LISTA)
            returnAux= 0;
        }
        else
        {
            Node* currentNode;
            currentNode= this->pFirstNode; // currentNode ES EL PRIMER NODO

            Node* auxNode= (Node*) malloc(sizeof(Node));
            auxNode->pElement= pElement; // SE SETEA auxNode
            auxNode->pNextNode= NULL;

            if(index == 0)
            {
                auxNode->pNextNode= currentNode;// auxNode APUNTARA a curretNode
                this->pFirstNode= auxNode;// EL PRIMER NODO DE LA LISTA SERA auxNode, auxNode seguira apuntando a current. SE ENLAZA SIN PERDER NODOS
                this->size++;
                returnAux= 0;
            }
            else
            {
                Node* lastNode;
                lastNode= this->pFirstNode; // lastNode ES PRIMER NODO(EJ NODO 0
                currentNode= lastNode->pNextNode; // current NODO ES EL NODO SIGUENTE(EJ NODO 1)
                for(cont=1; cont < this->size; cont++)
                {
                    if(cont == index)
                    {
                        lastNode->pNextNode=auxNode; // EJ NODO 0 APUNTARA A NODO AUXILIAR
                        auxNode->pNextNode= currentNode; // NODO AUXILIAR(AHORA NODO 1) APUNTARA A currentNode(AHORA ES NODO 2)
                        this->size++;
                        returnAux= 0;
                        break;
                    }
                    lastNode=lastNode->pNextNode; // SI cont != index, LOS AUXILIARES AVANZAN UN NODO Y SE ITERA
                    currentNode= currentNode->pNextNode;
                }
            }
        }

    }

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    int cont;
    if(this != NULL && index>=0 && index <= this->size)
    {
        Node* currentNode;
        currentNode= this->pFirstNode;
        for(cont=0; cont < this->size; cont++)
        {
            if(cont == index)
            {
                returnAux= ll_get(this, cont);
                ll_remove(this, cont);
            }
            currentNode= currentNode->pNextNode; // AVANZA UN NODO
        }
    }

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int cont=0;

    if(this != NULL)
    {
        void* aux;
        Node* currentNode;
        currentNode= this->pFirstNode;
        returnAux = 0;
        for(cont=0; cont <= this->size; cont++)
        {
            aux= ll_get(this, cont);
            if(cont == this->size)
            {
                returnAux = 0;
                break;
            }
            else if( aux == pElement)
            {
                returnAux= 1;
                break;

            }
            currentNode= currentNode->pNextNode; // AVANZA UN NODO
        }

    }




    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int cont=0;

    if(this != NULL && this2 != NULL) // COMPROBACION
    {
        if(this == this2) // SI LAS LISTAN SON IGUALES..
        {
            returnAux= 1;
        }

        if(this->size <= this2->size ) //COMPRUEBA TAMANIO DE LISTAS
        {
            void* auxThis;
            void* auxThis2;

            for(cont=0; cont < this2->size; cont++)
            {
                auxThis= ll_get(this, cont);
                auxThis2= ll_get(this2, cont);
                /** COMPARACION **/
                if( auxThis == auxThis2)
                {
                    returnAux= 1;
                }
                else
                {
                    returnAux= 0;
                    break;
                }

            }
        }
    }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    void* pAux;

    int cont = 0;
    int listSize= ll_len(this);
    if(this != NULL )
    {
        if(from >= 0 && from < listSize && to > from && to <= listSize) //VERIFICACIONES
        {
            cloneArray= ll_newLinkedList();
            for(cont=from; cont<= to; cont++)
            {
                pAux= ll_get(this, cont); // OBTIENE ELEMENTO DE INDICE INDICADO POR CONT
                ll_add(cloneArray, pAux); // Y LO AGREGA A LA NUEVA LISTA, UNO POR UNO

            }

        }
    }

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    if(this != NULL)
    {
        cloneArray = ll_subList(this, 0, ll_len(this)); // CREA UNA SUBLISTA DE NODO 0 HASTA EL FINAL DE THIS
    }

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void*, void*), int order)
{
    int returnAux= -1;
    if(this != NULL && (*pFunc) != NULL && (order == 0 || order == 1 )) // COMPRUEBA CONDICIONES
    {
        Node* aux1;
        Node* aux2;
        void* auxTemp;
        int funcReturn;
        int i,j;

        int len= ll_len(this);

        if(order == 1)
        {
            /** ORDENAMIENTO **/
            for(i=0; i<len-1; i++)
            {
                for(j=i+1; j<len; j++)
                {
                    aux1= getNode(this, i);
                    aux2= getNode(this, j);
                    funcReturn= pFunc(aux1->pElement, aux2->pElement);
                    if(funcReturn == 1)
                    {
                        /**  SWAP DE ELEMENTOS***/
                        auxTemp = aux1->pElement;
                        aux1->pElement= aux2->pElement;
                        aux2->pElement= auxTemp;
                    }
                }
            }
            returnAux= 0;
        }

        else if(order == 0)
        {
            for(i=0; i<len -1; i++)
            {
                for(j=i+1; j<len; j++)
                {
                    aux1= getNode(this, i);
                    aux2= getNode(this, j);
                    funcReturn= pFunc(aux1->pElement, aux2->pElement);
                    if(funcReturn == -1)
                    {
                        auxTemp = aux1->pElement;
                        aux1->pElement= aux2->pElement;
                        aux2->pElement= auxTemp;
                    }
                }
            }
            returnAux= 0;

        }
    }

    return returnAux;
}

LinkedList* H_Filter(LinkedList* this, int (*pFuncion) (LinkedList* ,int index, int argument), int argument )
{
    LinkedList* listaFiltrada = NULL; // DECLARA LISTA NUEVA

    int i;
    int len = ll_len(this); // TOMA EL TAMANIO DE THIS
    void* aux;
    if(this != NULL && pFuncion != NULL && len > 0) // COMPRUEBA QUE THIS, EL PUNTERO A LA FUNCION NO SEAN NULOS Y LEN MAYOR A 0
    {

        listaFiltrada = ll_newLinkedList(); // RESERVA MEMORIA PARA LA LISTA
        if(listaFiltrada != NULL)
        {
            for(i=0; i<len; i++) // RECORRE LA LISTA
            {
                aux = ll_get(this, i); // GUARDA EN AUXILIAR EL RETURN DE ll_get
                if(pFuncion(this, i, argument) == 1) // ENVIA A LA FUNCION EL NODO SI AL VOLVER DE ESA FUNCION EL RESULTADO ES POSITIVO SE GUARDA EN LA LISTA FILTRADA
                {
                    // EL CRITERIO PUEDE CAMBIAR SEGUN LA FUNCION
                    ll_add(listaFiltrada, aux);
                }
            }
        }

    }
    return listaFiltrada;
}
int ll_map(LinkedList* this, int (*pFuncion)(void*) )
{
    int returnAux= -1;
    void* aux;
    int i;
    int listLen= ll_len(this);
    if(this != NULL && pFuncion != NULL)
    {
        for(i=0; i < listLen; i++)
        {
            aux= ll_get(this, i);
            returnAux= pFuncion(aux);
            /*
             if( returnAux == 0)
                {
                    printf("OK %d!!!\n", i);
                }
                */
        }
    }


    return returnAux;
}

