//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 
// 
// Versuch 1.1: Datentypen und Typumwandlung
//
// Datei:  Variablen.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

int main()
{
    int iErste = 0;
    int iZweite = 0;

    int iSumme = 0;
    int iQuotient = 0;

    double dSumme = 0;
    double dQuotient = 0;

    double dSummeCast = 0;
    double dQuotientCast = 0;

    std::string sVorname;
    std::string sNachname;
    std::string sVornameName;
    std::string sNameVorname;
    
    // Hier folgt Ihr eigener Code
    std::cout << "erste Zahl ist?" << std::endl; 
    std::cin >> iErste;

    std::cout << "zweite Zahl ist?" << std::endl;
    std::cin >> iZweite;

    std::cout << "dein Vorname ist?" <<std::endl;
    std::cin >> sVorname;

    std::cout << "dein Nachname ist?" <<std::endl;
    std::cin >> sNachname;

    double dErsteCast = (double)iErste;
    double dZweiteCast = (double)iZweite;

    iSumme = iErste + iZweite;
    iQuotient = iErste / iZweite;
    dSumme = iErste + iZweite;
    dQuotient = iErste / iZweite;
    dSummeCast = dErsteCast + dZweiteCast;
    dQuotientCast = dErsteCast / dZweiteCast;

    sVornameName = sVorname + " " + sNachname;
    sNameVorname = sNachname + ", " +sVorname;

    std::cout << "die Summe in int ist " << iSumme << std::endl;
    std::cout << "die Quotient in int ist " << iQuotient << std::endl;
    std::cout << "die Summe in double ist " << dSumme << std::endl;
    std::cout << "die Quotient in double ist " << dQuotient << std::endl;
    std::cout << "die Summe fuer typcast ist " << dSummeCast << std::endl;
    std::cout << "die Quotient fuer typcast ist " << dQuotientCast << std::endl;
    std::cout << "dein Vornamename ist " << sVornameName << std::endl;
    std::cout << "dein Namevorname ist " << sNameVorname << std::endl;

    {
        int iFeld[2] = {1,2};
        std::cout << "iFeld ist " << iFeld[0] << " " << iFeld[1] << std::endl;

        int spielFeld[2][3] = {
            {1,2,3},
            {4,5,6}
        };

        std::cout << "Spielfeld ist" << std::endl;
        std::cout << spielFeld[0][0] << " " << spielFeld[0][1] << " " << spielFeld[0][2] << std::endl;
        std::cout << spielFeld[1][0] << " " << spielFeld[1][1] << " " << spielFeld[1][2] << std::endl;

        const int iZweite = 100;

        std::cout << "Konstante iZweite innen block ist " << iZweite << std::endl;
    }
    
    std::cout << "Konstante iZweite ausser block ist " << iZweite << std::endl;

    return 0;
    
}
