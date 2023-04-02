#include <iostream>
#include "Zad4.h"

int main()
{
    Zad4* zad = new Zad4();
    std::string str = "123321";
    //std::cout << zad->isPal(str, 0, str.size() - 1);
    zad->genPerm("", str);
    zad->displayTab();
    zad->deleteDup();
    std::cout << std::endl;
    zad->displayTab();
}
