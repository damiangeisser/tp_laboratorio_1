#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

//Crea un nuevo LinkedList en memoria de manera dinamica
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

//Retorna la cantidad de elementos de la lista
int ll_len(LinkedList* this)
{

    int returnAux = -1;
    if(this!=NULL)
    {
        returnAux=this->size;
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
    Node* pNode =NULL;

    if(this!=NULL && nodeIndex >= 0 && nodeIndex < ll_len(this))
    {
        pNode = this->pFirstNode;

        for(int i =0; i<nodeIndex; i++)
        {
            pNode = pNode->pNextNode;
        }
    }

    return pNode;
}

// Permite realizar el test de la funcion getNode la cual es privada
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}

static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;

    Node* prev;
    Node* next;
    Node* nuevoNodo;

    if( this != NULL)
    {
        if(nodeIndex >= 0 && nodeIndex <= ll_len(this))
        {
            nuevoNodo = (Node*)malloc(sizeof(Node));
            if(nuevoNodo != NULL)
            {
                nuevoNodo->pElement = pElement;
                nuevoNodo->pNextNode = NULL;

                if(nodeIndex == 0)
                {
                    nuevoNodo->pNextNode = this->pFirstNode;
                    this->pFirstNode = nuevoNodo;
                }
                else
                {
                    prev = this->pFirstNode;
                    next = prev->pNextNode;

                    while( nodeIndex > 1)
                    {
                        prev  = next;
                        next  = prev->pNextNode;
                        nodeIndex--;
                    }

                    prev->pNextNode = nuevoNodo;
                    nuevoNodo->pNextNode = next;
                }
                this->size++;
                returnAux = 0;
            }
        }
    }

    return returnAux;
}

// Permite realizar el test de la funcion addNode la cual es privada
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}

// Agrega un elemento a la lista
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this!=NULL)
    {

        returnAux = addNode(this,ll_len(this),pElement);
    }

    return returnAux;
}

void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;

    if(this!=NULL && index>=0 && index < ll_len(this))
    {
        if(index==0)
        {
            returnAux = this->pFirstNode->pElement;
        }
        else
        {
            returnAux=getNode(this,index)->pElement;
        }
    }
    return (void*)returnAux;
}

// Modifica un elemento de la lista
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* nodoAux = NULL;

    if(this != NULL && index >=0 && index < ll_len(this) )
    {
        nodoAux = getNode(this,index);

        if(nodoAux != NULL)
        {
            nodoAux->pElement = pElement ;
        }
        returnAux=0;
    }

    return returnAux;
}

// Elimina un elemento de la lista

int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;

    Node* prev;
    Node* next;

    if(this != NULL)
    {
        if(index >= 0 && index < ll_len(this))
        {
            if(index==0)
            {
                next=getNode(this, (index+1));
                this->pFirstNode=next;

            }
            else
            {
                prev=getNode(this, (index-1));
                next=getNode(this, (index+1));
                prev->pNextNode=next;
            }

            this->size--;
            returnAux = 0;
        }
    }


    return returnAux;
}

// Elimina todos los elementos de la lista
int ll_clear(LinkedList* this)
{
    int returnAux = -1;

    if(this!=NULL)
    {

        for(int i=0; i<ll_len(this); i++)
        {
            returnAux=ll_remove(this,i);
        }
    }
    return returnAux;
}
// Elimina todos los elementos de la lista y la lista
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(this!=NULL)
    {

        returnAux=ll_clear(this);

        free(this);
    }

    return returnAux;
}

//Busca el indice de la primer ocurrencia del elemento pasado como parametro

int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    void* elementAux;

    if(this!=NULL)
    {

        for(int i=0; i<ll_len(this); i++)
        {
            elementAux=ll_get(this,i);

            if(elementAux==pElement)
            {
                returnAux=i;
            }
        }
    }
    return returnAux;
}

//Indica si la lista esta o no vacia

int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if(this!=NULL)
    {
        if(ll_len(this)==0)
        {
            returnAux=1;
        }
        else
        {
            returnAux=0;
        }
    }
    return returnAux;
}

