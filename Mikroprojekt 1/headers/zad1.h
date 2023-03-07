#pragma once

class Zad1 {
    private:
    int rowSize;
    int columnSize;
    int rangeSize;

    float** numberGenerator(int& rangeSize, float** tab);
    float** tabGenerator(int& rowSize, int& columnSize);

    public:
    Zad1(int n, int m, int range);    
};