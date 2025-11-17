#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class BramkaPrototyp { //klasa bramki logicznej
public:
    string typ;         //typ bramki
    string wejscie1;    //nazwa sygnalu 1
    string wejscie2;    //nazwa sygnalu 2
    string wynik;       //nazwa wyniku
    int czas_propagacji;    //czas tej bramki
    int value;             // wynik bramki (0/1)
    int czas_skumulowany;  // ile czasu zajelo przejscie do tej bramki

    BramkaPrototyp(string typA, string in1, string in2, string wynikA, int czasA) { //konstruktor
        typ = typA;
        wejscie1 = in1;
        wejscie2 = in2;
        wynik = wynikA;
        czas_propagacji = czasA;
        value = -1;
        czas_skumulowany = 0;
    }
};

int obliczBramke(BramkaPrototyp &br, int val1, int val2) { //funkcja liczaca wartosc bramki (poza klasa)
    if (br.typ == "NAND") return !(val1 & val2);
    else if (br.typ == "AND") return val1 & val2;
    else if (br.typ == "OR")  return val1 | val2;
    else if (br.typ == "NOR") return !(val1 | val2);
    else if (br.typ == "XOR") return val1 ^ val2;
    else if (br.typ == "NOT") return !val1;
    return 0;
}

int main() {
    // wczytanie opisu ukladu bramek z pliku
    fstream opis("opis_ukladu.txt", ios::in);
    if (!opis.good()) { cout << "Nie mozna otworzyc opis_ukladu.txt\n"; return 1; } //sprawdzanie, czy wczytywanie dziala poprawnie

    vector<BramkaPrototyp> bramki; //wektor kolejnych bramek zczytanych z pliku
    string typ, in1, in2, out; //zmienne tymczasowe
    int opoznienie;

    while (opis >> typ >> in1 >> in2 >> out >> opoznienie) { //wczytywanie z pliku
        bramki.push_back(BramkaPrototyp(typ, in1, in2, out, opoznienie));
    }
    opis.close(); //zamkniecie pliku po wczytywaniu

    // wczytanie a i b z pliku
    fstream wej("wejscie.txt", ios::in);
    if (!wej.good()) { cout << "Nie mozna otworzyc wejscie.txt\n"; return 1; }

    string hA, hB; // na razie ignoruje naglowek, przy wiekszym skomplikowaniu moze sie przyda
    wej >> hA >> hB;

    vector<pair<int,int>> zestawy; //wektor par a i b, gdybym znal wiecej sygnalow na starcie to albo mozna inaczej troche podejsc, albo dodac bramki o zerowym czasie propagacji
    int aVal, bVal;
    while (wej >> aVal >> bVal) { //czytanie
        zestawy.push_back({aVal,bVal});
    }
    wej.close();


    ofstream wynikPlik("wynik.txt"); // otwarcie pliku wynikowego
    if (!wynikPlik.is_open()) {
        cout << "Nie mozna otworzyc wyniki.txt\n";
        return 1;
    }

    // petla dla kazdego zestawu a i b
    for (int z = 0; z < zestawy.size(); z++) {
        aVal = zestawy[z].first;
        bVal = zestawy[z].second;

        // resetujemy wartosci bramek
        for (auto &br : bramki) { //za kazda bramke w bramkach
            br.value = -1;
            br.czas_skumulowany = 0;
        }

        int a = aVal;
        int b = bVal;

        // obliczenia: powtarzamy, aa wszystkie bramki maja value
        bool zmiana = true; //w petli zmiana na true gdy chociaz 1 bramka sie zmienila
        while (zmiana) {
            zmiana = false;
            for (auto &br : bramki) { //petla przechodzi przez wszystkie bramki
                if (br.value != -1) continue; // jezeli value nie jest rowne -1 to ta bramka ma juz wynik i nie trzeba jej liczyc

                int val1 = 0, val2 = 0;
                int czas1 = 0, czas2 = 0;
                bool got1 = false, got2 = false; //czy wartosc1 lub wartosc2 sa znane a nie jeszcze nie policzone

                // wejscie1
                if (br.wejscie1 == "a") { val1 = a; czas1 = 0; got1 = true; }
                else if (br.wejscie1 == "b") { val1 = b; czas1 = 0; got1 = true; }
                else {
                    for (auto &prev : bramki) { //przechodzimy znowu przez wszystkie bramki
                        if (prev.wynik == br.wejscie1 && prev.value != -1) { //jezeli wczesniejsza bramka ktora jest jednym z potrzebnych sygnalow ma juz znana wartosc
                            val1 = prev.value;
                            czas1 = prev.czas_skumulowany;
                            got1 = true;
                            break;
                        }
                    }
                }

                // wejscie2 aka to samo co wejscie 1 ale dla wejscia2
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

                if (got1 && got2) { //jezeli znane sa wartosci obu wejsc to mozna policzyc wartosc dla tego wejscia
                    br.value = obliczBramke(br, val1, val2); //liczenie value
                    br.czas_skumulowany = (czas1 > czas2 ? czas1 : czas2) + br.czas_propagacji;
                    zmiana = true;
                }
            }
        }

        // wypisanie wynikow
        cout << "Zestaw a=" << a << " b=" << b << ":\n";
        for (auto &br : bramki) {
            if (br.wynik == "c" || br.wynik == "f" || br.wynik == "k" || br.wynik == "e") {
                cout << br.wynik << " = " << br.value
                     << " (czas propagacji: " << br.czas_skumulowany << ")\n";
            }
        }
        cout << "------------------------\n";
        // zapis do pliku
        wynikPlik << "Zestaw a=" << a << " b=" << b << ":\n";
        for (auto &br : bramki) {
            if (br.wynik == "c" || br.wynik == "f" || br.wynik == "k" || br.wynik == "e") {
                wynikPlik << br.wynik << " = " << br.value
                          << " (czas propagacji: " << br.czas_skumulowany << ")\n";
            }
        }
        wynikPlik << "------------------------\n";
    }

    return 0;
}
