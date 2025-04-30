//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXV
// Versuch 04: Einf�hrung Klasse
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include "Vektor.h"

int main()
{
    
    Vektor vektor1(1, 0, 0);
    Vektor vektor2(0, 1, 0);

    std::cout << "Vektor 1:" << std::endl;
    vektor1.ausgabe();
    std::cout << "Vektor 2:" << std::endl;
    vektor2.ausgabe();

    // Testen die funktion in Vektor.cpp
    ////testen funktion sub
    Vektor sub12 = vektor1.sub(vektor2);
    Vektor sub21 = vektor2.sub(vektor1);
    std::cout << "Sub 1 von 2 ist:" << std::endl;
    sub12.ausgabe();
    std::cout << "Sub 2 von 1 ist:" << std::endl;
    sub21.ausgabe();

    ////testen function laenge
    double laenge1 = vektor1.laenge();
    double laenge2 = vektor2.laenge();
    std::cout << "laenge von vektor 1 ist: " << laenge1 << std::endl;
    std::cout << "laenge von vektor 2 ist: " << laenge2 << std::endl;

    ////testen function skalarProd

    ////testen function winkel

    ////testen function rotiereUmZ

    // Ende test;

    Vektor erdRadius(0, 0, 0);      // bitte sinnvoll initialisieren
    Vektor aussichtsPunkt(0, 0, 0); // bitte sinnvoll initialisieren
    Vektor sicht(0, 0, 0);

    return 0;

}
