#include "Zad1.h"
#include <cstdlib>
#include <time.h>
#include <iostream>

using namespace std;

void Zad1::numberGenerator(int rangeSize)
{
    srand(time(0)); // current time as a seed for generating numbers, prevent repeat numbers

    for (int i = 0; i < columnSize; i++)
    {
        for (int j = 0; j < rowSize; j++)
        {
            tab[i][j] = rand() % (rangeSize + 1);
        }
    }
}

Zad1::Zad1(int n, int m)
{
    columnSize = m;
    rowSize = n;

    tab = new int* [columnSize];
    for (int i = 0; i < columnSize; i++)
    {
        tab[i] = new int[rowSize];
    }
}

Zad1::~Zad1()
{
    for (int i = 0; i < columnSize; i++)
    {
        delete[] tab[i];
    }
    delete[] tab;
}

void Zad1::displayTab()
{
    for (int i = 0; i < columnSize; i++)
    {
        for (int j = 0; j < rowSize; j++)
        {
            cout << tab[i][j] << " ";
        }
        cout << endl;
    }
}

void Zad1::maxValue()
{
    int max = 0;
    for (int i = 0; i < columnSize; i++)
    {
        for (int j = 0; j < rowSize; j++)
        {
            if (max < tab[i][j])
            {
                max = tab[i][j];
            }
        }
    }
    cout << "Najwiszka liczba w tablicy to: " << max << endl;
}