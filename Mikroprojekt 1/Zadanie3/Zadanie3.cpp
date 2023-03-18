#include <iostream>
#include "Zad3.h"

int main()
{
    Zad3 zad(5, 2, 10);
    std::cout << zad.factorial(5);
    std::cout << std::endl;
    std::cout << zad.power(2, 10);
}