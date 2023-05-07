#ifndef QUICKSORT_H
#define QUICKSORT_H
#include <vector>
#include "Upload.h"
class QuickSort: public Upload
{
public:
	int partition(std::vector<Ranking>& Tab, int begin, int end);
	void quickSort(std::vector<Ranking>& Tab, int begin, int end);

	QuickSort(int size) : Upload(size) {};
};
#endif QUICKSORT_H