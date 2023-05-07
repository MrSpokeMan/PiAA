#include "QuickSort.h"
#include <vector>
#include <algorithm>
#include <iostream>

void QuickSort::swap(int *from, int *to) {
	Ranking tmp = ranking.at(*from);
	ranking.at(*from) = ranking.at(*to);
	ranking.at(*to) = tmp;
}

int QuickSort::partition(std::vector<Ranking>& Tab, int begin, int end)
{
	int pivot = Tab.at((begin + end) / 2).pos;
	int beginIx = begin - 1;
	int i = begin;
	while (i < end)
	{
		if (Tab.at(i).pos < pivot) {
			beginIx++;
			if(beginIx != i)
				swap(&beginIx, &i);
		}
		i++;
	}
	if (beginIx != end) {
		int incBeginIx = beginIx + 1;
		swap(&incBeginIx, &end);
	}
	return beginIx + 1;
}

void QuickSort::quickSort(std::vector<Ranking>& Tab, int begin, int end)
{
	if (begin < end) {
		int beginIx = partition(Tab, begin, end);
		quickSort(Tab, begin, beginIx - 1);
		quickSort(Tab, beginIx + 1, end);
	}
}