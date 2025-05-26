#include "Magazin.h"

#include <string>
#include <iostream>

Magazin::Magazin(std::string initTitel, Datum initDatumAusgabe, std::string initSparte)
	:Medium(initTitel),
	datumAusgabe(initDatumAusgabe),
	sparte(initSparte)
{
	
}

Magazin::~Magazin(void)
{
}

void Magazin::ausgabe() const {
	std::cout << "ID: " << ID << std::endl
		<< "Typ: Magazin" << std::endl
		<< "Titel: " << titel << std::endl
		<< "AusgabeDatum: " << datumAusgabe << std::endl
		<< "Sparte: " << sparte << std::endl;
	if (status)
	{
		std::cout << "Status : Das Medium ist seit dem " << datumAusgeliehen << " an " << personAusgeliehen.getName() << " ausgeliehen." << std::endl;
	}
	else
	{
		std::cout << "Status: Medium ist zurzeit nicht verliehen." << std::endl;
	}
}

bool Magazin::ausleihen(Person person, Datum ausleihdatum) {
	int datumdiff = ausleihdatum - datumAusgabe;
	if (status)
	{
		std::cout << "Das Medium \"" << titel << "\" ist bereits verliehen!" << std::endl;
		return false;
	}
	else if (datumdiff <= 1)
	{
		std::cout << std::endl << "Neuste Magazin duerfen ausleihen werden!" << std::endl;
		return false;
	}
	else
	{
		status = true;
		personAusgeliehen = person;
		datumAusgeliehen = ausleihdatum;
		std::cout << "Das Medium \"" << titel << "\" wird an " << person.getName() << " verliehen." << std::endl;
		return true;
	}
}