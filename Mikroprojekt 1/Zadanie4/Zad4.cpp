#include "Zad4.h"
#include <iostream>

bool Zad4::isPal(std::string str, int begin, int end)
{
    if(begin >= end) // większy w momencie gdy wyraz jest parzysty, równy gdy wyraz ma nieparzystą ilość znaków
        return true;

    if (str[begin] != str[end])
        return false;

    return isPal(str, begin + 1, end - 1);
}

void Zad4::genPerm(std::string prefix, std::string rest)
{
    int place = 0;

    for (int i = 0; i < rest.size(); i++) {
        prefix = prefix + rest[i];
        rest = rest.substr(0, i) + prefix + rest.substr(i + 1);

        if (isPal(prefix, 0, prefix.size() - 1)) {
            tab[place] = prefix;
            place++;
        }
        return;

        return genPerm(prefix, rest);
    }
}

void Zad4::displayTab()
{
    for (int i = 0; i < 720; i++) {
        std::cout << tab[i] << " ";
    }
}
