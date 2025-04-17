//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXV
// Versuch 02
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////


#include <iostream>

int fibonacci(int n)
{
    int previousFib = 1;
    int currentFib = 1;
    if(n == 1)
    {
        return 0;
    }
    if(n == 2)
    {
        return 1;
    }
    for (int i = 4; i <= n; i++)
    {
        int newFib = previousFib + currentFib ;
        previousFib = currentFib ;
        currentFib = newFib ;
    }
    return currentFib ;
}

int main ()
{
    int m;
    std::cout << "Anzahl" << std::endl;
    std::cin >> m;
    std::cout << " Fibonacci - Zahlen von 0 bis:" << m << std::endl ;
    for (int i = 1; i <= m ; i ++)
    {
        std::cout << "f(" << i << ") = " << fibonacci(i) << std::endl ;
    }
    return 0;
}

//bei mein programmm muss die programm fuer jeder zahl von fibonacci zahl ein man ganz verfach durchlaufen
//also bei jeder zahl muss die programme immer von 0,1,1.....rechnen
//das ist ja viel langsamer
//hier laeuft das programm nur einmal durch
