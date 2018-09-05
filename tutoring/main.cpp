#include "LinkedList.h"
#include <iostream>
#include <string>

using namespace std;
int main()
{
    LinkedList<string> miLista;
    LinkedList<string> miO;
   
    miLista.addLast("A");
    miLista.addLast("B");
    miLista.addLast("C");
    miLista.addLast("D");
    miLista.addLast("E");
    miLista.addLast("F");
    miLista.addLast("G");
    miLista.addLast("H");
    miLista.addLast("I");
    miLista.addLast("J");
    miLista.addLast("K");
    miLista.addLast("L");
    miLista.print();
  
    
    miLista.spin(3);

    miLista.print();
    LinkedList<string> m(miO);
    
 
    
    
}

