#include "Upload.h"
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>

Upload::Upload(int size)
{
	this->size = size;
	dataFromFile();
}

void Upload::dataFromFile()
{
	std::ifstream file;
	file.open("../projekt2_dane.csv");

	if (file.is_open()) {
		std::string title;
		std::string pos;
		std::string tmpIndex;
		std::string tmpString;
		std::getline(file, tmpString);
		while (std::getline(file, tmpString)) {

			if (size != 0)
				if (ranking.size() >= size) break;

			std::stringstream tmp(tmpString);
			std::getline(tmp, tmpIndex, ',');
			std::getline(tmp, title, ',');
			while (title.front() == '"')
			{
				std::string tmpTmpName;
				if (title.back() == '"') break;
				std::getline(tmp, tmpTmpName, ',');
				title = title + ',' + tmpTmpName;
			}
			std::getline(tmp, pos, ',');
			if (!pos.empty()) {
				ranking.push_back({ title, stoi(pos) });
			}
		}
	}
	file.close();
}

void Upload::show()
{
	for (int i = 0; i < ranking.size(); i++) {
		std::cout << ranking.at(i).title << " " << ranking.at(i).pos << std::endl;
	}
}
