#include "../headers/zad1.h"
#include <cstdlib>
#include <iostream>

using namespace std;

void displayMenu()
{
	cout << endl;
    cout << "--- TABLICA ---" << endl;
	cout << "1.Zadanie 1" << endl;
	cout << "0.Wyjscie" << endl;
}

void displayMenuZad1()
{
	cout << endl;
    cout << "--- TABLICA ---" << endl;
	cout << "1. Wygeneruj liczby z zakresu:" << endl;
	cout << "2. Wyswietl tablice" << endl;
	cout << "3. Znajdz najwieksza wartosc" << endl;
	cout << "0.Wyjscie" << endl;
}

int main() {
    int num, n, m;
    
    do {
        displayMenu();
		cin >> num;
		cout << endl;
		switch (num) {
            case 1: 
            {
                cout << "Podaj wymiary tablicy (n x m): " << endl;
                cin >> n, m;
                Zad1* zad = new Zad1(n, m);
                displayMenuZad1();
                int choice;
                cin >> choice;
                switch (choice) {
                    case 1:
                    {
                        int range;
                        cin >> range;
                        zad->numberGenerator(range);
                    break;
                    }
                    case 2:
                        zad->displayTab();
                    break;
                    case 3:
                        zad->maxValue();
                    break;
                    case 0:
                        exit(0);
                    break;
                }
            break;
            }
            // miejsce na reszte zadań
            case 0:
                exit(0);
            break;
        }        
    }while(num != 0);
}