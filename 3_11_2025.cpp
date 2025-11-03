// 3_11_2025.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void kwadrat(int liczba) {

    for (int i = liczba; i <= (liczba + 10); i++) {
        std::cout <<"Kwadrat "<<i<<": " << i * i << endl;
    }
    return;
}

string slownie(int liczba) {
    switch (liczba)
    {
    case 1:
        return "jeden";
        break;
    case 2:
        return "dwa";
        break;
    case 3:
        return "trzy";
        break;
    case 4:
        return "cztery";
        break;
    case 5:
        return "piec";
        break;
    case 6:
        return "szesc";
        break;
    case 7:
        return "siedem";
        break;
    case 8:
        return "osiem";
        break;
    case 9:
        return "dziewiec";
        break;
    default:
        return "No";
        break;
    }
}

int policzY(int a, int b, int c, int x) {
    int y = a * x * x + b * x + c;
    return y;
}



int potega(int podstawa,int n) {
    int wynik=podstawa;
    for (int i = 1; i < n; i++) {
        wynik *=podstawa;
    }

    return wynik;
}

//vector<int> rownanieKwadratowe(int a, int b, int c) {
//    int delta = (a * a) - (4 * a * c);
//    vector<int> wynik;
//    if (delta < 0) {
//        cout << "delta<0" << endl;
//        wynik.push_back(0);
//        return wynik;
//    }
//    int x1, x2;
//    x1 = ((-1 * b) - sqrt(delta)) / (2 * a);
//    x2 = ((-1 * b) + sqrt(delta)) / (2 * a);
//    wynik.push_back(x1);
//    wynik.push_back(x2);
//    return wynik;
//}


int main()
{
    std::cout << "Hello World!\n";
    //std::cout << potega(2, 10) << std::endl;
    //int a = 5;
    //int& b = a;
    kwadrat(10);
    cout<<slownie(1)<<endl;
    cout << "Policzone Y:" << policzY(1, 1, 2,5) << endl;
    cout<<potega(2, 10)<<endl;
    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
