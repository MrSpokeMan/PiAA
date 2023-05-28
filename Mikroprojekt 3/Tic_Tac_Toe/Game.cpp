#include "Game.h"

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
                sf::CircleShape xMark(cellWidth / 3);
                xMark.setPosition(j * cellWidth, i * cellHeight);
                xMark.setFillColor(sf::Color::Red);
                window.draw(xMark);
            }
            else if (board[i][j] == 'O') {
                sf::CircleShape oMark(cellWidth / 3);
                oMark.setPosition(j * cellWidth, i * cellHeight);
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
    return row >= 0 && row < size&& col >= 0 && col < size&& board[row][col] == ' ';
}
