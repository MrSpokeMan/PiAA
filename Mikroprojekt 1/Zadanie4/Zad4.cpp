#include "Zad4.h"

Zad4::Zad4(std::string str) {
    this->str = str;
}

bool Zad4::isPal()
{
    for (int i = 0; i < str.size() / 2; i++) {
        if (str[i] != str[str.size() - i - 1]) {
            return false;
        }
    }
    return true;
}
