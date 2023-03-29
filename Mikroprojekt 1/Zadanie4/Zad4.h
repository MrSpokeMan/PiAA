#pragma once
#include <iostream>
#include <string>

class Zad4
{
	std::string tab[720];
public:
	bool isPal(std::string str, int begin, int end);
	void genPerm(std::string prefix, std::string rest);
	void displayTab();
};

