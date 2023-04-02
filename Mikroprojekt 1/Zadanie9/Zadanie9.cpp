#include <iostream>
#include "Deque.h"

int main()
{
    Deque deque;

    deque.addFirst(1);
    deque.addFirst(2);
    deque.addLast(3);
    deque.addLast(4);

    std::cout << "Pierwszy element: " << deque.first() << std::endl;
    std::cout << "Ostatni element: " << deque.first() << std::endl;
    std::cout << "Rozmiar: " << deque.Size() << std::endl;
    deque.deleteFirst();
    deque.deleteLast();
    std::cout << "Pierwszy element: " << deque.first() << std::endl;
    std::cout << "Ostatni element: " << deque.last() << std::endl;
    std::cout << "Rozmiar: " << deque.Size() << std::endl;
    std::cout << "Czy kolejka jest pusta? " << deque.isEmpty() << std::endl;

    return 0;
}