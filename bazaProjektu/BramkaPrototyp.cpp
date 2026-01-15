#include "BramkaPrototyp.h"

BramkaPrototyp::BramkaPrototyp(std::string typA, std::string in1, std::string in2, std::string wynikA, int czasA) { //konstruktor
    typ = typA;
    wejscie1 = in1;
    wejscie2 = in2;
    wynik = wynikA;
    czas_propagacji = czasA;
    value = -1;
    czas_skumulowany = 0;
}

int obliczBramke(BramkaPrototyp &br, int val1, int val2) { //funkcja liczaca wartosc bramki (poza klasa), przyjmuje obiekt klasy wiec jest nierozerwalnie zwiazana z ta klasa
    if (br.typ == "NAND") return !(val1 & val2);
    else if (br.typ == "AND") return val1 & val2;
    else if (br.typ == "OR")  return val1 | val2;
    else if (br.typ == "NOR") return !(val1 | val2);
    else if (br.typ == "XOR") return val1 ^ val2;
    //else if (br.typ == "NOT") return !val1;
    return 0;
}
