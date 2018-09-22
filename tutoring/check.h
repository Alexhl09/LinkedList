// Alejandro Hernández López
// A00822926
//  check.h
// Exmaen parcial 1


#ifndef check_h
#define check_h
#include "LinkedList.h"
/*
 Nombre: check
 Descripción: Revisa que existala cantidad de elementos que dice la variable size, en caso contrario actualiza la variable size
 Parametros: Nada
 Return: Regresa un booleano si esta bien el size, con respecto a la cantidad de elementos en la lista
 */
template <class T>
bool LinkedList<T>::check()
{
    
    int contador = 0;
    Node<T>* t1 = head;
    while(t1 != nullptr)
    {
        contador++;
        t1 = t1->getNext();
    }
    if(contador == size)
    {
        return true;
    }
    else
    {
        this->size = contador;
        return false;
        
    }
}

#endif /* check_h */
