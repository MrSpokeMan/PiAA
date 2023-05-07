#include "QuickSort.h"
#include <vector>
#include <algorithm>
#include <iostream>

int QuickSort::partition(std::vector<Ranking>& Tab, int begin, int end)
{
	Ranking pivot = Tab.at(end);
	int beginIx = begin - 1;
	int i = begin;
	while (i < end)
	{
		if (Tab.at(i).pos < pivot.pos) {
			beginIx++;
			if(beginIx != i)
				std::swap(ranking.at(beginIx), ranking.at(i));
		}
		i++;
	}
	if(beginIx != end)
		std::swap(ranking.at(beginIx + 1), ranking.at(end));
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
