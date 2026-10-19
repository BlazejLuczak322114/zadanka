// ConsoleApplication1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>

template <typename T>
void Fizbuzz() {
    
}
//
//dane wejściowe lub wyjściowe w json lub csv
//
//generate, transform
//
//obiekty funkcyjne
//
//
//zadania ?
//konwersja liczb w różnych formatach temperaturę
//fizzbuzz
//
//szukanie wzorca w tekście
//liczby rzymskie
//średnia arytmetyczna

int main()
{

    std::vector<int> table = {10,9,8,7,6,5,4,3,2,1};

    std::ifstream file("plik.json");
    //std::getline()

    std::sort(table.begin(), table.end(), [](int a, int b) {return a < b;});
    std::cout << table[0]<<std::endl;

    std::vector<int> table1(100);
    int counter = 1;
    std::generate(table1.begin(), table1.end(), [counter]() mutable {return counter++;}); 

    std::for_each(table1.begin(), table1.end(), [](int x) {
        std::string a = (x % 3) ? "" : "fizz";
        std::string b = (x % 5) ? "" : "buzz";
        std::cout << x << a << b <<std::endl;
        });

    //find if i count if op
    
}

