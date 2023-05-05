#ifndef QUICKSORT_H
#define QUICKSORT_H
#include <vector>
#include "Upload.h"
class QuickSort: public Upload
{
private:
	void changePlaces(std::vector<Ranking> ranking, int from, int to);

public:
	int partition(std::vector<Ranking> Tab, int begin, int end);
	void quickSort(std::vector<Ranking> Tab, int begin, int end);
};
#endif QUICKSORT_H