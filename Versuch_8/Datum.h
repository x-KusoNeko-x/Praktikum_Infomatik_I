/*!
 * Praktikum Informatik 1 MMXXV
 *
 * @file Datum.h
 */

#ifndef Datum_H_
#define Datum_H_

#include <string>
#include <iostream>


 /*! \brief Klasse f�r ein Datum
  *
  * Speichert ein Datum, bestehend aus Tag, Monat und Jahr.
  * Die Klasse Datum bietet verschiedene Funktionalit�ten/Operatoren
  * die zum Ausgeben/Bearbeiten/Vergleichen von verschiedenen Daten genutzt werden k�nnen
  *
  */

class Datum
{
public:
    /*!
     * @brief Standartkonstruktor
     *
     * Initialisiert die Klasse Datum mit dem heutigen Datum
     *
     */
    Datum();

    /*!
     * @brief Konstruktor f�r ein gegebenes Datum
     *
     * \param int initTag:    gegebener Tag
     * \param int initMonat:  gegebener Monat
     * \param int initJahr:   gegebenes Jahr
     *
     */
    Datum(int initTag, int initMonat, int initJahr);

    /*!
     * @Brief Destruktor
     */
    ~Datum(void);

    /*!
     * @brief Eingabe eines Datums �ber einen Eingabestream
     *
     * \param std::istream& in: Eingabestream zum Einlesen
     */
    void eingabe(std::istream& in);

    /*!
     * @brief Ausgabe eines Datums �ber einen Ausgabestream
     *
     * \param std::ostream out: Ausgabestream zum Ausgeben
     */
    void ausgabe(std::ostream& out) const;

    /*!
     * @brief Zuweisungsoperator
     *
     * \param Datum& d: Argument auf der rechten Seite, welches der Ausgangspunkt f�r die Zuweisung ist
     */
    Datum& operator=(Datum& d);

    /*!
     * @brief Subtraktionsoperator
     *
     * \param Datum& d: Argument auf der rechten Seite
     *
     * \return int: Gibt die Differenz der beiden Monate in Monaten zur�ck
     */
    int operator-(const Datum d) const;

    /*!
     * @brief Additionsoperator
     *
     * \param const int: anzahlTag Anzahl der Tage, die auf das aktuelle Datum addiert werden sollen
     *
     * \return Datum: Gibt das modifizierte Datum zur�ck
     */
    Datum operator+(const int anzahlTage) const;

private:
    int tag;
    int monat;
    int jahr;

    /*!
     * @brief Enth�lt die Anzahl der Tage pro Monat
     */
    static const int tageMonat[12];
};

/*!
 * @brief �berladung des Ausgabestream-Operators f�r die Klasse Datum
 *
 * \param std::ostream& out: Argument auf der linken Seite des Operators
 * \param const Datum& d: Argument auf der rechten Seite des Operators
 *
 * \return std::ostream&: R�ckgabe des Streams auf den das Datum geschrieben wurde
 */
std::ostream& operator<<(std::ostream& out, const Datum& d);

/*!
 * @brief �berladung des Eingabestream-Operators f�r die Klasse Datum
 *
 * \param std::istream& out: Argument auf der linken Seite des Operators
 * \param const Datum& d: Argument auf der rechten Seite des Operators
 *
 * \return std::istream&: R�ckgabe des Streams in den das Datum geschrieben wurde
 */
std::istream& operator >> (std::istream& in, Datum& d);

#endif
