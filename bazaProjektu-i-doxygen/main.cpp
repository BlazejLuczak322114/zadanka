/**
 * @file main.cpp
 * @brief Program symulujący działanie układu bramek logicznych.
 *
 * Program wczytuje opis układu bramek oraz zestawy wejść z plików tekstowych,
 * a następnie symuluje propagację sygnałów przez układ z uwzględnieniem
 * czasów propagacji poszczególnych bramek.
 */

 /**
  * @page format_plikow Format plików wejściowych
  *
  * @section opis Opis układu (opis_ukladu.txt)
  * Plik zawiera opis kolejnych bramek logicznych.
  * Każda linia ma postać:
  *
  * typ wejście1 wejście2 wyjście czas_propagacji
  *
  * Przykład:
  * NAND a a c 10
  *
  * @section wejscia Zestawy wejść (wejscie.txt)
  * Pierwsza linia zawiera nagłówki sygnałów wejściowych.
  * Kolejne linie zawierają wartości logiczne sygnałów.
  *
  * Przykład:
  * a b
  * 0 1
  */

  /**
   * @section wyjscie Pliki wyjściowe
   *
   * Program generuje plik wynikowy:
   *
   * - wynik.txt – zawiera obliczone wartości wyjść układu logicznego
   *   dla kolejnych zestawów wejściowych wraz z czasami propagacji sygnałów.
   *
   * Plik jest tworzony automatycznie w katalogu roboczym programu.
   */
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "BramkaPrototyp.h"

using namespace std;

/**
 * @brief Główna funkcja programu.
 *
 * Odpowiada za:
 * - wczytanie opisu układu bramek z pliku,
 * - wczytanie zestawów wejściowych,
 * - symulację propagacji sygnałów,
 * - zapis i wyświetlenie wyników.
 *
 * @return 0 w przypadku poprawnego zakończenia programu
 */
int main() {
    fstream opis("opis_ukladu.txt", ios::in);
    if (!opis.good()) { cout << "Nie mozna otworzyc opis_ukladu.txt\n"; return 1; } 

    vector<BramkaPrototyp> bramki; 
    string typ, in1, in2, out; 
    int opoznienie;

    while (opis >> typ >> in1 >> in2 >> out >> opoznienie) { 
        bramki.push_back(BramkaPrototyp(typ, in1, in2, out, opoznienie));
    }
    opis.close(); 

    
    fstream wej("wejscie.txt", ios::in);
    if (!wej.good()) { cout << "Nie mozna otworzyc wejscie.txt\n"; return 1; }

    string hA, hB; 
    wej >> hA >> hB;

    vector<pair<int,int>> zestawy; 
    int aVal, bVal;
    while (wej >> aVal >> bVal) { 
        zestawy.push_back({aVal,bVal});
    }
    wej.close();


    ofstream wynikPlik("wynik.txt"); 
    if (!wynikPlik.is_open()) {
        cout << "Nie mozna otworzyc wyniki.txt\n";
        return 1;
    }

    
    for (int z = 0; z < zestawy.size(); z++) {
        aVal = zestawy[z].first;
        bVal = zestawy[z].second;

        
        for (auto &br : bramki) { 
            br.value = -1;
            br.czas_skumulowany = 0;
        }

        int a = aVal;
        int b = bVal;

        
        bool zmiana = true; 
        while (zmiana) {
            zmiana = false;
            for (auto &br : bramki) { 
                if (br.value != -1) continue; 

                int val1 = 0, val2 = 0;
                int czas1 = 0, czas2 = 0;
                bool got1 = false, got2 = false; 

                
                if (br.wejscie1 == "a") { val1 = a; czas1 = 0; got1 = true; }
                else if (br.wejscie1 == "b") { val1 = b; czas1 = 0; got1 = true; }
                else {
                    for (auto &prev : bramki) { 
                        if (prev.wynik == br.wejscie1 && prev.value != -1) { 
                            val1 = prev.value;
                            czas1 = prev.czas_skumulowany;
                            got1 = true;
                            break;
                        }
                    }
                }

                
                if (br.wejscie2 == "a") { val2 = a; czas2 = 0; got2 = true; }
                else if (br.wejscie2 == "b") { val2 = b; czas2 = 0; got2 = true; }
                else {
                    for (auto &prev : bramki) {
                        if (prev.wynik == br.wejscie2 && prev.value != -1) {
                            val2 = prev.value;
                            czas2 = prev.czas_skumulowany;
                            got2 = true;
                            break;
                        }
                    }
                }

                if (got1 && got2) { 
                    br.value = obliczBramke(br, val1, val2); 
                    br.czas_skumulowany = (czas1 > czas2 ? czas1 : czas2) + br.czas_propagacji;
                    zmiana = true;
                }
            }
        }

        
        cout << "Zestaw a=" << a << " b=" << b << ":\n";
        for (auto &br : bramki) {
            if (br.wynik == "c"|| br.wynik == "f"|| br.wynik == "j") {
                cout << br.wynik << " = " << br.value
                     << " (czas propagacji: " << br.czas_skumulowany << ")\n";
            }
        }
        cout << "------------------------\n";
        
        wynikPlik << "Zestaw a=" << a << " b=" << b << ":\n";
        for (auto &br : bramki) {
            if (br.wynik == "c" || br.wynik == "f" || br.wynik == "j") {
                wynikPlik << br.wynik << " = " << br.value
                          << " (czas propagacji: " << br.czas_skumulowany << ")\n";
            }
        }
        wynikPlik << "------------------------\n";
    }

    return 0;
}
