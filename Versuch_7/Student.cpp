//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXV
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "Student.h"

/**
 * @brief Konstruktor, der einen neuen Studenten mit allen Werten erstellt
 *
 * @param matNr Matrikelnummer
 * @param name Name
 * @param geburtstag Geburtstag
 * @param adresse Adresse
 */
Student::Student(unsigned int matNr, std::string name, std::string geburtstag, std::string adresse) :
    matNr(matNr), name(name), geburtstag(geburtstag), adresse(adresse)
{
}

/**
 * @brief Standardkonstruktor, der einen leeren Studenten erstellt
 */
Student::Student() : matNr(), name(""), geburtstag(""), adresse("")
{
}

/**
 * @brief Gibt die Matrikelnummer des Studenten zurueck
 *
 * @return Matrikelnummer
 */
unsigned int Student::getMatNr() const
{
    return matNr;
}

/**
 * @brief Gibt den Namen des Studenten zurueck
 *
 * @return Name
 */
std::string Student::getName() const
{
    return name;
}

/**
 * @brief Gibt den Geburtstag des Studenten zurueck
 *
 * @return Geburtstag
 */
std::string Student::getGeburtstag() const
{
    return geburtstag;
}

/**
 * @brief Gibt die Adresse des Studenten zurueck
 *
 * @return Adresse
 */
std::string Student::getAdresse() const
{
    return adresse;
}

/**
 * @brief Gibt alle Daten des Studenten in einer Zeile aus
 */
void Student::ausgabe(std::ostream& output) const
{
    output << "Matikelnummer: " << matNr << ", ";
    output << "Name: " << name << ", ";
    output << "Geburtsdatum: " << geburtstag << ", ";
    output << "Adresse: " << adresse << ", ";
}

//Versuch_7

/**
*@brief Matikelnummer von studenten vergleichen
*/
bool Student::operator < (const Student& input) const
{
    if (matNr < input.getMatNr())
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
*@brief Matikelnummer von studenten vergleichen
*/
bool Student::operator > (const Student& input) const
{
    if (matNr > input.getMatNr())
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
*@brief Matikelnummer von studenten vergleichen
*/
bool Student::operator == (const Student& input) const
{
    if (matNr == input.getMatNr())
    {
        return true;
    }
    else
    {
        return false;
    }
}