// Inserta un nuevo elemento en la lista en la posicion indicada

int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;

    Node* prev;
    Node* next;
    Node* nuevoNodo;

    if( this != NULL)
    {
        if(index >= 0 && index <= ll_len(this))
        {
            nuevoNodo = (Node*)malloc(sizeof(Node));
            if(nuevoNodo != NULL)
            {
                nuevoNodo->pElement = pElement;
                nuevoNodo->pNextNode = NULL;

                if(index == 0)
                {
                    nuevoNodo->pNextNode = this->pFirstNode;
                    this->pFirstNode = nuevoNodo;
                }
                else
                {
                    prev = this->pFirstNode;
                    next = prev->pNextNode;

                    while( index > 1)
                    {
                        prev  = next;
                        next  = prev->pNextNode;
                        index--;
                    }

                    prev->pNextNode = nuevoNodo;
                    nuevoNodo->pNextNode = next;
                }
                this->size++;
                returnAux = 0;
            }
        }
    }

    return returnAux;
}


// Elimina el elemento de la posicion indicada y retorna su puntero

void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;

    if(this!=NULL && index>=0 && index < ll_len(this))
    {
        returnAux=getNode(this,index)->pElement;
        ll_remove(this,index);
    }

    return returnAux;
}

// Determina si la lista contiene o no el elemento pasado como parametro

int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this!=NULL)
    {
        if(ll_indexOf(this,pElement)==-1)
        {
            returnAux=0;
        }
        else
        {
            returnAux=1;
        }
    }

    return returnAux;
}

//Determina si todos los elementos de la lista (this2)

int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int flagNoHallado = 0;
    int flagDiferente = 0;
    int indexAux;
    void* elementAux;

    if(this!=NULL && this2!=NULL)
    {
        returnAux=1;

        for(int i=0; i<ll_len(this); i++)
        {
            elementAux=ll_get(this, i);

            indexAux=ll_indexOf(this2,elementAux);

            if(indexAux==-1)
            {
                flagNoHallado = 1;
            }
            else if(indexAux!=i)
            {
                flagDiferente = 1;
            }
        }
    }

    if(flagDiferente)
    {
        returnAux=0;
    }

    if(flagNoHallado)
    {
        returnAux=-1;
    }

    return returnAux;
}

//Crea y retorna una nueva lista con los elementos indicados

LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;

    void* pElementAux = NULL;

    if(this !=NULL && from >= 0 && to <= ll_len(this))
    {
        cloneArray = ll_newLinkedList();

        if ( cloneArray != NULL )
        {
            for(int i = from; i<=to; i++)
            {
                pElementAux=ll_get(this, i);

                if (pElementAux != NULL )
                {
                    ll_add(cloneArray,pElementAux);
                }
            }
        }
    }
    return cloneArray;
}
//Crea y retorna una nueva lista con los elementos de la lista pasada como parametro

LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;


    cloneArray = ll_subList(this,0,ll_len(this));


    return cloneArray;
}

// Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro

int ll_sort(LinkedList* this, int (*pFunc)(void*,void*), int order)
{
    int returnAux =-1;

    void* pElementAux1;
    void* pElementAux2;
    void* pElementAux3;
    int comparacion;

    if(this != NULL && pFunc!=NULL && (order==0 || order==1 ))
    {
        for(int i = 0; i<ll_len(this); i++)
        {
            for(int j=i+1; j<ll_len(this); j++)
            {
                pElementAux1=ll_get(this, i);
                pElementAux2=ll_get(this, j);

                comparacion=pFunc(pElementAux1,pElementAux2);

                if(order==1 && comparacion== 1)//Ascendente
                {
                    pElementAux3=pElementAux1;
                    ll_set(this, i, pElementAux2);
                    ll_set(this, j, pElementAux3);
                }
                if(order==0 && comparacion==-1)//Descendente
                {
                    pElementAux3=pElementAux1;
                    ll_set(this, i, pElementAux2);
                    ll_set(this, j, pElementAux3);
                }
            }
        }
        returnAux=0;
    }

    return returnAux;
}

