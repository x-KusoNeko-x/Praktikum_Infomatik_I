//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXV
//////////////////////////////////////////////////////////////////////////////

#include "Liste.h"

/**
 * @brief Standardkonstruktor, der eine leere Liste erstellt
 */
Liste::Liste(): front(nullptr), back(nullptr)
{
}

/**
 * @brief Hinzufuegen eines neuen Listenelements am Ende der Liste.
 *
 * @param pData Zeiger auf ein Objekt der Klasse Student
 * @return void
 */
void Liste::pushBack(Student pData)
{
    ListenElement* neuesElement = new ListenElement(back, pData, nullptr);

    if (front == nullptr)                                       // Liste leer?
    {
        front = neuesElement;
        back = neuesElement;
    }
    else
    {
        back->setNext(neuesElement);
        back = neuesElement;
    }
}

/**
 * @brief Hinzufuegen eines neuen Listenelements am Beginn der Liste.
 *
 * @param pData Zeiger auf ein Objekt der Klasse Student
 * @return void
 */
void Liste::pushFront(Student pData)
{
    ListenElement* neuesElement = new ListenElement(nullptr, pData, front);

    if (front == nullptr)                                       // Liste leer?
    {
        front = neuesElement;
        back = neuesElement;
    }
    else
    {
        neuesElement->setNext(front);
        front->setPrev(neuesElement);
        front = neuesElement;
    }
}

/**
 * @brief Entfernen eines Listenelements am Anfang der Liste.
 *
 * @return void
 */
void Liste::popFront()
{
    ListenElement* cursor = front;

    if (front == back)                                       // Liste enth�lt nur ein Listenelement
    {
        delete front;                                        // Listenelement l�schen
        front = nullptr;
        back = nullptr;
    }
    else
    {
        front = front->getNext();
        front->setPrev(nullptr);
        delete cursor;
    }
}

bool Liste::dataLoesch(unsigned int suchNr)
{
    ListenElement* cursor = front;

    while (cursor != nullptr)
    {
        if (cursor->getData().getMatNr() == suchNr)
        {
            if (cursor->getPrev())
            {
                cursor->getPrev()->setNext(cursor->getNext());
            }
            else
            {
                front = cursor->getNext(); 
            }
            if (cursor->getNext())
            {
                cursor->getNext()->setPrev(cursor->getPrev());
            }
            else
            {
                back = cursor->getPrev();
            }
            delete cursor;
            return true;
        }

        cursor = cursor->getNext();
    }
    return false;

}


/**
 * @brief Pruefen, ob die Liste leer ist
 *
 * @return wenn leer true, sonst false
 */
bool Liste::empty()
{
    if(front == nullptr)
    {
        return true;
    }
    return false;
}

/**
 * @brief Gibt die Daten des ersten Listenelements in der Liste zurueck
 *
 * @return Zeiger auf ein Objekt der Klasse Student
 */
Student Liste::dataFront()
{
    return front->getData();
}

/**
 * @brief Gibt die Daten des letzten Listenelements in der Liste zurueck
 *
 * @return Zeiger auf ein Objekt der Klasse Student
 */
Student Liste::dataBack()
{
    return back->getData();
}

/**
 * @brief Ausgabe der Liste vom ersten bis zum letzten Element.
 *
 * @return void
 */
void Liste::ausgabeVorwaerts() const
{
    ListenElement* cursor = front;

    while (cursor != nullptr)
    {
    	cursor->getData().ausgabe();
        cursor = cursor->getNext();
    }
}

/**
 * @brief Ausgabe der Liste vom letzten bis zum ersten Element.
 *
 * @return void
 */
void Liste::ausgabeRueckwarets() const
{
    ListenElement* cursor = back;

    while (cursor != nullptr)
    {
    	cursor->getData().ausgabe();
        cursor = cursor->getPrev();
    }
}
