#include "../headers/zad1.h"
#include <cstdlib>
#include <time.h>

Zad1::Zad1(int n, int m, int range) {
    columnSize = n;
    rowSize = m;
    rangeSize = range;

    float **tab = new float*[rowSize];
    for (int i = 0; i < rowSize; i++) {
        tab[i] = new float[columnSize];
    }

    srand(time(0)); // current time as a seed for generating numbers, prevent repetable numbers

    for(int i = 0; i < rowSize; i++) {
        for(int j = 0; j < columnSize; j++) {
            tab[i][j] = rand() % rangeSize;
        }
    }
}