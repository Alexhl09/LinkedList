
#include "Node.h"
#include <iostream>
template <class T>
class LinkedList
{
    
public:
    LinkedList();
    LinkedList(LinkedList<T> const &);
    ~LinkedList();
    bool isEmpty();
    void addFirst(T data);
    void addLast(T data);
    void deleteFirst(void);
	void deleteLast(void);
	bool add(T data, int pos);
	int deleteAll();
	void del(int);
    T get(int);
    T set(T,int);
	int getSize(){return size;}
    bool change(int, int);
	void print(void);
    void reverse(void);
    bool operator == (LinkedList<T> const &);
	void operator = (LinkedList<T>const &);
    void operator+= (T);
    void operator += (LinkedList<T>const &);
    void shift(int);
    void spin(int);
private:
    Node<T> *head;
    int size;
	void borraTodo();
};
	

	template <class T>
	LinkedList<T>:: LinkedList()
	{
		head = nullptr;
		size = 0;
	}
    template <class T>
    LinkedList<T>::LinkedList(LinkedList<T> const &objeto)
    {
        Node<T> * node = objeto.head;
        head = nullptr;
        size = 0;
        for(int i = 0; i < objeto.size; i++)
        {
            this->addLast(node->getData());
            node = node->getNext();
        }
   
    }
	template<class T>
	void LinkedList<T> :: borraTodo()
	{
	  Node<T>* c = head;
        
        while(head != nullptr)
        {
        
                head = head->getNext();
                delete c;
                c = head;
        }
               
    }
	template<class T>
	LinkedList<T>::~LinkedList()
	{
		borraTodo();
	}

	template <class T>
	bool LinkedList<T>::isEmpty()
	{
		return (size == 0);
	}
	
	template <class T>
	void LinkedList<T>::addFirst(T data)
	{
		head = new Node<T>(data, head);
		size++;
	}
	
	template <class T>
	void LinkedList<T>::addLast(T data)
	{
		if(this->isEmpty())
		{
			this->addFirst(data);
		}else 
		{
			Node<T>* c = head;
			while(c->getNext() != nullptr)
			{
				c = c->getNext();
			}
			c->setNext(new Node<T>(data));
			size++;
		}
	}
	template<class T>
	void LinkedList<T>::deleteFirst()
	{
		if(!this->isEmpty())
		{
			Node<T> *c = head;
			head = head->getNext();
			delete c;
			size--;
		}	
	}

	template<class T>
	void LinkedList<T>::deleteLast()
	{
		if(this->size <= 1)
		{
		}else
		{
			Node<T> *c = head;
			while(c->getNext()->getNext() != nullptr)
			{
				c = c->getNext();
			}
			delete c->getNext();
			c->setNext(nullptr);
			size--;
		}
	}
	template<class T>
	bool LinkedList<T>::add(T data, int pos)
	{
		if(pos > size)
		{
			return false;
		}
		else if(pos == 0)
		{
			addFirst(data);
		}else if(pos == size)
		{
			addLast(data);
		}
		else
		{
			Node<T>* c = head;
			for(int i = 1; i < pos; i++)
			{
				c = c->getNext();
			}
			c->setNext(new Node<T>(data,c->getNext()));
			size++;
		}
		return true;
	}
	template<class T>
	int LinkedList<T>::deleteAll()
	{
	borraTodo();
		int iCant = size;
		size = 0;
		return iCant;
	}
	template<class T>
	void LinkedList<T>::del(int pos)
	{
		if(pos == 0)
		{
			deleteFirst();
		}
		else if(pos == size - 1)
		{
			deleteLast();
		}
		else
		{
		Node<T>* c = head;
		for(int i = 1; i < pos; i++)
		{
			c = c->getNext();
		}
		Node<T>* t = c->getNext();
		c->setNext(t->getNext());
		delete t;
		size--;
		}	
	}
	
template <class T>
T LinkedList<T>::get(int posicion)
{
    if(posicion < this->size)
    {
        Node<T>* temp = head;
        for(int i = 0; i < posicion; i++)
        {
            temp = temp->getNext();
        }
        return temp->getData();
    }
    return 0;
    
}

template <class T>
T LinkedList<T>::set(T objeto, int posicion)
{
    if(posicion < this->size)
    {
        Node<T>* temp = head;
        for(int i = 0; i < posicion; i++)
        {
            temp = temp->getNext();
        }
	T data = temp->getData();
        temp->setData(objeto);
	return data;
    }
    return 0;
}

