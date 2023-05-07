#include <iostream>
#include <chrono>
#include "QuickSort.h"
#include "Upload.h"
#include "MergeSort.h"
#include "BucketSort.h"

int main()
{
    /*Upload* zad = new Upload(100);
    zad->show();*/

    //QuickSort sort(10000);
    MergeSort sort(900000);
    //BucketSort sort(0);
    auto start = std::chrono::high_resolution_clock::now();
    //sort.quickSort(sort.ranking, 0, sort.size - 1);
    sort.mergeSort(sort.ranking, 0, sort.size - 1);
    //sort.bucketSort(sort.ranking);
    auto stop = std::chrono::high_resolution_clock::now();

    std::chrono::duration <double, std::milli> d = stop - start;
    /*float mediana = (sort.ranking.at(sort.ranking.size() / 2 - 1).pos) + (sort.ranking.at(sort.ranking.size() / 2 + 1).pos) / 2;
    float srednia = 0;
    for (int i = 0; i < sort.ranking.size() - 1; i++) {
        srednia += sort.ranking.at(i).pos;
    }
    srednia = srednia / sort.ranking.size();*/
    //sort.show();
    std::cout << "Time taken = " << d.count() << std::endl;
   /* std::cout << "Srednia = " << srednia << std::endl;
    std::cout << "Mediana = " << mediana << std::endl;*/
}