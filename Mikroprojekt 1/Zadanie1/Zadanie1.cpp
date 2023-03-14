#include "Zad1.h"
#include <cstdlib>
#include <iostream>
#include <conio.h>

using namespace std;

void displayMenuZad1()
{
    cout << endl;
    cout << "--- TABLICA ---" << endl;
    cout << "1. Wygeneruj liczby z zakresu:" << endl;
    cout << "2. Wyswietl tablice" << endl;
    cout << "3. Znajdz najwieksza wartosc" << endl;
    cout << "4. Wyjscie" << endl;
    cout << "Podaj numer opcji: " << endl;
}

int main()
{
    int n, m;

    cout << "Podaj wymiary tablicy (n x m): " << endl;
    cin >> n;
    cin >> m;
    Zad1 *zad = new Zad1(n, m);
    displayMenuZad1();
    while (true) {
        int choice = 0;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << "Podaj zakres liczb do wylosowania: " << endl;
            int range;
            cin >> range;
            zad->numberGenerator(range);
            displayMenuZad1();
            break;
        }
        case 2:
            zad->displayTab();
            displayMenuZad1();
            break;
        case 3:
            zad->maxValue();
            break;
        case 4:
            exit(0);
            break;
        }
    }
}