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
    cout << "4. Wczytaj liczby z pliku tekstowego" << endl;
    cout << "5. Zapisz tablice w pliku tekstowego" << endl;
    cout << "6. Wczytaj liczby z pliku binarnego" << endl;
    cout << "7. Zapisz tablice w pliku binarnym" << endl;
    cout << "8. Wyjscie" << endl;
    cout << "Podaj numer opcji: " << endl;
}

int main()
{
    Zad1* zad = new Zad1(5, 4);
    zad->numberGenerator(12);
    zad->loadToTextFile();

    /*int n, m;

    cout << "Podaj wymiary tablicy (n x m): " << endl;
    cin >> n;
    cin >> m;
    Zad1* zad = new Zad1(n, m);
    Zad1* zad2 = new Zad1(5, 4)
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
            displayMenuZad1();
            break;
        case 4:
            zad2->loadFromTextFile();
            displayMenuZad1();
            break;
        case 5:
            zad->loadToTextFile();
            displayMenuZad1();
            break;
        case 6:
            \\ użycie funkcji do wczytywania z pliku binarnego
            displayMenuZad1();
            break;
        case 7:
            \\ użycie funkcji do zapisania w pliku binarnym
            displayMenuZad1();
            break;
        case 8:
            exit(0);
            break;
        }
    }*/
}