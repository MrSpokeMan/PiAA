#include "../header/zad1.h"
#include <cstdlib>

Zad1::Zad1(int n, int m, int range) {
    columnSize = n;
    rowSize = m;
    rangeSize = range;

    float **tab = new float*[rowSize];
    for (int i = 0; i < rowSize; i++) {
        tab[i] = new float[columnSize];
    }
}