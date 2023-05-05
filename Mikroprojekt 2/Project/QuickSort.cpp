#include "QuickSort.h"
#include <vector>

void QuickSort::changePlaces(std::vector<Ranking> ranking, int from, int to)
{
	Ranking tmp = ranking.at(from);
	ranking.at(from) = ranking.at(to);
	ranking.at(to) = tmp;
}

int QuickSort::partition(std::vector<Ranking> Tab, int begin, int end)
{
	Ranking lastEl = ranking.at(end);
	int beginIx = begin - 1;
	for (size_t i = begin; i < end - 1; i++)
	{
		if (ranking.at(i).pos <= lastEl.pos) {
			beginIx += 1;
			changePlaces(ranking, beginIx, i);
		}
	}
	changePlaces(ranking, beginIx + 1, end);
	return beginIx + 1;
}

void QuickSort::quickSort(std::vector<Ranking> Tab, int begin, int end)
{
	if (begin < end) {
		int q = partition(ranking, begin, end);
		quickSort(ranking, begin, q - 1);
		quickSort(ranking, q + 1, end);
	}
}
