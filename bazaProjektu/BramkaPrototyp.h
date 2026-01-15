#ifndef BRAMKAPROTOTYP_H
#define BRAMKAPROTOTYP_H

#include <string>

class BramkaPrototyp {
public:
    std::string typ;
    std::string wejscie1;
    std::string wejscie2;
    std::string wynik;
    int czas_propagacji;
    int value;
    int czas_skumulowany;


    BramkaPrototyp(std::string typA, std::string in1, std::string in2, std::string wynikA, int czasA); //konstruktor
};

int obliczBramke(BramkaPrototyp &br, int val1, int val2); //funkcja liczaca wartosc bramki (poza klasa), przyjmuje obiekt klasy wiec jest nierozerwalnie zwiazana z ta klasa

#endif // BRAMKAPROTOTYP_H

