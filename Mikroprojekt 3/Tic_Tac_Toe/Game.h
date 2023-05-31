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
    int maxDepth;
    std::vector<std::vector<char>> board;

    void handleEvents();

    void render();

    bool isValidMove(int row, int column);

    bool checkWin(char sign);

    bool checkDraw();

    void AITurn(std::vector<std::vector<char>>& board, char sign, char opSign);

    int minimax(std::vector<std::vector<char>>& board, int depth, bool isMaximizingPlayer, char sign, char opSign, int alpha, int beta);
    
    int evaluate(std::vector<std::vector<char>>& board, char sign, char opSign);
};

