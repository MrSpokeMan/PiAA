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
    //MergeSort sort(10000);
    BucketSort sort(1000000);
    auto start = std::chrono::high_resolution_clock::now();
    //sort.quickSort(sort.ranking, 0, sort.size - 1);
    //sort.mergeSort(sort.ranking, 0, sort.size - 1);
    sort.bucketSort(sort.ranking);
    auto stop = std::chrono::high_resolution_clock::now();

    std::chrono::duration <double, std::milli> d = stop - start;

    //sort.show();
    std::cout << "Time taken = " << d.count() << std::endl;
}