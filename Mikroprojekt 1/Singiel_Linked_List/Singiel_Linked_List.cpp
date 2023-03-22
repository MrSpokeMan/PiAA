#include <iostream>
#include "List.h"

int main()
{
    List lista = List();

    for (int i = 0; i < 10; i++) {
        lista.addElement(i);
    }
    lista.displayList();

    lista.removeElement(5);
    lista.displayList();

    lista.removeAll();
    lista.displayList();
}