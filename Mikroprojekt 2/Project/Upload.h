#ifndef UPLOAD_H
#define UPLOAD_H
#include <vector>
#include <string>

class Upload
{
protected:

	struct Ranking
	{
		int index;
		std::string title;
		int pos;
	};
public:

	std::vector<Ranking> ranking;
	int size;

	Upload(int size);

	void dataFromFile();
	void show();
};
#endif UPLOAD_H