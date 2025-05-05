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
    std::cout << std::endl;

    //Testen die funktion in Vektor.cpp
    //testen funktion sub
    Vektor sub12 = vektor1.sub(vektor2);
    Vektor sub21 = vektor2.sub(vektor1);
    std::cout << "Sub 1 von 2 ist:" << std::endl;
    sub12.ausgabe();
    std::cout << "Sub 2 von 1 ist:" << std::endl;
    sub21.ausgabe();
    std::cout << std::endl;

    //testen function laenge
    double laenge1 = vektor1.laenge();
    double laenge2 = vektor2.laenge();

    std::cout << std::setprecision(4);
    std::cout << "laenge von vektor 1 ist: " << laenge1 << std::endl;
    std::cout << "laenge von vektor 2 ist: " << laenge2 << std::endl << std::endl;

    //testen function skalarProd
    double skalarProd12 = vektor1.skalarProd(vektor2);

    std::cout << std::setprecision(4);
    std::cout << "skalarprudukt von vektor1 und 2 ist: " << skalarProd12 << std::endl << std::endl;

    //testen function winkel
    double winkelWert = vektor1.winkel(vektor2);

    std::cout << std::setprecision(2);
    std::cout << "winkel zwischen vektor1 und 2 ist: " << winkelWert << " rad" << std::endl << std::endl;

    //testen function rotiereUmZ
    double rotierWink = M_PI/2;
    vektor1.rotiereUmZ(rotierWink);
    std::cout << "vektor 1 dereht sich 90grad um z ist: " << std::endl;
    vektor1.ausgabe();

    // Ende test

    // Horizon
    //variable inportieren
    Vektor erdRadius(0, 6371, 0);      // bitte sinnvoll initialisieren
    Vektor aussichtsPunkt(0, 557.4, 0); // bitte sinnvoll initialisieren
    Vektor sicht(0, 0, 0);
    Vektor normVektor(0, 0, 0);

    int schrittCNT = 0;
    double schritt_Rad;
    double winkel = 1;

    // Rechnen
    std::cout << "geben sie schrittlaenge(in rad) ein :" << std::endl;
    std::cin >> schritt_Rad;

    normVektor = erdRadius.plus(aussichtsPunkt);
    
    while (winkel < M_PI/2)
    {
        erdRadius.rotiereUmZ(schritt_Rad);
        sicht = normVektor.sub(erdRadius);
        winkel = sicht.winkel(erdRadius);
        schrittCNT++;
    }
    

    // Output
    std::cout << std::fixed;
    std::cout << std::setprecision(4);

    return 0;

}
