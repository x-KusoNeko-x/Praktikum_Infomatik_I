/////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXV
// Versuch 1.2: Strukturen
//
// Datei:  Strukturen.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

struct Person
{
    std::string sNachname;
    std::string sVorname;
    int iGeburtsjahr;
    int iAlter;
};

Person nBenutzer;

int main()
{
    std::cout << "Nachname ist ?" << std::endl;
    std::cin >> nBenutzer.sNachname;

    std::cout << "Vorname ist ?" << std::endl;
    std::cin >> nBenutzer.sVorname;

    std::cout << "Alter ist ?" << std::endl;
    std::cin >> nBenutzer.iAlter;

    std::cout << "Geburtsjahr ist ?" << std::endl;
    std::cin >> nBenutzer.iGeburtsjahr;

    std::cout << "Nachname:    " << nBenutzer.sNachname << std::endl;
    std::cout << "Vorname:     " << nBenutzer.sVorname << std::endl;
    std::cout << "Alter:       " << nBenutzer.iAlter << std::endl;
    std::cout << "Geburtsjahr: " << nBenutzer.iGeburtsjahr << std::endl;
    std::cout << std::endl;

    Person nKopieEinzeln;

    nKopieEinzeln.sNachname = nBenutzer.sNachname;
    nKopieEinzeln.sVorname = nBenutzer.sVorname;
    nKopieEinzeln.iAlter = nBenutzer.iAlter;
    nKopieEinzeln.iGeburtsjahr = nBenutzer.iGeburtsjahr;

    Person nKopieGesammt;

    nKopieGesammt = nBenutzer;

    std::cout << "Nachname:    " << nKopieEinzeln.sNachname << std::endl;
    std::cout << "Vorname:     " << nKopieEinzeln.sVorname << std::endl;
    std::cout << "Alter:       " << nKopieEinzeln.iAlter << std::endl;
    std::cout << "Geburtsjahr: " << nKopieEinzeln.iGeburtsjahr << std::endl;
    std::cout << std::endl;

    std::cout << "Nachname:    " << nKopieGesammt.sNachname << std::endl;
    std::cout << "Vorname:     " << nKopieGesammt.sVorname << std::endl;
    std::cout << "Alter:       " << nKopieGesammt.iAlter << std::endl;
    std::cout << "Geburtsjahr: " << nKopieGesammt.iGeburtsjahr << std::endl;
    std::cout << std::endl;

    return 0;
    
}
