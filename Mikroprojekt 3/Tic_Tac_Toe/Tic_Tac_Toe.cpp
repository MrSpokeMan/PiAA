#include <iostream>
#include "Game.h"

int main()
{
    int size, winCondition;

    std::cout << "Size of the board: ";
    std::cin >> size;
    std::cout << "\nWin condition (amount of marks in a row): ";
    std::cin >> winCondition;

    Game game(size, winCondition);
    game.run();

    return 0;
}