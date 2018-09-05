
template <class T>
class Node
{
public:
    Node(T data);
    Node(T data, Node<T> *next);
    T getData();
    Node<T>* getNext();
    void setData(T data);
    void setNext(Node<T> * next);
private:
    T data;
    Node<T> *next;
};

	template <class T>
	Node<T>::Node(T data)
	{
		this->data = data;
		this->next = nullptr;
	}
	
	template <class T>
	Node<T>::Node(T data, Node<T> * next)
	{
		this->data = data;
		this->next = next;
	}
	
	template <class T>
	void Node<T>::setData(T data)
	{
		this->data = data;
	}
	
	template <class T>
	void Node<T>::setNext(Node<T> * next)
	{
		this->next = next;
	}
	
	template <class T>
    T Node<T>::getData(){return this->data;}
	
	template <class T>
	Node<T>* Node<T>::getNext(){return this->next;}
	
/*
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
 */
