// 27-10-2025.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    std::cout << "Hello World!\n";

    int liczba;
    bool czyUjemna = false;
    vector<int> dzielniki = {};

    cout << "podaj liczbe" << endl;
    cin >> liczba;

    if (liczba > 0) {
        cout << "Liczba dodatnia"<<endl;
    }
    else if (liczba < 0) {
        cout << "Liczba ujemna" << endl;
        czyUjemna = true;

    }
    else {
        cout << "Zero" << endl;
    }

    
    if (!czyUjemna) {
        for (int i = 1; i < liczba + 1; i++) {
            if (liczba % i == 0) {
                cout << "Liczba podzielna przez " << i << endl;
                dzielniki.push_back(i);
            }
        }
    }
    else {
        for (int i = 1; i < (liczba*-1) + 1; i++) {
            if (liczba % i == 0) {
                cout << "Liczba podzielna przez " << i << endl;
                dzielniki.push_back(i);
            }
        }
    }
    

    if (dzielniki.size() == 2 && liczba>1) {
        cout << "Liczba pierwsza" << endl;
    }
    else {
        cout << "Nie jest liczba pierwsza" << endl;
    }

    //sito erystotelesa or sth idk
    int licznik = 0;
    for (int q = 0; q < 100; q++) {
        for (int p = 1; p < 100; p++) {
            if (q % p == 0) {
                licznik++;
            }
        }
        if (licznik !=2) {
            cout << q << endl;
        }
        else {
            cout << q << " Liczba pierwsza" << endl;
        }
        licznik = 0;
    }

    char uprawnienia;
    cout << "Podaj uprawnienia(A,B,C,D)" << endl;
    cin >> uprawnienia;

    switch (uprawnienia)
    {
    case 'a':
    case 'A':
        cout << "motor" << endl;
        break;
    case 'b':
    case 'B':
        cout << "samochod" << endl;
        break;
    case 'c':
    case 'C':
        cout << "ciezarowka" << endl;
        break;
    case 'd':
    case 'D':
        cout << "autobus" << endl;
        break;
    default:
        cout << "wybrales opcje inna niz podane" << endl;
        break;
    }

    string gwiazdki = "*";
    for (int i = 0; i < 10; i++) {
        cout << gwiazdki << endl;
        gwiazdki += "*";
    }

    for (int i = 0; i < 10; i++) {
        switch (i)
        {
        case 0:
            cout << "*";
        case 1:
            cout << "*";
        case 2:
            cout << "*";
        case 3:
            cout << "*";
        case 4:
            cout << "*";
        case 5:
            cout << "*";
        case 6:
            cout << "*";
        case 7:
            cout << "*";
        case 8:
            cout << "*";
        case 9:
            cout << "*";
        default:
            break;
        }
        cout << endl;
    }

    int tablica[11][3];

    for (int i = 0; i <= 10; i++) {
        tablica[i][0] = i;
        tablica[i][1] = i * i;
        tablica[i][2] = i * i * i;
    }

    for (int q = 0; q <= 10; q++) {
        cout << tablica[q][0] << " " << tablica[q][1] << " " << tablica[q][2] << endl;
    }
}
