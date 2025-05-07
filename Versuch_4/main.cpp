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
    
    Vektor vektor1(1, 1, 0);
    Vektor vektor2(0, 1, 1);

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
    Vektor erdRadius(0, 6371000, 0);      // bitte sinnvoll initialisieren
    Vektor aussichtsPunkt(0, 557.4, 0); // bitte sinnvoll initialisieren
    Vektor sicht(0, -557.4, 0);
    Vektor normVektor(0, 0, 0);

    Vektor erdRadiusNxt(0, 6371000, 0);
    Vektor sichtNxt(0, -577.4, 0);

    int schrittCNT = 0;
    int gesSchritt = 0;
    double schritt_Rad = M_PI/6;
    int prec;

    // Rechnen
    std::cout << "geben sie gewuenschte genauigkeit(in stelle) ein :" << std::endl;
    std::cin >> prec;

    //prec = 10;

    while (prec % 1 != 0)
    {
        std::cout << "ungueltige eingabe, geben sie mal erneurt." << std::endl;
        std::cin >> prec;
    }

    double kommaZ = pow(0.1,prec);

    normVektor = erdRadius.plus(aussichtsPunkt);

    erdRadiusNxt.rotiereUmZ(schritt_Rad);
    sichtNxt = erdRadiusNxt.sub(normVektor);

    while (schritt_Rad > kommaZ || schritt_Rad < -kommaZ)
    {
        if (cos(sicht.winkel(erdRadius)) < 0 && cos(sichtNxt.winkel(erdRadiusNxt)) < 0)
        {
            erdRadius.rotiereUmZ(schritt_Rad);
            sicht = erdRadius.sub(normVektor);
            erdRadiusNxt.rotiereUmZ(schritt_Rad);
            sichtNxt = erdRadiusNxt.sub(normVektor);
            schrittCNT++;
        }
        else if (cos(sicht.winkel(erdRadius)) > 0 && cos(sichtNxt.winkel(erdRadiusNxt)) > 0)
        {
            erdRadius.rotiereUmZ(schritt_Rad);
            sicht = erdRadius.sub(normVektor);
            erdRadiusNxt.rotiereUmZ(schritt_Rad);
            sichtNxt = erdRadiusNxt.sub(normVektor);
            schrittCNT++;
        }
        else
        {
            erdRadius.rotiereUmZ(schritt_Rad);
            schritt_Rad = (-schritt_Rad)/2;
            schrittCNT++;

            if (schritt_Rad > 0)
            {
                std::cout << std::fixed << std::setprecision(prec);
                std::cout << "sucht " << schrittCNT << " schritte in richtung gegenuhrzeigersinn" << std::endl;
                std::cout << std::setprecision(prec) << "ersetzt schrittlaenge durch " << schritt_Rad << std::endl;
            }
            else if (schritt_Rad < 0)
            {
                std::cout << std::fixed << std::setprecision(prec);
                std::cout << "sucht " << schrittCNT << " schritte in richtung uhrzeigersinn" << std::endl;
                std::cout << std::setprecision(prec) << "ersetzt schrittlaenge durch " << schritt_Rad << std::endl;
            }
                
            erdRadiusNxt.rotiereUmZ(schritt_Rad);
            gesSchritt += schrittCNT;
            schrittCNT = 0;
        }      
    }

    double sichtLaenge = sicht.laenge() / 1000;
    double hohe = aussichtsPunkt.laenge();

    double winkel_grad = erdRadius.winkel(normVektor) * (180/M_PI);

    // Output
    std::cout << std::fixed << std::endl;
    std::cout << std::setprecision(2) << "========================================" << std::endl;
    std::cout << "sie koennen " << sichtLaenge << " km weit sehen" << std::endl;
    std::cout << std::fixed;
    std::cout << std::setprecision(2);
    std::cout << "sie sind " << hohe << " meter hoch" << std::endl;
    std::cout << std::fixed;
    std::cout << std::setprecision(prec);
    std::cout << "die winkel betraegt " << winkel_grad << " grad" << std::endl;
    std::cout << std::fixed;
    std::cout << std::setprecision(0);
    std::cout << "anzahl schritte: " << gesSchritt << std::endl;

    return 0;

}
