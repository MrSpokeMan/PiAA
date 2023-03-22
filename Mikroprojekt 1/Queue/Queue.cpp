#include <iostream>
#include "QueDs.h"

int main()
{
    QueDs kolejka = QueDs();

    for (int i = 0; i < 10; i++) {
        kolejka.add(i);
    }
    kolejka.display();

    kolejka.remove();
    kolejka.display();

    kolejka.removeAll();
    kolejka.display();
}