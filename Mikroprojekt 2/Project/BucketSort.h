#ifndef BUCKETSORT_H
#define BUCKETSORT_H
#include "Upload.h"
#include <vector>
class BucketSort : public Upload
{
public:
	BucketSort(int size) : Upload(size) {};
	void bucketSort(std::vector<Ranking>& Tab);
};
#endif BUCEKETSORT_H