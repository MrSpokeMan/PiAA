#pragma once

class Zad1 {
    private:
    int rowSize;
    int columnSize;
    int **tab;
    int** tabGenerator(int& rowSize, int& columnSize);

    public:
    Zad1(int n, int m); 
    ~Zad1();

    int** numberGenerator(int& rangeSize, int** tab);
    void displayTab(int const &rowSize, int const &columnSize);
    int maxValue(int const &rowSize, int const &columnSize);
};