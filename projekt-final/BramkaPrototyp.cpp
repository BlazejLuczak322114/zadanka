/**
 * @file BramkaPrototyp.cpp
 * @brief Implementacja klasy BramkaPrototyp i funkcji obliczania bramek logicznych.
 */

#include "BramkaPrototyp.h"

/**
 * @brief Konstruktor klasy BramkaPrototyp.
 *
 * Ustawia wszystkie pola obiektu bramki oraz inicjalizuje wartości
 * (value = -1 oznacza brak obliczonego wyniku).
 */
BramkaPrototyp::BramkaPrototyp(std::string typA, std::string in1, std::string in2, std::string wynikA, int czasA) { //konstruktor
    typ = typA;
    wejscie1 = in1;
    wejscie2 = in2;
    wynik = wynikA;
    czas_propagacji = czasA;
    value = -1;
    czas_skumulowany = 0;
}

/**
 * @brief Implementacja obliczania wartości bramki logicznej.
 *
 * Na podstawie typu bramki (np. AND, OR, NAND) wykonywana jest odpowiednia
 * operacja logiczna na wejściach.
 */
int obliczBramke(BramkaPrototyp &br, int val1, int val2) { 
    if (br.typ == "NAND") return !(val1 && val2);
    else if (br.typ == "AND") return (val1 && val2);
    else if (br.typ == "OR")  return (val1 || val2);
    else if (br.typ == "NOR") return !(val1 || val2);
    else if (br.typ == "XOR") return (val1 != val2);
    return 0;
}
