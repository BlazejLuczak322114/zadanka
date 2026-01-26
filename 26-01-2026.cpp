// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <memory>
#include <algorithm>

using namespace std;

class Product {
public:
    string nazwa;
    string typ;
    int ilosc;
    double cena;
    Product(string NowaNazwa, string NowyTyp, int NowaIlosc, double NowaCena) {
        nazwa = NowaNazwa;
        typ = NowyTyp;
        ilosc = NowaIlosc;
        cena = NowaCena;
    }
    void wypisz() {
        cout << nazwa << " " << typ << " " << ilosc << " " << cena << endl;
    }
private:
    shared_ptr<Product> next; //zrobic coś z tym w domu z shared, unique i weak ptr
    shared_ptr<Product> prev;
};

int main()
{
    std::cout << "Hello World!\n";
    fstream plik("magazyn.txt", ios::in);
    if (!plik.good()) {
        cout << "Plik not good" << endl;
        return 0;
    }
    vector<Product> StanMagazynu;
    string nazwa, typ;
    int ilosc;
    double cena;
    while (plik>>nazwa >> typ >> ilosc >> cena) {
        StanMagazynu.push_back(Product(nazwa, typ, ilosc, cena));
    }
    bool dziala = true;
    std::string wejscie, wejscie1;
    while (dziala) {
        cout << "Wybierz produkt do wypisania(karta_graficzna,dysk,monitor,procesor,obudowa,plyta)" << endl;
        cin >> wejscie;
        //cout << "napisz 'stop' by stop" << endl;
        cout << "Posortowac wg ceny?(rosnaco/malejaco)" << endl;
        cin >> wejscie1;
        if (wejscie1 == "rosnaco") {
            std::sort(StanMagazynu.begin(), StanMagazynu.end(), [](const Product& a, const Product& b) { return a.cena < b.cena; });
        }
        else if (wejscie1 == "malejaco") {
            std::sort(StanMagazynu.begin(), StanMagazynu.end(), [](const Product& a, const Product& b) { return a.cena > b.cena; });
        }
        for (int i = 0; i < StanMagazynu.size(); i++) {
            if (StanMagazynu[i].typ == wejscie) {
                StanMagazynu[i].wypisz();
            }
        }
        if (wejscie1 == "stop") {
            dziala = false;
        }
        
    }
    
}
