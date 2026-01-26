/**
 * @file BramkaPrototyp.h
 * @brief Deklaracja klasy BramkaPrototyp oraz funkcji obsługujących bramki logiczne.
 *
 * Plik zawiera definicję klasy reprezentującej bramkę logiczną
 * używaną w symulacji układu logicznego wraz z deklaracją
 * funkcji obliczającej wartość wyjścia bramki.
 */

#ifndef BRAMKAPROTOTYP_H
#define BRAMKAPROTOTYP_H

#include <string>

/**
 * @class BramkaPrototyp
 * @brief Reprezentuje pojedynczą bramkę logiczną w symulowanym układzie.
 *
 * Klasa przechowuje informacje o typie bramki logicznej, nazwach sygnałów
 * wejściowych i wyjściowych oraz danych potrzebnych do symulacji
 * sygnału w czasie.
 */
class BramkaPrototyp {
public:
    /// Typ bramki logicznej (np. AND, OR, NAND, XOR)
    std::string typ;

    /// Nazwa pierwszego sygnału wejściowego
    std::string wejscie1;

    /// Nazwa drugiego sygnału wejściowego
    std::string wejscie2;

    /// Nazwa sygnału wyjściowego bramki
    std::string wynik;

    /// Czas propagacji sygnału przez bramkę
    int czas_propagacji;

    /// Aktualna wartość logiczna wyjścia (0, 1 lub -1 gdy nieobliczona)
    int value;

    /// Skumulowany czas propagacji sygnału do tej bramki
    int czas_skumulowany;

    /**
     * @brief Konstruktor klasy BramkaPrototyp.
     *
     * Inicjalizuje bramkę logiczną na podstawie podanych danych 
     *      
     * @param typA typ bramki logicznej
     * @param in1 nazwa pierwszego wejścia
     * @param in2 nazwa drugiego wejścia
     * @param wynikA nazwa sygnału wyjściowego
     * @param czasA czas propagacji bramki
     */
    BramkaPrototyp(std::string typA, std::string in1, std::string in2, std::string wynikA, int czasA); 
};

/**
 * @brief Oblicza wartość logiczną wyjścia bramki.
 *
 * Funkcja na podstawie typu bramki zapisanej w obiekcie BramkaPrototyp
 * oblicza wynik operacji logicznej dla podanych wartości wejściowych.
 *
 * @param br referencja do obiektu bramki
 * @param val1 wartość pierwszego wejścia (0 lub 1)
 * @param val2 wartość drugiego wejścia (0 lub 1)
 * @return wynik operacji logicznej (0 lub 1)
 */
int obliczBramke(BramkaPrototyp &br, int val1, int val2); 

#endif // BRAMKAPROTOTYP_H

