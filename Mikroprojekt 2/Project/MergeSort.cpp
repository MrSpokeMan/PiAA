#include "MergeSort.h"
#include <iostream>

void MergeSort::merge(std::vector<Ranking>& Tab, int begin, int mid, int end) {
    int n1 = mid - begin + 1;
    int n2 = end - mid;
    std::vector<Ranking> L(n1), R(n2);
    for (int i = 0; i < n1; i++) {
        L[i] = Tab[begin + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = Tab[mid + 1 + j];
    }
    int i = 0, j = 0, k = begin;
    while (i < n1 && j < n2) {
        if (L[i].pos <= R[j].pos) {
            Tab[k] = L[i];
            i++;
        }
        else {
            Tab[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        Tab[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        Tab[k] = R[j];
        j++;
        k++;
    }
}

void MergeSort::mergeSort(std::vector<Ranking>& Tab, int begin, int end) {
    if (begin < end) {
        int mid = begin + (end - begin) / 2;
        mergeSort(Tab, begin, mid);
        mergeSort(Tab, mid + 1, end);
        merge(Tab, begin, mid, end);
    }
}