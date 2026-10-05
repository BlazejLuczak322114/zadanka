// ConsoleApplication5.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>

template <typename T>
void sortowanieMalejace(T table[], int rozmiar) { //babelkowe
    T temp;
    for (int i = 0; i < rozmiar-1; ++i) {
        for (int j = 0; j < rozmiar-1; ++j) {
            if (table[j] < table[j+1]) {
                temp = table[j];
                table[j] = table[j+1];
                table[j+1] = temp;
            }
        }
    }
    return;
}

template <typename T>
bool wyszukiwanieBinarne(T table[], int rozmiar, T wyszukiwany) { //zakladamy tablice posortowana malejaco

    int left = 0; //index poczatku tablicy
    int right = rozmiar - 1; //index konca tablicy
    //niezaleznie od wartosci tablicy, indexy sa zawsze calkowite (imo worth mentioning)

    while (left <= right) { //zmniejszamy obszar tak dlugo az de facto sie skonczy
        int srodek = (left + right) / 2; //index srodka tej posortowanej tablicy (zaokraglony w dol)

        if (wyszukiwany == table[srodek]) { //znaleziono szukany
            return true;
        }
        else if (wyszukiwany < table[srodek]) { //szukany mniejszy niz srodek (malejaca wiec wszystko na prawo od srodka mniejsze)
            left = srodek + 1;
        }
        else { //szukany wiekszy niz srodek
            right = srodek - 1;
        }
    }
    return false;
}

template <typename T>
class KlasaSzablonowa {
private:
    T* table; 
    int size;
public:
    KlasaSzablonowa(T tablica[], int rozmiar):size(rozmiar) {
        table = new T[size]; //dynamiczny rozmiar 
        for (int i = 0; i < size; ++i) {
            table[i] = tablica[i]; //wsadzamy elementy tablicy do klasy
        }
    }
    ~KlasaSzablonowa() { 
        delete[] table;
        //std::cout << "Usunieto klase szablonowa" << std::endl;
    }
    void sortowanieMalejace() { //funkcja przerobiona na metode
        T temp;
        for (int i = 0; i < size-1; ++i) {
            for (int j = 0; j < size-1; ++j) {
                if (table[j] < table[j+1]) {
                    temp = table[j];
                    table[j] = table[j+1];
                    table[j+1] = temp;
                }
            }
        }
        return;
    }

    bool wyszukiwanieBinarne(T wyszukiwany) { //still zakladamy tablice posortowana malejaco

        int left = 0; 
        int right = size - 1; 

        while (left <= right) { 
            int srodek = (left + right) / 2; 

            if (wyszukiwany == table[srodek]) { 
                return true;
            }
            else if (wyszukiwany < table[srodek]) { 
                left = srodek + 1;
            }
            else { 
                right = srodek - 1;
            }
        }
        return false;
    }

    void wyswietlanie() {
        for (int i = 0; i < size; i++) {
            std::cout << table[i] << " ";
        }
        std::cout<<std::endl;
        return;
    }

};

template <int kierunkowy, int dlugosc>
class NumerTelefonu {
private:
    std::string numer;
public:
    NumerTelefonu(std::string podanyNum) {
        if (podanyNum.length() == dlugosc) { //zeby po cos ten parametr byl
            numer = podanyNum;
        }
        else {
            std::cout << "Niepoprawna dlugosc numeru, inna od: " << dlugosc << std::endl;
            numer = "";
            for (int i = 0; i < dlugosc; ++i) {
                numer += '0'; //same zera, o podanej dlugosci
            }
        }
    }
    ~NumerTelefonu() {
       // std::cout << "Usunieto numer telefonu" << std::endl;

    }
    void wyswietlanie() {
        std::cout << "+" << kierunkowy << " " << numer << std::endl;
    }
};

template<typename T, int wielkosc>
requires (wielkosc>0) //inaczej sie wykrzaczy dla wielkosci <=0
class BuforCykliczny {
private:
    T table[wielkosc];
    int zapis=0; //index buforu
    int odczyt=0;
    int zapelnione=0; //ile w buforze

public:
    void pisz(T wartosc) { 
        table[zapis] = wartosc;
        zapis = (zapis + 1) % wielkosc;
        if (zapelnione < wielkosc) {
            zapelnione++;
        }
        else {
            odczyt = (odczyt + 1) % wielkosc;
        }
    }

    T czytaj(){ 
        if (zapelnione == 0) {
            throw "Bufor jest pusty";
        }
        T wartosc = table[odczyt];
        odczyt = (odczyt + 1) % wielkosc;
        zapelnione--;
        return wartosc;
    }

    bool pusty() { return zapelnione == 0; }
    int getZapelnienie() { return zapelnione; }
    void wyswietlanie() {
        std::cout << "Zapelnienie: " << zapelnione << "/" << wielkosc << ", index zapisu: " << zapis << ", index odczytu: " << odczyt << std::endl;
    }
};


int main()
{
    //int table[11] = { 7, 2, 11, 4, 1, 9, 5, 8, 3, 10, 6 };
    float table[11] = { 7.2, 2.11, 11.4, 4.1, 1.9, 9.5, 5.8, 8.3, 3.1, 10.6, 6.7 };

    //sortowanieMalejace(table, 11);
    
    //int szukane = 8;
    //if (wyszukiwanieBinarne(table, 11, szukane)) {
    //    std::cout << "Mamy " << szukane << std::endl;
    //}
    //else {
    //    std::cout << "Nie ma szukanej w tablicy" << std::endl;
    //}

    KlasaSzablonowa jeden(table, 11);
    jeden.sortowanieMalejace();
    jeden.wyswietlanie();

    float szukane = 2.11; //liczba ktora szukamy w tablicy

    if (jeden.wyszukiwanieBinarne(szukane)) {
        std::cout << "Mamy " << szukane << std::endl;
    }
    else {
    std::cout << "Nie ma liczby szukanej w tablicy" << std::endl;
    }

    NumerTelefonu<48, 9> polska("997998999");
    polska.wyswietlanie();

    std::cout << "=====" << std::endl;

    NumerTelefonu<49, 11> niemcy("997998999"); //sprawdzanie niepoprawnej dlugosci
    niemcy.wyswietlanie();

    std::cout << "=====" << std::endl;

    NumerTelefonu<49, 11> niemcy2("99799899910");
    niemcy2.wyswietlanie();

    std::cout << std::endl;
    BuforCykliczny<int, 3> pierwszy;
    
    pierwszy.pisz(10);
    pierwszy.pisz(20);
    pierwszy.pisz(30);
    pierwszy.pisz(40);

    std::cout<<pierwszy.czytaj()<<std::endl;
    pierwszy.pisz(50);
    std::cout << pierwszy.czytaj()<<std::endl;
    pierwszy.wyswietlanie();

    BuforCykliczny<int, 3> drugi;
    try {
        drugi.czytaj();
    }
    catch (const char* err) {
        std::cout << err << std::endl;
    }

}
