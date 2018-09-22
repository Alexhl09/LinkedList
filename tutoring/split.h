// Alejandro Hernández López
// A00822926
//  split.h
// Exmaen parcial 1

#ifndef split_h
#define split_h
#include "LinkedList.h"
/*
 Nombre: split
 Descripción: Divide a la LinkedList original, dejandola con los primeros n elementos
 Parametros: n (int) nuemero de elementosque se queda en la LinkedList original
 Return: Regresa una lista con los elementos restantes
 */
template <class T>
LinkedList<T> LinkedList<T>::split(int n)
{
    LinkedList<T> nueva;
    if(n < size && n != 0)
    {
        
        Node<T>* t1 = head;
        Node<T>* t2 = head->getNext();
     
        for(size_t i = 0; i < n - 1; i++)
        {
            t1 = t1->getNext();
            t2 = t2->getNext();
        }
        t1->setNext(nullptr);
        nueva.head = t2;
        nueva.size = size - n;
        size = n;
    }else if(n == 0)
    {
        nueva = *this;
        this->deleteAll();
    }
    return nueva;
}

#endif /* split_h */
