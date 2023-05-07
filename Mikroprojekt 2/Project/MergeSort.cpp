#include "MergeSort.h"
#include <iostream>

void MergeSort::merge(std::vector<Ranking> Tab, int begin, int pivot, int end)
{
    std::vector<Ranking> tmp = ranking;
    for (int i = 0; i < tmp.size(); i++)
        std::cout << tmp.at(i).title << std::endl;
    int begin1 = begin;
    int begin2 = pivot + 1;
    int current = begin;

    while (begin1 <= pivot && begin2 <= end) {
        if (tmp.at(begin1).pos <= tmp.at(begin2).pos) {
            ranking.at(current) = tmp.at(begin1);
            begin1++;
        }
        else {
            ranking.at(current) = tmp.at(begin2);
            begin2++;
        }
        current++;
    }

    while (begin1 <= pivot) {
        ranking.at(current) = tmp.at(begin1);
        begin1++;
        current++;
    }
}

void MergeSort::mergeSort(std::vector<Ranking> Tab, int begin, int end)
{
    if (begin < end) {
        int pivot = (begin + end) / 2;
        mergeSort(ranking, begin, pivot);
        mergeSort(ranking, pivot + 1, end);
        merge(ranking, begin, pivot, end);
    }
    
}
