#include "../headers/zad1.h"
#include <cstdlib>
#include <time.h>
#include <iostream>

using namespace std;

int** Zad1::numberGenerator(int& rangeSize, int** tab) {
    srand(time(0)); // current time as a seed for generating numbers, prevent repetable numbers

    for(int i = 0; i < rowSize; i++) {
        for(int j = 0; j < columnSize; j++) {
            tab[i][j] = rand() % (rangeSize + 1);
        }
    }

    return tab;
}

int** Zad1::tabGenerator(int& rowSize, int& columnSize) {
    int **tab = new int*[columnSize];
    for (int i = 0; i < rowSize; i++) {
        tab[i] = new int[columnSize];
    }

    return tab;
}

Zad1::Zad1(int n, int m) {
    columnSize = n;
    rowSize = m;

    tabGenerator(rowSize, columnSize);
}

Zad1::~Zad1() {
    for(int i = 0; i < columnSize; i++) {
        delete [] tab[i];
    }
    delete [] tab;
}

void Zad1::displayTab(int const &rowSize, int const &columnSize) {
    for(int i = 0; i < columnSize; i++) {
        for(int j = 0; j < rowSize; j++) {
            cout << tab[i][j] << " ";
        }
        cout << endl;
    }
}

int maxValue(int const &rowSize, int const &columnSize) {
    int max = 0;
    for(int i = 0; i < columnSize; i++) {
        for(int j = 0; j < rowSize; j++) {
            if(max < tab[i][j]) {
                max = tab[i][j];
            }
        }
    }
    cout << "Najwiszka liczba w tablicy to: " << max << endl;

    return max;
}