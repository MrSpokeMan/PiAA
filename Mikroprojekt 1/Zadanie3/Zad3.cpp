#include "Zad3.h"

Zad3::Zad3(int factor, int base, int exp) {
    this->factor = factor;
    this->base = base;
    this->exp = exp;
}

int Zad3::factorial(int factor)
{
    if (factor == 0 || factor == 1)
        return 1;
    else
        return factor * factorial(factor - 1);
}

int Zad3::power(int base, int exp)
{
    if (exp > 0)
        return base * power(base, exp - 1);
    else
        return 1;
}
