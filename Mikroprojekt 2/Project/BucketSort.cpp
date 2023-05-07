#include "BucketSort.h"

void BucketSort::bucketSort(std::vector<Ranking>& Tab)
{
    int min = Tab.at(0).pos;
    int max = Tab.at(0).pos;

    for (int i = 1; i < Tab.size(); i++)
    {
        if (Tab.at(i).pos > max)
        {
            max = Tab.at(i).pos;
        }
        if (Tab.at(i).pos < min)
        {
            min = Tab.at(i).pos;
        }
    }

    int length = max - min + 1;

    std::vector<Ranking>* bucket = new std::vector<Ranking>[length];

    for (int i = 0; i < length; i++)
    {
        bucket[i] = std::vector<Ranking>();
    }

    for (int i = 0; i < Tab.size(); i++)
    {
        bucket[Tab.at(i).pos - min].push_back(Tab.at(i));
    }

    int a = 0;

    for (int i = 0; i < length; i++)
    {
        int tmpSize = bucket[i].size();
        if (tmpSize > 0)
        {
            for (int j = 0; j < tmpSize; j++)
            {
                Tab.at(a) = bucket[i][j];
                a++;
            }
        }
    }
}
