#pragma once

class Zad1 {
    private:
    int rowSize;
    int columnSize;
    int **tab;

    public:
    Zad1(int n, int m); 
    ~Zad1();

    int** numberGenerator(int rangeSize);
    void displayTab();
    int maxValue();
};