template <class T>
bool LinkedList<T>::change(int pos1, int pos2)
{
    if((pos1 < this->size && pos1 >= 0) && (pos2>= 0 && pos2 < this->size))
    {
    	Node<T>* temp1 = head;
    	
  
    	int posMen = (pos1 < pos2 ? pos1 : pos2);
	int posMay = (pos1 > pos2 ? pos1 : pos2);
	
	for(int i = 0; i < posMen; i++)
	{
		temp1 = temp1->getNext();
	}
	Node<T>* temp2 = temp1;
	for(int i = posMen; i < posMay; i++)
	{
		temp2 = temp2->getNext();
	}
    	T temp = temp1->getData();
    	temp1->setData(temp2->getData());

    	temp2->setData(temp);


    	}else if(pos1 == pos2)
	{
		return true;
	}
    	return false;
   
}
template <class T>
void LinkedList<T>:: print()
{
	std::cout << "INICIO" << std::endl;
	Node<T> *c = head;
	while(c != nullptr)
	{
	std::cout << c->getData() << " ";
	c = c->getNext();
	}
	std::cout << std::endl << "FIN\n";
}
template <class T>
void LinkedList<T>::reverse()
{
    Node<T> * c1 = head;
    Node<T> * c2 = head->getNext();
    head->setNext(nullptr);
    if(size > 1)
    {
        
        while(c2 != nullptr)
        {
            head = c2;
            c2 = c2->getNext();
            head->setNext(c1);
            c1 = head;
        }
    }
}
template <class T>
bool LinkedList<T>::operator==(LinkedList<T> const &objeto)
{
    bool iguales = false;
    if(this->getSize() != objeto.size)
    {
        return false;
    }

    Node<T>* c1 = head;
    Node<T>* c2 = objeto.head;
    for(size_t i = 0; i < this->getSize(); i++)
    {
        
        if(c1->getData() != c2->getData())
        {
            std::cout << i << std::endl;
            return false;
        }
        c1 = c1->getNext();
        c2 = c2->getNext();
    }
    return true;
}
template <class T>
void LinkedList<T>::operator = (LinkedList<T> const &objeto)
{
  
    this->borraTodo();
    Node<T> * c = objeto.head;
    for(size_t i = 0; i < objeto.size; i++)
    {
        this->addLast(c->getData());
        c = c->getNext();
    }
    
}
template <class T>
void LinkedList<T>::operator += (T objeto)
{
    Node<T>* node = head;
    while(node->getNext() != nullptr)
    {
        node = node->getNext();
    }
    node->setNext(new Node<T>(objeto));
    size++;

}
template< class T>
void LinkedList<T>::operator += (LinkedList<T> const & objeto)
{
    Node<T>* temp = objeto.head;
    for(size_t i = 0; i < objeto.size; i++)
    {
        *this += (temp->getData());
        temp = temp->getNext();
    }
    
    
}
template< class T>
void LinkedList<T>::shift(int veces)
{
   
    if(veces < 1)
    {
        veces = veces * -1;
         int valor = veces % size;
    Node<T> * temp = head;
    for(size_t i = 0; i < valor; i++)
    {
        this->addLast(temp->getData());
        this->deleteFirst();
        temp = temp->getNext();
    }
    }
    else
    {
        
        Node<T> * temp = head;
        Node<T> * inicial = head;
        int valor = veces % size;
        for(size_t i = 0; i < size - valor - 1 ; i++)
        {
            temp = temp->getNext();
        }
        std::cout << temp->getData() << std::endl;
        head = temp->getNext();
        
        temp->setNext(nullptr);
        
         Node<T> * temp1 = head;
        while(temp1->getNext() != nullptr)
        {
            temp1 = temp1->getNext();
        }
        temp1->setNext(inicial);
//        head = temp;
//        while(temp->getNext() != nullptr)
//        {
//            temp = temp->getNext();
//        }
//        temp->setNext(head);
        
    }
}

template< class T>
void LinkedList<T>::spin(int veces)
{
    if(veces >= this->size)
    {
        this->reverse();
    }
    else
    {
        if(size > 1 && veces > 1)
        {
            Node<T> * c1 = head;
            Node<T> * c2 = head->getNext();
            Node<T> * c3 = head;
            //inicial
            Node<T> * c4 = head;
            Node<T> * c5 = head;
            head->setNext(nullptr);
            for(size_t i = 0; i < veces - 1;i++)
            {
                head = c2;
                c2 = c2->getNext();
                head->setNext(c1);
                c1 = head;
               
            }
         
            
         
            
          
     
            //c3 es head
            c3 = c2;
            c1 = c3;
            c2 = c2->getNext();
            
            for(size_t i = 0; i < (size / veces) - 1  ;i++)
            {
                
                
              
                c3->setNext(nullptr);
                c5 = c3;
                for(size_t i = 0; i < veces - 1;i++)
                {
                    
                    c3 = c2;
                    if(c2->getNext() != nullptr)
                    c2 = c2->getNext();
                    c3->setNext(c1);
                    c1 = c3;
                 
                }
                
                c4->setNext(c3);
                c4 = c5;
                
               
                c3 = c2;
                c1 = c3;
                c2 = c2->getNext();
               
               
 
            }
            if(size % veces > 0)
            {
                c3->setNext(nullptr);
                c5 = c3;
                for(size_t i = 0; i < (size % veces) - 1; i++)
                {
                    c3 = c2;
                    if(c2->getNext() != nullptr)
                        c2 = c2->getNext();
                    c3->setNext(c1);
                    c1 = c3;
                }
                 c4->setNext(c3);
            }
//            c3->setNext(nullptr);
            
            
            
            
           
            
            
        }
    }
        
}
//        LinkedList<T> temp;
//        LinkedList<T> tempTotal;
//        int contador = 0;
//        for(size_t j = 0; j < size  - veces + 1 ; j += veces)
//        {
//        for(size_t i = 0; i < veces ; i++)
//        {
//            temp.addFirst(this->get(contador));
//            contador++;
//        }
//        tempTotal += temp;
//        temp.deleteAll();
//        }
//
//        int c = contador;
//
//        for(size_t i = 0; i < size - c; i++)
//        {
//             temp  += this->get(contador);
//            contador++;
//        }
//
//        temp.reverse();
//        tempTotal += temp;
//
//        this->deleteAll();
//        *this = tempTotal;
//
