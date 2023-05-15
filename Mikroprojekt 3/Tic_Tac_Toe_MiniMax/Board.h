#ifndef BOARD_H
#define BOARD_H
#include <string>
class Board
{
	size_t size, winCond;
	std::string** board;
public:
	Board(size_t x, size_t w);
	~Board();
};
#endif BOARD_H