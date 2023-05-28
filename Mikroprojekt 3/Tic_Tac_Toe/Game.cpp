#include "Game.h"
#include <climits>

Game::Game(int size, int winCondition) : window(sf::VideoMode(800, 600), "Tic Tac Toe"), board(size, std::vector<char>(size, ' '))
{
    this->size = size;
    this->winCondition = winCondition;
}

void Game::run()
{
    while (window.isOpen()) {
        handleEvents();
        render();
    }
}

void Game::handleEvents()
{
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
        else if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                int x = event.mouseButton.x;
                int y = event.mouseButton.y;
                int row = y / (window.getSize().y / size);
                int column = x / (window.getSize().x / size);

                if (isValidMove(row, column)) {
                    board[row][column] = 'X';

                    if (checkWin('X')) {
                        std::cout << "Player Wins!" << std::endl;
                    } else if (checkDraw()) {
                        std::cout << "Draw!" << std::endl;
                    }
                    else {
                        AITurn(board, 'O', 'X');
                        if (checkWin('O'))
                            std::cout << "AI Wins!" << std::endl;
                    }
                }
            }
        }
    }
}

void Game::render()
{
    window.clear(sf::Color::White);

    float cellWidth = window.getSize().x / static_cast<float>(size);
    float cellHeight = window.getSize().y / static_cast<float>(size);
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++) {
            sf::RectangleShape cell(sf::Vector2f(cellWidth, cellHeight));
            cell.setPosition(j * cellWidth, i * cellHeight);
            cell.setOutlineThickness(2.f);
            cell.setOutlineColor(sf::Color::Black);
            cell.setFillColor(sf::Color::Transparent);
            window.draw(cell);

            if (board[i][j] == 'X') {
                sf::RectangleShape xMark(sf::Vector2f(cellWidth / 2, 4.f));
                xMark.setPosition(j * cellWidth + cellWidth / 4, i * cellHeight + cellHeight / 4);
                xMark.setFillColor(sf::Color::Red);
                xMark.rotate(45.f);
                window.draw(xMark);
                sf::RectangleShape x2Mark(sf::Vector2f(cellWidth / 2, 4.f));
                x2Mark.setPosition(j * cellWidth + cellWidth / 4, i * cellHeight + (3 * cellHeight / 4));
                x2Mark.setFillColor(sf::Color::Red);
                x2Mark.rotate(-45.f);
                window.draw(x2Mark);
            }
            else if (board[i][j] == 'O') {
                sf::CircleShape oMark(cellWidth / 3);
                oMark.setPosition(j * cellWidth - cellWidth / 4, i * cellHeight - cellHeight / 4);
                oMark.setFillColor(sf::Color::Blue);
                oMark.setOutlineThickness(2.f);
                oMark.setOutlineColor(sf::Color::Black);
                oMark.setOrigin(cellWidth / 6, cellHeight / 6);
                oMark.move(cellWidth / 2, cellHeight / 2);
                window.draw(oMark);
            }
        }
    }

    window.display();
}

bool Game::isValidMove(int row, int col)
{
    return row >= 0 && row < size && col >= 0 && col < size && board[row][col] == ' ';
}

bool Game::checkWin(char sign)
{
    // check rows
    for (size_t i = 0; i < size; i++)
    {
        int count = 0;
        for (size_t j = 0; j < size; j++)
        {
            if (board[i][j] == sign) {
                count++;
                if (count == winCondition)
                    return true;
            }
            else {
                count = 0;
            }
        }
    }

    // check columns
    for (size_t j = 0; j < size; j++)
    {
        int count = 0;
        for (size_t i = 0; i < size; i++)
        {
            if (board[i][j] == sign) {
                count++;
                if (count == winCondition)
                    return true;
            }
            else {
                count = 0;
            }
        }
    }
    
    // check diagonal down to right
    for (size_t i = 0; i <= size - winCondition; i++)
    {
        for (size_t j = 0; j <= size - winCondition; j++) {
            int count = 0;
            for (size_t k = 0; k < winCondition; k++)
            {
                if (board[i + k][j + k] == sign) {
                    count++;
                    if (count == winCondition)
                        return true;
                }
                else {
                    count = 0;
                }
            }
        }
    }

    // check diagonal down to left
    for (size_t i = 0; i <= size - winCondition; i++)
    {
        for (size_t j = winCondition - 1; j < size; j++) {
            int count = 0;
            for (size_t k = 0; k < winCondition; k++)
            {
                if (board[i + k][j - k] == sign) {
                    count++;
                    if (count == winCondition)
                        return true;
                }
                else {
                    count = 0;
                }
            }
        }
    }

    return false;
}

bool Game::checkDraw()
{
    int count = 0;
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++) {
            if (board[i][j] == ' ')
                return false;
        }
    }

    return true;
}

void Game::AITurn(std::vector<std::vector<char>>& board, char sign, char opSign)
{
    int bestScore = INT_MIN;
    int bestRow = -1;
    int bestCol = -1;
    
    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size; j++) {
            if (isValidMove(i, j)) {
                board[i][j] = sign;
                int score = minimax(board, 0, false, sign, opSign, INT_MIN, INT_MAX);
                board[i][j] = ' ';
                if (score > bestScore) {
                    bestScore = score;
                    bestRow = i;
                    bestCol = j;
                }
            }
        }
    }
    if (bestRow != -1 && bestCol != -1) {
        board[bestRow][bestCol] = sign;
    }
}

int Game::minimax(std::vector<std::vector<char>>& board, int depth, bool isMaximizingPlayer, char sign, char opSign, int alpha, int beta)
{
    if (checkWin(sign))
        return INT_MAX - depth;
    if (checkWin(opSign))
        return INT_MIN + depth;
    else if (checkDraw())
        return 0;

    int bestRow = -1;
    int bestColumn = -1;

    if (isMaximizingPlayer) {
        int bestScore = INT_MIN;
        for (size_t i = 0; i < size; i++)
        {
            for (size_t j = 0; j < size; j++) {
                if (isValidMove(i, j)) {
                    board[i][j] = sign;
                    int score = minimax(board, depth + 1, false, sign, opSign, alpha, beta);
                    board[i][j] = ' ';
                    bestScore = std::max(bestScore, score);
                    bestRow = i;
                    bestColumn = j;
                    alpha = std::max(alpha, bestScore);
                    if (alpha >= beta) {
                        break;
                    }
                }
            }
            if (alpha >= beta) {
                break;
            }
        }
        return bestScore;
    }
    else {
        int bestScore = INT_MAX;
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (isValidMove(i, j)) {
                    board[i][j] = opSign;
                    int score = minimax(board, depth + 1, true, sign, opSign, alpha, beta);
                    board[i][j] = ' ';
                    bestScore = std::min(bestScore, score);
                    beta = std::min(beta, bestScore);
                    if (alpha >= beta) {
                        break;
                    }
                }
            }
            if (alpha >= beta) {
                break;
            }
        }
        return bestScore;
    }
}
