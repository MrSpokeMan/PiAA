#pragma once

class Zad1
{
private:
    int rowSize;
    int columnSize;
    int** tab = nullptr;

public:
    Zad1(int n, int m);
    ~Zad1();

    void numberGenerator(int rangeSize);
    void displayTab();
    void maxValue();
    // Do zadania 2
    void loadFromTextFile();
    void loadToTextFile();
    void loadFromBinFile();
    void loadToBinFile();
};