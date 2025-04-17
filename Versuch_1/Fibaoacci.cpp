/////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXV
// Versuch 2.1: Fibonacci
//
// Datei:  Fibonacci.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////


#include <iostream>

int main()
{
    int fibonacci_n1 = 0;
    int fibonacci_n2 = 1;
    int fibonacci_temp;
    int anzahl = 0; 
    
    //bei int gibt es maximal 2,147,483,627(2^31-1). d.h. groessere Zahl hat kein sinn;
    //nach 47-te fibonacci-zahl koennen wir nicht mehr mit int rechnen;
    //fuer groessere zahl bnutzen wir "insigned int" oder "long long"

    std::cout << "geben Sie Anzahl von fibonacci Zahlen ein" << std::endl;
    std::cin >> anzahl;

    for(int i = 0; i < anzahl; i++)
    {
        std::cout << fibonacci_n1 << std::endl;
        fibonacci_temp = fibonacci_n1;
        fibonacci_n1 = fibonacci_n2;
        fibonacci_n2 = fibonacci_n1 + fibonacci_temp;
    }

    return 0;
}
