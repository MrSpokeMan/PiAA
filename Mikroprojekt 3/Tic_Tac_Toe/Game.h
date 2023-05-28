#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

class Game
{
public:
    Game(int size, int winCondition);

    void run();


private:
    sf::RenderWindow window;
    int size;
    int winCondition;
    std::vector<std::vector<char>> board;

    void handleEvents();

    void render();

    bool isValidMove(int row, int column);
};

