#include "Zad3.h"

Zad3::Zad3(int factorial, int base, int exp) {
    factorial = factorial;
    base = base;
    exp = exp;
}

int Zad3::factorial(int num)
{
    if (num == 0 || num == 1)
        return 1;
    else
        return num * factorial(num - 1);
}

int Zad3::power(int base, int exp)
{
    if (exp > 0)
        return base * power(base, exp - 1);
    else
        return 1;
}
