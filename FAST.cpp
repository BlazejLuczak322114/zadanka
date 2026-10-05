// ConsoleApplication1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>

template <typename T>
void wyszukiwanieBinarne(T table[],int rozmiar, T wyszukiwany) {
    T temp;
    for (int i = 0; i < rozmiar; ++i) {//tablica wczesniej posortowana malejaco
        for (int j = 0; j < rozmiar; ++j) {
            if (table[j] < table[i]) {
                temp = table[j];
                table[j] = table[i];
                table[i] = temp;
            }
        }
    }

    T srodek = (table[0] + table[rozmiar - 1]) / 2; //srodek tej posortowanej tablicy

    //zrobić funkcje do sortownaia
    //zrobić funkcje do wyszukiwania binarnego
    //scalić te dwie funkcje w klase szablonową (z tego co rozumiem to mają to być metody tej klasy?)

    //also
    //2. numer telefonu z długością i numerem kierunkowym jako parametry szablonu
    //3. zaimplementuj układ cykliczny jako klase szablonową
    //4. fisbass

    //parametr szablonu


    
    
    //if (rozmiar % 2 == 0) {
    //    srodek = table[rozmiar / 2];
    //}
    //else {
    //    srodek = (table[rozmiar/2]+table[(rozmiar/2)+1])/2
    //}

    //if (wyszukiwany < srodek) {
    //}


}

template <typename T>
class NumerTelefonu {

};

int main()
{
    int table[11] = { 1,2,3,4,5,6,7,8,9,10,11 };
    std::cout << "Hello World!\n";
    float a = 0;

    a = 11 / 2;
    std::cout << a;

//    int temp;
//    for (int i = 0; i < 11; ++i) {
//        for (int j = 0; j < 11; ++j) {
//            if (table[j] < table[i]) {
//                temp = table[j];
//                table[j] = table[i];
//                table[i] = temp;
//            }
//        }
//    }
//
//    for (int i = 0; i < 11; ++i) {
//        std::cout << table[i] << " " << std::endl;
//    }
//}

