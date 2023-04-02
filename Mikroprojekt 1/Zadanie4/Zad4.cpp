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
    if (!rest.length()) {
        if (isPal(prefix, 0, prefix.size() - 1)) {
            tab[place] = prefix;
            place++;
        }
        return;
    }

    for (int i = 0; i < rest.size(); i++) {
        std::string newPrefix = prefix + rest[i];
        std::string newRest = rest.substr(0, i) + rest.substr(i + 1);
        genPerm(newPrefix, newRest);
    }
}

void Zad4::displayTab()
{
    for (int i = 0; i < 720; i++) {
        std::cout << tab[i] << " ";
    }
}

void Zad4::deleteDup()
{
    for (int i = 0; i < 719; i++) {
        for (int j = i + 1; j < 720; j++) {
            if (tab[i] == tab[j]) {
                tab[j] = "";
            }
        }
    }
}
