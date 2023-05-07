#ifndef MERGESORT_H
#define MERGESORT_H
#include "Upload.h"

class MergeSort: public Upload
{
public:
	MergeSort(int size) : Upload(size) {};

	void merge(std::vector<Ranking>& Tab, int begin, int mid, int end);
	void mergeSort(std::vector<Ranking>& Tab, int begin, int end);
};
#endif MERGESORT_H