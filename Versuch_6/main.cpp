/** @mainpage
 *
 * Praktikum Informatik 1 MMXXV <BR>
 * Versuch 5: Dynamische Datenstrukturen
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "Student.h"

/**
 * @brief main funktion, menue ausrufen
 * 
 * @param abfrage antworten von benutzer
 * 
 * @return no return
 */
int main()
{
    std::vector<Student> studentenVector;
    Student student;
    char abfrage1;

    std::cout << "wollen sie daten selbst hinzufuegen?(j/n)" << std::endl;
    std::cin >> abfrage1;

    if (abfrage1 == 'n')
    {
        //dateiname C:\\Programms\\C_Cpp\\prInfo1\\Versuch06\\studenten.txt//
        std::string dateiname;
        std::cout << "geben Sie bitte Name von Datei ein, die wir lesen sollen(.txt)" << std::endl;
        std::cout << "(C:\\Programms\\C_Cpp\\prInfo1\\Versuch06\\studenten.txt)" << std::endl;
        std::cin >> dateiname;

        std::ifstream eingabe(dateiname);

        while (eingabe.is_open() != true)
        {
            std::cout << "datei mit name " << dateiname << " konnte nicht gefungen werden! Geben sie mal erneut!" << std::endl;
            std::cin >> dateiname;
            std::ifstream eingebe(dateiname);
        }

        std::cout << "datei wird erfolgreich geoeffnet!" << std::endl;
        std::cout << "beginnen mit einlesen prozess......" << std::endl;

        int zeileNr = 0;
        std::string zeileInfo;

        std::string matNr;
        std::string name;
        std::string adresse;
        std::string geburtsdatum;

        while (zeileNr <= 20)
        {

            switch (zeileNr % 4)
            {
            case 0:
                std::getline(eingabe, zeileInfo);
                matNr = zeileInfo;
                zeileNr++;
                std::cout << "einlesen......" << std::endl;
                break;
            case 1:
                std::getline(eingabe, zeileInfo);
                name = zeileInfo;
                zeileNr++;
                std::cout << "einlesen......" << std::endl;
                break;
            case 2:
                std::getline(eingabe, zeileInfo);
                adresse = zeileInfo;
                zeileNr++;
                std::cout << "einlesen......" << std::endl;
                break;
            case 3:
                std::getline(eingabe, zeileInfo);
                geburtsdatum = zeileInfo;
                zeileNr++;
                std::cout << "einlesen......" << std::endl;

                student = Student(matNr, name, adresse, geburtsdatum);
                studentenVector.push_back(student);
                break;
            }
        }
        std::cout << "daten erfolgreich gelesen!" << std::endl;
    }

    /*
    char abfrage;
    std::cout << "Wollen Sie die Liste selbst fuellen? (j)/(n) ";
    std::cin >> abfrage;
    std::cin.ignore(10, '\n');

    if (abfrage != 'j')
    {
        student = Student(34567, "Harro Simoneit", "19.06.1971", "Am Markt 1");
        studentenListe.pushBack(student);
        student = Student(74567, "Vera Schmitt", "23.07.1982", "Gartenstr. 23");
        studentenListe.pushBack(student);
        student = Student(12345, "Siggi Baumeister", "23.04.1983", "Ahornst.55");
        studentenListe.pushBack(student);
        student = Student(64567, "Paula Peters", "9.01.1981", "Weidenweg 12");
        studentenListe.pushBack(student);
        student = Student(23456, "Walter Rodenstock", "15.10.1963", "W�llnerstr.9");
        studentenListe.pushBack(student);
    }
    */
    char abfrage;
    do
    {
        std::cout << "\nMenue:" << std::endl
                  << "-----------------------------" << std::endl
                  << "(1): Datenelement hinten hinzufuegen" << std::endl
                  << "(2): Datenelement vornen hinzufuegen" << std::endl
                  << "(3): Datenelement vorne entfernen" << std::endl
                  << "(4): Datenbank vorwaerts ausgeben" << std::endl
                  << "(5): Datenbank rueckwaerts ausgeben" << std::endl
                  << "(6): Datenelement entfernen" << std::endl
                  << "(7): Daten aus einer Datei einschreiben" << std::endl
                  << "(0): Beenden" << std::endl;
        std::cin >> abfrage;
        std::cin.ignore(10, '\n');

        switch (abfrage)
        {
            // Datenelement hinten hinzufuegen
            case '1':
                {
                    std::string matNr = "";
                    std::string name = "";
                    std::string geburtstag = "";
                    std::string adresse = "";

                    std::cout << "Bitte geben sie die Daten f�r den Studenten ein.\nName: ";
                    getline(std::cin, name);    // ganze Zeile einlesen inklusive aller Leerzeichen

                    std::cout << "Geburtsdatum: ";
                    getline(std::cin, geburtstag);

                    std::cout << "Adresse: ";
                    getline(std::cin, adresse);

                    std::cout << "Matrikelnummer: ";
                    std::cin >> matNr;
                    std::cin.ignore(10, '\n');

                    student = Student(matNr, name, geburtstag, adresse);

                    studentenVector.push_back(student);
                }
                break;

             // Datenelement vornen hinzufuegen
            case '2':
                {
                    std::string matNr = "";
                    std::string name = "";
                    std::string geburtstag = "";
                    std::string adresse = "";

                    std::cout << "Bitte geben sie die Daten f�r den Studenten ein.\nName: ";
                    getline(std::cin, name);    // ganze Zeile einlesen inklusive aller Leerzeichen

                    std::cout << "Geburtsdatum: ";
                    getline(std::cin, geburtstag);

                    std::cout << "Adresse: ";
                    getline(std::cin, adresse);

                    std::cout << "Matrikelnummer: ";
                    std::cin >> matNr;
                    std::cin.ignore(10, '\n');

                    student = Student(matNr, name, geburtstag, adresse);

                    studentenVector.insert(studentenVector.begin(), student);
                }
                break;

            // Datenelement vorne entfernen
            case '3':
                {
                    if(!studentenVector.empty())
                    {
                        studentenVector.erase(studentenVector.begin());
                        std::cout << "loesch erfolgt" << std::endl;
                    }
                    else
                    {
                        std::cout << "Die Liste ist leer!\n";
                    }
                }
                break;

            // Datenbank vorwaerts ausgeben
            case '4':
                if(!studentenVector.empty())
                {
                    std::cout << "Inhalt der Liste in fortlaufender Reihenfolge:" << std::endl;
                    
                    std::vector<Student>::iterator it;
                    it = studentenVector.begin();
                    while (it != studentenVector.end())
                    {
                        Student tmpStudent = *it;
                        tmpStudent.ausgabe();
                        it++;
                    }
                }
                else
                {
                    std::cout << "Die Vector ist leer!\n\n";
                }
                break;

            //Datenbank rueckwaerts ausgeben
            case '5':
                if (!studentenVector.empty())
                {
                    std::cout << "Inhalt der Liste in ruecklaufender Reienfolge:" << std::endl;

                    std::vector<Student>::reverse_iterator rit;
                    rit = studentenVector.rbegin();
                    while (rit != studentenVector.rend())
                    {
                        Student tmpStudent = *rit;
                        tmpStudent.ausgabe();
                        rit++;
                    }
                }
                else
                {
                    std::cout << "Die Liste ist leer\n\n";
                }
                break;

            //Datenelement entfernen
            case '6':
                if (!studentenVector.empty())
                {
                    std::string matNr;
                    std::cout << "Geben Sie die Matrikelnummer ein: ";
                    std::cin >> matNr;

                    std::vector<Student>::iterator lit;
                    lit = studentenVector.begin();
                    bool matNrf = false;
                    while (lit != studentenVector.end())
                    {
                        Student tmpStudent = *lit;
                        std::string tmpMatnr = tmpStudent.getMatNr();
                        if (tmpMatnr == matNr)
                        {
                            std::cout << "diese student wird geloescht:" << std::endl;
                            tmpStudent.ausgabe();
                            studentenVector.erase(lit);
                            std::cout << "student erfolgreich geloescht" << std::endl;
                            matNrf = true;
                            break;
                        }
                        else
                        {
                            lit++;
                        }
                    }
                    if (!matNrf)
                    {
                        std::cout << "diese matikelnummer nicht gefunden";
                    }
                }
                else
                {
                    std::cout << "Die Liste ist leer\n\n";
                }
                break;
            case '7':
            {
                int zeileNr = 0;
                std::string zeileInfo;

                std::string matNr;
                std::string name;
                std::string adresse;
                std::string geburtsdatum;

                std::ofstream ausgabe;
                ausgabe.open("C:\\Programms\\C_Cpp\\prInfo1\\Versuch06\\studentenaus.txt");

                std::vector<Student>::iterator ait;
                ait = studentenVector.begin();
                Student tmpStudent;

                while (ait != studentenVector.end())
                {

                    switch (zeileNr % 4)
                    {
                    case 0:
                        tmpStudent = *ait;
                        ausgabe << tmpStudent.getMatNr() << std::endl;
                        zeileNr++;
                        break;
                    case 1:
                        tmpStudent = *ait;
                        ausgabe << tmpStudent.getName() << std::endl;
                        zeileNr++;
                        break;
                    case 2:
                        tmpStudent = *ait;
                        ausgabe << tmpStudent.getGeburtstag() << std::endl;
                        zeileNr++;
                        break;
                    case 3:
                        tmpStudent = *ait;
                        ausgabe << tmpStudent.getAdresse() << std::endl;
                        zeileNr++;
                        
                        ait++;
                        break;
                    }
                }
            }
            std::cout << "die daten wird erfolgreich in studentenaus.txt unter path: C:\\Programms\\C_Cpp\\prInfo1\\Versuch06\\studenten.txt eingeschrieben" << std::endl;
            break;
            case '0':
                std::cout << "Das Programm wird nun beendet";
                break;

            default :
                std::cout << "Falsche Eingabe, bitte nochmal";
                break;
        }
    }
    while (abfrage != '0');

    return 0;
}
