#ifndef UPLOAD_H
#define UPLOAD_H
#include <vector>
#include <string>

class Upload
{
protected:
	struct Ranking
	{
		std::string title;
		int pos;
	};

	std::vector<Ranking> ranking;
	Ranking begin = ranking.front();
	Ranking end = ranking.back();
	int size;

public:
	Upload(int size);

	void dataFromFile();
	void show();
};
#endif UPLOAD_H