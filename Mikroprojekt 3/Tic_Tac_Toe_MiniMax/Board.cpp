#include "Board.h"

Board::Board(size_t x, size_t w)
{
	this->size = x;
	this->winCond = w;

	board = new std::string * [size];
	for (size_t i = 0; i < size; i++)
		board[i] = new std::string[size];
}

Board::~Board()
{
	for (size_t i = 0; i < size; i++)
		delete[] board[i];
	delete[] board;
}
